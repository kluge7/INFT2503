#include "WebServer.hpp"
#include <iostream>

int main() {
  // Create a WebServer object
  WebServer web_server;

  // Output a message to indicate the server is starting
  std::cout << "Starting web server" << std::endl
            << "Connect in a terminal with: telnet localhost 8080." << std::endl;

  // Start the server
  web_server.start();

  return 0;
}
