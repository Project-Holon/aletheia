#ifndef GAME_OV009_GSPLATFORMSOCKET_H
#define GAME_OV009_GSPLATFORMSOCKET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsplatformsocket.c, prototypes copied from their definitions. */

struct SOCSockAddr;
struct SOCHostEnt;
struct SOCInAddr;

int CheckRcode(int rcode, int fallback);
int socket(int pf, int type, int protocol);
int closesocket(int sock);
int closesocketsure(int sock, int *notInCloseSocket);
int shutdown(int sock, int how);
int bind(int sock, const struct SOCSockAddr * addr, int len);
int connect(int sock, const struct SOCSockAddr * addr, int len);
int recv(int sock, char *buffer, int len, int flags);
int recvfrom(int sock, char * buf, int len, int flags, struct SOCSockAddr * addr, int * fromlen);
int send(int sock, char *buffer, int bufferLen, int flags);
int sendto(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
int setsockopt(int s, int level, int optname, void *optval, int optlen);
int getsockname(int sock, struct SOCSockAddr * addr, int * len);
int inet_addr(char *addrString);
int GOAGetLastError(int sock);
int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
int SetSockBlocking(int sock, int isblocking);
int SetReceiveBufferSize(int sock, int size);
int CanReceiveOnSocket(int sock);
int CanSendOnSocket(int sock);
struct SOCHostEnt *getlocalhost(void);
int IsPrivateIP(struct SOCInAddr * addr);
/* END mkheaders: generated region */

#endif
