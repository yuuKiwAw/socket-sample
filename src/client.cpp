#include <iostream>
#include <cstring>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int main() {
    // socket
    int client = socket(AF_INET, SOCK_STREAM, 0);
    if (client == -1) {
        std::cout << "[ERROR] socket" << std::endl;
        return 0;
    }

    // connect
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(client, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cout << "[ERROR] connect" << std::endl;
        return 0;
    }
    std::cout << "[INFO] connect..." << std::endl;
    char data[255];
    char buf[255];
    while(true) {
        std::cin >> data;
        send(client, data, strlen(data), 0);
        if (strcmp(data, "exit") == 0) {
            std::cout << "[INFO] dis connect" << std::endl;
            break;
        }
        memset(buf, 0, sizeof(buf));
        int len = recv(client, buf, sizeof(buf), 0);
        buf[len] = '\0';
        std::cout << "[SERVER INFO]:" << buf << std::endl;
    }
    close(client);
    return 0;
}

