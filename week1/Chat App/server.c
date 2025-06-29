#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFLEN 512

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFLEN];
    socklen_t addr_len = sizeof(client_addr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Chat Server started on port %d\n", PORT);

    while (1) {
        int n = recvfrom(sockfd, (char *)buffer, BUFLEN, 0, (struct sockaddr *) &client_addr, &addr_len);
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        printf("You: ");
        fgets(buffer, BUFLEN, stdin);
        sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *) &client_addr, addr_len);
    }
    close(sockfd);
    return 0;
}
