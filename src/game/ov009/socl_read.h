#ifndef GAME_OV009_SOCL_READ_H
#define GAME_OV009_SOCL_READ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_read.c, prototypes copied from their definitions. */

struct SOCLSocket;

int SOCL_ReadFrom(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, int flags);
int SOCLi_ReadAndConsumeBuffer(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, int flag_block, int flags);
int SOCLi_ReadBuffer(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, long flag_block);
unsigned char *SOCLi_ReadCPSBuffer(struct SOCLSocket *socket, long *buffer_len, unsigned short *local_port, unsigned short *remote_port, unsigned long *remote_ip);
int SOCLi_ExecReadCommand(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, long flag_block);
int SOCLi_ConsumeBuffer(struct SOCLSocket *socket);
int SOCLi_ConsumeCallBack(void *arg);
long SOCLi_ConsumeCPSBuffer(struct SOCLSocket *socket);
int SOCLi_UdpRecvCallback(unsigned char *data, unsigned long len, struct SOCLSocket *socket);
/* END mkheaders: generated region */

#endif
