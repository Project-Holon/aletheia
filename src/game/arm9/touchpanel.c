/*
 * file:     touchpanel.c
 * unit:     yes
 * function: func_02035750, func_02035760, func_02035780, func_020357A0, func_020357C0, func_020357E0, func_020358A0, func_02035A60, func_02035A70, func_02035AA4, func_02035ADC, func_02035B58, func_02035BA4, func_02035BBC, func_02035C08, func_02035C20, func_02035C38, func_02035C48, func_02035C60, func_02035C70, func_02035CB8, func_02035CD8, func_02035D20, func_02035D40, func_02035D5C, func_02035D98, func_02035DC8, func_02035DD8, func_02035E08, func_02035E18, func_02035E54, func_02035E84, func_02035EB0, func_02035ECC, func_02035EE8, func_02035F38, func_020360A8, func_020360B8, func_02036254, func_02036270, func_02036290, func_020362A4, func_020362BC, func_020362DC, func_020362EC, func_0203630C, func_0203631C, func_0203633C, func_0203634C, func_02036370, func_02036390, func_020363B8, func_020363D4, func_020363F0, func_0203640C, func_02036428, func_020364D4, func_02036500, func_02036540, func_02036568, func_020365E8, func_0203660C, func_02036624, func_02036640, func_0203666C, func_02036670, func_020366A8, func_020366C0, func_020366FC, func_02036738, func_0203675C, func_020367C4, func_020368C0, func_020369C8, func_020369F8, func_02036A50, func_02036AF4, func_02036B4C, func_02036B88, func_02036B98, func_02036BD4, func_02036CA8, func_02036D64, func_02036DC8, func_02036E74, func_02036E80, func_02036EC8, func_02036F04, func_02036F24, func_02036FD8, func_02037010, func_020370C8, func_020370F4, func_02037118, func_02037154, func_02037174, func_02037190, func_020371AC, func_020371D8, func_02037200
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
 *   func_02039548                    0x02039548  arm
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

/* net_ring_buff.c ring buffer */
typedef struct {
    u8   *buf;
    int   size;
    u32   state;                 /* nothing in this file reads it */
    short readPos;               /* 0x0C */
    volatile short writePos;     /* 0x0E */
} NetRingBuff;

/* net_queue.c: one queued send (0x14 bytes) */
typedef struct NetQueueNode {
    const u8 *data;              /* 0 when the data went to the ring */
    struct NetQueueNode *prev;
    struct NetQueueNode *next;
    u16 size;                    /* 0x0C: bytes still to send */
    u16 command;                 /* 0x0E: 0 = free node */
    u8  sendID;                  /* 0x10 */
    u8  headerSent;              /* 0x11 */
} NetQueueNode;

typedef struct {
    NetQueueNode *head;
    NetQueueNode *tail;
} NetQueueList;

/* net_queue.c send queue, 0x28 bytes */
typedef struct {
    NetQueueList  fast;          /* 0x00 */
    NetQueueList  slow;          /* 0x08 */
    NetQueueNode *current;       /* 0x10: node cut by a full send buffer */
    NetRingBuff  *ring;          /* 0x14 */
    NetQueueNode *nodes;         /* 0x18 */
    s32           nodeMax;       /* 0x1C */
    u32           pad20[2];      /* nothing reads it */
} NetQueue;

/* net_queue.c: write window into a send buffer */
typedef struct {
    u8  *ptr;
    u16  size;                   /* 0xffff: buffer full */
} NetSendBuf;

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
extern void func_02039548(void);
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
TouchPanelWork *func_02035750(void);
u16 func_02035760(UiCtx *ui);
u16 func_02035780(UiCtx *ui);
int func_020357A0(UiCtx *ui);
u16 func_020357C0(UiCtx *ui);
TouchPanelWork *sub_020357E0(u32 heapId);
void func_020358A0(UiCtx *ui);
void func_02035A60(void);
u32 func_02035A70(const TouchHitTable *hit, s32 x, s32 y);
u32 func_02035AA4(const TouchHitTable *hit, u32 x, u32 y);
int func_02035ADC(const TouchHitTable *tbl, u32 x, u32 y);
int func_02035B58(UiCtx *ui, const TouchHitTable *tbl);
int func_02035BA4(const TouchHitTable *tbl);
int func_02035BBC(UiCtx *ui, const TouchHitTable *tbl);
int func_02035C08(const TouchHitTable *tbl);
int func_02035C20(UiCtx *ui);
int sub_02035C38(void);
u16 func_02035C48(UiCtx *ui);
int sub_02035C60(void);
u32 sub_02035C70(UiCtx *ui, u32 *x, u32 *y);
u32 sub_02035CB8(u32 *x, u32 *y);
u32 sub_02035CD8(UiCtx *ui, u32 *x, u32 *y);
u32 sub_02035D20(u32 *x, u32 *y);
u32 sub_02035D40(const TouchHitTable *tbl, u32 x, u32 y);
u32 sub_02035D5C(TouchPanelWork *tp);
void sub_02035D98(UiCtx *ui);
void sub_02035DC8(void);
void sub_02035DD8(UiCtx *ui);
void sub_02035E08(void);
u32 sub_02035E18(TouchPanelWork *tp);
void sub_02035E54(UiCtx *ui);
void func_02035E84(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30);
void func_02035EB0(UiCtx *ui, int trg, int trg30);
void func_02035ECC(UiCtx *ui, int cont, int cont30);
/* key.c */
KeyWork *func_02035EE8(u32 heapId);
void func_02035F38(UiCtx *ui);
void sub_020360A8(void);
void func_020360B8(KeyWork *key);
void func_02036254(UiCtx *ui, int speed, int wait);
void func_02036270(int speed, int wait);
void func_02036290(UiCtx *ui, const KeyConvEntry *table);
void func_020362A4(const KeyConvEntry *table);
u32 sub_020362BC(UiCtx *ui);
u32 sub_020362DC(void);
u32 sub_020362EC(UiCtx *ui);
u32 sub_0203630C(void);
u32 sub_0203631C(UiCtx *ui);
u32 sub_0203633C(void);
void sub_0203634C(UiCtx *ui, u32 *speed, u32 *wait);
void sub_02036370(u32 *speed, u32 *wait);
void sub_02036390(UiCtx *ui);
void func_020363B8(UiCtx *ui, int trg, int trg30);
void func_020363D4(UiCtx *ui, int cont, int cont30);
void func_020363F0(UiCtx *ui, int repeat, int repeat30);
/* net_ring_buff.c */
void func_0203640C(NetRingBuff *ring, u8 *buf, int size);
void func_02036428(NetRingBuff *ring, const u8 *pDataArea, int size);
int func_020364D4(NetRingBuff *ring, u8 *dst, u32 size, u32 max);
u32 func_02036500(NetRingBuff *ring);
u32 func_02036540(NetRingBuff *ring);
int func_02036568(const NetRingBuff *ring, u8 *dst, int size, int max);
int func_020365E8(NetRingBuff *ring);
int func_0203660C(NetRingBuff *ring);
int func_02036624(const NetRingBuff *ring, int pos);
int func_02036640(NetRingBuff *ring);
void func_0203666C(NetRingBuff *ring);
/* net_queue.c */
NetQueueNode *func_02036670(NetQueue *queue);
int func_020366A8(NetQueue *queue);
int func_020366C0(NetQueue *queue);
u32 func_020366FC(NetQueueList *list);
void func_02036738(NetSendBuf *out, int byte);
int func_0203675C(NetQueueNode *node, NetSendBuf *out);
int func_020367C4(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader);
int func_020368C0(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID);
NetQueueNode *func_020369C8(NetQueue *queue);
void func_020369F8(NetQueue *queue);
int func_02036A50(NetQueue *queue, NetSendBuf *out);
void func_02036AF4(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId);
void func_02036B4C(NetQueue *queue);
void func_02036B88(NetQueue *queue);
int func_02036B98(NetQueue *queue, int command);
/* wm_icon.c */
WmIcon *func_02036BD4(u32 unused, u32 heapId, u32 x, u32 y, u32 iconVariant, WmIcon *icon, u32 screen, u32 screenChanged, u32 level);
void func_02036CA8(WmIcon *icon);
u32 func_02036D64(const WmIcon *icon);
u32 func_02036DC8(u32 engine, u32 charNo);
WmIcon *func_02036E74(WmIcon *icon, int level);
void func_02036E80(WmIcon *icon);
void func_02036EC8(WmIcon *icon, u32 isTop, u32 heapId);
int func_02036F04(int engine);
void func_02036F24(int engine, int iconVariant, int heapId);
void func_02036FD8(void);
void func_02037010(u32 x, u32 y, u32 iconVariant, u32 heapId);
void func_020370C8(void);
u32 func_020370F4(u32 level);
void func_02037118(u32 isTop, u32 heapId);
void func_02037154(void);
void func_02037174(void);
void func_02037190(void);
void func_020371AC(u16 x, u16 y);
void func_020371D8(u32 screen);
u32 func_02037200(void);

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

TouchPanelWork *func_02035750(void)
{
    return _pTouchPanelWork;
}

/*
 * Point and button accessors: with the UI at 30 fps the values collected
 * over the frame pair are reported, otherwise the ones of this frame.
 * The work comes from func_02035750 and the frame rate from the argument,
 * which is why the argument is kept in r4 across the call.
 */
u16 func_02035760(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = func_02035750();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->x30;
    return tp->x;
}

u16 func_02035780(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = func_02035750();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->y30;
    return tp->y;
}

int func_020357A0(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = func_02035750();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->cont30;
    return tp->cont;
}

u16 func_020357C0(UiCtx *ui)
{
    TouchPanelWork *tp;

    tp = func_02035750();
    if (ui->frameRate == UI_FRAMERATE_30)
        return tp->trg30;
    return tp->trg;
}

/*
 * Allocates and clears the work, brings the touch panel up with the user
 * calibration (or a default one when none is stored).
 */
TouchPanelWork *sub_020357E0(u32 heapId)
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
void func_020358A0(UiCtx *ui)
{
    TPData raw;
    TPData cal;
    TouchPanelWork *tp;
    u32 done = 0;
    u32 n;
    TouchPanelWork *tpTmp = func_02035750();

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

void func_02035A60(void)
{
    func_020358A0(sub_02035224());
}

/* Inside a circle entry: strictly closer than the radius. */
u32 func_02035A70(const TouchHitTable *hit, s32 x, s32 y)
{
    s32 dx = hit->circle.x - x;
    s32 dy = hit->circle.y - y;
    u32 r = hit->circle.r;

    return (u32)(dx * dx + dy * dy) < r * r;
}

/* Inside a rectangle entry (unsigned range tests). */
u32 func_02035AA4(const TouchHitTable *hit, u32 x, u32 y)
{
    if (x - hit->rect.left <= (u32)(hit->rect.right - hit->rect.left)
        && y - hit->rect.top <= (u32)(hit->rect.bottom - hit->rect.top))
        return 1;
    return 0;
}

/* Index of the first table entry the point falls inside, or -1. */
int func_02035ADC(const TouchHitTable *tbl, u32 x, u32 y)
{
    int i = 0;

    while (tbl[i].circle.code != TOUCHPANEL_HIT_END) {
        if (tbl[i].circle.code != TOUCHPANEL_HIT_SKIP) {
            if (tbl[i].circle.code == TOUCHPANEL_HIT_CIRCLE) {
                if (func_02035A70(&tbl[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (func_02035AA4(&tbl[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}

int func_02035B58(UiCtx *ui, const TouchHitTable *tbl)
{
    u32 x;
    u32 y;

    func_02035750();
    if (func_020357A0(ui) == 0) {
        return -1;
    }
    x = func_02035760(ui);
    y = func_02035780(ui);
    return func_02035ADC(tbl, x, y);
}

int func_02035BA4(const TouchHitTable *tbl)
{
    return func_02035B58(sub_02035224(), tbl);
}

int func_02035BBC(UiCtx *ui, const TouchHitTable *tbl)
{
    u32 x;
    u32 y;

    func_02035750();
    if (func_020357C0(ui) == 0) {
        return -1;
    }
    x = func_02035760(ui);
    y = func_02035780(ui);
    return func_02035ADC(tbl, x, y);
}

int func_02035C08(const TouchHitTable *tbl)
{
    return func_02035BBC(sub_02035224(), tbl);
}

int func_02035C20(UiCtx *ui)
{
    func_02035750();
    return func_020357A0(ui);
}

int sub_02035C38(void)
{
    return func_02035C20(sub_02035224());
}

u16 func_02035C48(UiCtx *ui)
{
    func_02035750();
    return func_020357C0(ui);
}

int sub_02035C60(void)
{
    return func_02035C48(sub_02035224());
}

u32 sub_02035C70(UiCtx *ui, u32 *x, u32 *y)
{
    func_02035750();
    if (func_020357A0(ui) == 0) {
        return 0;
    }
    *x = func_02035760(ui);
    *y = func_02035780(ui);
    return 1;
}

u32 sub_02035CB8(u32 *x, u32 *y)
{
    return sub_02035C70(sub_02035224(), x, y);
}

u32 sub_02035CD8(UiCtx *ui, u32 *x, u32 *y)
{
    func_02035750();
    if (func_020357C0(ui) == 0) {
        return 0;
    }
    *x = func_02035760(ui);
    *y = func_02035780(ui);
    return 1;
}

u32 sub_02035D20(u32 *x, u32 *y)
{
    return sub_02035CD8(sub_02035224(), x, y);
}

u32 sub_02035D40(const TouchHitTable *tbl, u32 x, u32 y)
{
    return (u32)func_02035ADC(tbl, (u16)x, (u16)y);
}

/* Stops auto sampling when it is used; 2 on a TP error, else 1. */
u32 sub_02035D5C(TouchPanelWork *tp)
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

void sub_02035D98(UiCtx *ui)
{
    TouchPanelWork *tp = func_02035750();

    if (tp != 0 && tp->autoSampleStopped != 0 && tp->autoSampleMode != 0) {
        sub_02035E18(tp);
        tp->autoSampleStopped = 0;
    }
}

void sub_02035DC8(void)
{
    sub_02035D98(sub_02035224());
}

void sub_02035DD8(UiCtx *ui)
{
    TouchPanelWork *tp = func_02035750();

    if (tp != 0 && tp->autoSampleStopped != 1 && tp->autoSampleMode != 0) {
        sub_02035D5C(tp);
        tp->autoSampleStopped = 1;
    }
}

void sub_02035E08(void)
{
    sub_02035DD8(sub_02035224());
}

/* Starts auto sampling into the work buffer; 1 when it started, else 2. */
u32 sub_02035E18(TouchPanelWork *tp)
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

void sub_02035E54(UiCtx *ui)
{
    TouchPanelWork *tp = func_02035750();

    tp->x30 = 0;
    tp->y30 = 0;
    tp->trg30 = 0;
    tp->cont30 = 0;
    tp->pendX = 0;
    tp->pendY = 0;
    tp->pendTrg = 0;
    tp->pendCont = 0;
}

void func_02035E84(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30)
{
    TouchPanelWork *tp;

    tp = func_02035750();
    tp->x30 = x30;
    tp->y30 = y30;
    tp->x = x;
    tp->y = y;
}

void func_02035EB0(UiCtx *ui, int trg, int trg30)
{
    TouchPanelWork *tp = func_02035750();

    tp->trg30 = (u16)trg30;
    tp->trg = (u16)trg;
}

void func_02035ECC(UiCtx *ui, int cont, int cont30)
{
    TouchPanelWork *tp = func_02035750();

    tp->cont30 = (u16)cont30;
    tp->cont = (u16)cont;
}

/* ==================================================================
 * key.c
 * ================================================================== */

/* Allocates and clears the work; key repeat starts after 15 frames, then
 * every 8 frames. */
KeyWork *func_02035EE8(u32 heapId)
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
void func_02035F38(UiCtx *ui)
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
    func_020360B8(key);
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

void sub_020360A8(void)
{
    func_02035F38(sub_02035224());
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
void func_020360B8(KeyWork *key)
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

void func_02036254(UiCtx *ui, int speed, int wait)
{
    KeyWork *key = sub_0203521C(ui);

    key->repeatSpeed = speed;
    key->repeatWait = wait;
}

void func_02036270(int speed, int wait)
{
    func_02036254(sub_02035224(), speed, wait);
}

void func_02036290(UiCtx *ui, const KeyConvEntry *table)
{
    KeyWork *key = sub_0203521C(ui);

    key->controlModeTable = table;
}

void func_020362A4(const KeyConvEntry *table)
{
    func_02036290(sub_02035224(), table);
}

u32 sub_020362BC(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->trg30;
    }
    return key->trg;
}

u32 sub_020362DC(void)
{
    return sub_020362BC(sub_02035224());
}

u32 sub_020362EC(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->cont30;
    }
    return key->cont;
}

u32 sub_0203630C(void)
{
    return sub_020362EC(sub_02035224());
}

u32 sub_0203631C(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    if (ui->frameRate == UI_FRAMERATE_30) {
        return key->repeat30;
    }
    return key->repeat;
}

u32 sub_0203633C(void)
{
    return sub_0203631C(sub_02035224());
}

void sub_0203634C(UiCtx *ui, u32 *speed, u32 *wait)
{
    KeyWork *key = sub_0203521C(ui);

    *speed = key->repeatSpeed;
    *wait = key->repeatWait;
}

void sub_02036370(u32 *speed, u32 *wait)
{
    sub_0203634C(sub_02035224(), speed, wait);
}

void sub_02036390(UiCtx *ui)
{
    KeyWork *key = sub_0203521C(ui);

    key->cont30 = 0;
    key->trg30 = 0;
    key->repeat30 = 0;
    key->pendCont = 0;
    key->pendTrg = 0;
    key->pendRepeat = 0;
}

void func_020363B8(UiCtx *ui, int trg, int trg30)
{
    KeyWork *key = sub_0203521C(ui);

    key->trg30 = trg30;
    key->trg = trg;
}

void func_020363D4(UiCtx *ui, int cont, int cont30)
{
    KeyWork *key = sub_0203521C(ui);

    key->cont30 = cont30;
    key->cont = cont;
}

void func_020363F0(UiCtx *ui, int repeat, int repeat30)
{
    KeyWork *key = sub_0203521C(ui);

    key->repeat30 = repeat30;
    key->repeat = repeat;
}

/* ==================================================================
 * net_ring_buff.c
 * ================================================================== */

void func_0203640C(NetRingBuff *ring, u8 *buf, int size)
{
    ring->buf = buf;
    ring->size = (short)size;   /* the store sign-extends from 16 bits */
    ring->readPos = 0;
    ring->writePos = 0;
}

/* Copies size bytes in at the write position; a full ring is a net error. */
void func_02036428(NetRingBuff *ring, const u8 *pDataArea, int size)
{
    int i;
    int k;

    if (func_02036640(ring) <= size) {
        func_02039548();
        return;
    }
    k = 0;
    for (i = ring->writePos; i < ring->writePos + size; i++) {
        if (pDataArea == 0) {
            func_02034714(net_ring_buff_File, 0x44, net_ring_buff_AssertDataArea);
        }
        ring->buf[func_02036624(ring, i)] = pDataArea[k];
        k++;
    }
    ring->writePos = (short)func_02036624(ring, i);
}

/* Reads up to max bytes and moves the read position past them. */
int func_020364D4(NetRingBuff *ring, u8 *dst, u32 size, u32 max)
{
    int got = func_02036568(ring, dst, size, max);

    ring->readPos = (short)func_02036624(ring, ring->readPos + got);
    return got;
}

u32 func_02036500(NetRingBuff *ring)
{
    u8 byte;

    if (func_020364D4(ring, &byte, 1, 1) == 1)
        return byte;
    func_02034714(net_ring_buff_File, 0x6C, net_ring_buff_AssertZero);
    return 0;
}

/* Big-endian halfword: the high byte comes first. */
u32 func_02036540(NetRingBuff *ring)
{
    u16 hi;
    u32 lo;

    hi = (u16)(func_02036500(ring) << 8);
    lo = func_02036500(ring);
    return (u16)(hi | lo);
}

/* Copies up to max bytes from the read position without consuming them. */
int func_02036568(const NetRingBuff *ring, u8 *dst, int size, int max)
{
    int i;
    int n;

    n = 0;
    for (i = ring->readPos; i < ring->readPos + size; i++) {
        if (ring->writePos == func_02036624(ring, i) || n == max) {
            return n;
        }
        dst[n] = ring->buf[func_02036624(ring, i)];
        n++;
    }
    return n;
}

/* Bytes waiting to be read. */
int func_020365E8(NetRingBuff *ring)
{
    int readPos = ring->readPos;

    if (readPos > ring->writePos)
        return ring->size + ring->writePos - readPos;
    return ring->writePos - readPos;
}

int func_0203660C(NetRingBuff *ring)
{
    int used = func_020365E8(ring);

    return ring->size - used;
}

int func_02036624(const NetRingBuff *ring, int pos)
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
int func_02036640(NetRingBuff *ring)
{
    return ring->size - GFL_NET_RING_BUFF_DataSize(ring);
}

/* Write commit hook; it does nothing in this version. */
void func_0203666C(NetRingBuff *ring)
{
}

/* ==================================================================
 * net_queue.c
 * ================================================================== */

/* First node with no command, or 0 when all are in use. */
NetQueueNode *func_02036670(NetQueue *queue)
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

int func_020366A8(NetQueue *queue)
{
    return func_020366C0(queue) == 0;
}

/* Nodes in use. */
int func_020366C0(NetQueue *queue)
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
u32 func_020366FC(NetQueueList *list)
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

void func_02036738(NetSendBuf *out, int byte)
{
    *out->ptr = (u8)byte;
    out->ptr = out->ptr + 1;
    out->size = out->size - 1;
}

/* Five-byte header: command and size (high byte first), then sendID. */
int func_0203675C(NetQueueNode *node, NetSendBuf *out)
{
    func_02036738(out, (node->command >> 8) & 0xff);
    func_02036738(out, node->command & 0xff);
    func_02036738(out, (node->size >> 8) & 0xff);
    func_02036738(out, node->size & 0xff);
    func_02036738(out, node->sendID);
    return 0;
}

/*
 * Moves one node into the send buffer: the header first (refused with 0
 * when needHeader is set and header and data do not fit), then as much
 * data as fits.  When the data does not fit, the buffer is marked full
 * (0xffff) and the node keeps the rest.
 */
int func_020367C4(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader)
{
    if (node->headerSent == 0) {
        if (needHeader != 0 && out->size < node->size + 5) {
            return 0;
        }
        func_0203675C(node, out);
    }
    if (out->size < node->size) {
        if (node->data == 0) {
            func_020364D4(ring, out->ptr, out->size, out->size);
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
        func_020364D4(ring, out->ptr, node->size, node->size);
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
int func_020368C0(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID)
{
    NetQueueNode *node = func_02036670(queue);

    if (node == 0) {
        func_02034714(net_queue_File, 0xdb, net_queue_AssertZero);
        return 0;
    }
    if (!((u16)size < 0xffff / 2)) {
        func_02034714(net_queue_File, 0xdf, net_queue_AssertSize);
    }
    if (copyToRing != 0) {
        if (!((int)(size + 5) < (int)func_0203660C(queue->ring))) {
            func_02034714(net_queue_File, 0xe3, net_queue_AssertZero);
            return 0;
        }
        func_02036428(queue->ring, pDataArea, size);
        func_0203666C(queue->ring);
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
NetQueueNode *func_020369C8(NetQueue *queue)
{
    if (queue->current != 0)
        return queue->current;
    if (queue->fast.head != 0)
        return queue->fast.head;
    if (queue->slow.head != 0)
        return queue->slow.head;
    return 0;
}

/* Removes the node func_020369C8 picked. */
void func_020369F8(NetQueue *queue)
{
    if (queue->current != 0) {
        queue->current = 0;
        return;
    }
    if (func_020366FC(&queue->fast) != 0) {
        return;
    }
    if (func_020366FC(&queue->slow) != 0) {
        return;
    }
    func_02034714(net_queue_File, 0x12f, net_queue_AssertRet);
}

/*
 * Fills the send buffer from the queue.  Returns 0 only when the buffer
 * filled up in the middle of a node after at least one node went in.
 */
int func_02036A50(NetQueue *queue, NetSendBuf *out)
{
    int needHeader = 0;

    if (out->size == 0)
        goto done;
    while (1) {
        NetQueueNode *node = func_020369C8(queue);

        if (node == 0)
            goto done;
        func_020369F8(queue);
        if (func_020367C4(node, out, queue->ring, needHeader) == 0) {
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

void func_02036AF4(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId)
{
    MI_CpuFill8(queue, 0, sizeof(NetQueue));
    queue->nodes = func_02030734(heapId, nodeMax * sizeof(NetQueueNode), 1, net_queue_File, 0x173);
    queue->nodeMax = nodeMax;
    queue->ring = ring;
}

void func_02036B4C(NetQueue *queue)
{
    MI_CpuFill8(queue->nodes, 0, queue->nodeMax * sizeof(NetQueueNode));
    queue->fast.head = 0;
    queue->fast.tail = 0;
    queue->slow.head = 0;
    queue->slow.tail = 0;
    queue->current = 0;
}

void func_02036B88(NetQueue *queue)
{
    func_020307B0(queue->nodes);
}

/* Is a node with this command queued? */
int func_02036B98(NetQueue *queue, int command)
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
WmIcon *func_02036BD4(u32 unused, u32 heapId, u32 x, u32 y, u32 iconVariant,
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
    func_02036F24(func_02036D64(icon), icon->iconVariant, (u16)heapId);
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
void func_02036CA8(WmIcon *icon)
{
    u32 engine;
    u32 name;
    GXOamAttr *oam;

    engine = func_02036D64(icon);
    name = func_02036DC8(engine, icon->level);
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
u32 func_02036D64(const WmIcon *icon)
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
u32 func_02036DC8(u32 engine, u32 charNo)
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

WmIcon *func_02036E74(WmIcon *icon, int level)
{
    if (level < 4)
        icon->level = level;
    return icon;
}

/* Hides the icon's entries in main OAM (and in sub OAM when the icon may
 * have been drawn there) and frees it. */
void func_02036E80(WmIcon *icon)
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

void func_02036EC8(WmIcon *icon, u32 isTop, u32 heapId)
{
    icon->screen = (isTop != 0) ? 1 : 2;
    icon->screenChanged = 1;
    func_02036F24(func_02036D64(icon), icon->iconVariant, heapId);
}

/* OBJ VRAM offset of the icon characters; always 0. */
int func_02036F04(int engine)
{
    if ((u32)engine == 1) {
        GX_GetBankForOBJ();
    } else {
        GX_GetBankForSubOBJ();
    }
    return 0;
}

/* Loads the icon palette and characters for the engine. */
void func_02036F24(int engine, int iconVariant, int heapId)
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
    charOffset = func_02036F04(engine);
    func_02049800(arc, ids.charData[charIdx], objEngine, charOffset, 0, 0, heapId);
    func_02049238(arc);
}

/* Hides the first four OAM entries of both engines. */
void func_02036FD8(void)
{
    GX_LoadOAM(wm_icon_HiddenOam, 0, sizeof(wm_icon_HiddenOam));
    GXS_LoadOAM(wm_icon_HiddenOam, 0, sizeof(wm_icon_HiddenOam));
}

/* (Re)creates the easy icon at a position; a new icon takes the default
 * screen and level 3. */
void func_02037010(u32 x, u32 y, u32 iconVariant, u32 heapId)
{
    WmIcon *icon;

    func_02036FD8();
    icon = _WmIconEasy.icon;
    if (icon != 0) {
        u8  screen;
        u32 level;
        u8  screenChanged;

        screenChanged = icon->screenChanged;
        screen = icon->screen;
        level = icon->level;
        func_020370C8();
        _WmIconEasy.icon = func_02036BD4(0, heapId, x, y, iconVariant,
                                         _WmIconEasy.icon,
                                         screen, screenChanged, level);
    } else {
        _WmIconEasy.icon = func_02036BD4(0, heapId, x, y, iconVariant,
                                         icon, _WmIconEasy.screen, 0, 3);
    }
}

void func_020370C8(void)
{
    func_02036FD8();
    if (_WmIconEasy.icon == 0)
        return;
    func_02036E80(_WmIconEasy.icon);
    _WmIconEasy.icon = 0;
}

u32 func_020370F4(u32 level)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon == 0)
        return (u32)icon;
    return (u32)func_02036E74(icon, level);
}

void func_02037118(u32 isTop, u32 heapId)
{
    func_020371D8(isTop != 0 ? 1 : 2);
    if (_WmIconEasy.icon != 0)
        func_02036EC8(_WmIconEasy.icon, isTop, heapId);
}

void func_02037154(void)
{
    if (_WmIconEasy.icon == 0)
        return;
    func_02036CA8(_WmIconEasy.icon);
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

void func_020371D8(u32 screen)
{
    _WmIconEasy.screen = (u16)screen;
}

u32 func_02037200(void)
{
    if (_WmIconEasy.icon == 0) {
        return 1;
    }
    return func_02036D64(_WmIconEasy.icon);
}
