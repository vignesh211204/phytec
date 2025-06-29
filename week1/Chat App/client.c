#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1" // Change to server's IP if remote
#define SERVER_PORT 8080
#define BUFLEN 512

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFLEN];
    socklen_t addr_len = sizeof(server_addr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    while (1) {
        printf("You: ");
        fgets(buffer, BUFLEN, stdin);
        sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *) &server_addr, addr_len);

        int n = recvfrom(sockfd, (char *)buffer, BUFLEN, 0, (struct sockaddr *) &server_addr, &addr_len);
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);
    }
    close(sockfd);
    return 0;
}
