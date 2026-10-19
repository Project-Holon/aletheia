/*
 * file:     btlv_input.c
 * unit:     yes
 * function: BTLV_INPUT_CreateDefault, BTLV_INPUT_CreateWithMode, BTLV_INPUT_Create, BTLV_INPUT_Delete, BTLV_INPUT_UpdateInfoWindow, BTLV_INPUT_InfoWindowTask, BTLV_INPUT_LoadScreenResources, BTLV_INPUT_ReleaseScreenResources, BTLV_INPUT_InitBgLayers, BTLV_INPUT_ReleaseBgLayers, BTLV_INPUT_StartPaletteFadeTask, BTLV_INPUT_StartScreenFadeTask, BTLV_INPUT_IsScreenBusy, BTLV_INPUT_ChangeScreen, BTLV_INPUT_ProcessTouchInput, BTLV_INPUT_StepFingerDemo, BTLV_INPUT_ProcessKeyInput, BTLV_INPUT_IsInputBlocked, BTLV_INPUT_GetScreen, BTLV_INPUT_LoadCommonGraphics, BTLV_INPUT_ActionScreenOpenTask, BTLV_INPUT_WazaScreenOpenTask, BTLV_INPUT_WazaScreenOpenInstantTask, BTLV_INPUT_ActionScreenOpenInstantTask, BTLV_INPUT_TargetScreenOpenTask, BTLV_INPUT_WazaScreenCloseTask, BTLV_INPUT_WaitScreenOpenTask, BTLV_INPUT_WaitScreenOpenInstantTask, BTLV_INPUT_MessageScreenOpenTask, BTLV_INPUT_ListScreenOpenTask, BTLV_INPUT_SelectScreenOpenTask, BTLV_INPUT_ConfirmScreenOpenTask, BTLV_INPUT_ListScreenOpenInstantTask, BTLV_INPUT_ScreenResetTask, BTLV_INPUT_TaskEndClearBusyBit, BTLV_INPUT_StartBgScrollTask, BTLV_INPUT_BgScrollTaskMain, BTLV_INPUT_BgScrollTaskEnd, BTLV_INPUT_StartBgWipeTask, BTLV_INPUT_BgWipeTaskMain, BTLV_INPUT_BgWipeTaskEnd, BTLV_INPUT_StartPaletteCycleTask, BTLV_INPUT_PaletteCycleTaskMain, BTLV_INPUT_PaletteCycleTaskEnd, BTLV_INPUT_CreateCursorActors, BTLV_INPUT_CursorActorTaskMain, BTLV_INPUT_CursorActorTaskEnd, BTLV_INPUT_StartPaletteFlashTask, BTLV_INPUT_PaletteFlashTaskMain, BTLV_INPUT_PaletteFlashTaskEnd, BTLV_INPUT_StartBgScrollOffsetTask, BTLV_INPUT_BgScrollOffsetTaskMain, BTLV_INPUT_WaitFadeTaskMain, BTLV_INPUT_WaitFadeTaskEnd, BTLV_INPUT_CursorMoveTaskMain, BTLV_INPUT_CursorMoveTaskEnd, BTLV_INPUT_StartScreenTransition, BTLV_INPUT_VisibilityTaskMain, BTLV_INPUT_WindowOpenTaskMain, BTLV_INPUT_WindowCloseTaskMain, BTLV_INPUT_GetTextBlockSize, BTLV_INPUT_DrawWazaButtons, BTLV_INPUT_DrawTargetButtons, BTLV_INPUT_DrawMessageText, BTLV_INPUT_InitButtonState, BTLV_INPUT_DrawSelectScreenText, BTLV_INPUT_ClearButtonState, BTLV_INPUT_GetPpTextColor, BTLV_INPUT_CreateActionButtons, BTLV_INPUT_DeleteActionButtonActors, BTLV_INPUT_SetActionUnitVisible, BTLV_INPUT_CreateStatusIcons, BTLV_INPUT_DeleteStatusIcons, BTLV_INPUT_CreateWazaCursorActors, BTLV_INPUT_DeleteWazaCursorActors, BTLV_INPUT_CreateTargetActors, BTLV_INPUT_DeleteTargetActors, BTLV_INPUT_DeleteWazaActors, BTLV_INPUT_CreateBackActor, BTLV_INPUT_DeleteBackActor, BTLV_INPUT_ProcessButtonSelection, BTLV_INPUT_ProcessKeyRepeat, BTLV_INPUT_UpdateButtonActors, BTLV_INPUT_SetSelection, BTLV_INPUT_ButtonFlashTaskMain, BTLV_INPUT_ButtonFlashTaskEnd, BTLV_INPUT_DrawRunButtonText, BTLV_INPUT_PrepareCommandSelect, BTLV_INPUT_ClearSlotEvents, BTLV_INPUT_RegisterTask, BTLV_INPUT_FindTask, BTLV_INPUT_DeleteTask, BTLV_INPUT_AllocTaskSlot, BTLV_INPUT_DeleteAllTasks, BTLV_INPUT_IsWazaSelectable, BTLV_INPUT_UpdateWazaRow, BTLV_INPUT_BlendWindowPalette, BTLV_INPUT_RestoreWindowPalette, BTLV_INPUT_GetMessageBoxMode, BTLV_INPUT_PlayConfirmSe, BTLV_INPUT_PlayCancelSe, BTLV_INPUT_PlaySelectSe, BTLV_INPUT_PlayCursorSe, BTLV_INPUT_PlayPageSe, BTLV_INPUT_PlayOpenSe, BTLV_INPUT_PlayBackSe
 * address:  0x02202058
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   ARC_UTIL_LoadScreenDataFromArchive  0x02049E34  arm
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main  0x02030D28  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   KEY_GetTrg 0x020362DC arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   d_0220AEB0  0x0220AEB0  data  a4
 *   BTLV_FINGER_CURSOR_Delete  0x02209B30  thumb  ov094
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   INFOWIN_Init 0x02024A20 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   d_0220A3D4 0x0220A3D4 data ov094 a4
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   INFOWIN_Exit 0x02024DCC thumb
 *   d_0220A8BC  0x0220A8BC  data  a4
 *   PALANM_RequestFadeOverwrite  0x02021848  thumb
 *   CLACT_GetUnitDrawEnable  0x0204B248  arm
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   KEY_GetCont  0x0203630C  arm
 *   d_0689E090     0x0689E090  data   ov095
 *   d_0689E0B0     0x0689E0B0  data   ov095
 *   gBtlvScdTargetRegionsSingleB     0x0689E560  data   ov095
 *   gBtlvScdTargetRegionsDoubleB     0x0689E704  data   ov095
 *   d_0220A598     0x0220A598  data   a4
 *   BTLV_FINGER_CURSOR_Create  0x02209A7C  thumb  ov094
 *   BTLV_FINGER_CURSOR_Start  0x02209B60  thumb  ov094
 *   BTLV_FINGER_CURSOR_IsActive  0x02209C2C  thumb  ov094
 *   sBtlvInputSectionData   0x0220A380  data
 *   d_0220A380     0x0220A380  data
 *   d_0220AE98     0x0220AE98  data
 *   d_0220AEA4     0x0220AEA4  data
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   MIi_CpuCopy16 0x02082A60 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 *   MTX_Scale22_  0x0207AD58  thumb
 *   BG_SYS_SetScroll  0x02040820  arm
 *   d_0220A46C     0x0220A46C  data  ov094  a4
 *   d_0220A53C  0x0220A53C  data  a4
 *   d_0220A85C  0x0220A85C  data  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   d_0220A3B4     0x0220A3B4  data   ov094  a4
 *   d_0220A38C     0x0220A38C  data   ov094  a1
 *   d_0220A3E4     0x0220A3E4  data   ov094  a4
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   d_0220A5B0  0x0220A5B0  data
 *   d_0220A5D0  0x0220A5D0  data
 *   d_0220A5F0  0x0220A5F0  data
 *   d_0220A392  0x0220A392  data
 *   d_0220A3C4  0x0220A3C4  data
 *   d_0220A4AC  0x0220A4AC  data
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_0220A7FC     0x0220A7FC  data
 *   d_0220A94C     0x0220A94C  data
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMovePP 0x021D5528 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   d_0220A386 0x0220A386 data a1
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   d_0220A50C 0x0220A50C data a4
 *   POKE_TOOL_GetIconCellArcIdSub 0x0201BC78 thumb
 *   POKE_TOOL_GetIconCellEntryIdSub 0x0201BCEC thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   d_0220A558 0x0220A558 data ov094 a4
 *   d_0220A56C 0x0220A56C data ov094 a4
 *   d_0220A544 0x0220A544 data ov094 a4
 *   d_0220A580     0x0220A580  data   ov094  a4
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   BTLV_GAUGE_TakeSlotEvent  0x02207D78  thumb  ov094
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 *   INFOWIN_Update  0x02024ABC  thumb  arm9
 *   BMP_Create  0x02043678  arm  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BMP_GetPixels  0x020437D4  arm  arm9
 *   MSGDATA_Delete  0x02045C04  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   FADE_Start  0x0204E720  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 *   BTLV_EFFECT_GaugeRequestStop 0x021F8168 thumb ov094
 *   BTLV_EFFECT_StartCameraMove 0x021F8554 thumb ov094
 *   BTLV_EFFECT_GetWorkPtr 0x021F8678 thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_EFFECT_GetGauge 0x021F86B4 thumb ov094
 *   BTLV_EFFECT_GetBattleMain 0x021F8754 thumb ov094
 *   BTLV_EFFECT_SetVisibilityMode 0x021F8884 thumb ov094
 *   BTLV_EFFECT_GetVisibilityMode 0x021F88A8 thumb ov094
 *   BTLV_EFFECT_IsRecordEnabledInComm 0x021F88F4 thumb ov094
 *   BTLV_EFFECT_IsRecordAllowed 0x021F8914 thumb ov094
 *   BTLV_EFFECT_SetIntroState 0x021F8A40 thumb ov094
 *   BTLV_EFFECT_StartIntroEffect 0x021F8A78 thumb ov094
 *   BTLV_EFFECT_ResetIntroState 0x021F8AC0 thumb ov094
 *   BTLV_MCSS_TakeSpriteRefreshedFlag 0x022005C4 thumb ov094
 *   FX_ModS32  0x0207C994  arm  arm9
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm  arm9
 *   GXx_GetMasterBrightness_  0x0207D55C  arm  arm9
 *   BG_SYS_ClearLayer  0x0204152C  arm  arm9
 *   APP_ICON_GetTypePaletteOffset  0x020275EC  thumb  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 *   MSGDATA_CreateFromArchive  0x02045B38  arm  arm9
 */
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_mcss_shared_types.h"
#include "btlv_clact_shared_types.h"
#include "btlv_input_shared_types.h"

#define DROP_ID(k, f) if (*(int *)(p + (k)) != -1) { f(*(int *)(p + (k))); *(int *)(p + (k)) = -1; }

#define DROP_ZERO_ID(k, f) if (*(int *)(p + (k)) != 0) { f((struct Bank *)*(int *)(p + (k))); *(int *)(p + (k)) = 0; }

#define DROP_PTR(k, f) if (*(void **)(p + (k)) != 0) { f(*(void **)(p + (k))); *(void **)(p + (k)) = 0; }

#define S_INT(o) (*(int *)(s + (o)))

#define S_PTR(o) (*(void **)(s + (o)))

#define F68_(s) (*(BtlvInputFlags *)((s) + 0x68))

#define F6C_(s) (*(BtlvInputFlags2 *)((s) + 0x6c))

#define HEAP(s) ((u16)((*(u16 *)((s) + 0x240) & 0x7fff) | 0x8000))

#define HEAPID(h) ((u16)(((h) & 0x7fff) | 0x8000))

#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)

#define reg_G2S_DB_WININ   (*(volatile u16 *)0x04001048)

#define reg_G2S_DB_WINOUT  (*(volatile u16 *)0x0400104A)

#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)

#define BTLV_INPUT_SLOT_INDEX(input) ((input)->flags.slotIndex)

#define BTLV_INPUT_SLOT_PARAM(input) ((u8 *)(input)->pokeParam[BTLV_INPUT_SLOT_INDEX(input)])

struct MsgBank;

struct Rec;

struct BgVramReq;

struct Main;

struct CharBuf;

struct Descriptor;

struct BgTemplate;

struct Info;

struct Out;

struct Slots;

struct U16Vec;

struct BtlPokeParam;

struct StrObj;

struct WordSet;

struct Struct36;

struct QG;

struct Bmp;

struct Bmp;



typedef struct BtlvInputVisibilityTask { BtlvInput *owner; int mode; } BtlvInputVisibilityTask;


typedef struct BtlvInputBgLayer { char tmplBytes[0x20]; int type; } BtlvInputBgLayer;





typedef struct Arg1 {
    BtlvInputSlotInfo a[6];
    BtlvInputSlotInfo b[6];
    int restrictedChoice;
    int doubleCursor;
    u8 pad98[0xbc - 0x98];
    int battlePos;
    u8 padc0[4];
    u8 runTextId;   /* 0xC4: value set into the run-button text slot */
    u8 bc5;
} Arg1;

typedef struct Arg2 {
    u16 h[4];
    int f8;
    int selectMode;
    int slot;
    int transformed;
} Arg2;

typedef struct Arg5 {
    void *a[3];
    int b[3][4];
} Arg5;


typedef struct {
    char pad0[0xa];
    s8 id;              /* 0x0a */
    char padb;
} BtlvInputTargetRegion;

typedef struct {
    void *key;          /* 0x00 */
    int f4;
    int *vals;          /* 0x08 */
} Cmd;



typedef struct BtlvInputFingerTable {
    BtlvClactPoint pos[3];
} BtlvInputFingerTable;


typedef struct BtlvInputCommandDesc {
    void *buttons;
    void *selectFlags;
    const int *values;
} BtlvInputCommandDesc;

/* The rodata objects at 0x0220A380..0x0220A3B4 are one section to the compiler: loads go
 * through the section base (sBtlvInputSectionData + field) and addresses taken get their own words;
 * the 3-byte object at the section start is a second name at the same address. */
typedef struct BtlvInputSectionData {
    u8 b0[3];
    u8 key[3];
    u8 pal[3][2];
    u8 mode[3][2];
    u16 h[5];
    BtlvInputCommandDesc da;
    BtlvInputCommandDesc db;
} BtlvInputSectionData;




















typedef struct { int start, end; } BtlvInputWipeOffset;















/* Work of the palette cycle task (allocated by BTLV_INPUT_StartPaletteCycleTask). */
typedef struct BtlvInputPaletteCycleTask {
    BtlvInput *input;
    int tab;                /* palette pair index, 0 or 1 */
    int palSet;             /* which colour set to cycle */
    int count;              /* frames left before the next palette step */
} BtlvInputPaletteCycleTask;

/* One step of d_0220A46C: the two colours written to BG palette 5. */
typedef struct BtlvInputPaletteCycleEntry {
    int color0;
    int color1;
} BtlvInputPaletteCycleEntry;

/* Work of the cursor actor task (allocated by BTLV_INPUT_CreateCursorActors). */
typedef struct BtlvInputCursorActorTask {
    BtlvInput *input;
    void *unit;
    void *actors[6];
} BtlvInputCursorActorTask;

typedef struct Quad { u16 v[4]; } Quad;

typedef struct BtlvInputPoint { short x; short y; } BtlvInputPoint;

/* One row of d_0220A85C: six cursor positions and the animation sequence per slot. */
typedef struct BtlvInputCursorRow { BtlvInputPoint point[6]; int animSeq[2]; } BtlvInputCursorRow;

/* Work of the palette flash task (allocated by BTLV_INPUT_StartPaletteFlashTask). */
typedef struct BtlvInputPaletteFlashTask {
    BtlvInput *input;
    int kind;
} BtlvInputPaletteFlashTask;

/* Work of the background scroll-offset task (allocated by BTLV_INPUT_StartBgScrollOffsetTask). */
typedef struct BtlvInputBgScrollOffsetTask {
    BtlvInput *input;
    int bg;                 /* -1: leave the scroll registers alone */
    int scrollX;
    int scrollY;
    int bg4;                /* 2: leave BG4 visibility alone */
    int bg5;
    int bg6;
    int bg7;
} BtlvInputBgScrollOffsetTask;

typedef int BOOL;

typedef struct BtlvInputTextPos { int x, y; } BtlvInputTextPos;

typedef struct BtlvInputTextPosRow { BtlvInputTextPos pos[4]; } BtlvInputTextPosRow;

typedef struct { int w[9]; } Struct36;

/* Screen graphics file filled by ARC_UTIL_LoadScreenDataFromArchive. */
typedef struct BtlvInputScreenFile {
    u8 header[0x14];
    void *tileGfx;      /* 0x14: tile pixel data */
} BtlvInputScreenFile;

/* Palette file filled by ARC_UTIL_LoadPaletteBlockFromArchive. */
typedef struct BtlvInputPaletteFile {
    u8 header[0xC];
    void *palette;      /* 0x0C: palette data */
} BtlvInputPaletteFile;

typedef struct Slots {
    u16 id[4];
    u8 a[4];
    u8 b[4];
} Slots;

typedef struct BtlvInputTargetButton {
    u8 kind : 2;
    u8 flag : 1;
    u8 pad0 : 5;
    u8 pad1[3];
    short show;
    short pad6;
    void *text;
} BtlvInputTargetButton;

typedef struct BtlvInputTargetInfo {
    BtlvInputTargetButton buttons[6];
    u8 battlerCount;    /* active battlers: 2 single, 4 double, 6 triple */
    u8 targetGroup;
} BtlvInputTargetInfo;


typedef struct Out {
    u32 pad[3];
    int bgFile;
} Out;

typedef struct BtlvInputTargetRes {
    u32 pad[3];
    u16 *palette;
} BtlvInputTargetRes;


typedef struct { u16 value[4]; u8 a[4], b[4]; u8 pad10[8]; } Buffer;

typedef struct { u8 first, second; } Palette;



typedef struct BtlvInputPartyInfo {
    unsigned char pad00[0x98];
    u32 species[3];
    u32 form[3];
    u32 gender[3];
    int sel;
} BtlvInputPartyInfo;



typedef struct Five { int v[5]; } Five;




typedef struct {
    int seq[6];
} BtlvInputTargetAnim;





/* Button table and per-button select flags; callers pass their command
 * descriptor (Cmd/Desc) as this. */
typedef struct BtlvInputSection {
    u8 (*buttons)[4];
    int *selectFlags;
} BtlvInputSection;

typedef struct PalAnmObj PalAnmObj;

/* Work of the button flash task (allocated by BTLV_INPUT_SetSelection). */
typedef struct BtlvInputButtonFlashTask {
    BtlvInput *input;
    int state;
    int colour;
    int flag;
} BtlvInputButtonFlashTask;


extern u32 GFL_HEAP_Free(void *p);

extern void *BTL_MAIN_GetCompetitor(void ***);

extern unsigned TCB_GetTaskOffset(unsigned);

extern struct Ctx *TCB_Init(u32 capacity, struct Ctx *c);

extern void *GFL_USE_AddMainTask(void (*)(void *, void *), void *, int);

extern void TCB_DeleteTask(struct Node *n);

extern void TCB_Noop(void *);

extern void * TCB_Main(struct Ctx *c);

extern void *TCB_AddTask(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);


extern u32 KEY_GetTrg(void);

extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern unsigned int CLACT_DeleteUnit(struct Bank *bank);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern u32 CLACT_SetActorAnimSeq(void *obj, u16 v);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern void BTLV_FINGER_CURSOR_Delete(void *);

extern void INFOWIN_Update(void *);

extern void BG_SYS_ApplyGraphicsMode(const struct BgVramReq *req, u32 which);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BG_SYS_PushTile(u32 index);

extern void INFOWIN_Init(u8, u8, void *, u16);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern int INFOWIN_Exit(void);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_ClearLayer(int channel, u16 val);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern int GXx_GetMasterBrightness_(volatile u16 *reg);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16, u8, u8, u16, void *);

extern u32 CLACT_GetUnitDrawEnable(struct Bank *bank);

extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);

extern void GF_FONT_SetTextColor(u32, u32, u32);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);

extern void STRBUF_Delete(struct U16Vec *vec);

extern int TOUCHPANEL_HitTrg(const void *p);

extern unsigned int KEY_GetCont(void);

extern void *BTLV_FINGER_CURSOR_Create(void *pal, int b, int c);

extern int BTLV_FINGER_CURSOR_Start(void *h, int x, int y, int k, int m, int n);

extern int BTLV_FINGER_CURSOR_IsActive(void *h);

extern int BTL_POKEPARAM_IsTransformed(struct BtlPokeParam *p);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *, u32, u32, u32, u32, u32, u16);

extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern int PALANM_GetDefaultWork(char *p, int i);

extern void MIi_CpuCopy16(const void *, void *, u32);

extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);

extern u32 APP_ICON_GetArchiveId(void);

extern u32 APP_ICON_GetTypePaletteFileId(u32);

extern u32 APP_ICON_GetTypeAnimFileId(u32);

extern u32 APP_ICON_GetTouchBarFileId(void);

extern u32 APP_ICON_GetTypeCellFileId(u32);

extern void MTX_Scale22_(void *dst, int a, int b);

extern void BG_SYS_SetScroll(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern int FADE_IsActive(void);

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);

extern int FX_ModS32(int n, int d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);

extern u8 APP_ICON_GetTypePaletteOffset(int i);

extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, u32 unpackedOut, u32 flags);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);

extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);

extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);

extern void WORDSET_SetSlotNumber(u32 p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

extern u32 WORDSET_Delete(struct WordSet *p);

extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);

extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);

extern u16 BTL_POKEPARAM_GetMovePP(u8 *, u8, u8 *, u8 *);

extern int BTL_POKEPARAM_IsFainted(void *);

extern void BG_SYS_SetTileEntry(u32 index, u32 value, u32 x0, u32 y0, u8 w, u8 h, u8 mode);

extern int POKE_TOOL_GetIconCellArcIdSub(void);

extern int POKE_TOOL_GetIconCellEntryIdSub(void);

extern int POKE_TOOL_GetIconPaletteArcId(void);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void BMP_Delete(struct Bmp *p);

extern unsigned int KEY_GetRepeat(void);

extern int BTLV_GAUGE_TakeSlotEvent(char *p, int i);

void BTLV_EFFECT_StartEffect(u32 a);

void BTLV_EFFECT_GaugeRequestStop(void);

void BTLV_EFFECT_StartCameraMove(u32 flags, int kind, int n, int s, int t);

void *BTLV_EFFECT_GetWorkPtr(void);

int BTLV_EFFECT_GetMcss(void);

int BTLV_EFFECT_GetGauge(void);

void *BTLV_EFFECT_GetOwner(void);

int BTLV_EFFECT_GetPalanm(void);

int BTLV_EFFECT_GetBattleMain(void);

void BTLV_EFFECT_SetVisibilityMode(int a);

int BTLV_EFFECT_GetVisibilityMode(void);

int BTLV_EFFECT_IsRecordEnabledInComm(void);

int BTLV_EFFECT_IsRecordAllowed(void);

void BTLV_EFFECT_SetIntroState(int a);

void BTLV_EFFECT_StartIntroEffect(void);

void BTLV_EFFECT_ResetIntroState(int a);

int BTLV_MCSS_TakeSpriteRefreshedFlag(BtlvMcssWork *w, int key);

BtlvInput *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k);

void BTLV_INPUT_CreateWithMode(int a, int b, int c, int d, int e, int f, int g, u16 k);

BtlvInput *BTLV_INPUT_Create(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap);

void BTLV_INPUT_Delete(BtlvInput *input);

void BTLV_INPUT_UpdateInfoWindow(BtlvInput *input);

void BTLV_INPUT_InfoWindowTask(void *unused, void *arg);

void BTLV_INPUT_LoadScreenResources(BtlvInput *input);

void BTLV_INPUT_ReleaseScreenResources(BtlvInput *input);

void BTLV_INPUT_InitBgLayers(BtlvInput *input);

void BTLV_INPUT_ReleaseBgLayers(void);

void BTLV_INPUT_StartPaletteFadeTask(BtlvInput *input, int flag);

void BTLV_INPUT_StartScreenFadeTask(BtlvInput *input);

int BTLV_INPUT_IsScreenBusy(BtlvInput *input);

void BTLV_INPUT_ChangeScreen(BtlvInput *input, int mode, void *arg);

int BTLV_INPUT_ProcessTouchInput(BtlvInput *input, Cmd *c, int x);

int BTLV_INPUT_StepFingerDemo(BtlvInput *input);

int BTLV_INPUT_ProcessKeyInput(BtlvInput *input, u8 *key, int *out);

int BTLV_INPUT_IsInputBlocked(BtlvInput *input);

int BTLV_INPUT_GetScreen(BtlvInput *input);

void BTLV_INPUT_LoadCommonGraphics(BtlvInput *input);

void BTLV_INPUT_ActionScreenOpenTask(void *task, void *arg);

void BTLV_INPUT_WazaScreenOpenTask(void *task, void *arg);

void BTLV_INPUT_WazaScreenOpenInstantTask(void *task, void *arg);

void BTLV_INPUT_ActionScreenOpenInstantTask(void *task, void *arg);

void BTLV_INPUT_TargetScreenOpenTask(void *task, void *arg);

void BTLV_INPUT_WazaScreenCloseTask(void *task, void *arg);

void BTLV_INPUT_WaitScreenOpenTask(void *task, void *arg);

void BTLV_INPUT_WaitScreenOpenInstantTask(void *task, void *arg);

void BTLV_INPUT_MessageScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_ListScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_SelectScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_ConfirmScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_ListScreenOpenInstantTask(void *h, void *arg);

void BTLV_INPUT_ScreenResetTask(void *h, void *arg);

void BTLV_INPUT_TaskEndClearBusyBit(void *h);

void BTLV_INPUT_StartBgScrollTask(BtlvInput *input, int startScale, int goalScale, int step, int scrollY);

void BTLV_INPUT_BgScrollTaskMain(void *task, void *arg);

void BTLV_INPUT_BgScrollTaskEnd(void *h);

void BTLV_INPUT_StartBgWipeTask(BtlvInput *input, int x, int y, int dy, int count);

void BTLV_INPUT_BgWipeTaskMain(void *task, void *arg);

void BTLV_INPUT_BgWipeTaskEnd(void *h);

void BTLV_INPUT_StartPaletteCycleTask(BtlvInput *input, int unused, int palSet);

void BTLV_INPUT_PaletteCycleTaskMain(void *task, void *arg);

void BTLV_INPUT_PaletteCycleTaskEnd(void *h);

void BTLV_INPUT_CreateCursorActors(BtlvInput *input, int rowIndex, int animIndex);

void BTLV_INPUT_CursorActorTaskMain(void *a, void *arg);

void BTLV_INPUT_CursorActorTaskEnd(void *h);

void BTLV_INPUT_StartPaletteFlashTask(BtlvInput *input, int kind);

void BTLV_INPUT_PaletteFlashTaskMain(void *task, void *arg);

void BTLV_INPUT_PaletteFlashTaskEnd(void *h);

void BTLV_INPUT_StartBgScrollOffsetTask(BtlvInput *input, int bg, int scrollX, int scrollY, int bg4, int bg5, int bg6, int bg7);

void BTLV_INPUT_BgScrollOffsetTaskMain(void *task, void *arg);

void BTLV_INPUT_WaitFadeTaskMain(void *a, void *arg);

void BTLV_INPUT_WaitFadeTaskEnd(void *h);

void BTLV_INPUT_CursorMoveTaskMain(void *task, void *arg);

void BTLV_INPUT_CursorMoveTaskEnd(void *h);

void BTLV_INPUT_StartScreenTransition(BtlvInput *input, int screen);

void BTLV_INPUT_VisibilityTaskMain(void *a, void *arg);

void BTLV_INPUT_WindowOpenTaskMain(void *task, void *arg);

void BTLV_INPUT_WindowCloseTaskMain(void *task, void *arg);

void BTLV_INPUT_GetTextBlockSize(struct StrObj *str, int font, int *outCount, int *outCapacity);

void BTLV_INPUT_DrawWazaButtons(BtlvInput *input, const Slots *q);

void BTLV_INPUT_DrawTargetButtons(BtlvInput *input, Out *out, const BtlvInputTargetInfo *p);

void BTLV_INPUT_DrawMessageText(BtlvInput *input, const int *c);

void BTLV_INPUT_InitButtonState(BtlvInput *input);

void BTLV_INPUT_DrawSelectScreenText(BtlvInput *input, const int *b);

void BTLV_INPUT_ClearButtonState(BtlvInput *input);

int BTLV_INPUT_GetPpTextColor(int a, int b);

void BTLV_INPUT_CreateActionButtons(BtlvInput *input, BtlvInputPartyInfo *info);

void BTLV_INPUT_DeleteActionButtonActors(BtlvInput *input);

void BTLV_INPUT_SetActionUnitVisible(BtlvInput *input, int visible);

void BTLV_INPUT_CreateStatusIcons(BtlvInput *input, int n);

void BTLV_INPUT_DeleteStatusIcons(BtlvInput *input);

void BTLV_INPUT_CreateWazaCursorActors(BtlvInput *input, int mode);

void BTLV_INPUT_DeleteWazaCursorActors(BtlvInput *input);

void BTLV_INPUT_CreateTargetActors(BtlvInput *input);

void BTLV_INPUT_DeleteTargetActors(BtlvInput *input);

void BTLV_INPUT_DeleteWazaActors(BtlvInput *input);

void BTLV_INPUT_CreateBackActor(BtlvInput *input);

void BTLV_INPUT_DeleteBackActor(BtlvInput *input);

int BTLV_INPUT_ProcessButtonSelection(BtlvInput *input, const BtlvInputSection *section, s8 (*rows)[12], u8 *list, int ret, int transformed);

int BTLV_INPUT_ProcessKeyRepeat(BtlvInput *input);

void BTLV_INPUT_UpdateButtonActors(BtlvInput *input, u8 (* __restrict tab)[4], s8 (*rows)[12]);

int BTLV_INPUT_SetSelection(BtlvInput *input, int a, int b);

void BTLV_INPUT_ButtonFlashTaskMain(void *task, void *arg);

void BTLV_INPUT_ButtonFlashTaskEnd(void *h);

void BTLV_INPUT_DrawRunButtonText(BtlvInput *input, char *runInfo);

void BTLV_INPUT_PrepareCommandSelect(BtlvInput *input);

void BTLV_INPUT_ClearSlotEvents(BtlvInput *input);

void BTLV_INPUT_RegisterTask(BtlvInput *input, int taskFunc, int taskEnd);

int BTLV_INPUT_FindTask(BtlvInput *input, int task);

void BTLV_INPUT_DeleteTask(BtlvInput *input, void *task);

int BTLV_INPUT_AllocTaskSlot(BtlvInput *input);

void BTLV_INPUT_DeleteAllTasks(BtlvInput *input);

int BTLV_INPUT_IsWazaSelectable(BtlvInput *input, const BtlvInputSection *section, int i);

void BTLV_INPUT_UpdateWazaRow(BtlvInput *input);

void BTLV_INPUT_BlendWindowPalette(BtlvInput *input);

void BTLV_INPUT_RestoreWindowPalette(BtlvInput *input);

int BTLV_INPUT_GetMessageBoxMode(BtlvInput *input);

void BTLV_INPUT_PlayConfirmSe(BtlvInput *input);

void BTLV_INPUT_PlayCancelSe(BtlvInput *input);

void BTLV_INPUT_PlaySelectSe(BtlvInput *input);

void BTLV_INPUT_PlayCursorSe(BtlvInput *input);

void BTLV_INPUT_PlayPageSe(BtlvInput *input);

void BTLV_INPUT_PlayOpenSe(BtlvInput *input);

void BTLV_INPUT_PlayBackSe(BtlvInput *input);

extern const char d_0220AEB0[];

extern char d_0220A3D4[];

extern const BtlvInputBgLayer d_0220A8BC[];

extern u8 d_0689E090[][15];

extern u8 d_0689E0B0[][15];

extern BtlvInputTargetRegion *gBtlvScdTargetRegionsSingleB[][15];

extern BtlvInputTargetRegion *gBtlvScdTargetRegionsDoubleB[][15];

extern const BtlvInputFingerTable d_0220A598;

extern const BtlvInputSectionData sBtlvInputSectionData;

extern const u8 d_0220A380[3];

extern void *const d_0220AE98[];

extern void *const d_0220AEA4[];

extern const BtlvInputWipeOffset d_0220A4EC[];

extern const BtlvInputPaletteCycleEntry d_0220A46C[][2];

extern const Quad d_0220A53C;

extern BtlvInputCursorRow d_0220A85C[];

extern const int d_0220A3B4[][2];

extern const u8 d_0220A38C[][2];

extern const int d_0220A3E4[][2];

extern const BtlvInputTextPosRow d_0220A5B0;

extern const BtlvInputTextPosRow d_0220A5D0;

extern const int d_0220A5F0[];

extern const u16 d_0220A392[];

extern const BtlvInputPoint d_0220A3C4[];

extern const BtlvInputTextPos d_0220A4AC[];

extern const int d_0220A7FC[2][6][2];

extern const int d_0220A94C[2][3][15];

extern const Palette d_0220A386[];

extern const BtlvInputPoint d_0220A50C[][3];

extern const Five d_0220A558, d_0220A56C, d_0220A544;

extern const BtlvInputTargetAnim d_0220A580;

BtlvInput *BTLV_INPUT_CreateDefault(int infoWinParam, int battleType, int palAnm, int font, int cursorVisible, u16 heap)
{
    return BTLV_INPUT_Create(infoWinParam, battleType, 0, palAnm, font, cursorVisible, 0, 0, heap);
}

void BTLV_INPUT_CreateWithMode(int infoWinParam, int battleType, int seMode, int palAnm, int font, int cursorVisible, int visibilityMode, u16 heap)
{
    BTLV_INPUT_Create(infoWinParam, battleType, seMode, palAnm, font, cursorVisible, visibilityMode, 1, heap);
}

BtlvInput *BTLV_INPUT_Create(int infoWinParam, int battleType, int seMode, int palAnm, int font, int cursorVisible, int visibilityMode, int infoWinEnabled, u16 heap)
{
    BtlvInput *input;
    BtlvInputVisibilityTask *r;
    int i;

    input = GFL_HEAP_Alloc(heap, 0x2e0, 1, d_0220AEB0, 0x39a);
    input->heap = heap;
    input->taskMgrMem = GFL_HEAP_Alloc(input->heap, TCB_GetTaskOffset(8), 1, d_0220AEB0, 0x39e);
    input->taskMgr = TCB_Init(8, input->taskMgrMem);
    input->infoWinParam = (void *)infoWinParam;
    input->font = (void *)font;
    input->battleType = battleType;
    input->seMode = seMode;
    input->cursorVisible = (u8 *)cursorVisible;
    input->flags.prevCursor = 15;
    input->infoWinEnabled = infoWinEnabled;
    input->palAnm = (void *)palAnm;
    input->resCommonChr = -1;
    input->resCommonPal = -1;
    input->resCommonCell = -1;
    input->resButtonChr = -1;
    input->resButtonCell = -1;
    input->pokePal = -1;
    input->pokeCell = -1;
    input->typePal = -1;
    input->typeCell = -1;
    for (i = 0; i < 3; i++) {
        input->pokeChr[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        input->typeChr[i] = -1;
    }
    input->msgData = MSGDATA_CreateFromArchive(0, 2, 12, input->heap);
    input->pending = -1;
    BTLV_INPUT_LoadScreenResources(input);
    r = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x3cc);
    r->owner = input;
    r->mode = visibilityMode;
    BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, (void (*)(void *, void *))(BTLV_INPUT_VisibilityTaskMain), r, 0), 0);
    return input;
}

void BTLV_INPUT_Delete(BtlvInput *input)
{
    if (input == 0)
        return;
    BTLV_INPUT_DeleteAllTasks((void *)input);
    BTLV_INPUT_ReleaseScreenResources(input);
    MSGDATA_Delete(input->msgData);
    if (input->fingerCursor != 0)
        BTLV_FINGER_CURSOR_Delete(input->fingerCursor);
    TCB_Noop(input->taskMgr);
    GFL_HEAP_Free(input->taskMgrMem);
    GFL_HEAP_Free(input);
}

void BTLV_INPUT_UpdateInfoWindow(BtlvInput *input)
{
    INFOWIN_Update(TCB_Main((struct Ctx *)input->taskMgr));
}

void BTLV_INPUT_InfoWindowTask(void *unused, void *arg)
{
    BtlvInput *input = arg;

    INFOWIN_Update(TCB_Main((struct Ctx *)input->taskMgr));
}

void BTLV_INPUT_LoadScreenResources(BtlvInput *input)
{
    BG_SYS_ApplyGraphicsMode((const struct BgVramReq *)d_0220A3D4, 1);
    input->arc = ARC_TOOL_CreateHandle(0xb, input->heap);
    input->unitWaza = CLACT_CreateUnit(4, 2, input->heap);
    input->unitButtons = CLACT_CreateUnit(0xc, 2, input->heap);
    input->unitCursors = CLACT_CreateUnit(6, 0, input->heap);
    input->unitPoke = CLACT_CreateUnit(3, 2, input->heap);
    input->unitStatus = CLACT_CreateUnit(2, 2, input->heap);
    input->unitBack = CLACT_CreateUnit(1, 1, input->heap);
    BTLV_INPUT_InitBgLayers(input);
    BTLV_INPUT_LoadCommonGraphics(input);
    BTLV_INPUT_CreateTargetActors((void *)input);
    input->bmpWinA = (void *)BMP_WIN_Create(6, 0, 4, 32, 12, 13, 1);
    input->bmpA = BMP_WIN_GetBmp(input->bmpWinA);
    input->bmpWinB = (void *)BMP_WIN_Create(6, 3, 22, 3, 2, 13, 1);
    input->bmpB = BMP_WIN_GetBmp(input->bmpWinB);
    BMP_Clear(input->bmpA, 0);
    BMP_Clear(input->bmpB, 0);
    BMP_WIN_TransferChars(input->bmpWinA);
    BMP_WIN_TransferChars(input->bmpWinB);
    BMP_WIN_MakeScreen(input->bmpWinA);
    BMP_WIN_MakeScreen(input->bmpWinB);
    BG_SYS_PushTile(6);
    INFOWIN_Init(6, 15, input->infoWinParam, input->heap);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout(0, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, 0xe0, 0x20);
    input->flags.redraw = 1;
    if (input->infoWinEnabled == 1)
        input->infoWinTask = TCB_AddTask(BTLV_EFFECT_GetOwner(), BTLV_INPUT_InfoWindowTask, input, 0);
    BTLV_INPUT_ChangeScreen(input, 0, 0);
}

void BTLV_INPUT_ReleaseScreenResources(BtlvInput *input)
{
    int i;
    BTLV_INPUT_DeleteWazaActors((void *)input);
    BTLV_INPUT_DeleteWazaCursorActors((void *)input);
    BTLV_INPUT_DeleteTargetActors((void *)input);
    BTLV_INPUT_DeleteActionButtonActors((void *)input);
    BTLV_INPUT_DeleteStatusIcons((void *)input);
    if (input->resCommonChr != -1) {
        CLACT_ReleaseCharacter(input->resCommonChr);
        input->resCommonChr = -1;
    }
    if (input->resCommonPal != -1) {
        CLACT_ReleasePalette(input->resCommonPal);
        input->resCommonPal = -1;
    }
    if (input->resCommonCell != -1) {
        CLACT_ReleaseCellAnim(input->resCommonCell);
        input->resCommonCell = -1;
    }
    if (input->resButtonChr != -1) {
        CLACT_ReleaseCharacter(input->resButtonChr);
        input->resButtonChr = -1;
    }
    if (input->resButtonCell != -1) {
        CLACT_ReleaseCellAnim(input->resButtonCell);
        input->resButtonCell = -1;
    }
    for (i = 0; i < 4; i++) {
        if (input->typeChr[i] != -1) {
            CLACT_ReleaseCharacter(input->typeChr[i]);
            input->typeChr[i] = -1;
        }
    }
    if (input->typeCell != -1) {
        CLACT_ReleaseCellAnim(input->typeCell);
        input->typeCell = -1;
    }
    if (input->typePal != -1) {
        CLACT_ReleasePalette(input->typePal);
        input->typePal = -1;
    }
    if (input->unitWaza != 0) {
        CLACT_DeleteUnit((struct Bank *)input->unitWaza);
        input->unitWaza = 0;
    }
    if (input->unitButtons != 0) {
        CLACT_DeleteUnit((struct Bank *)input->unitButtons);
        input->unitButtons = 0;
    }
    if (input->unitCursors != 0) {
        CLACT_DeleteUnit((struct Bank *)input->unitCursors);
        input->unitCursors = 0;
    }
    if (input->unitPoke != 0) {
        CLACT_DeleteUnit((struct Bank *)input->unitPoke);
        input->unitPoke = 0;
    }
    if (input->unitStatus != 0) {
        CLACT_DeleteUnit((struct Bank *)input->unitStatus);
        input->unitStatus = 0;
    }
    if (input->unitBack != 0) {
        CLACT_DeleteUnit((struct Bank *)input->unitBack);
        input->unitBack = 0;
    }
    if (input->bmpWinA != 0) {
        BMP_WIN_Delete(input->bmpWinA);
        input->bmpWinA = 0;
    }
    if (input->bmpWinB != 0) {
        BMP_WIN_Delete(input->bmpWinB);
        input->bmpWinB = 0;
    }
    INFOWIN_Exit();
    BTLV_INPUT_ReleaseBgLayers();
    if (input->infoWinTask != 0) {
        TCB_DeleteTask(input->infoWinTask);
        input->infoWinTask = 0;
    }
    if (input->arc != 0) {
        ARC_TOOL_DeleteHandle(input->arc);
        input->arc = 0;
    }
    input->screen = 0;
}

void BTLV_INPUT_InitBgLayers(BtlvInput *input)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        BG_SYS_InitBgLayer((u8)(i + 4), (const struct BgTemplate *)(&d_0220A8BC[i]), (u8)d_0220A8BC[i].type);
        BG_SYS_ClearLayer((u8)(i + 4), (int)0x3ff);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)input, i + 4, 0, 0, 2, 2, 2, 2);
    }
}

void BTLV_INPUT_ReleaseBgLayers(void)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        BG_SYS_SetPlaneVisible((u8)(i + 4), (int)0);
        BG_SYS_FreeLayerBuf((u8)(i + 4));
    }
}

/*
 * lever: the flag test is two whole PALANM_RequestFade calls, one per arm, differing only
 *   in the fifth argument (0 / 0xC). The compiler cross-jumps them after the [sp] store,
 *   hoists the shared `ldr r2, =0xFFFF` above the branch and pools the three zeros of the
 *   two calls in r6 before the alloc call. A u8 local set in an if/else (or an enum
 *   zero) gave the same size with flag and the zero in each other's registers
 *   (docs/notes/pkt_ov094_022025D8.c.txt).
 */
void BTLV_INPUT_StartPaletteFadeTask(BtlvInput *input, int flag)
{
    int *p;

    p = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x4F7);
    if (flag == 1)
        PALANM_RequestFade(input->palAnm, 0xA, 0xFFFF, 1, 0, 0x10, 0, input->taskMgr);
    else
        PALANM_RequestFade(input->palAnm, 0xA, 0xFFFF, 1, 0xC, 0x10, 0, input->taskMgr);
    input->flags.fadeKind = 1;
    p[0] = (int)input;
    BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, (void ( *)(void *, void *))(BTLV_INPUT_WaitFadeTaskMain), p, 0), (int)BTLV_INPUT_WaitFadeTaskEnd);
}

/*
 * note: the two zero arguments of FADE_Start sit in r6 because the call is written in
 *   both arms of the if (the arms are cross-jumped and the shared zero is hoisted).
 * trailing: 022026FC..0220270C is an unlabelled getter (mode bits 15..16 of +0x68 != 0).
 */
void BTLV_INPUT_StartScreenFadeTask(BtlvInput *input)
{
    BtlvInput **q;
    q = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x50c);
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106c) <= 0)
        FADE_Start(2, 0x10, 0, 0);
    else
        FADE_Start(8, 0x10, 0, 0);
    BTLV_INPUT_LoadScreenResources(input);
    input->flags.fadeKind = 2;
    *q = input;
    BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, (void ( *)(void *, void *))(BTLV_INPUT_WaitFadeTaskMain), q, 0), (int)BTLV_INPUT_WaitFadeTaskEnd);
}

/*
 * notes:    tests a 2-bit field at bits 15..16 of the word at +0x68, returns 1 if nonzero. Witness for calls in ov098 PDC_MAIN_StepChooseItem (2026-10-05, lane W-B).
 */
int BTLV_INPUT_IsScreenBusy(BtlvInput *input)
{
    if (input->flags.fadeKind) return 1;
    return 0;
}

void BTLV_INPUT_ChangeScreen(BtlvInput *input, int mode, void *arg)
{
    BtlvInputTask *t;
    void *w;
    int i;
    int j;

    BTLV_INPUT_ClearButtonState((void *)input);
    input->flags.fingerStep = 0;
    input->flags2.inputEnabled = 1;
    switch (mode) {
    case 0:
        input->pending = -1;
        if (input->screen == 0) {
            BTLV_INPUT_StartBgScrollTask(input, 0x3000, 0x3000, 0, 0x98);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)input, -1, 0, 0, 0, 0, 2, 1);
            PALANM_RequestFade(input->palAnm, 2, 3, 1, 12, 12, 0x842, input->taskMgr);
        } else {
            t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x549);
            input->flags.busy = 1;
            t->input = input;
            if (input->infoWinEnabled == 1)
                BTLV_EFFECT_StartIntroEffect();
            BTLV_INPUT_DeleteWazaCursorActors((void *)input);
            BTLV_INPUT_DeleteActionButtonActors((void *)input);
            if (input->screen == 1 || input->screen == 4) {
                BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_WaitScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
            } else {
                t->fromScreen = input->screen;
                BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_WaitScreenOpenInstantTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
            }
            PALANM_RequestFadeOverwrite(input->palAnm, 2, 3, 1, 0, 12, 0x842, input->taskMgr);
            if (CLACT_GetUnitDrawEnable(input->unitCursors) != 0) {
                input->flags.cursor = 0;
                input->flags.prevCursor = 15;
                input->flags.redraw = 1;
                CLACT_SetUnitDrawEnable(input->unitCursors, 0);
            }
        }
        break;
    case 1: {
        Arg1 *a = arg;
        BtlvInputTask *t1;
        t1 = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x570);
        input->battlePos = a->battlePos;
        BTLV_INPUT_PrepareCommandSelect((void *)input);
        BTLV_EFFECT_SetIntroState(2);
        if (a->battlePos >= 2)
            a->battlePos = (a->battlePos - 2) / 2;
        input->flags.busy = 1;
        input->flags.restrictedChoice = a->restrictedChoice;
        t1->input = input;
        t1->slot = a->battlePos;
        input->partyIdx = a->battlePos;
        if (input->screen == 0)
            BTLV_INPUT_ClearSlotEvents((void *)input);
        for (i = 0; i < 6; i++) {
            *(BtlvInputSlotInfo *)&input->slotInfo[0][i] = a->a[i];
            *(BtlvInputSlotInfo *)&input->slotInfo[1][i] = a->b[i];
        }
        for (j = 0; j < 4; j++)
            input->enabled[j] = 1;
        input->enabled[1] = BTLV_EFFECT_IsRecordAllowed();
        BTLV_INPUT_DeleteActionButtonActors((void *)input);
        BTLV_INPUT_CreateActionButtons((void *)input, (BtlvInputPartyInfo *)((struct Info *)a));
        BTLV_INPUT_CreateStatusIcons((void *)input, a->bc5);
        t1->bgFile = BTLV_INPUT_GetMessageBoxMode((void *)input);
        BTLV_INPUT_DrawRunButtonText((void *)input, (char *)a);
        if (input->screen == 2 || input->screen == 5) {
            BTLV_INPUT_SetActionUnitVisible((void *)input, 0);
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ActionScreenOpenInstantTask, t1, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_CreateWazaCursorActors((void *)input, 0);
            if (a->doubleCursor != 0)
                BTLV_INPUT_CreateWazaCursorActors((void *)input, 1);
            input->flags.doubleCursor = a->doubleCursor;
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ActionScreenOpenTask, t1, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 2: {
        Arg2 *a = arg;
        BtlvInputTask *t2;
        t2 = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x5bd);
        BTLV_INPUT_DrawWazaButtons((void *)input, (const Slots *)((const struct Slots *)a));
        input->flags.busy = 1;
        t2->input = input;
        t2->slot = a->slot;
        input->transformed = a->transformed;
        t2->bgFile = BTLV_INPUT_GetMessageBoxMode((void *)input);
        for (j = 0; j < 4; j++)
            input->moveIds[j] = a->h[j];
        if (input->infoWinEnabled == 1 && (input->battleType == 1 || input->battleType == 2)) {
            BTLV_EFFECT_ResetIntroState(2);
            BTLV_EFFECT_StartEffect(0x244);
        }
        if (input->screen == 3) {
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_WazaScreenCloseTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else if (input->screen == 0) {
            BTLV_INPUT_CreateWazaCursorActors((void *)input, 0);
            if (input->flags.doubleCursor)
                BTLV_INPUT_CreateWazaCursorActors((void *)input, 1);
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_WazaScreenOpenTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_DeleteActionButtonActors((void *)input);
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_WazaScreenOpenInstantTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 3:
        t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x5ec);
        BTLV_INPUT_DrawTargetButtons((void *)input, (Out *)((struct Out *)t), (const BtlvInputTargetInfo *)arg);
        input->flags.busy = 1;
        t->input = input;
        t->slot = ((u8 *)arg)[0x48];
        BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_TargetScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        break;
    case 4:
        t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x5f8);
        BTLV_INPUT_DrawMessageText((void *)input, arg);
        input->flags.busy = 1;
        t->input = input;
        input->flags2.inputEnabled = ((int *)arg)[2];
        BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_MessageScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        break;
    case 5: {
        Arg5 *a = arg;
        int k;
        t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x605);
        if (input->screen != 0) {
            input->flags.bits17 = 0;
            input->flags.slotIndex = 0;
        }
        for (i = 0; i < 3; i++) {
            input->pokeParam[i] = a->a[i];
            for (k = 0; k < 4; k++)
                input->moveFlags[i][k] = a->b[i][k];
        }
        BTLV_INPUT_InitButtonState((void *)input);
        input->flags.busy = 1;
        t->input = input;
        if (input->screen == 0) {
            BTLV_INPUT_CreateWazaCursorActors((void *)input, 0);
            if (input->flags.doubleCursor)
                BTLV_INPUT_CreateWazaCursorActors((void *)input, 1);
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ListScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ListScreenOpenInstantTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 6: {
        Arg2 *a = arg;
        w = 0;
        for (j = 0; j < 3; j++)
            input->enabled[j] = 1;
        BTLV_INPUT_DrawSelectScreenText((void *)input, (const int *)a);
        switch (a->selectMode) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            GF_FONT_SetTextColor(1, 2, 0);
            w = MSGDATA_AllocString(input->msgData, a->selectMode + 8);
            break;
        }
        if (input->screen == 0) {
            t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x65f);
            input->flags.busy = 1;
            t->input = input;
            if (a->selectMode == 0) {
                t->scrollX = 0;
                t->scrollY = 0x100;
            } else {
                t->scrollX = 0x100;
                t->scrollY = 0;
            }
            t->text = w;
            BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_SelectScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            if (a->selectMode == 0)
                BTLV_INPUT_StartBgScrollOffsetTask((void *)input, 4, 0, 0x100, 2, 2, 2, 2);
            else
                BTLV_INPUT_StartBgScrollOffsetTask((void *)input, 4, 0x100, 0, 2, 2, 2, 2);
            if (w != 0) {
                PRINTSYS_Print((void *)input->bmpA, 0x18, 0x38, w, (void *)input->font);
                STRBUF_Delete(w);
            }
            BMP_WIN_MakeScreen(input->bmpWinA);
            BG_SYS_PushTile(6);
            BMP_WIN_TransferChars(input->bmpWinA);
        }
        break;
    }
    case 7:
        t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x68c);
        input->flags.busy = 1;
        t->input = input;
        BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ConfirmScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        input->enabled[0] = 1;
        input->enabled[1] = 1;
        break;
    }
    input->screen = mode;
}

int BTLV_INPUT_ProcessTouchInput(BtlvInput *input, Cmd *table, int neighbours)
{
    int r;
    int k;
    u32 keys;
    int ret;
    int i;
    int cnt;
    int idx;
    BtlvInputTargetRegion *e;
    int mode;

    if (input->flags.busy || PALANM_GetFadeRequestBits((const char *)input->palAnm) != 0 || input->flags.inputLock)
        return -1;
    ret = input->pending;
    if (ret != -1) {
        input->flags2.choiceMade = 0;
        input->pending = -1;
        return ret;
    }
    if (KEY_GetTrg() & 8) {
        if ((u32)(input->screen - 1) <= 2)
            BTLV_EFFECT_GaugeRequestStop();
    }
    if (input->screen == 6) {
        r = TOUCHPANEL_HitTrg(table->key);
        if (r != -1) {
            if (input->enabled[r] == 0)
                r = -1;
            else if (r == 2)
                BTLV_INPUT_PlayCursorSe((void *)input);
            else
                BTLV_INPUT_PlaySelectSe((void *)input);
        } else {
            r = BTLV_INPUT_ProcessKeyRepeat((void *)input);
        }
        if (r != -1)
            r = BTLV_INPUT_SetSelection(input, r, table->vals[r]);
        return r;
    }

    k = TOUCHPANEL_HitTrg(table->key);
    r = BTLV_INPUT_ProcessButtonSelection(input, (const BtlvInputSection *)table, (s8 (*)[12])neighbours, (u8 *)0, k, input->transformed);
    if (r != -1) {
        keys = KEY_GetCont();
        if (input->enabled[r] == 0 && (!(keys & 0x200) || input->screen != 2)) {
            if (input->enabled2[r] != 0 && input->screen == 2)
                BTLV_INPUT_PlayBackSe((void *)input);
            r = -1;
        } else if (r < 4 && (keys & 0x200) && input->screen == 2 && input->transformed == 1) {
            r = -1;
        } else if (r < 4 && (keys & 0x200) && input->screen == 2 && input->enabled2[r] == 0) {
            r = -1;
        } else if (k != -1) {
            if (BTLV_INPUT_IsWazaSelectable(input, (const BtlvInputSection *)table, r) == 0 && !input->flags2.choiceMade) {
                BTLV_INPUT_PlaySelectSe((void *)input);
                mode = input->screen;
                switch (mode) {
                case 1:
                case 2:
                case 5:
                    input->lastChoice[input->partyIdx][mode] = r;
                    break;
                case 3:
                    idx = 0;
                    if (input->battleType != 2)
                        cnt = d_0689E090[input->partyIdx][input->flags2.targetGroup];
                    else
                        cnt = d_0689E0B0[input->partyIdx][input->flags2.targetGroup];
                    if (input->battleType != 2)
                        e = gBtlvScdTargetRegionsSingleB[input->partyIdx][input->flags2.targetGroup];
                    else
                        e = gBtlvScdTargetRegionsDoubleB[input->partyIdx][input->flags2.targetGroup];
                    for (i = 0; i < cnt; i++) {
                        if (r == e[i].id) {
                            idx = i;
                            break;
                        }
                    }
                    input->lastChoice[input->partyIdx][mode] = (input->lastChoice[input->partyIdx][2] << 4) | idx;
                    break;
                }
            } else {
                BTLV_INPUT_PlayCursorSe((void *)input);
            }
        }
    }
    if (r != -1)
        r = BTLV_INPUT_SetSelection(input, r, table->vals[r]);
    return r;
}

int BTLV_INPUT_StepFingerDemo(BtlvInput *input)
{
    int r = 0;
    BtlvInputFingerTable t;

    switch (input->flags.fingerStep) {
    case 0:
        t = d_0220A598;
        if (input->fingerCursor == 0)
            input->fingerCursor = BTLV_FINGER_CURSOR_Create(input->palAnm, 0xb, input->heap);
        if (BTLV_FINGER_CURSOR_Start(input->fingerCursor, t.pos[input->flags.fingerPos].x, t.pos[input->flags.fingerPos].y, 2, 7, 0x10) != 0) {
            input->flags.fingerStep = input->flags.fingerStep + 1;
            input->flags.fingerPos = input->flags.fingerPos + 1;
        }
        break;
    case 1:
        r = BTLV_FINGER_CURSOR_IsActive(input->fingerCursor);
        if (r == 1)
            BTLV_INPUT_PlaySelectSe((void *)input);
        break;
    }
    return r;
}

int BTLV_INPUT_ProcessKeyInput(BtlvInput *input, u8 *key, int *out)
{
    int i;
    int a;
    u32 held;
    int r;

    if (input->flags.busy || PALANM_GetFadeRequestBits((const char *)input->palAnm) != 0 || input->flags.inputLock)
        return 0;
    if (KEY_GetTrg() & 8)
        BTLV_EFFECT_GaugeRequestStop();
    if (input->pending != -1) {
        i = input->pending & 0xFFFF7FFF;
        if (i < 5) {
            if (i < 4 && input->struggle == 1)
                input->pending = 7;
            *out = input->pending;
            *key = sBtlvInputSectionData.key[input->flags.slotIndex];
            input->pending = -1;
            input->flags2.choiceMade = 0;
            PALANM_RequestFadeOverwrite((void *)input->palAnm, 2, 0x3e00, 0, 0, 0, 0, input->taskMgr);
            PALANM_RequestFadeOverwrite((void *)input->palAnm, 8, 0x700, 0, 0, 0, 0, input->taskMgr);
            return 1;
        }
        input->flags.cursor = 0;
        input->lastChoice[input->partyIdx][input->screen] = 0;
        input->flags2.choiceMade = 0;
        BTLV_INPUT_PlayPageSe((void *)input);
        BTLV_INPUT_StartScreenTransition((void *)input, i);
        input->pending = -1;
        return 0;
    }
    if (input->struggle == 1) {
        a = TOUCHPANEL_HitTrg(sBtlvInputSectionData.db.buttons);
        i = BTLV_INPUT_ProcessButtonSelection(input, (const BtlvInputSection *)((Cmd *)(&sBtlvInputSectionData.db)), (s8 (*)[12])((int)(d_0220AE98[input->flags.slotIndex])), (u8 *)((int)0), a, BTL_POKEPARAM_IsTransformed(input->pokeParam[input->flags.slotIndex]));
    } else {
        a = TOUCHPANEL_HitTrg(sBtlvInputSectionData.da.buttons);
        i = BTLV_INPUT_ProcessButtonSelection(input, (const BtlvInputSection *)((Cmd *)(&sBtlvInputSectionData.da)), (s8 (*)[12])((int)(d_0220AEA4[input->flags.slotIndex])), (u8 *)((int)d_0220A380), a, BTL_POKEPARAM_IsTransformed(input->pokeParam[input->flags.slotIndex]));
    }
    if (i != -1) {
        held = KEY_GetCont();
        if (input->enabled[i] == 0 && !(held & 0x200)) {
            if (input->enabled2[i] != 0)
                BTLV_INPUT_PlayBackSe((void *)input);
            i = -1;
        } else if (i > 4 && input->enabled[i] == 0) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && (BTL_POKEPARAM_IsTransformed(input->pokeParam[input->flags.slotIndex]) == 1 || input->struggle == 1)) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && input->enabled2[i] == 0) {
            i = -1;
        }
    }
    if (i != -1) {
        if (input->struggle == 1) {
            r = BTLV_INPUT_IsWazaSelectable(input, (const BtlvInputSection *)(&sBtlvInputSectionData.db), i);
            if (r == 0 && !(input->flags2.choiceMade)) {
                input->lastChoice[input->partyIdx][input->screen] = i;
                BTLV_INPUT_PlayOpenSe((void *)input);
            } else if (r == 1 && !(input->flags2.choiceMade)) {
                BTLV_INPUT_PlayCursorSe((void *)input);
            }
            i = BTLV_INPUT_SetSelection(input, i, sBtlvInputSectionData.db.values[i]);
        } else {
            r = BTLV_INPUT_IsWazaSelectable(input, (const BtlvInputSection *)(&sBtlvInputSectionData.da), i);
            if (r == 0 && !(input->flags2.choiceMade)) {
                input->lastChoice[input->partyIdx][input->screen] = i;
                BTLV_INPUT_PlayOpenSe((void *)input);
            } else if (r == 1 && !(input->flags2.choiceMade)) {
                BTLV_INPUT_PlayCursorSe((void *)input);
            }
            i = BTLV_INPUT_SetSelection(input, i, sBtlvInputSectionData.da.values[i]);
        }
    }
    if (i != -1)
        return 1;
    return 0;
}

/*
 * trailing: 022033F0..022033F4 is an unlabelled 4-byte getter (ldr r0, [r0, #0x58]; bx lr).
 */
int BTLV_INPUT_IsInputBlocked(BtlvInput *input)
{
    if (input->flags.busy || PALANM_GetFadeRequestBits(input->palAnm) != 0 || input->flags.inputLock)
        return 1;
    return 0;
}

int BTLV_INPUT_GetScreen(BtlvInput *input)
{
    return input->screen;
}

/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 at +0072 has no admissible outside witness.
 * Verified C copied from ov029_func_021F0DB4.c's EXACT 8-byte scratch proof:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 * ARM9 belongs to the integrator. Caller sets r0 to the palette object, r1 to 1.
 */
void BTLV_INPUT_LoadCommonGraphics(BtlvInput *input)
{
    void *arc;
    u32 file;
    int i;

    ARC_UTIL_UploadBgCharFromHandle(input->arc, 0x5b, 4, 0, 0, 0, input->heap);
    ARC_UTIL_UploadBgCharFromHandle(input->arc, 0x71, 7, 0, 0x8000, 0, input->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(input->arc, 0x72, 7, 0, 0, 0, input->heap);
    PALANM_LoadHandlePaletteToSlot(input->palAnm, input->arc, 0x5c, input->heap, 1, 0x1e0, 0);
    if (input->infoWinEnabled == 1)
        MIi_CpuCopy16((const void *)(PALANM_GetDefaultWork((char *)BTLV_EFFECT_GetPalanm(), 1) + 0x40), input->palBackup, 0x20);
    input->resCommonChr = CLACT_RegisterCharacter(input->arc, 0x73, 0, 1, input->heap);
    input->resCommonCell = CLACT_RegisterCellAnim(input->arc, 0x75, 0x76, input->heap);
    input->resCommonPal = CLACT_RegisterPalette(input->arc, 0x74, 1, 0, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, (u16)(CLACT_GetPaletteVramAddress(input->resCommonPal, 1) >> 1), 0x100);
    input->resButtonChr = CLACT_RegisterCharacter(input->arc, 0x77, 0, 1, input->heap);
    input->resButtonCell = CLACT_RegisterCellAnim(input->arc, 0x78, 0x79, input->heap);
    arc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), (u16)((input->heap & 0x7fff) | 0x8000));
    file = APP_ICON_GetTypePaletteFileId(0);
    input->typeCell = CLACT_RegisterCellAnim(arc, file, APP_ICON_GetTypeAnimFileId(0), input->heap);
    input->typePal = CLACT_RegisterPalette(arc, APP_ICON_GetTouchBarFileId(), 1, 0x100, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, (u16)(CLACT_GetPaletteVramAddress(input->typePal, 1) >> 1), 0x60);
    for (i = 0; i < 4; i++)
        input->typeChr[i] = CLACT_RegisterCharacter(arc, APP_ICON_GetTypeCellFileId(0), 0, 1, input->heap);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * lever: case 1 and default share the completion arm.
 */
void BTLV_INPUT_ActionScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x68, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 1, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_StartBgWipeTask(ctx->input, 0, 0x1c0, 8, 8);
        BTLV_INPUT_BlendWindowPalette((void *)ctx->input);
        BMP_WIN_MakeScreen(ctx->input->bmpWinB);
        BG_SYS_PushTile(6);
        PALANM_RequestFadeOverwrite(ctx->input->palAnm, 2, 3, 1, 12, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinB);
            BG_SYS_SetPlaneVisible(4, 1);
            BG_SYS_SetPlaneVisible(5, 1);
            BG_SYS_SetPlaneVisible(7, 0);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_WazaScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x6f, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BG_SYS_PushTile(6);
        PALANM_RequestFadeOverwrite(ctx->input->palAnm, 2, 3, 1, 12, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
        if (ctx->input->flags.animTasks == 0) {
            if (ctx->input->battleType == 2 && ctx->slot != 4) {
                ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x5e, 4, 0, 0, 0, ctx->input->heap);
            } else {
                ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
            }
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            BG_SYS_PushTile(6);
            BTLV_INPUT_StartBgWipeTask(ctx->input, 0x100, 0x1c0, 8, 8);
            BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 0);
            BTLV_INPUT_StartPaletteFlashTask((void *)ctx->input, 0);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, -1, 0, 0, 1, 1, 2, 0);
            ctx->timer = 4;
            ctx->state++;
        }
        break;
    case 2:
        if (--ctx->timer == 0) {
            BTLV_INPUT_CreateCursorActors((void *)ctx->input, 0, 0);
            ctx->state++;
        }
        break;
    case 3:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

/*
 * trailing: 02203976..02203978 is two-byte alignment padding.
 * lever: case 2 shares its body with default, retaining the dead compare.
 */
void BTLV_INPUT_WazaScreenOpenInstantTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgWipeTask(ctx->input, 0x100, 0x1c0, 8, 8);
        BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 0);
        BTLV_INPUT_StartPaletteFlashTask((void *)ctx->input, 0);
        BTLV_INPUT_RestoreWindowPalette((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, -1, 0, 0, 1, 1, 2, 0);
        ctx->timer = 4;
        ctx->state++;
        break;
    case 1:
        if (--ctx->timer == 0) {
            BTLV_INPUT_CreateCursorActors((void *)ctx->input, 0, 0);
            ctx->state++;
        }
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_ActionScreenOpenInstantTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x68, 5, 0, 0, 0, ctx->input->heap);
        BMP_WIN_MakeScreen(ctx->input->bmpWinB);
        BTLV_INPUT_BlendWindowPalette((void *)ctx->input);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0xc0, 1, 1, 2, 0);
        ctx->state++;
        break;
    case 1:
        BTLV_INPUT_CreateCursorActors((void *)ctx->input, 0, 1);
        ctx->timer = 4;
        ctx->state++;
        break;
    case 2:
        if (--ctx->timer == 0) {
            BTLV_INPUT_StartBgWipeTask(ctx->input, 0, 0x1c0, 8, 8);
            BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 1);
            BTLV_INPUT_StartPaletteFlashTask((void *)ctx->input, 1);
            ctx->state++;
        }
        break;
    case 3:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BTLV_INPUT_SetActionUnitVisible((void *)ctx->input, 1);
            BMP_WIN_TransferChars(ctx->input->bmpWinB);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_TargetScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    int z = 0;

    ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x5d, 4, 0, z, z, ctx->input->heap);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, ctx->bgFile, 4, 0x440, 0x380, z, ctx->input->heap);
    BMP_WIN_MakeScreen(ctx->input->bmpWinA);
    BG_SYS_PushTile(6);
    if (ctx->input->battleType == 2) {
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x6a, 5, 0, z, z, ctx->input->heap);
    } else {
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x69, 5, 0, z, z, ctx->input->heap);
    }
    BMP_WIN_TransferChars(ctx->input->bmpWinA);
    BTLV_INPUT_DeleteTask((void *)ctx->input, (void *)task);
}

void BTLV_INPUT_WazaScreenCloseTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0xc0, 2, 2, 2, 2);
        ctx->state = ctx->state + 1;
        break;
    case 1:
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        BG_SYS_PushTile(6);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x68, 5, 0, 0, 0, ctx->input->heap);
        BMP_WIN_TransferChars(ctx->input->bmpWinA);
        CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
        BTLV_INPUT_DeleteTask((void *)ctx->input, (void *)task);
        break;
    }
}

void BTLV_INPUT_WaitScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x1000, 0x3000, 0x400, 0xa8);
        ctx->state = ctx->state + 1;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(4, 0);
        BG_SYS_SetPlaneVisible(5, 0);
        BG_SYS_SetPlaneVisible(7, 1);
        ctx->state = ctx->state + 1;
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0)
            BTLV_INPUT_DeleteTask((void *)ctx->input, (void *)task);
        break;
    }
}

void BTLV_INPUT_WaitScreenOpenInstantTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x6e, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0xc0, 1, 1, 2, 0);
        ctx->state++;
        break;
    case 1:
        if (ctx->fromScreen == 2 || ctx->fromScreen == 5)
            BTLV_INPUT_CreateCursorActors((void *)ctx->input, 0, 1);
        ctx->state++;
        ctx->timer = 4;
        break;
    case 2:
        if (--ctx->timer == 0) {
            BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 1);
            ctx->state++;
        }
        break;
    case 3:
        if (ctx->input->flags.animTasks == 0) {
            BTLV_INPUT_StartBgScrollTask(ctx->input, 0x1000, 0x3000, 0x400, 0xa8);
            ctx->state++;
        }
        break;
    case 4:
        BG_SYS_SetPlaneVisible(4, 0);
        BG_SYS_SetPlaneVisible(5, 0);
        BG_SYS_SetPlaneVisible(7, 1);
        ctx->state++;
        break;
    case 5:
    default:
        if (ctx->input->flags.animTasks == 0)
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        break;
    }
}

void BTLV_INPUT_MessageScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_RestoreWindowPalette((void *)ctx->input);
        PALANM_RequestFade(ctx->input->palAnm, 2, 3, 1, 0xc, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
        if (ctx->input->flags.animTasks == 0) {
            BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 0);
            BG_SYS_SetPlaneVisible(5, 1);
            BG_SYS_SetPlaneVisible(7, 0);
            ctx->state++;
        }
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            BG_SYS_PushTile(6);
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_ListScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x6f, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BG_SYS_PushTile(6);
        PALANM_RequestFadeOverwrite(ctx->input->palAnm, 2, 3, 1, 0xc, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
        if (ctx->input->flags.animTasks == 0) {
            ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x64, 4, 0, 0, 0, ctx->input->heap);
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            BG_SYS_PushTile(6);
            BTLV_INPUT_StartBgWipeTask(ctx->input, d_0220A4EC[ctx->input->flags.slotIndex].start, d_0220A4EC[ctx->input->flags.slotIndex].end, 8, 8);
            BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 0);
            BTLV_INPUT_StartPaletteFlashTask((void *)ctx->input, 0);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, -1, 0, 0, 1, 1, 2, 0);
            ctx->timer = 4;
            ctx->state++;
        }
        break;
    case 2:
        if (--ctx->timer == 0) {
            BTLV_INPUT_CreateCursorActors((void *)ctx->input, 0, 0);
            ctx->state++;
        }
        break;
    case 3:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_SelectScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x62, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x6d, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 1, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_StartBgWipeTask(ctx->input, 0, 0x1c0, 8, 8);
        PALANM_RequestFade(ctx->input->palAnm, 2, 3, 1, 0xc, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
    default:
        if (ctx->input->flags.animTasks == 0) {
            if (ctx->text != 0) {
                PRINTSYS_Print(ctx->input->bmpA, 0x18, 0x38, ctx->text, ctx->input->font);
                STRBUF_Delete(ctx->text);
            }
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            BG_SYS_PushTile(6);
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 4, ctx->scrollX, ctx->scrollY, 1, 1, 2, 0);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_ConfirmScreenOpenTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x63, 4, 0, 0, 0, ctx->input->heap);
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x6b, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 1, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_StartBgWipeTask(ctx->input, 0, 0x1c0, 8, 8);
        PALANM_RequestFade(ctx->input->palAnm, 2, 3, 1, 0xc, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BG_SYS_SetPlaneVisible(4, 1);
            BG_SYS_SetPlaneVisible(5, 1);
            BG_SYS_SetPlaneVisible(7, 0);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_ListScreenOpenInstantTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        ARC_UTIL_UploadBgPaletteFromHandle((void *)ctx->input->arc, 0x64, 4, 0, 0, 0, ctx->input->heap);
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        BTLV_INPUT_RestoreWindowPalette((void *)ctx->input);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgWipeTask(ctx->input, d_0220A4EC[ctx->input->flags.slotIndex].start, d_0220A4EC[ctx->input->flags.slotIndex].end, 8, 8);
        BTLV_INPUT_StartPaletteCycleTask((void *)ctx->input, 0, 0);
        BTLV_INPUT_StartPaletteFlashTask((void *)ctx->input, 0);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, -1, 0, 0, 1, 1, 2, 0);
        ctx->timer = 4;
        ctx->state++;
        break;
    case 1:
        if (--ctx->timer == 0) {
            BTLV_INPUT_CreateCursorActors((void *)ctx->input, 0, 0);
            ctx->state++;
        }
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

void BTLV_INPUT_ScreenResetTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        BTLV_INPUT_ClearButtonState((void *)ctx->input);
        ctx->state++;
        break;
    case 1:
        BTLV_INPUT_InitButtonState((void *)ctx->input);
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgWipeTask(ctx->input, d_0220A4EC[ctx->input->flags.slotIndex].start, d_0220A4EC[ctx->input->flags.slotIndex].end, 8, 8);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, -1, 0, 0, 1, 1, 2, 0);
        ctx->state++;
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        }
        break;
    }
}

/* Work of the vertical slide task (allocated by BTLV_INPUT_StartBgScrollTask). */
typedef struct BtlvInputSlideTask {
    BtlvInput *input;
    int cur;                /* current scroll position */
    int goal;               /* position at which the task ends */
    int step;               /* signed change per frame */
    int scroll;             /* second scroll register value */
} BtlvInputSlideTask;

/* Work of the background scroll task (allocated by BTLV_INPUT_StartBgWipeTask). */
typedef struct BtlvInputScrollTask {
    BtlvInput *input;
    int state;
    int x;
    int y;
    int dy;                 /* change of y per frame */
    int count;              /* frames left */
} BtlvInputScrollTask;

void BTLV_INPUT_TaskEndClearBusyBit(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.busy = 0;
}

void BTLV_INPUT_StartBgScrollTask(BtlvInput *input, int startScale, int goalScale, int step, int scrollY)
{
    BtlvInputSlideTask *o;

    o = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 0x14, 0, d_0220AEB0, 0xb97);
    o->input = input;
    o->cur = startScale;
    o->goal = goalScale;
    o->step = step;
    o->scroll = scrollY;
    BTLV_INPUT_RegisterTask((void *)input, (int)GFL_USE_AddMainTask(BTLV_INPUT_BgScrollTaskMain, o, 0), (int)BTLV_INPUT_BgScrollTaskEnd);
    input->flags.animTasks = input->flags.animTasks + 1;
}

void BTLV_INPUT_BgScrollTaskMain(void *task, void *arg)
{
    BtlvInputSlideTask *o = arg;
    int m[4];

    o->cur = o->cur + o->step;
    if (o->step > 0)
        o->scroll = o->scroll - 2;
    else if (o->step < 0)
        o->scroll = o->scroll + 2;
    MTX_Scale22_(m, o->cur, o->cur);
    BG_SYS_SetScroll(7, 0, 0x80, (u32)m, 0x100, 0x100);
    BG_SYS_SetScroll(7, 3, o->scroll, (u32)m, 0x100, 0x100);
    if (o->cur == o->goal)
        BTLV_INPUT_DeleteTask((void *)o->input, (void *)task);
}

void BTLV_INPUT_BgScrollTaskEnd(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.animTasks--;
}

void BTLV_INPUT_StartBgWipeTask(BtlvInput *input, int x, int y, int dy, int count)
{
    BtlvInputScrollTask *o;

    o = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 0x18, 0, d_0220AEB0, 0xbd5);
    o->input = input;
    o->state = 0;
    o->x = x;
    o->y = y;
    o->dy = dy;
    o->count = count;
    BTLV_INPUT_RegisterTask((void *)input, (int)GFL_USE_AddMainTask(BTLV_INPUT_BgWipeTaskMain, o, 0), (int)BTLV_INPUT_BgWipeTaskEnd);
    input->flags.animTasks = input->flags.animTasks + 1;
}

void BTLV_INPUT_BgWipeTaskMain(void *task, void *arg)
{
    BtlvInputScrollTask *c = arg;

    if (c->state == 0) {
        BG_SYS_ChangeScrollImmediate(4, 0, c->x);
        BG_SYS_ChangeScrollImmediate(4, 3, c->y);
        c->state = c->state + 1;
        return;
    }
    c->y = c->y + c->dy;
    BG_SYS_ChangeScrollImmediate(4, 3, c->y);
    c->count = c->count - 1;
    if (c->count == 0)
        BTLV_INPUT_DeleteTask((void *)c->input, (void *)task);
}

void BTLV_INPUT_BgWipeTaskEnd(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.animTasks--;
}

void BTLV_INPUT_StartPaletteCycleTask(BtlvInput *input, int unused, int palSet)
{
    BtlvInputPaletteCycleTask *t;

    t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x10, 0, d_0220AEB0, 0xc10);
    t->input = input;
    t->tab = 0;
    t->palSet = palSet;
    t->count = 2;
    BTLV_INPUT_RegisterTask((void *)input, (int)GFL_USE_AddMainTask(BTLV_INPUT_PaletteCycleTaskMain, t, 0), (int)BTLV_INPUT_PaletteCycleTaskEnd);
    input->flags.animTasks = input->flags.animTasks + 1;
}

/*
 * lever:    the table extern is `const` (non-const put the count store before the address add)
 */
void BTLV_INPUT_PaletteCycleTaskMain(void *task, void *arg)
{
    BtlvInputPaletteCycleTask *t = arg;

    int i;

    t->count = t->count - 1;
    if (t->count == 0) {
        t->count = 2;
        BG_SYS_ChangeScrollImmediate(5, 0, d_0220A46C[t->palSet][t->tab].color0);
        i = t->tab;
        t->tab = i + 1;
        BG_SYS_ChangeScrollImmediate(5, 3, d_0220A46C[t->palSet][i].color1);
        if (t->tab >= 2)
            BTLV_INPUT_DeleteTask((void *)t->input, task);
    }
}

void BTLV_INPUT_PaletteCycleTaskEnd(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.animTasks--;
}

/*
 * note: the row offset goes into the row pointer first and the table base is added
 *   to it (base + offset); that order gives the original r0/r1 colouring at +0056.
 */
void BTLV_INPUT_CreateCursorActors(BtlvInput *input, int rowIndex, int animIndex)
{
    BtlvInputCursorActorTask *t;
    u16 v;
    int i;
    BtlvInputCursorRow *row;
    Quad quad;

    t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x20, 0, d_0220AEB0, 0xc53);
    quad = d_0220A53C;
    t->input = input;
    t->unit = CLACT_CreateUnit(6, 0, input->heap);
    row = (BtlvInputCursorRow *)(rowIndex << 5);
    row = (BtlvInputCursorRow *)((u32)d_0220A85C + (u32)row);
    v = row->animSeq[animIndex];
    for (i = 0; i < 6; i++) {
        if (row->point[i].x == -1) {
            t->actors[i] = 0;
        } else {
            t->actors[i] = (struct Obj *)CLACT_CreateActor(t->unit, input->resCommonChr, input->resCommonPal, input->resCommonCell, &quad, 1, input->heap);
            CLACT_AddActorSurfacePos((struct Obj *)(t->actors[i]), (const struct Vec2 *)(&row->point[i]), 1);
            CLACT_SetActorAffineMode(t->actors[i], 2);
            CLACT_SetActorAutoAnim((struct Obj *)(t->actors[i]), 1);
            CLACT_SetActorAnimSeq(t->actors[i], v);
        }
    }
    BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_CursorActorTaskMain, t, 0), (int)BTLV_INPUT_CursorActorTaskEnd);
    input->flags.animTasks++;
}

void BTLV_INPUT_CursorActorTaskMain(void *task, void *arg)
{
    BtlvInputCursorActorTask *t = arg;

    int i;
    for (i = 0; i < 6; i++) {
        if (t->actors[i] != 0 && CLACT_IsActorAnimActive(t->actors[i]) != 0)
            return;
    }
    BTLV_INPUT_DeleteTask((void *)t->input, task);
}

void BTLV_INPUT_CursorActorTaskEnd(void *task)
{
    BtlvInputCursorActorTask *t = (BtlvInputCursorActorTask *)TCBL_IsDeletePending(task);
    int i;

    for (i = 0; i < 6; i++) {
        if (t->actors[i] != 0)
            CLACT_DeleteActor((struct Obj *)(t->actors[i]));
    }
    CLACT_DeleteUnit((struct Bank *)((int)((struct Bank *)t->unit)));
    t->input->flags.animTasks = t->input->flags.animTasks - 1;
}

void BTLV_INPUT_StartPaletteFlashTask(BtlvInput *input, int kind)
{
    BtlvInputPaletteFlashTask *t;

    t = GFL_HEAP_Alloc(HEAPID(input->heap), 8, 0, d_0220AEB0, 0xcc9);
    t->input = input;
    t->kind = kind;
    BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_PaletteFlashTaskMain, t, 0), (int)BTLV_INPUT_PaletteFlashTaskEnd);
    input->flags.animTasks = input->flags.animTasks + 1;
}

void BTLV_INPUT_PaletteFlashTaskMain(void *task, void *arg)
{
    BtlvInputPaletteFlashTask *t = arg;

    int k;
    int changed = 0;
    int target;
    char *p;
    int j;
    short v[2];

    for (k = 0; k < 2; k++) {
        target = d_0220A3B4[k][t->kind];
        if (k == 0) {
            p = (char *)t->input + 0x47 * 4;
        } else {
            if (t->input->flags.doubleCursor == 0) {
                break;
            }
            p = (char *)t->input + 0x53 * 4;
        }
        for (j = 0; j < 6; j++) {
            CLACT_GetActorSurfacePos(*(void **)(p + j * 8), (struct PtS *)v, 1);
            if (v[1] > target) {
                v[1] = v[1] - 4;
                changed = 1;
            } else if (v[1] < target) {
                v[1] = v[1] + 4;
                changed = 1;
            }
            CLACT_AddActorSurfacePos((struct Obj *)(*(void **)(p + j * 8)), (const struct Vec2 *)v, 1);
        }
    }
    if (changed == 0) {
        BTLV_INPUT_DeleteTask((void *)t->input, task);
    }
}

void BTLV_INPUT_PaletteFlashTaskEnd(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.animTasks--;
}

void BTLV_INPUT_StartBgScrollOffsetTask(BtlvInput *input, int bg, int scrollX, int scrollY, int bg4, int bg5, int bg6, int bg7)
{
    BtlvInputBgScrollOffsetTask *t;

    t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x20, 0, d_0220AEB0, 0xd1d);
    t->input = input;
    t->bg = bg;
    t->scrollX = scrollX;
    t->scrollY = scrollY;
    t->bg4 = bg4;
    t->bg5 = bg5;
    t->bg6 = bg6;
    t->bg7 = bg7;
    BTLV_INPUT_RegisterTask((void *)input, (int)GFL_USE_AddMainTask(BTLV_INPUT_BgScrollOffsetTaskMain, t, 0), 0);
}

void BTLV_INPUT_BgScrollOffsetTaskMain(void *task, void *arg)
{
    BtlvInputBgScrollOffsetTask *t = arg;

    if (t->bg != -1) {
        BG_SYS_ChangeScrollImmediate((u8)t->bg, (int)0, (int)t->scrollX);
        BG_SYS_ChangeScrollImmediate((u8)t->bg, (int)3, (int)t->scrollY);
    }
    if (t->bg4 != 2) {
        BG_SYS_SetPlaneVisible((int)4, (u8)t->bg4);
    }
    if (t->bg5 != 2) {
        BG_SYS_SetPlaneVisible((int)5, (u8)t->bg5);
    }
    if (t->bg6 != 2) {
        BG_SYS_SetPlaneVisible((int)6, (u8)t->bg6);
    }
    if (t->bg7 != 2) {
        BG_SYS_SetPlaneVisible((int)7, (u8)t->bg7);
    }
    BTLV_INPUT_DeleteTask((void *)t->input, task);
}

void BTLV_INPUT_WaitFadeTaskMain(void *task, void *arg)
{
    BtlvInput **q = arg;

    if (PALANM_GetFadeRequestBits((*q)->palAnm) != 0)
        return;
    if (FADE_IsActive() != 0)
        return;
    if ((*q)->flags.fadeKind == 1)
        BTLV_INPUT_ReleaseScreenResources(*q);
    BTLV_INPUT_DeleteTask((void *)*q, task);
}

void BTLV_INPUT_WaitFadeTaskEnd(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.fadeKind = 0;
}

void BTLV_INPUT_CursorMoveTaskMain(void *task, void *arg)
{
    BtlvInput **q = arg;

    short v[2];

    CLACT_GetActorSurfacePos((*q)->statusActors[0], (struct PtS *)v, 1);
    v[0] -= 8;
    CLACT_AddActorSurfacePos((struct Obj *)((*q)->statusActors[0]), (const struct Vec2 *)v, 1);
    CLACT_GetActorSurfacePos((*q)->statusActors[1], (struct PtS *)v, 1);
    v[0] -= 8;
    CLACT_AddActorSurfacePos((struct Obj *)((*q)->statusActors[1]), (const struct Vec2 *)v, 1);
    if (v[0] == 0xe0) {
        BTLV_INPUT_DeleteTask((void *)*q, task);
    }
}

void BTLV_INPUT_CursorMoveTaskEnd(void *task)
{
    BtlvInput *input = *(BtlvInput **)TCBL_IsDeletePending(task);
    input->flags.animTasks--;
}

void BTLV_INPUT_StartScreenTransition(BtlvInput *input, int screen)
{
    BtlvInputTask *t;
    int k;

    t = GFL_HEAP_Alloc(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0xd8c);
    k = input->flags.slotIndex;
    input->flags.slotIndex = d_0220A38C[k][screen - 5];
    input->flags.busy = 1;
    t->input = input;
    BTLV_INPUT_RegisterTask((void *)input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ScreenResetTask, t, 1), (int)((void *)BTLV_INPUT_TaskEndClearBusyBit));
    BTLV_EFFECT_ResetIntroState(2);
    BTLV_EFFECT_StartEffect(d_0220A3E4[k][screen - 5]);
}

void BTLV_INPUT_VisibilityTaskMain(void *task, void *arg)
{
    BtlvInputVisibilityTask *r = arg;

    if (BTLV_EFFECT_GetWorkPtr() != 0) {
        BTLV_EFFECT_SetVisibilityMode(r->mode);
        BTLV_INPUT_DeleteTask((void *)r->owner, task);
    }
}

static inline void GXS_SetVisibleWnd(int mask)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0xe000) | ((u32)mask << 13);
}

static inline void G2S_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}

static inline void G2S_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f00) | ((u32)wnd << 8));
    if (effect) {
        tmp |= (0x20 << 8);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}

static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}

static inline void G2S_SetBlendBrightness(int plane, int brightness)
{
    G2x_SetBlendBrightness_((u32)&reg_G2S_DB_BLDCNT, plane, brightness);
}

/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204BD4..0x02204C20)
 */
void BTLV_INPUT_WindowOpenTaskMain(void *task, void *arg)
{
    int *c = arg;

    GXS_SetVisibleWnd(3);
    G2S_SetWnd0InsidePlane(0x1f, c[1] > 1);
    G2S_SetWnd1InsidePlane(0x1f, c[1] == 3);
    G2S_SetWndOutsidePlane(0x1f, 0);
    G2S_SetBlendBrightness(0x10, -8);
    BTLV_INPUT_DeleteTask((void *)c[0], task);
}

static inline void G2S_BlendNone(void)
{
    G2x_SetBlendBrightness_((u32)&reg_G2S_DB_BLDCNT, 0, 0);
}

/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204C4C..0x02204C76)
 */
void BTLV_INPUT_WindowCloseTaskMain(void *task, void *arg)
{
    int *c = arg;

    GXS_SetVisibleWnd(0);
    G2S_SetWnd0InsidePlane(0, 0);
    G2S_SetWnd1InsidePlane(0, 0);
    G2S_SetWndOutsidePlane(0, 0);
    G2S_BlendNone();
    BTLV_INPUT_DeleteTask((void *)c[0], task);
}

void BTLV_INPUT_GetTextBlockSize(struct StrObj *str, int font, int *outCount, int *outCapacity)
{
    int n = GF_FONT_MeasureWidestLine(str, font, 0);
    int q = n / 8;
    if (FX_ModS32(n, 8) != 0)
        q++;
    *outCount = n;
    *outCapacity = q;
}

#pragma opt_common_subs off

#pragma opt_propagation off

/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of APP_ICON_GetArchiveId. Left: register allocation. The image keeps q in r6 and
 *   recomputes p + i*4, q + i*2 and q + i after every call (only i*8 lives in r7, k
 *   and font are spilled, font at sp+0x9c just under c); 1.1p1 CSEs those sums
 *   across the calls, so q spills, k takes r7 and every slot shifts. Breaking the
 *   CSEs with (u32)i / (s32)(u32)i casts per call group plus a temporary for the
 *   CLACT_CreateActor result (so the store address is formed after the call) gets the
 *   p/i registers and the per-call recompute, but q still lands in r7 and k in r6.
 *   Also open: GF_FONT_SetTextColor's colour arguments are evaluated r2, r1, r0 in the
 *   image (col kept in r0), ours evaluates r0 first and copies col to r3.
 * note (2026-10-02, lane A2-06): source now has the casts per call group (the
 *   recompute pattern of every p/q/i sum matches the image), the obj temporary,
 *   a Work_v3E30 struct for p, and (&tbl[i].x)[1] for the three y arguments: plain
 *   .y makes 1.1p1 form tbl + i*8 at the head of the call and spill it (sibling
 *   022050F0 does that, this image does not); the (&x)[1] spelling reproduces
 *   the image's x-load, w/2, late y-address order (checked in a loop probe).
 *   Measured inert for the allocator: block-scoped k/arc/chr/obj, heap inline,
 *   if/else inverted, x in a local, u8 locals or u8/u32 prototype for the
 *   colour call, font as a pointer, u32, long or u16, the cast spelling set itself, a
 *   q copy local, dead q uses. Still open, all allocator: q r7 (image r6), k
 *   and pltt take r6 (image spills both, k at sp+0x30, pltt at sp+0x3c), the
 *   second w/2 temp lands in r6 (image spills it to sp+0x68), frame 0x10c vs
 *   0x118, and the image's t1 call copies i*8 (adds r2, r7, #0). Slot order in
 *   the image is reverse declaration with font last (sp+0x9c); ours spills font
 *   right after file. volatile font declared last puts font just under c but
 *   flips p/i (image p r4, i r5); a 4-byte struct Font gets frame 0x118.
 *   Witness gaps once bytes match: APP_ICON_GetTypeCellFileId, APP_ICON_GetTypePaletteOffset (arm, no caller
 *   outside this body) and the six d_0220Axxx tables are unresolved relocations.
 * note (2026-10-02, lane A2 follow-up): cause found, not closable under the
 *   lane rules. The image is this body compiled with global CSE off: with
 *   `#pragma opt_common_subs off` above the function, the natural spelling
 *   (no index casts, no obj temporary, plain tbl[i].y) gives 1072 bytes, frame
 *   0x118, p r4 / i r5, font at sp+0x9c and every spill and hoist slot of the
 *   image's prologue, and only 308 bytes differ. The casts, obj and (&x)[1]
 *   in this draft are stand-ins that emulate CSE-off. The `(i < 4) ? 1 : 0`
 *   condition is still needed (CSE-off alone still rotates a plain loop: 547).
 *   Left with the pragma: q r7 / i*8 r6 (image q r6 / i*8 r7), the slot order
 *   of the 0x224/0x22c hoisted constants (first print group lowest, image
 *   highest), the w/2 sign temp spilled in the first print (image: third), the
 *   colour call channels evaluated r0 first (image r2 first; u8 r/g/b locals
 *   are copy-propagated, inert), and 0x06600000 + buf operand order.
 *   Measured as NOT disabling the CSE (probes and full body): int/u8/u16/s16_02203E30/
 *   u32/long/enum counter, register on params/counter, volatile Slots, void *
 *   params cast per use, static inline accessor, raw `char *` offsets in every
 *   form ((s + i * 4) + K, s + (i * 4 + K), ((T *)(s + K))[i]), up to 100
 *   extra locals, 3000 extra statements, 1500 extra branches, switch, static
 *   local, function pointer, struct copy/return, varargs, bit-field, float,
 *   division, long long. `asm { nop }` disables it but also constant
 *   propagation (offsets go to the pool), so not that either. The pragma is
 *   user-approved 2026-10-02.
 * note (2026-10-02, lane A2 pragma): neighbour check. The CSE-off pattern is
 *   per-function, not per-file: the EXACT next function BTLV_INPUT_DrawTargetButtons (same
 *   Work_v3E30 struct, same print callees, normal settings) keeps i*12 at sp+0x14
 *   and p+i*12 at sp+0x10 and reuses both after calls (ldr r2,[sp,#0x10] at
 *   0x022051B4 after blx 0x02045EC0; ldr r0,[sp,#0x14] at 0x02205212 after
 *   blx 0x02045808), which CSE off cannot produce. So the pragma is scoped
 *   to this function (opt_common_subs off ... reset).
 *   Result: CSE off alone leaves 309 bytes. The image also needs
 *   `#pragma opt_propagation off` (user-approved 2026-10-02). `#pragma
 *   opt_dead_assignments off` in its place gives byte-identical output, so
 *   which of the two the original used cannot be recovered. Both are scoped
 *   to this function with reset after it: the neighbour evidence above
 *   (022050F0 compiled with normal settings) shows the settings are
 *   per-function.
 *   What closes the rest once both pragmas are on: (1) the colour channels
 *   as u8 locals assigned b, g, r and passed r, g, b (keeps col in r0, the
 *   image's r2-first order, and with it q r6 / i*8 r7, the 0x224/0x22c hoist
 *   slot order and the w/2 spill in the third print); (2) `const Slots *q`
 *   (q + i formed before the stack-argument stores of both WORDSET_SetSlotNumber
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling BTLV_INPUT_CreateBackActor
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, APP_ICON_GetTypePaletteOffset, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/APP_ICON_GetTypePaletteOffset.c, EXACT).
 */
/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of APP_ICON_GetArchiveId. Left: register allocation. The image keeps q in r6 and
 *   recomputes p + i*4, q + i*2 and q + i after every call (only i*8 lives in r7, k
 *   and font are spilled, font at sp+0x9c just under c); 1.1p1 CSEs those sums
 *   across the calls, so q spills, k takes r7 and every slot shifts. Breaking the
 *   CSEs with (u32)i / (s32)(u32)i casts per call group plus a temporary for the
 *   CLACT_CreateActor result (so the store address is formed after the call) gets the
 *   p/i registers and the per-call recompute, but q still lands in r7 and k in r6.
 *   Also open: GF_FONT_SetTextColor's colour arguments are evaluated r2, r1, r0 in the
 *   image (col kept in r0), ours evaluates r0 first and copies col to r3.
 * note (2026-10-02, lane A2-06): source now has the casts per call group (the
 *   recompute pattern of every p/q/i sum matches the image), the obj temporary,
 *   a Work struct for p, and (&tbl[i].x)[1] for the three y arguments: plain
 *   .y makes 1.1p1 form tbl + i*8 at the head of the call and spill it (sibling
 *   022050F0 does that, this image does not); the (&x)[1] spelling reproduces
 *   the image's x-load, w/2, late y-address order (checked in a loop probe).
 *   Measured inert for the allocator: block-scoped k/arc/chr/obj, heap inline,
 *   if/else inverted, x in a local, u8 locals or u8/u32 prototype for the
 *   colour call, font as a pointer, u32, long or u16, the cast spelling set itself, a
 *   q copy local, dead q uses. Still open, all allocator: q r7 (image r6), k
 *   and pltt take r6 (image spills both, k at sp+0x30, pltt at sp+0x3c), the
 *   second w/2 temp lands in r6 (image spills it to sp+0x68), frame 0x10c vs
 *   0x118, and the image's t1 call copies i*8 (adds r2, r7, #0). Slot order in
 *   the image is reverse declaration with font last (sp+0x9c); ours spills font
 *   right after file. volatile font declared last puts font just under c but
 *   flips p/i (image p r4, i r5); a 4-byte struct Font gets frame 0x118.
 *   Witness gaps once bytes match: APP_ICON_GetTypeCellFileId, APP_ICON_GetTypePaletteOffset (arm, no caller
 *   outside this body) and the six d_0220Axxx tables are unresolved relocations.
 * note (2026-10-02, lane A2 follow-up): cause found, not closable under the
 *   lane rules. The image is this body compiled with global CSE off: with
 *   `#pragma opt_common_subs off` above the function, the natural spelling
 *   (no index casts, no obj temporary, plain tbl[i].y) gives 1072 bytes, frame
 *   0x118, p r4 / i r5, font at sp+0x9c and every spill and hoist slot of the
 *   image's prologue, and only 308 bytes differ. The casts, obj and (&x)[1]
 *   in this draft are stand-ins that emulate CSE-off. The `(i < 4) ? 1 : 0`
 *   condition is still needed (CSE-off alone still rotates a plain loop: 547).
 *   Left with the pragma: q r7 / i*8 r6 (image q r6 / i*8 r7), the slot order
 *   of the 0x224/0x22c hoisted constants (first print group lowest, image
 *   highest), the w/2 sign temp spilled in the first print (image: third), the
 *   colour call channels evaluated r0 first (image r2 first; u8 r/g/b locals
 *   are copy-propagated, inert), and 0x06600000 + buf operand order.
 *   Measured as NOT disabling the CSE (probes and full body): int/u8/u16/s16/
 *   u32/long/enum counter, register on params/counter, volatile Slots, void *
 *   params cast per use, static inline accessor, raw `char *` offsets in every
 *   form ((s + i * 4) + K, s + (i * 4 + K), ((T *)(s + K))[i]), up to 100
 *   extra locals, 3000 extra statements, 1500 extra branches, switch, static
 *   local, function pointer, struct copy/return, varargs, bit-field, float,
 *   division, long long. `asm { nop }` disables it but also constant
 *   propagation (offsets go to the pool), so not that either. The pragma is
 *   user-approved 2026-10-02.
 * note (2026-10-02, lane A2 pragma): neighbour check. The CSE-off pattern is
 *   per-function, not per-file: the EXACT next function BTLV_INPUT_DrawTargetButtons (same
 *   Work struct, same print callees, normal settings) keeps i*12 at sp+0x14
 *   and p+i*12 at sp+0x10 and reuses both after calls (ldr r2,[sp,#0x10] at
 *   0x022051B4 after blx 0x02045EC0; ldr r0,[sp,#0x14] at 0x02205212 after
 *   blx 0x02045808), which CSE off cannot produce. So the pragma is scoped
 *   to this function (opt_common_subs off ... reset).
 *   Result: CSE off alone leaves 309 bytes. The image also needs
 *   `#pragma opt_propagation off` (user-approved 2026-10-02). `#pragma
 *   opt_dead_assignments off` in its place gives byte-identical output, so
 *   which of the two the original used cannot be recovered. Both are scoped
 *   to this function with reset after it: the neighbour evidence above
 *   (022050F0 compiled with normal settings) shows the settings are
 *   per-function.
 *   What closes the rest once both pragmas are on: (1) the colour channels
 *   as u8 locals assigned b, g, r and passed r, g, b (keeps col in r0, the
 *   image's r2-first order, and with it q r6 / i*8 r7, the 0x224/0x22c hoist
 *   slot order and the w/2 spill in the third print); (2) `const Slots *q`
 *   (q + i formed before the stack-argument stores of both WORDSET_SetSlotNumber
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling BTLV_INPUT_CreateBackActor
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, APP_ICON_GetTypePaletteOffset, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/APP_ICON_GetTypePaletteOffset.c, EXACT).
 */
void BTLV_INPUT_DrawWazaButtons(BtlvInput *input, const Slots *slots)
{
    BtlvInputTextPosRow t1 = d_0220A5B0;
    BtlvInputTextPosRow t2 = d_0220A5D0;
    int font;
    void *pltt;
    void *chr;
    u32 arc;
    int k;
    int file;
    void *str1;
    void *m0;
    void *str2;
    void *m2;
    void *m1;
    u16 heap;
    int i;
    Struct36 buf;
    int w;
    int h;
    void *cd;
    void *pd;
    u8 c[3];
    int col;
    u8 cr, cg, cb;
    enum { VRAM_BASE = 0x06600000 } vram;

    str1 = STRBUF_Create(0x10, input->heap);
    m0 = MSGDATA_AllocString(input->msgData, 0);
    m1 = MSGDATA_AllocString(input->msgData, 1);
    font = (int)WORDSET_CreateDefault(input->heap);
    str2 = STRBUF_Create(0x10, input->heap);
    m2 = MSGDATA_AllocString(input->msgData, 2);
    CLACT_SetUnitDrawEnable(input->unitWaza, 0);
    for (i = 0; (i < 4) ? 1 : 0; i++) {
        if (slots->id[i] != 0) {
            k = WAZA_TOOL_GetParam(slots->id[i], 0);
            file = d_0220A5F0[k];
            input->wazaActors[i] = (struct Obj *)CLACT_CreateActor(input->unitWaza, input->typeChr[i], input->typePal, input->typeCell, d_0220A392, 1, input->heap);
            CLACT_AddActorSurfacePos((struct Obj *)(input->wazaActors[i]), (const struct Vec2 *)(&d_0220A3C4[i]), (int)1);
            heap = (input->heap & 0x7fff) | 0x8000;
            arc = APP_ICON_GetArchiveId();
            chr = ARC_UTIL_LoadScreenDataFromArchive(arc, APP_ICON_GetTypeCellFileId((u8)k), 0, (u32)(&cd), heap);
            CLACT_SetActorPaletteOffset(input->wazaActors[i], APP_ICON_GetTypePaletteOffset((u8)k), 1);
            CLACT_GetActorImageProxy(input->wazaActors[i], (struct Struct36 *)(&buf));
            vram = VRAM_BASE;
            MIi_CpuCopy16(((BtlvInputScreenFile *)cd)->tileGfx, (void *)(vram + buf.w[2]), 0x100);
            GFL_HEAP_Free(chr);
            GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
            GF_FONT_SetTextColor(1, 2, 0);
            WORDSET_SetSlotFromMsgCB((struct WordSet *)font, 0, slots->id[i]);
            WORDSET_CopyTaggedText((struct WordSet *)font, str1, m0);
            BTLV_INPUT_GetTextBlockSize(str1, (int)input->font, &w, &h);
            PRINTSYS_Print(input->bmpA, d_0220A4AC[i].x - w / 2, d_0220A4AC[i].y, str1, input->font);
            WORDSET_SetSlotNumber(font, 0, slots->a[i], 2, 1, 1);
            WORDSET_SetSlotNumber(font, 1, slots->b[i], 2, 1, 1);
            WORDSET_CopyTaggedText((struct WordSet *)font, str2, m2);
            col = BTLV_INPUT_GetPpTextColor(slots->a[i], slots->b[i]);
            cb = (u8)(col & 0x1f);
            cg = (u8)((col >> 5) & 0x1f);
            cr = (u8)((col >> 10) & 0x1f);
            GF_FONT_SetTextColor(cr, cg, cb);
            PRINTSYS_Print(input->bmpA, t1.pos[i].x, t1.pos[i].y, m1, input->font);
            BTLV_INPUT_GetTextBlockSize(str2, (int)input->font, &w, &h);
            PRINTSYS_Print(input->bmpA, t2.pos[i].x - w / 2, t2.pos[i].y, str2, input->font);
            GF_FONT_SetTextColor(c[2], c[1], c[0]);
            input->enabled[i] = slots->a[i] != 0;
            input->enabled2[i] = slots->id[i] != 0;
        } else {
            file = 0xc1;
        }
        heap = (input->heap & 0x7fff) | 0x8000;
        pltt = ARC_UTIL_LoadPaletteBlockFromArchive(0xb, file, (u32)(&pd), heap);
        PALANM_CopyToSlot(input->palAnm, ((BtlvInputPaletteFile *)pd)->palette, (int)1, (u16)(i * 16 + 0x90), 0x20);
        GFL_HEAP_Free(pltt);
    }
    input->enabled[i] = 1;
    if (input->battleType == 2) {
        input->enabled[i + 1] = 1;
    }
    WORDSET_Delete((struct WordSet *)font);
    STRBUF_Delete(str1);
    STRBUF_Delete(m1);
    STRBUF_Delete(m0);
    STRBUF_Delete(m2);
    STRBUF_Delete(str2);
}

#pragma opt_propagation reset

#pragma opt_common_subs reset

void BTLV_INPUT_DrawTargetButtons(BtlvInput *input, Out *out, const BtlvInputTargetInfo *targetInfo)
{
    int n;
    int k;
    int i;
    int m;
    int idx;
    void *v;
    int h;
    void *w;
    void *r;
    int ww;
    int hh;
    BtlvInputTargetRes *res;
    u8 c[3];

    n = (input->battleType == 2) ? 6 : 4;
    k = (input->battleType == 2) ? 1 : 0;
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    v = STRBUF_Create(12, (u16)((input->heap & 0x7fff) | 0x8000));
    h = (int)WORDSET_CreateDefault((u16)((input->heap & 0x7fff) | 0x8000));
    GF_FONT_SetTextColor(1, 2, 0);
    for (i = 0; i < n; i++) {
        if (targetInfo->buttons[i].show != 0) {
            w = MSGDATA_AllocString(input->msgData, targetInfo->buttons[i].kind + 3);
            WORDSET_SetSlotMonNickname((void *)h, 0, targetInfo->buttons[i].text);
            WORDSET_CopyTaggedText((struct WordSet *)h, v, w);
            BTLV_INPUT_GetTextBlockSize((struct StrObj *)v, (int)input->font, &ww, &hh);
            PRINTSYS_Print((void *)(input->bmpA), d_0220A7FC[k][i][0] - ww / 2, d_0220A7FC[k][i][1], v, (void *)(input->font));
            STRBUF_Delete(w);
        }
        input->enabled[i] = targetInfo->buttons[i].flag;
    }
    input->enabled[i] = 1;
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    WORDSET_Delete((struct WordSet *)h);
    STRBUF_Delete(v);
    idx = (targetInfo->battlerCount - 2) / 2;
    input->flags2.targetGroup = targetInfo->targetGroup;
    out->bgFile = d_0220A94C[k][idx][targetInfo->targetGroup];
    m = 3;
    if (input->battleType != 2)
        m = 2;
    for (i = 0; i < m; i++) {
        r = ARC_UTIL_LoadPaletteBlockFromArchive(11, 0xd3, (u32)(&res), (u16)((input->heap & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(input->palAnm), res->palette, 1, (u16)(i * 16 + 0x70), 0x20);
        GFL_HEAP_Free(r);
    }
    for (m *= 2; i < m; i++) {
        r = ARC_UTIL_LoadPaletteBlockFromArchive(11, 0xd4, (u32)(&res), (u16)((input->heap & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(input->palAnm), res->palette, 1, (u16)(i * 16 + 0x70), 0x20);
        GFL_HEAP_Free(r);
    }
}

void BTLV_INPUT_DrawMessageText(BtlvInput *input, const int *text)
{
    int w;
    int h;

    GF_FONT_SetTextColor(1, 2, 0);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)text[0], (int)input->font, &w, &h);
    PRINTSYS_Print((void *)input->bmpA, 0x80 - w / 2, 0x10, (void *)text[0], (void *)input->font);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)text[1], (int)input->font, &w, &h);
    PRINTSYS_Print((void *)input->bmpA, 0x80 - w / 2, 0x40, (void *)text[1], (void *)input->font);
    input->enabled[0] = 1;
    input->enabled[1] = 1;
    ARC_UTIL_UploadBgPaletteFromHandle((void *)input->arc, 0x6b, 5, 0, 0, 0, input->heap);
}

/*
 * lever: 022053DE reserves 0x28 bytes: 16 outgoing argument bytes plus
 *   a 24-byte local. Only its first 16 bytes are read/initialized here;
 *   pad10 preserves the observed allocation without naming unknown fields.
 *   Palette field reads retain the A386/A387 pools as one extern plus addend.
 */
void BTLV_INPUT_InitButtonState(BtlvInput *input)
{
    int i;
    Buffer buf;
    for (i = 0; i < 4; i++) {
        buf.value[i] = 0;
        buf.a[i] = 0;
        buf.b[i] = 0;
    }
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)BTLV_INPUT_SLOT_PARAM(input)); i++)
        buf.value[i] = BTL_POKEPARAM_GetMovePP(BTLV_INPUT_SLOT_PARAM(input), i, &buf.a[i], &buf.b[i]);
    BTLV_INPUT_DrawWazaButtons(input, (const Slots *)((const struct Slots *)(&buf)));
    input->enabled[5] = d_0220A386[BTLV_INPUT_SLOT_INDEX(input)].first;
    input->enabled[6] = d_0220A386[BTLV_INPUT_SLOT_INDEX(input)].second;
    input->struggle = 1;
    for (i = 0; i < 4; i++) {
        if (input->moveFlags[BTLV_INPUT_SLOT_INDEX(input)][i] == 1)
            input->struggle = 0;
    }
    if (BTL_POKEPARAM_IsFainted(BTLV_INPUT_SLOT_PARAM(input))) {
        for (i = 0; i < 4; i++)
            input->enabled[i] = 0;
        input->struggle = 0;
        PALANM_RequestFadeOverwrite(input->palAnm, 2, 0x3e00, 0, 8, 8, 0, input->taskMgr);
        PALANM_RequestFadeOverwrite(input->palAnm, 8, 0x700, 0, 8, 8, 0, input->taskMgr);
        return;
    }
    if (input->struggle == 1) {
        input->enabled[0] = 1;
        BTLV_INPUT_CreateBackActor(input);
        PALANM_RequestFadeOverwrite(input->palAnm, 2, 0x3e00, 0, 8, 8, 0, input->taskMgr);
        PALANM_RequestFadeOverwrite(input->palAnm, 8, 0x700, 0, 8, 8, 0, input->taskMgr);
        return;
    }
    PALANM_RequestFadeOverwrite(input->palAnm, 2, 0x3e00, 0, 0, 0, 0, input->taskMgr);
    PALANM_RequestFadeOverwrite(input->palAnm, 8, 0x700, 0, 0, 0, 0, input->taskMgr);
}

/*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 */
void BTLV_INPUT_DrawSelectScreenText(BtlvInput *input, const int *params)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = (int)WORDSET_CreateDefault(input->heap);
    v = STRBUF_Create(8, input->heap);
    w = MSGDATA_AllocString(input->msgData, 6);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(9, 10, 0);
    WORDSET_SetSlotNumber(h, 0, params[2], 3, 2, 1);
    WORDSET_CopyTaggedText((void *)h, v, w);
    PRINTSYS_Print((void *)(input->bmpA), 0x8c, 8, v, (void *)(input->font));
    if (params[0] != params[1])
        GF_FONT_SetTextColor(7, 8, 0);
    WORDSET_SetSlotNumber(h, 0, params[1], 3, 2, 1);
    WORDSET_CopyTaggedText((void *)h, v, w);
    PRINTSYS_Print((void *)(input->bmpA), 0x60, 8, v, (void *)(input->font));
    GF_FONT_SetTextColor(1, 2, 0);
    extra = MSGDATA_AllocString(input->msgData, 7);
    PRINTSYS_Print((void *)(input->bmpA), 0x7c, 8, extra, (void *)(input->font));
    STRBUF_Delete(extra);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    WORDSET_Delete((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
    PALANM_CopyToSlot((struct PalAnmSlot *)(input->palAnm), (u16 *)(PALANM_GetDefaultWork((char *)BTLV_EFFECT_GetPalanm(), 1) + 0x40), 1, 0x70, 0x20);
}

void BTLV_INPUT_ClearButtonState(BtlvInput *input)
{
    int i;
    int j;

    input->flags2.choiceMade = 0;
    for (i = 0; i < 8; i++) {
        input->enabled[i] = 0;
    }
    for (j = 0; j < 4; j++) {
        input->enabled2[j] = 0;
    }
    BMP_Clear((struct CharBuf *)input->bmpA, 0);
    BMP_WIN_TransferChars((struct Descriptor *)input->bmpWinA);
    BMP_Clear((struct CharBuf *)input->bmpB, 0);
    BMP_WIN_TransferChars((struct Descriptor *)input->bmpWinB);
    BTLV_INPUT_DeleteWazaActors(input);
    BTLV_INPUT_DeleteBackActor(input);
    BTLV_INPUT_DeleteStatusIcons(input);
    BG_SYS_SetTileEntry(4, 0, 0x20, 2, 0x20, 0x20, 0);
    PALANM_RequestFadeOverwrite((void *)input->palAnm, 2, 0x3e00, 0, 0, 0, 0, input->taskMgr);
    PALANM_RequestFadeOverwrite((void *)input->palAnm, 8, 0x700, 0, 0, 0, 0, input->taskMgr);
}

int BTLV_INPUT_GetPpTextColor(int index, int count)
{
    if (index == 0) {
        return 0x1d00;
    }
    if (count == index) {
        return 0x440;
    }
    if (count <= 2) {
        if (index == 1) {
            return 0x14c0;
        }
    } else if (count <= 7) {
        switch (index) {
        case 1:
            return 0x14c0;
        case 2:
            return 0xc80;
        }
    } else {
        if (index <= count / 4) {
            return 0x14c0;
        }
        if (index <= count / 2) {
            return 0xc80;
        }
    }
    return 0x440;
}

void BTLV_INPUT_CreateActionButtons(BtlvInput *input, BtlvInputPartyInfo *info)
{
    int n;
    void *arc;
    int i;
    int k;
    void **r;
    const BtlvInputPoint *pt;
    s16 x, y;

    n = (input->battleType == 3) ? 2 : input->battleType + 1;
    k = 0;
    if (input->battleType == 0 || input->battleType == 3)
        return;
    arc = ARC_TOOL_CreateHandle(7, (u16)((input->heap & 0x7fff) | 0x8000));
    input->pokeCell = CLACT_RegisterCellAnim(arc, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), input->heap);
    input->pokePal = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0x160, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, (u16)(CLACT_GetPaletteVramAddress(input->pokePal, 1) >> 1), 0x60);
    *(volatile u16 *)0x04001040 = 0x100;
    *(volatile u16 *)0x04001044 = 0;
    *(volatile u16 *)0x04001042 = 0x100;
    *(volatile u16 *)0x04001046 = 0;
    if (n > 1) {
        r = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x1145);
        r[0] = input;
        r[1] = (void *)n;
        BTLV_INPUT_RegisterTask(input, (int)GFL_USE_AddMainTask(BTLV_INPUT_WindowOpenTaskMain, r, 0), 0);
    }
    for (i = 0; i < n; i++) {
        if (info->species[i] != 0) {
            input->pokeChr[i] = CLACT_RegisterCharacter(arc, POKE_TOOL_CalcGraphicIndex(info->species[i], info->form[i], info->gender[i], 0), 0, 1, input->heap);
            input->pokeIcons[i].actor = CLACT_CreateActor((void *)input->unitPoke, input->pokeChr[i], input->pokePal, input->pokeCell, d_0220A392, 1, input->heap);
            CLACT_AddActorSurfacePos((struct Obj *)(input->pokeIcons[i].actor), (const struct Vec2 *)(&d_0220A50C[input->battleType][i]), 1);
            CLACT_SetActorAutoAnim(input->pokeIcons[i].actor, 1);
            if (info->sel == i) {
                CLACT_SetActorAnimSeq(input->pokeIcons[i].actor, 1);
            } else if (k == 0) {
                pt = &d_0220A50C[input->battleType][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001040 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001044 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
                k++;
            } else {
                pt = &d_0220A50C[input->battleType][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001042 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001046 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
            }
            CLACT_SetActorPaletteOffset(input->pokeIcons[i].actor, POKE_TOOL_CalcIconPalette(info->species[i], info->form[i], info->gender[i], 0), 0);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * lever: entry reads use the indexed aggregate; the zero store uses its raw
 * offset. This avoids retaining a common entry pointer across both frees.
 */
void BTLV_INPUT_DeleteActionButtonActors(BtlvInput *input)
{
    int i;
    int empty = 1;
    int *ctx;
    for (i = 0; i < 3; i++) {
        if (input->pokeIcons[i].actor != 0) {
            CLACT_DeleteActor(input->pokeIcons[i].actor);
            CLACT_ReleaseCharacter(input->pokeChr[i]);
            input->pokeIcons[i].actor = 0;
            input->pokeChr[i] = -1;
            empty = 0;
        }
    }
    if (input->pokeCell != -1) {
        CLACT_ReleaseCellAnim(input->pokeCell);
        input->pokeCell = -1;
    }
    if (input->pokePal != -1) {
        CLACT_ReleasePalette(input->pokePal);
        input->pokePal = -1;
    }
    if (!empty) {
        ctx = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x11b2);
        ctx[0] = (int)input;
        BTLV_INPUT_RegisterTask(input, (int)GFL_USE_AddMainTask(BTLV_INPUT_WindowCloseTaskMain, ctx, 0), 0);
    }
}

void BTLV_INPUT_SetActionUnitVisible(BtlvInput *input, int visible)
{
    CLACT_SetUnitDrawEnable(input->unitPoke, visible);
}

void BTLV_INPUT_CreateStatusIcons(BtlvInput *input, int statusKind)
{
    Five a = d_0220A558;
    Five b = d_0220A56C;
    Five c = d_0220A544;
    BtlvInputPoint v;
    int index;
    void **q;
    if (statusKind == 0) return;
    input->statusActors[0] = CLACT_CreateActor((void *)input->unitStatus, input->resCommonChr, input->resCommonPal, input->resCommonCell, d_0220A392, 1, input->heap);
    index = statusKind - 1;
    v.x = 0x130 + b.v[index];
    v.y = 0x20 + c.v[index];
    CLACT_AddActorSurfacePos((struct Obj *)(input->statusActors[0]), (const struct Vec2 *)(&v.x), (int)1);
    CLACT_SetActorAutoAnim(input->statusActors[0], 1);
    statusKind += 14;
    CLACT_SetActorAnimSeq(input->statusActors[0], statusKind);
    input->statusActors[1] = CLACT_CreateActor((void *)input->unitStatus, input->resCommonChr, input->resCommonPal, input->resCommonCell, d_0220A392, 1, input->heap);
    v.x = 0x130;
    v.y = 0x20;
    CLACT_AddActorSurfacePos((struct Obj *)(input->statusActors[1]), (const struct Vec2 *)(&v.x), (int)1);
    CLACT_SetActorAutoAnim(input->statusActors[1], 1);
    CLACT_SetActorAnimSeq(input->statusActors[1], 14);
    CLACT_SetActorPaletteOffset(input->statusActors[1], (u8)a.v[index], 0);
    q = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x11ec);
    q[0] = (void *)input;
    BTLV_INPUT_RegisterTask(input, (int)TCB_AddTask((void *)input->taskMgr, BTLV_INPUT_CursorMoveTaskMain, q, 0), (int)((void *)BTLV_INPUT_CursorMoveTaskEnd));
    input->flags.animTasks++;
}

void BTLV_INPUT_DeleteStatusIcons(BtlvInput *input)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (input->statusActors[i] != 0) {
            CLACT_DeleteActor(input->statusActors[i]);
            input->statusActors[i] = 0;
        }
    }
}

void BTLV_INPUT_CreateWazaCursorActors(BtlvInput *input, int mode)
{
    BtlvInputActor *slots;
    BtlvInputPoint pos;
    int add;
    int step;
    char *row;
    int i;

    if (mode == 1) {
        slots = input->cursorB;
        pos.x = 0x94;
        pos.y = 0x30;
        step = -8;
        add = 4;
    } else {
        slots = input->cursorA;
        pos.x = 0x58;
        pos.y = 0x88;
        step = 0x10;
        add = 0;
    }
    i = 0;
    row = (char *)input + mode * 0x48;
    for (; i < 6; i++) {
        slots[i].actor = CLACT_CreateActor((void *)input->unitButtons, input->resCommonChr, input->resCommonPal, input->resCommonCell, d_0220A392, 1, input->heap);
        CLACT_AddActorSurfacePos((struct Obj *)slots[i].actor, (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorAutoAnim(slots[i].actor, 1);
        CLACT_SetActorAnimSeq(slots[i].actor, add + *(u8 *)(row + i * 12 + 0x75));
        pos.x += (s16)step;
    }
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x11c;` before `off = 0x14c;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void BTLV_INPUT_DeleteWazaCursorActors(BtlvInput *input)
{
    int i;
    int j;
    int off;
    char *slots;

    i = 0;
    off = 0x14c;
    for (; i < 2; i++) {
        if (i != 0) {
            slots = (char *)input + off;
        } else {
            slots = (char *)input + 0x47 * 4;
        }
        for (j = 0; j < 6; j++) {
            if (*(void **)(slots + j * 8) != 0) {
                CLACT_DeleteActor(*(void **)(slots + j * 8));
                *(void **)(slots + j * 8) = 0;
            }
        }
    }
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`o0 = 0x240;` before `o0 = 0x17c;`; `o1 = 0x110;` before `o1 = 0x108;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void BTLV_INPUT_CreateTargetActors(BtlvInput *input)
{
    BtlvInputTargetAnim q = d_0220A580;
    int o0;
    int o1;
    int o2;
    int o3;
    int o4;
    int o5;
    char *target;
    int j;

    o0 = 0x17c;
    o1 = 0x108;
    o2 = 0x114;
    o3 = 0x180;
    o4 = 0x180;
    o5 = 0x180;
    for (j = 0; j < 6; j++) {
        target = (char *)input + j * 8;
        *(u32 *)(target + o3) = (u32)CLACT_CreateActor((void *)*(u32 *)((char *)input + o0), input->resButtonChr, *(u32 *)((char *)input + o1),
                                         *(u32 *)((char *)input + o2), d_0220A392, 1, input->heap);
        CLACT_SetActorAutoAnim((struct Obj *)*(int *)(target + o4), 1);
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(target + o5)), q.seq[j]);
        CLACT_SetActorDrawEnable((struct Obj *)((BtlvInput *)target)->targets[0].actor, 0);
    }
}

void BTLV_INPUT_DeleteTargetActors(BtlvInput *input)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (input->targets[i].actor != 0) {
            CLACT_DeleteActor(input->targets[i].actor);
            input->targets[i].actor = 0;
        }
    }
}

void BTLV_INPUT_DeleteWazaActors(BtlvInput *input)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (input->wazaActors[i] != 0) {
            CLACT_DeleteActor(input->wazaActors[i]);
            input->wazaActors[i] = 0;
        }
    }
}

void BTLV_INPUT_CreateBackActor(BtlvInput *input)
{
    void *str;
    void *msg;
    int font;
    void *bmp;
    BtlvInputPoint pos;
    int w;
    int h;
    u8 c[3];
    Struct36 buf;
    char *pixels;
    int i;
    enum { VRAM_BASE = 0x06600000 } vram;

    input->backActor = CLACT_CreateActor((void *)input->unitBack, input->resCommonChr, input->resCommonPal, input->resCommonCell, d_0220A392, 1, input->heap);
    pos.x = 0x80;
    pos.y = 0x50;
    CLACT_AddActorSurfacePos((struct Obj *)(input->backActor), (const struct Vec2 *)(&pos), 1);
    CLACT_SetActorAutoAnim(input->backActor, 1);
    CLACT_SetActorAnimSeq(input->backActor, 0x14);
    str = STRBUF_Create(0x10, input->heap);
    msg = MSGDATA_AllocString(input->msgData, 0);
    font = (int)WORDSET_CreateDefault(input->heap);
    bmp = BMP_Create(0xe, 4, 0x20, input->heap);
    BMP_Clear(bmp, 0);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(0xe, 0xa, 0);
    WORDSET_SetSlotFromMsgCB((struct WordSet *)font, 0, 0xa5);
    WORDSET_CopyTaggedText((struct WordSet *)font, str, msg);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)str, (int)(input->font), &w, &h);
    PRINTSYS_Print(bmp, 0x38 - w / 2, 8, str, input->font);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(input->backActor, (struct Struct36 *)(&buf));
    vram = VRAM_BASE;
    for (i = 0; i < 4; i++) {
        MIi_CpuCopy16(pixels + i * 0x1c0, (void *)(vram + (i * 8 + 0xcd) * 32 + buf.w[2]), 0x100);
        MIi_CpuCopy16(pixels + (i * 0x1c0 + 0x100), (void *)(vram + (i * 4 + 0xed) * 32 + buf.w[2]), 0x80);
        MIi_CpuCopy16(pixels + (i * 0x1c0 + 0x180), (void *)(vram + (i * 2 + 0xfd) * 32 + buf.w[2]), 0x40);
    }
    STRBUF_Delete(str);
    STRBUF_Delete(msg);
    WORDSET_Delete((struct WordSet *)font);
    BMP_Delete(bmp);
}

void BTLV_INPUT_DeleteBackActor(BtlvInput *input)
{
    if (input->backActor != 0) {
        CLACT_DeleteActor(input->backActor);
        input->backActor = 0;
    }
}

/*
 * `const BtlvInputSection *section` lets the scheduler hoist the reload of
 * section above the bitfield store in the ret != -1 arm.
 */
int BTLV_INPUT_ProcessButtonSelection(BtlvInput *input, const BtlvInputSection *section, s8 (*rows)[12], u8 *list, int ret, int transformed)
{
    int keys;
    int cont;
    int done;
    s8 *row;
    int i;
    int k;
    int v;

    keys = KEY_GetTrg();
    cont = KEY_GetCont();
    done = 0;
    if (input->flags2.inputEnabled == 0)
        keys &= ~2;
    if (input->flags.redraw) {
        input->flags.redraw = 0;
        BTLV_INPUT_UpdateWazaRow(input);
        BTLV_INPUT_UpdateButtonActors(input, section->buttons, rows);
        CLACT_SetUnitDrawEnable(input->unitCursors, 1);
    }
    v = -1;
    if (ret != v) {
        *input->cursorVisible = 0;
        input->flags.cursor = 0;
        input->flags.prevCursor = 0xF;
        BTLV_INPUT_UpdateButtonActors(input, section->buttons, rows);
        return ret;
    }
    if (keys == 0)
        goto end;
    if (*input->cursorVisible != 0) {
        v = -128;
        row = rows[input->flags.cursor];
        switch (keys) {
        case 0x40:
            v = row[6];
            break;
        case 0x80:
            v = row[7];
            break;
        case 0x20:
            v = row[8];
            break;
        case 0x10:
            v = row[9];
            break;
        case 2:
            k = row[11];
            if (k < 0) {
                if (input->flags.restrictedChoice == 1)
                    v = (s8)-k;
            } else {
                v = k;
            }
            break;
        }
        if (keys == 1) {
            ret = row[10];
            if (ret < 4 && (cont & 0x200) && input->screen == 5 && (transformed == 1 || input->struggle == 1))
                goto draw;
            if (ret < 4 && (cont & 0x200) && input->screen == 2 && transformed == 1)
                goto draw;
            if (input->enabled[ret] == 1) {
                if (BTLV_INPUT_IsWazaSelectable(input, section, ret) == 0)
                    BTLV_INPUT_PlaySelectSe(input);
                else
                    BTLV_INPUT_PlayCursorSe(input);
                done = 1;
            } else if (ret < 4 && (cont & 0x200) && input->screen == 2 && input->enabled2[ret] == 1) {
                BTLV_INPUT_PlaySelectSe(input);
            }
        } else if (v != -128) {
            BTLV_INPUT_PlayCancelSe(input);
            if (v < 0) {
                if (-v != input->flags.prevCursor && input->flags.prevCursor != 0xF)
                    v = (s8)input->flags.prevCursor;
                else
                    v *= -1;
            } else if (v & 0x40) {
                i = 0;
                v &= ~0x40;
                for (; list[i] != 0xff; i++) {
                    if (input->flags.prevCursor == list[i]) {
                        v = (s8)input->flags.prevCursor;
                        break;
                    }
                }
            }
            input->flags.prevCursor = input->flags.cursor;
            input->flags.cursor = v;
            if (keys == 2) {
                if (v != 0xF)
                    BTLV_INPUT_PlayCursorSe(input);
                ret = v;
                done = 1;
            }
        }
    } else if (keys & 0xcf3) {
        *input->cursorVisible = 1;
        BTLV_INPUT_UpdateWazaRow(input);
        BTLV_INPUT_PlayCancelSe(input);
    }
draw:
    BTLV_INPUT_UpdateButtonActors(input, section->buttons, rows);
end:
    if (done == 1) {
        switch (input->screen) {
        case 2:
            if (BTLV_INPUT_IsWazaSelectable(input, section, input->flags.cursor) == 0)
                input->lastMove[input->partyIdx] = input->moveIds[input->flags.cursor];
        case 1:
        case 5:
            if (BTLV_INPUT_IsWazaSelectable(input, section, input->flags.cursor) == 0)
                input->lastChoice[input->partyIdx][input->screen] = input->flags.cursor;
            input->flags2.choiceMade = 1;
            break;
        case 3:
            if (BTLV_INPUT_IsWazaSelectable(input, section, ret) == 0)
                input->lastChoice[input->partyIdx][input->screen] = input->flags.cursor | (input->lastChoice[input->partyIdx][2] << 4);
            input->flags2.choiceMade = 1;
            break;
        }
        input->flags.cursor = 0;
        input->flags.prevCursor = 0xF;
        input->flags.redraw = 1;
        CLACT_SetUnitDrawEnable(input->unitCursors, 0);
    }
    return ret;
}

int BTLV_INPUT_ProcessKeyRepeat(BtlvInput *input)
{
    u32 k = KEY_GetRepeat();

    if (k & 2) {
        BTLV_INPUT_PlayCursorSe(input);
        return 2;
    }
    if (k & 0x20) {
        BTLV_INPUT_PlaySelectSe(input);
        return 0;
    }
    if (k & 0x10) {
        BTLV_INPUT_PlaySelectSe(input);
        return 1;
    }
    return -1;
}

/*
 * The table parameter is `__restrict`: with it the scheduler hoists the y
 * load above the x store in cases 2..5 (e[1] vs pos.x) but not in cases 0/1
 * (e[0] vs pos.x, same offset), which is the original's mixed schedule.
 */
void BTLV_INPUT_UpdateButtonActors(BtlvInput *input, u8 (* __restrict tab)[4], s8 (*rows)[12])
{
    BtlvInputPoint pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[input->flags.cursor][i];
        if (k >= 0) {
            e = tab[k];
            switch (i) {
            case 0:
                pos.x = e[2];
                pos.y = e[0];
                break;
            case 1:
                pos.x = e[3];
                pos.y = e[0];
                break;
            case 2:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 3:
                pos.x = e[3];
                pos.y = e[1];
                break;
            case 4:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 5:
                pos.x = e[3];
                pos.y = e[1];
                break;
            }
            CLACT_SetActorDrawEnable(input->targets[i].actor, *input->cursorVisible);
            CLACT_AddActorSurfacePos((struct Obj *)(input->targets[i].actor), (const struct Vec2 *)(&pos), 1);
        } else {
            CLACT_SetActorDrawEnable(input->targets[i].actor, 0);
        }
    }
}

int BTLV_INPUT_SetSelection(BtlvInput *input, int choice, int colour)
{
    BtlvInputButtonFlashTask *c;
    int flag;

    if (colour < 0)
        return choice;
    if ((KEY_GetCont() & 0x200) && choice < 4 && (input->screen == 2 || input->screen == 5))
        input->pending = choice | 0x8000;
    else
        input->pending = choice;
    c = GFL_HEAP_Alloc((u16)((input->heap & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0x1440);
    flag = 0;
    if ((0x10000 & colour) == 0)
        flag = 1;
    input->flags.inputLock = flag;
    c->input = input;
    c->state = 0;
    c->colour = (u16)colour;
    if (input->struggle == 1 && c->colour == 0)
        c->flag = 1;
    else
        c->flag = 0;
    BTLV_INPUT_RegisterTask(input, (int)TCB_AddTask(input->taskMgr, BTLV_INPUT_ButtonFlashTaskMain, c, 0), (int)((void *)BTLV_INPUT_ButtonFlashTaskEnd));
    return -1;
}

void BTLV_INPUT_ButtonFlashTaskMain(void *task, void *arg)
{
    BtlvInputButtonFlashTask *c = arg;

    switch (c->state) {
    case 0:
        if (c->flag == 1)
            PALANM_RequestFade(c->input->palAnm, 8, 2, 0, 0, 8, 0x7fff, c->input->taskMgr);
        else
            PALANM_RequestFade(c->input->palAnm, 2, c->colour, 0, 0, 8, 0x7fff, c->input->taskMgr);
        c->state++;
        break;
    case 1:
        if (PALANM_GetFadeRequestBits((const char *)c->input->palAnm) == 0) {
            if (c->flag == 1)
                PALANM_RequestFade(c->input->palAnm, 8, 2, 0, 8, 0, 0x7fff, c->input->taskMgr);
            else
                PALANM_RequestFade(c->input->palAnm, 2, c->colour, 0, 8, 0, 0x7fff, c->input->taskMgr);
            c->state++;
        }
        break;
    case 2:
        if (PALANM_GetFadeRequestBits((const char *)c->input->palAnm) == 0)
            BTLV_INPUT_DeleteTask(c->input, task);
        break;
    }
}

void BTLV_INPUT_ButtonFlashTaskEnd(void *task)
{
    (*(BtlvInput **)TCBL_IsDeletePending((struct S02030EE8 *)task))->flags.inputLock = 0;
}

void BTLV_INPUT_DrawRunButtonText(BtlvInput *input, char *runInfo)
{
    int h;
    void *v;
    void *w;
    int textWidth;
    int textHeight;
    u8 c[3];

    if (BTLV_EFFECT_IsRecordEnabledInComm() == 0)
        return;
    h = (int)WORDSET_CreateDefault(input->heap);
    v = STRBUF_Create(6, input->heap);
    w = MSGDATA_AllocString(input->msgData, 8);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(1, 2, 0);
    WORDSET_SetSlotNumber((u32)((struct WordSet *)h), 0, ((Arg1 *)runInfo)->runTextId, 2, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)h, v, w);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)v, (int)input->font, &textWidth, &textHeight);
    PRINTSYS_Print((void *)(input->bmpB), 12 - textWidth / 2, 0, v, (void *)(input->font));
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    WORDSET_Delete((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
}

void BTLV_INPUT_PrepareCommandSelect(BtlvInput *input)
{
    BTLV_EFFECT_ResetIntroState(2);
    BTLV_EFFECT_StartCameraMove((u32)(input->battlePos), 1, 10, 0, 8);
}

void BTLV_INPUT_ClearSlotEvents(BtlvInput *input)
{
    int a = BTLV_GAUGE_TakeSlotEvent((char *)BTLV_EFFECT_GetGauge(), input->battlePos);
    int b = BTLV_MCSS_TakeSpriteRefreshedFlag((BtlvMcssWork *)((void *)BTLV_EFFECT_GetMcss()), input->battlePos);
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            input->lastChoice[input->partyIdx][i] = 0;
    }
}

void BTLV_INPUT_RegisterTask(BtlvInput *input, int taskFunc, int taskEnd)
{
    int i = BTLV_INPUT_AllocTaskSlot(input);

    input->tasks[i] = (void *)taskFunc;
    input->taskEnd[i] = (void (*)(void *))taskEnd;
}

/*
 * lane S13 leaf of BTLV_INPUT_DeleteTask
 */
int BTLV_INPUT_FindTask(BtlvInput *input, int task)
{
    int i;
    int x;

    for (i = 0; i < 8; i++) {
        x = (int)input->tasks[i];
        if (x == task)
            break;
    }
    return i;
}

void BTLV_INPUT_DeleteTask(BtlvInput *input, void *task)
{
    int i = BTLV_INPUT_FindTask(input, (int)task);
    int off;

    if (task != 0) {
        void *r = (void *)TCBL_IsDeletePending((struct S02030EE8 *)task);
        char *t = (char *)input->taskEnd;
        void (*cb)(void *);

        off = i * 4;
        cb = *(void (**)(void *))(t + off);
        if (cb != 0)
            cb(task);
        if (r != 0)
            GFL_HEAP_Free(r);
        TCB_DeleteTask(task);
        *(int *)((char *)input->tasks + off) = 0;
        *(int *)(t + off) = 0;
    }
}

int BTLV_INPUT_AllocTaskSlot(BtlvInput *input)
{
    int i;

    for (i = 0; i < 8; i++) {
        if ((int)input->tasks[i] == 0)
            break;
    }
    if (i == 8) {
        BTLV_INPUT_DeleteTask(input, input->tasks[0]);
        i = 0;
    }
    return i;
}

void BTLV_INPUT_DeleteAllTasks(BtlvInput *input)
{
    int i;

    for (i = 0; i < 8; i++) {
        void *v = input->tasks[i];

        if (v != 0)
            BTLV_INPUT_DeleteTask(input, v);
    }
}

int BTLV_INPUT_IsWazaSelectable(BtlvInput *input, const BtlvInputSection *section, int i)
{
    int r;

    if (!input->flags.restrictedChoice || input->screen != 1)
        return 1 & section->selectFlags[i];
    r = (section->selectFlags[i] & 2) >> 1;
    if (r == 1)
        input->lastChoice[input->partyIdx][input->screen] = 0;
    return r;
}

void BTLV_INPUT_UpdateWazaRow(BtlvInput *input)
{
    u8 b;

    switch (input->screen) {
    case 2:
        if (input->lastMove[input->partyIdx] != input->moveIds[input->lastChoice[input->partyIdx][input->screen]])
            input->lastChoice[input->partyIdx][3] = 0;
    case 1:
    case 5:
        input->flags.cursor = input->lastChoice[input->partyIdx][input->screen];
        break;
    case 3:
        b = input->lastChoice[input->partyIdx][input->screen];
        if (((b & 0xf0) >> 4) == input->lastChoice[input->partyIdx][2])
            input->flags.cursor = b;
        else
            input->flags.cursor = 0;
        break;
    default:
        input->flags.cursor = 0;
        break;
    }
}

void BTLV_INPUT_BlendWindowPalette(BtlvInput *input)
{
    u16 buf[16];

    if ((int)BTL_MAIN_GetCompetitor((void ***)BTLV_EFFECT_GetBattleMain()) != 4 && BTLV_EFFECT_IsRecordAllowed() == 0) {
        PALANM_BlendColors(input->palBackup, buf, 0x10, 8, 0);
        PALANM_CopyToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), buf, 1, 0x20, 0x20);
    }
}

void BTLV_INPUT_RestoreWindowPalette(BtlvInput *input)
{
    if (input->infoWinEnabled == 1)
        PALANM_CopyToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), input->palBackup, 1, 0x20, 0x20);
}

int BTLV_INPUT_GetMessageBoxMode(BtlvInput *input)
{
    if (!input->flags.restrictedChoice) {
        if (input->battleType == 2) {
            if (BTLV_EFFECT_GetVisibilityMode() == 1) {
                if (input->battlePos == 4)
                    return 0x65;
                return 0x5f;
            }
            if (input->battlePos == 4)
                return 0x5d;
            return 0x5e;
        }
        if (BTLV_EFFECT_GetVisibilityMode() == 1)
            return 0x65;
        return 0x5d;
    }
    if (input->battleType == 2 && input->battlePos != 4) {
        if (BTLV_EFFECT_GetVisibilityMode() == 1)
            return 0x67;
        return 0x61;
    }
    if (BTLV_EFFECT_GetVisibilityMode() == 1)
        return 0x66;
    return 0x60;
}

void BTLV_INPUT_PlayConfirmSe(BtlvInput *input)
{
    if (input->seMode != 3 || input->screen == 6)
        GFL_USE_PlaySeDefaultVolume(0x555);
}

void BTLV_INPUT_PlayCancelSe(BtlvInput *input)
{
    if (input->seMode != 3 || input->screen == 6)
        GFL_USE_PlaySeDefaultVolume(0x548);
}

/*
 * lane S13 leaf of BTLV_INPUT_ProcessKeyRepeat
 */
void BTLV_INPUT_PlaySelectSe(BtlvInput *input)
{
    if (input->screen != 6) {
        if (input->seMode != 3) {
            GFL_USE_PlaySeDefaultVolume(0x54d);
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x54c);
    }
}

/*
 * lane S13 leaf of BTLV_INPUT_UpdateButtonActors-area callers (BTLV_INPUT_ProcessKeyRepeat)
 */
void BTLV_INPUT_PlayCursorSe(BtlvInput *input)
{
    if (input->seMode != 3 || input->screen == 6)
        GFL_USE_PlaySeDefaultVolume(0x552);
}

void BTLV_INPUT_PlayPageSe(BtlvInput *input)
{
    if (input->seMode != 3 || input->screen == 6)
        GFL_USE_PlaySeDefaultVolume(0x579);
}

void BTLV_INPUT_PlayOpenSe(BtlvInput *input)
{
    if (input->seMode != 3 || input->screen == 6)
        GFL_USE_PlaySeDefaultVolume(0x54d);
}

void BTLV_INPUT_PlayBackSe(BtlvInput *input)
{
    if (input->seMode != 3 || input->screen == 6)
        GFL_USE_PlaySeDefaultVolume(0x557);
}
