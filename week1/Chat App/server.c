#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int sockfd;
struct sockaddr_in cliaddr;
socklen_t len = sizeof(cliaddr);

void* receive_messages(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("\nClient: %s", buffer);
        fflush(stdout);
    }
    return NULL;
}

void* send_messages(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cliaddr, len);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    int port = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", port);

    pthread_t recv_thread, send_thread;
    pthread_create(&recv_thread, NULL, receive_messages, NULL);
    pthread_create(&send_thread, NULL, send_messages, NULL);

    pthread_join(recv_thread, NULL);
    pthread_join(send_thread, NULL);

    close(sockfd);
    return 0;
}
