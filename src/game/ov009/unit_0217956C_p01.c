/*
 * file:     unit_0217956C_p01.c
 * unit:     yes
 * function: func_0217956C, func_0217967C, func_02179718, func_021797D4, func_02179814, func_0217988C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217A0D4  0x0217A0D4  arm  ov009
 *   func_0217A1FC  0x0217A1FC  arm  ov009
 *   func_02179DA0  0x02179DA0  arm  ov009
 *   func_02179E60  0x02179E60  arm  ov009
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
 *   func_021799E8          0x021799E8  arm  ov009
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   OS_GetLowEntropyData   0x02088168  arm
 *   CPS_SslAddRandomSeed   0x02162248  arm
 *   OS_Sleep               0x02085a38  arm
 *   MI_CpuFill8      0x02082bcc  arm
 *   CPS_SocRegister  0x0215aa5c  arm
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

typedef struct DWCHttp {
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
} DWCHttp;

typedef unsigned char  u8;

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_0217A0D4(DWCHttp *http, DWCHttpBuffer *buf, unsigned long size);
extern int func_0217A1FC(DWCHttp *http, char *url);
extern int func_02179DA0(char *http);
extern int func_02179E60(char *http, char *label, char *data);
extern u8 *func_02094B20(const u8 *s1, const u8 *s2);
extern int func_0209477C(const u8 *s);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern void OS_InitMutex(void *mutex);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void func_021799E8(void *arg);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void OS_GetLowEntropyData(unsigned long *buffer);
extern void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
extern void OS_Sleep(unsigned long msec);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SocRegister(void *soc);
int func_0217956C(DWCHttp *http, DWCHttpParam *param);
int func_0217967C(char *http);
void func_02179718(char *http, unsigned long prio);
void DWC_Http_Abort(char *http);
extern char g_021A25C0[];
extern char g_021A25CC[];
extern char g_021A25D4[];
extern char g_021A25DC[];
extern char g_021A25E0[];
extern int g_021ACE58;


/*
 * sdk:      DWC_Http_Create (libdwcauth.TWL.HYB.a dwc_http.o)
 */
int func_0217956C(DWCHttp *http, DWCHttpParam *param)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    func_02082BCC(http, 0, sizeof(DWCHttp));
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
    if (!func_0217A0D4(http, &http->rep, http->param.len_recvbuf)) {
        http->error = 1;
        return 1;
    }
    if (!func_0217A1FC(http, param->url)) {
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
