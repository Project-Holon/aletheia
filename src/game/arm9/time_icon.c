/*
 * file:     time_icon.c
 * unit:     yes
 * function: APP_ENV_IsRunOnTwl, APP_ENV_HasParentalControlBits, APP_ENV_InitParentalControl, APP_ENV_IsEulaAgreed, APP_ENV_GetOwnerColorAndBirthMonth, COMM_HISTORY_InsertIfNamed, COMM_HISTORY_InsertOrReplace, COMM_HISTORY_CountLeadingOccupied, COMM_HISTORY_CountByKey, COMM_HISTORY_FindByKey, COMM_HISTORY_FindByKeys, COMM_HISTORY_RemoveAt, COMM_HISTORY_StoreAndNotify, COMM_HISTORY_StoreAt, COMM_HISTORY_ScaleValue, COMM_HISTORY_ScaleSpan, TIME_ICON_Create, TIME_ICON_CreateNode, TIME_ICON_Init, TIME_ICON_Alloc, TIME_ICON_Start, TIME_ICON_Delete, TIME_ICON_TaskMain, TIME_ICON_NodeMain, TIME_ICON_Update, ITEM_GFX_IsFlagClear, ITEM_GFX_GetItemId, ITEM_GFX_GetExtraValue, ITEM_GFX_GetRowIndex, SAVE_EVENT_Write, SAVE_EVENT_WriteMode, SAVE_EVENT_StoreTodayDate, SAVE_EVENT_WriteWithDate, SAVE_EVENT_ClearVariant, SAVE_EVENT_WriteEventIdWithDate, SAVE_EVENT_StoreVariant, SAVE_EVENT_CopyVariant, SAVE_EVENT_StoreRecord, SAVE_EVENT_CopyDoneFlag, SAVE_EVENT_SetDoneFlag, SAVE_EVENT_IsStageDone, SAVE_EVENT_CheckStage, SAVE_EVENT_CommitStage, SAVE_EVENT_AdvanceStage, EVENT_ID_GetBank, EVENT_ID_GetIndex, EVENT_ID_Check, EVENT_ID_AreSlotsClear, APP_POWER_ClearCallback, APP_POWER_SetCallback, APP_POWER_Main, APP_POWER_ResetDisplay, APP_POWER_LoadShutdownScreen, APP_POWER_DrawShutdownScreen, APP_POWER_IsSupported, OVERLAY_LAUNCH_Driver, APP_POWER_IsReady
 * address:  0x0202EB0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetParentalControlInfoPtr  0x02087E60  arm
 *   func_02087DC4  0x02087DC4  arm
 *   OS_IsAgreeEULA  0x02087DE0  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_0200974C  0x0200974C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   COMM_HISTORY_CountLeadingOccupied  0x0202EC24  thumb
 *   func_02008530   0x02008530  thumb
 *   func_02009750   0x02009750  thumb
 *   func_020095E8   0x020095E8  thumb
 *   _u32_div_f      0x0209C2B0  arm
 *   time_icon_File     0x020A7814  data
 *   func_02030DA8  0x02030DA8  arm
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   func_020056EC   0x020056EC  thumb
 *   BMP_CreateFromArchive   0x0204384C  arm
 *   BMP_WIN_GetBgLayer   0x02045730  arm
 *   BMP_WIN_GetPosX   0x02045758  arm
 *   BMP_WIN_GetWidth   0x02045738  arm
 *   BMP_WIN_GetPosY   0x02045760  arm
 *   BMP_WIN_GetHeight   0x02045740  arm
 *   BMP_WIN_GetPalette   0x02045778  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *   BMP_Delete   0x020437AC  arm
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_WIN_Delete   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   TCBL_DeleteTask   0x02031194  arm
 *   BMP_Blit   0x020439A0  arm
 *   sItemGfxExtraTable      0x020A03C8  data
 *   POKE_TOOL_Dummy   0x020185F0  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb
 *   POKE_TOOL_SetBoxValue   0x02017E64  thumb
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   ZONEDATA_IsRawZoneGroup4CTo69   0x02014034  thumb
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb
 *   FILE_UTIL_Check12E4  0x020212E4  thumb
 *   func_02007084  0x02007084  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   UI_ClearFlags39Global  0x020351A0  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   GXx_SetMasterBrightness_    0x0207D534  arm
 *   GX_HBlankIntr    0x0207D3AC  arm
 *   GX_VBlankIntr    0x0207D3E4  arm
 *   GX_ResetBankForBG    0x020808F4  arm
 *   GX_ResetBankForSubBG    0x020809A0  arm
 *   func_0207FDCC    0x0207FDCC  arm
 *   GX_SetGraphicsMode    0x0207D4B0  arm
 *   G2_GetBG1CharPtr    0x0207E24C  arm
 *   func_02082A7C    0x02082A7C  arm
 *   ARC_UTIL_LoadMember    0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx    0x02062A4C  arm
 *   DWCi_ScreenDC_FlushRange    0x020862F0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   NNS_G2dGetUnpackedScreenData    0x02062B30  arm
 *   G2_GetBG1ScrPtr    0x0207DFB4  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo    0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData    0x02062A98  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   BMP_CreateFromVram    0x02043754  arm
 *   GF_FONT_Create    0x0201D7EC  thumb
 *   func_02045B38    0x02045B38  arm
 *   func_02045EC0    0x02045EC0  arm
 *   PRINTSYS_PrintColor    0x0201C7D0  thumb
 *   MSGDATA_Delete    0x02045C04  arm
 *   GF_FONT_Delete    0x0201D83C  thumb
 *   ov088_id       0x00000058  data  a1
 *   ov179_id       0x000000B3  data  a1
 *   d_021BD8E8     0x021BD8E8  data
 *   d_021B68D8     0x021B68D8  data  ov179
 *   d_021BD574     0x021BD574  data
 *   sOverlayLaunchWork     0x02146948  data
 *   sOverlayLaunchWorkArg 0x02146948  data
 *   PROCSYS_PushGlobal  0x020312CC  arm
 */
#include "comm_player_support_shared_types.h"
#include "blink_palanm_shared_types.h"

#define REG32(a) (*(volatile u32 *)(a))

#define REG16(a) (*(volatile u16 *)(a))

#define REG_BG1CNT_A        0x0400000A

#define REG_BG1HOFS_A       0x04000014

#define REG_BLDCNT_A        0x04000050

#define REG_MASTER_BRIGHT_A 0x0400006C

#define REG_MASTER_BRIGHT_B 0x0400106C

struct Tcb;

struct TcbList;

struct TcblNode;

struct TcblList;

struct BmpWin;

struct Bmp;

struct SaveData;

struct Strbuf;

struct MsgBank;

struct GfFont;

struct HistoryOwner;

struct ArchiveRecord;

/* One slot of the 20-entry history table (0x28 bytes). */
struct HistoryEntry {
    struct PlayerRecord record;     /* 0x00 */
    u8 reserved20[6];               /* 0x20 */
    u8 : 3;                         /* 0x26 */
    u8 isMarked : 1;
    u8 isOccupied : 1;
    u8 : 3;
    u8 reserved27;                  /* 0x27 */
};

/* Hardware capability word (DSi/wireless flags) behind OS_GetParentalControlInfoPtr. */
struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

/* Owner info record behind OS_GetOwnerInfo: only bytes 2 and 3 are read. */
struct OwnerInfo {
    u8 reserved00;
    u8 reserved01;
    u8 favoriteColor;
    u8 birthMonth;
    u8 rest[0x50];
};

/*
 * TIME_ICON object (0x1c bytes): the animated wait icon, a 2x2 tile window
 * in the bottom right corner of a reference window.  Each tick copies the
 * next 16x16 frame of the 8-frame sheet into the window.
 */
struct TimeIcon {
    struct Tcb *task;           /* 0x00, set when created with a task list */
    struct TcblNode *node;      /* 0x04, set when created with a TCBL node */
    struct BmpWin *win;         /* 0x08 */
    struct Bmp *sheet;          /* 0x0c, frame sheet loaded from archive 0xC6 */
    u16 heapId;                 /* 0x10 */
    u8 fillColor;               /* 0x12, window background fill value */
    u8 waitCounter;             /* 0x13, ticks left until the next frame */
    u8 waitInterval;            /* 0x14, ticks per frame */
    u8 frame;                   /* 0x15, current frame, 0..7 */
    u8 reserved16[2];           /* 0x16 */
    u32 isActive;               /* 0x18 */
};

/* Entry of the 46-row item graphics extra table. */
struct ItemGfxExtra {
    u16 itemId;
    u16 value;
};

/* State block of the overlay launcher driven by OVERLAY_LAUNCH_Driver. */
struct OverlayLaunchWork {
    u16 stage;      /* 0x00 */
    u8 enabled;     /* 0x02 */
    u8 aborted;     /* 0x03, set by the launched overlay */
    u32 mode;       /* 0x04 */
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void STRBUF_Delete(struct Strbuf *str);

extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);

extern u32 OS_IsRunOnTwl(void);

extern struct DeviceInfo *OS_GetParentalControlInfoPtr(void);

extern void func_02087DC4(void);

extern int OS_IsAgreeEULA(void);

extern void OS_GetOwnerInfo(struct OwnerInfo *info);

extern u8 func_0200856C(const struct PlayerRecord *record);

extern struct HistoryEntry *func_0200974C(struct HistoryOwner *owner);

extern u32 func_02008530(const struct PlayerRecord *record);

extern u32 func_02009750(struct HistoryOwner *owner, u32 key);

extern void func_020095E8(struct HistoryOwner *owner);

extern u32 _u32_div_f(u32 dividend, u32 divisor);

extern struct Tcb *func_02030DA8(struct TcbList *list, void (*callback)(struct Tcb *, void *), void *work, u32 priority);

extern struct TcblNode *TCBL_AddTask(struct TcblList *list, void (*callback)(struct TcblNode *, void *), u32 size, u32 flags);

extern void *TCBL_GetWork(struct TcblNode *node);

extern u32 func_020056EC(u32 range);

extern struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern u8 BMP_WIN_GetPosX(struct BmpWin *win);

extern u8 BMP_WIN_GetWidth(struct BmpWin *win);

extern u8 BMP_WIN_GetPosY(struct BmpWin *win);

extern u8 BMP_WIN_GetHeight(struct BmpWin *win);

extern u8 BMP_WIN_GetPalette(struct BmpWin *win);

extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u32 width, u32 height, u32 palette, u32 allocDir);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern void func_02041B6C(u32 bgLayer);

extern void BMP_Delete(struct Bmp *bmp);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_Clear(struct Bmp *bmp, u8 value);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern u32 BMP_WIN_Delete(struct BmpWin *win);

extern void func_02030EAC(struct Tcb *tcb);

extern void TCBL_DeleteTask(struct TcblNode *node);

extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u32 colorKey);

extern struct SaveData *POKE_TOOL_Dummy(void *gameData);

extern u32 POKE_TOOL_DecodeBoxParam(struct SaveData *save);

extern u32 POKE_TOOL_EncodeBoxParam(struct SaveData *save, u32 savedFlag);

extern u32 POKE_TOOL_IsBoxOwnedByPlayer(struct SaveData *save, const struct PlayerRecord *record);

extern void POKE_TOOL_SetBoxValue(struct SaveData *save, u32 varId, u32 value);

extern u32 POKE_TOOL_GetBoxValue(struct SaveData *save, u32 varId, u32 defaultValue);

extern u32 ZONEDATA_IsRawZoneGroup4CTo69(u32 id);

extern struct Strbuf *func_02008510(const struct PlayerRecord *record, u32 index);

extern u32 func_02008550(const struct PlayerRecord *record);

extern u32 POKE_TOOL_IsBoxShiny(struct SaveData *save);

extern u32 FILE_UTIL_Check12E4(u16 value);

extern void func_02007084(void);

extern int GFL_NET_GetRunState(void);

extern void GFL_NET_ClearExitFlag(void);

extern int GFL_NET_Exit(int enable);

extern void GFL_NET_IRC_WIRELESS_Exit(void);

extern u32 GFL_NET_Main(void);

extern int GFL_NET_IsSessionNull(void);

extern int UI_ClearFlags39Global(u32 stage);

extern void GFL_USE_PollPowerExit(void);

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

extern long GX_HBlankIntr(int enable);

extern long GX_VBlankIntr(int enable);

extern int GX_ResetBankForBG(void);

extern int GX_ResetBankForSubBG(void);

extern void func_0207FDCC(u32 layerMask);

extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0Is3d);

extern void *G2_GetBG1CharPtr(void);

extern void func_02082A7C(u32 value, u32 dest, u32 size);

extern int ARC_UTIL_LoadMember(int arcId, int memberId, int compressed, int heapId);

extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct ArchiveRecord *file, void **out);

extern void DWCi_ScreenDC_FlushRange(u32 addr, u32 size);

extern void MIi_CpuCopy16(u32 src, u32 dest, u32 size);

extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);

extern void *G2_GetBG1ScrPtr(void);

extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct ArchiveRecord *file, void **out);

extern s32 NNS_G2dGetUnpackedPaletteData(struct ArchiveRecord *file, void **out);

extern void MIi_CpuClear16(u32 value, u32 dest, u32 size);

extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heapId);

extern struct GfFont *GF_FONT_Create(int fontId, int spacingX, int spacingY, int colorMode, u32 heapId);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);

extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *text, struct GfFont *font, u16 color);

extern u32 MSGDATA_Delete(struct MsgBank *bank);

extern u32 GF_FONT_Delete(struct GfFont *font);

extern void PROCSYS_PushGlobal(u32 ovl, u32 proc, u32 arg);

u32 APP_ENV_IsRunOnTwl(void);

int APP_ENV_HasParentalControlBits(void);

void APP_ENV_InitParentalControl(void);

u32 APP_ENV_IsEulaAgreed(void);

void APP_ENV_GetOwnerColorAndBirthMonth(u8 *outFavoriteColor, u8 *outBirthMonth);

u32 COMM_HISTORY_InsertIfNamed(struct HistoryOwner *owner, struct HistoryEntry *entry);

u32 COMM_HISTORY_InsertOrReplace(struct HistoryOwner *owner, struct HistoryEntry *entry);

u32 COMM_HISTORY_CountLeadingOccupied(const struct HistoryEntry *table);

u32 COMM_HISTORY_CountByKey(struct HistoryEntry *table, u32 key);

s32 COMM_HISTORY_FindByKey(struct HistoryEntry *table, u32 key);

s32 COMM_HISTORY_FindByKeys(struct HistoryEntry *table, struct HistoryEntry *entry);

void COMM_HISTORY_RemoveAt(struct HistoryEntry *table, u32 index);

void COMM_HISTORY_StoreAndNotify(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark);

void COMM_HISTORY_StoreAt(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark);

u32 COMM_HISTORY_ScaleValue(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin);

u32 COMM_HISTORY_ScaleSpan(u32 total, u32 rate, u32 start, u32 end, u32 margin);

struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId);

struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);

void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId);

struct TimeIcon *TIME_ICON_Alloc(u32 heapId);

void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval);

void TIME_ICON_Delete(struct TimeIcon *icon);

void TIME_ICON_TaskMain(struct Tcb *tcb, void *work);

void TIME_ICON_NodeMain(struct TcblNode *node, void *work);

void TIME_ICON_Update(struct TimeIcon *icon);

u32 ITEM_GFX_IsFlagClear(const u8 *bits, u32 index);

u16 ITEM_GFX_GetItemId(u32 row);

u32 ITEM_GFX_GetExtraValue(u32 itemId);

u32 ITEM_GFX_GetRowIndex(u16 itemId);

void SAVE_EVENT_Write(void *gameData, u32 mode, const struct PlayerRecord *record, u32 eventId, u16 index);

void SAVE_EVENT_WriteMode(struct SaveData *save, u32 mode, const struct PlayerRecord *record, u32 eventId, u32 index);

void SAVE_EVENT_StoreTodayDate(struct SaveData *save);

void SAVE_EVENT_WriteWithDate(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day);

void SAVE_EVENT_ClearVariant(struct SaveData *save, u32 variant);

void SAVE_EVENT_WriteEventIdWithDate(struct SaveData *save, u32 eventId, u32 variant);

void SAVE_EVENT_StoreVariant(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant);

void SAVE_EVENT_CopyVariant(struct SaveData *save, u32 variant);

void SAVE_EVENT_StoreRecord(struct SaveData *save, const struct PlayerRecord *record, u32 index);

void SAVE_EVENT_CopyDoneFlag(struct SaveData *save);

void SAVE_EVENT_SetDoneFlag(struct SaveData *save);

int SAVE_EVENT_IsStageDone(void *gameData, int stage);

int SAVE_EVENT_CheckStage(struct SaveData *save, int stage);

void SAVE_EVENT_CommitStage(void *gameData, u32 stage);

void SAVE_EVENT_AdvanceStage(struct SaveData *save, u32 stage);

unsigned int EVENT_ID_GetBank(unsigned int id);

unsigned int EVENT_ID_GetIndex(unsigned int id);

u32 EVENT_ID_Check(void *unused, u16 value, u16 unused2);

int EVENT_ID_AreSlotsClear(struct SaveData *save, int unused);

void APP_POWER_ClearCallback(void);

void APP_POWER_SetCallback(u32 on);

void APP_POWER_Main(u32 mode);

void APP_POWER_ResetDisplay(u32 messageId);

void APP_POWER_LoadShutdownScreen(void);

void APP_POWER_DrawShutdownScreen(u32 messageId);

int APP_POWER_IsSupported(void);

int OVERLAY_LAUNCH_Driver(void *unused, u32 *state);

int APP_POWER_IsReady(void);

extern char time_icon_File[];

extern struct ItemGfxExtra sItemGfxExtraTable[];

extern u8 ov088_id[];

extern u8 ov179_id[];

extern u8 d_021BD8E8[];

extern u8 d_021B68D8[];

extern u8 d_021BD574[];

extern struct OverlayLaunchWork sOverlayLaunchWork;

extern u8 sOverlayLaunchWorkArg[];

/* Hardware registers (main engine, A) used by the shutdown display reset. */
#define REG_DISPCNT_A       0x04000000

/*
 * A pool-word-and-bx tail call into an ARM SDK entry point
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), eight bytes with no
 * prologue. Its result is compared against 1 by APP_ENV_IsEulaAgreed, which is the
 * only caller.
 */
u32 APP_ENV_IsRunOnTwl(void)
{
    return OS_IsRunOnTwl();
}

/* Nonzero when running on a DSi with both capability bits (0 and 5) set. */
int APP_ENV_HasParentalControlBits(void)
{
    if (APP_ENV_IsRunOnTwl()) {
        if (OS_GetParentalControlInfoPtr()->bit0 && OS_GetParentalControlInfoPtr()->bit5) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Bare tail call into an ARM SDK leaf. */
void APP_ENV_InitParentalControl(void)
{
    func_02087DC4();
}

/*
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 */
u32 APP_ENV_IsEulaAgreed(void)
{
    if (APP_ENV_IsRunOnTwl() == 1) {
        return OS_IsAgreeEULA();
    }
    return 1;
}

/*
 * Fills an 0x54-byte structure on the stack from an ARM SDK getter and
 * copies two of its bytes out through the two pointer parameters. The
 * whole 0x54 bytes are reserved even though only offsets 2 and 3 are
 * read, so the stack object is the SDK's structure and not a pair of
 * bytes; `add r0, sp, #0` is emitted twice, once for the call and once
 * as the base of the two loads, which is what a named local rather than
 * a re-taken address looks like here.
 */
void APP_ENV_GetOwnerColorAndBirthMonth(u8 *outFavoriteColor, u8 *outBirthMonth)
{
    struct OwnerInfo info;

    OS_GetOwnerInfo(&info);
    *outFavoriteColor = info.favoriteColor;
    *outBirthMonth = info.birthMonth;
}

/*
 * Byte-correct, MATCH-capped.
 *
 * All 30 concrete bytes are right; the call to COMM_HISTORY_InsertOrReplace is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when COMM_HISTORY_InsertOrReplace itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing.
 */
u32 COMM_HISTORY_InsertIfNamed(struct HistoryOwner *owner, struct HistoryEntry *entry)
{
    if (func_0200856C(&entry->record) == 0) {
        return 0;
    }
    return COMM_HISTORY_InsertOrReplace(owner, entry);
}

/*
 * The history table dispatcher (look the entry up; remove and notify, or
 * insert by key under the count-capped policy).  Closed in wave 16 under
 * 1.1p1, no pin: the notify call is written in BOTH arms of the count test.
 * 1.1p1 then cross-jumps the two notify tails (the then-arm's `b` at
 * 0x0202EC04, reached by the inner `blo` as a jump to a jump) and no longer
 * merges the two COMM_HISTORY_RemoveAt calls, and the a/b/v register rotation
 * resolves with it.  `isMarked` is the +0x26 bit-3 field.
 *
 * Returns 1 when an existing entry was replaced and 2 when a new one was
 * inserted.
 */
u32 COMM_HISTORY_InsertOrReplace(struct HistoryOwner *owner, struct HistoryEntry *entry)
{
    struct HistoryEntry *table;
    u32 index;
    u32 value;

    table = func_0200974C(owner);
    index = COMM_HISTORY_FindByKeys(table, entry);

    if (index != 0x14) {
        if (table[index].isMarked)
            value = 1;
        else
            value = 0;
        COMM_HISTORY_RemoveAt(table, index);
        COMM_HISTORY_StoreAndNotify(owner, entry, value);
        return 1;
    }

    value = func_0200856C(&entry->record);
    if (COMM_HISTORY_CountByKey(table, value) < 5) {
        if (COMM_HISTORY_CountLeadingOccupied(table) >= 0x14)
            COMM_HISTORY_RemoveAt(table, 0);
        COMM_HISTORY_StoreAndNotify(owner, entry, 0);
    } else {
        COMM_HISTORY_RemoveAt(table, COMM_HISTORY_FindByKey(table, value));
        COMM_HISTORY_StoreAndNotify(owner, entry, 0);
    }
    return 2;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Counts the leading run of occupied entries in a 20-entry array of
 * 0x28-byte records and returns the index of the first free one, or 20.
 * No prologue at all, because it calls nothing and needs no callee-saved
 * register, so `disasm.py` gives it no label.
 *
 * The occupancy test is `lsls #0x1B` / `lsrs #0x1F` on a byte at offset
 * 0x26, which is a one-bit unsigned bitfield at bit 4 and cannot be
 * written as a mask: `& 0x10` folds to `movs`/`ands` and a shift pair
 * with unequal amounts is a narrowing cast, not a field
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md,
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The record stride arrives as `movs r1, #0x28` / `muls` rather than a
 * scaled index because 0x28 is not a power of two.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 */
u32 COMM_HISTORY_CountLeadingOccupied(const struct HistoryEntry *table)
{
    u32 i;

    for (i = 0; i < 20; i++) {
        if (table[i].isOccupied == 0) {
            break;
        }
    }
    return i;
}

/*
 * Counts the occupied entries whose key matches, capped at five.  Same
 * 0x28-byte record as COMM_HISTORY_FindByKey, matched next door.
 */
u32 COMM_HISTORY_CountByKey(struct HistoryEntry *table, u32 key)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < 0x14; i++) {
        u32 entryKey;
        if (!table[i].isOccupied)
            break;
        entryKey = func_0200856C(&table[i].record);
        if (entryKey == key)
            count++;
    }

    if (count > 5)
        count = 5;
    return count;
}

/* Index of the first occupied entry with the given key, or 0x14. */
s32 COMM_HISTORY_FindByKey(struct HistoryEntry *table, u32 key)
{
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 entryKey;
        if (!table[i].isOccupied) break;
        entryKey = func_0200856C(&table[i].record);
        if (entryKey == key) return i;
    }
    return 0x14;
}

/*
 * Finds the first occupied entry whose two keys both match the reference
 * entry's, or 0x14 when there is none.
 */
s32 COMM_HISTORY_FindByKeys(struct HistoryEntry *table, struct HistoryEntry *entry)
{
    u32 keyA = func_02008530(&entry->record);
    u32 keyB = func_0200856C(&entry->record);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 candidateA, candidateB;
        if (!table[i].isOccupied)
            break;
        candidateA = func_02008530(&table[i].record);
        if (candidateA == keyA) {
            candidateB = func_0200856C(&table[i].record);
            if (candidateB == keyB)
                return i;
        }
    }
    return 0x14;
}

/*
 * Removes entry `index` by shifting the following entries down, then clears
 * the occupied flag of the tail.
 *
 * EXACT* only for the two bytes of alignment padding at 0x0202ED5E.  Closed
 * in wave 16 (the residue since wave 12 was the ldm/stm base order of the
 * record copy): the copy goes through a named destination and a source
 * derived from it (`dst = &table[index]; src = dst + 1; *dst = *src;`), and
 * the flag test must NOT share the `table + index` subexpression with them,
 * or the front end rematerialises table + index*0x28 and computes the
 * source first.  `(table + 1)[index]` shares only the index*0x28 product,
 * which is what the image keeps in r7.
 */
void COMM_HISTORY_RemoveAt(struct HistoryEntry *table, u32 index)
{
    struct HistoryEntry *dst;
    struct HistoryEntry *src;

    if (index >= 0x14)
        return;

    if (index < 0x13) {
        while (1) {
            dst = &table[index];
            src = dst + 1;
            *dst = *src;
            if (!(table + 1)[index].isOccupied) {
                index++;
                break;
            }
            index++;
            if (index >= 0x13)
                break;
        }
    }

    while (index < 0x14) {
        table[index].isOccupied = 0;
        index++;
    }
}

/*
 * Stores the entry in the owner's table, then asks the owner whether the
 * entry's key now needs its follow-up (func_020095E8).  The key is read out
 * of the entry once into a named local and handed to func_02009750; that
 * call's answer decides whether func_020095E8 runs.
 */
void COMM_HISTORY_StoreAndNotify(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark)
{
    struct HistoryEntry *table = func_0200974C(owner);
    u32 key;

    COMM_HISTORY_StoreAt(table, entry, mark);

    key = func_0200856C(&entry->record);
    if (func_02009750(owner, key) != 0)
        func_020095E8(owner);
}

/*
 * Stores the entry at the first free index of the table (COMM_HISTORY_CountLeadingOccupied),
 * after setting the bit-3 mark from `mark` and the bit-4 occupied flag.
 */
void COMM_HISTORY_StoreAt(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark)
{
    u32 index = COMM_HISTORY_CountLeadingOccupied(table);

    if (index >= 0x14)
        return;

    if (mark != 0)
        entry->isMarked = 1;
    else
        entry->isMarked = 0;

    entry->isOccupied = 1;

    table[index] = *entry;
}

/* Maps value into the band [rangeStart+margin/2, rangeEnd-margin/2]: 0 below it and maxValue above it. */
u32 COMM_HISTORY_ScaleValue(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin)
{
    u32 halfMargin  = margin >> 1;
    u32 low = rangeStart + halfMargin;
    u32 high = rangeEnd - halfMargin;
    u32 offset;

    if (value <= low)
        return 0;
    if (value >= high)
        return maxValue;

    offset = value - low;
    return (offset * (maxValue << 8) / (high - low)) >> 8;
}

/*
 * A scaled-span helper: the span (end - start - margin) is raised eight
 * bits, scaled by the rate, divided by the total and shifted back down; the
 * quotient joins start and half of margin.
 *
 * The divide is the UNSIGNED runtime entry at 0x0209C2B0 (which
 * layout/runtime_arm9.txt names `_div_by_zero_check`, but the code there is
 * the unsigned divide entry itself; `signed / signed` emits 0x0209C0A4
 * instead).  Declared here under the front end's own name, `_u32_div_f`.
 *
 * Two spellings are load-bearing:
 *   - the quotient must be bound to its own local.  Written inline, the
 *     quotient stays live in r0 and the re-read of `margin` is scheduled
 *     into r1 BEFORE the shift.
 *   - the sum must associate as `(start + scaled) + (margin >> 1)`.  With
 *     `(scaled + start) + (margin >> 1)` the two `adds` land on the other
 *     operand order.
 * Together they put the quotient's high half in r2 and re-read `margin`
 * into r0, which is exactly the original's tail.
 */
u32 COMM_HISTORY_ScaleSpan(u32 total, u32 rate, u32 start, u32 end, u32 margin)
{
    u32 span = ((end - start) - margin) << 8;
    u32 scaled = _u32_div_f(span * rate, total) >> 8;

    return (start + scaled) + (margin >> 1);
}

/*
 * Allocates and fills the 0x1c-byte time icon.  The heap id is the fifth
 * (stack) argument and is re-read from its slot for the second use (it is
 * also what TIME_ICON_Init's u16 tail parameter receives), so it is spelled
 * `volatile u16`.  When the optional task list is non-null the icon is
 * registered as a task (callback TIME_ICON_TaskMain); otherwise `task` is zeroed.
 *
 * Sibling of TIME_ICON_CreateNode, which builds the same object through the
 * TCBL_AddTask allocator instead.
 */
struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId)
{
    struct TimeIcon *icon;

    icon = func_02030734(heapId, sizeof(struct TimeIcon), 0, time_icon_File, 0x49);
    TIME_ICON_Init(icon, refWin, fillColor, waitInterval, heapId);
    if (taskList != 0) {
        icon->task = func_02030DA8(taskList, TIME_ICON_TaskMain, icon, 0);
    } else {
        icon->task = 0;
    }
    icon->node = 0;
    icon->isActive = 1;
    return icon;
}

/*
 * Sibling of TIME_ICON_Create: the same 0x1c-byte TimeIcon, built through the
 * TCBL_AddTask node allocator instead of func_02030734.  The node is
 * stashed at +4 and +0 is zeroed, the mirror image of TIME_ICON_Create, which
 * registers a task into +0 and zeroes +4.  The node callback is
 * TIME_ICON_NodeMain.
 */
struct TimeIcon *TIME_ICON_CreateNode(struct TcblList *nodeList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId)
{
    struct TcblNode *node;
    struct TimeIcon *icon;

    node = TCBL_AddTask(nodeList, TIME_ICON_NodeMain, 0x1c, 0);
    icon = TCBL_GetWork(node);
    TIME_ICON_Init(icon, refWin, fillColor, waitInterval, heapId);
    icon->node = node;
    icon->task = 0;
    icon->isActive = 1;
    return icon;
}

/*
 * Fills in a freshly allocated icon: the heap id, the fill color, the frame
 * timing and a random start frame, then builds the 2x2 window from the
 * reference window's six accessors (x and y are the sum of position and
 * size, minus two, truncated to a byte).
 */
void TIME_ICON_Init(struct TimeIcon *icon, struct BmpWin *refWin, u8 fillColor, u8 waitInterval, u16 heapId)
{
    u32 bgLayer, posY, height;
    u32 posX, width;
    u32 palette;

    icon->heapId = heapId;
    icon->waitCounter = 0;
    icon->fillColor = fillColor;
    icon->waitInterval = waitInterval;
    icon->frame = func_020056EC(8);
    icon->sheet = BMP_CreateFromArchive(0xC6, 0, 1, icon->heapId);

    bgLayer = BMP_WIN_GetBgLayer(refWin);
    posX = BMP_WIN_GetPosX(refWin);
    width = BMP_WIN_GetWidth(refWin);
    posY = BMP_WIN_GetPosY(refWin);
    height = BMP_WIN_GetHeight(refWin);
    palette = BMP_WIN_GetPalette(refWin);

    BMP_WIN_MakeScreen(icon->win = BMP_WIN_Create(bgLayer, (u8)((posX + width) - 2),
                                   (u8)((posY + height) - 2), 2, 2, palette, 1));
    func_02041B6C(BMP_WIN_GetBgLayer(icon->win));
}

/* Allocates an idle TimeIcon: heap id and frame sheet only; TIME_ICON_Start finishes it. */
struct TimeIcon *TIME_ICON_Alloc(u32 heapId)
{
    struct TimeIcon *icon = func_02030734(heapId, 0x1c, 0, time_icon_File, 0xa6);

    icon->heapId = (u16)heapId;
    icon->sheet = BMP_CreateFromArchive(0xc6, 0, 1, icon->heapId);
    icon->win = 0;
    icon->task = 0;
    icon->node = 0;
    return icon;
}

/*
 * TIME_ICON_Init's twin for an icon from TIME_ICON_Alloc: the window is built
 * the same way, then the icon is registered as a task of the caller's list.
 */
void TIME_ICON_Start(struct TimeIcon *icon, struct TcbList *taskList, struct BmpWin *refWin, u8 fillColor, u8 waitInterval)
{
    u32 bgLayer, posY, height;
    u32 posX, width;
    u32 palette;

    icon->waitCounter = 0;
    icon->fillColor = fillColor;
    icon->waitInterval = waitInterval;
    icon->frame = func_020056EC(8);

    bgLayer = BMP_WIN_GetBgLayer(refWin);
    posX = BMP_WIN_GetPosX(refWin);
    width = BMP_WIN_GetWidth(refWin);
    posY = BMP_WIN_GetPosY(refWin);
    height = BMP_WIN_GetHeight(refWin);
    palette = BMP_WIN_GetPalette(refWin);

    BMP_WIN_MakeScreen(icon->win = BMP_WIN_Create(bgLayer, (u8)((posX + width) - 2),
                                   (u8)((posY + height) - 2), 2, 2, palette, 1));
    func_02041B6C(BMP_WIN_GetBgLayer(icon->win));

    icon->node = 0;
    icon->task = func_02030DA8(taskList, TIME_ICON_TaskMain, icon, 0);
    icon->isActive = 1;
}

/*
 * Deletes the icon.  An icon that never got a window (neither task nor
 * node) only frees its sheet and itself; otherwise it clears the window,
 * frees the sheet and removes whichever of task and node it holds.
 */
void TIME_ICON_Delete(struct TimeIcon *icon)
{
    if (icon->task == 0 && icon->node == 0) {
        BMP_Delete(icon->sheet);
        func_020307B0(icon);
        return;
    }

    icon->isActive = 0;
    BMP_Clear(BMP_WIN_GetBmp(icon->win), icon->fillColor);
    BMP_WIN_TransferChars(icon->win);
    BMP_WIN_Delete(icon->win);
    BMP_Delete(icon->sheet);

    if (icon->task != 0) {
        func_02030EAC(icon->task);
        func_020307B0(icon);
        return;
    }

    if (icon->node != 0)
        TCBL_DeleteTask(icon->node);
}

/* Task callback of an icon created with a task list. */
void TIME_ICON_TaskMain(struct Tcb *tcb, void *work)
{
    TIME_ICON_Update(work);
}

/* Node callback of an icon created with a TCBL node. */
void TIME_ICON_NodeMain(struct TcblNode *node, void *work)
{
    TIME_ICON_Update(work);
}

/*
 * One tick of the icon: while the wait counter runs down it only counts;
 * at zero it fills the window, copies the next 16x16 frame of the sheet
 * into it, commits the window and reloads the counter.  The frame wraps at 8.
 */
void TIME_ICON_Update(struct TimeIcon *icon)
{
    if (icon->isActive == 0)
        return;

    if (icon->waitCounter == 0) {
        BMP_Clear(BMP_WIN_GetBmp(icon->win), icon->fillColor);
        BMP_Blit(icon->sheet, BMP_WIN_GetBmp(icon->win), 0,
                      (u32)icon->frame << 4, 0, 0, 0x10, 0x10, 0);
        BMP_WIN_TransferChars(icon->win);

        icon->waitCounter = icon->waitInterval;
        icon->frame = icon->frame + 1;

        if (icon->frame == 8)
            icon->frame = 0;
    } else {
        icon->waitCounter = icon->waitCounter - 1;
    }
}

/*
 * Bit `index` of a byte array, inverted: 1 when the bit is clear.
 * Unlabelled leaf in the 0x0202F114..0x0202F190 gap.
 *
 * The byte index and the bit number are both `u8` locals: the original
 * truncates each with its own `lsls #0x18`/`lsrs #0x18` pair, and `i >> 3`
 * or `i & 7` folded into the shift expression loses them (the front end
 * knows both are already in range and drops the conversions).
 */
u32 ITEM_GFX_IsFlagClear(const u8 *bits, u32 index)
{
    u8 byteIndex = (u8)(index >> 3);
    u8 bitIndex = (u8)(index & 7);

    if ((bits[byteIndex] & (1 << bitIndex)) != 0)
        return 0;
    return 1;
}

/*
 * First field (item id) of row `row` of the 0x2E-row item graphics extra
 * table; the sibling lookups ITEM_GFX_GetExtraValue (second field) and ITEM_GFX_GetRowIndex
 * (row index) share it.  All three are unlabelled leaf functions in the
 * 0x0202F114..0x0202F190 gap.
 */
u16 ITEM_GFX_GetItemId(u32 row)
{
    return sItemGfxExtraTable[row].itemId;
}

/*
 * Second field of the row whose item id matches, 0 when there is none.
 */
u32 ITEM_GFX_GetExtraValue(u32 itemId)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sItemGfxExtraTable[i].itemId == itemId)
            return sItemGfxExtraTable[i].value;
    }
    return 0;
}

/*
 * Row index of the entry whose item id matches, 0 when there is none.
 * Unsigned loop here, signed in ITEM_GFX_GetExtraValue.
 */
u32 ITEM_GFX_GetRowIndex(u16 itemId)
{
    u32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sItemGfxExtraTable[i].itemId == itemId)
            return i;
    }
    return 0;
}

void SAVE_EVENT_Write(void *gameData, u32 mode, const struct PlayerRecord *record, u32 eventId, u16 index)
{
    SAVE_EVENT_WriteMode(POKE_TOOL_Dummy(gameData), mode, record, eventId, index);
}

/*
 * Seven-way mode switch around a POKE_TOOL_DecodeBoxParam / POKE_TOOL_EncodeBoxParam bracket.
 * Closed in wave 16: the 129-byte residue was NOT an allocator tie but the
 * source's gotos.  Every case is written out in full (no shared labels) and
 * case 2's guard carries the call run in BOTH arms; 1.1p1's own
 * cross-jumping then produces the image's `b` into case 0's
 * SAVE_EVENT_CopyDoneFlag/SAVE_EVENT_SetDoneFlag tail, the kept `bne; b` pair in case 2, and
 * the head that spills the selector and holds the fifth parameter in r7.
 * The call at +0x58 is attested by SAVE_EVENT_SetDoneFlag (same shard).  0x7532 is
 * a plain constant.
 */
void SAVE_EVENT_WriteMode(struct SaveData *save, u32 mode, const struct PlayerRecord *record, u32 eventId, u32 index)
{
    u32 savedFlag = POKE_TOOL_DecodeBoxParam(save);

    switch (mode) {
    case 0:
        SAVE_EVENT_ClearVariant(save, 0);
        SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
        SAVE_EVENT_StoreRecord(save, record, index);
        SAVE_EVENT_CopyDoneFlag(save);
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 1:
        SAVE_EVENT_WriteEventIdWithDate(save, 0x7532, 1);
        SAVE_EVENT_CopyDoneFlag(save);
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 2:
        if (POKE_TOOL_IsBoxOwnedByPlayer(save, record) == 1) {
            SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
            SAVE_EVENT_StoreRecord(save, record, index);
        } else {
            SAVE_EVENT_CopyVariant(save, 1);
            SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
            SAVE_EVENT_StoreRecord(save, record, index);
        }
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 3:
    case 4:
        break;
    case 5:
        SAVE_EVENT_WriteEventIdWithDate(save, eventId, 0);
        SAVE_EVENT_StoreRecord(save, record, index);
        SAVE_EVENT_SetDoneFlag(save);
        break;
    case 6:
        SAVE_EVENT_WriteEventIdWithDate(save, eventId, 1);
        break;
    }
    POKE_TOOL_EncodeBoxParam(save, savedFlag);
}

/* Stores today's RTC date into save variables 0x92 to 0x94. */
void SAVE_EVENT_StoreTodayDate(struct SaveData *save)
{
    struct RtcDate date;

    GF_STANDARD_SetField00_F4E4(&date);

    POKE_TOOL_SetBoxValue(save, 0x92, date.year);
    POKE_TOOL_SetBoxValue(save, 0x93, date.month);
    POKE_TOOL_SetBoxValue(save, 0x94, date.day);
}

void SAVE_EVENT_WriteWithDate(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day)
{
    if (POKE_TOOL_GetBoxValue(save, 0xAA, 0) == 1)
        SAVE_EVENT_StoreVariant(save, eventId, year, month, day, 0);
    else
        SAVE_EVENT_StoreVariant(save, eventId, year, month, day, 1);
    SAVE_EVENT_CopyDoneFlag(save);
    POKE_TOOL_SetBoxValue(save, 0x6D, 1);
}

void SAVE_EVENT_ClearVariant(struct SaveData *save, u32 variant)
{
    SAVE_EVENT_StoreVariant(save, 0, 0, 0, 0, variant);
}

/* Stores the event id with today's date into the given variant. */
void SAVE_EVENT_WriteEventIdWithDate(struct SaveData *save, u32 eventId, u32 variant)
{
    struct RtcDate date;

    GF_STANDARD_SetField00_F4E4(&date);

    if (ZONEDATA_IsRawZoneGroup4CTo69((u16)eventId) == 1)
        SAVE_EVENT_StoreVariant(save, 0x753E, date.year, date.month, date.day, variant);
    else
        SAVE_EVENT_StoreVariant(save, eventId, date.year, date.month, date.day, variant);
}

/*
 * Installs the four save variables of one variant (event id, year, month,
 * day).  The base index is the variant flag plus 0x95 for the event id,
 * then that same flag times three plus 0x8f/0x90/0x91 for the date.
 */
void SAVE_EVENT_StoreVariant(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant)
{
    u8 base = (variant == 1);

    POKE_TOOL_SetBoxValue(save, base + 0x95, eventId);
    base = (u8)(base * 3);
    POKE_TOOL_SetBoxValue(save, base + 0x8F, year);
    POKE_TOOL_SetBoxValue(save, base + 0x90, month);
    POKE_TOOL_SetBoxValue(save, base + 0x91, day);
}

/*
 * Reads the four save variables of one variant and hands them, with the
 * opposite variant, to SAVE_EVENT_StoreVariant (copies a variant to the other one).
 */
void SAVE_EVENT_CopyVariant(struct SaveData *save, u32 variant)
{
    u8 base = (variant == 1);
    u32 eventId, year, month, otherVariant, day;

    eventId = POKE_TOOL_GetBoxValue(save, base + 0x95, 0);
    base = (u8)(base * 3);
    year = POKE_TOOL_GetBoxValue(save, base + 0x8F, 0);
    month = POKE_TOOL_GetBoxValue(save, base + 0x90, 0);
    day = POKE_TOOL_GetBoxValue(save, base + 0x91, 0);

    otherVariant = (variant == 0);
    SAVE_EVENT_StoreVariant(save, eventId, year, month, day, otherVariant);
}

/*
 * Stores the record's name (variable 0x8d), key (0x9a) and kind (7) and
 * frees the name string.
 */
void SAVE_EVENT_StoreRecord(struct SaveData *save, const struct PlayerRecord *record, u32 index)
{
    struct Strbuf *name = (struct Strbuf *)func_02008510(record, index);
    u32 kind = func_02008530(record);
    u32 key = func_02008550(record);

    POKE_TOOL_SetBoxValue(save, 0x8d, (u32)name);
    POKE_TOOL_SetBoxValue(save, 0x9a, key);
    POKE_TOOL_SetBoxValue(save, 7, kind);
    STRBUF_Delete(name);
}

/* Copies save variable 0x9e into 0x99. */
void SAVE_EVENT_CopyDoneFlag(struct SaveData *save)
{
    u32 value = POKE_TOOL_GetBoxValue(save, 0x9e, 0);

    POKE_TOOL_SetBoxValue(save, 0x99, value);
}

/*
 * Unlabelled 12-byte Thumb leaf (a tail call through a pool word to
 * POKE_TOOL_SetBoxValue with id 0x77, value 0x15) after SAVE_EVENT_CopyDoneFlag; filed as the
 * witness for SAVE_EVENT_WriteMode's call at +0x58, the only branch to it
 * image-wide.
 */
void SAVE_EVENT_SetDoneFlag(struct SaveData *save)
{
    POKE_TOOL_SetBoxValue(save, 0x77, 0x15);
}

int SAVE_EVENT_IsStageDone(void *gameData, int stage)
{
    return SAVE_EVENT_CheckStage(POKE_TOOL_Dummy(gameData), stage);
}

/*
 * Nonzero when the save variables match the expected state of the given
 * stage (0 to 7): variable 5, the event id (0x96), the done flag (0x6d),
 * the count from POKE_TOOL_IsBoxShiny and whether any of the date variables is set.
 */
int SAVE_EVENT_CheckStage(struct SaveData *save, int stage)
{
    u32 savedFlag = POKE_TOOL_DecodeBoxParam(save);
    int variable5 = POKE_TOOL_GetBoxValue(save, 5, 0);
    int eventId = POKE_TOOL_GetBoxValue(save, 0x96, 0);
    int done = POKE_TOOL_GetBoxValue(save, 0x6d, 0);
    int count = POKE_TOOL_IsBoxShiny(save);
    int anyDate = 0;

    if (POKE_TOOL_GetBoxValue(save, 0x8f, anyDate) != 0
        || POKE_TOOL_GetBoxValue(save, 0x90, anyDate) != 0
        || POKE_TOOL_GetBoxValue(save, 0x91, anyDate) != 0
        || POKE_TOOL_GetBoxValue(save, 0x95, anyDate) != 0) {
        anyDate = 1;
    }
    POKE_TOOL_EncodeBoxParam(save, savedFlag);

    switch (stage) {
    case 0:
        if (variable5 == 0xfb && eventId == 0x753a && done == 1 && anyDate == 0 && count == 0) {
            return 1;
        }
        break;
    case 1:
        if (variable5 == 0xfb && eventId == 0x753b && done == 1 && anyDate == 0 && count == 0) {
            return 1;
        }
        break;
    case 2:
        if ((unsigned)(variable5 - 0xf3) <= 2 && eventId == 0x753c && count == 1 && done == 1
            && anyDate == 0) {
            return 1;
        }
        break;
    case 3:
        if ((unsigned)(variable5 - 0xf3) <= 2 && eventId == 0x753d && count == 1 && done == 1
            && anyDate == 0) {
            return 1;
        }
        /* fall through */
    case 4:
        if (variable5 == 0x287 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 5:
        if (variable5 == 0x288 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 6:
        if (variable5 == 0x289 && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    case 7:
        if (variable5 == 0x1ec && done == 1 && anyDate == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Promoted out of src/pending: the callee SAVE_EVENT_AdvanceStage became a manifest
 * entry this pass, so the second call site resolves on `matched`.
 */
void SAVE_EVENT_CommitStage(void *gameData, u32 stage)
{
    SAVE_EVENT_AdvanceStage(POKE_TOOL_Dummy(gameData), stage);
}

/*
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 */
void SAVE_EVENT_AdvanceStage(struct SaveData *save, u32 stage)
{
    u32 savedFlag = POKE_TOOL_DecodeBoxParam(save);

    if (SAVE_EVENT_CheckStage(save, stage) == 1) {
        switch (stage) {
        case 0:
            POKE_TOOL_SetBoxValue(save, 0x96, 0x753B);
            break;
        case 2:
            POKE_TOOL_SetBoxValue(save, 0x96, 0x753D);
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam(save, savedFlag);
}

/*
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 80 bytes including its literal
 * pool. Witness for ov131 func_021D8784 (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */
unsigned int EVENT_ID_GetBank(unsigned int id) {
  if(id<0x7531) return 89;
  if(id<0x9c41) { if(id-0x7531>=14) return 89; return 92; }
  if(id<0xea61) { if(id-0x9c41>=109) return 89; return 90; }
  if(id<=65535) return 91;
  return 89;
}

/* The in-bank index half of the pair above (see EVENT_ID_GetBank); 84 bytes with its pool. */
unsigned int EVENT_ID_GetIndex(unsigned int id) {
  if(id<0x7531) { if(id>=117) return 2; }
  else if(id<0x9c41) { id-=0x7531; if(id>=14) return 2; }
  else if(id<0xea61) { id-=0x9c41; if(id>=109) return 2; }
  else { if(id<=65535) { id-=0xea61; if(id>=3) return 0; } else return 2; }
  return id;
}

/*
 * Twelve-byte tail forwarder (pool word and bx) to FILE_UTIL_Check12E4 with the
 * second argument; witness for ov131 P_STA_SKILL_HandleTouchForget (bl at +0x13A), whose
 * call supplies a pointer, a halfword and a second halfword.
 */
u32 EVENT_ID_Check(void *unused, u16 value, u16 unused2)
{
    return FILE_UTIL_Check12E4(value);
}

/* 1 when none of the four save variables 0x36 to 0x39 passes FILE_UTIL_Check12E4. */
int EVENT_ID_AreSlotsClear(struct SaveData *save, int unused)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (FILE_UTIL_Check12E4((u16)POKE_TOOL_GetBoxValue(save, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}

/*
 * An unlabelled tail-call leaf (it saves nothing, so disasm.py prints it as
 * .word data): APP_POWER_Main(0).  With APP_POWER_SetCallback it is the callback pair
 * GFL_USE_InitSystem (gfl_use.c boot) hands to BACKUP_SYSTEM_Init(7, ...).  Filed apart
 * from APP_POWER_SetCallback on purpose: the only pool words naming 0x0202F789 that
 * are outside a two-function range are each other's, so as one unit neither
 * site has a witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 */
void APP_POWER_ClearCallback(void)
{
    APP_POWER_Main(0);
}

/*
 * The second unlabelled tail-call leaf of the callback pair GFL_USE_InitSystem
 * hands to BACKUP_SYSTEM_Init: a flag mapped to mode 2 (clear) or 1 (set) for
 * APP_POWER_Main.  Filed apart from APP_POWER_ClearCallback so each pool word
 * witnesses the other.
 */
void APP_POWER_SetCallback(u32 on)
{
    u32 mode;

    if (on == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    APP_POWER_Main(mode);
}

/*
 * The power callback reached from APP_POWER_ClearCallback as APP_POWER_Main(0) (and
 * registered through the pool word 0x0202F789 at 0x0202F784).  It never
 * returns: after the shutdown work it spins on GFL_USE_PollPowerExit.
 */
void APP_POWER_Main(u32 mode)
{
    func_02007084();
    APP_POWER_ResetDisplay(mode);
    if (GFL_NET_GetRunState()) {
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        do {
            GFL_NET_Main();
        } while (!GFL_NET_IsSessionNull());
    }
    UI_ClearFlags39Global(2);
    for (;;)
        GFL_USE_PollPowerExit();
}

/*
 * The two calls to this packet's own followers (0x0202F870 at +0x7A and
 * 0x0202F940 at +0x80) are the only sites that need the `matched` class:
 * their compared range was their only `label` witness until those two files
 * existed.  Everything else is `label`.
 *
 * A display reset for the shutdown screen: two GXx_SetMasterBrightness_ writes of
 * 0xFFFFFFF0 to the master brightness registers of both engines, the engine
 * setup calls, then three read-modify-write pairs on the hardware registers
 * (DISPCNT: clear bits 8-12, set bit 9, then clear 0xE000; BG1CNT: clear all
 * but 0x43, set 4, then clear bit 6; BG1HOFS and BLDCNT zeroed), the two
 * packet-local sub-inits, and the brightness registers set again.
 *
 * Note the compiler derives BG1CNT and BG1HOFS from the pooled
 * master-brightness address with `subs r0, #0x62` / `#0x58`, and reuses the
 * value 4 in r6 as `lsls r0, r6, #0x18` for the DISPCNT base; both fall out
 * of writing the plain literals, so no symbol for the registers is needed.
 */
void APP_POWER_ResetDisplay(u32 messageId)
{
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_A, 0xFFFFFFF0);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_B, 0xFFFFFFF0);
    GX_HBlankIntr(0);
    GX_VBlankIntr(0);
    GX_ResetBankForBG();
    GX_ResetBankForSubBG();
    func_0207FDCC(4);
    GX_SetGraphicsMode(1, 0, 0);
    REG32(REG_DISPCNT_A) = (REG32(REG_DISPCNT_A) & 0xFFFFE0FF) | 0x200;
    REG32(REG_DISPCNT_A) = REG32(REG_DISPCNT_A) & 0xFFFF1FFF;
    REG16(REG_BG1CNT_A) = (REG16(REG_BG1CNT_A) & 0x43) | 4;
    REG16(REG_BG1CNT_A) = REG16(REG_BG1CNT_A) & 0xFFBF;
    REG32(REG_BG1HOFS_A) = 0;
    REG16(REG_BLDCNT_A) = 0;
    APP_POWER_LoadShutdownScreen();
    APP_POWER_DrawShutdownScreen(messageId);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_A, 0);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_B, 0x10);
}

/*
 * Three copies of one block: register a handle with ARC_UTIL_LoadMember(0x16, i, 0, 7),
 * probe it (NNS_G2dGetUnpackedCharacterDataEx / 02062B30 / 02062A98 with a stack out-pointer), and
 * on success clear 0x20 bytes of the record's buffer through DWCi_ScreenDC_FlushRange and
 * fill it back through MIi_CpuCopy16 with the current frame-tick from the
 * getter (G2_GetBG1CharPtr / G2_GetBG1ScrPtr).  The handle is released with
 * func_020307B0 after each block.
 *
 * The idiom that makes this EXACT: the word each block reads twice (size of
 * the character data, size of the screen data) is written as an ASSIGNMENT
 * INSIDE the third argument of the second call --
 * `MIi_CpuCopy16(chars[5], getter(), charSize = chars[4])`.  mwcc evaluates
 * the arguments of a call right-to-left, so the assignment's load lands
 * before the getter call, and the value it produces is live across that
 * call, which is what puts it in r5 and forces the original's
 * `push {r3, r4, r5, lr}` frame.  Spelling the same value as a statement
 * before the call puts the load one statement early; spelling it inline in
 * both calls leaves the load where it is scheduled and loses r5 (6 bytes
 * short).  See docs/idioms/
 * an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md
 *
 * Archive 0x16 members 1, 2 and 0 are the character data, screen data and
 * palette of the shutdown screen.
 */
void APP_POWER_LoadShutdownScreen(void)
{
    u32 *chars;
    u32 *screen;
    u32 *palette;
    u32 *paletteHeader;
    u32 res;
    u32 charSize;
    u32 screenSize;

    func_02082A7C(0, (u32)G2_GetBG1CharPtr(), 0x4000);
    res = ARC_UTIL_LoadMember(0x16, 1, 0, 7);
    if (NNS_G2dGetUnpackedCharacterDataEx((struct ArchiveRecord *)res, (void **)(&chars)) != 0) {
        DWCi_ScreenDC_FlushRange(chars[5], chars[4]);
        MIi_CpuCopy16(chars[5], (u32)G2_GetBG1CharPtr(), charSize = chars[4]);
    }
    func_020307B0((void *)res);
    res = ARC_UTIL_LoadMember(0x16, 2, 0, 7);
    if (NNS_G2dGetUnpackedScreenData((void *)res, (void **)(&screen)) != 0) {
        DWCi_ScreenDC_FlushRange((u32)screen + 0xc, screen[2]);
        MIi_CpuCopy16((u32)screen + 0xc, (u32)G2_GetBG1ScrPtr(), screenSize = screen[2]);
    }
    func_020307B0((void *)res);
    res = ARC_UTIL_LoadMember(0x16, 0, 0, 7);
    NNS_G2dGetUnpackedPaletteCompressInfo((struct ArchiveRecord *)res, (void **)(&paletteHeader));
    if (NNS_G2dGetUnpackedPaletteData((struct ArchiveRecord *)res, (void **)(&palette)) != 0) {
        DWCi_ScreenDC_FlushRange(palette[3], 0x20);
        MIi_CpuCopy16(palette[3], 0x05000000, 0x20);
    }
    func_020307B0((void *)res);
}

/*
 * EXACT* -- the inferred extent (184 bytes) runs 4 bytes past this
 * function's own 180, over the unlabelled 4-byte leaf at 0x0202F9F4
 * (`movs r0, #1; bx lr`, i.e. `return 1;`), which saves no lr and so gets no
 * label from disasm.py -- docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is worth seeding
 * into layout/function_starts.txt by the integrator; it is not ours to edit.
 * The follower is also not covered by the manifest entry below, and no `tu`
 * range may span it.
 *
 * Fills the tilemap of the shutdown screen with consecutive tile numbers,
 * then draws message `messageId` of message bank 2 into a 30x16 tile bitmap.
 */
void APP_POWER_DrawShutdownScreen(u32 messageId)
{
    u16 *tilemap;
    s32 column;
    s32 row;
    u16 tile;
    struct Bmp *bmp;
    struct GfFont *font;
    struct MsgBank *msgBank;
    struct Strbuf *message;

    tilemap = (u16 *)G2_GetBG1ScrPtr();
    tile = 0x20;
    for (row = 4; row < 0x14; row++) {
        for (column = 1; column < 0x1f; column++) {
            tilemap[(row << 5) + column] = tile;
            tile = tile + 1;
        }
    }
    MIi_CpuClear16(0x7777, (u32)G2_GetBG1CharPtr() + 0x400, 0x3C00);
    bmp = BMP_CreateFromVram((void *)((u32)G2_GetBG1CharPtr() + 0x400), 0x1e, 0x10, 0x20, 7);
    font = GF_FONT_Create(0x17, 0, 0, 0, 7);
    msgBank = func_02045B38(0, 2, 2, 7);
    message = func_02045EC0(msgBank, messageId);
    PRINTSYS_PrintColor(bmp, 0, 0, message, font, 0x1167);
    STRBUF_Delete(message);
    MSGDATA_Delete(msgBank);
    GF_FONT_Delete(font);
    BMP_Delete(bmp);
}

int APP_POWER_IsSupported(void)
{
    return 1;
}

/*
 * wave 17 (overlay_id class): EXACT. The pooled overlay-id sites ov088_id
 * (88) and ov179_id (179) resolve as `overlay_id` (a layout overlay index,
 * loaded by a pc-relative load of this function, reaching the id register
 * of a known overlay loader), which was the last blocker.
 *
 * A five-state proc driver, the net_save.c shape of
 * src/pending/GFL_NET_SAVE_Main.c: state 0 starts overlay 0x58's proc on
 * &sOverlayLaunchWork.mode, states 1 to 3 (re)start overlay 0xB3's proc on
 * the work block, with state 2 bailing to 4 when `aborted` is set, and
 * state 4 starts overlay 0x58's second proc and resets to 0.
 *
 * Two pool words both name 0x02146948 (0x0202FA9C, the base of the field
 * stores, and 0x0202FAA8, the third call argument).  mwcc merges pool words
 * per symbol and CSEs the loaded address, so one symbol gives one word and
 * reuses r2 as the store base (184 -> 172 bytes, 98 out).  Two symbols at
 * the same address reproduce both words; sOverlayLaunchWorkArg is that
 * second name.  The state-2 test is written with the work in the `if` and
 * the bail-out after it (fall-through arm is the source order), so its
 * `*state = 4` block is the one state 3 branches back into.
 */
int OVERLAY_LAUNCH_Driver(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        PROCSYS_PushGlobal((u32)ov088_id, (u32)d_021BD8E8, (u32)&sOverlayLaunchWork.mode);
        *state = 1;
        break;
    case 1:
        sOverlayLaunchWork.mode = 1;
        sOverlayLaunchWork.stage = 0;
        sOverlayLaunchWork.enabled = 1;
        sOverlayLaunchWork.aborted = 0;
        PROCSYS_PushGlobal((u32)ov179_id, (u32)d_021B68D8, (u32)sOverlayLaunchWorkArg);
        *state = 2;
        break;
    case 2:
        if (sOverlayLaunchWork.aborted == 0) {
            sOverlayLaunchWork.stage = 1;
            sOverlayLaunchWork.aborted = 0;
            PROCSYS_PushGlobal((u32)ov179_id, (u32)d_021B68D8, (u32)sOverlayLaunchWorkArg);
            *state = 3;
            break;
        }
        *state = 4;
        break;
    case 3:
        sOverlayLaunchWork.stage = 2;
        sOverlayLaunchWork.aborted = 0;
        PROCSYS_PushGlobal((u32)ov179_id, (u32)d_021B68D8, (u32)sOverlayLaunchWorkArg);
        *state = 4;
        break;
    case 4:
        PROCSYS_PushGlobal((u32)ov088_id, (u32)d_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}

int APP_POWER_IsReady(void)
{
    return 1;
}
