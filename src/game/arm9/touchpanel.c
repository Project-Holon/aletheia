/*
 * file:     touchpanel.c
 * unit:     yes
 * function: TOUCHPANEL_GetWork, TOUCHPANEL_ReadPointX, TOUCHPANEL_ReadPointY, TOUCHPANEL_ReadCont, TOUCHPANEL_ReadTrg, TOUCHPANEL_Create, TOUCHPANEL_MainSys, TOUCHPANEL_Main, TOUCHPANEL_HitCircle, TOUCHPANEL_HitRect, TOUCHPANEL_SearchHitTable, TOUCHPANEL_HitContSys, TOUCHPANEL_HitCont, TOUCHPANEL_HitTrgSys, func_02035C08, TOUCHPANEL_GetContSys, func_02035C38, TOUCHPANEL_GetTrgSys, func_02035C60, TOUCHPANEL_GetPointContSys, TOUCHPANEL_GetPointCont, TOUCHPANEL_GetPointTrgSys, func_02035D20, TOUCHPANEL_HitPoint, TOUCHPANEL_RequestAutoSamplingStop, TOUCHPANEL_AutoSamplingRestartSys, TOUCHPANEL_AutoSamplingRestart, TOUCHPANEL_AutoSamplingStopSys, TOUCHPANEL_AutoSamplingStop, TOUCHPANEL_RequestAutoSamplingStart, TOUCHPANEL_ClearFrameRateWork, TOUCHPANEL_SetPoint, TOUCHPANEL_SetTrg, TOUCHPANEL_SetCont, KEY_Create, KEY_MainSys, KEY_Main, KEY_ApplyControlMode, KEY_SetRepeatSpeedSys, KEY_SetRepeatSpeed, KEY_SetControlModeTableSys, KEY_SetControlModeTable, KEY_GetTrgSys, func_020362DC, KEY_GetContSys, func_0203630C, KEY_GetRepeatSys, func_0203633C, KEY_GetRepeatSpeedSys, KEY_GetRepeatSpeed, KEY_ClearFrameRateWork, KEY_SetTrg, KEY_SetCont, KEY_SetRepeat, GFL_NET_RING_BUFF_Init, GFL_NET_RING_BUFF_Write, GFL_NET_RING_BUFF_Read, GFL_NET_RING_BUFF_ReadByte, GFL_NET_RING_BUFF_ReadU16, GFL_NET_RING_BUFF_Peek, GFL_NET_RING_BUFF_GetDataSize, GFL_NET_RING_BUFF_GetFreeSize, GFL_NET_RING_BUFF_WrapPos, GFL_NET_RING_BUFF_GetWritableSize, GFL_NET_RING_BUFF_EndChange, GFL_NET_QUEUE_GetFreeNode, GFL_NET_QUEUE_IsEmpty, GFL_NET_QUEUE_GetCount, GFL_NET_QUEUE_PopList, GFL_NET_QUEUE_PutByte, GFL_NET_QUEUE_WriteHeader, GFL_NET_QUEUE_WriteNode, GFL_NET_QUEUE_Put, GFL_NET_QUEUE_GetNext, GFL_NET_QUEUE_RemoveNext, GFL_NET_QUEUE_FillSendBuffer, GFL_NET_QUEUE_Init, GFL_NET_QUEUE_Reset, GFL_NET_QUEUE_Exit, GFL_NET_QUEUE_IsCommandQueued, GFL_NET_WM_ICON_Create, GFL_NET_WM_ICON_Draw, GFL_NET_WM_ICON_GetEngine, GFL_NET_WM_ICON_GetCharName, GFL_NET_WM_ICON_SetLevel, GFL_NET_WM_ICON_Delete, GFL_NET_WM_ICON_SetScreen, GFL_NET_WM_ICON_GetCharOffset, GFL_NET_WM_ICON_LoadGraphics, GFL_NET_WM_ICON_ClearOam, GFL_NET_WM_ICON_EasyStart, GFL_NET_WM_ICON_EasyEnd, GFL_NET_WM_ICON_EasySetLevel, GFL_NET_WM_ICON_EasySetScreen, GFL_NET_WM_ICON_EasyMain, func_02037174, func_02037190, func_020371AC, GFL_NET_WM_ICON_SetDefaultScreen, GFL_NET_WM_ICON_EasyGetEngine
 * address:  0x02035750
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x02035750 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   sub_02035224                     0x02035224  arm
 *   sub_0203521C                     0x0203521C  arm
 *   func_02030734                    0x02030734  arm
 *   func_020307B0                    0x020307B0  arm
 *   func_02034714                    0x02034714  arm
 *   GFL_NET_SYSTEM_SetError                    0x02039548  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   TP_Init                          0x0208A924  arm
 *   TP_GetUserInfo                   0x0208A998  arm
 *   TP_SetCalibrateParam             0x0208AA2C  arm
 *   TP_RequestSamplingAsync          0x0208AB1C  arm
 *   TP_WaitRawResult                 0x0208ABB8  arm
 *   TP_RequestAutoSamplingStartAsync 0x0208AC0C  arm
 *   TP_RequestAutoSamplingStopAsync  0x0208AD14  arm
 *   TP_GetLatestRawPointInAuto       0x0208ADB4  arm
 *   TP_GetCalibratedPoint            0x0208B104  arm
 *   TP_WaitBusy                      0x0208B220  arm
 *   TP_CheckError                    0x0208B238  arm
 *   GX_GetBankForOBJ                 0x02080C24  arm
 *   GX_GetBankForSubOBJ              0x02080C64  arm
 *   GX_LoadOAM                       0x0207E684  arm
 *   GXS_LoadOAM                      0x0207E708  arm
 *   func_0200F168                    0x0200F168  thumb
 *   func_0200F16C                    0x0200F16C  thumb
 *   func_020490F4                    0x020490F4  arm
 *   func_02049B68                    0x02049B68  arm
 *   func_02049800                    0x02049800  arm
 *   func_02049238                    0x02049238  arm
 *   _pTouchPanelWork                 0x021469C4  data
 *   _WmIconEasy                      0x021469C8  data
 *   touchpanel_File                  0x020A798C  data
 *   key_File                         0x020A799C  data
 *   net_ring_buff_File               0x020A79A4  data
 *   net_ring_buff_AssertDataArea     0x020A79B4  data
 *   net_ring_buff_AssertZero         0x020A79C0  data
 *   net_queue_File                   0x020A79C4  data
 *   net_queue_AssertZero             0x020A79D0  data
 *   net_queue_AssertSize             0x020A79D4  data
 *   net_queue_AssertRet              0x020A79EC  data
 *   wm_icon_File                     0x020A79F0  data
 *   wm_icon_AssertObjMapping         0x020A79FC  data
 *   wm_icon_HiddenOam                0x020A0810  data
 */

/*
 * This file holds five original source files, in image order (cut points
 * from their __FILE__ words):
 *   touchpanel.c     0x02035750..0x02035EE8  touch panel sampling, hit tests
 *   key.c            0x02035EE8..0x0203640C  pad reading, key repeat
 *   net_ring_buff.c  0x0203640C..0x02036670  byte ring buffer of the net code
 *   net_queue.c      0x02036670..0x02036BD4  send queue of the net code
 *   wm_icon.c        0x02036BD4..0x02037224  wireless signal icon
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef int            BOOL;
typedef volatile u16   vu16;
typedef volatile u32   vu32;

#include "net_types.h"

#define HW_BUTTON_XY_BUF    0x02FFFFA8
#define REG_KEYINPUT        0x04000130
#define REG_POWCNT          0x04000304
#define REG_DISPCNT         0x04000000
#define REG_DB_DISPCNT      0x04001000
#define HW_OAM              0x07000000
#define HW_DB_OAM           0x07000400
#define PAD_ALL_MASK        0x2FFF

/* ui.c: UI frame rate values (UiCtx.frameRate) */
#define UI_FRAMERATE_30     30

/* SDK TPData validity values */
#define TP_VALIDITY_VALID       0
#define TP_VALIDITY_INVALID_X   1
#define TP_VALIDITY_INVALID_Y   2
#define TP_VALIDITY_INVALID_XY  3

/* touch hit table codes (first byte of an entry) */
#define TOUCHPANEL_HIT_END      0xff
#define TOUCHPANEL_HIT_CIRCLE   0xfe
#define TOUCHPANEL_HIT_SKIP     0xfd

/* SDK touch panel sample */
typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

/* One entry of a touch hit table: a rectangle, or a circle when the first
 * byte is TOUCHPANEL_HIT_CIRCLE.  TOUCHPANEL_HIT_END ends the table. */
typedef union {
    struct {
        u8 top;
        u8 bottom;
        u8 left;
        u8 right;
    } rect;
    struct {
        u8 code;
        u8 x;
        u8 y;
        u8 r;
    } circle;
} TouchHitTable;

/* touchpanel.c work, 0x7c bytes (held by UiCtx.tpWork and _pTouchPanelWork) */
typedef struct {
    u8     pad00[0x0C];          /* nothing reads it */
    TPData autoSampleBuf[9];     /* 0x0C: auto sampling buffer */
    u8     pad54[4];             /* nothing reads it */
    u16    autoSampleMode;       /* 0x58: auto sampling is used */
    u16    autoSampleStopped;    /* 0x5A: auto sampling is stopped for now */
    u16    x;                    /* 0x5C */
    u16    y;                    /* 0x5E */
    u16    trg;                  /* 0x60 */
    u16    cont;                 /* 0x62 */
    u16    x30;                  /* 0x64: values for a 30 fps frame */
    u16    y30;
    u16    trg30;
    u16    cont30;
    u16    pendX;                /* 0x6C: collected over the frame pair */
    u16    pendY;
    u16    pendTrg;
    u16    pendCont;
    u8     autoSampleActive;     /* 0x74: read the auto sampling result */
    u8     autoSampleFreq;       /* 0x75 */
    u8     autoSampleIndex;      /* 0x76 */
    u8     pad77[5];             /* nothing reads it */
} TouchPanelWork;

/* key.c: one entry of a control mode table (key conversion) */
typedef struct {
    u32 srcKey;
    u32 dstKey;
    u8  kind;                    /* KEY_CONV_* */
    u8  pad09[3];
} KeyConvEntry;

#define KEY_CONV_END    0
#define KEY_CONV_COPY   1
#define KEY_CONV_SWAP   2
#define KEY_CONV_MASK   3

/* key.c work, 0x4c bytes (held by UiCtx.keyWork) */
typedef struct {
    const KeyConvEntry *controlModeTable;  /* 0x00 */
    u32 controlModeCount;        /* 0x04 */
    u32 controlMode;             /* 0x08: entry index into the table */
    u32 rawCont;                 /* 0x0C: pad state before conversion */
    u32 rawTrg;
    u32 rawRepeat;
    u32 cont;                    /* 0x18: after conversion */
    u32 trg;
    u32 repeat;
    u32 cont30;                  /* 0x24: values for a 30 fps frame */
    u32 trg30;
    u32 repeat30;
    u32 pendCont;                /* 0x30: collected over the frame pair */
    u32 pendTrg;
    u32 pendRepeat;
    s32 repeatCounter;           /* 0x3C */
    s32 repeatSpeed;             /* 0x40 */
    s32 repeatWait;              /* 0x44 */
    u32 pad48;                   /* nothing reads it */
} KeyWork;

/* ui.c system object; only the members this file uses */
typedef struct UiCtx {
    KeyWork        *keyWork;     /* 0x00 */
    TouchPanelWork *tpWork;      /* 0x04 */
    u8              uiState[0x35]; /* 0x08: callbacks and flags of ui.c */
    u8              frameRate;   /* 0x3D: 60 or UI_FRAMERATE_30 */
    u8              frameCounter; /* 0x3E */
} UiCtx;

/* wm_icon.c: the wireless icon, 0x14 bytes */
typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

typedef struct {
    u32 level;                   /* 0x00: signal level 0..3 */
    u16 x;                       /* 0x04 */
    u16 y;                       /* 0x06 */
    u8  pad08[4];
    u8  iconVariant;             /* 0x0C: picks the character set */
    u8  screen;                  /* 0x0D: 1 top, 2 bottom */
    u8  screenChanged;           /* 0x0E: may be on both OAMs */
    u8  objWindow;               /* 0x0F: draw an OBJ window under it */
    GXOamAttr *lastOam;          /* 0x10: OAM of the last draw */
} WmIcon;

/* wm_icon.c defaults and the one icon the Easy calls drive */
typedef struct {
    u16 defaultX;
    u16 defaultY : 14;
    u16 screen   : 2;
    WmIcon *icon;
} WmIconEasy;

/* unit_0200EE48.c: archive data ids of the icon graphics */
typedef struct {
    u32 charData[2];
    u32 palette;
} WmIconArcData;

extern UiCtx *sub_02035224(void);
extern KeyWork *sub_0203521C(UiCtx *ui);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern void func_02034714(const char *file, u32 line, const char *expr);
extern void GFL_NET_SYSTEM_SetError(void);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void TP_Init(void);
extern int  TP_GetUserInfo(u16 *info);
extern void TP_SetCalibrateParam(u16 *info);
extern void TP_RequestSamplingAsync(void);
extern u32  TP_WaitRawResult(TPData *result);
extern void TP_RequestAutoSamplingStartAsync(u32 vcount, u32 freq, TPData *buf, u32 size);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_GetLatestRawPointInAuto(TPData *result);
extern void TP_GetCalibratedPoint(TPData *disp, const TPData *raw);
extern void TP_WaitBusy(u32 command);
extern u32  TP_CheckError(u32 command);
extern u32  GX_GetBankForOBJ(void);
extern u32  GX_GetBankForSubOBJ(void);
extern void GX_LoadOAM(const void *src, u32 offset, u32 size);
extern void GXS_LoadOAM(const void *src, u32 offset, u32 size);
extern u32  func_0200F168(void);
extern void func_0200F16C(WmIconArcData *ids);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049B68(void *arc, u32 dataId, int palType, int offset, int size, int heapId);
extern void func_02049800(void *arc, u32 dataId, int engine, int offset, int a4, int a5, int heapId);
extern void func_02049238(void *arc);

/* touchpanel.c */
TouchPanelWork *TOUCHPANEL_GetWork(void);
u16 TOUCHPANEL_ReadPointX(UiCtx *ui);
u16 TOUCHPANEL_ReadPointY(UiCtx *ui);
int TOUCHPANEL_ReadCont(UiCtx *ui);
u16 TOUCHPANEL_ReadTrg(UiCtx *ui);
TouchPanelWork *TOUCHPANEL_Create(u32 heapId);
void TOUCHPANEL_MainSys(UiCtx *ui);
void TOUCHPANEL_Main(void);
u32 TOUCHPANEL_HitCircle(const TouchHitTable *hit, s32 x, s32 y);
u32 TOUCHPANEL_HitRect(const TouchHitTable *hit, u32 x, u32 y);
int TOUCHPANEL_SearchHitTable(const TouchHitTable *tbl, u32 x, u32 y);
int TOUCHPANEL_HitContSys(UiCtx *ui, const TouchHitTable *tbl);
int TOUCHPANEL_HitCont(const TouchHitTable *tbl);
int TOUCHPANEL_HitTrgSys(UiCtx *ui, const TouchHitTable *tbl);
int func_02035C08(const TouchHitTable *tbl);
int TOUCHPANEL_GetContSys(UiCtx *ui);
int TOUCHPANEL_GetCont(void);
u16 TOUCHPANEL_GetTrgSys(UiCtx *ui);
int TOUCHPANEL_GetTrg(void);
u32 TOUCHPANEL_GetPointContSys(UiCtx *ui, u32 *x, u32 *y);
u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);
u32 TOUCHPANEL_GetPointTrgSys(UiCtx *ui, u32 *x, u32 *y);
u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
u32 TOUCHPANEL_HitPoint(const TouchHitTable *tbl, u32 x, u32 y);
u32 TOUCHPANEL_RequestAutoSamplingStop(TouchPanelWork *tp);
void TOUCHPANEL_AutoSamplingRestartSys(UiCtx *ui);
void TOUCHPANEL_AutoSamplingRestart(void);
void TOUCHPANEL_AutoSamplingStopSys(UiCtx *ui);
void TOUCHPANEL_AutoSamplingStop(void);
u32 TOUCHPANEL_RequestAutoSamplingStart(TouchPanelWork *tp);
void TOUCHPANEL_ClearFrameRateWork(UiCtx *ui);
void TOUCHPANEL_SetPoint(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30);
void TOUCHPANEL_SetTrg(UiCtx *ui, int trg, int trg30);
void TOUCHPANEL_SetCont(UiCtx *ui, int cont, int cont30);
/* key.c */
KeyWork *KEY_Create(u32 heapId);
void KEY_MainSys(UiCtx *ui);
void KEY_Main(void);
void KEY_ApplyControlMode(KeyWork *key);
void KEY_SetRepeatSpeedSys(UiCtx *ui, int speed, int wait);
void KEY_SetRepeatSpeed(int speed, int wait);
void KEY_SetControlModeTableSys(UiCtx *ui, const KeyConvEntry *table);
void KEY_SetControlModeTable(const KeyConvEntry *table);
u32 KEY_GetTrgSys(UiCtx *ui);
u32 KEY_GetTrg(void);
u32 KEY_GetContSys(UiCtx *ui);
u32 KEY_GetCont(void);
u32 KEY_GetRepeatSys(UiCtx *ui);
u32 KEY_GetRepeat(void);
void KEY_GetRepeatSpeedSys(UiCtx *ui, u32 *speed, u32 *wait);
void KEY_GetRepeatSpeed(u32 *speed, u32 *wait);
void KEY_ClearFrameRateWork(UiCtx *ui);
void KEY_SetTrg(UiCtx *ui, int trg, int trg30);
void KEY_SetCont(UiCtx *ui, int cont, int cont30);
void KEY_SetRepeat(UiCtx *ui, int repeat, int repeat30);
/* net_ring_buff.c */
void GFL_NET_RING_BUFF_Init(NetRingBuff *ring, u8 *buf, int size);
void GFL_NET_RING_BUFF_Write(NetRingBuff *ring, const u8 *pDataArea, int size);
int GFL_NET_RING_BUFF_Read(NetRingBuff *ring, u8 *dst, u32 size, u32 max);
u32 GFL_NET_RING_BUFF_ReadByte(NetRingBuff *ring);
u32 GFL_NET_RING_BUFF_ReadU16(NetRingBuff *ring);
int GFL_NET_RING_BUFF_Peek(const NetRingBuff *ring, u8 *dst, int size, int max);
int GFL_NET_RING_BUFF_GetDataSize(NetRingBuff *ring);
int GFL_NET_RING_BUFF_GetFreeSize(NetRingBuff *ring);
int GFL_NET_RING_BUFF_WrapPos(const NetRingBuff *ring, int pos);
int GFL_NET_RING_BUFF_GetWritableSize(NetRingBuff *ring);
void GFL_NET_RING_BUFF_EndChange(NetRingBuff *ring);
/* net_queue.c */
NetQueueNode *GFL_NET_QUEUE_GetFreeNode(NetQueue *queue);
int GFL_NET_QUEUE_IsEmpty(NetQueue *queue);
int GFL_NET_QUEUE_GetCount(NetQueue *queue);
u32 GFL_NET_QUEUE_PopList(NetQueueList *list);
void GFL_NET_QUEUE_PutByte(NetSendBuf *out, int byte);
int GFL_NET_QUEUE_WriteHeader(NetQueueNode *node, NetSendBuf *out);
int GFL_NET_QUEUE_WriteNode(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader);
int GFL_NET_QUEUE_Put(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID);
NetQueueNode *GFL_NET_QUEUE_GetNext(NetQueue *queue);
void GFL_NET_QUEUE_RemoveNext(NetQueue *queue);
int GFL_NET_QUEUE_FillSendBuffer(NetQueue *queue, NetSendBuf *out);
void GFL_NET_QUEUE_Init(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId);
void GFL_NET_QUEUE_Reset(NetQueue *queue);
void GFL_NET_QUEUE_Exit(NetQueue *queue);
int GFL_NET_QUEUE_IsCommandQueued(NetQueue *queue, int command);
/* wm_icon.c */
WmIcon *GFL_NET_WM_ICON_Create(u32 unused, u32 heapId, u32 x, u32 y, u32 iconVariant, WmIcon *icon, u32 screen, u32 screenChanged, u32 level);
void GFL_NET_WM_ICON_Draw(WmIcon *icon);
u32 GFL_NET_WM_ICON_GetEngine(const WmIcon *icon);
u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 charNo);
WmIcon *GFL_NET_WM_ICON_SetLevel(WmIcon *icon, int level);
void GFL_NET_WM_ICON_Delete(WmIcon *icon);
void GFL_NET_WM_ICON_SetScreen(WmIcon *icon, u32 isTop, u32 heapId);
int GFL_NET_WM_ICON_GetCharOffset(int engine);
void GFL_NET_WM_ICON_LoadGraphics(int engine, int iconVariant, int heapId);
void GFL_NET_WM_ICON_ClearOam(void);
void GFL_NET_WM_ICON_EasyStart(u32 x, u32 y, u32 iconVariant, u32 heapId);
void GFL_NET_WM_ICON_EasyEnd(void);
u32 GFL_NET_WM_ICON_EasySetLevel(u32 level);
void GFL_NET_WM_ICON_EasySetScreen(u32 isTop, u32 heapId);
void GFL_NET_WM_ICON_EasyMain(void);
void func_02037174(void);
void func_02037190(void);
void func_020371AC(u16 x, u16 y);
void GFL_NET_WM_ICON_SetDefaultScreen(u32 screen);
u32 GFL_NET_WM_ICON_EasyGetEngine(void);

extern TouchPanelWork *_pTouchPanelWork;
extern WmIconEasy _WmIconEasy;
extern const char touchpanel_File[];
extern const char key_File[];
extern const char net_ring_buff_File[];
extern const char net_ring_buff_AssertDataArea[];
extern const char net_ring_buff_AssertZero[];
extern const char net_queue_File[];
extern const char net_queue_AssertZero[];
extern const char net_queue_AssertSize[];
extern const char net_queue_AssertRet[];
extern const char wm_icon_File[];
extern const char wm_icon_AssertObjMapping[];
extern const u32 wm_icon_HiddenOam[8];

/* ==================================================================
 * touchpanel.c
 * ================================================================== */

TouchPanelWork *TOUCHPANEL_GetWork(void)
{
    return _pTouchPanelWork;
}

/*
 * Point and button accessors: with the UI at 30 fps the values collected
 * over the frame pair are reported, otherwise the ones of this frame.
 * The work comes from TOUCHPANEL_GetWork and the frame rate from the argument,
 * which is why the argument is kept in r4 across the call.
 */
u16 TOUCHPANEL_ReadPointX(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->x30;
    return tp->x;
}

u16 TOUCHPANEL_ReadPointY(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->y30;
    return tp->y;
}

int TOUCHPANEL_ReadCont(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->cont30;
    return tp->cont;
}

u16 TOUCHPANEL_ReadTrg(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->trg30;
    return tp->trg;
}

/*
 * Allocates and clears the work, brings the touch panel up with the user
 * calibration (or a default one when none is stored).
 */
TouchPanelWork *TOUCHPANEL_Create(u32 heapId)
{
    u16 info[4];
    TouchPanelWork *tp = func_02030734(heapId, sizeof(TouchPanelWork), 0, touchpanel_File, 0x83);

    MI_CpuFill8(tp, 0, sizeof(TouchPanelWork));
    tp->autoSampleMode = 0;
    tp->autoSampleStopped = 0;
    TP_Init();
    if (TP_GetUserInfo(info) == 1) {
        TP_SetCalibrateParam(info);
    } else {
        info[0] = 0x2ae;
        info[1] = 0x58c;
        info[2] = 0xe25;
        info[3] = 0x1208;
        TP_SetCalibrateParam(info);
    }
    tp->autoSampleFreq = 4;
    tp->autoSampleIndex = 0;
    _pTouchPanelWork = tp;
    return tp;
}

/*
 * The per-frame sampling pass.  With the lid closed (bit 15 of the button
 * word at HW_BUTTON_XY_BUF) the work is cleared.  Otherwise the panel is
 * sampled (manual sampling retries up to 32 times), calibrated, and the
 * point and button state latched; every second frame the 30 fps values
 * take what was collected over the pair.
 *
 * Declaration facts that carry the register allocation: `raw` is declared
 * before `cal` (the converter's output `cal` is the sp+0 object), and the
 * work pointer is first bound to `tpTmp`, declared last, then copied into
 * `tp`; that copy keeps the loop counter in r4.
 */
void TOUCHPANEL_MainSys(UiCtx *ui)
{
    TPData raw;
    TPData cal;
    TouchPanelWork *tp;
    u32 done = 0;
    u32 n;
    TouchPanelWork *tpTmp = TOUCHPANEL_GetWork();

    tp = tpTmp;
    if (tp == 0) {
        return;
    }
    if ((s32)(*(u16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15 != 0) {
        MI_CpuFill8(tp, 0, sizeof(TouchPanelWork));
        return;
    }
    if (tp->autoSampleActive == 0) {
        n = 0;
        TP_RequestSamplingAsync();
        if (TP_WaitRawResult(&raw) != 0) {
            do {
                n = (n + 1) & 0xff;
                if (n >= 0x20) {
                    cal.validity = TP_VALIDITY_INVALID_XY;
                    done = 1;
                    break;
                }
                TP_RequestSamplingAsync();
            } while (TP_WaitRawResult(&raw) != 0);
        }
    } else {
        TP_GetLatestRawPointInAuto(&raw);
    }
    if (done == 0) {
        TP_GetCalibratedPoint(&cal, &raw);
    }
    if (cal.validity == TP_VALIDITY_VALID) {
        tp->x = cal.x;
        tp->y = cal.y;
    } else if (tp->cont != 0) {
        if (cal.validity != TP_VALIDITY_INVALID_X) {
            if (cal.validity == TP_VALIDITY_INVALID_Y) {
                tp->x = cal.x;
            }
        } else {
            tp->y = cal.y;
        }
    } else {
        cal.touch = 0;
    }
    tp->trg = cal.touch & (cal.touch ^ tp->cont);
    tp->cont = cal.touch;
    tp->pendTrg = tp->pendTrg | tp->trg;
    tp->pendCont = tp->pendCont | tp->cont;
    if (tp->y != 0) {
        tp->pendY = tp->y;
    }
    if (tp->x != 0) {
        tp->pendX = tp->x;
    }
    if (ui->frameCounter % 2 == 0) {
        tp->x30 = tp->pendX;
        tp->y30 = tp->pendY;
        tp->trg30 = tp->pendTrg;
        tp->cont30 = tp->pendCont;
        tp->pendX = 0;
        tp->pendY = 0;
        tp->pendTrg = 0;
        tp->pendCont = 0;
    }
}

void TOUCHPANEL_Main(void)
{
    TOUCHPANEL_MainSys(sub_02035224());
}

/* Inside a circle entry: strictly closer than the radius. */
u32 TOUCHPANEL_HitCircle(const TouchHitTable *hit, s32 x, s32 y)
{
    s32 dx = hit->circle.x - x;
    s32 dy = hit->circle.y - y;
    u32 r = hit->circle.r;

    return (u32)(dx * dx + dy * dy) < r * r;
}

/* Inside a rectangle entry (unsigned range tests). */
u32 TOUCHPANEL_HitRect(const TouchHitTable *hit, u32 x, u32 y)
{
    if (x - hit->rect.left <= (u32)(hit->rect.right - hit->rect.left)
        && y - hit->rect.top <= (u32)(hit->rect.bottom - hit->rect.top))
        return 1;
    return 0;
}

/* Index of the first table entry the point falls inside, or -1. */
int TOUCHPANEL_SearchHitTable(const TouchHitTable *tbl, u32 x, u32 y)
{
    int i = 0;

    while (tbl[i].circle.code != TOUCHPANEL_HIT_END) {
        if (tbl[i].circle.code != TOUCHPANEL_HIT_SKIP) {
            if (tbl[i].circle.code == TOUCHPANEL_HIT_CIRCLE) {
                if (TOUCHPANEL_HitCircle(&tbl[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (TOUCHPANEL_HitRect(&tbl[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}

int TOUCHPANEL_HitContSys(UiCtx *ui, const TouchHitTable *tbl)
{
    u32 x;
    u32 y;

    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadCont(ui) == 0) {
        return -1;
    }
    x = TOUCHPANEL_ReadPointX(ui);
    y = TOUCHPANEL_ReadPointY(ui);
    return TOUCHPANEL_SearchHitTable(tbl, x, y);
}

int TOUCHPANEL_HitCont(const TouchHitTable *tbl)
{
    return TOUCHPANEL_HitContSys(sub_02035224(), tbl);
}

int TOUCHPANEL_HitTrgSys(UiCtx *ui, const TouchHitTable *tbl)
{
    u32 x;
    u32 y;

    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadTrg(ui) == 0) {
        return -1;
    }
    x = TOUCHPANEL_ReadPointX(ui);
    y = TOUCHPANEL_ReadPointY(ui);
    return TOUCHPANEL_SearchHitTable(tbl, x, y);
}

int func_02035C08(const TouchHitTable *tbl)
{
    return TOUCHPANEL_HitTrgSys(sub_02035224(), tbl);
}

int TOUCHPANEL_GetContSys(UiCtx *ui)
{
    TOUCHPANEL_GetWork();
    return TOUCHPANEL_ReadCont(ui);
}

int TOUCHPANEL_GetCont(void)
{
    return TOUCHPANEL_GetContSys(sub_02035224());
}

u16 TOUCHPANEL_GetTrgSys(UiCtx *ui)
{
    TOUCHPANEL_GetWork();
    return TOUCHPANEL_ReadTrg(ui);
}

int TOUCHPANEL_GetTrg(void)
{
    return TOUCHPANEL_GetTrgSys(sub_02035224());
}

u32 TOUCHPANEL_GetPointContSys(UiCtx *ui, u32 *x, u32 *y)
{
    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadCont(ui) == 0) {
        return 0;
    }
    *x = TOUCHPANEL_ReadPointX(ui);
    *y = TOUCHPANEL_ReadPointY(ui);
    return 1;
}

u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y)
{
    return TOUCHPANEL_GetPointContSys(sub_02035224(), x, y);
}

u32 TOUCHPANEL_GetPointTrgSys(UiCtx *ui, u32 *x, u32 *y)
{
    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadTrg(ui) == 0) {
        return 0;
    }
    *x = TOUCHPANEL_ReadPointX(ui);
    *y = TOUCHPANEL_ReadPointY(ui);
    return 1;
}

u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y)
{
    return TOUCHPANEL_GetPointTrgSys(sub_02035224(), x, y);
}

u32 TOUCHPANEL_HitPoint(const TouchHitTable *tbl, u32 x, u32 y)
{
    return (u32)TOUCHPANEL_SearchHitTable(tbl, (u16)x, (u16)y);
}

/* Stops auto sampling when it is used; 2 on a TP error, else 1. */
u32 TOUCHPANEL_RequestAutoSamplingStop(TouchPanelWork *tp)
{
    if (tp->autoSampleMode == 0) {
        return 1;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    if (TP_CheckError(4) != 0) {
        return 2;
    }
    return 1;
}

void TOUCHPANEL_AutoSamplingRestartSys(UiCtx *ui)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    if (tp != 0 && tp->autoSampleStopped != 0 && tp->autoSampleMode != 0) {
        TOUCHPANEL_RequestAutoSamplingStart(tp);
        tp->autoSampleStopped = 0;
    }
}

void TOUCHPANEL_AutoSamplingRestart(void)
{
    TOUCHPANEL_AutoSamplingRestartSys(sub_02035224());
}

void TOUCHPANEL_AutoSamplingStopSys(UiCtx *ui)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    if (tp != 0 && tp->autoSampleStopped != 1 && tp->autoSampleMode != 0) {
        TOUCHPANEL_RequestAutoSamplingStop(tp);
        tp->autoSampleStopped = 1;
    }
}

void TOUCHPANEL_AutoSamplingStop(void)
{
    TOUCHPANEL_AutoSamplingStopSys(sub_02035224());
}

/* Starts auto sampling into the work buffer; 1 when it started, else 2. */
u32 TOUCHPANEL_RequestAutoSamplingStart(TouchPanelWork *tp)
{
    u32 ret;

    TP_RequestAutoSamplingStartAsync(0, tp->autoSampleFreq, tp->autoSampleBuf, 9);
    ret = 2;
    TP_WaitBusy(2);
    if (TP_CheckError(2) == 0) {
        ret = 1;
    }
    return ret;
}

void TOUCHPANEL_ClearFrameRateWork(UiCtx *ui)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    tp->x30 = 0;
    tp->y30 = 0;
    tp->trg30 = 0;
    tp->cont30 = 0;
    tp->pendX = 0;
    tp->pendY = 0;
    tp->pendTrg = 0;
    tp->pendCont = 0;
}

void TOUCHPANEL_SetPoint(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30)
{
    TouchPanelWork *tp;

    tp = TOUCHPANEL_GetWork();
    tp->x30 = x30;
    tp->y30 = y30;
    tp->x = x;
    tp->y = y;
}

void TOUCHPANEL_SetTrg(UiCtx *ui, int trg, int trg30)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    tp->trg30 = (u16)trg30;
    tp->trg = (u16)trg;
}

void TOUCHPANEL_SetCont(UiCtx *ui, int cont, int cont30)
{
    TouchPanelWork *tp = TOUCHPANEL_GetWork();

    tp->cont30 = (u16)cont30;
    tp->cont = (u16)cont;
}

/* ==================================================================
 * key.c
 * ================================================================== */

/* Allocates and clears the work; key repeat starts after 15 frames, then
 * every 8 frames. */
KeyWork *KEY_Create(u32 heapId)
{
    KeyWork *key = func_02030734(heapId, sizeof(KeyWork), 0, key_File, 0x44);

    MI_CpuFill8(key, 0, sizeof(KeyWork));
    key->repeatSpeed = 8;
    key->repeatWait = 0xf;
    return key;
}

static inline s32 KEY_PadDetectFold(void)
{
    return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15);
}

static inline u16 KEY_PadRead(void)
{
    return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF) ^ PAD_ALL_MASK) & PAD_ALL_MASK);
}

/*
 * The per-frame pad update: with the lid closed the converted and 30 fps
 * words are cleared; otherwise the pad is read (opposite directions
 * pressed together cancel), trigger and repeat are derived, the control
 * mode table is applied, and every second frame the 30 fps values take
 * what was collected over the pair.
 */
void KEY_MainSys(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);
    u16 pad;

    if (KEY_PadDetectFold()) {
        key->trg = 0;
        key->cont = 0;
        key->repeat = 0;
        key->trg30 = 0;
        key->cont30 = 0;
        key->repeat30 = 0;
        return;
    }
    pad = KEY_PadRead();
    pad = pad & ~((pad & 0x40) << 1) & ~((pad & 0x20) >> 1);
    key->rawTrg = pad & (pad ^ key->rawCont);
    key->rawRepeat = pad & (pad ^ key->rawCont);
    if (pad != 0 && key->rawCont == pad) {
        if (--key->repeatCounter == 0) {
            key->rawRepeat = pad;
            key->repeatCounter = key->repeatSpeed;
        }
    } else {
        key->repeatCounter = key->repeatWait;
    }
    key->rawCont = pad;
    key->trg = key->rawTrg;
    key->cont = pad;
    key->repeat = key->rawRepeat;
    KEY_ApplyControlMode(key);
    key->pendTrg |= key->trg;
    key->pendCont |= key->cont;
    key->pendRepeat |= key->repeat;
    if (ui->frameCounter % 2 != 0) {
        return;
    }
    key->trg30 = key->pendTrg;
    key->cont30 = key->pendCont;
    key->repeat30 = key->pendRepeat;
    key->pendTrg = 0;
    key->pendCont = 0;
    key->pendRepeat = 0;
}

void KEY_Main(void)
{
    KEY_MainSys(sub_02035224());
}

/* KEY_CONV_SWAP: the two keys trade places. */
static inline void KEY_ConvSwap(u32 *keys, const KeyConvEntry *conv)
{
    u32 swapped = 0;

    if (*keys & conv->srcKey)
        swapped |= conv->dstKey;
    if (*keys & conv->dstKey)
        swapped |= conv->srcKey;
    *keys &= (conv->srcKey | conv->dstKey) ^ 0xffff;
    *keys |= swapped;
}

/* KEY_CONV_COPY: the source key also presses the destination key. */
static inline void KEY_ConvCopy(u32 *keys, const KeyConvEntry *conv)
{
    if (*keys & conv->srcKey)
        *keys |= conv->dstKey;
}

/* KEY_CONV_MASK: the source key is dropped. */
static inline void KEY_ConvMask(u32 *keys, const KeyConvEntry *conv)
{
    *keys &= conv->srcKey ^ 0xffff;
}

/* Applies the entries of the current control mode to the converted words. */
void KEY_ApplyControlMode(KeyWork *key)
{
    const KeyConvEntry *conv;

    if (key->controlModeTable == 0)
        return;
    conv = key->controlModeTable + key->controlMode;
    for (;;) {
        switch (conv->kind) {
        case KEY_CONV_END:
            return;
        case KEY_CONV_COPY:
            KEY_ConvCopy(&key->trg, conv);
            KEY_ConvCopy(&key->cont, conv);
            KEY_ConvCopy(&key->repeat, conv);
            break;
        case KEY_CONV_SWAP:
            KEY_ConvSwap(&key->trg, conv);
            KEY_ConvSwap(&key->cont, conv);
            KEY_ConvSwap(&key->repeat, conv);
            break;
        case KEY_CONV_MASK:
            KEY_ConvMask(&key->trg, conv);
            KEY_ConvMask(&key->cont, conv);
            KEY_ConvMask(&key->repeat, conv);
            break;
        }
        conv++;
    }
}

void KEY_SetRepeatSpeedSys(UiCtx *ui, int speed, int wait)
{
    KeyWork *key = sub_0203521C(ui);

    key->repeatSpeed = speed;
    key->repeatWait = wait;
}

void KEY_SetRepeatSpeed(int speed, int wait)
{
    KEY_SetRepeatSpeedSys(sub_02035224(), speed, wait);
}

void KEY_SetControlModeTableSys(UiCtx *ui, const KeyConvEntry *table)
{
    KeyWork *key = sub_0203521C(ui);

    key->controlModeTable = table;
}

void KEY_SetControlModeTable(const KeyConvEntry *table)
{
    KEY_SetControlModeTableSys(sub_02035224(), table);
}

u32 KEY_GetTrgSys(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->trg30;
    }
    return key->trg;
}

u32 KEY_GetTrg(void)
{
    return KEY_GetTrgSys(sub_02035224());
}

u32 KEY_GetContSys(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->cont30;
    }
    return key->cont;
}

u32 KEY_GetCont(void)
{
    return KEY_GetContSys(sub_02035224());
}

u32 KEY_GetRepeatSys(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->repeat30;
    }
    return key->repeat;
}

u32 KEY_GetRepeat(void)
{
    return KEY_GetRepeatSys(sub_02035224());
}

void KEY_GetRepeatSpeedSys(UiCtx *ui, u32 *speed, u32 *wait)
{
    KeyWork *key = sub_0203521C(ui);

    *speed = key->repeatSpeed;
    *wait = key->repeatWait;
}

void KEY_GetRepeatSpeed(u32 *speed, u32 *wait)
{
    KEY_GetRepeatSpeedSys(sub_02035224(), speed, wait);
}

void KEY_ClearFrameRateWork(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    key->cont30 = 0;
    key->trg30 = 0;
    key->repeat30 = 0;
    key->pendCont = 0;
    key->pendTrg = 0;
    key->pendRepeat = 0;
}

void KEY_SetTrg(UiCtx *ui, int trg, int trg30)
{
    KeyWork *key = sub_0203521C(ui);

    key->trg30 = trg30;
    key->trg = trg;
}

void KEY_SetCont(UiCtx *ui, int cont, int cont30)
{
    KeyWork *key = sub_0203521C(ui);

    key->cont30 = cont30;
    key->cont = cont;
}

void KEY_SetRepeat(UiCtx *ui, int repeat, int repeat30)
{
    KeyWork *key = sub_0203521C(ui);

    key->repeat30 = repeat30;
    key->repeat = repeat;
}

/* ==================================================================
 * net_ring_buff.c
 * ================================================================== */

void GFL_NET_RING_BUFF_Init(NetRingBuff *ring, u8 *buf, int size)
{
    ring->buf = buf;
    ring->size = (short)size;   /* the store sign-extends from 16 bits */
    ring->readPos = 0;
    ring->writePos = 0;
}

/* Copies size bytes in at the write position; a full ring is a net error. */
void GFL_NET_RING_BUFF_Write(NetRingBuff *ring, const u8 *pDataArea, int size)
{
    int i;
    int k;

    if (GFL_NET_RING_BUFF_GetWritableSize(ring) <= size) {
        GFL_NET_SYSTEM_SetError();
        return;
    }
    k = 0;
    for (i = ring->writePos; i < ring->writePos + size; i++) {
        if (pDataArea == 0) {
            func_02034714(net_ring_buff_File, 0x44, net_ring_buff_AssertDataArea);
        }
        ring->buf[GFL_NET_RING_BUFF_WrapPos(ring, i)] = pDataArea[k];
        k++;
    }
    ring->writePos = (short)GFL_NET_RING_BUFF_WrapPos(ring, i);
}

/* Reads up to max bytes and moves the read position past them. */
int GFL_NET_RING_BUFF_Read(NetRingBuff *ring, u8 *dst, u32 size, u32 max)
{
    int got = GFL_NET_RING_BUFF_Peek(ring, dst, size, max);

    ring->readPos = (short)GFL_NET_RING_BUFF_WrapPos(ring, ring->readPos + got);
    return got;
}

u32 GFL_NET_RING_BUFF_ReadByte(NetRingBuff *ring)
{
    u8 byte;

    if (GFL_NET_RING_BUFF_Read(ring, &byte, 1, 1) == 1)
        return byte;
    func_02034714(net_ring_buff_File, 0x6C, net_ring_buff_AssertZero);
    return 0;
}

/* Big-endian halfword: the high byte comes first. */
u32 GFL_NET_RING_BUFF_ReadU16(NetRingBuff *ring)
{
    u16 hi;
    u32 lo;

    hi = (u16)(GFL_NET_RING_BUFF_ReadByte(ring) << 8);
    lo = GFL_NET_RING_BUFF_ReadByte(ring);
    return (u16)(hi | lo);
}

/* Copies up to max bytes from the read position without consuming them. */
int GFL_NET_RING_BUFF_Peek(const NetRingBuff *ring, u8 *dst, int size, int max)
{
    int i;
    int n;

    n = 0;
    for (i = ring->readPos; i < ring->readPos + size; i++) {
        if (ring->writePos == GFL_NET_RING_BUFF_WrapPos(ring, i) || n == max) {
            return n;
        }
        dst[n] = ring->buf[GFL_NET_RING_BUFF_WrapPos(ring, i)];
        n++;
    }
    return n;
}

/* Bytes waiting to be read. */
int GFL_NET_RING_BUFF_GetDataSize(NetRingBuff *ring)
{
    int readPos = ring->readPos;

    if (readPos > ring->writePos)
        return ring->size + ring->writePos - readPos;
    return ring->writePos - readPos;
}

int GFL_NET_RING_BUFF_GetFreeSize(NetRingBuff *ring)
{
    int used = GFL_NET_RING_BUFF_GetDataSize(ring);

    return ring->size - used;
}

int GFL_NET_RING_BUFF_WrapPos(const NetRingBuff *ring, int pos)
{
    return pos % ring->size;
}

static inline int GFL_NET_RING_BUFF_DataSize(NetRingBuff *ring)
{
    int readPos = ring->readPos;

    if (readPos > ring->writePos)
        return (u32)ring->size + ring->writePos - readPos;
    return ring->writePos - readPos;
}

/* Free space, with the data size computed inline. */
int GFL_NET_RING_BUFF_GetWritableSize(NetRingBuff *ring)
{
    return ring->size - GFL_NET_RING_BUFF_DataSize(ring);
}

/* Write commit hook; it does nothing in this version. */
void GFL_NET_RING_BUFF_EndChange(NetRingBuff *ring)
{
}

/* ==================================================================
 * net_queue.c
 * ================================================================== */

/* First node with no command, or 0 when all are in use. */
NetQueueNode *GFL_NET_QUEUE_GetFreeNode(NetQueue *queue)
{
    NetQueueNode *node;
    s32 i;
    s32 n;

    node = queue->nodes;
    n = queue->nodeMax;
    for (i = 0; i < n; i++) {
        if (node->command == 0)
            return node;
        node++;
    }
    return 0;
}

int GFL_NET_QUEUE_IsEmpty(NetQueue *queue)
{
    return GFL_NET_QUEUE_GetCount(queue) == 0;
}

/* Nodes in use. */
int GFL_NET_QUEUE_GetCount(NetQueue *queue)
{
    const NetQueueNode *node = queue->nodes;
    int i;
    int count = 0;
    int n = queue->nodeMax;

    for (i = 0; i < n; i++, node++) {
        if (node->command != 0)
            count++;
    }
    return count;
}

/* Unlinks the head node of a list; 0 when the list is empty. */
u32 GFL_NET_QUEUE_PopList(NetQueueList *list)
{
    NetQueueNode *next;

    next = list->head;
    if (next != 0) {
        next = next->next;
        if (next != 0) {
            list->head = next;
            next->prev = 0;
        } else {
            list->head = 0;
            list->tail = 0;
        }
        return 1;
    }
    return 0;
}

void GFL_NET_QUEUE_PutByte(NetSendBuf *out, int byte)
{
    *out->ptr = (u8)byte;
    out->ptr = out->ptr + 1;
    out->size = out->size - 1;
}

/* Five-byte header: command and size (high byte first), then sendID. */
int GFL_NET_QUEUE_WriteHeader(NetQueueNode *node, NetSendBuf *out)
{
    GFL_NET_QUEUE_PutByte(out, (node->command >> 8) & 0xff);
    GFL_NET_QUEUE_PutByte(out, node->command & 0xff);
    GFL_NET_QUEUE_PutByte(out, (node->size >> 8) & 0xff);
    GFL_NET_QUEUE_PutByte(out, node->size & 0xff);
    GFL_NET_QUEUE_PutByte(out, node->sendID);
    return 0;
}

/*
 * Moves one node into the send buffer: the header first (refused with 0
 * when needHeader is set and header and data do not fit), then as much
 * data as fits.  When the data does not fit, the buffer is marked full
 * (0xffff) and the node keeps the rest.
 */
int GFL_NET_QUEUE_WriteNode(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader)
{
    if (node->headerSent == 0) {
        if (needHeader != 0 && out->size < node->size + 5) {
            return 0;
        }
        GFL_NET_QUEUE_WriteHeader(node, out);
    }
    if (out->size < node->size) {
        if (node->data == 0) {
            GFL_NET_RING_BUFF_Read(ring, out->ptr, out->size, out->size);
        } else {
            MI_CpuCopy8(node->data, out->ptr, out->size);
            node->data += out->size;
        }
        node->size = node->size - out->size;
        out->size = 0xffff;
        node->headerSent = 1;
        return 1;
    }
    if (node->data == 0) {
        GFL_NET_RING_BUFF_Read(ring, out->ptr, node->size, node->size);
    } else {
        MI_CpuCopy8(node->data, out->ptr, node->size);
    }
    out->ptr += node->size;
    out->size = out->size - node->size;
    return 1;
}

/*
 * Queues one send.  With copyToRing the data is copied into the ring now,
 * else the node keeps the caller's pointer.  isFast is not used in this
 * version: every node goes on the fast list.
 */
int GFL_NET_QUEUE_Put(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID)
{
    NetQueueNode *node = GFL_NET_QUEUE_GetFreeNode(queue);

    if (node == 0) {
        func_02034714(net_queue_File, 0xdb, net_queue_AssertZero);
        return 0;
    }
    if (!((u16)size < 0xffff / 2)) {
        func_02034714(net_queue_File, 0xdf, net_queue_AssertSize);
    }
    if (copyToRing != 0) {
        if (!((int)(size + 5) < (int)GFL_NET_RING_BUFF_GetFreeSize(queue->ring))) {
            func_02034714(net_queue_File, 0xe3, net_queue_AssertZero);
            return 0;
        }
        GFL_NET_RING_BUFF_Write(queue->ring, pDataArea, size);
        GFL_NET_RING_BUFF_EndChange(queue->ring);
        node->data = 0;
    } else {
        node->data = pDataArea;
    }
    node->size = size;
    node->command = command;
    node->sendID = sendID;
    node->headerSent = 0;
    if (queue->fast.tail == 0) {
        queue->fast.tail = node;
        queue->fast.head = node;
    } else {
        queue->fast.tail->next = node;
        node->prev = queue->fast.tail;
        queue->fast.tail = node;
    }
    return 1;
}

/* Next node to send: the cut one first, then the fast list, then the slow. */
NetQueueNode *GFL_NET_QUEUE_GetNext(NetQueue *queue)
{
    if (queue->current != 0)
        return queue->current;
    if (queue->fast.head != 0)
        return queue->fast.head;
    if (queue->slow.head != 0)
        return queue->slow.head;
    return 0;
}

/* Removes the node GFL_NET_QUEUE_GetNext picked. */
void GFL_NET_QUEUE_RemoveNext(NetQueue *queue)
{
    if (queue->current != 0) {
        queue->current = 0;
        return;
    }
    if (GFL_NET_QUEUE_PopList(&queue->fast) != 0) {
        return;
    }
    if (GFL_NET_QUEUE_PopList(&queue->slow) != 0) {
        return;
    }
    func_02034714(net_queue_File, 0x12f, net_queue_AssertRet);
}

/*
 * Fills the send buffer from the queue.  Returns 0 only when the buffer
 * filled up in the middle of a node after at least one node went in.
 */
int GFL_NET_QUEUE_FillSendBuffer(NetQueue *queue, NetSendBuf *out)
{
    int needHeader = 0;

    if (out->size == 0)
        goto done;
    while (1) {
        NetQueueNode *node = GFL_NET_QUEUE_GetNext(queue);

        if (node == 0)
            goto done;
        GFL_NET_QUEUE_RemoveNext(queue);
        if (GFL_NET_QUEUE_WriteNode(node, out, queue->ring, needHeader) == 0) {
            queue->current = node;
            goto done;
        }
        needHeader = 1;
        if (out->size == 0xffff) {
            queue->current = node;
            return 0;
        }
        MI_CpuFill8(node, 0, sizeof(NetQueueNode));
        if (out->size == 0)
            break;
    }
done:
    return 1;
}

void GFL_NET_QUEUE_Init(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId)
{
    MI_CpuFill8(queue, 0, sizeof(NetQueue));
    queue->nodes = func_02030734(heapId, nodeMax * sizeof(NetQueueNode), 1, net_queue_File, 0x173);
    queue->nodeMax = nodeMax;
    queue->ring = ring;
}

void GFL_NET_QUEUE_Reset(NetQueue *queue)
{
    MI_CpuFill8(queue->nodes, 0, queue->nodeMax * sizeof(NetQueueNode));
    queue->fast.head = 0;
    queue->fast.tail = 0;
    queue->slow.head = 0;
    queue->slow.tail = 0;
    queue->current = 0;
}

void GFL_NET_QUEUE_Exit(NetQueue *queue)
{
    func_020307B0(queue->nodes);
}

/* Is a node with this command queued? */
int GFL_NET_QUEUE_IsCommandQueued(NetQueue *queue, int command)
{
    int i;
    NetQueueNode *node = queue->nodes;
    int n = queue->nodeMax;

    for (i = 0; i < n; i++, node++) {
        if (node->command == command)
            return 1;
    }
    return 0;
}

/* ==================================================================
 * wm_icon.c
 * ================================================================== */

/*
 * Sets up an icon (allocating it when icon is 0) and loads its graphics.
 * A default position set with func_020371AC wins over x and y.
 */
WmIcon *GFL_NET_WM_ICON_Create(u32 unused, u32 heapId, u32 x, u32 y, u32 iconVariant,
                      WmIcon *icon, u32 screen, u32 screenChanged, u32 level)
{
    if (icon == 0)
        icon = func_02030734((u16)(((u16)heapId & 0x7fff) | 0x8000), sizeof(WmIcon), 0,
                             wm_icon_File, 100);
    icon->x = x;
    icon->y = y;
    if (_WmIconEasy.defaultX != 0) {
        icon->x = _WmIconEasy.defaultX;
        icon->y = _WmIconEasy.defaultY;
    }
    icon->level = level;
    icon->iconVariant = iconVariant;
    icon->screenChanged = screenChanged;
    icon->screen = screen;
    icon->objWindow = 0;
    icon->lastOam = (GXOamAttr *)HW_OAM;
    GFL_NET_WM_ICON_LoadGraphics(GFL_NET_WM_ICON_GetEngine(icon), icon->iconVariant, (u16)heapId);
    return icon;
}

static inline void G2_SetOBJAttr(GXOamAttr *oam, int x, int y, int priority,
                                 int mode, BOOL mosaic, int effect, int shape,
                                 int color, int charName, int cParam, int rsParam)
{
    oam->attr01 = (u32)(((y & 0xff) << 0) |
                        (mode << 10) |
                        (mosaic << 12) |
                        effect |
                        (color << 13) |
                        shape |
                        ((x & 0x1ff) << 16) |
                        (rsParam << 25));
    oam->attr2 = (u16)((charName << 0) | (priority << 10) | (cParam << 12));
}

/*
 * Writes the icon's two 16x16 OAM entries (the first one an OBJ window
 * when objWindow is set) into the OAM of its engine, and hides the pair
 * in the OAM of the last draw when the engine changed.
 */
void GFL_NET_WM_ICON_Draw(WmIcon *icon)
{
    u32 engine;
    u32 name;
    GXOamAttr *oam;

    engine = GFL_NET_WM_ICON_GetEngine(icon);
    name = GFL_NET_WM_ICON_GetCharName(engine, icon->level);
    if (engine == 1) {
        oam = (GXOamAttr *)HW_OAM;
    } else {
        oam = (GXOamAttr *)HW_DB_OAM;
    }
    if (icon->objWindow == 1) {
        G2_SetOBJAttr(&oam[0], icon->x, icon->y, 0, 2, 0, 0, 0x40000000, 0, name, 14, 0);
    } else {
        G2_SetOBJAttr(&oam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
    }
    G2_SetOBJAttr(&oam[1], icon->x, icon->y, 0, 0, 0, 0, 0x40000000, 0, name, 14, 0);
    if (oam != icon->lastOam) {
        G2_SetOBJAttr(&icon->lastOam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        G2_SetOBJAttr(&icon->lastOam[1], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        icon->lastOam = oam;
    }
}

/* Engine of the icon's screen (1 main, 2 sub), from the LCD swap bit. */
u32 GFL_NET_WM_ICON_GetEngine(const WmIcon *icon)
{
    switch (icon->screen) {
    case 1:
        return ((*(u16 *)REG_POWCNT & 0x8000) >> 15) == 1 ? 1 : 2;
    case 2:
        return ((*(u16 *)REG_POWCNT & 0x8000) >> 15) == 1 ? 2 : 1;
    }
    return 1;
}

/* OBJ character name of charNo under the engine's OBJ mapping mode. */
u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 charNo)
{
    int mapping;

    if (engine == 1) {
        GX_GetBankForOBJ();
        mapping = *(vu32 *)REG_DISPCNT & 0x00300010;
    } else {
        GX_GetBankForSubOBJ();
        mapping = *(vu32 *)REG_DB_DISPCNT & 0x00300010;
    }
    switch (mapping) {
    case 0x10:
        return charNo * 4;
    case 0x00100010:
        return charNo * 2;
    case 0x00200010:
        return charNo;
    case 0x00300010:
    default:
        func_02034714(wm_icon_File, 0xfb, wm_icon_AssertObjMapping);
        return charNo;
    }
}

WmIcon *GFL_NET_WM_ICON_SetLevel(WmIcon *icon, int level)
{
    if (level < 4)
        icon->level = level;
    return icon;
}

/* Hides the icon's entries in main OAM (and in sub OAM when the icon may
 * have been drawn there) and frees it. */
void GFL_NET_WM_ICON_Delete(WmIcon *icon)
{
    *(volatile u32 *)(HW_OAM + 0x0) = 0x40000200;
    *(volatile u16 *)(HW_OAM + 0x4) = 0;
    *(volatile u32 *)(HW_OAM + 0x8) = 0x40000200;
    *(volatile u16 *)(HW_OAM + 0xc) = 0;
    if (icon->screenChanged != 0) {
        volatile u32 *oam = (volatile u32 *)HW_DB_OAM;

        oam[0] = 0x40000200;
        ((volatile u16 *)oam)[2] = 0;
        oam[2] = 0x40000200;
        ((volatile u16 *)oam)[6] = 0;
    }
    func_020307B0(icon);
}

void GFL_NET_WM_ICON_SetScreen(WmIcon *icon, u32 isTop, u32 heapId)
{
    icon->screen = (isTop != 0) ? 1 : 2;
    icon->screenChanged = 1;
    GFL_NET_WM_ICON_LoadGraphics(GFL_NET_WM_ICON_GetEngine(icon), icon->iconVariant, heapId);
}

/* OBJ VRAM offset of the icon characters; always 0. */
int GFL_NET_WM_ICON_GetCharOffset(int engine)
{
    if ((u32)engine == 1) {
        GX_GetBankForOBJ();
    } else {
        GX_GetBankForSubOBJ();
    }
    return 0;
}

/* Loads the icon palette and characters for the engine. */
void GFL_NET_WM_ICON_LoadGraphics(int engine, int iconVariant, int heapId)
{
    WmIconArcData ids;
    int objEngine;
    int palType;
    void *arc;
    int charIdx;
    int charOffset;

    arc = func_020490F4(func_0200F168(), (u16)((heapId & 0x7fff) | 0x8000));
    func_0200F16C(&ids);
    if (engine == 1) {
        palType = 1;
        objEngine = 0;
    } else {
        palType = 5;
        objEngine = 1;
    }
    func_02049B68(arc, ids.palette, palType, 0x1c0, 0x20, heapId);
    charIdx = (iconVariant == 0) ? 1 : 0;
    charOffset = GFL_NET_WM_ICON_GetCharOffset(engine);
    func_02049800(arc, ids.charData[charIdx], objEngine, charOffset, 0, 0, heapId);
    func_02049238(arc);
}

/* Hides the first four OAM entries of both engines. */
void GFL_NET_WM_ICON_ClearOam(void)
{
    GX_LoadOAM(wm_icon_HiddenOam, 0, sizeof(wm_icon_HiddenOam));
    GXS_LoadOAM(wm_icon_HiddenOam, 0, sizeof(wm_icon_HiddenOam));
}

/* (Re)creates the easy icon at a position; a new icon takes the default
 * screen and level 3. */
void GFL_NET_WM_ICON_EasyStart(u32 x, u32 y, u32 iconVariant, u32 heapId)
{
    WmIcon *icon;

    GFL_NET_WM_ICON_ClearOam();
    icon = _WmIconEasy.icon;
    if (icon != 0) {
        u8  screen;
        u32 level;
        u8  screenChanged;

        screenChanged = icon->screenChanged;
        screen = icon->screen;
        level = icon->level;
        GFL_NET_WM_ICON_EasyEnd();
        _WmIconEasy.icon = GFL_NET_WM_ICON_Create(0, heapId, x, y, iconVariant,
                                         _WmIconEasy.icon,
                                         screen, screenChanged, level);
    } else {
        _WmIconEasy.icon = GFL_NET_WM_ICON_Create(0, heapId, x, y, iconVariant,
                                         icon, _WmIconEasy.screen, 0, 3);
    }
}

void GFL_NET_WM_ICON_EasyEnd(void)
{
    GFL_NET_WM_ICON_ClearOam();
    if (_WmIconEasy.icon == 0)
        return;
    GFL_NET_WM_ICON_Delete(_WmIconEasy.icon);
    _WmIconEasy.icon = 0;
}

u32 GFL_NET_WM_ICON_EasySetLevel(u32 level)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon == 0)
        return (u32)icon;
    return (u32)GFL_NET_WM_ICON_SetLevel(icon, level);
}

void GFL_NET_WM_ICON_EasySetScreen(u32 isTop, u32 heapId)
{
    GFL_NET_WM_ICON_SetDefaultScreen(isTop != 0 ? 1 : 2);
    if (_WmIconEasy.icon != 0)
        GFL_NET_WM_ICON_SetScreen(_WmIconEasy.icon, isTop, heapId);
}

void GFL_NET_WM_ICON_EasyMain(void)
{
    if (_WmIconEasy.icon == 0)
        return;
    GFL_NET_WM_ICON_Draw(_WmIconEasy.icon);
}

void func_02037174(void)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon != 0)
        icon->objWindow = 1;
}

void func_02037190(void)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon != 0)
        icon->objWindow = 0;
}

void func_020371AC(u16 x, u16 y)
{
    _WmIconEasy.defaultX = x;
    _WmIconEasy.defaultY = y;
}

void GFL_NET_WM_ICON_SetDefaultScreen(u32 screen)
{
    _WmIconEasy.screen = (u16)screen;
}

u32 GFL_NET_WM_ICON_EasyGetEngine(void)
{
    if (_WmIconEasy.icon == 0) {
        return 1;
    }
    return GFL_NET_WM_ICON_GetEngine(_WmIconEasy.icon);
}
