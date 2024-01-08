#include "socket.hpp"

void serverThreadFunction() {
    // 创建 socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating server socket." << std::endl;
        return;
    }

    // 配置服务器地址
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY; // 监听所有网络接口
    serverAddress.sin_port = htons(listen_port); // 使用端口号 8001

    // 将 socket 绑定到服务器地址
    if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding server socket." << std::endl;
        close(serverSocket);
        return;
    }

    // 开始监听连接
    if (listen(serverSocket, 10) == -1) {
        std::cerr << "Error listening for connections." << std::endl;
        close(serverSocket);
        return;
    }

    // 循环等待客户端连接和接收数据
    while (true) {
        // 接受客户端连接
        sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, reinterpret_cast<struct sockaddr*>(&clientAddress), &clientAddressLength);
        if (clientSocket == -1) {
            std::cerr << "Error accepting client connection." << std::endl;
            continue;
        }

        std::cout << "Client connected: " << inet_ntoa(clientAddress.sin_addr) << std::endl;

        // 循环接收客户端发送的数据
        char buffer[1024];
        int bytesRead;
        while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
            // 处理接收到的数据，这里简单地打印出来
            buffer[bytesRead] = '\0';
            std::cout << "Received message from client: " << buffer << std::endl;

            // 回复客户端
            const char* response = "Server received your message.";
            send(clientSocket, response, strlen(response), 0);
        }

        // 关闭客户端连接
        close(clientSocket);
    }

    // 关闭服务器 socket（这里不会被执行，因为上面是一个无限循环）
    close(serverSocket);
}


