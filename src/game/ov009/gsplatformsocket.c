/*
 * file:     gsplatformsocket.c
 * unit:     yes
 * function: CheckRcode, socket, closesocket, closesocketsure, shutdown, bind, connect, recv, recvfrom, send, sendto, setsockopt, getsockname, inet_addr, GOAGetLastError, GSISocketSelect, SetSockBlocking, SetReceiveBufferSize, CanReceiveOnSocket, CanSendOnSocket, getlocalhost, IsPrivateIP
 * address:  0x0217EB00
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gGsSocketError  0x021AD0F4  data
 *   SOC_Close        0x0215f644 arm
 *   SOCL_IsReleased  0x0215e7c8 arm
 *   CheckRcode       0x0217eb00 arm
 *   SOC_Bind         0x0215f454 arm
 *   SOC_Connect      0x0215f480 arm
 *   SOC_RecvFrom     0x0215f500 arm
 *   SOC_SendTo                  0x0215F5B4  arm ov009
 *   SOC_Accept       0x0215f714 arm
 *   SOC_InetAtoN  0x0215FAD0  arm  ov009
 *   SOC_Poll  0x0215FBCC  arm  ov009
 *   SOC_Fcntl  0x0215F854  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gGsSocketBlockingStr     0x021A3740  data
 *   gGsSocketNonBlockingStr     0x021A374C  data
 *   gGsSetSockBlockingFmt     0x021A375C  data
 *   gGsSetSockBlockingFailFmt     0x021A3784  data
 *   setsockopt       0x0217ecf8 arm
 *   GSISocketSelect  0x0217ed64 arm
 *   SOCL_GetHostID                  0x0215EF48  arm ov009
 *   SOC_U32to4U8                  0x0215FBAC  arm ov009
 *   gGsLocalhostName                     0x021A37BC  data
 *   _ZZ12getlocalhostvE9aliases_0 0x021AD0F4  data
 *   _ZZ12getlocalhostvE9localhost_0 0x021AD0FC  data
 *   _ZZ12getlocalhostvE5ips_2_1   0x021AD10C  data
 *   _ZZ12getlocalhostvE8ipPtrs_1_2 0x021AD120  data
 *   SOC_Shutdown  0x0215F638  arm
 *   SOC_Socket  0x0215F428  arm
 *   SOC_Recv  0x0215F4DC  arm
 *   SOC_Send  0x0215F590  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef struct {
    int fd;
    short events;
    short revents;
} GSPollFd;

#include "../sdk_soc.h"

extern int SOC_Socket(int pf, int type);
extern int SOC_Close(int s);
extern int SOCL_IsReleased(int s);
extern int CheckRcode(int rcode, int errCode);
extern int SOC_Shutdown(int s, int how);
struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
} __attribute__((packed));
extern int SOC_Bind(int s, void * sockAddr);
extern int SOC_Connect(int s, void * sockAddr);
extern int SOC_Recv(int s, void *buf, int len, int flags);
extern int SOC_RecvFrom(int s, int buf, int len, int flags, unsigned char *sockFrom);
extern int SOC_Send(int s, void *buf, int len, int flags);
extern int SOC_SendTo(int s, void *buf, int len, int flags, void *sockTo);
extern int SOC_Accept(int s, void * sockAddr);
extern int SOC_InetAtoN(char *cp, unsigned long *inp);
extern int SOC_Poll(GSPollFd *fds, int nfds, int timeout, int flags);
extern int SOC_Fcntl(int sock, int cmd, int arg);
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
extern int setsockopt(int s, int level, int optname, void * optval, int optlen);
extern int GSISocketSelect(int theSocket, int * theReadFlag, int * theWriteFlag, int * theExceptFlag);
extern unsigned long SOCL_GetHostID(void);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
/*
 * Stores a negative argument at +0x4 of the module state object and returns the second.
 */
/*
 * Calls the module setter on the value with the sentinel -1.
 */
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
/*
 * Tail call with the constant pair (0, -1).
 */
int getsockname(int sock, struct SOCSockAddr * addr, int * len);
/*
 * The word the call fills in, or -1.
 */
int inet_addr(char *a);
/*
 * The word at +4 of the module state block.
 */
int GOAGetLastError(int sock);
/*
 * SetSockBlocking: read the socket's fcntl flags (SOC_Fcntl cmd 3), set or * clear the non-blocking bit (4), write them back (cmd 4), and log the * outcome through gsDebugFormat. Returns 1 on success, 0 on failure. * * EXACT*: the inferred extent ran four bytes long into the unlabelled * follower at 0x0217EF00 (a leaf whose prologue saves r0-r3, not lr, so * disasm.py does not trace it); seed that start to make the extent exact.
 */
int SetSockBlocking(int sock, int isblocking);
int SetReceiveBufferSize(int sock, int size);
int CanReceiveOnSocket(int sock);
int CanSendOnSocket(int sock);
/*
 * sdk: getlocalhost (gsplatformsocket) * * note: function-local statics, declared in the order aliases_0, localhost, * ips_2, ipPtrs_1 (they reach r4 as one base). The first literal (+0x6C) is * relocated against `.bss`+0 by 1.1p1; the four static symbols: lines place * that section and agree on one base.
 */
struct SOCHostEnt *getlocalhost(void);
int IsPrivateIP(struct SOCInAddr * addr);
extern char gGsSocketError[];
extern char gGsSocketBlockingStr[];
extern char gGsSocketNonBlockingStr[];
extern char gGsSetSockBlockingFmt[];
extern char gGsSetSockBlockingFailFmt[];
extern char gGsLocalhostName[];




int CheckRcode(int rcode, int fallback)
{
    if (rcode < 0) {
        *(int *)(gGsSocketError + 0x4) = rcode;
        return fallback;
    }
    return rcode;
}




int socket(int pf, int type, int protocol)
{
    return CheckRcode(SOC_Socket(pf, type), -1);
}




int closesocket(int sock)
{
    return CheckRcode(SOC_Close(sock), -1);
}




int closesocketsure(int sock, int *notInCloseSocket)
{
    int rcode;

    rcode = SOC_Close(sock);
    if (rcode == 0) {
        *notInCloseSocket = (*notInCloseSocket == 0) ? 1 : 0;
        return *notInCloseSocket;
    }
    if (SOCL_IsReleased(sock) == 0)
        return 0;
    CheckRcode(rcode, -1);
    *notInCloseSocket = 1;
    return 1;
}




int shutdown(int sock, int how)
{
    return CheckRcode(SOC_Shutdown(sock, how), -1);
}




int bind(int sock, const struct SOCSockAddr * addr, int len)
{
    struct SOCSockAddr localAddr;
    int rcode;

    if (addr->port == 0)
        return 0;

    localAddr = *addr;
    localAddr.len = len;
    rcode = SOC_Bind(sock, &localAddr);
    return CheckRcode(rcode, -1);
}



int connect(int sock, const struct SOCSockAddr * addr, int len)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    remoteAddr = *addr;
    remoteAddr.len = len;
    rcode = SOC_Connect(sock, &remoteAddr);
    return CheckRcode(rcode, -1);
}



int recv(int sock, char *buffer, int len, int flags)
{
    return CheckRcode(SOC_Recv(sock, buffer, len, flags), -1);
}





int recvfrom(int sock, char * buf, int len, int flags, struct SOCSockAddr * addr, int * fromlen)
{
    int rcode;

    addr->len = (unsigned char)*fromlen;
    rcode = SOC_RecvFrom((int)sock, (int)buf, len, flags, (unsigned char *)addr);
    *fromlen = addr->len;
    return CheckRcode(rcode, -1);
}



int send(int sock, char *buffer, int bufferLen, int flags)
{
    return CheckRcode(SOC_Send(sock, buffer, bufferLen, flags), -1);
}



/*
 * sdk:      sendto (gsplatformsocket)
 *
 * Closed (w4_nm): the address copy is memcpy(&remoteAddr, addr, sizeof(remoteAddr))
 * with the string.h prototype, so mwccarm inlines it as the two-byte loop with the
 * object's source/dest registers (the struct assignment swapped them).
 */
int sendto(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    memcpy(&remoteAddr, addr, sizeof(remoteAddr));
    remoteAddr.len = tolen;
    rcode = SOC_SendTo(sock, buf, len, flags, &remoteAddr);
    return CheckRcode(rcode, -1);
}




int setsockopt(int s, int level, int optname, void *optval, int optlen)
{
    return CheckRcode(0, -1);
}




int getsockname(int sock, struct SOCSockAddr * addr, int * len)
{
    int rcode;

    addr->len = (unsigned char)*len;
    rcode = SOC_Accept(sock, addr);
    *len = addr->len;
    return CheckRcode(rcode, -1);
}



int inet_addr(char *addrString)
{
    int v;

    if (SOC_InetAtoN((char *)addrString, (long unsigned int *)(&v)) == 0) {
        return -1;
    }

    return v;
}



int GOAGetLastError(int sock)
{
    return *(int *)(gGsSocketError + 4);
}



int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag)
{
    GSPollFd pfd;
    int result;

    pfd.fd = theSocket;
    pfd.events = 0;
    if (theReadFlag != 0)
        pfd.events |= 1;
    if (theWriteFlag != 0)
        pfd.events |= 8;
    pfd.revents = 0;

    result = SOC_Poll(&pfd, 1, 0, 0);
    if (result < 0)
        return -1;

    if (theReadFlag != 0) {
        if (result > 0 && (pfd.revents & 0x41))
            *theReadFlag = 1;
        else
            *theReadFlag = 0;
    }
    if (theWriteFlag != 0) {
        if (result > 0 && (pfd.revents & 0x8))
            *theWriteFlag = 1;
        else
            *theWriteFlag = 0;
    }
    if (theExceptFlag != 0) {
        if (result > 0 && (pfd.revents & 0x20))
            *theExceptFlag = 1;
        else
            *theExceptFlag = 0;
    }
    return result;
}



/*
 * SetSockBlocking: read the socket's fcntl flags (SOC_Fcntl cmd 3), set or
 * clear the non-blocking bit (4), write them back (cmd 4), and log the
 * outcome through gsDebugFormat.  Returns 1 on success, 0 on failure.
 *
 * EXACT*: the inferred extent ran four bytes long into the unlabelled
 * follower at 0x0217EF00 (a leaf whose prologue saves r0-r3, not lr, so
 * disasm.py does not trace it); seed that start to make the extent exact.
 */
int SetSockBlocking(int sock, int isblocking)
{
    int val;
    int rcode;

    val = SOC_Fcntl(sock, 3, 0);
    if (isblocking)
        val &= ~4;
    else
        val |= 4;
    rcode = SOC_Fcntl(sock, 4, val);
    if (rcode == 0) {
        gsDebugFormat(12, 0, 0x10, gGsSetSockBlockingFmt, sock, isblocking ? gGsSocketBlockingStr : gGsSocketNonBlockingStr);
        return 1;
    }
    gsDebugFormat(12, 0, 0x10, gGsSetSockBlockingFailFmt, sock, isblocking ? gGsSocketBlockingStr : gGsSocketNonBlockingStr);
    return 0;
}



int SetReceiveBufferSize(int sock, int size)
{
    int rcode;

    rcode = setsockopt(sock, 0xffff, 0x1002, &size, 4);
    return (rcode != -1);
}



int CanReceiveOnSocket(int sock)
{
    int aReadFlag = 0;

    if (GSISocketSelect(sock, &aReadFlag, 0, 0) == 1)
        return aReadFlag;
    return 0;
}



int CanSendOnSocket(int sock)
{
    int aWriteFlag = 0;

    if (GSISocketSelect(sock, 0, &aWriteFlag, 0) == 1)
        return aWriteFlag;
    return 0;
}



/*
 * sdk:      getlocalhost (gsplatformsocket)
 *
 * note: function-local statics, declared in the order aliases_0, localhost,
 * ips_2, ipPtrs_1 (they reach r4 as one base).  The first literal (+0x6C) is
 * relocated against `.bss`+0 by 1.1p1; the four static symbols: lines place
 * that section and agree on one base.
 */
struct SOCHostEnt *getlocalhost(void)
{
    static char *aliases_0[2];
    static struct SOCHostEnt localhost;
    static unsigned int ips_2[5];
    static unsigned char *ipPtrs_1[6];

    localhost.name = gGsLocalhostName;
    localhost.aliases = aliases_0;
    localhost.addrType = 2;
    localhost.length = 0;
    localhost.addrList = ipPtrs_1;
    ips_2[0] = 0;
    SOC_U32to4U8(SOCL_GetHostID(), (unsigned char *)ips_2);
    if (ips_2[0] == 0)
        return 0;
    ipPtrs_1[0] = (unsigned char *)ips_2;
    localhost.length = 4;
    ipPtrs_1[1] = 0;
    return &localhost;
}



int IsPrivateIP(struct SOCInAddr * addr)
{
    unsigned int ip;
    int b1;
    int b2;

    ip = addr->addr;
    ip = ((ip >> 24) & 0xff) | ((ip >> 8) & 0xff00) | ((ip << 8) & 0xff0000)
       | ((ip << 24) & 0xff000000);
    b2 = (ip >> 24) & 0xff;
    b1 = (ip >> 16) & 0xff;
    if (b2 == 10)
        return 1;
    if (b2 == 172 && b1 >= 16 && b1 <= 31)
        return 1;
    if (b2 == 192 && b1 == 168)
        return 1;
    return 0;
}
