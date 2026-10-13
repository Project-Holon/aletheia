/*
 * function: WcmEditScanExParam
 * address:  0x02732B70
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   data_021A1988  0x021A1988  data  ov009
 *   data_021A1990  0x021A1990  data  ov009
 *   func_021656D0  0x021656D0  arm  ov009
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02165918  0x02165918  arm  ov009
 *   NWM_GetDispersionScanPeriod  0x02702998  arm  twl
 *   NWM_Init  0x02702434  arm
 *   NWM_GetState  0x027028B0  arm
 *   NWM_GetAllowedChannel  0x02702980  arm
 *   NWM_End  0x02702A98  arm
 *   NWM_LoadDevice  0x02702B08  arm
 *   NWM_UnloadDevice  0x02702BFC  arm
 *   NWM_Open  0x02702F38  arm
 *   NWM_Close  0x02702FE8  arm
 *   NWM_StartScanEx  0x02703088  arm
 *   NWM_Connect  0x027032E0  arm
 *   NWM_Disconnect  0x02703424  arm
 *   NWM_SetWEPKey  0x027034C0  arm
 *   NWM_SetPowerSaveMode  0x027035F4  arm
 *   NWM_SendFrame  0x027036A0  arm
 *   NWM_SetReceivingFrameBuffer  0x0270379C  arm
 *   NWM_UnsetReceivingFrameBuffer  0x02703854  arm
 *   NWM_SetWPAPSK  0x02703960  arm
 *   WCMi_NwmifStartupAsync  0x0273199C  arm
 *   WCMi_NwmifCleanupAsync  0x02731A84  arm
 *   WCMi_NwmifBeginSearchAsync  0x02731AF0  arm
 *   WCMi_NwmifConnectAsync  0x02731BF8  arm
 *   WCMi_NwmifDisconnectAsync  0x02731CFC  arm
 *   WCMi_NwmifTerminateAsync  0x02731D6C  arm
 *   WCMi_NwmifSetDCFData  0x02731E50  arm
 *   WCMi_NwmifGetAllowedChannel  0x02731F00  arm
 *   WcmNwmReset  0x02731F14  arm
 *   WcmNwmcbCommon  0x027320D0  arm
 *   WcmNwmcbScanEx  0x027323A8  arm
 *   WcmNwmcbConnect  0x02732648  arm
 *   WcmNwmcbDisconnect  0x02732874  arm
 *   WcmNwmcbSetRecvFrmBuf  0x02732944  arm
 *   WcmNwmcbUnsetRecvFrmBuf  0x02732A64  arm
 *   WcmNwmcbSetDCFData  0x02732CAC  arm
 *   WcmNwmcbSetDCFDataAsync  0x02732CEC  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef unsigned char u8;

typedef struct HmacCtx {
    u8 sha[0x64];
    u8 key[0x40];
    u32 keyLen;
} HmacCtx;

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
extern NetWork *func_021657C8(void);
extern void func_020862B8(u32 buf, u32 len);
extern int NWM_StartScanEx(void *cb, void *buf);
extern u32 NWM_Init(u32 a0, u32 a1, u32 a2);
extern void func_02165A4C(unsigned char phase);
extern u32 NWM_LoadDevice(void *arg);
extern u32 NWM_Close(void *arg);
extern u32 NWM_SetWEPKey(void *a, u32 b, u32 c, void *d, u32 e);
extern u32 NWM_SetWPAPSK(void *a, void *b);
extern u32 NWM_UnsetReceivingFrameBuffer(void *a0, u32 a1);
extern u32 NWM_GetState(void);
extern u32 NWM_End(void);
extern u32 NWM_UnloadDevice(void *arg);
extern u32 NWM_Disconnect(void *arg);
extern NetObj *func_02166378(void);
extern u32 NWM_SendFrame(void *cb, u32 a, u32 b, u32 c);
extern void OS_SleepThread(void *queue);
extern void WcmNwmcbSetDCFDataAsync(void);
extern u32 NWM_GetAllowedChannel(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern void func_021659F8(u32 a, u32 b, u32 c, void *d, u32 e);
extern void func_02165D04(u32 a, u32 b);
extern u16 func_02165918(u16 a);
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
extern unsigned long func_021656D0(unsigned long option);
extern u32 NWM_GetDispersionScanPeriod(u32 a);
extern void func_02165AF4(void);
extern void OS_WakeupThread(void *queue);
void func_02731774(HmacCtx *ctx, const void *key, u32 key_len);
void func_0273184C(void *a, const void *b, u32 c);
void func_02731868(HmacCtx *ctx, u8 *digest);
asm void func_02731920(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len);
u32 WCMi_NwmifStartupAsync(void);
u32 WCMi_NwmifCleanupAsync(void);
int WCMi_NwmifBeginSearchAsync(u32 a, u32 b, u32 c);
u32 WCMi_NwmifConnectAsync(void);
u32 WCMi_NwmifDisconnectAsync(void);
u32 WCMi_NwmifTerminateAsync(void);
u32 WCMi_NwmifSetDCFData(u32 a, u32 b, u32 c, u32 d);
u32 WCMi_NwmifGetAllowedChannel(void);
asm void WcmNwmReset(void);
void WcmNwmcbCommon(u16 *arg);
void WcmNwmcbScanEx(SendPkt *p);
asm void WcmNwmcbConnect(void *arg);
void WcmNwmcbDisconnect(u16 *arg);
void WcmNwmcbSetRecvFrmBuf(Pkt *p);
void WcmNwmcbUnsetRecvFrmBuf(Pkt *p);
static void WcmEditScanExParam(u8 *mac, u8 *name, u32 opt);
void WcmNwmcbSetDCFData(u16 *arg);
extern u8 data_021A1988[];
extern u8 data_021A1990[];

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern NetWork *func_021657C8(void);
extern u16 func_02165918(u16 a);
extern unsigned long func_021656D0(unsigned long option);
extern u32 NWM_GetDispersionScanPeriod(u32 a);
extern u8 data_021A1988[];
extern u8 data_021A1990[];

static void WcmEditScanExParam(u8 *mac, u8 *name, u32 opt)
{
    NetWork *w = func_021657C8();
    u32 id;
    int i;

    func_021656D0(opt);
    w->sendBuf = (u32)w->recvBuf;
    w->sendLen = 0xc40;
    w->sendMask = (1 << func_02165918(0)) >> 1;
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
