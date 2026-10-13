/*
 * file:     dwc_http.c
 * unit:     yes
 * function: func_0217956C, func_0217967C, func_02179718, func_021797D4, func_02179814, func_0217988C, func_021798E4, func_021798F8, func_021799E8, func_02179CF4, func_02179DA0, func_02179E60, func_02179F3C, func_0217A044, func_0217A0C8, func_0217A0D4, func_0217A120, func_0217A15C, func_0217A1FC, func_0217A344, func_0217A484, func_0217A728, func_0217A77C, func_0217A7C8, func_0217A808
 * address:  0x0217956C
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0217A0D4  0x0217A0D4  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_0209477C  0x0209477C  arm
 *   func_02084F80  0x02084F80  arm
 *   g_021A25C0     0x021A25C0  data
 *   g_021A25CC     0x021A25CC  data
 *   g_021A25D4     0x021A25D4  data
 *   g_021A25DC     0x021A25DC  data
 *   g_021A25E0     0x021A25E0  data
 *   OS_InitMutex           0x02086004  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread        0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   g_021ACE58             0x021ACE58  data
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   OS_GetLowEntropyData   0x02088168  arm
 *   CPS_SslAddRandomSeed   0x02162248  arm
 *   OS_Sleep               0x02085a38  arm
 *   MI_CpuFill8      0x02082bcc  arm
 *   CPS_SocRegister  0x0215aa5c  arm
 *   func_0215C910  0x0215C910  arm
 *   func_020964E0  0x020964E0  arm
 *   g_021A25F0     0x021A25F0  data
 *   g_021A2604     0x021A2604  data
 *   func_0217988C  0x0217988C  arm  ov009
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_02160108  0x02160108  arm  ov009
 *   func_02162E94  0x02162E94  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215AC60  0x0215AC60  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 *   func_0215AA70  0x0215AA70  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   func_0215B584  0x0215B584  arm  ov009
 *   func_02179814  0x02179814  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_0215B504  0x0215B504  arm  ov009
 *   func_0215AEB0  0x0215AEB0  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_0215B064  0x0215B064  arm  ov009
 *   _ll_udiv       0x0209C00C  arm
 *   func_0215AD00  0x0215AD00  arm  ov009
 *   func_0215AD3C  0x0215AD3C  arm  ov009
 *   func_0217A0C8  0x0217A0C8  arm  ov009
 *   g_021A2590     0x021A2590  data ov009
 *   g_021A82BC     0x021A82BC  data ov009
 *   func_0217A808  0x0217A808  arm  ov009
 *   func_0217A120  0x0217A120  arm  ov009
 *   g_021A2608     0x021A2608  data
 *   g_021A265C     0x021A265C  data
 *   func_02092364  0x02092364  arm
 *   g_021A267C     0x021A267C  data
 *   func_02059B40  0x02059B40  arm
 *   g_021A2688     0x021A2688  data ov009
 *   g_021A268C     0x021A268C  data ov009
 *   g_021A2694     0x021A2694  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02094860  0x02094860  arm
 *   g_021A2698     0x021A2698  data ov009
 *   g_021A26A0     0x021A26A0  data ov009
 *   g_021A26AC     0x021A26AC  data ov009
 *   g_021A26B0     0x021A26B0  data ov009
 *   func_02094798  0x02094798  arm
 *   func_020949F4  0x020949F4  arm
 *   g_021A26B4     0x021A26B4  data ov009
 *   g_021A26B8     0x021A26B8  data ov009
 *   g_021A26C4     0x021A26C4  data ov009
 *   g_021A26C8     0x021A26C8  data ov009
 *   g_021A26CC     0x021A26CC  data ov009
 *   g_021A26D0     0x021A26D0  data ov009
 *   strcmp  0x020948e0  arm
 *   strlen              0x0209477c  arm
 *   DWC_Base64Decode    0x02059cbc  arm
 *   strcpy              0x02094798  arm
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

typedef struct DWCHttp_0217956C {
    unsigned char stack[0x1000];
    unsigned char initflag;
    DWCHttpParam param;
    int error;
    char pad1024[0x9e4];
    unsigned char *lowrecvbuf;
    unsigned char *lowsendbuf;
    unsigned long lowentropydata[8];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
    char content_len_mutex[0x18];
    int content_len;
    int receivedbody_len;
    char pad1a74[0x1dc];
} DWCHttp_0217956C;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;

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

typedef struct DWCHttp_021798E4 {
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
} DWCHttp_021798E4;

typedef struct SOCLCaInfo SOCLCaInfo;

typedef struct DWCHttp_0217A044 {
    unsigned char stack[0x1000];
    unsigned char initflag;
    char param[0x1c];
    int error;
    char url[256];
    char *hostname;
    char *filepath;
    unsigned long hostip;
    int ssl_enabled;
    unsigned short port;
} DWCHttp_0217A044;

typedef struct DWCHttp_0217A344 {
    unsigned char stack[0x1000];
    unsigned char initflag;
    DWCHttpParam param;
} DWCHttp_0217A344;

typedef struct DWCHttpLabelValue {
    char *label;
    char *value;
} DWCHttpLabelValue;

typedef struct DWCHttpParseResult_0217956C {
    DWCHttpLabelValue *entry;
    int len;
    int index;
} DWCHttpParseResult_0217956C;

typedef struct DWCHttpLabelValue_0217A484 {
    char *label;
    char *value;
} DWCHttpLabelValue_0217A484;

typedef struct DWCHttpParseResult_0217A484 {
    DWCHttpLabelValue_0217A484 *entry;
    int len;
    int index;
} DWCHttpParseResult_0217A484;

typedef struct DWCHttp_0217A484 {
    char pad0[0x1a30];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
    char content_len_mutex[0x18];
    int content_len;
    int receivedbody_len;
    DWCHttpLabelValue_0217A484 labelvalue[32];
} DWCHttp_0217A484;

typedef struct {
    char *label;
    char *value;
} DWCHttpLabelValue_0217956C;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_0217A0D4(DWCHttp_0217956C *http, DWCHttpBuffer *buf, unsigned long size);
extern u8 *func_02094B20(const u8 *s1, const u8 *s2);
extern int func_0209477C(const u8 *s);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern void OS_InitMutex(void *mutex);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void OS_GetLowEntropyData(unsigned long *buffer);
extern void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
extern void OS_Sleep(unsigned long msec);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SocRegister(void *soc);
extern unsigned long func_0215C910(char *name);
extern int func_020964E0(u32 a0);
extern void func_0217988C(DWCHttp_021798E4 *http);
extern void func_0215AB10(void);
extern void func_02160108(int a, int b);
extern void func_02162E94(int mode);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long func_0215AC60(void);
extern void func_0215AB5C(void);
extern void func_0215AA70(void);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern void func_0215B584(void);
extern int func_02179814(DWCHttp_021798E4 *http);
extern unsigned long long func_020870D0(void);
extern long func_0215B504(void);
extern unsigned char *func_0215AEB0(unsigned long *len);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_02086028(OSMutex *mutex);
extern void func_02086078(OSMutex *mutex);
extern void func_0215B064(unsigned long len);
extern void func_0215AD00(void);
extern void func_0215AD3C(void);
extern int func_0217A0C8(int result);
extern void func_0217A808(char *http, void *array_entry, int array_len);
extern void func_0217A120(char *http, void *buf);
extern void *func_02092364(void *dst, const void *src, unsigned long n);
extern int func_02059B40(const char *src, unsigned long srclen, char *dst, unsigned long dstlen);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern u8 *func_02094860(u8 *dest, const u8 *src, unsigned int n);
extern char *func_02094798(char *dst, const char *src);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int strcmp(const char *s1, const char *s2);
extern unsigned long strlen(const char *s);
extern int DWC_Base64Decode(char *src, unsigned long srclen, char *dst, unsigned long dstlen);
extern char *strcpy(char *dst, const char *src);
int func_0217956C(DWCHttp_0217956C *http, DWCHttpParam *param);
int func_0217967C(char *http);
void func_02179718(char *http, unsigned long prio);
void DWC_Http_Abort(char *http);
u32 func_021798E4(const char *p);
int func_021798F8(char *http);
void func_021799E8(void *arg);
void func_02179CF4(char *http);
int func_02179DA0(char *http);
int func_02179E60(char *http, char *label, char *data);
int func_02179F3C(DWCHttp_0217956C *http, char *label, char *data, unsigned long data_len);
int func_0217A044(char *http, char *data);
int DWCi_Http_CPSCallback(int result);
int func_0217A15C(char *http, Buf *buf, int size);
int func_0217A1FC(DWCHttp_0217A044 *http, char *url);
int func_0217A344(DWCHttp_0217A344 *http, DWCHttpParseResult_0217956C *result, char *label, char *value);
int func_0217A484(DWCHttp_0217A484 *http, int noparsebody);
char *DWC_Http_GetResult(char *http, char *label);
int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned long buffer_len);
int DWC_Http_GetRawResult(char *http, char *label, char *buffer, int buffer_len);
extern char g_021A25C0[];
extern char g_021A25CC[];
extern char g_021A25D4[];
extern char g_021A25DC[];
extern char g_021A25E0[];
extern int g_021ACE58;
extern char g_021A25F0[];
extern char g_021A2604[];
extern SOCLCaInfo *g_021A2590[12];
extern unsigned long g_021A82BC;
extern char g_021A2608[];
extern char g_021A265C[];
extern char g_021A267C[];
extern const char g_021A2688[];
extern const char g_021A268C[];
extern char g_021A2694[];
extern const char g_021A2698[];
extern const char g_021A26A0[];
extern const char g_021A26AC[];
extern const char g_021A26B0[];
extern const char g_021A26B4[];
extern char g_021A26B8[];
extern const char g_021A26C4[];
extern const char g_021A26C8[];
extern const char g_021A26CC[];
extern const char g_021A26D0[];







/*
 * sdk:      DWC_Http_Create (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int func_0217956C(DWCHttp_0217956C *http, DWCHttpParam *param)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    MI_CpuFill8(http, 0, sizeof(DWCHttp_0217956C));
    http->content_len = -1;
    http->receivedbody_len = -1;
    http->param = *param;

    http->lowrecvbuf = alloc(0, 0xb68);
    if (http->lowrecvbuf == 0) {
        http->error = 1;
        return 1;
    }
    http->lowsendbuf = alloc(0, 0x5ea);
    if (http->lowsendbuf == 0) {
        http->error = 1;
        return 1;
    }
    if (!func_0217A0D4((DWCHttp_0217956C *)http, &http->rep, http->param.len_recvbuf)) {
        http->error = 1;
        return 1;
    }
    if (!func_0217A1FC((DWCHttp_0217A044 *)((DWCHttp_0217956C *)http), param->url)) {
        http->error = 1;
        return 1;
    }
    http->error = func_02179DA0((char *)http);
    if (http->error == 0)
        http->initflag = 0xff;
    return http->error;
}







/*
 * sdk:      DWC_Http_FinishHeader (dwc_http.o)
 */
int func_0217967C(char *http)
{
    char str_contentlen[8];
    int contentlen;

    if (func_02179E60(http, g_021A25C0, g_021A25CC)) {
        return 1;
    }
    contentlen = func_0209477C(func_02094B20((const u8 *)(*(char **)(http + 0x1a34)), (const u8 *)g_021A25D4) + 4);
    if (contentlen != 0) {
        func_02084F80(str_contentlen, 7, g_021A25DC, contentlen);
        if (func_02179E60(http, g_021A25E0, str_contentlen)) {
            return 1;
        }
    }
    return 0;
}







/*
 * sdk:      DWC_Http_StartThread (dwc_http.o)
 */
void func_02179718(char *http, unsigned long prio)
{
    *(int *)(http + 0x1c4c) = 0;
    OS_InitMutex(http + 0x1c34);
    OS_InitMutex(http + 0x1a54);
    if (*(int *)(http + 0x1018) == 1) {
        g_021ACE58 = 1;
    } else {
        g_021ACE58 = 0;
    }
    if (*(int *)(http + 0x1be0) != 0 && !OS_IsThreadTerminated(http + 0x1b74)) {
        return;
    }
    OS_CreateThread(http + 0x1b74, func_021799E8, http, http + 0x1000, 0x1000, prio);
    OS_WakeupThreadDirect(http + 0x1b74);
}







void DWC_Http_Abort(char *http)
{
    if (*(unsigned char *)(http + 0x1000) != 0xff) {
        return;
    }
    OS_LockMutex(http + 0x1c34);
    *(int *)(http + 0x1c4c) = 1;
    OS_UnlockMutex(http + 0x1c34);
}







static int DWCi_Http_Yield(char *http)
{
    if (*(int *)(http + 0x1130) == 1) {
        OS_GetLowEntropyData((unsigned long *)(http + 0x1a10));
        CPS_SslAddRandomSeed(http + 0x1a10, 0x20);
    }
    OS_LockMutex(http + 0x1c34);
    if (*(int *)(http + 0x1c4c) == 1) {
        OS_UnlockMutex(http + 0x1c34);
        return 0;
    }
    OS_UnlockMutex(http + 0x1c34);
    OS_Sleep(10);
    return 1;
}







static void DWCi_Http_InitCpsSocket(char *http)
{
    MI_CpuFill8(http + 0x1138, 0, 0xa0);
    *(unsigned long *)(http + 0x1180) = 0xb68;
    *(unsigned long *)(http + 0x1184) = *(unsigned long *)(http + 0x1a08);
    *(unsigned long *)(http + 0x118c) = 0x5ea;
    *(unsigned long *)(http + 0x1190) = *(unsigned long *)(http + 0x1a0c);
    CPS_SocRegister(http + 0x1138);
}






/*
 * Tail call on the word at +0x1124 of the object.
 */
u32 func_021798E4(const char *p)
{
    return func_0215C910((char *)(*(const int *)(p + 0x1124)));
}







/*
 * sdk:      DWCi_Http_CheckHeaderReceived (dwc_http.o)
 */
int func_021798F8(char *http)
{
    char content_temp;
    char *content_end;
    char *content_length;
    char *endof_header;
    Buf *rep;
    char *hdr;

    hdr = *(char **)(http + 0x1a44);
    rep = (Buf *)(http + 0x1a44);
    if (func_02094B20((const unsigned char *)hdr, (const unsigned char *)g_021A25D4) == 0) {
        return 0;
    }
    endof_header = (char *)(func_02094B20((const unsigned char *)hdr, (const unsigned char *)g_021A25D4) + 4);
    OS_LockMutex(http + 0x1a54);
    *(int *)(http + 0x1a70) = rep->cur - endof_header;
    OS_UnlockMutex(http + 0x1a54);
    content_length = (char *)func_02094B20((const unsigned char *)rep->base, (const unsigned char *)g_021A25F0);
    if (content_length == 0) {
        return 1;
    }
    content_length += func_0209477C((const u8 *)g_021A25F0);
    content_end = (char *)func_02094B20((const unsigned char *)content_length, (const unsigned char *)g_021A2604);
    content_temp = *content_end;
    *content_end = 0;
    OS_LockMutex(http + 0x1a54);
    *(int *)(http + 0x1a6c) = func_020964E0((u32)content_length);
    OS_UnlockMutex(http + 0x1a54);
    *content_end = content_temp;
    return 1;
}







/*
 * sdk:      DWCi_Http_Thread (libdwcauth.TWL.HYB.a dwc_http.o)
 */
void func_021799E8(void *arg)
{
    DWCHttp_021798E4 *http = (DWCHttp_021798E4 *)arg;
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

    func_0217988C((DWCHttp_021798E4 *)http);
    ip = func_021798E4((const char *)http);
    if (ip == 0) {
        http->error = 2;
        return;
    }
    http->hostip = ip;
    func_0215AB10();

    if (http->ssl_enabled == 1) {
        MI_CpuFill8(con, 0, sizeof(CPSSslConnection));
        con->auth_callback = func_0217A0C8;
        con->server_name = http->hostname;
        soc->con = con;
        func_02160108((int)g_021A2590, 12);
        func_02162E94(1);
    }

    func_0215AAB0(0, http->port, ip);
    tcpconnect = func_0215AC60();
    if (tcpconnect != 0) {
        http->error = 3;
        func_0215AB5C();
        func_0215AA70();
        return;
    }

    s = (unsigned char *)http->req.buffer;
    len = func_0215B470(s, func_0209477C((const u8 *)s));
    if (len <= 0) {
        http->error = 5;
        goto fail;
    }
    func_0215B584();
    if (!func_02179814((DWCHttp_021798E4 *)http)) {
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
        len = func_0215B504();
        if (len < 0)
            break;
        if (len > 0) {
            lastactivetime = func_020870D0();
            s = func_0215AEB0((unsigned long *)&len);
            if (s == 0)
                break;
            copy_length = (len < rep->buffer_tail - 1 - rep->write_index)
                              ? len : rep->buffer_tail - 1 - rep->write_index;
            func_02082D44(s, rep->write_index, copy_length);
            rep->write_index += copy_length;
            *rep->write_index = 0;
            if (header_received == 1) {
                func_02086028(&http->content_len_mutex);
                http->receivedbody_len += copy_length;
                func_02086078(&http->content_len_mutex);
            } else {
                header_received = func_021798F8((char *)http);
            }
            if (len > copy_length) {
                func_0215B064(len);
                break;
            }
            func_0215B064(copy_length);
        }
        if (http->content_len >= 0 && http->receivedbody_len >= http->content_len)
            break;
        nowtime = func_020870D0();
        if (((nowtime - lastactivetime) << 6) / 33514 > timeout) {
            http->error = 6;
            goto fail;
        }
        if (!func_02179814((DWCHttp_021798E4 *)http)) {
            http->error = 7;
            goto fail;
        }
    }

    func_0215AD00();
    func_0215AD3C();
    func_0215AB5C();
    func_0215AA70();
    http->error = 8;
    return;

fail:
    func_0215AD00();
    func_0215AD3C();
    func_0215AB5C();
    func_0215AA70();
}






/*
 * sdk:      DWC_Http_Destroy (dwc_http.o)
 */
void func_02179CF4(char *http)
{
    void (*free)(unsigned long, void *, long) =
        *(void (**)(unsigned long, void *, long))(http + 0x1014);

    if (http == 0) {
        return;
    }
    func_0217A808(http, http + 0x1a74, 0x20);
    func_0217A120(http, http + 0x1a44);
    func_0217A120(http, http + 0x1a34);
    if (*(void **)(http + 0x1a08) != 0) {
        free(0, *(void **)(http + 0x1a08), 0);
        *(void **)(http + 0x1a08) = 0;
    }
    if (*(void **)(http + 0x1a0c) != 0) {
        free(0, *(void **)(http + 0x1a0c), 0);
        *(void **)(http + 0x1a0c) = 0;
    }
    MI_CpuFill8(http, 0, 0x1c50);
}






/*
 * sdk:      DWCi_Http_WriteBasicHeader (dwc_http.o)
 */
int func_02179DA0(char *http)
{
    char *format;
    Buf *req;
    int result_len;

    req = (Buf *)(http + 0x1a34);
    if (*(int *)(http + 0x1008) == 0) {
        format = g_021A2608;
    } else {
        format = g_021A265C;
    }
    result_len = func_0209477C((const u8 *)(*(char **)(http + 0x1124))) +
                 (func_0209477C((const u8 *)format) - 4 + func_0209477C((const u8 *)(*(char **)(http + 0x1128))));
    if (func_0217A0D4((DWCHttp_0217956C *)http, (DWCHttpBuffer *)((Buf *)(http + 0x1a34)), result_len + 0x400) != 1) {
        return 1;
    }
    result_len = func_02084F80(req->cur, req->cap, format, *(char **)(http + 0x1128), *(char **)(http + 0x1124));
    req->cur += result_len;
    return 0;
}






/*
 * sdk:      DWC_Http_Add_HeaderItem (dwc_http.o)
 */
int func_02179E60(char *http, char *label, char *data)
{
    Buf *temp_buffer;
    int buf_remain;
    int result_len;
    char temp;
    char *temp_index;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = func_0209477C((const u8 *)data) +
                 (func_0209477C((const u8 *)g_021A267C) - 4 + func_0209477C((const u8 *)label));
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len + 1 > buf_remain) {
        if (func_0217A15C(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
    }
    temp_index = (char *)func_02094B20((const u8 *)temp_buffer->base, (const u8 *)g_021A25D4) + 2;
    temp = *temp_index;
    func_02092364(temp_index + result_len, temp_index, func_0209477C((const u8 *)temp_index) + 1);
    temp_index[func_02084F80(temp_index, result_len + 1, g_021A267C, label, data)] = temp;
    temp_buffer->cur += result_len;
    return 0;
}




/*
 * sdk:      DWC_Http_Add_PostBase64Item (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int func_02179F3C(DWCHttp_0217956C *http, char *label, char *data, unsigned long data_len)
{
    int result_len;
    int result_base64;
    int buf_remain;
    DWCHttpBuffer *temp_buffer;
    const char *format;

    temp_buffer = &http->req;
    if (http->num_postitem == 0)
        format = g_021A2688;
    else
        format = g_021A268C;

    http->num_postitem++;

    result_base64 = func_02059B40(data, data_len, 0, 0);
    result_len = result_base64 + (func_0209477C((const u8 *)format) - 2 + func_0209477C((const u8 *)label));
    buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    if (result_len > buf_remain) {
        if (!func_0217A15C((char *)http, (Buf *)temp_buffer, result_len - buf_remain + 1))
            return 1;
        buf_remain = temp_buffer->buffer_tail - temp_buffer->write_index;
    }

    result_len = func_02084F80(temp_buffer->write_index, buf_remain, format, label);
    temp_buffer->write_index += result_len;

    result_len = func_02059B40(data, data_len, temp_buffer->write_index,
                               temp_buffer->buffer_tail - temp_buffer->write_index - 1);
    if (result_len < 0)
        return 1;
    temp_buffer->write_index += result_base64;
    *temp_buffer->write_index = 0;
    return 0;
}







/*
 * sdk:      DWC_Http_Add_Body (dwc_http.o)
 */
int func_0217A044(char *http, char *data)
{
    int result_len;
    int buf_remain;
    int temp;
    Buf *temp_buffer;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = func_0209477C((const u8 *)data);
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len > buf_remain) {
        if (func_0217A15C(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
        buf_remain = temp_buffer->end - temp_buffer->cur;
    }
    temp = func_02084F80(temp_buffer->cur, buf_remain, g_021A2694, data);
    if (temp != result_len) {
        return 1;
    }
    temp_buffer->cur += temp;
    return 0;
}






int DWCi_Http_CPSCallback(int result)
{
	if (result & 0x8000)
		result &= ~0x8000;
	return result;
}






static int DWCi_Http_AllocBuffer(char *http, char *buf, unsigned long size)
{
    void *(*alloc)(unsigned long, long) = *(void *(**)(unsigned long, long))(http + 0x1010);
    void *p;

    if (size == 0)
        return 0;

    p = alloc(0, size);
    *(void **)(buf + 0) = p;
    if (p == 0)
        return 0;

    *(void **)(buf + 4) = p;
    *(void **)(buf + 8) = (char *)p + size;
    *(unsigned long *)(buf + 0xc) = size;
    return 1;
}







static void DWCi_Http_FreeBuffer(char *http, char *buf)
{
    void (*free)(unsigned long, void *, long) = *(void (**)(unsigned long, void *, long))(http + 0x1014);

    if (*(void **)buf != 0) {
        free(0, *(void **)buf, 0);
    }
    MI_CpuFill8(buf, 0, 0x10);
}







/*
 * sdk:      DWCi_Http_ReallocBuffer (dwc_http.o)
 */
int func_0217A15C(char *http, Buf *buf, int size)
{
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    char *newptr;

    alloc = *(void *(**)(unsigned long, long))(http + 0x1010);
    free = *(void (**)(unsigned long, void *, long))(http + 0x1014);
    if (size <= 0) {
        return 0;
    }
    newptr = alloc(0, buf->cap + size);
    if (newptr == 0) {
        return 0;
    }
    MI_CpuCopy8(buf->base, newptr, buf->cap);
    free(0, buf->base, 0);
    if (newptr == 0) {
        return 0;
    }
    buf->cur = buf->cur + (newptr - buf->base);
    buf->cap = buf->cap + size;
    buf->base = newptr;
    buf->end = newptr + buf->cap;
    return 1;
}





int func_0217A1FC(DWCHttp_0217A044 *http, char *url)
{
    char *temp;
    char *portnum = 0;

    if ((unsigned long)func_0209477C((const u8 *)url) >= 256)
        return 0;
    func_02094860((u8 *)http->url, (const u8 *)url, 256);
    if ((unsigned long)func_0209477C((const u8 *)url) != (unsigned long)func_0209477C((const u8 *)http->url))
        return 0;

    if ((char *)func_02094B20((const u8 *)http->url, (const u8 *)g_021A2698) != 0) {
        http->hostname = &http->url[7];
        http->ssl_enabled = 0;
        http->port = 80;
    } else {
        temp = (char *)func_02094B20((const u8 *)http->url, (const u8 *)g_021A26A0);
        if (temp == 0)
            return 0;
        http->hostname = temp + 8;
        http->ssl_enabled = 1;
        http->port = 443;
    }

    temp = (char *)func_02094B20((const u8 *)http->hostname, (const u8 *)g_021A26AC);
    if (temp != 0) {
        *temp = 0;
        portnum = temp + 1;
    }
    temp = (char *)func_02094B20((const u8 *)http->hostname, (const u8 *)g_021A26B0);
    if (temp != 0) {
        *temp = 0;
        http->filepath = temp + 1;
    } else {
        http->filepath = 0;
    }
    if (portnum != 0)
        http->port = func_020964E0((u32)portnum);
    return 1;
}




/*
 * sdk:      DWCi_Http_AddResult (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int func_0217A344(DWCHttp_0217A344 *http, DWCHttpParseResult_0217956C *result, char *label, char *value)
{
    void *(*alloc)(unsigned long, long) = http->param.alloc;
    void (*free)(unsigned long, void *, long) = http->param.free;

    if (result->index > result->len)
        return 0;

    result->entry[result->index].label = alloc(0, func_0209477C((const u8 *)label) + 1);
    if (result->entry[result->index].label != 0) {
        result->entry[result->index].value = alloc(0, func_0209477C((const u8 *)value) + 1);
        if (result->entry[result->index].value != 0) {
            func_02094798(result->entry[result->index].label, label);
            func_02094798(result->entry[result->index].value, value);
            result->index++;
            return 1;
        }
    }

    if (result->entry[result->index].label != 0) {
        free(0, result->entry[result->index].label, 0);
        result->entry[result->index].label = 0;
    }
    if (result->entry[result->index].value != 0) {
        free(0, result->entry[result->index].value, 0);
        result->entry[result->index].value = 0;
    }
    return 0;
}



/*
 * sdk:      DWC_Http_ParseResult (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int func_0217A484(DWCHttp_0217A484 *http, int noparsebody)
{
    char *buffer;
    char *p_char1;
    char *p_char2;
    char p_char1_temp;
    char p_char2_temp;
    char *httpbody_top;
    char *httpbody_end;
    char *index;
    char *value;
    char temp;
    DWCHttpParseResult_0217A484 parse_result;

    parse_result.entry = http->labelvalue;
    parse_result.len = 32;
    parse_result.index = 0;
    MI_CpuFill8(http->labelvalue, 0, sizeof(http->labelvalue));

    buffer = http->rep.buffer;
    httpbody_top = (char *)func_02094B20((const unsigned char *)buffer, (const unsigned char *)g_021A25D4);
    if (httpbody_top == 0)
        return 0;
    httpbody_end = httpbody_top + 4 + func_0209477C((const u8 *)(httpbody_top + 4));

    p_char1 = (char *)func_02094B20((const unsigned char *)buffer, (const unsigned char *)g_021A26B4);
    if (p_char1 == 0)
        return 0;
    temp = p_char1[4];
    p_char1[4] = 0;
    if (func_0217A344((DWCHttp_0217A344 *)http, (DWCHttpParseResult_0217956C *)&parse_result, g_021A26B8, p_char1 + 1) != 1) {
        p_char1[4] = temp;
        return 0;
    }
    p_char1[4] = temp;

    if (noparsebody == 1 || func_020949F4((const u8 *)(p_char1 + 1), (const u8 *)g_021A26C4, 3) != 0)
        return 1;

    index = (char *)func_02094B20((const unsigned char *)(p_char1 + 5), (const unsigned char *)g_021A2604);
    if (index == 0)
        return 0;
    index += 2;

    while (*index != '\r' && *(index + 1) != '\n') {
        p_char1 = (char *)func_02094B20((const unsigned char *)index, (const unsigned char *)g_021A26C8);
        if (p_char1 == 0)
            break;
        p_char1_temp = *p_char1;
        value = p_char1 + 2;
        *p_char1 = 0;
        p_char2 = (char *)func_02094B20((const unsigned char *)value, (const unsigned char *)g_021A2604);
        if (p_char2 == 0) {
            *p_char1 = p_char1_temp;
            break;
        }
        p_char2_temp = *p_char2;
        *p_char2 = 0;
        if (func_0217A344((DWCHttp_0217A344 *)http, (DWCHttpParseResult_0217956C *)&parse_result, index, value) != 1) {
            *p_char1 = p_char1_temp;
            *p_char2 = p_char2_temp;
            return 0;
        }
        index = value + func_0209477C((const u8 *)value) + 2;
        *p_char1 = p_char1_temp;
        *p_char2 = p_char2_temp;
    }

    index = httpbody_top + 4;
    while (index < httpbody_end) {
        buffer = (char *)func_02094B20((const unsigned char *)index, (const unsigned char *)g_021A26CC);
        if (buffer == 0)
            break;
        p_char1_temp = *buffer;
        p_char1 = buffer + 1;
        *buffer = 0;
        p_char2 = (char *)func_02094B20((const unsigned char *)p_char1, (const unsigned char *)g_021A26D0);
        if (p_char2 == 0)
            p_char2 = (char *)func_02094B20((const unsigned char *)p_char1, (const unsigned char *)g_021A2604);
        if (p_char2 != 0) {
            p_char2_temp = *p_char2;
            *p_char2 = 0;
        }
        if (func_0217A344((DWCHttp_0217A344 *)http, (DWCHttpParseResult_0217956C *)&parse_result, index, p_char1) != 1) {
            *buffer = p_char1_temp;
            if (p_char2 != 0)
                *p_char2 = p_char2_temp;
            return 0;
        }
        index = p_char1 + func_0209477C((const u8 *)p_char1) + 1;
        *buffer = p_char1_temp;
        if (p_char2 != 0)
            *p_char2 = p_char2_temp;
    }
    return 1;
}




char *DWC_Http_GetResult(char *http, char *label)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (*(char **)(http + 0x1a74 + i * 8) == 0)
            break;
        if (strcmp(label, *(char **)(http + 0x1a74 + i * 8)) == 0)
            return *(char **)(http + 0x1a78 + i * 8);
    }
    return 0;
}




int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned long buffer_len)
{
    char *value = DWC_Http_GetResult(http, label);
    int result_len;

    if (value == 0)
        return 0;

    result_len = DWC_Base64Decode(value, strlen(value), buffer, buffer_len);
    if (result_len == -1)
        return result_len;
    if (result_len < buffer_len)
        buffer[result_len] = 0;
    return result_len;
}




int DWC_Http_GetRawResult(char *http, char *label, char *buffer, int buffer_len)
{
    char *value = DWC_Http_GetResult(http, label);
    int value_len;

    if (value == 0)
        return 0;

    value_len = strlen(value);
    if (value_len >= buffer_len)
        return 0;
    strcpy(buffer, value);
    return 1;
}




static void DWCi_Http_DestroyResult(char *http, DWCHttpLabelValue_0217956C *array_entry, int array_len)
{
    void (*free)(unsigned long, void *, long) = *(void (**)(unsigned long, void *, long))(http + 0x1014);
    int i;

    for (i = 0; i < array_len; i++) {
        if (array_entry[i].label != 0) {
            free(0, array_entry[i].label, 0);
            array_entry[i].label = 0;
        }
        if (array_entry[i].value != 0) {
            free(0, array_entry[i].value, 0);
            array_entry[i].value = 0;
        }
    }
}
