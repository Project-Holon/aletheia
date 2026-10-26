#ifndef GAME_OV009_SOCL_COMMAND_H
#define GAME_OV009_SOCL_COMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_command.c, prototypes copied from their definitions. */

struct SOCLiCommandPacket;
struct SOCLSocket;

int SOCLi_StartupCommandPacketQueue(int packetCount);
int SOCLi_CleanupCommandPacketQueue(void);
struct SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag);
struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
void SOCLi_FreeCommandPacket(void *ptr);
void *SOCLi_GetCtrlPipe(struct SOCLSocket *socket, struct SOCLiCommandPacket *b);
int SOCLi_SendCommandPacket(void *queue, struct SOCLiCommandPacket *packet);
void SOCLi_SendCommandPacketToCtrlPipe(struct SOCLSocket *socket, struct SOCLiCommandPacket *packet);
int SOCLi_ExecCommandPacket(void *pipe, struct SOCLiCommandPacket *command);
int SOCLi_ExecCommandPacketInRecvPipe(struct SOCLSocket *socket, struct SOCLiCommandPacket *command);
int SOCLi_ExecCommandPacketInSendPipe(struct SOCLSocket *socket, struct SOCLiCommandPacket *command);
void SOCLi_ExecCommandPacketInCtrlPipe(struct SOCLSocket *socket, struct SOCLiCommandPacket *packet);
void SOCLi_CommandPacketHandler(void *arg);
/* END mkheaders: generated region */

#endif
