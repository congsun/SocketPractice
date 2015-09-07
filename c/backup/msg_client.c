// CS 6421 - Simple Message Board Client in C
// T. Wood
// Compile with: gcc msg_client -o msg_client
// Run with:     ./msg_client

// @author Cong Sun
// @Gwid G48099998

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>

int main(int argc, char ** argv)
{

    //System Argument should be [fileName] [Host IP] [Port Number] [Message_Name] [Message_Content], check the count for the argument before try to run the program
    if(argc!=5){
        printf("error");
        exit(-1);
    }
    
    char* server_port = argv[2];
    char* server_ip = argv[1];
    
    struct addrinfo hints, *server;
    int rc;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    if ((rc = getaddrinfo(server_ip, server_port, &hints, &server)) != 0) {
        perror(gai_strerror(rc));
        exit(-1);
    }
    
    int sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1) {
        perror("ERROR opening socket");
        exit(-1);
    }
    rc = connect(sockfd, server->ai_addr, server->ai_addrlen);
    if (rc == -1) {
        perror("ERROR on connect");
        close(sockfd);
        exit(-1);
    }
    
    //Alloc the memory space for the message to be sent
    char *socketMessage = malloc(strlen(argv[3])+strlen("\n")+strlen(argv[4])+1);
    socketMessage[0] = '\0';
    strcat(socketMessage,argv[3]);
    strcat(socketMessage,"\n");
    strcat(socketMessage,argv[4]);
    
    
    send(sockfd,socketMessage,strlen(socketMessage),0);
    
    

        printf("Done.\n");
        return 0;
}
