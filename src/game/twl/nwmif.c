/*
 * file:     nwmif.c
 * unit:     yes
 * function: WCMi_NwmifStartupAsync, WCMi_NwmifCleanupAsync, WCMi_NwmifBeginSearchAsync, WCMi_NwmifConnectAsync, WCMi_NwmifDisconnectAsync, WCMi_NwmifTerminateAsync, WCMi_NwmifSetDCFData, WCMi_NwmifGetAllowedChannel, WcmNwmReset, WcmNwmcbCommon, WcmNwmcbScanEx, WcmNwmcbConnect, WcmNwmcbDisconnect, WcmNwmcbSetRecvFrmBuf, WcmNwmcbUnsetRecvFrmBuf, WcmEditScanExParam, WcmNwmcbSetDCFData, WcmNwmcbSetDCFDataAsync
 * address:  0x0273199C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libwcm.TWL.HYB.a nwmif.o (WCMi_NwmifStartupAsync at 0x0273199C,
 *           WcmNwmReset at 0x02731F14, WcmNwmcbSetDCFDataAsync at 0x02732CEC)
 *
 * symbols:
 *   func_020862B8  0x020862B8  arm  twl
 *   NWM_StartScanEx  0x02703088  arm  twl
 *   MI_CpuCopy8    0x02082D44  arm
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   NWM_Init  0x02702434  arm  twl
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   NWM_LoadDevice  0x02702B08  arm  twl
 *   NWM_Close  0x02702FE8  arm  twl
 *   NWM_SetWEPKey  0x027034C0  arm  twl
 *   NWM_SetWPAPSK  0x02703960  arm  twl
 *   NWM_UnsetReceivingFrameBuffer  0x02703854  arm  twl
 *   NWM_GetState  0x027028B0  arm  twl
 *   NWM_End  0x02702A98  arm  twl
 *   NWM_UnloadDevice  0x02702BFC  arm  twl
 *   NWM_Disconnect  0x02703424  arm  twl
 *   WCMi_GetCpsifWork   0x02166378  arm  ov009
 *   NWM_SendFrame   0x027036A0  arm  twl
 *   OS_SleepThread  0x020857B0  arm
 *   WcmNwmcbSetDCFDataAsync   0x02732CEC  arm  twl
 *   NWM_GetAllowedChannel  0x02702980  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 *   NWM_Open     0x02702F38  arm  twl
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_021665CC     0x021665CC  arm  ov009
 *   NWM_SetPowerSaveMode     0x027035F4  arm  twl
 *   NWM_SetReceivingFrameBuffer     0x0270379C  arm  twl
 *   func_02166804  0x02166804  arm  ov009
 *   func_02166358  0x02166358  arm  ov009
 *   NWM_Connect  0x027032E0  arm  twl
 *   WCM_UpdateOption  0x021656D0  arm  ov009
 *   WCMi_GetNextScanChannel  0x02165918  arm  ov009
 *   NWM_GetDispersionScanPeriod  0x02702998  arm  twl
 *   data_021A1988  0x021A1988  data ov009 a4
 *   data_021A1990  0x021A1990  data ov009 a4
 *   func_02165AF4    0x02165AF4  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 *   func_02166594  0x02166594  arm  ov009
 *   WCMi_EntryApList  0x02165D04  arm  ov009
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct NetWork {
    u8 pad00[0x600];
    u8 recvBuf[0xc40];
    u8 peer[0x20];
    u8 pad0a[0x1290 - 0x1260];
    u8 mode;
    u8 submode;
    u8 pad0b[0x12c0 - 0x1292];
    u32 cmdArg;
    u8 pad0c[0x12d4 - 0x12c4];
    u32 linkFlags;
    u16 sync;
    short phase;
    u8 pad2a;
    u8 stopFlag;
    u8 state;
    u8 pad3;
    u8 buf[0x130c - 0x12e0];
    u16 optFlags;
    u8 pad4[0x13a0 - 0x130e];
    u8 rxBuf[0x3000];
    u32 sendBuf;
    u16 sendLen;
    u16 sendMask;
    u16 sendId;
    u16 sendFlag;
    u8 sendMac[6];
    u16 nameLen;
    u8 sendName[0x20];
    u16 nameLen2;
    u8 pad5[0x43e0 - 0x43d6];
    u32 sendCount;
    u16 rxFlag;
    u16 txFlag;
} NetWork;

typedef struct SendPkt {
    u16 pad0;
    u16 kind;
    u32 len;
    u16 pad1;
    u16 count;
    u8 pad2[4];
    u32 ptr[32];
    u16 size[32];
} SendPkt;

typedef struct JoinReq {
    u16 mode;
    u8 peer[0x20];
} JoinReq;

typedef struct NetObj {
    u8 pad0[4];
    u8 queue[0x20];
    u16 status;
    u8 pad1[6];
    u32 arg;
} NetObj;

typedef struct Pkt {
    u16 pad0;
    u16 kind;
    u16 pad1;
    short level;
    u32 len;
    u8 *data;
} Pkt;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern NetWork *WCMi_GetSystemWork(void);
extern void func_020862B8(u32 buf, u32 len);
extern int NWM_StartScanEx(void *cb, void *buf);
extern u32 NWM_Init(u32 a0, u32 a1, u32 a2);
extern void WCMi_SetPhase(unsigned char phase);
extern u32 NWM_LoadDevice(void *arg);
extern u32 NWM_Close(void *arg);
extern u32 NWM_SetWEPKey(void *a, u32 b, u32 c, void *d, u32 e);
extern u32 NWM_SetWPAPSK(void *a, void *b);
extern u32 NWM_UnsetReceivingFrameBuffer(void *a0, u32 a1);
extern u32 NWM_GetState(void);
extern u32 NWM_End(void);
extern u32 NWM_UnloadDevice(void *arg);
extern u32 NWM_Disconnect(void *arg);
extern NetObj *WCMi_GetCpsifWork(void);
extern u32 NWM_SendFrame(void *cb, u32 a, u32 b, u32 c);
extern void OS_SleepThread(void *queue);
extern u32 NWM_GetAllowedChannel(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern void func_021659F8(u32 a, u32 b, u32 c, void *d, u32 e);
extern void WCMi_EntryApList(u32 a, u32 b);
extern u16 WCMi_GetNextScanChannel(u16 a);
extern void func_020862D4(u32 buf, u32 len);
extern u32 func_02080D24(u32 x);
extern u32 NWM_Open(void *arg);
extern void OS_GetMacAddress(void *mac);
extern void func_021665CC(void *mac);
extern u32 NWM_SetPowerSaveMode(void *arg, u32 b);
extern u32 NWM_SetReceivingFrameBuffer(void *arg, void *b, u32 c, u32 d);
extern void func_02166804(u8 v);
extern void func_02166358(u8 *a, u8 *b, u8 *c, u32 len);
extern int NWM_Connect(void *cb, u8 flag, void *buf);
extern unsigned long WCM_UpdateOption(unsigned long option);
extern u32 NWM_GetDispersionScanPeriod(u32 a);
extern void func_02165AF4(void);
extern void OS_WakeupThread(void *queue);
u32 WCMi_NwmifStartupAsync(void);
u32 WCMi_NwmifCleanupAsync(void);
int WCMi_NwmifBeginSearchAsync(u32 a, u32 b, u32 c);
u32 WCMi_NwmifConnectAsync(void);
u32 WCMi_NwmifDisconnectAsync(void);
u32 WCMi_NwmifTerminateAsync(void);
u32 WCMi_NwmifSetDCFData(u32 a, u32 b, u32 c, u32 d);
u32 WCMi_NwmifGetAllowedChannel(void);
void WcmNwmReset(void);
void WcmNwmcbCommon(u16 *arg);
void WcmNwmcbScanEx(SendPkt *p);
void WcmNwmcbConnect(u16 *arg);
void WcmNwmcbDisconnect(u16 *arg);
void WcmNwmcbSetRecvFrmBuf(Pkt *p);
void WcmNwmcbUnsetRecvFrmBuf(Pkt *p);
static void WcmEditScanExParam(u8 *mac, u8 *name, u32 opt);
void WcmNwmcbSetDCFData(u16 *arg);
void WcmNwmcbSetDCFDataAsync(void *arg);
extern u8 data_021A1988[];
extern u8 data_021A1990[];

static inline unsigned long clz32(unsigned long x)
{
    asm { clz x, x }
    return x;
}

typedef struct OSThreadQueue { void *head; void *tail; } OSThreadQueue;
typedef struct OSMutex { OSThreadQueue queue; void *thread; long count; void *prev; void *next; } OSMutex;
typedef struct WCMCpsifWork {
    unsigned char initialized;
    unsigned char reserved[3];
    OSThreadQueue sendQ;
    OSMutex sendMutex;
    unsigned short sendResult;
    unsigned short padding1;
    void (*recvCallback)(unsigned char *, unsigned char *, unsigned char *, long);
    void (*sendCallback)(long);
    unsigned char macAddress[6];
    unsigned short padding2;
} WCMCpsifWork;
typedef struct NWMCallback { unsigned short apiid; unsigned short retcode; } NWMCallback;

extern void func_02166594(OSMutex *mutex);

u32 WCMi_NwmifStartupAsync(void)
{
    NetWork *w = WCMi_GetSystemWork();

    switch (NWM_Init((u32)w->rxBuf, 0x3000, w->cmdArg & 0xff)) {
    case 3:
        WCMi_SetPhase(11);
        return 7;
    case 4:
        return 5;
    case 1:
    case 2:
    case 5:
    default:
        WCMi_SetPhase(11);
        return 7;
    case 0:
        w->txFlag = 0;
        switch (NWM_LoadDevice(WcmNwmcbCommon)) {
        case 2:
            WCMi_SetPhase(2);
            w->phase = 1;
            break;
        case 6:
            WCMi_SetPhase(12);
            return 1;
        case 3:
        default:
            WCMi_SetPhase(11);
            return 7;
        }
        break;
    }
    return 3;
}








u32 WCMi_NwmifCleanupAsync(void)
{
    NetWork *w = WCMi_GetSystemWork();

    switch (NWM_Close(WcmNwmcbCommon)) {
    case 2:
        WCMi_SetPhase(4);
        w->phase = 2;
        break;
    case 6:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}





int WCMi_NwmifBeginSearchAsync(u32 a, u32 b, u32 c)
{
    NetWork *w = WCMi_GetSystemWork();

    switch (w->state) {
    case 5:
        WcmEditScanExParam((void *)a, (void *)b, c);
        return 2;
    case 6:
        WcmEditScanExParam((void *)a, (void *)b, c);
        return 0;
    default:
        return 1;
    case 3:
        WcmEditScanExParam((void *)a, (void *)b, c);
        func_020862B8(w->sendBuf, w->sendLen);
        w->sendCount++;
        switch (NWM_StartScanEx(WcmNwmcbScanEx, &w->sendBuf)) {
        case 2:
            WCMi_SetPhase(5);
            w->phase = 3;
            return 3;
        case 6:
            return 4;
        case 3:
        default:
            WCMi_SetPhase(11);
            return 7;
        }
    }
}






u32 WCMi_NwmifConnectAsync(void)
{
    NetWork *w = WCMi_GetSystemWork();
    JoinReq req;
    u32 ret;
    u32 flag;

    switch (w->mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        flag = 0;
        if ((w->linkFlags & 0xc0000) == 0xc0000) {
            flag = 1;
        }
        ret = NWM_SetWEPKey(WcmNwmcbCommon, w->mode, w->submode, w->peer, flag);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        MI_CpuCopy8(w->peer, req.peer, 0x20);
        req.mode = w->mode;
        ret = NWM_SetWPAPSK(WcmNwmcbCommon, &req);
        break;
    }
    switch (ret) {
    case 2:
        WCMi_SetPhase(8);
        w->phase = 5;
        break;
    case 6:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}







u32 WCMi_NwmifDisconnectAsync(void)
{
    NetWork *w = WCMi_GetSystemWork();

    switch (NWM_UnsetReceivingFrameBuffer(WcmNwmcbUnsetRecvFrmBuf, 0)) {
    case 2:
        WCMi_SetPhase(10);
        w->phase = 6;
        break;
    case 6:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}







u32 WCMi_NwmifTerminateAsync(void)
{
    NetWork *w = WCMi_GetSystemWork();
    u32 ret;

    switch (NWM_GetState()) {
    case 1:
        ret = NWM_End();
        if (ret == 0) {
            WCMi_SetPhase(1);
            w->phase = 0;
            return 0;
        }
        break;
    case 2:
        ret = NWM_UnloadDevice(WcmNwmcbCommon);
        break;
    case 3:
        ret = NWM_Close(WcmNwmcbCommon);
        break;
    case 4:
        ret = NWM_Disconnect(WcmNwmcbDisconnect);
        break;
    default:
        w->stopFlag = 1;
        ret = 4;
        break;
    }
    switch (ret) {
    case 2:
        WCMi_SetPhase(13);
        w->phase = 9;
        break;
    case 6:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}







u32 WCMi_NwmifSetDCFData(u32 a, u32 b, u32 c, u32 d)
{
    NetObj *o = WCMi_GetCpsifWork();
    u32 ret;

    if (d == 0) {
        ret = NWM_SendFrame(WcmNwmcbSetDCFData, a, b, c);
    } else {
        o->arg = d;
        ret = NWM_SendFrame(WcmNwmcbSetDCFDataAsync, a, b, c);
    }
    switch (ret) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        return -5;
    case 2:
        break;
    }
    if (d == 0) {
        OS_SleepThread(o->queue);
        if (o->status != 0) {
            return -5;
        }
    }
    return c;
}







u32 WCMi_NwmifGetAllowedChannel(void)
{
    return (NWM_GetAllowedChannel() << 15) >> 16;
}







void WcmNwmReset(void)
{
    NetWork *w = WCMi_GetSystemWork();
    u16 tx;

    if (w->stopFlag != 0) {
        return;
    }
    /* WcmNwmReset (libwcm nwmif.o): its line table puts a constant 1 on a
       line of its own before the store of 0, so the source sets the flag
       and then clears it; the dead first store leaves the 1 in a register. */
    w->stopFlag = 1;
    w->stopFlag = 0;
    w->rxFlag = 0;
    switch (w->state) {
    case 5:
    case 6:
        WCMi_SetPhase(3);
        func_021659B4(1, 0, 0, 667);
        return;
    case 7:
        WCMi_SetPhase(3);
        func_021659B4(0, 0, 0, 673);
        return;
    case 8:
        tx = w->txFlag;
        w->txFlag = 0;
        WCMi_SetPhase(3);
        func_021659B4(1, w->buf, tx, 683);
        return;
    case 9:
    case 12:
        WCMi_SetPhase(3);
        func_021659B4(0, w->buf, 1, 691);
        return;
    case 10:
        WCMi_SetPhase(3);
        func_021659B4(0, w->buf, 0, 698);
        return;
    case 13:
        switch (NWM_Close(WcmNwmcbCommon)) {
        case 2:
            return;
        case 6:
            WCMi_SetPhase(12);
            func_021659B4(1, 0, 0, 712);
            return;
        case 3:
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, 0, 0, 721);
            return;
        }
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, 0, w->state, 727);
        return;
    }
}







void WcmNwmcbCommon(u16 *arg)
{
    u8 mac[6];
    u32 ret = 13;
    u32 flag;
    NetWork *w = WCMi_GetSystemWork();

    switch (arg[1]) {
    case 0:
        switch (arg[0]) {
        case 3:
            ret = NWM_Open(WcmNwmcbCommon);
            break;
        case 4:
            if (NWM_End() == 0) {
                WCMi_SetPhase(1);
                func_021659B4(0, 0, 0, 768);
                return;
            }
            WCMi_SetPhase(11);
            func_021659B4(7, 0, 0, 777);
            return;
        case 5:
            OS_GetMacAddress(mac);
            func_021665CC(mac);
            WCMi_SetPhase(3);
            func_021659B4(0, 0, 0, 790);
            return;
        case 6:
            ret = NWM_UnloadDevice(WcmNwmcbCommon);
            break;
        case 13:
        case 18:
            flag = 0;
            if ((w->linkFlags & 0x30000) != 0x30000) {
                flag = 1;
            }
            ret = NWM_SetPowerSaveMode(WcmNwmcbCommon, flag);
            break;
        case 14:
            ret = NWM_SetReceivingFrameBuffer(WcmNwmcbSetRecvFrmBuf, w->recvBuf, 0xc40, 0);
            break;
        default:
            break;
        }
        switch (ret) {
        case 2:
            return;
        case 6:
            WCMi_SetPhase(12);
            func_021659B4(1, w->phase == 5 ? w->buf : 0, 0, 842);
            return;
        case 3:
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, w->phase == 5 ? w->buf : 0, 0, 851);
            return;
        }
    case 1:
        WCMi_SetPhase(12);
        func_021659B4(1, w->phase == 5 ? w->buf : 0, 0, 882);
        return;
    case 10:
        WCMi_SetPhase(11);
        func_021659B4(7, w->phase == 5 ? w->buf : 0, 0, 888);
        return;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, w->phase == 5 ? w->buf : 0, 0, 901);
        return;
    }
}




void WcmNwmcbScanEx(SendPkt *p)
{
    int status = 13;
    NetWork *w = WCMi_GetSystemWork();
    int i;

    switch (p->kind) {
    case 0:
        if (w->state == 5) {
            WCMi_SetPhase(6);
            func_021659B4(0, 0, 0, 931);
        }
        switch (w->state) {
        case 6:
            w->phase = 7;
            if (p->count != 0) {
                func_020862B8(w->sendBuf, w->sendLen);
                for (i = 0; i < p->count; i++) {
                    WCMi_EntryApList(p->ptr[i], p->size[i]);
                    func_021659F8(7, 0, p->ptr[i], p, 953);
                }
            }
            if ((w->linkFlags & 0xc00000) == 0xc00000) {
                u32 n = func_02080D24(w->linkFlags & 0x3ffe);
                if (n != 0 && w->sendCount % n == 0) {
                    func_021659F8(8, 0, w->sendCount, 0, 967);
                }
            }
            w->sendMask = (1 << WCMi_GetNextScanChannel(32 - clz32(p->len))) >> 1;
            func_020862D4(w->sendBuf, w->sendLen);
            w->sendCount++;
            status = NWM_StartScanEx(WcmNwmcbScanEx, &w->sendBuf);
            break;
        case 7:
            status = 2;
            WCMi_SetPhase(3);
            func_021659B4(0, 0, 0, 983);
            break;
        case 13:
            WcmNwmReset();
            return;
        }
        switch (status) {
        case 2:
            return;
        case 6:
            WCMi_SetPhase(12);
            func_021659B4(1, 0, 0, 1011);
            return;
        case 3:
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, 0, 0, 1020);
            return;
        }
    case 1:
        WcmNwmReset();
        return;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, 0, 0, 1037);
        return;
    }
}






void WcmNwmcbConnect(u16 *arg)
{
    NetWork *w = WCMi_GetSystemWork();
    u32 cur = NWM_GetState();

    switch (arg[1]) {
    case 0:
        if (cur == 4) {
            if (w->state == 12) {
                WCMi_SetPhase(8);
                WcmNwmReset();
                return;
            }
            w->rxFlag = arg[7];
            WCMi_SetPhase(9);
            func_021659B4(0, w->buf, 0, 1078);
            return;
        }
        WCMi_SetPhase(11);
        func_021659B4(7, w->buf, 0, 1084);
        return;
    case 1:
        switch (arg[8]) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            switch (w->state) {
            case 9:
            case 10:
                w->phase = 6;
            case 8:
                w->rxFlag = 0;
                switch (arg[8]) {
                case 5:
                    w->txFlag = 13;
                    break;
                case 10:
                case 11:
                    w->txFlag = 15;
                    break;
                case 7:
                    w->txFlag = 17;
                    break;
                }
            case 12:
                WcmNwmReset();
                break;
            case 11:
                goto exit11;
            default:
                goto exit_default;
            }
            return;
        case 3:
            if (w->state == 8) {
                w->rxFlag = 0;
                WcmNwmReset();
            }
            return;
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, w->buf, arg[8], 1153);
            return;
        }
    case 5:
        WCMi_SetPhase(8);
        WcmNwmReset();
        return;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, w->buf, 0, 1173);
        return;
    }
exit11:
    return;
exit_default:
    return;
}






void WcmNwmcbDisconnect(u16 *arg)
{
    NetWork *w = WCMi_GetSystemWork();

    switch (arg[1]) {
    case 0:
        if (w->state == 12) {
            WCMi_SetPhase(10);
            WcmNwmReset();
            return;
        }
        if (w->state == 13) {
            WcmNwmReset();
            return;
        }
        w->rxFlag = 0;
        WCMi_SetPhase(3);
        func_021659B4(0, w->buf, 0, 1213);
        return;
    case 1:
    case 3:
        WCMi_SetPhase(10);
        WcmNwmReset();
        return;
    case 2:
    case 4:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, w->buf, 0, 1231);
        return;
    }
}





void WcmNwmcbSetRecvFrmBuf(Pkt *p)
{
    NetWork *w = WCMi_GetSystemWork();
    int lv;

    switch (p->kind) {
    case 0:
        if (w->state == 12) {
            WCMi_SetPhase(8);
            WcmNwmReset();
            return;
        }
        switch (NWM_Connect(WcmNwmcbConnect, (w->optFlags & 2) ? 1 : 0, w->buf)) {
        case 2:
            return;
        case 6:
            WCMi_SetPhase(12);
            func_021659B4(1, w->buf, 0, 1286);
            return;
        case 3:
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, w->buf, 0, 1295);
            return;
        }
    case 11:
        func_020862B8((u32)p->data, 0x620);
        lv = p->level;
        if (lv < 0) {
            lv = 0;
        }
        if (lv > 0x100) {
            lv = 0xff;
        }
        func_02166804(lv);
        func_02166358(p->data + 6, p->data, p->data + 14, p->len - 14);
        return;
    }
}




void WcmNwmcbUnsetRecvFrmBuf(Pkt *p)
{
    NetWork *w = WCMi_GetSystemWork();
    switch (p->kind) {
    case 0:
        if (w->state == 12) {
            WCMi_SetPhase(10);
            WcmNwmReset();
            return;
        }
        switch (NWM_Disconnect(WcmNwmcbDisconnect)) {
        case 2:
            WCMi_SetPhase(10);
            w->phase = 6;
            return;
        case 6:
            WCMi_SetPhase(12);
            func_021659B4(1, w->buf, 0, 1365);
            return;
        case 3:
            WCMi_SetPhase(10);
            WcmNwmReset();
            return;
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, w->buf, 0, 1378);
            return;
        }
    case 1:
    case 2:
        break;
    }
    WCMi_SetPhase(11);
    func_021659B4(7, w->buf, 0, 1390);
}



static void WcmEditScanExParam(u8 *mac, u8 *name, u32 opt)
{
    NetWork *w = WCMi_GetSystemWork();
    u32 id;
    int i;

    WCM_UpdateOption(opt);
    w->sendBuf = (u32)w->recvBuf;
    w->sendLen = 0xc40;
    w->sendMask = (1 << WCMi_GetNextScanChannel(0)) >> 1;
    w->sendFlag = ((w->linkFlags & 0x300000) == 0x300000) ? 1 : 0;
    id = w->sync;
    if (id == 0) {
        id = NWM_GetDispersionScanPeriod(w->sendFlag);
    }
    w->sendId = id;
    if (mac == 0) {
        MI_CpuCopy8(data_021A1988, w->sendMac, 6);
    } else {
        MI_CpuCopy8(mac, w->sendMac, 6);
    }
    if (name == 0 || name == data_021A1990) {
        MI_CpuCopy8(data_021A1990, w->sendName, 0x20);
        w->nameLen = 0;
        w->nameLen2 = 0;
    } else {
        MI_CpuCopy8(name, w->sendName, 0x20);
        for (i = 0; i < 0x20; i++) {
            if (name[i] == 0) {
                break;
            }
        }
        w->nameLen = i;
        w->nameLen2 = i;
    }
    w->sendCount = 0;
}



void WcmNwmcbSetDCFData(u16 *arg)
{
    NetObj *o = WCMi_GetCpsifWork();

    if (arg[0] != 11) {
        return;
    }
    o->status = arg[1];
    if (arg[1] == 0) {
        func_02165AF4();
    }
    OS_WakeupThread(&o->queue);
}

/*
 * WcmNwmcbSetDCFDataAsync (nwmif.o): NWM completion callback for an
 * asynchronous DCF send, the TWL twin of ov009 WcmWmcbSetDCFDataAsync
 * (0x02167E20): record the NWM error code, re-arm the keep-alive alarm on
 * success, map the result to the WCM cpsif code (0 or -5), release the send
 * mutex and call the user callback.  The result is a switch on sendResult
 * with a `case 1: default:` arm, as in the wmif.o twin; that arm is reached
 * by two edges, so it is not if-converted.
 */
void WcmNwmcbSetDCFDataAsync(void *arg)
{
    NWMCallback *cb = (NWMCallback *)arg;
    WCMCpsifWork *wcmiw = (WCMCpsifWork *)WCMi_GetCpsifWork();
    long wcmResult;
    void (*sendCallback)(long);

    switch (cb->apiid) {
    case 0xb:
        wcmiw->sendResult = cb->retcode;
        if (cb->retcode == 0) {
            func_02165AF4();
        }
        switch (wcmiw->sendResult) {
        case 0:
            wcmResult = 0;
            break;
        case 1:
        default:
            wcmResult = -5;
            break;
        }
        sendCallback = wcmiw->sendCallback;
        wcmiw->sendCallback = 0;
        func_02166594(&wcmiw->sendMutex);
        sendCallback(wcmResult);
        break;
    }
}
