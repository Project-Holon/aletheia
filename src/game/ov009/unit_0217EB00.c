/*
 * file:     unit_0217EB00.c
 * unit:     yes
 * function: func_0217EB00, func_0217EB18, func_0217EB2C, func_0217EB40, func_0217EB9C, func_0217EBB0, func_0217EC08, func_0217EC4C, recvfrom, func_0217EC90, func_0217ECA4, func_0217ECF8, func_0217ED0C, func_0217ED38, func_0217ED54, func_0217ED64, func_0217EE50, func_0217EF00, func_0217EF50, func_0217EF84, func_0217EFB8, func_0217F038
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
 *   g_021AD0F4  0x021AD0F4  data
 *   SOC_Close        0x0215f644 arm
 *   SOCL_IsReleased  0x0215e7c8 arm
 *   CheckRcode       0x0217eb00 arm
 *   SOC_Bind         0x0215f454 arm
 *   SOC_Connect      0x0215f480 arm
 *   SOC_RecvFrom     0x0215f500 arm
 *   func_0215F5B4                  0x0215F5B4  arm ov009
 *   SOC_Accept       0x0215f714 arm
 *   func_0215FAD0  0x0215FAD0  arm  ov009
 *   func_0215FBCC  0x0215FBCC  arm  ov009
 *   func_0215F854  0x0215F854  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A3740     0x021A3740  data
 *   g_021A374C     0x021A374C  data
 *   g_021A375C     0x021A375C  data
 *   g_021A3784     0x021A3784  data
 *   setsockopt       0x0217ecf8 arm
 *   GSISocketSelect  0x0217ed64 arm
 *   func_0215EF48                  0x0215EF48  arm ov009
 *   func_0215FBAC                  0x0215FBAC  arm ov009
 *   g_021A37BC                     0x021A37BC  data
 *   _ZZ13func_0217EFB8vE9aliases_0 0x021AD0F4  data
 *   _ZZ13func_0217EFB8vE9localhost_0 0x021AD0FC  data
 *   _ZZ13func_0217EFB8vE5ips_2_1   0x021AD10C  data
 *   _ZZ13func_0217EFB8vE8ipPtrs_1_2 0x021AD120  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef struct {
    int fd;
    short events;
    short revents;
} GSPollFd;

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

struct SOCInAddr {
    unsigned int addr;
};

extern int func_0215F428(void);
extern int func_0215F644(int s);
extern int SOC_Close(int s);
extern int SOCL_IsReleased(int s);
extern int CheckRcode(int rcode, int errCode);
extern int func_0215F638(int s, int how);
struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
} __attribute__((packed));
extern int SOC_Bind(int s, void * sockAddr);
extern int SOC_Connect(int s, void * sockAddr);
extern int func_0215F4DC(void);
extern int SOC_RecvFrom(int s, void * buf, int len, int flags, void * sockFrom);
extern int func_0215F590(void);
extern int func_0215F5B4(int s, void *buf, int len, int flags, void *sockTo);
extern int SOC_Accept(int s, void * sockAddr);
extern int func_0215FAD0(char *cp, unsigned long *inp);
extern int func_0215FBCC(GSPollFd *fds, int nfds, int timeout, int flags);
extern int func_0215F854(int sock, int cmd, int arg);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int setsockopt(int s, int level, int optname, void * optval, int optlen);
extern int GSISocketSelect(int theSocket, int * theReadFlag, int * theWriteFlag, int * theExceptFlag);
extern unsigned long func_0215EF48(void);
extern void func_0215FBAC(unsigned long adr_u32, unsigned char *adr_4u8);
/*
 * Stores a negative argument at +0x4 of the module state object and returns the second.
 */
int func_0217EB00(int a, int b);
/*
 * Calls the module setter on the value with the sentinel -1.
 */
int func_0217EB18(int pf, int type, int protocol);
int func_0217EB2C(int sock);
int closesocketsure(int sock, int *notInCloseSocket);
int func_0217EB9C(int sock, int how);
int bind(int sock, const struct SOCSockAddr * addr, int len);
int connect(int sock, const struct SOCSockAddr * addr, int len);
int func_0217EC4C(int sock, char *buffer, int len, int flags);
int recvfrom(int sock, char * buf, int len, int flags, struct SOCSockAddr * addr, int * fromlen);
int func_0217EC90(int sock, char *buffer, int bufferLen, int flags);
int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
/*
 * Tail call with the constant pair (0, -1).
 */
void func_0217ECF8(void);
int getsockname(int sock, struct SOCSockAddr * addr, int * len);
/*
 * The word the call fills in, or -1.
 */
int func_0217ED38(int a);
/*
 * The word at +4 of the module state block.
 */
int func_0217ED54(int sock);
int func_0217ED64(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
/*
 * SetSockBlocking: read the socket's fcntl flags (SOC_Fcntl cmd 3), set or * clear the non-blocking bit (4), write them back (cmd 4), and log the * outcome through gsDebugFormat. Returns 1 on success, 0 on failure. * * EXACT*: the inferred extent ran four bytes long into the unlabelled * follower at 0x0217EF00 (a leaf whose prologue saves r0-r3, not lr, so * disasm.py does not trace it); seed that start to make the extent exact.
 */
int func_0217EE50(int sock, int isblocking);
int SetReceiveBufferSize(int sock, int size);
int CanReceiveOnSocket(int sock);
int CanSendOnSocket(int sock);
/*
 * sdk: getlocalhost (gsplatformsocket) * * note: function-local statics, declared in the order aliases_0, localhost, * ips_2, ipPtrs_1 (they reach r4 as one base). The first literal (+0x6C) is * relocated against `.bss`+0 by 1.1p1; the four static symbols: lines place * that section and agree on one base.
 */
struct SOCHostEnt *func_0217EFB8(void);
int IsPrivateIP(struct SOCInAddr * addr);
extern char g_021AD0F4[];
extern char g_021A3740[];
extern char g_021A374C[];
extern char g_021A375C[];
extern char g_021A3784[];
extern char g_021A37BC[];




int func_0217EB00(int a, int b)
{
    if (a < 0) {
        *(int *)(g_021AD0F4 + 0x4) = a;
        return b;
    }
    return a;
}




int func_0217EB18(int pf, int type, int protocol)
{
    return func_0217EB00(func_0215F428(), -1);
}




int func_0217EB2C(int sock)
{
    return func_0217EB00(func_0215F644(sock), -1);
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




int func_0217EB9C(int sock, int how)
{
    return func_0217EB00(func_0215F638(sock, how), -1);
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



int func_0217EC4C(int sock, char *buffer, int len, int flags)
{
    return func_0217EB00(func_0215F4DC(), -1);
}





int recvfrom(int sock, char * buf, int len, int flags, struct SOCSockAddr * addr, int * fromlen)
{
    int rcode;

    addr->len = (unsigned char)*fromlen;
    rcode = SOC_RecvFrom(sock, buf, len, flags, addr);
    *fromlen = addr->len;
    return CheckRcode(rcode, -1);
}



int func_0217EC90(int sock, char *buffer, int bufferLen, int flags)
{
    return func_0217EB00(func_0215F590(), -1);
}



/*
 * sdk:      sendto (gsplatformsocket)
 *
 * Closed (w4_nm): the address copy is memcpy(&remoteAddr, addr, sizeof(remoteAddr))
 * with the string.h prototype, so mwccarm inlines it as the two-byte loop with the
 * object's source/dest registers (the struct assignment swapped them).
 */
int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    memcpy(&remoteAddr, addr, sizeof(remoteAddr));
    remoteAddr.len = tolen;
    rcode = func_0215F5B4(sock, buf, len, flags, &remoteAddr);
    return func_0217EB00(rcode, -1);
}




void func_0217ECF8(void)
{
    func_0217EB00(0, -1);
}




int getsockname(int sock, struct SOCSockAddr * addr, int * len)
{
    int rcode;

    addr->len = (unsigned char)*len;
    rcode = SOC_Accept(sock, addr);
    *len = addr->len;
    return CheckRcode(rcode, -1);
}



int func_0217ED38(int a)
{
    int v;

    if (func_0215FAD0((char *)a, (long unsigned int *)(&v)) == 0) {
        return -1;
    }

    return v;
}



int func_0217ED54(int sock)
{
    return *(int *)(g_021AD0F4 + 4);
}



int func_0217ED64(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag)
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

    result = func_0215FBCC(&pfd, 1, 0, 0);
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
int func_0217EE50(int sock, int isblocking)
{
    int val;
    int rcode;

    val = func_0215F854(sock, 3, 0);
    if (isblocking)
        val &= ~4;
    else
        val |= 4;
    rcode = func_0215F854(sock, 4, val);
    if (rcode == 0) {
        func_0217D254(12, 0, 0x10, g_021A375C, sock, isblocking ? g_021A3740 : g_021A374C);
        return 1;
    }
    func_0217D254(12, 0, 0x10, g_021A3784, sock, isblocking ? g_021A3740 : g_021A374C);
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
struct SOCHostEnt *func_0217EFB8(void)
{
    static char *aliases_0[2];
    static struct SOCHostEnt localhost;
    static unsigned int ips_2[5];
    static unsigned char *ipPtrs_1[6];

    localhost.name = g_021A37BC;
    localhost.aliases = aliases_0;
    localhost.addrType = 2;
    localhost.length = 0;
    localhost.addrList = ipPtrs_1;
    ips_2[0] = 0;
    func_0215FBAC(func_0215EF48(), (unsigned char *)ips_2);
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
