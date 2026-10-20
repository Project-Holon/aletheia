#ifndef GAME_OV009_SOC_H
#define GAME_OV009_SOC_H

#include "../ov009/qr2_types.h"

/* A SOCL socket handle points at this object; only the blocking flag at 0xae is read here. */
typedef struct SOCSockFlags {
    unsigned char pad[0xae];
    signed char flag;
} SOCSockFlags;

typedef struct PollFD {
    int fd;
    short events;
    short revents;
} PollFD;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of soc.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_soc.h"

int SOC_Socket(int pf, int type, int protocol);
int SOC_Bind(int s, void *sockAddr);
int SOC_Connect(int s, void * sockAddr);
int SOC_Recv(int s, void *buf, int len, int flags);
int SOC_RecvFrom(int s, int buf, int len, int flags, u8 *sockFrom);
int SOC_Send(int s, void *buf, int len, int flags);
int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo);
int SOC_Shutdown(int s, int how);
int SOC_Close(int s);
SOCHostEnt *SOC_GetHostByName(const char *name);
int SOC_GetSockName(u8 *sock, u8 *sockAddr);
long SOC_GetHostID(void);
int SOC_SetResolver(unsigned long *dns1, unsigned long *dns2);
int SOC_Startup(const SOCConfig *config);
int SOC_Cleanup(void);
char *SOC_InetNtoA(struct SOCInAddr in);
int SOC_InetAtoN(char *cp, unsigned long *inp);
char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len);
void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
int SOC_Fcntl(SOCSockFlags *s, int cmd, int flags);
int SOC_Poll(PollFD *fds, unsigned int nfds, long long timeout);
/* END mkheaders: generated region */

#endif
