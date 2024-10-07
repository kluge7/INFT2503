#include "WebServer.hpp"

// Constructor: initializes the endpoint and acceptor
WebServer::WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

// Method to start accepting connections
void WebServer::start() {
    accept();  // Start accepting new connections
    io_service.run();  // Run the IO service to handle asynchronous operations
}

// Handles incoming requests from the connected client
void WebServer::handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n",
        [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
            if (!ec) {
                istream read_stream(read_buffer.get());
                std::string request_line;
                getline(read_stream, request_line); // Read the first line (request line)

                // Example request: GET / HTTP/1.1
                std::string method, path, version;
                std::istringstream request_stream(request_line);
                request_stream >> method >> path >> version; // Parse the request line

                // Prepare response message
                std::string response_body;
                std::string status_line;

                // Check the requested path
                if (method == "GET") {
                    if (path == "/") {
                        // Main page response
                        status_line = "HTTP/1.1 200 OK\r\n";
                        response_body = "Dette er hovedsiden";
                    } else if (path == "/en_side") {
                        // Secondary page response
                        status_line = "HTTP/1.1 200 OK\r\n";
                        response_body = "Dette er en side";
                    } else {
                        // Handle 404 Not Found
                        status_line = "HTTP/1.1 404 Not Found\r\n";
                        response_body = "404 Not Found";
                    }
                } else {
                    // Handle unsupported methods
                    status_line = "HTTP/1.1 405 Method Not Allowed\r\n";
                    response_body = "405 Method Not Allowed";
                }

                // Prepare the full HTTP response
                std::ostringstream response_stream;
                response_stream << status_line
                                << "Content-Length: " << response_body.size() << "\r\n"
                                << "Content-Type: text/plain\r\n"
                                << "\r\n"  // End of headers
                                << response_body;

                auto write_buffer = make_shared<boost::asio::streambuf>();
                ostream write_stream(write_buffer.get());
                write_stream << response_stream.str(); // Write the full response

                // Write to client
                async_write(connection->socket, *write_buffer,
                    [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                        if (!ec)
                            handle_request(connection); // Wait for the next request
                    });
            }
        });
}

// Accepts a new connection from a client
void WebServer::accept() {
    auto connection = make_shared<Connection>(io_service);
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
        accept();  // Accept the next connection
        if (!ec) {
            handle_request(connection);  // Start handling requests for the new connection
        }
    });
}
