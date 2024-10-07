#ifndef WEB_SERVER_HPP
#define WEB_SERVER_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
private:
    class Connection {
    public:
        tcp::socket socket;  // TCP socket for the connection
        
        Connection(boost::asio::io_service &io_service) 
            : socket(io_service) {}  // Constructor initializes the socket
    };

    boost::asio::io_service io_service;  // IO service for handling asynchronous operations
    tcp::endpoint endpoint;  // Endpoint to listen on
    tcp::acceptor acceptor;  // Accepts incoming connections

    void handle_request(shared_ptr<Connection> connection);  // Handles client requests
    void accept();  // Accepts new client connections

public:
    WebServer();  // Constructor to initialize the server
    void start();  // Starts the server
};

#endif // WEB_SERVER_HPP
