/*
 * file:     btlv_input.c
 * unit:     yes
 * function: BTLV_INPUT_CreateDefault, BTLV_INPUT_CreateWithMode, BTLV_INPUT_Create, BTLV_INPUT_Delete, BTLV_INPUT_UpdateInfoWindow, BTLV_INPUT_InfoWindowTask, BTLV_INPUT_LoadScreenResources, BTLV_INPUT_ReleaseScreenResources, BTLV_INPUT_InitBgLayers, BTLV_INPUT_ReleaseBgLayers, BTLV_INPUT_StartPaletteFadeTask, BTLV_INPUT_StartScreenFadeTask, BTLV_INPUT_IsScreenBusy, BTLV_INPUT_ChangeScreen, BTLV_INPUT_ProcessTouchInput, BTLV_INPUT_GetScreenButtonTable, BTLV_INPUT_ProcessKeyInput, BTLV_INPUT_IsInputBlocked, BTLV_INPUT_GetPendingResult, BTLV_INPUT_LoadCommonGraphics, BTLV_INPUT_ActionScreenOpenTask, BTLV_INPUT_WazaScreenOpenTask, BTLV_INPUT_WazaScreenOpenInstantTask, BTLV_INPUT_ActionScreenOpenInstantTask, BTLV_INPUT_TargetScreenOpenTask, BTLV_INPUT_WazaScreenCloseTask, BTLV_INPUT_WaitScreenOpenTask, BTLV_INPUT_WaitScreenOpenInstantTask, BTLV_INPUT_MessageScreenOpenTask, BTLV_INPUT_ListScreenOpenTask, BTLV_INPUT_SelectScreenOpenTask, BTLV_INPUT_ConfirmScreenOpenTask, BTLV_INPUT_ListScreenOpenInstantTask, BTLV_INPUT_ScreenResetTask, BTLV_INPUT_TaskEndClearBusyBit, BTLV_INPUT_StartBgScrollTask, BTLV_INPUT_BgScrollTaskMain, BTLV_INPUT_BgScrollTaskEnd, BTLV_INPUT_StartBgWipeTask, BTLV_INPUT_BgWipeTaskMain, BTLV_INPUT_BgWipeTaskEnd, BTLV_INPUT_StartPaletteCycleTask, BTLV_INPUT_PaletteCycleTaskMain, BTLV_INPUT_PaletteCycleTaskEnd, BTLV_INPUT_CreateCursorActors, BTLV_INPUT_CursorActorTaskMain, BTLV_INPUT_CursorActorTaskEnd, BTLV_INPUT_StartPaletteFlashTask, BTLV_INPUT_PaletteFlashTaskMain, BTLV_INPUT_PaletteFlashTaskEnd, BTLV_INPUT_StartBgScrollOffsetTask, BTLV_INPUT_BgScrollOffsetTaskMain, BTLV_INPUT_WaitFadeTaskMain, BTLV_INPUT_WaitFadeTaskEnd, BTLV_INPUT_CursorMoveTaskMain, BTLV_INPUT_CursorMoveTaskEnd, BTLV_INPUT_StartScreenTransition, BTLV_INPUT_VisibilityTaskMain, BTLV_INPUT_WindowOpenTaskMain, BTLV_INPUT_WindowCloseTaskMain, BTLV_INPUT_GetTextBlockSize, BTLV_INPUT_DrawWazaButtons, BTLV_INPUT_DrawTargetButtons, BTLV_INPUT_DrawMessageText, BTLV_INPUT_InitButtonState, BTLV_INPUT_DrawSelectScreenText, BTLV_INPUT_ClearButtonState, BTLV_INPUT_GetNeighbourIndex, BTLV_INPUT_CreateActionButtons, BTLV_INPUT_DeleteActionButtonActors, BTLV_INPUT_SetActionUnitVisible, BTLV_INPUT_CreateStatusIcons, BTLV_INPUT_DeleteStatusIcons, BTLV_INPUT_CreateWazaCursorActors, BTLV_INPUT_DeleteWazaCursorActors, BTLV_INPUT_CreateTargetActors, BTLV_INPUT_DeleteTargetActors, BTLV_INPUT_DeleteWazaActors, BTLV_INPUT_CreateBackActor, BTLV_INPUT_DeleteBackActor, BTLV_INPUT_ProcessButtonSelection, BTLV_INPUT_ProcessKeyRepeat, BTLV_INPUT_UpdateButtonActors, BTLV_INPUT_SetSelection, BTLV_INPUT_ButtonFlashTaskMain, BTLV_INPUT_ButtonFlashTaskEnd, BTLV_INPUT_DrawRunButtonText, BTLV_INPUT_PrepareCommandSelect, BTLV_INPUT_ClearSlotEvents, BTLV_INPUT_RegisterTask, BTLV_INPUT_FindTask, BTLV_INPUT_DeleteTask, BTLV_INPUT_AllocTaskSlot, BTLV_INPUT_DeleteAllTasks, BTLV_INPUT_IsWazaSelectable, BTLV_INPUT_UpdateWazaRow, BTLV_INPUT_BlendWindowPalette, BTLV_INPUT_RestoreWindowPalette, BTLV_INPUT_GetMessageBoxMode, BTLV_INPUT_PlayConfirmSe, BTLV_INPUT_PlayCancelSe, BTLV_INPUT_PlaySelectSe, BTLV_INPUT_PlayCursorSe, BTLV_INPUT_PlayPageSe, BTLV_INPUT_PlayOpenSe, BTLV_INPUT_PlayBackSe
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
 *   func_020307B0  0x020307B0  arm
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28  0x02030D28  arm
 *   func_02030DA8  0x02030DA8  arm
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   func_02040588  0x02040588  arm
 *   TCBL_GetTaskUserData   0x02030EE8  arm
 *   KEY_GetTrg 0x020362DC arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   func_02030734  0x02030734  arm
 *   func_02040618 0x02040618 arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_020490F4 0x020490F4 arm
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
 *   func_0203FC6C 0x0203FC6C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
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
 *   func_02045EC0  0x02045EC0  arm
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
 *   sec_0220A380   0x0220A380  data
 *   d_0220A380     0x0220A380  data
 *   d_0220AE98     0x0220AE98  data
 *   d_0220AEA4     0x0220AEA4  data
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   MIi_CpuCopy16 0x02082A60 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 *   func_0207AD58  0x0207AD58  thumb
 *   func_02040820  0x02040820  arm
 *   d_0220A46C     0x0220A46C  data  ov094  a4
 *   d_0220A53C  0x0220A53C  data  a4
 *   d_0220A85C  0x0220A85C  data  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   d_0220A3B4     0x0220A3B4  data   ov094  a4
 *   d_0220A38C     0x0220A38C  data   ov094  a1
 *   d_0220A3E4     0x0220A3E4  data   ov094  a4
 *   func_0207D658  0x0207D658  arm
 *   d_0220A5B0  0x0220A5B0  data
 *   d_0220A5D0  0x0220A5D0  data
 *   d_0220A5F0  0x0220A5F0  data
 *   d_0220A392  0x0220A392  data
 *   d_0220A3C4  0x0220A3C4  data
 *   d_0220A4AC  0x0220A4AC  data
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_0220A7FC     0x0220A7FC  data
 *   d_0220A94C     0x0220A94C  data
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   func_021D5528 0x021D5528 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   d_0220A386 0x0220A386 data a1
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02041300  0x02041300  arm
 *   d_0220A50C 0x0220A50C data a4
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   d_0220A558 0x0220A558 data ov094 a4
 *   d_0220A56C 0x0220A56C data ov094 a4
 *   d_0220A544 0x0220A544 data ov094 a4
 *   d_0220A580     0x0220A580  data   ov094  a4
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_0201EF34  0x0201EF34  thumb
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
 *   func_0201D304 0x0201D304 thumb
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
 */
#include "../../matched/include/Obj00083.h"
#include "../../matched/include/Obj01049.h"
#include "../../matched/include/Obj03718.h"
#include "../../matched/include/Obj21763.h"
#include "../../matched/include/Obj21770.h"
#include "../../matched/include/Obj21781.h"
#include "../../matched/include/Obj21782.h"
#include "../../matched/include/Obj01909.h"
#include "../../matched/include/Obj00168.h"
#include "../../matched/include/Obj02440.h"
#include "../../matched/include/Obj21785.h"
#include "../../matched/include/Obj00896.h"
#include "../../matched/include/Obj06327.h"
#include "../../matched/include/Obj21787.h"
#include "../../matched/include/Obj01384.h"
#include "../../matched/include/Obj10158.h"
#include "../../matched/include/Obj00823.h"
#include "../../matched/include/Obj21789.h"
#include "../../matched/include/Obj21791.h"
#include "../../matched/include/Obj21793.h"
#include "../../matched/include/Obj21794.h"
#include "../../matched/include/Obj21796.h"
#include "../../matched/include/Obj21798.h"
#include "../../matched/include/Obj05249.h"
#include "../../matched/include/Obj21799.h"
#include "../../matched/include/Obj21800.h"
#include "../../matched/include/Obj10159.h"
#include "../../matched/include/Obj18616.h"
#include "../../matched/include/Obj04404.h"
#include "../../matched/include/Obj21803.h"
#include "../../matched/include/Obj06328.h"
#include "../../matched/include/Obj13619.h"
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

#define F68_(s) (*(F68 *)((s) + 0x68))

#define F6C_(s) (*(F6C *)((s) + 0x6c))

#define HEAP(s) ((u16)((*(u16 *)((s) + 0x240) & 0x7fff) | 0x8000))

#define HEAPID(h) ((u16)(((h) & 0x7fff) | 0x8000))

#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)

#define reg_G2S_DB_WININ   (*(volatile u16 *)0x04001048)

#define reg_G2S_DB_WINOUT  (*(volatile u16 *)0x0400104A)

#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)

#define INDEX (((Flags_02201B20 *)m)->index)

#define OBJECT (*(u8 **)(m + INDEX * 4 + 0x2a4))

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

struct Work_02201B20;

struct R5;

struct Obj_02203E30;

struct Ctx_v3E30;

struct StrObj;

struct WordSet;

struct Struct36;

struct QG;

struct Ctx_v53DC;

struct Bmp;

struct Obj020437AC;

typedef signed short s16_02201DA0;

typedef struct Bits_02201DA0 { unsigned lo:9; unsigned k:4; unsigned rest:19; } Bits_02201DA0;

typedef struct Obj_022020A0 {
    void *h0;
    void *h4;
    char pad08[0x4c - 8];
    int a4c;
    int a50;
    int a54;
    char pad58[0x5c - 0x58];
    int a5c;
    char pad60[0x64 - 0x60];
    int a64;
    Bits_02201DA0 f68;
    char pad6c[0x70 - 0x6c];
    int a70;
    char pad74[0x104 - 0x74];
    int b104[5];
    char pad118[0x1b0 - 0x118];
    int b1b0[3];
    int b1bc;
    int b1c0;
    char pad1c4[0x1e0 - 0x1c4];
    int b1e0[4];
    int b1f0;
    int b1f4;
    char pad1f8[0x224 - 0x1f8];
    int a224;
    char pad228[0x23c - 0x228];
    int a23c;
    u16 heap;
    char pad242[0x274 - 0x242];
    int a274;
} Obj_022020A0;

typedef struct Res_02201DA0 { BtlvInput *owner; int v; } Res_02201DA0;

typedef struct Obj_022021F4 {
    void *h0;
    void *h4;
    char pad[0x5c - 8];
    void *h5c;
    void *h60;
} Obj_022021F4;

typedef struct Ent_02202238 { char pad[0x20]; int f20; } Ent_02202238;

typedef struct Bits_0220266C { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_0220266C;

typedef struct Obj_0220266C {
    void *h0;
    char pad[0x68 - 4];
    Bits_0220266C f68;
    char pad2[0x240 - 0x6c];
    u16 heap;
} Obj_0220266C;

typedef struct F68 {
    u32 b0 : 1;
    u32 b1 : 3;
    u32 b4 : 1;
    u32 b5 : 4;
    u32 b9 : 4;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 mode : 2;
    u32 b17 : 2;
    u32 b19 : 2;
    u32 b21 : 2;
    u32 b23 : 4;
    u32 b27 : 5;
} F68;

typedef struct F6C {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 x : 8;
    u32 rest : 22;
} F6C;

typedef struct T12 {
    int v[3];
} T12;

typedef struct Task_v1DA0 {
    char *s;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    void *f1c;
    int f20;
} Task_v1DA0;

typedef struct Arg1 {
    T12 a[6];
    T12 b[6];
    int f90;
    int f94;
    u8 pad98[0xbc - 0x98];
    int fbc;
    u8 padc0[5];
    u8 bc5;
} Arg1;

typedef struct Arg2 {
    u16 h[4];
    int f8;
    int fc;
    int f10;
    int f14;
} Arg2;

typedef struct Arg5 {
    void *a[3];
    int b[3][4];
} Arg5;

typedef struct S5 {
    u8 pad[0x2a4];
    int a[3];
    int b[3][4];
} S5;

typedef struct {
    char pad0[0xa];
    s8 id;              /* 0x0a */
    char padb;
} Ent_v1DA0;

typedef struct {
    void *key;          /* 0x00 */
    int f4;
    int *vals;          /* 0x08 */
} Cmd;

typedef struct {
    char pad0[0x50];
    int f50;            /* 0x50 */
    int f54;
    int mode;           /* 0x58 */
    char pad5c[0x64 - 0x5c];
    int f64;            /* 0x64 */
    u32 busy : 1;       /* 0x68 */
    u32 f68_1 : 30;
    u32 lock : 1;
    u32 f6c_0 : 1;      /* 0x6c */
    u32 flag : 1;
    u32 sel : 8;
    u32 f6c_10 : 22;
    int pending;        /* 0x70 */
    char pad74[0x242 - 0x74];
    u8 slot[3][8];      /* 0x242 */
    u8 en[8];           /* 0x25a */
    u8 en2[8];          /* 0x262 */
    char pad26a[0x27c - 0x26a];
    int cur;            /* 0x27c */
    int f280;           /* 0x280 */
} Obj_v1DA0;

typedef struct Main_02203040 {
    unsigned char pad00[0x60];
    int f60;
    int f64;
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int pad4 : 11;
    unsigned int mode : 2;
    unsigned int pad17 : 6;
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int top : 1;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_02203040;

typedef struct Tbl_v1DA0 {
    Pair_02201B20 p[3];
} Tbl_v1DA0;

typedef struct Main_022030F0 {
    void *owner;
    unsigned char pad04[0x58 - 4];
    int f58;
    unsigned char pad5c[0x64 - 0x5c];
    int f64;
    u32 b0 : 1;
    u32 lo : 4;
    u32 f5 : 4;
    u32 mid : 10;
    u32 mode : 2;
    u32 hi : 10;
    u32 b31 : 1;
    u32 f6c;
    int f70;
    unsigned char pad74[0x220 - 0x74];
    int f220;
    unsigned char pad224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 b25a[8];
    u8 b262[4];
    unsigned char pad266[0x27c - 0x266];
    int f27c;
    unsigned char pad280[0x2a4 - 0x280];
    void *f2a4[3];
} Main_022030F0;

typedef struct Desc_02201B20 {
    void *a;
    void *b;
    const int *c;
} Desc_02201B20;

/* The rodata objects at 0x0220A380..0x0220A3B4 are one section to the compiler: loads go
 * through the section base (sec_0220A380 + field) and addresses taken get their own words;
 * the 3-byte object at the section start is a second name at the same address. */
typedef struct Sec {
    u8 b0[3];
    u8 key[3];
    u8 pal[3][2];
    u8 mode[3][2];
    u16 h[5];
    Desc_02201B20 da;
    Desc_02201B20 db;
} Sec;

typedef struct Main_022033F4 {
    unsigned char pad00[0x48];
    void *f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;
    unsigned char pad68[0x104 - 0x68];
    int h104;
    int h108;
    int h10c;
    int h110;
    int h114;
    int h118;
    unsigned char pad11c[0x1e0 - 0x11c];
    int h1e0[4];
    int h1f0;
    int h1f4;
    unsigned char pad1f8[0x23c - 0x1f8];
    int f23c;
    u16 heap;
    unsigned char pad242[0x284 - 0x242];
    unsigned char buf284[0x20];
} Main_022033F4;

typedef struct Main_022035C0 {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_022035C0;

typedef struct Ctx_022033F4 {
    Main_022035C0 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_022033F4;

typedef struct Main_v33F4 {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[4];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_v33F4;

typedef struct Ctx_022036C4 {
    Main_v33F4 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_022036C4;

typedef struct Main_02203880 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4c[0x68 - 0x4c];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[0x240 - 0x22c];
    u16 h240;
} Main_02203880;

typedef struct Ctx_02203880 {
    Main_02203880 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_02203880;

typedef struct Main_02203978 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4c[0x68 - 0x4c];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_02203978;

typedef struct Ctx_02203978 {
    Main_02203978 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_02203978;

typedef struct Main_02203A78 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x50 - 0x4C];
    int f50;
    unsigned char pad54[0x228 - 0x54];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main_02203A78;

typedef struct Ctx_02203A78 {
    Main_02203A78 *main;
    unsigned char pad04[0xC - 0x4];
    int f0c;
} Ctx_02203A78;

typedef struct Main_02203B08 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x1f8 - 0x4C];
    void *obj1f8;
    unsigned char pad1FC[0x228 - 0x1FC];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main_02203B08;

typedef struct Ctx_02203B08 {
    Main_02203B08 *main;
    int state;
    int f8;
    int fc;
} Ctx_02203B08;

typedef struct Main_02203BC0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main_02203BC0;

typedef struct Ctx_02203BC0 {
    Main_02203BC0 *main;
    int state;
} Ctx_02203BC0;

typedef struct Main_02203C2C {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_02203C2C;

typedef struct Ctx_02203C2C {
    Main_02203C2C *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
    int f1c;
    int mode;
} Ctx_02203C2C;

typedef signed short s16_02203E30;

typedef struct Main_02203E30 {
    void *owner;
    char pad04[0x44];
    u32 f48;
    char pad4c[0x18];
    void *pal64;
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
    char pad22c[0x14];
    u16 h240;
} Main_02203E30;

typedef struct { Main_02203E30 *main; int state, f8, fc, f10, f14, timer; } Ctx_02203E30;

typedef struct { int a, b; } Pair_022033F4;

typedef struct Main_02203FDC {
    void *owner;
    char pad04[0x44];
    u32 f48;
    char pad4c[0x18];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1b8];
    void *obj224, *obj228, *obj22c;
    char pad230[0x10];
    u16 h240;
} Main_02203FDC;

typedef struct { Main_02203FDC *main; int state, f8, fc, f10, f14, timer; void *obj1c; } Ctx_02203FDC;

typedef struct Main_022041E0 {
    char pad00[0x48];
    u32 f48;
    char pad4c[0x1c];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
    char pad22c[0x14];
    u16 h240;
} Main_022041E0;

typedef struct { Main_022041E0 *main; int state, f8, fc, f10, f14, timer; } Ctx_022041E0;

typedef struct Main_022042E4 {
    char pad00[0x68];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
} Main_022042E4;

typedef struct { Main_022042E4 *main; int state; } Ctx_022042E4;

typedef struct Main_022043C0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022043C0;

typedef struct Obj_02203E30 {
    Main_022043C0 *main;
    int f4;
    int f8;
    int fc;
    int f10;
} Obj_02203E30;

typedef struct Ctx_02204438 {
    char *main;
    int cur;
    int target;
    int step;
    int ang;
} Ctx_02204438;

typedef struct Bits_022044A0 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_022044A0;

typedef struct Main_022044C0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022044C0;

typedef struct Obj_022044C0 {
    Main_022044C0 *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Obj_022044C0;

typedef struct Ctx_0220453C {
    char *main;
    int state;
    int a8;
    int ac;
    int d10;
    int cnt;
} Ctx_0220453C;

typedef struct Bits_02204588 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204588;

typedef struct Main_022045A8 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022045A8;

typedef struct Obj_022045A8 {
    Main_022045A8 *main;
    int idx;
    int set;
    int cnt;
} Obj_022045A8;

typedef struct Ent_v3E30 {
    int v0;
    int v1;
} Ent_v3E30;

typedef struct Ctx_0220461C {
    char *main;
    int idx;
    int set;
    int cnt;
} Ctx_0220461C;

typedef struct Bits_02204678 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204678;

typedef struct Bits_02204698 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204698;

typedef struct Obj_02204698 {
    void *h0;
    char pad04[0x68 - 4];
    Bits_02204698 f68;
    char pad6c[0x104 - 0x6c];
    int h104;
    int h108;
    int h10c;
    char pad110[0x240 - 0x110];
    u16 heap;
} Obj_02204698;

typedef struct Quad { u16 v[4]; } Quad;

typedef struct Pos_02203E30 { short x; short y; } Pos_02203E30;

typedef struct Row_02201B20 { Pos_02203E30 pos[6]; int val[2]; } Row_02201B20;

typedef struct Res_02203E30 { Obj_02204698 *owner; void *h; void *e[6]; } Res_02203E30;

typedef struct Main_022047F8 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main_022047F8;

typedef struct Ctx_022047F8 {
    Main_022047F8 *main;
    int h4;
    void *ent[6];
} Ctx_022047F8;

typedef struct Main_02204838 {
    void *f0;
    unsigned char pad04[0x68 - 4];
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_02204838;

typedef struct Obj_02204838 {
    Main_02204838 *main;
    int f4;
} Obj_02204838;

typedef short s16_022044A0;

typedef struct Main_022048A4 {
    unsigned char pad00[0x68];
    u32 f68;
} Main_022048A4;

typedef struct Ctx_022048A4 {
    Main_022048A4 *main;
    int f4;
} Ctx_022048A4;

typedef struct Bits_02204940 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204940;

typedef struct Main_02204960 {
    unsigned char pad00[0x240];
    u16 h240;
} Main_02204960;

typedef struct Obj_02204960 {
    Main_02204960 *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Obj_02204960;

typedef struct Ctx_022049C8 {
    void *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Ctx_022049C8;

typedef struct Bits_02204A3C { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_02204A3C;

typedef struct Bits_02204A70 { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_02204A70;

typedef struct Main_02204A88 {
    unsigned char pad00[0x210];
    void *o210;
    void *o214;
} Main_02204A88;

typedef struct Ctx_v3E30 {
    Main_02204A88 *main;
} Ctx_v3E30;

typedef struct Bits_02204AEC { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204AEC;

typedef struct Main_02204B0C {
    void *owner;
    unsigned char pad04[0x68 - 4];
    u32 b0 : 1;
    u32 lo : 18;
    u32 mode : 2;
    u32 hi : 11;
    unsigned char pad6c[0x240 - 0x6c];
    u16 h240;
} Main_02204B0C;

typedef struct Obj_02204A70 {
    Main_02204B0C *main;
} Obj_02204A70;

typedef int BOOL;

typedef short s16_02204CC0;

typedef struct Point_02201B20 { s16_02204CC0 x, y; } Point_02201B20;

typedef struct Pos_02204C98 { int x, y; } Pos_02204C98;

typedef struct PosTab { Pos_02204C98 v[4]; } PosTab;

typedef struct { int w[9]; } Struct36;

typedef struct Slots {
    u16 id[4];
    u8 a[4];
    u8 b[4];
} Slots;

typedef struct Work_v3E30 {
    char pad0[0x50];
    int mode;           /* 0x50 */
    char pad54[0x5c - 0x54];
    void *msgdata;      /* 0x5c */
    char pad60[0x64 - 0x60];
    void *bg;           /* 0x64 */
    char pad68[0x1e0 - 0x68];
    u32 res[4];         /* 0x1e0 */
    u32 r1f0;           /* 0x1f0 */
    u32 r1f4;           /* 0x1f4 */
    void *sys;          /* 0x1f8 */
    void *obj[4];       /* 0x1fc */
    char pad20c[0x224 - 0x20c];
    void *fnt;          /* 0x224 */
    char pad228[0x22c - 0x228];
    void *win;          /* 0x22c */
    char pad230[0x240 - 0x230];
    u16 heap;           /* 0x240 */
    char pad242[0x25a - 0x242];
    u8 f25a[8];         /* 0x25a */
    u8 f262[4];         /* 0x262 */
} Work_v3E30;

typedef struct Entry_v3E30 {
    u8 kind : 2;
    u8 flag : 1;
    u8 pad0 : 5;
    u8 pad1[3];
    short show;
    short pad6;
    void *text;
} Entry_v3E30;

typedef struct Info_v3E30 {
    Entry_v3E30 e[6];
    u8 b48;
    u8 b49;
} Info_v3E30;

typedef struct Bits6C {
    u32 lo : 2;
    u32 x : 8;
    u32 hi : 22;
} Bits6C;

typedef struct Out {
    u32 pad[3];
    int fc;
} Out;

typedef struct Res_02204C98 {
    u32 pad[3];
    u16 *fc;
} Res_02204C98;

typedef struct Main_v3E30 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x224 - 0x4C];
    int o224;
    unsigned char pad228[0x22c - 0x228];
    int o22c;
    unsigned char pad230[0x240 - 0x230];
    u16 h240;
    unsigned char pad242[0x25a - 0x242];
    u8 b25a;
    u8 b25b;
} Main_v3E30;

typedef struct { u16 value[4]; u8 a[4], b[4]; u8 pad10[8]; } Buffer;

typedef struct { u8 first, second; } Palette;

typedef struct { char pad[0x68]; u32 lo : 19; u32 index : 2; } Flags_02201B20;

typedef struct Main_022053DC {
    void *owner;
    unsigned char pad04[0x64 - 4];
    int f64;
    unsigned char pad68[0x6c - 0x68];
    u32 f6c;
    unsigned char pad70[0x228 - 0x70];
    int o228;
    int o22c;
    int o230;
    int o234;
    unsigned char pad238[0x25a - 0x238];
    u8 b25a[8];
    u8 b262[4];
} Main_022053DC;

typedef short s16_022057CC;

typedef struct Point_022053DC { s16_022057CC x, y; } Point_022053DC;

typedef struct Pair { void *obj; u32 pad; } Pair;

typedef struct Main_022057CC {
    unsigned char pad00[0x50];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;
    unsigned char pad68[0x1b0 - 0x68];
    u32 h1b0[3];
    u32 h1bc;
    u32 h1c0;
    u32 h1c4;
    Pair h1c8[3];
    unsigned char pad1e0[0x240 - 0x1e0];
    u16 heap;
} Main_022057CC;

typedef struct Info_v53DC {
    unsigned char pad00[0x98];
    u32 species[3];
    u32 form[3];
    u32 gender[3];
    int sel;
} Info_v53DC;

typedef struct { void *entry; int extra; } Entry;

typedef struct { char pad[0x1c8]; Entry entries[3]; } Work_02201B20;

typedef struct Five { int v[5]; } Five;

typedef struct Bits_022053DC { u32 low : 1; u32 count : 3; u32 high : 28; } Bits_022053DC;

typedef struct { void *h; } E_02201B20;

typedef struct { char pad[0x210]; E_02201B20 a[2]; } W_022053DC;

typedef struct { void *h; int x; } Slot;

typedef struct {
    int v[6];
} Q_v53DC;

typedef struct { void *h; int x; } E_02205F40;

typedef struct { char pad[0x180]; E_02205F40 a[6]; } W_02205F40;

typedef struct { void *h; } E_02205F64;

typedef struct { char pad[0x1fc]; E_02205F64 a[4]; } W_02205F64;

typedef struct Point_02205F40 { s16 x, y; } Point_02205F40;

typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 lo : 4;
    u32 b4 : 1;
    u32 cur : 4;
    u32 prev : 4;
    u32 redraw : 1;
    u32 rest68 : 18;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest6c : 30;
    char p70[0x17c - 0x70];
    void *f17c;
    char p180[0x220 - 0x180];
    int f220;
    char p224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 f25a[8];
    u8 f262[4];
    u16 f266[3];
    u16 f26c[4];
    u8 *f274;
    int f278;
    int f27c;
} W_02206140;

typedef struct {
    u8 (*tab)[4];
    int *flags;
} Ctx_v53DC;

typedef short s16_022064CC;

typedef struct Point_022064CC { s16_022064CC x, y; } Point_022064CC;

typedef struct {
    char p0[0x68];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x180 - 0x6c];
    Slot slots[6];
    char p1b0[0x274 - 0x1b0];
    u8 *f274;
} W_022064CC;

typedef struct {
    unsigned int lo : 31;
    unsigned int top : 1;
} Top;

typedef struct {
    char *s;
    int f4;
    int f8;
    int fc;
} Ctx_022064CC;

typedef struct PalAnmObj PalAnmObj;

typedef struct { char *p; int state, colour, flag; } Ctx_0220663C;

typedef struct {
    unsigned int lo : 4;
    unsigned int b4 : 1;
} Bf_022064CC;

typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x242 - 0x6c];
    u8 row[4][8];
    char p262[0x266 - 0x262];
    u16 a266[3];
    u16 a26c[8];
    int k;
} W_02206950;

extern u32 func_020307B0(void *p);

extern void *BTL_MAIN_GetCompetitor(void ***);

extern unsigned func_02030CB0(unsigned);

extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

extern void *func_020056A0(void (*)(void *, void *), void *, int);

extern void func_02030EAC(struct Node *n);

extern void func_02030DA4(void *);

extern void * func_02030D28(struct Ctx *c);

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);

extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16_021F6560 step, u8 b, u8 c, u16 d, void *ctx);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

extern u32 KEY_GetTrg(void);

extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void func_02040618(u32 layer, u32 a, u32 b);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern unsigned int CLACT_DeleteUnit(struct Bank *bank);

extern void *func_020490F4(u32 id, u32 heap);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

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

extern void CLACT_AddActorSurfacePos(struct Obj_02201DA0 *p, const struct Vec2 *delta, u32 which);

extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern void BTLV_FINGER_CURSOR_Delete(void *);

extern void INFOWIN_Update(void *);

extern void func_0203FC6C(const struct BgVramReq *req, u32 which);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void func_020409B4(u32 index);

extern void INFOWIN_Init(u8, u8, void *, u16);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern int INFOWIN_Exit(void);

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_0204152C(int channel, u16 val);

extern void func_020403F4(u32 i);

extern int func_0207D55C(volatile u16 *reg);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16_02201DA0, u8, u8, u16, void *);

extern u32 CLACT_GetUnitDrawEnable(struct Bank *bank);

extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);

extern void GF_FONT_SetTextColor(u32, u32, u32);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern void PRINTSYS_Print(void *x, s16_02201DA0 y, s16_02201DA0 z, void *s, void *w);

extern void STRBUF_Delete(struct U16Vec *vec);

extern int TOUCHPANEL_HitTrg(const void *p);

extern unsigned int KEY_GetCont(void);

extern void *BTLV_FINGER_CURSOR_Create(void *pal, int b, int c);

extern int BTLV_FINGER_CURSOR_Start(void *h, int x, int y, int k, int m, int n);

extern int BTLV_FINGER_CURSOR_IsActive(void *h);

extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);

extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern int PALANM_GetDefaultWork(char *p, int i);

extern void MIi_CpuCopy16(const void *, void *, u32);

extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);

extern u32 func_020275E4(void);

extern u32 func_020275FC(u32);

extern u32 func_02027600(u32);

extern u32 func_020275E8(void);

extern u32 func_020275F8(u32);

extern void func_0207AD58(void *dst, int a, int b);

extern void func_02040820(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern int FADE_IsActive(void);

extern void func_0207D658(u32 addr, int plane, int brightness);

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

extern int FX_ModS32(int n, int d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern struct WordSet *func_0201EC64(u32 heap);

extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);

extern u8 func_020275EC(int i);

extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);

extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);

extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);

extern void func_0201EFA4(u32 p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

extern u32 func_0201ED04(struct WordSet *p);

extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);

extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);

extern u16 func_021D5528(u8 *, u8, u8 *, u8 *);

extern int BTL_POKEPARAM_IsFainted(void *);

extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);

extern int func_0201BC78(void);

extern int func_0201BCEC(void);

extern int func_0201BC3C(void);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void BMP_Delete(struct Obj020437AC *p);

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

int BTLV_INPUT_GetScreenButtonTable(BtlvInput *input);

int BTLV_INPUT_ProcessKeyInput(BtlvInput *input, u8 *key, int *out);

int BTLV_INPUT_IsInputBlocked(BtlvInput *input);

int BTLV_INPUT_GetPendingResult(BtlvInput *input);

void BTLV_INPUT_LoadCommonGraphics(BtlvInput *input);

void BTLV_INPUT_ActionScreenOpenTask(void *task, void *arg);

void BTLV_INPUT_WazaScreenOpenTask(void *task, void *arg);

void BTLV_INPUT_WazaScreenOpenInstantTask(void *task, void *arg);

void BTLV_INPUT_ActionScreenOpenInstantTask(void *task, void *arg);

void BTLV_INPUT_TargetScreenOpenTask(void *a0, void *arg);

void BTLV_INPUT_WazaScreenCloseTask(void *a0, void *arg);

void BTLV_INPUT_WaitScreenOpenTask(void *a0, void *arg);

void BTLV_INPUT_WaitScreenOpenInstantTask(void *task, void *arg);

void BTLV_INPUT_MessageScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_ListScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_SelectScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_ConfirmScreenOpenTask(void *h, void *arg);

void BTLV_INPUT_ListScreenOpenInstantTask(void *h, void *arg);

void BTLV_INPUT_ScreenResetTask(void *h, void *arg);

void BTLV_INPUT_TaskEndClearBusyBit(void *h);

void BTLV_INPUT_StartBgScrollTask(BtlvInput *input, int a1, int a2, int a3, int a4);

void BTLV_INPUT_BgScrollTaskMain(void *a0, void *arg);

void BTLV_INPUT_BgScrollTaskEnd(void *h);

void BTLV_INPUT_StartBgWipeTask(BtlvInput *input, int a1, int a2, int a3, int a4);

void BTLV_INPUT_BgWipeTaskMain(void *a0, void *arg);

void BTLV_INPUT_BgWipeTaskEnd(void *h);

void BTLV_INPUT_StartPaletteCycleTask(Main_022045A8 *m, int a1, int a2);

void BTLV_INPUT_PaletteCycleTaskMain(void *a0, void *arg);

void BTLV_INPUT_PaletteCycleTaskEnd(void *h);

void BTLV_INPUT_CreateCursorActors(Obj_02204698 *p, int a, int b);

void BTLV_INPUT_CursorActorTaskMain(void *a, void *arg);

void BTLV_INPUT_CursorActorTaskEnd(void *h);

void BTLV_INPUT_StartPaletteFlashTask(Main_02204838 *m, int a1);

void BTLV_INPUT_PaletteFlashTaskMain(void *a0, void *arg);

void BTLV_INPUT_PaletteFlashTaskEnd(void *h);

void BTLV_INPUT_StartBgScrollOffsetTask(Main_02204960 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);

void BTLV_INPUT_BgScrollOffsetTaskMain(void *a0, void *arg);

void BTLV_INPUT_WaitFadeTaskMain(void *a, void *arg);

void BTLV_INPUT_WaitFadeTaskEnd(void *h);

void BTLV_INPUT_CursorMoveTaskMain(void *a0, void *arg);

void BTLV_INPUT_CursorMoveTaskEnd(void *h);

void BTLV_INPUT_StartScreenTransition(Main_02204B0C *m, int c);

void BTLV_INPUT_VisibilityTaskMain(void *a, void *arg);

void BTLV_INPUT_WindowOpenTaskMain(void *a0, void *arg);

void BTLV_INPUT_WindowCloseTaskMain(void *a0, void *arg);

void BTLV_INPUT_GetTextBlockSize(struct StrObj *a, int b, int *outn, int *outq);

void BTLV_INPUT_DrawWazaButtons(Work_v3E30 *p, const Slots *q);

void BTLV_INPUT_DrawTargetButtons(char *s, Out *out, const Info_v3E30 *p);

void BTLV_INPUT_DrawMessageText(Main_v3E30 *m, const int *c);

void BTLV_INPUT_InitButtonState(char *m);

void BTLV_INPUT_DrawSelectScreenText(char *s, const int *b);

void BTLV_INPUT_ClearButtonState(Main_022053DC *m);

int BTLV_INPUT_GetNeighbourIndex(int a, int b);

void BTLV_INPUT_CreateActionButtons(Main_022057CC *m, Info_v53DC *q);

void BTLV_INPUT_DeleteActionButtonActors(char *p);

void BTLV_INPUT_SetActionUnitVisible(char *p, int a);

void BTLV_INPUT_CreateStatusIcons(char *p, int n);

void BTLV_INPUT_DeleteStatusIcons(W_022053DC *p);

void BTLV_INPUT_CreateWazaCursorActors(char *p, int mode);

void BTLV_INPUT_DeleteWazaCursorActors(char *o);

void BTLV_INPUT_CreateTargetActors(char *m);

void BTLV_INPUT_DeleteTargetActors(W_02205F40 *p);

void BTLV_INPUT_DeleteWazaActors(W_02205F64 *p);

void BTLV_INPUT_CreateBackActor(char *p);

void BTLV_INPUT_DeleteBackActor(char *p);

int BTLV_INPUT_ProcessButtonSelection(W_02206140 *p, const Ctx_v53DC *c, s8 (*rows)[12], u8 *list, int ret, int arg6);

int BTLV_INPUT_ProcessKeyRepeat(char *p);

void BTLV_INPUT_UpdateButtonActors(W_022064CC *p, u8 (* __restrict tab)[4], s8 (*rows)[12]);

int BTLV_INPUT_SetSelection(char *s, int a, int b);

void BTLV_INPUT_ButtonFlashTaskMain(void *task, void *arg);

void BTLV_INPUT_ButtonFlashTaskEnd(void *h);

void BTLV_INPUT_DrawRunButtonText(char *s, char *b);

void BTLV_INPUT_PrepareCommandSelect(char *p);

void BTLV_INPUT_ClearSlotEvents(char *p);

void BTLV_INPUT_RegisterTask(char *p, int a, int b);

int BTLV_INPUT_FindTask(char *p, int v);

void BTLV_INPUT_DeleteTask(char *p, void *q);

int BTLV_INPUT_AllocTaskSlot(char *p);

void BTLV_INPUT_DeleteAllTasks(char *p);

int BTLV_INPUT_IsWazaSelectable(char *p, char *q, int i);

void BTLV_INPUT_UpdateWazaRow(W_02206950 *p);

void BTLV_INPUT_BlendWindowPalette(char *p);

void BTLV_INPUT_RestoreWindowPalette(char *p);

int BTLV_INPUT_GetMessageBoxMode(char *p);

void BTLV_INPUT_PlayConfirmSe(char *p);

void BTLV_INPUT_PlayCancelSe(char *p);

void BTLV_INPUT_PlaySelectSe(char *p);

void BTLV_INPUT_PlayCursorSe(char *p);

void BTLV_INPUT_PlayPageSe(char *p);

void BTLV_INPUT_PlayOpenSe(char *p);

void BTLV_INPUT_PlayBackSe(char *p);

extern const char d_0220AEB0[];

extern char d_0220A3D4[];

extern const Ent_02202238 d_0220A8BC[];

extern u8 d_0689E090[][15];

extern u8 d_0689E0B0[][15];

extern Ent_v1DA0 *gBtlvScdTargetRegionsSingleB[][15];

extern Ent_v1DA0 *gBtlvScdTargetRegionsDoubleB[][15];

extern const Tbl_v1DA0 d_0220A598;

extern const Sec sec_0220A380;

extern const u8 d_0220A380[3];

extern void *const d_0220AE98[];

extern void *const d_0220AEA4[];

extern const Pair_022033F4 d_0220A4EC[];

extern const Ent_v3E30 d_0220A46C[][2];

extern const Quad d_0220A53C;

extern Row_02201B20 d_0220A85C[];

extern const int d_0220A3B4[][2];

extern const u8 d_0220A38C[][2];

extern const int d_0220A3E4[][2];

extern const PosTab d_0220A5B0;

extern const PosTab d_0220A5D0;

extern const int d_0220A5F0[];

extern const u16 d_0220A392[];

extern const Point_02201B20 d_0220A3C4[];

extern const Pos_02204C98 d_0220A4AC[];

extern const int d_0220A7FC[2][6][2];

extern const int d_0220A94C[2][3][15];

extern const Palette d_0220A386[];

extern const Point_022053DC d_0220A50C[][3];

extern const Five d_0220A558, d_0220A56C, d_0220A544;

extern const Q_v53DC d_0220A580;

BtlvInput *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k)
{
    return BTLV_INPUT_Create(a, b, 0, c, d, e, 0, 0, k);
}

void BTLV_INPUT_CreateWithMode(int a, int b, int c, int d, int e, int f, int g, u16 k)
{
    BTLV_INPUT_Create(a, b, c, d, e, f, g, 1, k);
}

BtlvInput *BTLV_INPUT_Create(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap)
{
    BtlvInput *input;
    Res_02201DA0 *r;
    int i;

    input = func_02030734(heap, 0x2e0, 1, d_0220AEB0, 0x39a);
    input->heap = heap;
    input->taskMgrMem = func_02030734(input->heap, func_02030CB0(8), 1, d_0220AEB0, 0x39e);
    input->taskMgr = func_02030CBC(8, input->taskMgrMem);
    input->infoWinParam = (void *)a;
    input->font = (void *)e;
    input->battleType = b;
    input->seMode = c;
    input->cursorVisible = (u8 *)f;
    input->flags.prevCursor = 15;
    input->infoWinEnabled = h;
    input->palAnm = (void *)d;
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
    input->msgData = func_02045B38(0, 2, 12, input->heap);
    input->pending = -1;
    BTLV_INPUT_LoadScreenResources(input);
    r = func_02030734((u16)((input->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x3cc);
    r->owner = input;
    r->v = g;
    BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, (void (*)(void *, void *))(BTLV_INPUT_VisibilityTaskMain), r, 0), 0);
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
    func_02030DA4(input->taskMgr);
    func_020307B0(input->taskMgrMem);
    func_020307B0(input);
}

void BTLV_INPUT_UpdateInfoWindow(BtlvInput *input)
{
    INFOWIN_Update(func_02030D28((struct Ctx *)input->taskMgr));
}

void BTLV_INPUT_InfoWindowTask(void *unused, void *arg)
{
    BtlvInput *input = arg;

    INFOWIN_Update(func_02030D28((struct Ctx *)input->taskMgr));
}

void BTLV_INPUT_LoadScreenResources(BtlvInput *input)
{
    func_0203FC6C((const struct BgVramReq *)d_0220A3D4, 1);
    input->arc = func_020490F4(0xb, input->heap);
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
    func_020409B4(6);
    INFOWIN_Init(6, 15, input->infoWinParam, input->heap);
    func_02040588(6, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout(0, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, 0xe0, 0x20);
    input->flags.redraw = 1;
    if (input->infoWinEnabled == 1)
        input->infoWinTask = func_02030DA8(BTLV_EFFECT_GetOwner(), BTLV_INPUT_InfoWindowTask, input, 0);
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
        func_02030EAC(input->infoWinTask);
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
        func_0203FCA0((u8)(i + 4), (const struct BgTemplate *)(&d_0220A8BC[i]), (u8)d_0220A8BC[i].f20);
        func_0204152C((u8)(i + 4), (int)0x3ff);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)input, i + 4, 0, 0, 2, 2, 2, 2);
    }
}

void BTLV_INPUT_ReleaseBgLayers(void)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_02040588((u8)(i + 4), (int)0);
        func_020403F4((u8)(i + 4));
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

    p = func_02030734((u16)((input->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x4F7);
    if (flag == 1)
        PALANM_RequestFade(input->palAnm, 0xA, 0xFFFF, 1, 0, 0x10, 0, input->taskMgr);
    else
        PALANM_RequestFade(input->palAnm, 0xA, 0xFFFF, 1, 0xC, 0x10, 0, input->taskMgr);
    input->flags.fadeKind = 1;
    p[0] = (int)input;
    BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, (void ( *)(void *, void *))(BTLV_INPUT_WaitFadeTaskMain), p, 0), (int)BTLV_INPUT_WaitFadeTaskEnd);
}

/*
 * note: the two zero arguments of FADE_Start sit in r6 because the call is written in
 *   both arms of the if (the arms are cross-jumped and the shared zero is hoisted).
 * trailing: 022026FC..0220270C is an unlabelled getter (mode bits 15..16 of +0x68 != 0).
 */
void BTLV_INPUT_StartScreenFadeTask(BtlvInput *input)
{
    BtlvInput **q;
    q = func_02030734((u16)((input->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x50c);
    if (func_0207D55C((volatile u16 *)0x0400106c) <= 0)
        FADE_Start(2, 0x10, 0, 0);
    else
        FADE_Start(8, 0x10, 0, 0);
    BTLV_INPUT_LoadScreenResources(input);
    input->flags.fadeKind = 2;
    *q = input;
    BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, (void ( *)(void *, void *))(BTLV_INPUT_WaitFadeTaskMain), q, 0), (int)BTLV_INPUT_WaitFadeTaskEnd);
}

/*
 * notes:    tests a 2-bit field at bits 15..16 of the word at +0x68, returns 1 if nonzero. Witness for calls in ov098 func_021B6578 (2026-10-05, lane W-B).
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
            t = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x549);
            input->flags.busy = 1;
            t->input = input;
            if (input->infoWinEnabled == 1)
                BTLV_EFFECT_StartIntroEffect();
            BTLV_INPUT_DeleteWazaCursorActors((void *)input);
            BTLV_INPUT_DeleteActionButtonActors((void *)input);
            if (input->screen == 1 || input->screen == 4) {
                BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_WaitScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
            } else {
                t->fromScreen = input->screen;
                BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_WaitScreenOpenInstantTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
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
        t1 = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x570);
        input->battlePos = a->fbc;
        BTLV_INPUT_PrepareCommandSelect((void *)input);
        BTLV_EFFECT_SetIntroState(2);
        if (a->fbc >= 2)
            a->fbc = (a->fbc - 2) / 2;
        input->flags.busy = 1;
        input->flags.restrictedChoice = a->f90;
        t1->input = input;
        t1->slot = a->fbc;
        input->partyIdx = a->fbc;
        if (input->screen == 0)
            BTLV_INPUT_ClearSlotEvents((void *)input);
        for (i = 0; i < 6; i++) {
            *(T12 *)&input->slotInfo[0][i] = a->a[i];
            *(T12 *)&input->slotInfo[1][i] = a->b[i];
        }
        for (j = 0; j < 4; j++)
            input->enabled[j] = 1;
        input->enabled[1] = BTLV_EFFECT_IsRecordAllowed();
        BTLV_INPUT_DeleteActionButtonActors((void *)input);
        BTLV_INPUT_CreateActionButtons((void *)input, (Info_v53DC *)((struct Info *)a));
        BTLV_INPUT_CreateStatusIcons((void *)input, a->bc5);
        t1->bgFile = BTLV_INPUT_GetMessageBoxMode((void *)input);
        BTLV_INPUT_DrawRunButtonText((void *)input, (char *)a);
        if (input->screen == 2 || input->screen == 5) {
            BTLV_INPUT_SetActionUnitVisible((void *)input, 0);
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_ActionScreenOpenInstantTask, t1, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_CreateWazaCursorActors((void *)input, 0);
            if (a->f94 != 0)
                BTLV_INPUT_CreateWazaCursorActors((void *)input, 1);
            input->flags.doubleCursor = a->f94;
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_ActionScreenOpenTask, t1, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 2: {
        Arg2 *a = arg;
        BtlvInputTask *t2;
        t2 = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x5bd);
        BTLV_INPUT_DrawWazaButtons((void *)input, (const Slots *)((const struct Slots *)a));
        input->flags.busy = 1;
        t2->input = input;
        t2->slot = a->f10;
        input->transformed = a->f14;
        t2->bgFile = BTLV_INPUT_GetMessageBoxMode((void *)input);
        for (j = 0; j < 4; j++)
            input->moveIds[j] = a->h[j];
        if (input->infoWinEnabled == 1 && (input->battleType == 1 || input->battleType == 2)) {
            BTLV_EFFECT_ResetIntroState(2);
            BTLV_EFFECT_StartEffect(0x244);
        }
        if (input->screen == 3) {
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_WazaScreenCloseTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else if (input->screen == 0) {
            BTLV_INPUT_CreateWazaCursorActors((void *)input, 0);
            if (input->flags.doubleCursor)
                BTLV_INPUT_CreateWazaCursorActors((void *)input, 1);
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_WazaScreenOpenTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_DeleteActionButtonActors((void *)input);
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_WazaScreenOpenInstantTask, t2, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 3:
        t = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x5ec);
        BTLV_INPUT_DrawTargetButtons((void *)input, (Out *)((struct Out *)t), (const Info_v3E30 *)arg);
        input->flags.busy = 1;
        t->input = input;
        t->slot = ((u8 *)arg)[0x48];
        BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_TargetScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        break;
    case 4:
        t = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x5f8);
        BTLV_INPUT_DrawMessageText((void *)input, arg);
        input->flags.busy = 1;
        t->input = input;
        input->flags2.inputEnabled = ((int *)arg)[2];
        BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_MessageScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        break;
    case 5: {
        Arg5 *a = arg;
        int k;
        t = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x605);
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
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_ListScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_ListScreenOpenInstantTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        }
        break;
    }
    case 6: {
        Arg2 *a = arg;
        w = 0;
        for (j = 0; j < 3; j++)
            input->enabled[j] = 1;
        BTLV_INPUT_DrawSelectScreenText((void *)input, (const int *)a);
        switch (a->fc) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            GF_FONT_SetTextColor(1, 2, 0);
            w = func_02045EC0(input->msgData, a->fc + 8);
            break;
        }
        if (input->screen == 0) {
            t = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x65f);
            input->flags.busy = 1;
            t->input = input;
            if (a->fc == 0) {
                t->scrollX = 0;
                t->scrollY = 0x100;
            } else {
                t->scrollX = 0x100;
                t->scrollY = 0;
            }
            t->text = w;
            BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_SelectScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        } else {
            if (a->fc == 0)
                BTLV_INPUT_StartBgScrollOffsetTask((void *)input, 4, 0, 0x100, 2, 2, 2, 2);
            else
                BTLV_INPUT_StartBgScrollOffsetTask((void *)input, 4, 0x100, 0, 2, 2, 2, 2);
            if (w != 0) {
                PRINTSYS_Print((void *)input->bmpA, 0x18, 0x38, w, (void *)input->font);
                STRBUF_Delete(w);
            }
            BMP_WIN_MakeScreen(input->bmpWinA);
            func_020409B4(6);
            BMP_WIN_TransferChars(input->bmpWinA);
        }
        break;
    }
    case 7:
        t = func_02030734(HEAPID(input->heap), 0x24, 1, d_0220AEB0, 0x68c);
        input->flags.busy = 1;
        t->input = input;
        BTLV_INPUT_RegisterTask((void *)input, (int)func_02030DA8(input->taskMgr, BTLV_INPUT_ConfirmScreenOpenTask, t, 1), (int)BTLV_INPUT_TaskEndClearBusyBit);
        input->enabled[0] = 1;
        input->enabled[1] = 1;
        break;
    }
    input->screen = mode;
}

int BTLV_INPUT_ProcessTouchInput(BtlvInput *input, Cmd *c, int x)
{
    int r;
    int k;
    u32 keys;
    int ret;
    int i;
    int cnt;
    int idx;
    Ent_v1DA0 *e;
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
        r = TOUCHPANEL_HitTrg(c->key);
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
            r = BTLV_INPUT_SetSelection((void *)input, r, c->vals[r]);
        return r;
    }

    k = TOUCHPANEL_HitTrg(c->key);
    r = BTLV_INPUT_ProcessButtonSelection((void *)input, (const Ctx_v53DC *)c, (s8 (*)[12])x, (u8 *)0, k, input->transformed);
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
            if (BTLV_INPUT_IsWazaSelectable((void *)input, (char *)c, r) == 0 && !input->flags2.choiceMade) {
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
        r = BTLV_INPUT_SetSelection((void *)input, r, c->vals[r]);
    return r;
}

int BTLV_INPUT_GetScreenButtonTable(BtlvInput *input)
{
    int r = 0;
    Tbl_v1DA0 t;

    switch (input->flags.fingerStep) {
    case 0:
        t = d_0220A598;
        if (input->fingerCursor == 0)
            input->fingerCursor = BTLV_FINGER_CURSOR_Create(input->palAnm, 0xb, input->heap);
        if (BTLV_FINGER_CURSOR_Start(input->fingerCursor, t.p[input->flags.fingerPos].x, t.p[input->flags.fingerPos].y, 2, 7, 0x10) != 0) {
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
            *key = sec_0220A380.key[input->flags.slotIndex];
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
        a = TOUCHPANEL_HitTrg(sec_0220A380.db.a);
        i = BTLV_INPUT_ProcessButtonSelection((void *)input, (const Ctx_v53DC *)((Cmd *)(&sec_0220A380.db)), (s8 (*)[12])((int)(d_0220AE98[input->flags.slotIndex])), (u8 *)((int)0), a, BTL_POKEPARAM_IsTransformed(input->pokeParam[input->flags.slotIndex]));
    } else {
        a = TOUCHPANEL_HitTrg(sec_0220A380.da.a);
        i = BTLV_INPUT_ProcessButtonSelection((void *)input, (const Ctx_v53DC *)((Cmd *)(&sec_0220A380.da)), (s8 (*)[12])((int)(d_0220AEA4[input->flags.slotIndex])), (u8 *)((int)d_0220A380), a, BTL_POKEPARAM_IsTransformed(input->pokeParam[input->flags.slotIndex]));
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
            r = BTLV_INPUT_IsWazaSelectable((void *)input, (char *)(&sec_0220A380.db), i);
            if (r == 0 && !(input->flags2.choiceMade)) {
                input->lastChoice[input->partyIdx][input->screen] = i;
                BTLV_INPUT_PlayOpenSe((void *)input);
            } else if (r == 1 && !(input->flags2.choiceMade)) {
                BTLV_INPUT_PlayCursorSe((void *)input);
            }
            i = BTLV_INPUT_SetSelection((void *)input, i, sec_0220A380.db.c[i]);
        } else {
            r = BTLV_INPUT_IsWazaSelectable((void *)input, (char *)(&sec_0220A380.da), i);
            if (r == 0 && !(input->flags2.choiceMade)) {
                input->lastChoice[input->partyIdx][input->screen] = i;
                BTLV_INPUT_PlayOpenSe((void *)input);
            } else if (r == 1 && !(input->flags2.choiceMade)) {
                BTLV_INPUT_PlayCursorSe((void *)input);
            }
            i = BTLV_INPUT_SetSelection((void *)input, i, sec_0220A380.da.c[i]);
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

int BTLV_INPUT_GetPendingResult(BtlvInput *input)
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

    func_02049658(input->arc, 0x5b, 4, 0, 0, 0, input->heap);
    func_02049658(input->arc, 0x71, 7, 0, 0x8000, 0, input->heap);
    func_020498F4(input->arc, 0x72, 7, 0, 0, 0, input->heap);
    PALANM_LoadHandlePaletteToSlot(input->palAnm, input->arc, 0x5c, input->heap, 1, 0x1e0, 0);
    if (input->infoWinEnabled == 1)
        MIi_CpuCopy16((const void *)(PALANM_GetDefaultWork((char *)BTLV_EFFECT_GetPalanm(), 1) + 0x40), input->palBackup, 0x20);
    input->resCommonChr = CLACT_RegisterCharacter(input->arc, 0x73, 0, 1, input->heap);
    input->resCommonCell = CLACT_RegisterCellAnim(input->arc, 0x75, 0x76, input->heap);
    input->resCommonPal = CLACT_RegisterPalette(input->arc, 0x74, 1, 0, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, (u16)(CLACT_GetPaletteVramAddress(input->resCommonPal, 1) >> 1), 0x100);
    input->resButtonChr = CLACT_RegisterCharacter(input->arc, 0x77, 0, 1, input->heap);
    input->resButtonCell = CLACT_RegisterCellAnim(input->arc, 0x78, 0x79, input->heap);
    arc = func_020490F4(func_020275E4(), (u16)((input->heap & 0x7fff) | 0x8000));
    file = func_020275FC(0);
    input->typeCell = CLACT_RegisterCellAnim(arc, file, func_02027600(0), input->heap);
    input->typePal = CLACT_RegisterPalette(arc, func_020275E8(), 1, 0x100, input->heap);
    PALANM_CopyHwPaletteToSlot(input->palAnm, 3, (u16)(CLACT_GetPaletteVramAddress(input->typePal, 1) >> 1), 0x60);
    for (i = 0; i < 4; i++)
        input->typeChr[i] = CLACT_RegisterCharacter(arc, func_020275F8(0), 0, 1, input->heap);
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
        func_020498F4((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x68, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 1, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_StartBgWipeTask(ctx->input, 0, 0x1c0, 8, 8);
        BTLV_INPUT_BlendWindowPalette((void *)ctx->input);
        BMP_WIN_MakeScreen(ctx->input->bmpWinB);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(ctx->input->palAnm, 2, 3, 1, 12, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinB);
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(7, 0);
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
        func_020498F4((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x6f, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(ctx->input->palAnm, 2, 3, 1, 12, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
        if (ctx->input->flags.animTasks == 0) {
            if (ctx->input->battleType == 2 && ctx->slot != 4) {
                func_020498F4((void *)ctx->input->arc, 0x5e, 4, 0, 0, 0, ctx->input->heap);
            } else {
                func_020498F4((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
            }
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            func_020409B4(6);
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
        func_020498F4((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        func_020409B4(6);
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
        func_020498F4((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x68, 5, 0, 0, 0, ctx->input->heap);
        BMP_WIN_MakeScreen(ctx->input->bmpWinB);
        BTLV_INPUT_BlendWindowPalette((void *)ctx->input);
        func_020409B4(6);
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

void BTLV_INPUT_TargetScreenOpenTask(void *a0, void *arg)
{
    BtlvInputTask *ctx = arg;

    int z = 0;

    func_020498F4((void *)ctx->input->arc, 0x5d, 4, 0, z, z, ctx->input->heap);
    func_020498F4((void *)ctx->input->arc, ctx->bgFile, 4, 0x440, 0x380, z, ctx->input->heap);
    BMP_WIN_MakeScreen(ctx->input->bmpWinA);
    func_020409B4(6);
    if (ctx->input->battleType == 2) {
        func_020498F4((void *)ctx->input->arc, 0x6a, 5, 0, z, z, ctx->input->heap);
    } else {
        func_020498F4((void *)ctx->input->arc, 0x69, 5, 0, z, z, ctx->input->heap);
    }
    BMP_WIN_TransferChars(ctx->input->bmpWinA);
    BTLV_INPUT_DeleteTask((void *)ctx->input, (void *)a0);
}

void BTLV_INPUT_WazaScreenCloseTask(void *a0, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        func_020498F4((void *)ctx->input->arc, ctx->bgFile, 4, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0xc0, 2, 2, 2, 2);
        ctx->state = ctx->state + 1;
        break;
    case 1:
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        func_020409B4(6);
        func_020498F4((void *)ctx->input->arc, 0x68, 5, 0, 0, 0, ctx->input->heap);
        BMP_WIN_TransferChars(ctx->input->bmpWinA);
        CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
        BTLV_INPUT_DeleteTask((void *)ctx->input, (void *)a0);
        break;
    }
}

void BTLV_INPUT_WaitScreenOpenTask(void *a0, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x1000, 0x3000, 0x400, 0xa8);
        ctx->state = ctx->state + 1;
        break;
    case 1:
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02040588(7, 1);
        ctx->state = ctx->state + 1;
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0)
            BTLV_INPUT_DeleteTask((void *)ctx->input, (void *)a0);
        break;
    }
}

void BTLV_INPUT_WaitScreenOpenInstantTask(void *task, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        func_020498F4((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x6e, 5, 0, 0, 0, ctx->input->heap);
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
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02040588(7, 1);
        ctx->state++;
        break;
    case 5:
    default:
        if (ctx->input->flags.animTasks == 0)
            BTLV_INPUT_DeleteTask((void *)ctx->input, task);
        break;
    }
}

void BTLV_INPUT_MessageScreenOpenTask(void *h, void *arg)
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
            func_02040588(5, 1);
            func_02040588(7, 0);
            ctx->state++;
        }
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            func_020409B4(6);
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, h);
        }
        break;
    }
}

void BTLV_INPUT_ListScreenOpenTask(void *h, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        func_020498F4((void *)ctx->input->arc, 0x5d, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x6f, 5, 0, 0, 0, ctx->input->heap);
        BTLV_INPUT_PlayConfirmSe((void *)ctx->input);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(ctx->input, 0x3000, 0x1000, -0x400, 0x98);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(ctx->input->palAnm, 2, 3, 1, 0xc, 0, 0x842, ctx->input->taskMgr);
        ctx->state++;
        break;
    case 1:
        if (ctx->input->flags.animTasks == 0) {
            func_020498F4((void *)ctx->input->arc, 0x64, 4, 0, 0, 0, ctx->input->heap);
            BMP_WIN_MakeScreen(ctx->input->bmpWinA);
            func_020409B4(6);
            BTLV_INPUT_StartBgWipeTask(ctx->input, d_0220A4EC[ctx->input->flags.slotIndex].a, d_0220A4EC[ctx->input->flags.slotIndex].b, 8, 8);
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
            BTLV_INPUT_DeleteTask((void *)ctx->input, h);
        }
        break;
    }
}

void BTLV_INPUT_SelectScreenOpenTask(void *h, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        func_020498F4((void *)ctx->input->arc, 0x62, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x6d, 5, 0, 0, 0, ctx->input->heap);
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
            func_020409B4(6);
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 4, ctx->scrollX, ctx->scrollY, 1, 1, 2, 0);
            BTLV_INPUT_DeleteTask((void *)ctx->input, h);
        }
        break;
    }
}

void BTLV_INPUT_ConfirmScreenOpenTask(void *h, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        func_020498F4((void *)ctx->input->arc, 0x63, 4, 0, 0, 0, ctx->input->heap);
        func_020498F4((void *)ctx->input->arc, 0x6b, 5, 0, 0, 0, ctx->input->heap);
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
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(7, 0);
            BTLV_INPUT_DeleteTask((void *)ctx->input, h);
        }
        break;
    }
}

void BTLV_INPUT_ListScreenOpenInstantTask(void *h, void *arg)
{
    BtlvInputTask *ctx = arg;

    switch (ctx->state) {
    case 0:
        func_020498F4((void *)ctx->input->arc, 0x64, 4, 0, 0, 0, ctx->input->heap);
        BMP_WIN_MakeScreen(ctx->input->bmpWinA);
        BTLV_INPUT_RestoreWindowPalette((void *)ctx->input);
        func_020409B4(6);
        BTLV_INPUT_StartBgWipeTask(ctx->input, d_0220A4EC[ctx->input->flags.slotIndex].a, d_0220A4EC[ctx->input->flags.slotIndex].b, 8, 8);
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
            BTLV_INPUT_DeleteTask((void *)ctx->input, h);
        }
        break;
    }
}

void BTLV_INPUT_ScreenResetTask(void *h, void *arg)
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
        func_020409B4(6);
        BTLV_INPUT_StartBgWipeTask(ctx->input, d_0220A4EC[ctx->input->flags.slotIndex].a, d_0220A4EC[ctx->input->flags.slotIndex].b, 8, 8);
        BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, -1, 0, 0, 1, 1, 2, 0);
        ctx->state++;
        break;
    case 2:
    default:
        if (ctx->input->flags.animTasks == 0) {
            BMP_WIN_TransferChars(ctx->input->bmpWinA);
            CLACT_SetUnitDrawEnable(ctx->input->unitWaza, 1);
            BTLV_INPUT_StartBgScrollOffsetTask((void *)ctx->input, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((void *)ctx->input, h);
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

void BTLV_INPUT_TaskEndClearBusyBit(void *h)
{
    BtlvInput *input = *(BtlvInput **)TCBL_GetTaskUserData(h);
    input->flags.busy = 0;
}

void BTLV_INPUT_StartBgScrollTask(BtlvInput *input, int a1, int a2, int a3, int a4)
{
    BtlvInputSlideTask *o;

    o = func_02030734((u16)((input->heap & 0x7fff) | 0x8000), 0x14, 0, d_0220AEB0, 0xb97);
    o->input = input;
    o->cur = a1;
    o->goal = a2;
    o->step = a3;
    o->scroll = a4;
    BTLV_INPUT_RegisterTask((void *)input, (int)func_020056A0(BTLV_INPUT_BgScrollTaskMain, o, 0), (int)BTLV_INPUT_BgScrollTaskEnd);
    input->flags.animTasks = input->flags.animTasks + 1;
}

void BTLV_INPUT_BgScrollTaskMain(void *a0, void *arg)
{
    BtlvInputSlideTask *o = arg;
    int m[4];

    o->cur = o->cur + o->step;
    if (o->step > 0)
        o->scroll = o->scroll - 2;
    else if (o->step < 0)
        o->scroll = o->scroll + 2;
    func_0207AD58(m, o->cur, o->cur);
    func_02040820(7, 0, 0x80, (u32)m, 0x100, 0x100);
    func_02040820(7, 3, o->scroll, (u32)m, 0x100, 0x100);
    if (o->cur == o->goal)
        BTLV_INPUT_DeleteTask((void *)o->input, (void *)a0);
}

void BTLV_INPUT_BgScrollTaskEnd(void *h)
{
    BtlvInput *input = *(BtlvInput **)TCBL_GetTaskUserData(h);
    input->flags.animTasks--;
}

void BTLV_INPUT_StartBgWipeTask(BtlvInput *input, int a1, int a2, int a3, int a4)
{
    BtlvInputScrollTask *o;

    o = func_02030734((u16)((input->heap & 0x7fff) | 0x8000), 0x18, 0, d_0220AEB0, 0xbd5);
    o->input = input;
    o->state = 0;
    o->x = a1;
    o->y = a2;
    o->dy = a3;
    o->count = a4;
    BTLV_INPUT_RegisterTask((void *)input, (int)func_020056A0(BTLV_INPUT_BgWipeTaskMain, o, 0), (int)BTLV_INPUT_BgWipeTaskEnd);
    input->flags.animTasks = input->flags.animTasks + 1;
}

void BTLV_INPUT_BgWipeTaskMain(void *a0, void *arg)
{
    BtlvInputScrollTask *c = arg;

    if (c->state == 0) {
        func_02040618(4, 0, c->x);
        func_02040618(4, 3, c->y);
        c->state = c->state + 1;
        return;
    }
    c->y = c->y + c->dy;
    func_02040618(4, 3, c->y);
    c->count = c->count - 1;
    if (c->count == 0)
        BTLV_INPUT_DeleteTask((void *)c->input, (void *)a0);
}

void BTLV_INPUT_BgWipeTaskEnd(void *h)
{
    BtlvInput *input = *(BtlvInput **)TCBL_GetTaskUserData(h);
    input->flags.animTasks--;
}

void BTLV_INPUT_StartPaletteCycleTask(Main_022045A8 *m, int a1, int a2)
{
    Obj_022045A8 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0xc10);
    o->main = m;
    o->idx = 0;
    o->set = a2;
    o->cnt = 2;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_020056A0(BTLV_INPUT_PaletteCycleTaskMain, o, 0), (int)BTLV_INPUT_PaletteCycleTaskEnd);
    m->st = m->st + 1;
}

/*
 * lever:    the table extern is `const` (non-const put the cnt store before the address add)
 */
void BTLV_INPUT_PaletteCycleTaskMain(void *a0, void *arg)
{
    Ctx_0220461C *c = arg;

    int i;

    c->cnt = c->cnt - 1;
    if (c->cnt == 0) {
        c->cnt = 2;
        func_02040618(5, 0, d_0220A46C[c->set][c->idx].v0);
        i = c->idx;
        c->idx = i + 1;
        func_02040618(5, 3, d_0220A46C[c->set][i].v1);
        if (c->idx >= 2)
            BTLV_INPUT_DeleteTask(c->main, (void *)a0);
    }
}

void BTLV_INPUT_PaletteCycleTaskEnd(void *h)
{
    char *p = *((char **)TCBL_GetTaskUserData(h));
    ((Bits_02204678 *)(p + 0x68))->n--;
}

/*
 * note: the row offset goes into the row pointer first and the table base is added
 *   to it (base + offset); that order gives the original r0/r1 colouring at +0056.
 */
void BTLV_INPUT_CreateCursorActors(Obj_02204698 *p, int a, int b)
{
    Res_02203E30 *r;
    u16 v;
    int i;
    Row_02201B20 *row;
    Quad quad;

    r = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xc53);
    quad = d_0220A53C;
    r->owner = p;
    r->h = CLACT_CreateUnit(6, 0, p->heap);
    row = (Row_02201B20 *)(a << 5);
    row = (Row_02201B20 *)((u32)d_0220A85C + (u32)row);
    v = row->val[b];
    for (i = 0; i < 6; i++) {
        if (row->pos[i].x == -1) {
            r->e[i] = 0;
        } else {
            r->e[i] = (struct Obj_02204698 *)CLACT_CreateActor(r->h, p->h104, p->h108, p->h10c, &quad, 1, p->heap);
            CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(r->e[i]), (const struct Vec2 *)(&row->pos[i]), 1);
            CLACT_SetActorAffineMode(r->e[i], 2);
            CLACT_SetActorAutoAnim((struct Obj *)(r->e[i]), 1);
            CLACT_SetActorAnimSeq(r->e[i], v);
        }
    }
    BTLV_INPUT_RegisterTask((char *)p, (int)func_02030DA8(p->h0, BTLV_INPUT_CursorActorTaskMain, r, 0), (int)BTLV_INPUT_CursorActorTaskEnd);
    p->f68.n++;
}

void BTLV_INPUT_CursorActorTaskMain(void *a, void *arg)
{
    void **s = arg;

    int i;
    for (i = 0; i < 6; i++) {
        if (s[i + 2] != 0 && CLACT_IsActorAnimActive(s[i + 2]) != 0)
            return;
    }
    BTLV_INPUT_DeleteTask(s[0], a);
}

void BTLV_INPUT_CursorActorTaskEnd(void *h)
{
    Ctx_022047F8 *c = (Ctx_022047F8 *)TCBL_GetTaskUserData(h);
    int i;

    for (i = 0; i < 6; i++) {
        if (c->ent[i] != 0)
            CLACT_DeleteActor((struct Obj *)((struct Obj_02203E30 *)(c->ent[i])));
    }
    CLACT_DeleteUnit((struct Bank *)((int)((struct Bank *)c->h4)));
    c->main->st = c->main->st - 1;
}

void BTLV_INPUT_StartPaletteFlashTask(Main_02204838 *m, int a1)
{
    Obj_02204838 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0xcc9);
    o->main = m;
    o->f4 = a1;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_02030DA8(m->f0, BTLV_INPUT_PaletteFlashTaskMain, o, 0), (int)BTLV_INPUT_PaletteFlashTaskEnd);
    m->st = m->st + 1;
}

void BTLV_INPUT_PaletteFlashTaskMain(void *a0, void *arg)
{
    Ctx_022048A4 *c = arg;

    int k;
    int changed = 0;
    int target;
    char *p;
    int j;
    s16_022044A0 v[2];

    for (k = 0; k < 2; k++) {
        target = d_0220A3B4[k][c->f4];
        if (k == 0) {
            p = (char *)c->main + 0x47 * 4;
        } else {
            if (((c->main->f68 << 17) >> 31) == 0) {
                break;
            }
            p = (char *)c->main + 0x53 * 4;
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
            CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(*(void **)(p + j * 8)), (const struct Vec2 *)v, 1);
        }
    }
    if (changed == 0) {
        BTLV_INPUT_DeleteTask((char *)c->main, (void *)a0);
    }
}

void BTLV_INPUT_PaletteFlashTaskEnd(void *h)
{
    char *p = *((char **)TCBL_GetTaskUserData(h));
    ((Bits_02204940 *)(p + 0x68))->n--;
}

void BTLV_INPUT_StartBgScrollOffsetTask(Main_02204960 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Obj_02204960 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xd1d);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    o->f14 = a5;
    o->f18 = a6;
    o->f1c = a7;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_020056A0(BTLV_INPUT_BgScrollOffsetTaskMain, o, 0), 0);
}

void BTLV_INPUT_BgScrollOffsetTaskMain(void *a0, void *arg)
{
    Ctx_022049C8 *c = arg;

    if (c->f4 != -1) {
        func_02040618((u8)c->f4, (int)0, (int)c->f8);
        func_02040618((u8)c->f4, (int)3, (int)c->fc);
    }
    if (c->f10 != 2) {
        func_02040588((int)4, (u8)c->f10);
    }
    if (c->f14 != 2) {
        func_02040588((int)5, (u8)c->f14);
    }
    if (c->f18 != 2) {
        func_02040588((int)6, (u8)c->f18);
    }
    if (c->f1c != 2) {
        func_02040588((int)7, (u8)c->f1c);
    }
    BTLV_INPUT_DeleteTask(c->main, (void *)a0);
}

void BTLV_INPUT_WaitFadeTaskMain(void *a, void *arg)
{
    char **s = arg;

    if (PALANM_GetFadeRequestBits(((struct Obj21770 *)(*s))->f64) != 0)
        return;
    if (FADE_IsActive() != 0)
        return;
    if (((Bits_02204A3C *)(*s + 0x68))->mode == 1)
        BTLV_INPUT_ReleaseScreenResources((BtlvInput *)(*s));
    BTLV_INPUT_DeleteTask(*s, a);
}

void BTLV_INPUT_WaitFadeTaskEnd(void *h)
{
    char *p = *((char **)TCBL_GetTaskUserData(h));
    ((Bits_02204A70 *)(p + 0x68))->mode = 0;
}

void BTLV_INPUT_CursorMoveTaskMain(void *a0, void *arg)
{
    Ctx_v3E30 *c = arg;

    s16_02203E30 v[2];

    CLACT_GetActorSurfacePos(c->main->o210, (struct PtS *)v, 1);
    v[0] -= 8;
    CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)((struct Obj_02204698 *)c->main->o210), (const struct Vec2 *)v, 1);
    CLACT_GetActorSurfacePos(c->main->o214, (struct PtS *)v, 1);
    v[0] -= 8;
    CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)((struct Obj_02204698 *)c->main->o214), (const struct Vec2 *)v, 1);
    if (v[0] == 0xe0) {
        BTLV_INPUT_DeleteTask((char *)c->main, (void *)a0);
    }
}

void BTLV_INPUT_CursorMoveTaskEnd(void *h)
{
    char *p = *((char **)TCBL_GetTaskUserData(h));
    ((Bits_02204AEC *)(p + 0x68))->n--;
}

void BTLV_INPUT_StartScreenTransition(Main_02204B0C *m, int c)
{
    Obj_02204A70 *o;
    int k;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x24, 1, d_0220AEB0, 0xd8c);
    k = m->mode;
    m->mode = d_0220A38C[k][c - 5];
    m->b0 = 1;
    o->main = m;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_02030DA8(m->owner, BTLV_INPUT_ScreenResetTask, o, 1), (int)((void *)BTLV_INPUT_TaskEndClearBusyBit));
    BTLV_EFFECT_ResetIntroState(2);
    BTLV_EFFECT_StartEffect(d_0220A3E4[k][c - 5]);
}

void BTLV_INPUT_VisibilityTaskMain(void *a, void *arg)
{
    int *b = arg;

    if (BTLV_EFFECT_GetWorkPtr() != 0) {
        BTLV_EFFECT_SetVisibilityMode(b[1]);
        BTLV_INPUT_DeleteTask((char *)b[0], (void *)a);
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
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, plane, brightness);
}

/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204BD4..0x02204C20)
 */
void BTLV_INPUT_WindowOpenTaskMain(void *a0, void *arg)
{
    int *c = arg;

    GXS_SetVisibleWnd(3);
    G2S_SetWnd0InsidePlane(0x1f, c[1] > 1);
    G2S_SetWnd1InsidePlane(0x1f, c[1] == 3);
    G2S_SetWndOutsidePlane(0x1f, 0);
    G2S_SetBlendBrightness(0x10, -8);
    BTLV_INPUT_DeleteTask((void *)c[0], a0);
}

static inline void G2S_BlendNone(void)
{
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, 0, 0);
}

/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204C4C..0x02204C76)
 */
void BTLV_INPUT_WindowCloseTaskMain(void *a0, void *arg)
{
    int *c = arg;

    GXS_SetVisibleWnd(0);
    G2S_SetWnd0InsidePlane(0, 0);
    G2S_SetWnd1InsidePlane(0, 0);
    G2S_SetWndOutsidePlane(0, 0);
    G2S_BlendNone();
    BTLV_INPUT_DeleteTask((void *)c[0], a0);
}

void BTLV_INPUT_GetTextBlockSize(struct StrObj *a, int b, int *outn, int *outq)
{
    int n = func_0201D304(a, b, 0);
    int q = n / 8;
    if (FX_ModS32(n, 8) != 0)
        q++;
    *outn = n;
    *outq = q;
}

#pragma opt_common_subs off

#pragma opt_propagation off

/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of func_020275E4. Left: register allocation. The image keeps q in r6 and
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
 *   Witness gaps once bytes match: func_020275F8, func_020275EC (arm, no caller
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
 *   (q + i formed before the stack-argument stores of both func_0201EFA4
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling BTLV_INPUT_CreateBackActor
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, func_020275EC, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/func_020275EC.c, EXACT).
 */
/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of func_020275E4. Left: register allocation. The image keeps q in r6 and
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
 *   Witness gaps once bytes match: func_020275F8, func_020275EC (arm, no caller
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
 *   (q + i formed before the stack-argument stores of both func_0201EFA4
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling BTLV_INPUT_CreateBackActor
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, func_020275EC, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/func_020275EC.c, EXACT).
 */
void BTLV_INPUT_DrawWazaButtons(Work_v3E30 *p, const Slots *q)
{
    PosTab t1 = d_0220A5B0;
    PosTab t2 = d_0220A5D0;
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

    str1 = STRBUF_Create(0x10, p->heap);
    m0 = func_02045EC0(p->msgdata, 0);
    m1 = func_02045EC0(p->msgdata, 1);
    font = (int)func_0201EC64(p->heap);
    str2 = STRBUF_Create(0x10, p->heap);
    m2 = func_02045EC0(p->msgdata, 2);
    CLACT_SetUnitDrawEnable(p->sys, 0);
    for (i = 0; (i < 4) ? 1 : 0; i++) {
        if (q->id[i] != 0) {
            k = WAZA_TOOL_GetParam(q->id[i], 0);
            file = d_0220A5F0[k];
            p->obj[i] = (struct Obj_02204698 *)CLACT_CreateActor(p->sys, p->res[i], p->r1f0, p->r1f4, d_0220A392, 1, p->heap);
            CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(p->obj[i]), (const struct Vec2 *)(&d_0220A3C4[i]), (int)1);
            heap = (p->heap & 0x7fff) | 0x8000;
            arc = func_020275E4();
            chr = ARC_UTIL_LoadScreenDataFromArchive(arc, func_020275F8((u8)k), 0, (u32)(&cd), heap);
            CLACT_SetActorPaletteOffset(p->obj[i], func_020275EC((u8)k), 1);
            CLACT_GetActorImageProxy(p->obj[i], (struct Struct36 *)(&buf));
            vram = VRAM_BASE;
            MIi_CpuCopy16(((struct Obj21781 *)cd)->f14, (void *)(vram + buf.w[2]), 0x100);
            func_020307B0(chr);
            GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
            GF_FONT_SetTextColor(1, 2, 0);
            func_0201EF34((struct WordSet *)font, 0, q->id[i]);
            func_0201F250((struct WordSet *)font, str1, m0);
            BTLV_INPUT_GetTextBlockSize(str1, (int)p->fnt, &w, &h);
            PRINTSYS_Print(p->win, d_0220A4AC[i].x - w / 2, d_0220A4AC[i].y, str1, p->fnt);
            func_0201EFA4(font, 0, q->a[i], 2, 1, 1);
            func_0201EFA4(font, 1, q->b[i], 2, 1, 1);
            func_0201F250((struct WordSet *)font, str2, m2);
            col = BTLV_INPUT_GetNeighbourIndex(q->a[i], q->b[i]);
            cb = (u8)(col & 0x1f);
            cg = (u8)((col >> 5) & 0x1f);
            cr = (u8)((col >> 10) & 0x1f);
            GF_FONT_SetTextColor(cr, cg, cb);
            PRINTSYS_Print(p->win, t1.v[i].x, t1.v[i].y, m1, p->fnt);
            BTLV_INPUT_GetTextBlockSize(str2, (int)p->fnt, &w, &h);
            PRINTSYS_Print(p->win, t2.v[i].x - w / 2, t2.v[i].y, str2, p->fnt);
            GF_FONT_SetTextColor(c[2], c[1], c[0]);
            p->f25a[i] = q->a[i] != 0;
            p->f262[i] = q->id[i] != 0;
        } else {
            file = 0xc1;
        }
        heap = (p->heap & 0x7fff) | 0x8000;
        pltt = ARC_UTIL_LoadPaletteBlockFromArchive(0xb, file, (u32)(&pd), heap);
        PALANM_CopyToSlot(p->bg, ((struct Obj21782 *)pd)->fC, (int)1, (u16)(i * 16 + 0x90), 0x20);
        func_020307B0(pltt);
    }
    p->f25a[i] = 1;
    if (p->mode == 2) {
        p->f25a[i + 1] = 1;
    }
    func_0201ED04((struct WordSet *)font);
    STRBUF_Delete(str1);
    STRBUF_Delete(m1);
    STRBUF_Delete(m0);
    STRBUF_Delete(m2);
    STRBUF_Delete(str2);
}

#pragma opt_propagation reset

#pragma opt_common_subs reset

void BTLV_INPUT_DrawTargetButtons(char *s, Out *out, const Info_v3E30 *p)
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
    Res_02204C98 *res;
    u8 c[3];

    n = (((struct Obj01909 *)s)->f50 == 2) ? 6 : 4;
    k = (((struct Obj01909 *)s)->f50 == 2) ? 1 : 0;
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    v = STRBUF_Create(12, (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    h = (int)func_0201EC64((u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    GF_FONT_SetTextColor(1, 2, 0);
    for (i = 0; i < n; i++) {
        if (p->e[i].show != 0) {
            w = func_02045EC0(((struct Obj01909 *)s)->f5C, p->e[i].kind + 3);
            func_0201EEF4((void *)h, 0, p->e[i].text);
            func_0201F250((struct WordSet *)h, v, w);
            BTLV_INPUT_GetTextBlockSize((struct StrObj *)v, ((struct Obj01909 *)s)->f224, &ww, &hh);
            PRINTSYS_Print((void *)(((struct Obj01909 *)s)->f22C), d_0220A7FC[k][i][0] - ww / 2, d_0220A7FC[k][i][1], v, (void *)(((struct Obj01909 *)s)->f224));
            STRBUF_Delete(w);
        }
        (s + i)[0x25a] = p->e[i].flag;
    }
    (s + i)[0x25a] = 1;
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    STRBUF_Delete(v);
    idx = (p->b48 - 2) / 2;
    ((Bits6C *)(s + 0x6c))->x = p->b49;
    out->fc = d_0220A94C[k][idx][p->b49];
    m = 3;
    if (((struct Obj01909 *)s)->f50 != 2)
        m = 2;
    for (i = 0; i < m; i++) {
        r = ARC_UTIL_LoadPaletteBlockFromArchive(11, 0xd3, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
    for (m *= 2; i < m; i++) {
        r = ARC_UTIL_LoadPaletteBlockFromArchive(11, 0xd4, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
}

void BTLV_INPUT_DrawMessageText(Main_v3E30 *m, const int *c)
{
    int w;
    int h;

    GF_FONT_SetTextColor(1, 2, 0);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)c[0], m->o224, &w, &h);
    PRINTSYS_Print((void *)m->o22c, 0x80 - w / 2, 0x10, (void *)c[0], (void *)m->o224);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)c[1], m->o224, &w, &h);
    PRINTSYS_Print((void *)m->o22c, 0x80 - w / 2, 0x40, (void *)c[1], (void *)m->o224);
    m->b25a = 1;
    m->b25b = 1;
    func_020498F4((void *)m->f48, 0x6b, 5, 0, 0, 0, m->h240);
}

/*
 * lever: 022053DE reserves 0x28 bytes: 16 outgoing argument bytes plus
 *   a 24-byte local. Only its first 16 bytes are read/initialized here;
 *   pad10 preserves the observed allocation without naming unknown fields.
 *   Palette field reads retain the A386/A387 pools as one extern plus addend.
 */
void BTLV_INPUT_InitButtonState(char *m)
{
    int i;
    Buffer buf;
    for (i = 0; i < 4; i++) {
        buf.value[i] = 0;
        buf.a[i] = 0;
        buf.b[i] = 0;
    }
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)OBJECT); i++)
        buf.value[i] = func_021D5528(OBJECT, i, &buf.a[i], &buf.b[i]);
    BTLV_INPUT_DrawWazaButtons((Work_v3E30 *)((struct Work_02201B20 *)m), (const Slots *)((const struct Slots *)(&buf)));
    ((struct Obj00168 *)m)->f25F = d_0220A386[INDEX].first;
    ((struct Obj00168 *)m)->f260 = d_0220A386[INDEX].second;
    ((struct Obj00168 *)m)->f220 = 1;
    for (i = 0; i < 4; i++) {
        if (*(int *)(m + INDEX * 16 + i * 4 + 0x2b0) == 1)
            ((struct Obj00168 *)m)->f220 = 0;
    }
    if (BTL_POKEPARAM_IsFainted(OBJECT)) {
        for (i = 0; i < 4; i++)
            *(u8 *)(m + i + 0x25a) = 0;
        ((struct Obj00168 *)m)->f220 = 0;
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        return;
    }
    if (((struct Obj00168 *)m)->f220 == 1) {
        ((struct Obj00168 *)m)->f25A = 1;
        BTLV_INPUT_CreateBackActor(m);
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        return;
    }
    PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 0, 0, 0, ((struct Obj00168 *)m)->f0);
    PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 0, 0, 0, ((struct Obj00168 *)m)->f0);
}

/*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 */
void BTLV_INPUT_DrawSelectScreenText(char *s, const int *b)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = (int)func_0201EC64(((struct Obj02440 *)s)->f240);
    v = STRBUF_Create(8, ((struct Obj02440 *)s)->f240);
    w = func_02045EC0(((struct Obj02440 *)s)->f5C, 6);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(9, 10, 0);
    func_0201EFA4(h, 0, b[2], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x8c, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    if (b[0] != b[1])
        GF_FONT_SetTextColor(7, 8, 0);
    func_0201EFA4(h, 0, b[1], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x60, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    GF_FONT_SetTextColor(1, 2, 0);
    extra = func_02045EC0(((struct Obj02440 *)s)->f5C, 7);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x7c, 8, extra, (void *)(((struct Obj02440 *)s)->f224));
    STRBUF_Delete(extra);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
    PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj02440 *)s)->f64), (u16 *)(PALANM_GetDefaultWork((char *)BTLV_EFFECT_GetPalanm(), 1) + 0x40), 1, 0x70, 0x20);
}

void BTLV_INPUT_ClearButtonState(Main_022053DC *m)
{
    int i;
    int j;

    m->f6c &= ~2;
    for (i = 0; i < 8; i++) {
        m->b25a[i] = 0;
    }
    for (j = 0; j < 4; j++) {
        m->b262[j] = 0;
    }
    BMP_Clear((struct CharBuf *)m->o22c, 0);
    BMP_WIN_TransferChars((struct Descriptor *)m->o228);
    BMP_Clear((struct CharBuf *)m->o234, 0);
    BMP_WIN_TransferChars((struct Descriptor *)m->o230);
    BTLV_INPUT_DeleteWazaActors((W_02205F64 *)((Main_022053DC *)m));
    BTLV_INPUT_DeleteBackActor((char *)m);
    BTLV_INPUT_DeleteStatusIcons((W_022053DC *)m);
    func_02041300(4, 0, 0x20, 2, 0x20, 0x20, 0);
    PALANM_RequestFadeOverwrite((void *)m->f64, 2, 0x3e00, 0, 0, 0, 0, m->owner);
    PALANM_RequestFadeOverwrite((void *)m->f64, 8, 0x700, 0, 0, 0, 0, m->owner);
}

int BTLV_INPUT_GetNeighbourIndex(int a, int b)
{
    if (a == 0) {
        return 0x1d00;
    }
    if (b == a) {
        return 0x440;
    }
    if (b <= 2) {
        if (a == 1) {
            return 0x14c0;
        }
    } else if (b <= 7) {
        switch (a) {
        case 1:
            return 0x14c0;
        case 2:
            return 0xc80;
        }
    } else {
        if (a <= b / 4) {
            return 0x14c0;
        }
        if (a <= b / 2) {
            return 0xc80;
        }
    }
    return 0x440;
}

void BTLV_INPUT_CreateActionButtons(Main_022057CC *m, Info_v53DC *q)
{
    int n;
    void *arc;
    int i;
    int k;
    void **r;
    const Point_022053DC *pt;
    s16_022057CC x, y;

    n = (m->mode == 3) ? 2 : m->mode + 1;
    k = 0;
    if (m->mode == 0 || m->mode == 3)
        return;
    arc = func_020490F4(7, (u16)((m->heap & 0x7fff) | 0x8000));
    m->h1c0 = CLACT_RegisterCellAnim(arc, func_0201BC78(), func_0201BCEC(), m->heap);
    m->h1bc = CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 1, 0x160, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h1bc, 1) >> 1), 0x60);
    *(volatile u16 *)0x04001040 = 0x100;
    *(volatile u16 *)0x04001044 = 0;
    *(volatile u16 *)0x04001042 = 0x100;
    *(volatile u16 *)0x04001046 = 0;
    if (n > 1) {
        r = func_02030734((u16)((m->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x1145);
        r[0] = m;
        r[1] = (void *)n;
        BTLV_INPUT_RegisterTask((char *)m, (int)func_020056A0(BTLV_INPUT_WindowOpenTaskMain, r, 0), 0);
    }
    for (i = 0; i < n; i++) {
        if (q->species[i] != 0) {
            m->h1b0[i] = CLACT_RegisterCharacter(arc, POKE_TOOL_CalcGraphicIndex(q->species[i], q->form[i], q->gender[i], 0), 0, 1, m->heap);
            m->h1c8[i].obj = CLACT_CreateActor((void *)m->h1c4, m->h1b0[i], m->h1bc, m->h1c0, d_0220A392, 1, m->heap);
            CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(m->h1c8[i].obj), (const struct Vec2 *)(&d_0220A50C[m->mode][i]), 1);
            CLACT_SetActorAutoAnim(m->h1c8[i].obj, 1);
            if (q->sel == i) {
                CLACT_SetActorAnimSeq(m->h1c8[i].obj, 1);
            } else if (k == 0) {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001040 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001044 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
                k++;
            } else {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001042 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001046 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
            }
            CLACT_SetActorPaletteOffset(m->h1c8[i].obj, POKE_TOOL_CalcIconPalette(q->species[i], q->form[i], q->gender[i], 0), 0);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * lever: entry reads use the indexed aggregate; the zero store uses its raw
 * offset. This avoids retaining a common entry pointer across both frees.
 */
void BTLV_INPUT_DeleteActionButtonActors(char *p)
{
    int i;
    int empty = 1;
    int *ctx;
    for (i = 0; i < 3; i++) {
        if (((Work_02201B20 *)p)->entries[i].entry != 0) {
            CLACT_DeleteActor(((Work_02201B20 *)p)->entries[i].entry);
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x1b0));
            *(void **)(p + i * 8 + 0x1c8) = 0;
            *(int *)(p + i * 4 + 0x1b0) = -1;
            empty = 0;
        }
    }
    if (((struct Obj01049 *)p)->f1C0 != -1) {
        CLACT_ReleaseCellAnim(((struct Obj01049 *)p)->f1C0);
        ((struct Obj01049 *)p)->f1C0 = -1;
    }
    if (((struct Obj01049 *)p)->f1BC != -1) {
        CLACT_ReleasePalette(((struct Obj01049 *)p)->f1BC);
        ((struct Obj01049 *)p)->f1BC = -1;
    }
    if (!empty) {
        ctx = func_02030734((u16)((((struct Obj01049 *)p)->f240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x11b2);
        ctx[0] = (int)p;
        BTLV_INPUT_RegisterTask(p, (int)func_020056A0(BTLV_INPUT_WindowCloseTaskMain, ctx, 0), 0);
    }
}

void BTLV_INPUT_SetActionUnitVisible(char *p, int a)
{
    CLACT_SetUnitDrawEnable(((struct Obj21785 *)p)->f1C4, a);
}

void BTLV_INPUT_CreateStatusIcons(char *p, int n)
{
    Five a = d_0220A558;
    Five b = d_0220A56C;
    Five c = d_0220A544;
    Point_022053DC v;
    int index;
    void **q;
    if (n == 0) return;
    ((struct Obj00896 *)p)->f210 = CLACT_CreateActor((void *)((struct Obj00896 *)p)->f20C, ((struct Obj00896 *)p)->f104, ((struct Obj00896 *)p)->f108, ((struct Obj00896 *)p)->f10C, d_0220A392, 1, ((struct Obj00896 *)p)->f240);
    index = n - 1;
    v.x = 0x130 + b.v[index];
    v.y = 0x20 + c.v[index];
    CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(((struct Obj00896 *)p)->f210), (const struct Vec2 *)(&v.x), (int)1);
    CLACT_SetActorAutoAnim(((struct Obj00896 *)p)->f210, 1);
    n += 14;
    CLACT_SetActorAnimSeq(((struct Obj00896 *)p)->f210, n);
    ((struct Obj00896 *)p)->f214 = CLACT_CreateActor((void *)((struct Obj00896 *)p)->f20C, ((struct Obj00896 *)p)->f104, ((struct Obj00896 *)p)->f108, ((struct Obj00896 *)p)->f10C, d_0220A392, 1, ((struct Obj00896 *)p)->f240);
    v.x = 0x130;
    v.y = 0x20;
    CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(((struct Obj00896 *)p)->f214), (const struct Vec2 *)(&v.x), (int)1);
    CLACT_SetActorAutoAnim(((struct Obj00896 *)p)->f214, 1);
    CLACT_SetActorAnimSeq(((struct Obj00896 *)p)->f214, 14);
    CLACT_SetActorPaletteOffset(((struct Obj00896 *)p)->f214, (u8)a.v[index], 0);
    q = func_02030734((u16)((((struct Obj00896 *)p)->f240 & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x11ec);
    q[0] = p;
    BTLV_INPUT_RegisterTask(p, (int)func_02030DA8((void *)((struct Obj00896 *)p)->f0, BTLV_INPUT_CursorMoveTaskMain, q, 0), (int)((void *)BTLV_INPUT_CursorMoveTaskEnd));
    ((Bits_022053DC *)(p + 0x68))->count++;
}

void BTLV_INPUT_DeleteStatusIcons(W_022053DC *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}

void BTLV_INPUT_CreateWazaCursorActors(char *p, int mode)
{
    Slot *slots;
    Point_022053DC pos;
    int add;
    int step;
    char *row;
    int i;

    if (mode == 1) {
        slots = (Slot *)(p + 0x14c);
        pos.x = 0x94;
        pos.y = 0x30;
        step = -8;
        add = 4;
    } else {
        slots = (Slot *)(p + 0x11c);
        pos.x = 0x58;
        pos.y = 0x88;
        step = 0x10;
        add = 0;
    }
    i = 0;
    row = p + mode * 0x48;
    for (; i < 6; i++) {
        slots[i].h = CLACT_CreateActor((void *)((struct Obj06327 *)p)->f118, ((struct Obj06327 *)p)->f104, ((struct Obj06327 *)p)->f108, ((struct Obj06327 *)p)->f10C, d_0220A392, 1, ((struct Obj06327 *)p)->f240);
        CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)slots[i].h, (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorAutoAnim(slots[i].h, 1);
        CLACT_SetActorAnimSeq(slots[i].h, add + *(u8 *)(row + i * 12 + 0x75));
        pos.x += (s16_022057CC)step;
    }
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x11c;` before `off = 0x14c;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void BTLV_INPUT_DeleteWazaCursorActors(char *o)
{
    int i;
    int j;
    int off;
    char *p;

    i = 0;
    off = 0x14c;
    for (; i < 2; i++) {
        if (i != 0) {
            p = o + off;
        } else {
            p = o + 0x47 * 4;
        }
        for (j = 0; j < 6; j++) {
            if (*(void **)(p + j * 8) != 0) {
                CLACT_DeleteActor(*(void **)(p + j * 8));
                *(void **)(p + j * 8) = 0;
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
void BTLV_INPUT_CreateTargetActors(char *m)
{
    Q_v53DC q = d_0220A580;
    int o0;
    int o1;
    int o2;
    int o3;
    int o4;
    int o5;
    char *p;
    int j;

    o0 = 0x17c;
    o1 = 0x108;
    o2 = 0x114;
    o3 = 0x180;
    o4 = 0x180;
    o5 = 0x180;
    for (j = 0; j < 6; j++) {
        p = m + j * 8;
        *(u32 *)(p + o3) = (u32)CLACT_CreateActor((void *)*(u32 *)(m + o0), ((struct Obj00083 *)m)->f110, *(u32 *)(m + o1),
                                         *(u32 *)(m + o2), d_0220A392, 1, ((struct Obj00083 *)m)->f240);
        CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p + o4), 1);
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + o5)), q.v[j]);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj21787 *)p)->f180, 0);
    }
}

void BTLV_INPUT_DeleteTargetActors(W_02205F40 *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}

void BTLV_INPUT_DeleteWazaActors(W_02205F64 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}

void BTLV_INPUT_CreateBackActor(char *p)
{
    void *str;
    void *msg;
    int font;
    void *bmp;
    Point_02205F40 pos;
    int w;
    int h;
    u8 c[3];
    Struct36 buf;
    char *pixels;
    int i;
    enum { VRAM_BASE = 0x06600000 } vram;

    ((struct Obj01384 *)p)->f21C = CLACT_CreateActor((void *)((struct Obj01384 *)p)->f218, ((struct Obj01384 *)p)->f104, ((struct Obj01384 *)p)->f108, ((struct Obj01384 *)p)->f10C, d_0220A392, 1, ((struct Obj01384 *)p)->f240);
    pos.x = 0x80;
    pos.y = 0x50;
    CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(((struct Obj01384 *)p)->f21C), (const struct Vec2 *)(&pos), 1);
    CLACT_SetActorAutoAnim(((struct Obj01384 *)p)->f21C, 1);
    CLACT_SetActorAnimSeq(((struct Obj01384 *)p)->f21C, 0x14);
    str = STRBUF_Create(0x10, ((struct Obj01384 *)p)->f240);
    msg = func_02045EC0(((struct Obj01384 *)p)->f5C, 0);
    font = (int)func_0201EC64(((struct Obj01384 *)p)->f240);
    bmp = BMP_Create(0xe, 4, 0x20, ((struct Obj01384 *)p)->f240);
    BMP_Clear(bmp, 0);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(0xe, 0xa, 0);
    func_0201EF34((struct WordSet *)font, 0, 0xa5);
    func_0201F250((struct WordSet *)font, str, msg);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)str, (int)(((struct Obj01384 *)p)->f224), &w, &h);
    PRINTSYS_Print(bmp, 0x38 - w / 2, 8, str, ((struct Obj01384 *)p)->f224);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(((struct Obj01384 *)p)->f21C, (struct Struct36 *)(&buf));
    vram = VRAM_BASE;
    for (i = 0; i < 4; i++) {
        MIi_CpuCopy16(pixels + i * 0x1c0, (void *)(vram + (i * 8 + 0xcd) * 32 + buf.w[2]), 0x100);
        MIi_CpuCopy16(pixels + (i * 0x1c0 + 0x100), (void *)(vram + (i * 4 + 0xed) * 32 + buf.w[2]), 0x80);
        MIi_CpuCopy16(pixels + (i * 0x1c0 + 0x180), (void *)(vram + (i * 2 + 0xfd) * 32 + buf.w[2]), 0x40);
    }
    STRBUF_Delete(str);
    STRBUF_Delete(msg);
    func_0201ED04((struct WordSet *)font);
    BMP_Delete(bmp);
}

void BTLV_INPUT_DeleteBackActor(char *p)
{
    if (((struct Obj10158 *)p)->f21C != 0) {
        CLACT_DeleteActor(((struct Obj10158 *)p)->f21C);
        ((struct Obj10158 *)p)->f21C = 0;
    }
}

/*
 * `const Ctx_v53DC *c` lets the scheduler hoist the reload of c above the
 * bitfield store in the ret != -1 arm.
 */
/*
 * `const Ctx *c` lets the scheduler hoist the reload of c above the
 * bitfield store in the ret != -1 arm.
 */
int BTLV_INPUT_ProcessButtonSelection(W_02206140 *p, const Ctx_v53DC *c, s8 (*rows)[12], u8 *list, int ret, int arg6)
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
    if (p->b0 == 0)
        keys &= ~2;
    if (p->redraw) {
        p->redraw = 0;
        BTLV_INPUT_UpdateWazaRow((W_02206950 *)p);
        BTLV_INPUT_UpdateButtonActors((W_022064CC *)p, (u8 (*)[4])c->tab, rows);
        CLACT_SetUnitDrawEnable(p->f17c, 1);
    }
    v = -1;
    if (ret != v) {
        *p->f274 = 0;
        p->cur = 0;
        p->prev = 0xF;
        BTLV_INPUT_UpdateButtonActors((W_022064CC *)p, (u8 (*)[4])c->tab, rows);
        return ret;
    }
    if (keys == 0)
        goto end;
    if (*p->f274 != 0) {
        v = -128;
        row = rows[p->cur];
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
                if (p->b4 == 1)
                    v = (s8)-k;
            } else {
                v = k;
            }
            break;
        }
        if (keys == 1) {
            ret = row[10];
            if (ret < 4 && (cont & 0x200) && p->f58 == 5 && (arg6 == 1 || p->f220 == 1))
                goto draw;
            if (ret < 4 && (cont & 0x200) && p->f58 == 2 && arg6 == 1)
                goto draw;
            if (p->f25a[ret] == 1) {
                if (BTLV_INPUT_IsWazaSelectable((char *)p, (char *)c, ret) == 0)
                    BTLV_INPUT_PlaySelectSe((char *)p);
                else
                    BTLV_INPUT_PlayCursorSe((char *)p);
                done = 1;
            } else if (ret < 4 && (cont & 0x200) && p->f58 == 2 && p->f262[ret] == 1) {
                BTLV_INPUT_PlaySelectSe((char *)p);
            }
        } else if (v != -128) {
            BTLV_INPUT_PlayCancelSe((char *)p);
            if (v < 0) {
                if (-v != p->prev && p->prev != 0xF)
                    v = (s8)p->prev;
                else
                    v *= -1;
            } else if (v & 0x40) {
                i = 0;
                v &= ~0x40;
                for (; list[i] != 0xff; i++) {
                    if (p->prev == list[i]) {
                        v = (s8)p->prev;
                        break;
                    }
                }
            }
            p->prev = p->cur;
            p->cur = v;
            if (keys == 2) {
                if (v != 0xF)
                    BTLV_INPUT_PlayCursorSe((char *)p);
                ret = v;
                done = 1;
            }
        }
    } else if (keys & 0xcf3) {
        *p->f274 = 1;
        BTLV_INPUT_UpdateWazaRow((W_02206950 *)p);
        BTLV_INPUT_PlayCancelSe((char *)p);
    }
draw:
    BTLV_INPUT_UpdateButtonActors((W_022064CC *)p, (u8 (*)[4])c->tab, rows);
end:
    if (done == 1) {
        switch (p->f58) {
        case 2:
            if (BTLV_INPUT_IsWazaSelectable((char *)p, (char *)c, p->cur) == 0)
                p->f266[p->f27c] = p->f26c[p->cur];
        case 1:
        case 5:
            if (BTLV_INPUT_IsWazaSelectable((char *)p, (char *)c, p->cur) == 0)
                p->tbl[p->f27c][p->f58] = p->cur;
            p->b1 = 1;
            break;
        case 3:
            if (BTLV_INPUT_IsWazaSelectable((char *)p, (char *)c, ret) == 0)
                p->tbl[p->f27c][p->f58] = p->cur | (p->tbl[p->f27c][2] << 4);
            p->b1 = 1;
            break;
        }
        p->cur = 0;
        p->prev = 0xF;
        p->redraw = 1;
        CLACT_SetUnitDrawEnable(p->f17c, 0);
    }
    return ret;
}

int BTLV_INPUT_ProcessKeyRepeat(char *p)
{
    u32 k = KEY_GetRepeat();

    if (k & 2) {
        BTLV_INPUT_PlayCursorSe(p);
        return 2;
    }
    if (k & 0x20) {
        BTLV_INPUT_PlaySelectSe(p);
        return 0;
    }
    if (k & 0x10) {
        BTLV_INPUT_PlaySelectSe(p);
        return 1;
    }
    return -1;
}

/*
 * The table parameter is `__restrict`: with it the scheduler hoists the y
 * load above the x store in cases 2..5 (e[1] vs pos.x) but not in cases 0/1
 * (e[0] vs pos.x, same offset), which is the original's mixed schedule.
 */
void BTLV_INPUT_UpdateButtonActors(W_022064CC *p, u8 (* __restrict tab)[4], s8 (*rows)[12])
{
    Point_022064CC pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[p->sel][i];
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
            CLACT_SetActorDrawEnable(p->slots[i].h, *p->f274);
            CLACT_AddActorSurfacePos((struct Obj_02201DA0 *)(p->slots[i].h), (const struct Vec2 *)(&pos), 1);
        } else {
            CLACT_SetActorDrawEnable(p->slots[i].h, 0);
        }
    }
}

int BTLV_INPUT_SetSelection(char *s, int a, int b)
{
    Ctx_022064CC *c;
    int flag;

    if (b < 0)
        return a;
    if ((KEY_GetCont() & 0x200) && a < 4 && (((struct Obj00823 *)s)->f58 == 2 || ((struct Obj00823 *)s)->f58 == 5))
        ((struct Obj00823 *)s)->f70 = a | 0x8000;
    else
        ((struct Obj00823 *)s)->f70 = a;
    c = func_02030734((u16)((((struct Obj00823 *)s)->f240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0x1440);
    flag = 0;
    if ((0x10000 & b) == 0)
        flag = 1;
    ((Top *)(s + 0x68))->top = flag;
    c->s = s;
    c->f4 = 0;
    c->f8 = (u16)b;
    if (((struct Obj00823 *)s)->f220 == 1 && c->f8 == 0)
        c->fc = 1;
    else
        c->fc = 0;
    BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(((struct Obj00823 *)s)->f0, BTLV_INPUT_ButtonFlashTaskMain, c, 0), (int)((void *)BTLV_INPUT_ButtonFlashTaskEnd));
    return -1;
}

void BTLV_INPUT_ButtonFlashTaskMain(void *task, void *arg)
{
    Ctx_0220663C *c = arg;

    switch (c->state) {
    case 0:
        if (c->flag == 1)
            PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21789 *)(c->p))->f64, 8, 2, 0, 0, 8, 0x7fff, *(void **)c->p);
        else
            PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21791 *)(c->p))->f64, 2, c->colour, 0, 0, 8, 0x7fff, *(void **)c->p);
        c->state++;
        break;
    case 1:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj21793 *)(c->p))->f64) == 0) {
            if (c->flag == 1)
                PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21794 *)(c->p))->f64, 8, 2, 0, 8, 0, 0x7fff, *(void **)c->p);
            else
                PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21796 *)(c->p))->f64, 2, c->colour, 0, 8, 0, 0x7fff, *(void **)c->p);
            c->state++;
        }
        break;
    case 2:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj21798 *)(c->p))->f64) == 0)
            BTLV_INPUT_DeleteTask(c->p, task);
        break;
    }
}

void BTLV_INPUT_ButtonFlashTaskEnd(void *h)
{
    (*(W_02206710 * *)TCBL_GetTaskUserData((struct S02030EE8 *)h))->f68 &= 0x7fffffff;
}

void BTLV_INPUT_DrawRunButtonText(char *s, char *b)
{
    int h;
    void *v;
    void *w;
    int v18;
    int v14;
    u8 c[3];

    if (BTLV_EFFECT_IsRecordEnabledInComm() == 0)
        return;
    h = (int)func_0201EC64(((struct Obj05249 *)s)->f240);
    v = STRBUF_Create(6, ((struct Obj05249 *)s)->f240);
    w = func_02045EC0(((struct Obj05249 *)s)->f5C, 8);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(1, 2, 0);
    func_0201EFA4((u32)((struct WordSet *)h), 0, ((struct Obj21799 *)b)->fC4, 2, 0, 1);
    func_0201F250((struct WordSet *)h, v, w);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)v, ((struct Obj05249 *)s)->f224, &v18, &v14);
    PRINTSYS_Print((void *)(((struct Obj05249 *)s)->f234), 12 - v18 / 2, 0, v, (void *)(((struct Obj05249 *)s)->f224));
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
}

void BTLV_INPUT_PrepareCommandSelect(char *p)
{
    BTLV_EFFECT_ResetIntroState(2);
    BTLV_EFFECT_StartCameraMove((u32)(((struct Obj21800 *)p)->f278), 1, 10, 0, 8);
}

void BTLV_INPUT_ClearSlotEvents(char *p)
{
    int a = BTLV_GAUGE_TakeSlotEvent((char *)BTLV_EFFECT_GetGauge(), ((struct Obj10159 *)p)->f278);
    int b = BTLV_MCSS_TakeSpriteRefreshedFlag((BtlvMcssWork *)((void *)BTLV_EFFECT_GetMcss()), ((struct Obj10159 *)p)->f278);
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            *(char *)(p + ((struct Obj10159 *)p)->f27C * 8 + i + 0x242) = 0;
    }
}

void BTLV_INPUT_RegisterTask(char *p, int a, int b)
{
    int i = BTLV_INPUT_AllocTaskSlot(p);

    *(int *)(p + i * 4 + 8) = a;
    *(int *)(p + i * 4 + 0x28) = b;
}

/*
 * lane S13 leaf of BTLV_INPUT_DeleteTask
 */
int BTLV_INPUT_FindTask(char *p, int v)
{
    int i;
    int x;

    for (i = 0; i < 8; i++) {
        x = *(int *)(p + i * 4 + 8);
        if (x == v)
            break;
    }
    return i;
}

void BTLV_INPUT_DeleteTask(char *p, void *q)
{
    int i = BTLV_INPUT_FindTask(p, (int)q);
    int off;

    if (q != 0) {
        void *r = (void *)(W_02206710 * *)TCBL_GetTaskUserData((struct S02030EE8 *)q);
        char *t = p + 0x28;
        void (*cb)(void *);

        off = i * 4;
        cb = *(void (**)(void *))(t + off);
        if (cb != 0)
            cb(q);
        if (r != 0)
            func_020307B0(r);
        func_02030EAC(q);
        *(int *)(p + off + 8) = 0;
        *(int *)(t + off) = 0;
    }
}

int BTLV_INPUT_AllocTaskSlot(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (*(int *)(p + 8 + i * 4) == 0)
            break;
    }
    if (i == 8) {
        BTLV_INPUT_DeleteTask(p, (void *)(((struct Obj18616 *)p)->f8));
        i = 0;
    }
    return i;
}

void BTLV_INPUT_DeleteAllTasks(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        int v = *(int *)(p + 8 + i * 4);

        if (v != 0)
            BTLV_INPUT_DeleteTask(p, (void *)v);
    }
}

int BTLV_INPUT_IsWazaSelectable(char *p, char *q, int i)
{
    int r;

    if (!((Bf_022064CC *)(p + 0x68))->b4 || ((struct Obj00823 *)p)->f58 != 1)
        return 1 & ((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i];
    r = (((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i] & 2) >> 1;
    if (r == 1)
        *(char *)(p + ((struct Obj00823 *)p)->f27C * 8 + 0x242 + ((struct Obj00823 *)p)->f58) = 0;
    return r;
}

void BTLV_INPUT_UpdateWazaRow(W_02206950 *p)
{
    u8 b;

    switch (p->f58) {
    case 2:
        if (p->a266[p->k] != p->a26c[p->row[p->k][p->f58]])
            p->row[p->k][3] = 0;
    case 1:
    case 5:
        p->sel = p->row[p->k][p->f58];
        break;
    case 3:
        b = p->row[p->k][p->f58];
        if (((b & 0xf0) >> 4) == p->row[p->k][2])
            p->sel = b;
        else
            p->sel = 0;
        break;
    default:
        p->sel = 0;
        break;
    }
}

void BTLV_INPUT_BlendWindowPalette(char *p)
{
    u16 buf[16];

    if ((int)BTL_MAIN_GetCompetitor((void ***)BTLV_EFFECT_GetBattleMain()) != 4 && BTLV_EFFECT_IsRecordAllowed() == 0) {
        PALANM_BlendColors((u16 *)(p + 0x284), buf, 0x10, 8, 0);
        PALANM_CopyToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), buf, 1, 0x20, 0x20);
    }
}

void BTLV_INPUT_RestoreWindowPalette(char *p)
{
    if (((struct Obj21803 *)p)->f23C == 1)
        PALANM_CopyToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), (u16 *)(p + 0x284), 1, 0x20, 0x20);
}

int BTLV_INPUT_GetMessageBoxMode(char *p)
{
    if (!((Bf_022064CC *)(p + 0x68))->b4) {
        if (((struct Obj06328 *)p)->f50 == 2) {
            if (BTLV_EFFECT_GetVisibilityMode() == 1) {
                if (((struct Obj06328 *)p)->f278 == 4)
                    return 0x65;
                return 0x5f;
            }
            if (((struct Obj06328 *)p)->f278 == 4)
                return 0x5d;
            return 0x5e;
        }
        if (BTLV_EFFECT_GetVisibilityMode() == 1)
            return 0x65;
        return 0x5d;
    }
    if (((struct Obj06328 *)p)->f50 == 2 && ((struct Obj06328 *)p)->f278 != 4) {
        if (BTLV_EFFECT_GetVisibilityMode() == 1)
            return 0x67;
        return 0x61;
    }
    if (BTLV_EFFECT_GetVisibilityMode() == 1)
        return 0x66;
    return 0x60;
}

void BTLV_INPUT_PlayConfirmSe(char *p)
{
    if (((struct Obj13619 *)p)->f54 != 3 || ((struct Obj13619 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x555);
}

void BTLV_INPUT_PlayCancelSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x548);
}

/*
 * lane S13 leaf of BTLV_INPUT_ProcessKeyRepeat
 */
void BTLV_INPUT_PlaySelectSe(char *p)
{
    if (((struct Obj00823 *)p)->f58 != 6) {
        if (((struct Obj00823 *)p)->f54 != 3) {
            GFL_USE_PlaySeDefaultVolume(0x54d);
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x54c);
    }
}

/*
 * lane S13 leaf of BTLV_INPUT_UpdateButtonActors-area callers (BTLV_INPUT_ProcessKeyRepeat)
 */
void BTLV_INPUT_PlayCursorSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x552);
}

void BTLV_INPUT_PlayPageSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x579);
}

void BTLV_INPUT_PlayOpenSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x54d);
}

void BTLV_INPUT_PlayBackSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x557);
}
