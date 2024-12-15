#include<stdio.h>
#include <sys/socket.h>

int main(){
    int createSocket = socket(AF_INET, SOCK_STREAM, 0);
    // connect(createSocket  );

    printf("%s socket:/n", createSocket);

    
}