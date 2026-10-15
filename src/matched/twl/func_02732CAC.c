/*
 * function: WcmNwmcbSetDCFData
 * address:  0x02732CAC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_WakeupThread  0x02085800  arm
 *   func_02165AF4  0x02165AF4  arm  ov009
 *   WCMi_GetCpsifWork  0x02166378  arm  ov009
 *   NWM_Init  0x02702434  arm
 *   NWM_GetState  0x027028B0  arm
 *   NWM_GetAllowedChannel  0x02702980  arm
 *   NWM_GetDispersionScanPeriod  0x02702998  arm
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
 *   WcmNwmcbSetDCFDataAsync  0x02732CEC  arm
 *   WcmEditScanExParam  0x02732B70  arm
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   WCMi_GetNextScanChannel  0x02165918  arm  ov009
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   WCMi_EntryApList  0x02165D04  arm  ov009
 *   SHA1_HMAC_Start  0x02731774  arm
 *   SHA1_HMAC_UpdateData  0x0273184C  arm
 *   SHA1_HMAC_Finish  0x02731868  arm
 *   SHA1_HMAC_Calc  0x02731920  arm
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
extern void WcmNwmcbSetDCFDataAsync(void);
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
extern unsigned long func_021656D0(unsigned long option);
extern u32 NWM_GetDispersionScanPeriod(u32 a);
extern void func_02165AF4(void);
extern void OS_WakeupThread(void *queue);
void SHA1_HMAC_Start(HmacCtx *ctx, const void *key, u32 key_len);
void SHA1_HMAC_UpdateData(void *a, const void *b, u32 c);
void SHA1_HMAC_Finish(HmacCtx *ctx, u8 *digest);
asm void SHA1_HMAC_Calc(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len);
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
void WcmEditScanExParam(u8 *mac, u8 *name, u32 opt);
void WcmNwmcbSetDCFData(u16 *arg);
extern u8 data_021A1988[];
extern u8 data_021A1990[];





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
