#ifndef RAW_SOCKET_H 
#define RAW_SOCKET_H

/* *******************************************************
   * @File                 : raw_socket.h
   * @Author               : mohamed bahget hamam
   * @gmail                : mahamedhamam15@gmail.com
   *******************************************************
*/

unsigned short checksum(void *data_pointer , int len);
/* 
   * @brief                       : function to ensure that the packet isn't corrupted during the transmission.
   * 
   * @param=>(data_pointer)       : pointer to the data (packet).
   * 
   * @param=>(len)                : the length of the data in bytes.   
*/






/* *******************************************************
   @User                 
   *******************************************************
   mohamed hamam      
*/

#endif