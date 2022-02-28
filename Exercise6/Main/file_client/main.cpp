//============================================================================
// Description : file_client in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "iknlib.h"

using namespace std;

void receiveFile(string fileName, int socketfd);

int main(int argc, char *argv[])
{
	// TO DO Your own code
  printf("Starting client...\n");

  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];

  if (argc < 3)
	    error( "ERROR usage: ""hostname"",  ""port""");

	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	    error("ERROR opening socket");

	server = gethostbyname(argv[1]);
	if (server == NULL)
	    error("ERROR no such host");

	printf("Server at: %s, port: %s\n",argv[1], argv[2]);


  // Write to server
  printf("Enter name of file to request (directory optional):\n");
  fgets(buffer,sizeof(buffer),stdin);
  // ?Programmet stopper her?
  writeTextTCP(sockfd,buffer);

  // Read filesize
  printf("test2");
  if ("0"==readTextTCP(buffer,20,sockfd)) // med \n?
    {
      error("File does not exist\n. Exiting.");
    }
  else
    error("Test");
}

/**
 * Modtager filstørrelsen og udskriver meddelelsen: "Filen findes ikke" hvis størrelsen = 0
 * ellers
 * Åbnes filen for at skrive de bytes som senere modtages fra serveren (HUSK kun selve filnavn)
 * Modtag og gem filen i blokke af 1000 bytes indtil alle bytes er modtaget.
 * Luk filen, samt input output streams
 *
 * @param fileName Det fulde filnavn incl. evt. stinavn
 * @param sockfd Stream for at skrive til/læse fra serveren
 */
void receiveFile(string fileName, int sockfd)
{
	// TO DO Your own code
}
