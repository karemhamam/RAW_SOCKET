/* *******************************************************
   * @File                 : raw_socket.c
   * @Author               : mohamed bahget hamam
   * @gmail                : mahamedhamam15@gmail.com
   *******************************************************
*/


/* **************** include section start *************** */

#include <stdio.h>           // for standard I/O functions
#include <string.h>          // for string functions like memset()
#include <sys/socket.h>      // for socket functions like socket()
#include <netinet/ip_icmp.h> // for defining ICMP header structures.
#include <netinet/in.h>      // for working with internet addresses
#include <arpa/inet.h>       // for converting IP addresses between different formats.
#include <unistd.h>          // for close() to close the socket
#include "raw_socket.h"

/* **************** include section end *************** */


/* **************** main section start *************** */

int main()
{
    int sockfd = socket(AF_INET , SOCK_RAW , IPPROTO_ICMP); // creates a raw socket
    if (sockfd < 0 )
    {
        perror("socket");
        return -1 ;
    }

    struct sockaddr_in addr; // This is a structure that holds information about where we want to send our message.
    addr.sin_family = AF_INET; // This specifies that we're using IPv4 addresses.
    addr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Google DNS

    char packet[64];  // A buffer to hold our packet data (64 bytes).
    struct icmphdr *icmp = (struct icmphdr *)packet;
    icmp->type = ICMP_ECHO;          // Type of ICMP message (Echo request, AKA ping).
    icmp->code = 0;                  // Code 0 means no special conditions.
    icmp->checksum = 0;              // We’ll calculate the checksum later.
    icmp->un.echo.id = 1234;         // An arbitrary identifier for the ping (it can be any number).
    icmp->un.echo.sequence = 1;      // Sequence number (can be incremented for multiple pings).

    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
        perror("sendto");
        return -1;
    }

    close(sockfd);
    
    return 0 ;
}

/* **************** main section end *************** */


/* **************** defination section end *************** */

unsigned short checksum(void *data_pointer , int len)
{
    unsigned short *buf = data_pointer ; // treats the input data as a series of 2-byte chunks.
    unsigned int sum = 0 ;               // initializes the sum variable to check the checksum value.

    /* loop through the dat to bytes at a time, adding each to the sum */
    for (sum = 0 ; len > 1 ; len -= 2)
    {
        sum += *buf++;
    }

    /* if there's an odd number of bytes , add teh last remaining byte */
    if(len == 1 )
    {
        sum += *(unsigned char *)buf;
    }

    /* fold the sum to fit into 16 bits. add any overflow from higher bits to lower bits. */
    sum = ( sum >> 16 ) + (sum & 0xFFFF);
    sum += ( sum >> 16); // ensure any remaining overflow is added

    /* now let's return the bitwise inverse of the sum*/
    return (~sum);

}

/* **************** defination section end *************** */

/* *******************************************************
   @User                 
   *******************************************************
   mohamed hamam      
*/