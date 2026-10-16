/*
 * file:     nhttp_socket_ntr.c
 * unit:     yes
 * function: NHTTPi_CpsAuthCallback, NHTTPi_CpsAuthCallbackForDebug, NHTTPi_SetSSLseed, NHTTPi_checkKeepAlive, NHTTPi_SocOpen, NHTTPi_SocClose, NHTTPi_SocConnect, NHTTPi_SocSSLConnect, NHTTPi_SocRecv_sub, NHTTPi_SocRecv, NHTTPi_SocRecvRaw, NHTTPi_SocSend, NHTTPi_SocCancel, NHTTPi_resolveHostname
 * address:  0x021B9C6C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC/libdwcauth.TWL.HYB.a(dwc_http.o).  decl_line 769, param result.
 * sdk:      NHTTPi_CpsAuthCallbackForDebug (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 * notes:    a stub the listing printed as data; NHTTPi_SocSSLConnect's
 *           relocation at +0x88 (ABS32 NHTTPi_CpsAuthCallbackForDebug) is the
 *           pool word at 0x021B9EC4.  Seeded in layout/function_starts.txt.
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 *
 * symbols:
 *   gNHTTPSslSeed  0x021CF964  data
 *   SOC_Close 0x0215F644 arm
 *   OS_Sleep 0x02085A38 arm
 *   SOCLi_TrashSocket 0x0215EBB4 arm
 *   NHTTPi_free 0x021BA850 arm ov114
 *   SOC_Connect 0x0215F480 arm
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   SOCL_EnableSsl 0x0215FC80 arm
 *   NHTTPi_CpsAuthCallback 0x021B9C6C arm ov114
 *   SOC_Recv 0x0215F4DC arm
 *   NHTTPi_memcpy 0x021BA100 arm ov114
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_lockReqList  0x021BEFCC  arm  ov114
 *   NHTTPi_unlockReqList  0x021BEFD8  arm  ov114
 *   SOC_InetAtoN 0x0215FAD0 arm
 *   SOC_GetHostByName 0x0215F650 arm
 *   SOC_Shutdown  0x0215F638  arm  ov009
 *   OS_GetLowEntropyData  0x02088168  arm  arm9
 *   CPS_SslAddRandomSeed  0x02162248  arm  ov009
 *   SOC_Socket  0x0215F428  arm  ov009
 *   SOC_Send  0x0215F590  arm  ov009
 */
#include "nhttp_types.h"

typedef struct {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned long addr;
} SOCSockAddrIn;

typedef struct {
    char pad[0xa];
    short h_length;
    char **h_addr_list;
} SOCHostEnt;

typedef struct {
    unsigned long addr;
} SOCInAddr;

extern void OS_GetLowEntropyData(u32 *buffer);
extern void CPS_SslAddRandomSeed(void *, int);
extern int SOC_Recv(int, int *, int, int);
extern void SOC_Socket(int, int, int);
extern int SOC_Close(int socket);
extern void OS_Sleep(unsigned long msec);
extern void SOCLi_TrashSocket(void);
extern void NHTTPi_free(void *ptr_p);
extern int SOC_Connect(int s, void *sockAddr);
extern void *NHTTPi_alloc(unsigned long size, int align);
extern void NHTTPi_memclr(void *dst_p, int size);
extern int SOCL_EnableSsl(int s, NHTTPSslCon *con);
extern int NHTTPi_CpsAuthCallback(int result);
extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);
NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
extern int SOC_Send(int socket, char *buf_p, int len, int flags);
extern void NHTTPi_lockReqList(NHTTPMutexInfo *mutexInfo_p);
extern void NHTTPi_unlockReqList(NHTTPMutexInfo *mutexInfo_p);
extern void SOC_Shutdown(int, int);
extern int SOC_InetAtoN(char *cp, SOCInAddr *inp);
extern SOCHostEnt *SOC_GetHostByName(char *name);
int NHTTPi_CpsAuthCallbackForDebug(void);
void NHTTPi_SetSSLseed(void);
int NHTTPi_checkKeepAlive(int a);
void NHTTPi_SocOpen(void);
int NHTTPi_SocClose(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
int NHTTPi_SocConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, unsigned long hostaddr, int port);
int NHTTPi_SocSSLConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
int NHTTPi_SocRecv_sub(NHTTPConnection *connection_p, int socket, char *buf_p, int len, int flags);
int NHTTPi_SocRecv(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
int NHTTPi_SocRecvRaw(int socket, char *buf_p, int len, int flags);
int NHTTPi_SocSend(NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
void NHTTPi_SocCancel(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
unsigned long NHTTPi_resolveHostname(NHTTPReq *req_p, char *hostname_p);
extern u8 gNHTTPSslSeed[];

static int NHTTPi_CpsAuthCallback(int result)
{
    if (result & 0x8000)
        result &= ~0x8000;
    return result;
}

int NHTTPi_CpsAuthCallbackForDebug(void)
{
    return 0;
}





void NHTTPi_SetSSLseed(void)
{
    OS_GetLowEntropyData((u32 *)gNHTTPSslSeed);
    CPS_SslAddRandomSeed(gNHTTPSslSeed, 0x20);
}





int NHTTPi_checkKeepAlive(int a)
{
    int v = 0;
    if (a == -1) {
        v = -1;
    } else {
        int n = 4;
        int tmp;
        if (SOC_Recv(a, &tmp, 1, n) != n - 10)
            v = n - 5;
    }
    return v;
}





void NHTTPi_SocOpen(void)
{
    SOC_Socket(2, 1, 0);
}





int NHTTPi_SocClose(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket)
{
    int error;
    int elapsed;

    error = SOC_Close(socket);
    if (error == 0 || error == -26) {
        for (elapsed = 0; (error = SOC_Close(socket)) == -26 && elapsed <= 10000; elapsed += 500) {
            OS_Sleep(500);
            SOCLi_TrashSocket();
        }
    }
    if (error != -26 && req_p != 0 && req_p->sslCon_p != 0) {
        NHTTPi_free(req_p->sslCon_p);
        req_p->sslCon_p = 0;
    }
    return error;
}




/*
 * sdk:      NHTTPi_SocConnect (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 */
int NHTTPi_SocConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, unsigned long hostaddr, int port)
{
    SOCSockAddrIn scadr;
    int error;

    scadr.len = 8;
    scadr.family = 2;
    scadr.port = (unsigned short)(((((unsigned short)port) >> 8) & 0xff) | (((unsigned short)port) << 8 & 0xff00));
    scadr.addr = hostaddr;
    if (req_p->isSSL != 0 && req_p->isProxy == 0) {
        error = NHTTPi_SocSSLConnect(bgnEndInfo_p, mutexInfo_p, req_p, socket);
        if (error < 0) {
            return error;
        }
    }
    error = SOC_Connect(socket, &scadr);
    if (error < 0) {
        if (req_p->doCancel != 0) {
            return -1002;
        }
        return -1001;
    }
    return 0;
}





int NHTTPi_SocSSLConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket)
{
    NHTTPSslCon *sslCon_p;

    sslCon_p = req_p->sslCon_p;
    if (sslCon_p == 0) {
        sslCon_p = NHTTPi_alloc(0x830, 4);
        req_p->sslCon_p = sslCon_p;
        NHTTPi_memclr(sslCon_p, 0x830);
    }
    sslCon_p->rootCA_p = req_p->rootCA_p;
    sslCon_p->rootCALen = req_p->rootCALen;
    sslCon_p->hostname_p = req_p->hostname_p;
    if (req_p->isIgnoreAuth) {
        sslCon_p->authCallback = (void *)NHTTPi_CpsAuthCallbackForDebug;
    } else {
        sslCon_p->authCallback = (void *)NHTTPi_CpsAuthCallback;
    }
    if (SOCL_EnableSsl(socket, sslCon_p) < 0) {
        return -1001;
    }
    NHTTPi_SetSSLseed();
    return 0;
}





/*
 * sdk:      NHTTPi_SocRecv_sub (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 */
int NHTTPi_SocRecv_sub(NHTTPConnection *connection_p, int socket, char *buf_p, int len, int flags)
{
    char *tmpBuf_p;
    int ret;
    int rec;
    unsigned long size;

    tmpBuf_p = (char *)connection_p->tmpBuf;
    ret = 0;
    if (len > 0) {
        if (connection_p->tmpBufRest == 0) {
            rec = SOC_Recv(socket, (int *)tmpBuf_p, 0x8000, flags);
            if (rec <= 0) {
                return rec;
            }
            connection_p->tmpBufRest = rec;
            connection_p->tmpBufOffset = 0;
        }
        size = connection_p->tmpBufRest;
        if (size != 0) {
            if ((unsigned long)len <= size) {
                size = len;
            }
            NHTTPi_memcpy(buf_p, tmpBuf_p + connection_p->tmpBufOffset, size);
            connection_p->tmpBufRest -= size;
            if (connection_p->tmpBufRest != 0) {
                connection_p->tmpBufOffset += size;
            } else {
                NHTTPi_memclr(tmpBuf_p, 0x8000);
                connection_p->tmpBufOffset = 0;
            }
            ret = size;
        }
    }
    return ret;
}




int NHTTPi_SocRecv(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags)
{
    NHTTPConnection *connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    int ret;

    if (connection_p != 0) {
        ret = NHTTPi_SocRecv_sub(connection_p, socket, buf_p, len, flags);
    } else {
        return -1001;
    }
    if (ret >= 0)
        return ret;
    if (req_p->doCancel != 0)
        return -1002;
    if (ret == -56)
        return 0;
    return -1001;
}


int NHTTPi_SocRecvRaw(int socket, char *buf_p, int len, int flags)
{
    return SOC_Send(socket, buf_p, len, flags);
}



int NHTTPi_SocSend(NHTTPReq *req_p, int socket, char *buf_p, int len, int flags)
{
    int error;

    error = NHTTPi_SocRecvRaw(socket, buf_p, len, flags);
    if (error < 0) {
        if (req_p->doCancel != 0) {
            return -1002;
        }
        if (error == -56) {
            return 0;
        }
        return -1001;
    }
    return error;
}



void NHTTPi_SocCancel(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket)
{
    NHTTPi_lockReqList(mutexInfo_p);
    if (socket >= 0)
        SOC_Shutdown(socket, 2);
    NHTTPi_unlockReqList(mutexInfo_p);
}



unsigned long NHTTPi_resolveHostname(NHTTPReq *req_p, char *hostname_p)
{
    SOCHostEnt *hostEnt;
    unsigned long addr = 0;
    SOCInAddr inAddr;

    if (SOC_InetAtoN(hostname_p, &inAddr)) {
        addr = inAddr.addr;
    } else {
        hostEnt = SOC_GetHostByName(hostname_p);
        if (hostEnt && hostEnt->h_length > 0) {
            NHTTPi_memcpy(&addr, *hostEnt->h_addr_list, 4);
        }
    }
    return addr;
}
