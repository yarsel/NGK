//============================================================================
// Description : file_server in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "iknlib.h"

using namespace std;



void sendFile(string fileName, long fileSize, int outToClient);

/**
 * main starter serveren og venter på en forbindelse fra en klient
 * Læser filnavn som kommer fra klienten.
 * Undersøger om filens findes på serveren.
 * Sender filstørrelsen tilbage til klienten (0 = Filens findes ikke)
 * Hvis filen findes sendes den nu til klienten
 *
 * HUSK at lukke forbindelsen til klienten og filen når denne er sendt til klienten
 *
 * @throws IOException
 *
 */
int main(int argc, char *argv[])
{

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 3) 
    {
        error("ERROR, no port provided");
    }

    //creating socket now.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


    //time for checking bind.
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0);
        error("Error on binding");


    // time for listen.
    listen(sockfd,5);

    for(;;)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        bzero(buffer, 1000);

        //nu læses filnavnet fra clienten.
        readTextTCP(buffer, 1000, newsockfd);

        const char *filename = extractFileName(buffer);
        long fileSize = check_File_Exists(filename);

        if(fileSize)
            sendFile(filename, fileSize, newsockfd);
        close(newsockfd);
    }
}   

/**
 * Sender filen som har navnet fileName til klienten
 *
 * @param fileName Filnavn som skal sendes til klienten
 * @param fileSize Størrelsen på filen, 0 hvis den ikke findes
 * @param outToClient Stream som der skrives til socket
     */
void sendFile(const char *fileName, long fileSize, int outToClient)
{
    // TO DO Your own code
    
    // open file
    FILE * fp;
    fp = fopen(fileName,"r"); // "r" for read mode of the file. 


    // gentag indtil alt fil data er sendt
    for (long i = 0; i <= fileSize; i + 1000)
    {
        // læs blok fra fil
        
        // send blok over til client

    }


    // luk fil 
}

