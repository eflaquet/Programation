#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<iostream>


#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
int main(){
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

SOCKET sock;
sock = socket(AF_INET, SOCK_DGRAM, 0);

fprintf(stderr, "socket() message: %s\n", strerror(errno));
SOCKADDR_IN destAddrUdp;
destAddrUdp.sin_addr.s_addr = inet_addr("192.168.65.40");
destAddrUdp.sin_family = AF_INET;
destAddrUdp.sin_port = htons(205);

char buffer[7];
buffer[0]= 'l';
buffer[1]= 'e';
buffer[2]= '1';
buffer[3]= '0';
buffer[4]= ':';
buffer[5]= 0x0a;
buffer[6]='\0';
socklen_t tailleudp = sizeof(destAddrUdp);
int error_message;
int octet_message = sendto(sock,buffer,sizeof(buffer),0,(SOCKADDR*)&destAddrUdp,sizeof(destAddrUdp));
 if(octet_message == 0){
	 fprintf(stderr, "sendto message erreur : %s\n", strerror(errno));
	 }
	 close(sock);
}