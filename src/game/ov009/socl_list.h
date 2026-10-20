#ifndef GAME_OV009_SOCL_LIST_H
#define GAME_OV009_SOCL_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_list.c, prototypes copied from their definitions. */

struct SOCLSocket;

void SOCLi_SocketRegister(void *a);
void SOCLi_SocketRegisterList(void **next, char *socket);
void SOCLi_SocketRegisterTrash(int a);
void SOCLi_SocketUnregister(int a);
struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next, struct SOCLSocket *socket);
void SOCLi_SocketUnregisterTrash(int a);
int SOCL_SocketIsInvalid(struct SOCLSocket *socket);
int SOCL_SocketIsInTrash(void *b);
/* END mkheaders: generated region */

#endif
