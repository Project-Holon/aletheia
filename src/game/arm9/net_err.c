/*
 * file:     net_err.c
 * unit:     yes
 * function: GFL_NET_SetBgmTrackVolumeUnlessVoiceChat, GFL_NET_ERR_CreateHeap, GFL_NET_ERR_Init, GFL_NET_ERR_DetectNetError, GFL_NET_ERR_ShowScreen, GFL_NET_ERR_HaltWithMessage, GFL_NET_ERR_Halt, GFL_NET_ERR_SetKeepDark, GFL_NET_ERR_ClearKeepDark, GFL_NET_ERR_RestoreBrightness, GFL_NET_ERR_UpdateNetwork, GFL_NET_ERR_ShowSimpleScreen, GFL_NET_ERR_HaltIfActive, GFL_NET_ERR_DrawAndHang, GFL_NET_ERR_RecordError, GFL_NET_ERR_GetErrorLevel, GFL_NET_ERR_RequestScreen, GFL_NET_ERR_RaiseFatal, GFL_NET_ERR_ExitAndHalt, GFL_NET_ERR_ResetState, GFL_NET_ERR_WaitLinkClosed, GFL_NET_ERR_ProcScreen, GFL_NET_ERR_SaveDisplayAndDraw, GFL_NET_ERR_RestoreDisplay, GFL_NET_ERR_IsActive, GFL_NET_ERR_LoadScreenGraphics, GFL_NET_ERR_GetMessageId, GFL_NET_ERR_DrawWindow
 * address:  0x0200F698
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from net_err.c by tools/splitfile.py.
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   DWC_RAP_GetVchatEnabled  0x02156B70  thumb  ov009
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   MI_CpuFill8       0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_CheckError  0x0203D880  arm
 *   GFL_NET_SYSTEM_IsError  0x020393D0  arm
 *   GFL_NET_STATE_GetErrorMode  0x0203C990  arm
 *   GFL_NET_ClearBeaconCallbacks  0x0203D864  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   DWC_RAP_GetErrorMessageClass  0x02156460  thumb  ov009
 *   GFL_USE_StopAllSe        0x02006210  thumb
 *   GX_VBlankIntr        0x0207D3E4  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOn        0x02037174  arm
 *   GFL_NET_WM_ICON_EasyGetEngine        0x02037200  arm
 *   WIH_DWC_PollSystem        0x0201034C  thumb
 *   GFL_NET_WM_ICON_EasyObjWindowOff        0x02037190  arm
 *   GXS_SetGraphicsMode  0x0207D518  arm
 *   UI_ClearSoftResetInhibitGlobal  0x020351A0  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   WIH_GetSysState  0x02178E4C  thumb
 *   GFL_NET_RequestDisconnect  0x0203CFA0  arm
 *   GX_HBlankIntr  0x0207D3AC  arm
 *   GFL_NET_ERR_DrawWindow  0x020101D4  thumb
 *   GXx_GetMasterBrightness_  0x0207D55C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GX_ResetBankForBG             0x020808F4  arm
 *   GX_ResetBankForSubBG             0x020809A0  arm
 *   GX_SetBankForBG           0x0207FDCC  arm
 *   GX_SetGraphicsMode        0x0207D4B0  arm
 *   G2_GetBG1CharPtr          0x0207E24C  arm
 *   G2_GetBG1ScrPtr           0x0207DFB4  arm
 *   MIi_CpuCopy16             0x02082A60  arm
 *   BG_SYS_GetSubVisiblePlanes             0x02043668  arm
 *   BG_SYS_SetSubVisiblePlanes             0x020435F4  arm
 *   GFL_NET_GetIrcParams             0x0203D828  arm
 *   GX_SetBankForSubBG        0x020806B0  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   DC_FlushRange  0x020862F0  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   gNetErrWork       0x0214617C  data
 *   sNetErrScreenRes  0x0209DEA0  data
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   sNetErrMessageIdsDS   0x0209DEB0  data
 *   sNetErrMessageIdsTwl   0x0209DED0  data
 *   MIi_CpuClear16    0x02082A48  arm
 *   BMP_CreateFromVram     0x02043754  arm
 *   WORDSET_CreateDefault     0x0201EC64  thumb
 *   GF_FONT_Create     0x0201D7EC  thumb
 *   MSGDATA_CreateFromArchive     0x02045B38  arm
 *   WORDSET_SetSlotNumber     0x0201EFA4  thumb
 *   MSGDATA_AllocString     0x02045EC0  arm
 *   STRBUF_Create     0x020457B0  arm
 *   WORDSET_CopyTaggedText     0x0201F250  thumb
 *   PRINTSYS_PrintColor     0x0201C7D0  thumb
 *   MSGDATA_Delete     0x02045C04  arm
 *   GF_FONT_Delete     0x0201D83C  thumb
 *   WORDSET_Delete     0x0201ED04  thumb
 *   BMP_Delete     0x020437AC  arm
 */
#include "wifi_friend_shared_types.h"

#define reg_GX_DISPCNT      (*(volatile u32 *)0x04000000)

#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)0x04001000)

#define reg_G2_WINOUT       (*(volatile u16 *)0x0400004A)

#define reg_G2S_DB_WINOUT   (*(volatile u16 *)0x0400104A)

#define reg_PAD_KEYINPUT    (*(volatile u16 *)0x04000130)

#define HW_BUTTON_XY_BUF    (*(volatile u16 *)0x02FFFFA8)

#define reg_GX_MASTER_BRIGHT   (*(volatile u16 *)0x0400006C)

#define reg_GXS_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)

#define reg_G2_BG1CNT          (*(volatile u16 *)0x0400000A)

#define reg_G2_BG1OFS          (*(volatile u32 *)0x04000014)

#define reg_G2_BLDCNT          (*(volatile u16 *)0x04000050)

#define reg_G2S_DB_BLDCNT      (*(volatile u16 *)0x04001050)

#define HW_BG_PLTT             0x05000000

#define HW_DB_BG_PLTT          0x05000400

/* net_err.c states (NetErrWork.state). */
#define NET_ERR_STATE_IDLE      0   /* no error recorded */

#define NET_ERR_STATE_RECORDED  1   /* error info captured, screen not requested yet */

#define NET_ERR_STATE_SHOW      2   /* the error screen is to be shown */

/* GFLNetInitializeStruct.bNetType values. */
#define GFL_NET_TYPE_WIFI         1

#define GFL_NET_TYPE_WIFI_LOBBY   2

#define GFL_NET_TYPE_WIFI_GTS     6

#define GFL_NET_TYPE_WIRELESS     0

#define GFL_NET_TYPE_IRC          5

/* NetErrWork.netType value when the VRAM backup was not taken (fatal error). */
#define NET_ERR_NETTYPE_NO_BACKUP  0x60

#define NET_ERR_HEAP_ID           8

#define NET_ERR_HEAP_PARENT_ID    1

#define NET_ERR_HEAP_SIZE         0x4920

#define NET_ERR_BG1_CHAR_SIZE     0x4000

#define NET_ERR_BG1_SCR_SIZE      0x800

#define NET_ERR_PLTT_BACKUP_SIZE  0x20

#define NET_ERR_BACKDROP_COLOR    0x7eea

struct NitroResFile;

typedef signed short   s16;

typedef unsigned short u16;

typedef int            BOOL;

typedef union {
    u32 raw;
    struct {
        u32 bgMode:3;
        u32 bg0_2d3d:1;
        u32 objMapChar:1;
        u32 objMapBmp:2;
        u32 blankScr:1;
        u32 visiblePlane:5;
        u32 visibleWnd:3;
        u32 dispMode:4;
        u32 extObjMapChar:2;
        u32 extObjMapBmp:1;
        u32 hBlankObjProc:1;
        u32 bgCharOffset:3;
        u32 bgScrOffset:3;
        u32 bgExtPltt:1;
        u32 objExtPltt:1;
    };
} GXDispCnt;

typedef union {
    u16 raw;
    struct {
        u16 priority:2;
        u16 charBase:4;
        u16 mosaic:1;
        u16 colorMode:1;
        u16 screenBase:5;
        u16 bgExtPltt:1;
        u16 screenSize:2;
    };
} GXBg01Control;

/* The part of the net init parameters (GFL_NET_GetInitParam) this file reads. */
typedef struct {
    u8 pad_00[0x65];
    u8 bNetType;
} GFLNetInitializeStruct;

/* The error record the net library keeps (GFL_NET_STATE_GetError returns it). */
typedef struct {
    u32 errorCode;
    u32 errorType;
    u32 errorParam;
    u32 reasonCode;
} NetErrInfo;

/* The module's state at 0x0214617C (size 0x64): backup of the display state
 * the error screen overwrites, plus the recorded error. */
typedef struct {
    void          *bg1CharBackup;       /* +0x00, NET_ERR_BG1_CHAR_SIZE bytes */
    void          *bg1ScrBackup;        /* +0x04, NET_ERR_BG1_SCR_SIZE bytes */
    void          *plttBackup;          /* +0x08, first NET_ERR_PLTT_BACKUP_SIZE bytes of the BG palette */
    GXDispCnt      savedDispCnt;        /* +0x0C */
    GXBg01Control  savedBg1Cnt;         /* +0x10 */
    u16            pad12;
    int            savedBright;         /* +0x14 */
    int            savedSubBright;      /* +0x18 */
    BOOL           savedHBlankIntr;     /* +0x1C */
    BOOL           savedVBlankIntr;     /* +0x20 */
    u32            savedBankBG;         /* +0x24 */
    u32            savedBankSubBG;      /* +0x28 */
    u32            state;               /* +0x2C, NET_ERR_STATE_* */
    u32            screenRequested;     /* +0x30, cleared when the screen was shown */
    u16            savedBldCnt;         /* +0x34 */
    u16            savedSubBldCnt;      /* +0x36 */
    u32            savedVisiblePlane;   /* +0x38 */
    int            savedSubVisibleWnd;  /* +0x3C */
    u16            savedSubBackdrop;    /* +0x40 */
    u16            pad42;
    u32            keepDarkOnRestore;   /* +0x44 */
    NetErrInfo     errorInfo;           /* +0x48 */
    u8             netErrorFlag;        /* +0x58 */
    u8             netType;             /* +0x59, bNetType at the time of the error */
    u8             fatalRaised;         /* +0x5A */
    u8             pad5B;
    u32            errorLevel;          /* +0x5C, 1 or 2 */
    u32            messageId;           /* +0x60 */
} NetErrWork;

typedef struct {
    u8 planeMask:5;
    u8 effect:1;
    u8 _reserve:2;
} GXWndPlane;

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;

typedef enum { GX_BG_COLORMODE_16 = 0 } GXBGColorMode;

typedef enum { GX_BG_SCRBASE_0x0000 = 0 } GXBGScrBase;

typedef enum { GX_BG_CHARBASE_0x00000 = 0 } GXBGCharBase;

typedef enum { GX_BG_EXTPLTT_01 = 0 } GXBGExtPltt;

/* One row of the error screen graphics table: the archive and the three files in it. */
struct NetErrScreenRes {
    u16 arcId;
    u16 charFileId;
    u16 scrnFileId;
    u16 plttFileId;
};

/* The unpacked character, screen and palette data of a Nitro graphics file. */
struct NitroCharData {
    u8  header[0x10];
    u32 size;
    void *pixels;
};

struct NitroScrnData {
    u32 header0;
    u32 header4;
    u32 size;
    u8  data[4];
};

struct NitroPlttData {
    u8  header[0xc];
    void *colors;
};

typedef signed int     s32;
struct Strbuf;

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern u32  GFL_NET_IsNetTypeWifi(void);

extern s16 DWC_RAP_GetVchatEnabled(void);

extern void GFL_USE_SetBgmTrackVolume(u32 eventMask, u32 eventValue);

extern void GFL_HEAP_CreateChildHeap(u32 parentHeapId, u32 heapId, u32 size);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern u32 GFL_HEAP_Alloc(u16 heapId, u32 size, u32 clearFlag, const void *file, u8 line);

extern int GFL_NET_GetRunState(void);

extern u32  GFL_NET_CheckError(void);

extern int GFL_NET_SYSTEM_IsError(void);

extern u32  GFL_NET_STATE_GetErrorMode(void);

extern void GFL_NET_ClearBeaconCallbacks(void);

extern GFLNetInitializeStruct *GFL_NET_GetInitParam(void);

extern NetErrInfo *GFL_NET_STATE_GetError(void);

extern int DWC_RAP_GetErrorMessageClass(int errorCode, int errorType);

extern u32 GFL_NET_Main();

extern void OS_WaitIrq(int clear, u32 irqFlags);

extern void GFL_USE_StopAllSe(void);

extern BOOL GX_VBlankIntr(BOOL on);

extern void GFL_NET_WM_ICON_EasyObjWindowOn(void);

extern u32 GFL_NET_WM_ICON_EasyGetEngine(void);

extern int WIH_DWC_PollSystem(void);

extern void GFL_NET_WM_ICON_EasyObjWindowOff(void);

extern void GXS_SetGraphicsMode(u32 bgMode);

extern void UI_ClearSoftResetInhibitGlobal(u32 mode);

extern void GFL_USE_PollPowerExit(void);

extern int   GFL_NET_IsSessionNull(void);

extern u32 GFL_HEAP_Free(void *block);

extern void GFL_HEAP_DeleteChecked(u32 heapId);

extern void GFL_NET_ClearExitFlag(void);

extern int GFL_NET_Exit(int arg);

extern void GFL_NET_IRC_WIRELESS_Exit(void);

extern s32 WIH_GetSysState(void);

extern void GFL_NET_RequestDisconnect(void);

extern s32 GX_HBlankIntr(BOOL on);

extern void GFL_NET_ERR_DrawWindow(u32 screenIndex, u32 isWifiLink);

extern int  GXx_GetMasterBrightness_(volatile u16 *reg);

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

extern int GX_ResetBankForBG(void);

extern int GX_ResetBankForSubBG(void);

extern void GX_SetBankForBG(s32 bg);

extern void GX_SetGraphicsMode(s32 dispMode, s32 bgMode, s32 bg0_2d3d);

extern void *G2_GetBG1CharPtr(void);

extern void *G2_GetBG1ScrPtr(void);

extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);

extern u32  BG_SYS_GetSubVisiblePlanes(void);

extern void BG_SYS_SetSubVisiblePlanes(u32 visiblePlane);

extern void GFL_NET_GetIrcParams(u32 *x, u32 *y);

extern void GX_SetBankForSubBG(s32 sub_bg);

extern void MIi_CpuClear32(u32 value, void *dst, u32 size);

extern int ARC_UTIL_LoadMember(s32 archiveID, s32 memberIdx, s32 decompress, u16 heapID);
struct NitroFileHeader;

extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);

extern void DC_FlushRange(void *p, u32 size);

extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);

extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);

extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);

void GFL_NET_SetBgmTrackVolumeUnlessVoiceChat(void *eventMask, void *eventValue);

void GFL_NET_ERR_CreateHeap(void);

void GFL_NET_ERR_Init(u32 heapId);

void GFL_NET_ERR_DetectNetError(void);

u32 GFL_NET_ERR_ShowScreen(u32 isFatal);

void GFL_NET_ERR_HaltWithMessage(u32 messageId);

void GFL_NET_ERR_Halt(void);

void GFL_NET_ERR_SetKeepDark(u32 keepDark);

void GFL_NET_ERR_ClearKeepDark(void);

void GFL_NET_ERR_RestoreBrightness(void);

void GFL_NET_ERR_UpdateNetwork(void);

void GFL_NET_ERR_ShowSimpleScreen(void);

void GFL_NET_ERR_HaltIfActive(void);

void GFL_NET_ERR_DrawAndHang(void);

void GFL_NET_ERR_RecordError(void);

u32 GFL_NET_ERR_GetErrorLevel(void);

void GFL_NET_ERR_RequestScreen(void);

void GFL_NET_ERR_RaiseFatal(unsigned int messageId);

void GFL_NET_ERR_ExitAndHalt(void);

void GFL_NET_ERR_ResetState(void);

u32 GFL_NET_ERR_WaitLinkClosed(void);

u32 GFL_NET_ERR_ProcScreen(u32 isFatal);

void GFL_NET_ERR_SaveDisplayAndDraw(u32 screenIndex, u32 isWifiLink);

void GFL_NET_ERR_RestoreDisplay(BOOL keepDark);

BOOL GFL_NET_ERR_IsActive(void);

void GFL_NET_ERR_LoadScreenGraphics(u32 screenIndex);

extern NetErrWork gNetErrWork;

extern struct NetErrScreenRes sNetErrScreenRes[];

extern u32 APP_ENV_IsRunOnTwl(void);

extern const u16 sNetErrMessageIdsDS[];

extern const u16 sNetErrMessageIdsTwl[];

struct Bmp;

struct WordSet;

struct MsgBank;

struct GfFont;

extern void MIi_CpuClear16(u16 data, void *dst, u32 size);

extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heap);

extern struct WordSet *WORDSET_CreateDefault(u16 heapId);

extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 padding, u32 flag);

extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);

extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);

extern u32 MSGDATA_Delete(struct MsgBank *bank);

extern u32 GF_FONT_Delete(struct GfFont *font);

extern u32 WORDSET_Delete(struct WordSet *wordSet);

extern void BMP_Delete(struct Bmp *bmp);

u32 GFL_NET_ERR_GetMessageId(NetErrInfo *info, u32 a);

#define GFL_NET_ERR_IS_ACTIVE()  GFL_NET_ERR_IsActive()

/*
 * Forwards its two arguments to GFL_USE_SetBgmTrackVolume unless both GFL_NET_IsNetTypeWifi()
 * and DWC_RAP_GetVchatEnabled() report nonzero; DWC_RAP_GetVchatEnabled is only called when
 * GFL_NET_IsNetTypeWifi reports zero.
 */
void GFL_NET_SetBgmTrackVolumeUnlessVoiceChat(void *eventMask, void *eventValue)
{
    if (GFL_NET_IsNetTypeWifi() == 0 || DWC_RAP_GetVchatEnabled() == 0) {
        GFL_USE_SetBgmTrackVolume((u32)eventMask, (u32)eventValue);
    }
}

/* Create the module heap and clear the work. */
void GFL_NET_ERR_CreateHeap(void)
{
    GFL_HEAP_CreateChildHeap(NET_ERR_HEAP_PARENT_ID, NET_ERR_HEAP_ID, NET_ERR_HEAP_SIZE);
    MI_CpuFill8(&gNetErrWork, 0, sizeof(NetErrWork));
}

/* Clear the work, then allocate the three backup buffers from heapId. */
void GFL_NET_ERR_Init(u32 heapId)
{
    NetErrWork *work = &gNetErrWork;
    /* stand-in: a named extern for this string changes the literal pool layout */
    const void *srcFile = (const void *)0x020A7234;

    MI_CpuFill8(work, 0, sizeof(NetErrWork));

    work->bg1CharBackup = (void *)GFL_HEAP_Alloc((u16)heapId, NET_ERR_BG1_CHAR_SIZE, 0, srcFile, 0xbb);
    work->bg1ScrBackup = (void *)GFL_HEAP_Alloc((u16)heapId, NET_ERR_BG1_SCR_SIZE, 0, srcFile, 0xbc);
    work->plttBackup = (void *)GFL_HEAP_Alloc((u16)heapId, NET_ERR_PLTT_BACKUP_SIZE, 0, srcFile, 0xbd);
}

/*
 * Poll for a network error and record it: bails out when an error is already
 * pending (state set), when GFL_NET_GetRunState does not report state 1, or when
 * none of three error probes says yes. Otherwise it captures the error
 * (GFL_NET_ERR_RecordError), requires a Wi-Fi net type (1, 2 or 6), and picks the
 * message id: fixed ids 0x28 and 0xe for two reason code windows, otherwise
 * the mapping DWC_RAP_GetErrorMessageClass(errorCode, errorType).
 */
void GFL_NET_ERR_DetectNetError(void)
{
    /* stand-in: with &gNetErrWork the compiler materialises the pool word differently */
    NetErrWork *work = (NetErrWork *)0x0214617C;

    if (work->state != 0) {
        return;
    }
    if (GFL_NET_GetRunState() != 1) {
        return;
    }
    if (GFL_NET_CheckError() == 0 && GFL_NET_SYSTEM_IsError() == 0 && GFL_NET_STATE_GetErrorMode() == 0) {
        return;
    }

    GFL_NET_ClearBeaconCallbacks();
    GFL_NET_ERR_RecordError();

    {
        GFLNetInitializeStruct *netInit = GFL_NET_GetInitParam();
        u8 netType = netInit->bNetType;
        if (netType != GFL_NET_TYPE_WIFI && netType != GFL_NET_TYPE_WIFI_LOBBY && netType != GFL_NET_TYPE_WIFI_GTS) {
            return;
        }
    }

    {
        NetErrInfo *errorInfo = GFL_NET_STATE_GetError();
        u32 reasonCode = errorInfo->reasonCode;

        if (reasonCode - 0x3f0 <= 1) {
            work->messageId = 0x28;
            return;
        }
        if (reasonCode - 0x3f2 <= 4) {
            work->messageId = 0xe;
            return;
        }

        work->messageId = DWC_RAP_GetErrorMessageClass(errorInfo->errorCode, errorInfo->errorType);
    }
}

/* Tail call into the error screen; isFatal 1 halts. */
u32 GFL_NET_ERR_ShowScreen(u32 isFatal)
{
    return GFL_NET_ERR_ProcScreen(isFatal);
}

/* Store messageId, mark a fatal error and show the error screen (halts). */
void GFL_NET_ERR_HaltWithMessage(u32 messageId)
{
    gNetErrWork.messageId = messageId;
    gNetErrWork.fatalRaised = 1;
    gNetErrWork.netType = 1;
    GFL_NET_ERR_ShowScreen(1);
}

/* Show the error screen as fatal (halts). */
void GFL_NET_ERR_Halt(void)
{
    GFL_NET_ERR_ShowScreen(1);
}

/* Set keepDarkOnRestore: 1 leaves the screens dark after the error screen. */
void GFL_NET_ERR_SetKeepDark(u32 keepDark)
{
    gNetErrWork.keepDarkOnRestore = keepDark;
}

void GFL_NET_ERR_ClearKeepDark(void)
{
    GFL_NET_ERR_SetKeepDark(0);
}

/* Write the saved master brightness back to both engines. */
void GFL_NET_ERR_RestoreBrightness(void)
{
    NetErrWork *work = &gNetErrWork;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, work->savedBright);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, work->savedSubBright);
}

/* One network service step: when the link is up, run GFL_NET_Main and wait for the next V-blank. */
void GFL_NET_ERR_UpdateNetwork(void)
{
    if (GFL_NET_GetRunState() == 1) {
        GFL_NET_Main();
        OS_WaitIrq(1, 1);
    }
}

static inline GXDispCnt GXS_GetDispCnt(void)
{
    return *(volatile GXDispCnt *)&reg_GXS_DB_DISPCNT;
}

static inline GXWndPlane G2_GetWndOutsidePlane(void)
{
    return *(volatile GXWndPlane *)&reg_G2_WINOUT;
}

static inline GXWndPlane G2_GetWndOBJInsidePlane(void)
{
    return *(volatile GXWndPlane *)((u8 *)&reg_G2_WINOUT + 1);
}

static inline GXWndPlane G2S_GetWndOutsidePlane(void)
{
    return *(volatile GXWndPlane *)&reg_G2S_DB_WINOUT;
}

static inline GXWndPlane G2S_GetWndOBJInsidePlane(void)
{
    return *(volatile GXWndPlane *)((u8 *)&reg_G2S_DB_WINOUT + 1);
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    reg_G2_WINOUT = (u16)tmp;
}

static inline void G2_SetWndOBJInsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2_WINOUT & ~0x3F00) | (wnd << 8);
    if (effect) {
        tmp |= 0x2000;
    }
    reg_G2_WINOUT = (u16)tmp;
}

static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2S_DB_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}

static inline void G2S_SetWndOBJInsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2S_DB_WINOUT & ~0x3F00) | (wnd << 8);
    if (effect) {
        tmp |= 0x2000;
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}

static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1F00) | (plane << 8);
}

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1F00) | (plane << 8);
}

static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}

static inline BOOL PAD_DetectFold(void)
{
    return (BOOL)((HW_BUTTON_XY_BUF & 0x8000) >> 15);
}

static inline u16 PAD_Read(void)
{
    return (u16)(((reg_PAD_KEYINPUT | HW_BUTTON_XY_BUF) ^ 0x2FFF) & 0x2FFF);
}

/* Drop one direction of each opposing D-pad pair (bits 5/6 and 4/7 shifted). */
static inline u16 FilterOpposingDpad(u16 keys)
{
    return (u16)(keys & ~((keys & 0x40) << 1) & ~((keys & 0x20) >> 1));
}

/*
 * Simple error screen: snapshots the sub-engine DISPCNT and the WINOUT
 * outside / OBJ-window planes of both engines, blanks and redraws through
 * GFL_NET_ERR_SaveDisplayAndDraw, narrows the chosen engine's windowing to BG1+OBJ, waits for
 * A/B to be released and pressed (polling WIH_DWC_PollSystem and GFL_NET_ERR_UpdateNetwork per
 * frame), restores through GFL_NET_ERR_RestoreDisplay and puts the snapshotted window
 * state back on whichever engine GFL_NET_WM_ICON_EasyGetEngine now names.
 */
void GFL_NET_ERR_ShowSimpleScreen(void)
{
    GXDispCnt dispCnt = GXS_GetDispCnt();
    GXWndPlane outMain = G2_GetWndOutsidePlane();
    GXWndPlane outSub = G2S_GetWndOutsidePlane();
    GXWndPlane objMain = G2_GetWndOBJInsidePlane();
    GXWndPlane objSub = G2S_GetWndOBJInsidePlane();

    if (GFL_NET_ERR_IS_ACTIVE() == 0) {
        return;
    }
    GFL_USE_StopAllSe();
    GFL_NET_ERR_SaveDisplayAndDraw(0, 0);
    GX_VBlankIntr(1);
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (GFL_NET_WM_ICON_EasyGetEngine() == 1) {
        G2_SetWndOutsidePlane(2, 0);
        G2_SetWndOBJInsidePlane(0x10, 0);
        GX_SetVisibleWnd(4);
        GX_SetVisiblePlane(0x12);
    } else {
        G2S_SetWndOutsidePlane(2, 0);
        G2S_SetWndOBJInsidePlane(0x10, 0);
        GXS_SetVisibleWnd(4);
        GXS_SetVisiblePlane(0x12);
    }
    while (PAD_DetectFold() == 1 || (FilterOpposingDpad(PAD_Read()) & 3) != 0) {
        WIH_DWC_PollSystem();
        GFL_NET_ERR_UpdateNetwork();
    }
    while (PAD_DetectFold() == 1 || (FilterOpposingDpad(PAD_Read()) & 3) == 0) {
        WIH_DWC_PollSystem();
        GFL_NET_ERR_UpdateNetwork();
    }
    GFL_NET_ERR_RestoreDisplay(gNetErrWork.keepDarkOnRestore == 1);
    GFL_NET_WM_ICON_EasyObjWindowOff();
    if (GFL_NET_WM_ICON_EasyGetEngine() == 2) {
        GXS_SetGraphicsMode(dispCnt.bgMode);
        GXS_SetVisiblePlane(dispCnt.visiblePlane);
        GXS_SetVisibleWnd(dispCnt.visibleWnd);
        G2S_SetWndOutsidePlane(outSub.planeMask, outSub.effect);
        G2S_SetWndOBJInsidePlane(objSub.planeMask, objSub.effect);
    } else {
        G2_SetWndOutsidePlane(outMain.planeMask, outMain.effect);
        G2_SetWndOBJInsidePlane(objMain.planeMask, objMain.effect);
    }
}

/* When the module is active, draw the error screen and halt. */
void GFL_NET_ERR_HaltIfActive(void)
{
    if (GFL_NET_ERR_IS_ACTIVE() != 0) {
        GFL_NET_ERR_DrawAndHang();
    }
}

/* Fatal path: draw the screen in its no-backup style, call UI_ClearSoftResetInhibitGlobal(2), then spin forever. */
void GFL_NET_ERR_DrawAndHang(void)
{
    GFL_NET_ERR_SaveDisplayAndDraw(1, 0);
    UI_ClearSoftResetInhibitGlobal(2);
    for (;;) {
        GFL_USE_PollPowerExit();
    }
}

/*
 * Record the pending network error: if the module is active and idle, move to
 * NET_ERR_STATE_RECORDED, then (when GFL_NET_IsSessionNull reports 0) copy the net
 * type, the error record and the error flag into the work. Wi-Fi net types
 * (1, 2, 6) get errorLevel 2 when errorType is 1 or 2 and 1 otherwise; other
 * net types get 2.
 */
void GFL_NET_ERR_RecordError(void)
{
    NetErrWork *work = &gNetErrWork;
    u8 netType;

    if (GFL_NET_ERR_IS_ACTIVE() == 0) {
        return;
    }
    if (work->state != NET_ERR_STATE_IDLE) {
        return;
    }
    work->state = NET_ERR_STATE_RECORDED;
    if (GFL_NET_IsSessionNull() != 0) {
        return;
    }
    work->netType = GFL_NET_GetInitParam()->bNetType;
    work->errorInfo = *GFL_NET_STATE_GetError();
    work->netErrorFlag = (u8)GFL_NET_STATE_GetErrorMode();
    netType = work->netType;
    if (netType == GFL_NET_TYPE_WIFI || netType == GFL_NET_TYPE_WIFI_LOBBY || netType == GFL_NET_TYPE_WIFI_GTS) {
        if ((u32)(work->errorInfo.errorType - 1) <= 1) {
            work->errorLevel = 2;
        } else {
            work->errorLevel = 1;
        }
        return;
    }
    work->errorLevel = 2;
}

/* errorLevel of the recorded error; 0 when no error is recorded. */
u32 GFL_NET_ERR_GetErrorLevel(void)
{
    NetErrWork *work = &gNetErrWork;

    if (work->state != 0) {
        return work->errorLevel;
    }
    return 0;
}

/* Request the error screen for a recorded error: RECORDED -> SHOW. */
void GFL_NET_ERR_RequestScreen(void)
{
    if (gNetErrWork.state == NET_ERR_STATE_RECORDED) {
        gNetErrWork.state = NET_ERR_STATE_SHOW;
    }
}

/* Raise a fatal error with messageId (unless the screen is already requested) and request the screen. */
void GFL_NET_ERR_RaiseFatal(unsigned int messageId)
{
    if (gNetErrWork.state != NET_ERR_STATE_SHOW) {
        gNetErrWork.messageId = messageId;
        gNetErrWork.fatalRaised = 1;
        gNetErrWork.netType = 1;
        gNetErrWork.state = NET_ERR_STATE_SHOW;
    }
}

/*
 * Free the three backup buffers and the module heap, mark the netType as
 * "no backup" and show the error screen as fatal.
 */
void GFL_NET_ERR_ExitAndHalt(void)
{
    NetErrWork *work = &gNetErrWork;

    GFL_HEAP_Free(work->bg1CharBackup);
    GFL_HEAP_Free(work->bg1ScrBackup);
    GFL_HEAP_Free(work->plttBackup);
    GFL_HEAP_DeleteChecked(NET_ERR_HEAP_ID);

    gNetErrWork.netType = NET_ERR_NETTYPE_NO_BACKUP;

    GFL_NET_ERR_ShowScreen(1);
}

/* Reset the error state: no error recorded, no level. */
void GFL_NET_ERR_ResetState(void)
{
    gNetErrWork.state = NET_ERR_STATE_IDLE;
    gNetErrWork.errorLevel = 0;
}

/*
 * Wait for the link to close: returns 1 at once when GFL_NET_GetRunState reports 0.
 * Otherwise it resets the link counters, then polls GFL_NET_IsSessionNull once per
 * frame until it stops returning 0. For net type 0 or 5 each frame first asks
 * WIH_GetSysState and returns 0 on answer 0xa.
 */
u32 GFL_NET_ERR_WaitLinkClosed(void)
{
    GFLNetInitializeStruct *netInit;
    u32 waiting;

    if (GFL_NET_GetRunState() != 0) {
        netInit = (GFLNetInitializeStruct *)GFL_NET_GetInitParam();
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        waiting = 1;

        for (;;) {
            if (netInit != 0) {
                u8 netType = netInit->bNetType;
                if (netType == GFL_NET_TYPE_WIRELESS || netType == GFL_NET_TYPE_IRC) {
                    if (WIH_GetSysState() == 0xa) {
                        return 0;
                    }
                }
            }
            GFL_NET_RequestDisconnect();
            WIH_DWC_PollSystem();
            OS_WaitIrq(waiting, waiting);
            if (GFL_NET_IsSessionNull() == 0) {
                continue;
            }
            break;
        }
    }

    return 1;
}

/*
 * Blocking error screen: returns 0 unless the module is active and the state
 * is NET_ERR_STATE_SHOW. isFatal 1 halts at once. For a Wi-Fi net type it
 * saves the display and draws (GFL_NET_ERR_SaveDisplayAndDraw), waits for the link to close
 * (GFL_NET_ERR_WaitLinkClosed), then draws the message (GFL_NET_ERR_DrawWindow); otherwise it draws
 * with GFL_NET_ERR_SaveDisplayAndDraw only. It then waits for A/B to be released and pressed
 * again, restores the display and resets the state. The test on the state is a
 * wrapping if (the shared return 0 sits after the body), and the work is a
 * named local so the compiler reloads the pool word per access.
 */
u32 GFL_NET_ERR_ProcScreen(u32 isFatal)
{
    NetErrWork *work = &gNetErrWork;
    u32 isWifiLink;

    if (GFL_NET_ERR_IS_ACTIVE() == 0) {
        return 0;
    }
    if (isFatal == 1) {
        GFL_NET_ERR_DrawAndHang();
    }
    if (work->state == NET_ERR_STATE_SHOW) {
        isWifiLink = 0;
        {
            u8 netType = work->netType;
            if (netType == GFL_NET_TYPE_WIFI || netType == GFL_NET_TYPE_WIFI_LOBBY || netType == GFL_NET_TYPE_WIFI_GTS) {
                isWifiLink = 1;
            }
        }
        if (isWifiLink == 1) {
            GFL_NET_ERR_SaveDisplayAndDraw(isFatal, 1);
        }
        if (GFL_NET_ERR_WaitLinkClosed() == 0) {
            GFL_NET_ERR_DrawAndHang();
        }
        if (isWifiLink == 1) {
            work->savedHBlankIntr = GX_HBlankIntr(0);
            work->savedVBlankIntr = GX_VBlankIntr(0);
            GFL_NET_ERR_DrawWindow(isFatal, 0);
        } else {
            GFL_NET_ERR_SaveDisplayAndDraw(isFatal, 0);
        }
        while (PAD_DetectFold() == 1 || (FilterOpposingDpad(PAD_Read()) & 3) != 0) {
            WIH_DWC_PollSystem();
        }
        while (PAD_DetectFold() == 1 || (FilterOpposingDpad(PAD_Read()) & 3) == 0) {
            WIH_DWC_PollSystem();
        }
        GFL_NET_ERR_RestoreDisplay(0);
        GFL_NET_ERR_ResetState();
        work->screenRequested = 0;
    return 1;
    }
    return 0;
}

static inline int GXS_GetVisibleWnd(void)
{
    return (int)((reg_GXS_DB_DISPCNT & 0xE000) >> 13);
}

static inline GXBg01Control G2_GetBG1Control(void)
{
    return *(volatile GXBg01Control *)&reg_G2_BG1CNT;
}

static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                    GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    reg_G2_BG1CNT = (u16)((reg_G2_BG1CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) |
                          (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        reg_G2_BG1CNT |= 0x40;
    } else {
        reg_G2_BG1CNT &= ~0x40;
    }
}

/*
 * Save the display state into the work and blank the screens: both master
 * brightness levels, the H/V-blank interrupt enables (unless isWifiLink),
 * two VRAM bank states, DISPCNT, the sub window mask, BG1CNT, the blend
 * registers, the visible plane and the sub backdrop color. BG1 is reprogrammed
 * as a 16-colour text layer; its character data, screen data and the first
 * palette block are backed up unless netType is NET_ERR_NETTYPE_NO_BACKUP.
 * Then the error screen graphics are loaded (GFL_NET_ERR_LoadScreenGraphics) and the message
 * is drawn (GFL_NET_ERR_DrawWindow). The two backup copies read their buffer pointer
 * and the BG1 pointer getter into named locals, destination first, which
 * reproduces the original register pressure.
 */
void GFL_NET_ERR_SaveDisplayAndDraw(u32 screenIndex, u32 isWifiLink)
{
    NetErrWork *work = &gNetErrWork;

    if (GFL_NET_ERR_IS_ACTIVE() == 0) {
        return;
    }
    work->savedBright = GXx_GetMasterBrightness_(&reg_GX_MASTER_BRIGHT);
    work->savedSubBright = GXx_GetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    if (isWifiLink == 0) {
        work->savedHBlankIntr = GX_HBlankIntr(0);
        work->savedVBlankIntr = GX_VBlankIntr(0);
    }
    work->savedBankBG = GX_ResetBankForBG();
    work->savedBankSubBG = GX_ResetBankForSubBG();
    GX_SetBankForBG(4);
    work->savedDispCnt.raw = reg_GX_DISPCNT;
    GX_SetGraphicsMode(1, 0, 0);
    GX_SetVisiblePlane(2);
    GX_SetVisibleWnd(0);
    work->savedSubVisibleWnd = GXS_GetVisibleWnd();
    GXS_SetVisibleWnd(0);
    work->savedBg1Cnt = G2_GetBG1Control();
    G2_SetBG1Control(0, 0, 0, 1, work->savedBg1Cnt.bgExtPltt);
    G2_BG1Mosaic(0);
    reg_G2_BG1OFS = 0;
    if (work->netType != NET_ERR_NETTYPE_NO_BACKUP) {
        void *dst;
        void *src;
        dst = work->bg1CharBackup;
        src = G2_GetBG1CharPtr();
        MIi_CpuCopy16(src, dst, NET_ERR_BG1_CHAR_SIZE);
        dst = work->bg1ScrBackup;
        src = G2_GetBG1ScrPtr();
        MIi_CpuCopy16(src, dst, NET_ERR_BG1_SCR_SIZE);
        MIi_CpuCopy16((void *)HW_BG_PLTT, work->plttBackup, NET_ERR_PLTT_BACKUP_SIZE);
    }
    work->savedBldCnt = reg_G2_BLDCNT;
    work->savedBldCnt = reg_G2S_DB_BLDCNT; /* sic: stored over savedBldCnt again, as in the image */
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    work->savedVisiblePlane = BG_SYS_GetSubVisiblePlanes();
    BG_SYS_SetSubVisiblePlanes(0);
    work->savedSubBackdrop = *(volatile u16 *)HW_DB_BG_PLTT;
    *(volatile u16 *)HW_DB_BG_PLTT = NET_ERR_BACKDROP_COLOR;
    if (gNetErrWork.netType == NET_ERR_NETTYPE_NO_BACKUP) {
        GFL_NET_ERR_LoadScreenGraphics(1);
    } else {
        GFL_NET_ERR_LoadScreenGraphics(0);
        GFL_NET_ERR_DrawWindow(screenIndex, isWifiLink);
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
}

static inline void G2_SetBG1Offset(int hOffset, int vOffset)
{
    reg_G2_BG1OFS = (u32)(((hOffset << 0) & 0x1FF) | ((vOffset << 16) & 0x1FF0000));
}

/*
 * Restore the display state GFL_NET_ERR_SaveDisplayAndDraw saved. G2_SetBG1Control's
 * parameters are the SDK's enum types (GXBGScrSizeText, GXBGColorMode,
 * GXBGScrBase, GXBGCharBase, GXBGExtPltt), not int: with enums the compiler
 * materialises each bitfield argument into a temporary before the inline
 * body reads reg_G2_BG1CNT. keepDark leaves the master brightness at -16.
 */
void GFL_NET_ERR_RestoreDisplay(BOOL keepDark)
{
    NetErrWork *work = &gNetErrWork;
    u32 scrollX;
    u32 scrollY;

    if (GFL_NET_ERR_IS_ACTIVE() == 0) {
        return;
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    *(volatile u16 *)HW_DB_BG_PLTT = work->savedSubBackdrop;
    BG_SYS_SetSubVisiblePlanes(work->savedVisiblePlane);
    reg_G2_BLDCNT = work->savedBldCnt;
    reg_G2S_DB_BLDCNT = work->savedSubBldCnt;
    MIi_CpuCopy16(work->bg1CharBackup, G2_GetBG1CharPtr(), NET_ERR_BG1_CHAR_SIZE);
    MIi_CpuCopy16(work->bg1ScrBackup, G2_GetBG1ScrPtr(), NET_ERR_BG1_SCR_SIZE);
    MIi_CpuCopy16(work->plttBackup, (void *)HW_BG_PLTT, NET_ERR_PLTT_BACKUP_SIZE);
    G2_SetBG1Control(work->savedBg1Cnt.screenSize, work->savedBg1Cnt.colorMode, work->savedBg1Cnt.screenBase,
                     work->savedBg1Cnt.charBase, work->savedBg1Cnt.bgExtPltt);
    G2_BG1Mosaic(work->savedBg1Cnt.mosaic);
    GFL_NET_GetIrcParams(&scrollX, &scrollY);
    G2_SetBG1Offset(scrollX, scrollY);
    GX_SetGraphicsMode(work->savedDispCnt.dispMode, work->savedDispCnt.bgMode, work->savedDispCnt.bg0_2d3d);
    GX_SetVisiblePlane(work->savedDispCnt.visiblePlane);
    GX_SetVisibleWnd(work->savedDispCnt.visibleWnd);
    GXS_SetVisibleWnd(work->savedSubVisibleWnd);
    GX_ResetBankForSubBG();
    GX_ResetBankForBG();
    GX_SetBankForBG(work->savedBankBG);
    GX_SetBankForSubBG(work->savedBankSubBG);
    GX_HBlankIntr(work->savedHBlankIntr);
    GX_VBlankIntr(work->savedVBlankIntr);
    OS_WaitIrq(1, 1);
    if (keepDark == 0) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, work->savedBright);
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, work->savedSubBright);
    }
}

/* 1 once the module has its backup buffers (bg1CharBackup set). */
BOOL GFL_NET_ERR_IsActive(void)
{
    if (gNetErrWork.bg1CharBackup != 0) {
        return 1;
    }
    return 0;
}

/*
 * Load the error screen graphics of table row screenIndex: clear BG1's
 * character area, then unpack the character, screen and palette files of the
 * row, flush them and copy them to BG1's character data, screen data and the
 * start of the BG palette.
 */
void GFL_NET_ERR_LoadScreenGraphics(u32 screenIndex)
{
    void *file;
    struct NitroCharData *charData;
    struct NitroScrnData *scrnData;
    struct NitroPlttData *plttData;
    u32 unusedData;
    u16 arcId;

    MIi_CpuClear32(0, G2_GetBG1CharPtr(), NET_ERR_BG1_CHAR_SIZE);

    arcId = sNetErrScreenRes[screenIndex].arcId;
    file = (void *)ARC_UTIL_LoadMember(arcId, sNetErrScreenRes[screenIndex].charFileId, 0, 1);
    if (NNS_G2dGetUnpackedCharacterDataEx(file, (void **)(&charData)) != 0) {
        u32 size;
        void *dst;
        DC_FlushRange(charData->pixels, charData->size);
        size = charData->size;
        dst = G2_GetBG1CharPtr();
        MIi_CpuCopy16(charData->pixels, dst, size);
    }
    GFL_HEAP_Free(file);

    file = (void *)ARC_UTIL_LoadMember(arcId, sNetErrScreenRes[screenIndex].scrnFileId, 0, 1);
    if (NNS_G2dGetUnpackedScreenData(file, (void **)(&scrnData)) != 0) {
        u32 size;
        void *dst;
        DC_FlushRange(scrnData->data, scrnData->size);
        size = scrnData->size;
        dst = G2_GetBG1ScrPtr();
        MIi_CpuCopy16(scrnData->data, dst, size);
    }
    GFL_HEAP_Free(file);

    file = (void *)ARC_UTIL_LoadMember(arcId, sNetErrScreenRes[screenIndex].plttFileId, 0, 1);
    NNS_G2dGetUnpackedPaletteCompressInfo(file, (void **)(&unusedData));
    if (NNS_G2dGetUnpackedPaletteData(file, (void **)(&plttData)) != 0) {
        DC_FlushRange(plttData->colors, NET_ERR_PLTT_BACKUP_SIZE);
        MIi_CpuCopy16(plttData->colors, (void *)HW_BG_PLTT, NET_ERR_PLTT_BACKUP_SIZE);
    }
    GFL_HEAP_Free(file);
}

/*
 * net_err.c's error-code mapper: the reason code of the module's error block
 * (0x3EE..0x3F7) maps to a fixed message id; anything else indexes one of two
 * sixteen-entry u16 tables by the module's +0x60 error number, picked by
 * APP_ENV_IsRunOnTwl().  The case 0x3F7 arm shares case 0x3EE's block.
 */
u32 GFL_NET_ERR_GetMessageId(NetErrInfo *info, u32 a)
{
    u32 errorNumber;

    switch (info->reasonCode) {
    case 0x3ee:
    case 0x3f7:
        return 0xd;
    case 0x3f1:
        return 0x28;
    case 0x3f2:
    case 0x3f3:
    case 0x3f4:
    case 0x3f5:
    case 0x3f6:
        return 0xe;
    case 0x3f0:
        return 0x28;
    }
    if (APP_ENV_IsRunOnTwl() != 0) {
        errorNumber = gNetErrWork.messageId;
        if (errorNumber >= 0x10) {
            return 0xb;
        }
        return sNetErrMessageIdsTwl[errorNumber];
    }
    errorNumber = gNetErrWork.messageId;
    if (errorNumber >= 0x10) {
        return 0xb;
    }
    return sNetErrMessageIdsDS[errorNumber];
}

/*
 * Draws net_err.c's error window: tiles BG1's screen with a running character
 * index, clears the character block to 0x7777, builds a surface, a window
 * object and a palette, picks the message (0x40 for useGenericMessage == 1;
 * the mapped error code from GFL_NET_ERR_GetMessageId or the stored +0x60 code
 * in link modes 1/2/6; else message 1, or 0 unless messageVariant == 1),
 * prints it and frees everything.
 */
void GFL_NET_ERR_DrawWindow(u32 messageVariant, u32 useGenericMessage)
{
    NetErrWork *errWork = &gNetErrWork;
    u16 *screen;
    struct Bmp *bmp;
    struct WordSet *wordSet;
    s32 tileX;
    struct MsgBank *msgBank;
    u32 messageIndex;
    void *message;
    struct U16String *textBuf;
    s32 tileY;
    struct GfFont *font;
    u16 *bg1ScrPtr;
    u16 tileIndex;

    bg1ScrPtr = G2_GetBG1ScrPtr();
    screen = bg1ScrPtr;
    tileIndex = 0x20;
    for (tileY = 4; tileY < 0x14; tileY++) {
        for (tileX = 1; tileX < 0x1f; tileX++) {
            screen[tileY * 0x20 + tileX] = tileIndex;
            tileIndex = (u16)(tileIndex + 1);
        }
    }
    MIi_CpuClear16(0x7777, (u8 *)G2_GetBG1CharPtr() + 0x400, 0x3c00);
    bmp = BMP_CreateFromVram((u8 *)G2_GetBG1CharPtr() + 0x400, 0x1e, 0x10, 0x20, 1);
    wordSet = WORDSET_CreateDefault(1);
    font = GF_FONT_Create(0x17, 0, 0, 0, 1);

    if (useGenericMessage == 1) {
        msgBank = MSGDATA_CreateFromArchive(0, 2, 0xe8, 1);
        messageIndex = 0x40;
    } else {
        u8 netType = errWork->netType;

        if (netType == 1 || netType == 2 || netType == 6) {
            WORDSET_SetSlotNumber(wordSet, 0, errWork->errorInfo.errorCode, 5, 2, 1);
            msgBank = MSGDATA_CreateFromArchive(0, 2, 0xe8, 1);
            if (errWork->fatalRaised != 0) {
                messageIndex = errWork->messageId;
                errWork->fatalRaised = 0;
            } else {
                messageIndex = GFL_NET_ERR_GetMessageId(&errWork->errorInfo, errWork->messageId);
            }
        } else {
            WORDSET_SetSlotNumber(wordSet, 0, errWork->netErrorFlag, 5, 2, 1);
            msgBank = MSGDATA_CreateFromArchive(0, 2, 0x52, 1);
            messageIndex = 1;
            if (messageVariant != 1) {
                messageIndex = 0;
            }
        }
    }

    message = MSGDATA_AllocString(msgBank, messageIndex);
    textBuf = (struct U16String *)STRBUF_Create(0x189, 1);
    WORDSET_CopyTaggedText(wordSet, (struct Strbuf *)textBuf, message);
    PRINTSYS_PrintColor(bmp, 0, 0, (struct Strbuf *)textBuf, font, 0x1167);
    STRBUF_Delete((struct Strbuf *)textBuf);
    STRBUF_Delete(message);
    MSGDATA_Delete(msgBank);
    GF_FONT_Delete(font);
    WORDSET_Delete(wordSet);
    BMP_Delete(bmp);
}
