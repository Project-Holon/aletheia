/*
 * function: DWCi_Http_Thread
 * address:  0x021799E8
 * packet:   pkt_ov009_021799E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_Thread (libdwcauth.TWL.HYB.a dwc_http.o)
 *
 * symbols:
 *   func_0217988C  0x0217988C  arm  ov009
 *   DWCi_Http_Resolve  0x021798E4  arm  ov009
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   CPS_SetRootCa  0x02160108  arm  ov009
 *   CPS_SetSsl  0x02162E94  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   CPS_TcpConnect  0x0215AC60  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   strlen  0x0209477C  arm
 *   CPS_SocWrite  0x0215B470  arm  ov009
 *   CPS_SocFlush  0x0215B584  arm  ov009
 *   func_02179814  0x02179814  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   CPS_SocGetLength  0x0215B504  arm  ov009
 *   CPS_SocRead  0x0215AEB0  arm  ov009
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   DWCi_Http_CheckHeaderReceived  0x021798F8  arm  ov009
 *   CPS_SocConsume  0x0215B064  arm  ov009
 *   _ll_udiv       0x0209C00C  arm
 *   CPS_TcpShutdown  0x0215AD00  arm  ov009
 *   CPS_TcpClose  0x0215AD3C  arm  ov009
 *   func_0217A0C8  0x0217A0C8  arm  ov009
 *   g_021A2590     0x021A2590  data ov009
 *   g_021A82BC     0x021A82BC  data ov009
 */

typedef struct DWCHttpBuffer {
    char *buffer;
    char *write_index;
    char *buffer_tail;
    unsigned long length;
} DWCHttpBuffer;

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct CPSSslConnection {
    char pad0[0x800];
    char *server_name;
    char pad804[0xc];
    int (*auth_callback)(int result);
    char pad814[0x1c];
} CPSSslConnection;

typedef struct CPSSoc {
    char pad0[0xc];
    CPSSslConnection *con;
    char pad10[0x90];
} CPSSoc;

typedef struct OSMutex { char pad[0x18]; } OSMutex;

typedef struct DWCHttp {
    unsigned char stack[0x1000];
    unsigned char initflag;
    DWCHttpParam param;
    int error;
    char url[256];
    char *hostname;
    char *filepath;
    unsigned long hostip;
    int ssl_enabled;
    unsigned short port;
    CPSSoc soc;
    CPSSslConnection con;
    unsigned char *lowrecvbuf;
    unsigned char *lowsendbuf;
    unsigned long lowentropydata[8];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
    OSMutex content_len_mutex;
    int content_len;
    int receivedbody_len;
} DWCHttp;

typedef struct SOCLCaInfo SOCLCaInfo;

extern void func_0217988C(DWCHttp *http);
typedef unsigned int   u32;
extern u32 DWCi_Http_Resolve(const char *p);
extern void CPS_SocUse(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
typedef unsigned char  u8;
extern void CPS_SetRootCa(int a, int b);
extern void CPS_SetSsl(int mode);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long CPS_TcpConnect(void);
extern void CPS_SocRelease(void);
extern void CPS_SocUnRegister(void);
extern int strlen(const u8 *s);
extern unsigned long CPS_SocWrite(unsigned char *buf, unsigned long len);
extern void CPS_SocFlush(void);
extern int func_02179814(DWCHttp *http);
extern unsigned long long func_020870D0(void);
extern long CPS_SocGetLength(void);
extern unsigned char *CPS_SocRead(unsigned long *len);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void OS_LockMutex(OSMutex *mutex);
extern void func_02086078(OSMutex *mutex);
extern int DWCi_Http_CheckHeaderReceived(char *http);
extern void CPS_SocConsume(unsigned long len);
extern void CPS_TcpShutdown(void);
extern void CPS_TcpClose(void);
extern int func_0217A0C8(int result);

extern SOCLCaInfo *g_021A2590[12];
extern unsigned long g_021A82BC;

void DWCi_Http_Thread(void *arg)
{
    DWCHttp *http = (DWCHttp *)arg;
    CPSSoc *soc = &http->soc;
    CPSSslConnection *con = &http->con;
    DWCHttpBuffer *rep = &http->rep;
    unsigned int copy_length;
    unsigned long ip;
    unsigned char *s;
    long len;
    unsigned long long lastactivetime;
    unsigned long long nowtime;
    int timeout;
    unsigned long tcpconnect;
    int header_received = 0;

    timeout = http->param.timeout;
    if (timeout <= 0)
        timeout = 60000;

    func_0217988C(http);
    ip = DWCi_Http_Resolve((const char *)http);
    if (ip == 0) {
        http->error = 2;
        return;
    }
    http->hostip = ip;
    CPS_SocUse();

    if (http->ssl_enabled == 1) {
        MI_CpuFill8(con, 0, sizeof(CPSSslConnection));
        con->auth_callback = func_0217A0C8;
        con->server_name = http->hostname;
        soc->con = con;
        CPS_SetRootCa((int)g_021A2590, 12);
        CPS_SetSsl(1);
    }

    CPS_SocBind(0, http->port, ip);
    tcpconnect = CPS_TcpConnect();
    if (tcpconnect != 0) {
        http->error = 3;
        CPS_SocRelease();
        CPS_SocUnRegister();
        return;
    }

    s = (unsigned char *)http->req.buffer;
    len = CPS_SocWrite(s, strlen((const u8 *)s));
    if (len <= 0) {
        http->error = 5;
        goto fail;
    }
    CPS_SocFlush();
    if (!func_02179814(http)) {
        http->error = 7;
        goto fail;
    }

    rep->write_index = rep->buffer;
    rep->buffer_tail = rep->buffer + rep->length;
    lastactivetime = func_020870D0();

    for (;;) {
        if (g_021A82BC == 0) {
            http->error = 5;
            goto fail;
        }
        len = CPS_SocGetLength();
        if (len < 0)
            break;
        if (len > 0) {
            lastactivetime = func_020870D0();
            s = CPS_SocRead((unsigned long *)&len);
            if (s == 0)
                break;
            copy_length = (len < rep->buffer_tail - 1 - rep->write_index)
                              ? len : rep->buffer_tail - 1 - rep->write_index;
            MI_CpuCopy8(s, rep->write_index, copy_length);
            rep->write_index += copy_length;
            *rep->write_index = 0;
            if (header_received == 1) {
                OS_LockMutex(&http->content_len_mutex);
                http->receivedbody_len += copy_length;
                func_02086078(&http->content_len_mutex);
            } else {
                header_received = DWCi_Http_CheckHeaderReceived((char *)http);
            }
            if (len > copy_length) {
                CPS_SocConsume(len);
                break;
            }
            CPS_SocConsume(copy_length);
        }
        if (http->content_len >= 0 && http->receivedbody_len >= http->content_len)
            break;
        nowtime = func_020870D0();
        if (((nowtime - lastactivetime) << 6) / 33514 > timeout) {
            http->error = 6;
            goto fail;
        }
        if (!func_02179814(http)) {
            http->error = 7;
            goto fail;
        }
    }

    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
    http->error = 8;
    return;

fail:
    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
}
