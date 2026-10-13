/*
 * file:     btlv_scu.c
 * unit:     yes
 * function: func_021EAF00, func_021EAF18, func_021EAF50, func_021EAF78, BTLV_SCU_Create, BTLV_SCU_SetupDisplay, BTLV_SCU_LoadArcTiles, BTLV_SCU_Delete, BTLV_SCU_ReloadGraphics, func_021EB318, BTLV_SCU_StartEntryScene, BTLV_SCU_RunProc, BTLV_SCU_StartBrightnessFade, BTLV_SCU_ProcQuickEntry, BTLV_SCU_ProcQuickEntrySingle, BTLV_SCU_ProcQuickEntryDouble, BTLV_SCU_ProcQuickEntryTriple, BTLV_SCU_ProcEntrySingleWild, BTLV_SCU_GetEntryMessageId, BTLV_SCU_ProcEntrySingleTrainer, BTLV_SCU_ProcEntrySingleLink, BTLV_SCU_ProcEntryDoubleWild, BTLV_SCU_ProcEntryDoubleTrainerLocal, BTLV_SCU_ProcEntryDoubleTrainerComm, BTLV_SCU_ProcEntryDoubleLinkLocal, BTLV_SCU_ProcEntryDoubleLinkComm
 * address:  0x021EAF00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02030734  0x02030734  arm    arm9
 *   d_021F3AD0     0x021F3AD0  data   a4
 *   STRBUF_Create  0x020457B0  arm    arm9
 *   func_0201C440  0x0201C440  thumb  arm9
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0204989C 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_021ED76C 0x021ED76C thumb ov093
 *   func_021ED930 0x021ED930 thumb ov093
 *   func_021EDB3C 0x021EDB3C thumb ov093
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   gBtlvScuBgTemplateMsg 0x021F3930 data a4
 *   gBtlvScuBgTemplateName 0x021F3950 data a4
 *   gBtlvScuBgTemplateBack 0x021F3970 data a4
 *   func_020490F4  0x020490F4  arm
 *   func_02049740  0x02049740  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_021EDBE8  0x021EDBE8  thumb  ov093
 *   func_021ED988  0x021ED988  thumb  ov093
 *   func_020452E8  0x020452E8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049658  0x02049658  arm
 *   func_020414EC  0x020414EC  arm
 *   FADE_IsActive   0x0204E804  arm
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   func_021EBED4 0x021EBED4 thumb ov093
 *   func_021EBF20 0x021EBF20 thumb ov093
 *   func_0207D55C  0x0207D55C  arm    arm9
 *   FADE_Start  0x0204E720  arm    arm9
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   gBtlvScuQuickSidesSingle  0x021F38AC  data  a4
 *   gBtlvScuQuickSidesDouble  0x021F38AE  data  a4
 *   gBtlvScuQuickSidesTriple  0x021F38B2  data  a4
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   BTLV_SCU_GetBallStates 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   gBtlvScuSingleLinkPhases  0x021F38E8  data  a4
 *   BTL_MAIN_GetClientTrainerIndex 0x021B8BEC thumb ov093
 *   BTL_MAIN_GetEnemyLanePosFromWork 0x021B8C50 thumb ov093
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   gBtlvScuDoubleTrainerLocalPhases  0x021F38D0  data  a4
 *   gBtlvScuDoubleTrainerCommPhases  0x021F38DC  data  a4
 *   gBtlvScuDoubleLinkLocalPhases  0x021F3900  data  a4
 *   gBtlvScuDoubleLinkCommPhases  0x021F38B8  data  a4
 */
#include "btlv_scu_types.h"

struct PalAnmSlot;
struct BgTemplate;

/* Master brightness register of the main engine. */
#define REG_MASTER_BRIGHT_MAIN ((volatile u16 *)0x0400006c)

/* Message record built for the view (home file not known, see misplaced). */
struct BtlvMessage {
    u16 msgId;
    u8 param;
    u8 kind : 4;
    u8 argCount : 4;
    u32 args[8];
};

/* First words of the battle view core (btlv_core.c owns the full layout). */
struct BtlvCoreHead {
    u32 reserved0;
    u8 *client;
};

extern u32 BTL_CLIENT_IsMainStepActive(u8 *);
extern void func_020061E4(u32 a);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern struct MsgBuf *STRBUF_Create(int, int);
extern struct PrintSys *func_0201C440(u32 heapId);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern int func_021F86E0(void);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct CharBuf *func_02045770(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern void BMP_WIN_DrawFrame(struct BmpWin *win, u16 base, u32 pal);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void func_021ED76C(BtlvScuWinSlide *slide, struct BmpWin *win);
extern void func_021ED930(BtlvScu *scu);
extern void func_021EDB3C(BtlvScu *scu, u32 tile);
extern void func_020409B4(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_021EDBE8(BtlvScu *scu);
extern void func_021ED988(BtlvScu *scu);
extern u32 func_020452E8(struct BmpWin *win);
extern void func_020403F4(u32 i);
extern void func_0201C4C0(struct PrintSys *printer);
extern void STRBUF_Delete(struct MsgBuf *buf);
extern u32 func_020307B0(void *p);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020414EC(u32 i);
extern int BTL_MAIN_GetCompetitor(struct BtlContext *);
extern u32 BTL_MAIN_GetRule(struct BtlContext *);
extern int BTL_MAIN_IsMultiMode(struct BtlContext *);
extern int func_021EBED4(int *, BtlvScu *);
extern int func_021EBF20(int *, BtlvScu *);
extern int func_0207D55C(volatile u16 *);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern u8 func_021B8ED8(struct BtlContext *, u8 side);
extern struct BtlPokeParam *func_021B98AC(struct BtlMonTable *, u8 monIdx);
extern void *BTL_POKEPARAM_GetDisplayMon(struct BtlPokeParam *mon);
extern void func_021F7EE8(void *sprite, int side);
extern void func_021EDA04(BtlvScuMonSlot *slot);
extern int func_021F7EB4(void);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *mon);
extern void func_021ED798(BtlvScuWinSlide *slide);
extern int func_021ED814(BtlvScuWinSlide *slide);
extern void func_021F7A28(int, u32);
extern void BTL_MSG_FormatArgs(struct MsgBuf *, u32, u32, ...);
extern void func_021ECEB8(BtlvScu *, struct MsgBuf *, u16, u32);
extern int func_021ECF68(BtlvScu *scu);
extern void func_021F7998(u32);
extern int func_021BA1A8(struct BtlContext *, int mask);
extern u8 func_021B8DE4(struct BtlContext *, int i);
extern u16 func_021BA020(struct BtlContext *, int);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void BTLV_SCU_GetBallStates(BtlvScu *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern u8 func_021B8FF4(struct BtlContext *);
extern void func_021F8260(u32);
extern int func_021F827C(u32);
extern u8 BTL_MAIN_GetClientTrainerIndex(struct BtlContext *, u32, u8);
extern u8 BTL_MAIN_GetEnemyLanePosFromWork(struct BtlContext *, u32 v, int k);
extern u8 func_021B8E70(struct BtlContext *, u32);
void func_021EAF00(struct BtlvCoreHead *core, int a);
void func_021EAF18(struct BtlvMessage *msg, int kind, int id);
void func_021EAF50(struct BtlvMessage *msg, u32 val);
/* 021EAF78 strb r1,[r0,#2] */ void func_021EAF78(struct BtlvMessage *msg, u8 param);
BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context, struct BtlMonTable *monTable, void *taskSys, void *fontMain, void *fontSub, u8 clientIndex, int heapId);
void BTLV_SCU_SetupDisplay(BtlvScu *scu);
u16 BTLV_SCU_LoadArcTiles(BtlvScu *scu, u32 arcId, u32 fileId, u32 layer);
void BTLV_SCU_Delete(BtlvScu *scu);
void BTLV_SCU_ReloadGraphics(const BtlvScu *scu);
u32 func_021EB318(void);
void BTLV_SCU_StartEntryScene(BtlvScu *scu, u32 quickMode);
int BTLV_SCU_RunProc(BtlvScu *scu);
void BTLV_SCU_StartBrightnessFade(int speed);
int BTLV_SCU_ProcQuickEntry(BtlvScu *scu, int *state, u8 *sides, u8 count);
int BTLV_SCU_ProcQuickEntrySingle(BtlvScu *scu, int *state);
int BTLV_SCU_ProcQuickEntryDouble(BtlvScu *scu, int *state);
int BTLV_SCU_ProcQuickEntryTriple(BtlvScu *scu, int *state);
int BTLV_SCU_ProcEntrySingleWild(int *state, BtlvScu *scu);
int BTLV_SCU_GetEntryMessageId(BtlvScu *scu);
int BTLV_SCU_ProcEntrySingleTrainer(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntrySingleLink(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleWild(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleTrainerLocal(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleTrainerComm(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleLinkLocal(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleLinkComm(int *state, BtlvScu *scu);
extern u8 d_021F3AD0[];
extern const struct BgTemplate gBtlvScuBgTemplateMsg, gBtlvScuBgTemplateName, gBtlvScuBgTemplateBack;
extern u8 gBtlvScuQuickSidesSingle[];
extern u8 gBtlvScuQuickSidesDouble[];
extern u8 gBtlvScuQuickSidesTriple[];
extern int (*const gBtlvScuSingleLinkPhases[][2])(BtlvScu *, int *);
extern int (*const gBtlvScuDoubleTrainerLocalPhases[])(BtlvScu *, int *);
extern int (*const gBtlvScuDoubleTrainerCommPhases[])(BtlvScu *, int *);
extern int (*const gBtlvScuDoubleLinkLocalPhases[][2])(BtlvScu *, int *);
extern int (*const gBtlvScuDoubleLinkCommPhases[])(BtlvScu *, int *);

void func_021EAF00(struct BtlvCoreHead *core, int a)
{
    if (BTL_CLIENT_IsMainStepActive(core->client) == 0)
        func_020061E4(a);
}

void func_021EAF18(struct BtlvMessage *msg, int kind, int id)
{
    u32 i;
    for (i = 0; i < 8; i++)
        msg->args[i] = 0;
    msg->argCount = 0;
    msg->msgId = id;
    msg->kind = kind;
    msg->param = 0x50;
}

void func_021EAF50(struct BtlvMessage *msg, u32 val)
{
    u32 n = msg->argCount;
    if (n < 8) {
        msg->argCount = n + 1;
        msg->args[n] = val;
    }
}


/* 021EAF78  strb r1,[r0,#2] */
/*
 * Stores the second argument (a u8) into the param field at #2.
 */
void func_021EAF78(struct BtlvMessage *msg, u8 param) { msg->param = param; }


BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context, struct BtlMonTable *monTable, void *taskSys, void *fontMain, void *fontSub, u8 clientIndex, int heapId)
{
    BtlvScu *scu;
    scu = func_02030734(heapId, 0x180, 1, (const char *)d_021F3AD0, 0x151);
    scu->core = core;
    scu->context = context;
    scu->monTable = monTable;
    scu->heapId = heapId;
    scu->clientIndex = clientIndex;
    scu->fontMain = fontMain;
    scu->fontSub = fontSub;
    scu->quickMode = 0;
    scu->taskHandle = 0;
    scu->taskSys = taskSys;
    scu->textBuf = STRBUF_Create(0x400, heapId);
    scu->wordBuf0 = STRBUF_Create(0x180, heapId);
    scu->wordBuf1 = STRBUF_Create(0x180, heapId);
    scu->busyFlag = 0;
    scu->cmdResult = 0;
    scu->printer = func_0201C440(scu->heapId);
    scu->msgWinCopy = scu->msgWin;
    scu->lineIndex = 0;
    return scu;
}


void BTLV_SCU_SetupDisplay(BtlvScu *scu)
{
    u16 zero;
    u32 frameTile;
    func_0203FCA0(1, &gBtlvScuBgTemplateMsg, 0);
    func_0203FCA0(2, &gBtlvScuBgTemplateName, 0);
    func_0203FCA0(3, &gBtlvScuBgTemplateBack, 0);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), 0xb, 0x5a, scu->heapId, 0, 0x20, 0, 0);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), 0xb, 0xd6, scu->heapId, 0, 0x60, 0x10, 0x10);
    zero = 0;
    PALANM_CopyToSlot((struct PalAnmSlot *)func_021F86E0(), &zero, 0, 0, 2);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040C14(1, 0, 1, 0);
    frameTile = BTLV_SCU_LoadArcTiles(scu, 0xb, 0x59, 1);
    scu->msgTile = BTLV_SCU_LoadArcTiles(scu, 0xb, 0xd5, 3);
    func_0204989C(0xb, 0xd7, 2, 0, 0, 0, scu->heapId);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, scu->heapId);
    scu->msgWin = BMP_WIN_Create(1, 1, 0x13, 0x1e, 4, 0, 0);
    scu->msgWinChars = func_02045770(scu->msgWin);
    BMP_WIN_MakeScreen(scu->msgWin);
    BMP_WIN_DrawFrame(scu->msgWin, frameTile, 0);
    BMP_Clear(scu->msgWinChars, 0xc);
    BMP_WIN_TransferChars(scu->msgWin);
    scu->nameTile = BTLV_SCU_LoadArcTiles(scu, 0xb, 0xdd, 3);
    scu->nameWin = BMP_WIN_Create(3, 0x15, 0x25, 0xa, 0xc, 3, 0);
    scu->nameWinChars = func_02045770(scu->nameWin);
    func_021ED76C(&scu->slide, scu->msgWin);
    func_021ED930(scu);
    func_021EDB3C(scu, scu->msgTile);
    func_020409B4(1);
    func_020409B4(2);
    func_020409B4(3);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_020434DC(0x10, 1);
}


u16 BTLV_SCU_LoadArcTiles(BtlvScu *scu, u32 arcId, u32 fileId, u32 layer)
{
    void *handle = func_020490F4(arcId, (u16)((scu->heapId & 0x7fff) | 0x8000));
    u32 tileOffset = func_02049740(handle, fileId, layer, 0, 0, (u16)((scu->heapId & 0x7fff) | 0x8000));

    ARC_TOOL_DeleteHandle(handle);
    return (u16)tileOffset;
}


void BTLV_SCU_Delete(BtlvScu *scu)
{
    func_021EDBE8(scu);
    func_021ED988(scu);
    if (scu->nameWin != 0) {
        func_020452E8(scu->nameWin);
        scu->nameWin = 0;
    }
    if (scu->msgWin != 0) {
        func_020452E8(scu->msgWin);
        scu->msgWin = 0;
    }
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    if (scu->printer != 0) {
        func_0201C4C0(scu->printer);
        scu->printer = 0;
    }
    if (scu->wordBuf1 != 0) {
        STRBUF_Delete(scu->wordBuf1);
        scu->wordBuf1 = 0;
    }
    if (scu->wordBuf0 != 0) {
        STRBUF_Delete(scu->wordBuf0);
        scu->wordBuf0 = 0;
    }
    STRBUF_Delete(scu->textBuf);
    func_020307B0(scu);
}


/*
 * Lever: the parameter is const BtlvScu *; without const the ldrh of the heap
 * halfword schedules after the second zero stack store (DIFF, 19 lines).
 */
void BTLV_SCU_ReloadGraphics(const BtlvScu *scu)
{
    void *handle = func_020490F4(0xb, (u16)((scu->heapId & 0x7fff) | 0x8000));

    func_02049658(handle, 0xd5, 3, scu->msgTile, 0, 0, scu->heapId);
    func_02049658(handle, 0xdd, 3, scu->nameTile, 0, 0, scu->heapId);
    ARC_TOOL_DeleteHandle(handle);
    func_020414EC(3);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, scu->heapId);
}


/*
 * Calls the ARM9 predicate FADE_IsActive and returns its negation.  Filed here because it is the only witness available for BTLV_SCU_GetWaitState's pool word: no branch anywhere in the image targets 0x021EB318, so `label` and `sole-ref/code` both refuse it.  18 bytes against a 20-byte listing extent (the last two are alignment), so the entry is EXACT*.
 */
u32 func_021EB318(void) { if (FADE_IsActive() == 0) return 1; return 0; }

static inline void BTLV_SCU_SetProc(BtlvScu *scu, BtlvScuProc proc)
{
    scu->preProc = 0;
    scu->mainProc = proc;
    scu->procScu = scu;
    scu->procState = 0;
}

void BTLV_SCU_StartEntryScene(BtlvScu *scu, u32 quickMode)
{
    int battleType = BTL_MAIN_GetCompetitor(scu->context);
    scu->phase = 0;
    scu->quickMode = quickMode;
    switch (BTL_MAIN_GetRule(scu->context)) {
    case 0:
        switch (battleType) {
        default: case 0: case 4: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntrySingleWild); return;
        case 1: case 2: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntrySingleTrainer); return;
        case 3: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntrySingleLink); return;
        }
    case 1:
        switch (battleType) {
        case 0: BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleWild); return;
        case 3:
            if (!BTL_MAIN_IsMultiMode(scu->context)) BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleLinkLocal);
            else BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleLinkComm);
            return;
        case 1: case 2:
            if (!BTL_MAIN_IsMultiMode(scu->context)) BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleTrainerLocal);
            else BTLV_SCU_SetProc(scu, BTLV_SCU_ProcEntryDoubleTrainerComm);
            return;
        }
        break;
    case 2:
        if (battleType != 3) BTLV_SCU_SetProc(scu, func_021EBED4);
        else BTLV_SCU_SetProc(scu, func_021EBF20);
        return;
    case 3:
        if (battleType != 3) BTLV_SCU_SetProc(scu, func_021EBED4);
        else BTLV_SCU_SetProc(scu, func_021EBF20);
        return;
    }
}


int BTLV_SCU_RunProc(BtlvScu *scu)
{
    if (scu->preProc != 0) {
        if (scu->preProc(&scu->procState, scu->procScu) != 0) {
            scu->preProc = 0;
            scu->procState = 0;
        }
        return 0;
    }
    if (scu->mainProc != 0) {
        if (scu->mainProc(&scu->procState, scu->procScu) != 0) {
            scu->mainProc = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

void BTLV_SCU_StartBrightnessFade(int speed)
{
    if (func_0207D55C(REG_MASTER_BRIGHT_MAIN) <= 0)
        FADE_Start(3, 0x10, 0, speed);
    else
        FADE_Start(0xc, 0x10, 0, speed);
}

int BTLV_SCU_ProcQuickEntry(BtlvScu *scu, int *state, u8 *sides, u8 count)
{
    switch (*state) {
    case 0: {
        u32 side;
        u32 i;
        u8 monIdx;
        for (i = 0; i < count; i++) {
            side = sides[i];
            monIdx = func_021B8ED8(scu->context, side);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(func_021B98AC(scu->monTable, monIdx)), side);
            func_021EDA04(&scu->monSlots[monIdx]);
        }
        *state = *state + 1;
        break;
    }
    case 1:
        if (scu->quickMode != 0)
            return 1;
        BTLV_SCU_StartBrightnessFade(-3);
        *state = *state + 1;
        break;
    case 2:
        if (func_021F7EB4() == 0)
            return 1;
        break;
    }
    return 0;
}

int BTLV_SCU_ProcQuickEntrySingle(BtlvScu *scu, int *state)
{
    return BTLV_SCU_ProcQuickEntry(scu, state, gBtlvScuQuickSidesSingle, 2);
}

int BTLV_SCU_ProcQuickEntryDouble(BtlvScu *scu, int *state)
{
    return BTLV_SCU_ProcQuickEntry(scu, state, gBtlvScuQuickSidesDouble, 4);
}

int BTLV_SCU_ProcQuickEntryTriple(BtlvScu *scu, int *state)
{
    return BTLV_SCU_ProcQuickEntry(scu, state, gBtlvScuQuickSidesTriple, 6);
}

int BTLV_SCU_ProcEntrySingleWild(int *state, BtlvScu *scu)
{
    BtlvScuIntroState *intro = &scu->intro;
    if (scu->quickMode) return BTLV_SCU_ProcQuickEntrySingle(scu, state);
    switch (*state) {
    case 0:
        intro->single.side = 1;
        intro->single.monIdx = func_021B8ED8(scu->context, intro->single.side);
        intro->single.mon = func_021B98AC(scu->monTable, intro->single.monIdx);
        intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
        func_021ED798(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (func_021ED814(&scu->slide)) {
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            func_021F7A28(intro->single.side, 0x231);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            BTL_MSG_FormatArgs(scu->textBuf, BTLV_SCU_GetEntryMessageId(scu), 1, intro->single.monId);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68(scu)) {
            func_021EDA04(&scu->monSlots[intro->single.monIdx]);
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814(&scu->slide)) {
            if (BTL_MAIN_GetCompetitor(scu->context) == 4) func_021F7998(0x23c);
            else func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 5:
        if (!func_021F7EB4()) {
            intro->single.side = 0;
            intro->single.monIdx = func_021B8ED8(scu->context, intro->single.side);
            intro->single.mon = func_021B98AC(scu->monTable, intro->single.monIdx);
            intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            func_021F7998(0x234);
            BTL_MSG_FormatArgs(scu->textBuf, 11, 1, intro->single.monId);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 6:
        if (func_021ECF68(scu)) {
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 7:
        if (func_021ED814(&scu->slide)) (*state)++;
        break;
    case 8:
        if (!func_021F7EB4()) {
            func_021EDA04(&scu->monSlots[intro->single.monIdx]);
            return 1;
        }
        break;
    }
    return 0;
}


int BTLV_SCU_GetEntryMessageId(BtlvScu *scu)
{
    if (func_021BA1A8(scu->context, 4) != 0) {
        return 6;
    }
    if (func_021BA1A8(scu->context, 8) != 0) {
        return 3;
    }
    if (func_021BA1A8(scu->context, 0x80) != 0) {
        return 4;
    }
    if (func_021BA1A8(scu->context, 0x10) != 0) {
        return 5;
    }
    return 1;
}

int BTLV_SCU_ProcEntrySingleTrainer(int *state, BtlvScu *scu)
{
    BtlvScuIntroState *intro = &scu->intro;
    u32 introArgs[7];
    u32 sendOutArgs[7];
    u32 side, trainerIdx;
    if (scu->quickMode) return BTLV_SCU_ProcQuickEntrySingle(scu, state);
    switch (*state) {
    case 0:
        side = func_021B8ED8(scu->context, 1);
        trainerIdx = func_021B8DE4(scu->context, side);
        func_021F7F58(func_021BA020(scu->context, trainerIdx), 9, 0, 0, 0);
        intro->single.side = 1;
        intro->single.trainerIdx = trainerIdx;
        intro->single.monIdx = side;
        intro->single.mon = func_021B98AC(scu->monTable, intro->single.monIdx);
        intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
        func_021ED798(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (func_021ED814(&scu->slide)) {
            func_021F7A28(intro->single.side, 0x237);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            BTLV_SCU_GetBallStates(scu, introArgs, intro->single.trainerIdx, 4, 1);
            func_021F823C(introArgs);
            BTL_MSG_FormatArgs(scu->textBuf, 7, 1, intro->single.trainerIdx);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68(scu)) {
            func_021F7A28(intro->single.side, 0x238);
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814(&scu->slide) && !func_021F7EB4()) {
            BTL_MSG_FormatArgs(scu->textBuf, 14, 2, 1, intro->single.monId);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ECF68(scu)) {
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            func_021F7A28(intro->single.side, 0x239);
            func_021F8260(1);
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814(&scu->slide) && !func_021F7EB4()) {
            BTLV_SCU_GetBallStates(scu, sendOutArgs, func_021B8FF4(scu->context), 4, 0);
            func_021F823C(sendOutArgs);
            (*state)++;
        }
        break;
    case 7:
        func_021EDA04(&scu->monSlots[intro->single.monIdx]);
        func_021F7998(0x232);
        (*state)++;
        break;
    case 8:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            intro->single.side = 0;
            intro->single.monIdx = func_021B8ED8(scu->context, intro->single.side);
            intro->single.mon = func_021B98AC(scu->monTable, intro->single.monIdx);
            intro->single.monId = BTL_POKEPARAM_GetPokeId(intro->single.mon);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->single.mon), intro->single.side);
            func_021F7998(0x234);
            BTL_MSG_FormatArgs(scu->textBuf, 11, 1, intro->single.monId);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 9:
        if (func_021ECF68(scu)) {
            func_021F8260(0);
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 10:
        if (func_021ED814(&scu->slide)) (*state)++;
        break;
    case 11:
        if (!func_021F7EB4()) {
            func_021EDA04(&scu->monSlots[intro->single.monIdx]);
            return 1;
        }
        break;
    }
    return 0;
}



int BTLV_SCU_ProcEntrySingleLink(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntrySingle(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuSingleLinkPhases[scu->phase][func_021B8FF4(scu->context)](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}

/*
 * match-note: The loop stores and reads each call result through the same
 * pointer-typed lvalue. Integer-store/pointer-reload gave 628 bytes; a named
 * integer temporary gave 620 and lost the index spill; pointer lvalues gave
 * EXACT 624 bytes. Evidence: B10/BB20-r1.log through BB20-r3.log.
 */
int BTLV_SCU_ProcEntryDoubleWild(int *state, BtlvScu *scu)
{
    BtlvScuIntroState *intro = &scu->intro;
    u32 side;
    unsigned i;
    if (scu->quickMode) return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    switch (*state) {
    case 0:
        side = BTL_MAIN_GetClientTrainerIndex(scu->context, scu->clientIndex, 0);
        intro->dbl.monIdx[0] = BTL_MAIN_GetEnemyLanePosFromWork(scu->context, side, 0);
        intro->dbl.mon[0] = func_021B98AC(scu->monTable, intro->dbl.monIdx[0]);
        intro->dbl.monId[0] = BTL_POKEPARAM_GetPokeId(intro->dbl.mon[0]);
        intro->dbl.monIdx[1] = BTL_MAIN_GetEnemyLanePosFromWork(scu->context, side, 1);
        intro->dbl.mon[1] = func_021B98AC(scu->monTable, intro->dbl.monIdx[1]);
        intro->dbl.monId[1] = BTL_POKEPARAM_GetPokeId(intro->dbl.mon[1]);
        func_021ED798(&scu->slide);
        (*state)++;
        break;
    case 1:
        if (func_021ED814(&scu->slide)) {
            side = func_021B8E70(scu->context, intro->dbl.monIdx[0]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[0]), side);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            side = func_021B8E70(scu->context, intro->dbl.monIdx[1]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[1]), side);
            func_021F7A28(side, 0x231);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 3:
        if (!func_021F7EB4()) {
            BTL_MSG_FormatArgs(scu->textBuf, 2, 2, intro->dbl.monId[0], intro->dbl.monId[1]);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ECF68(scu)) {
            func_021EDA04(&scu->monSlots[intro->dbl.monIdx[0]]);
            func_021EDA04(&scu->monSlots[intro->dbl.monIdx[1]]);
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ED814(&scu->slide)) {
            func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 6:
        if (!func_021F7EB4()) {
            intro->dbl.side[0] = 2;
            intro->dbl.side[1] = 4;
            intro->dbl.localSide = func_021B8FF4(scu->context);
            for (i = 0; i < 2; i++) {
                intro->dbl.monIdx[i] = func_021B8ED8(scu->context, intro->dbl.side[i]);
                intro->dbl.mon[i] = func_021B98AC(scu->monTable, intro->dbl.monIdx[i]);
                if (intro->dbl.mon[i]) intro->dbl.monId[i] = BTL_POKEPARAM_GetPokeId(intro->dbl.mon[i]);
            }
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[0]), intro->dbl.side[0]);
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(intro->dbl.mon[1]), intro->dbl.side[1]);
            func_021F7998(0x234);
            BTL_MSG_FormatArgs(scu->textBuf, 12, 2, intro->dbl.monId[0], intro->dbl.monId[1]);
            func_021ECEB8(scu, scu->textBuf, 0x50, 0);
            (*state)++;
        }
        break;
    case 7:
        if (func_021ECF68(scu)) {
            func_021ED798(&scu->slide);
            (*state)++;
        }
        break;
    case 8:
        if (func_021ED814(&scu->slide) && !func_021F7EB4()) {
            func_021EDA04(&scu->monSlots[intro->dbl.monIdx[0]]);
            func_021EDA04(&scu->monSlots[intro->dbl.monIdx[1]]);
            (*state)++;
        }
        break;
    case 9:
        if (!func_021F7EB4()) return 1;
        break;
    }
    return 0;
}



int BTLV_SCU_ProcEntryDoubleTrainerLocal(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleTrainerLocalPhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}



int BTLV_SCU_ProcEntryDoubleTrainerComm(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleTrainerCommPhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}



int BTLV_SCU_ProcEntryDoubleLinkLocal(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleLinkLocalPhases[scu->phase][func_021B8FF4(scu->context)](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}



int BTLV_SCU_ProcEntryDoubleLinkComm(int *state, BtlvScu *scu)
{
    if (scu->quickMode != 0)
        return BTLV_SCU_ProcQuickEntryDouble(scu, state);
    if (scu->phase < 3) {
        if (gBtlvScuDoubleLinkCommPhases[scu->phase](scu, state) != 0) {
            scu->phase = scu->phase + 1;
            *state = 0;
        }
        return 0;
    }
    return 1;
}
