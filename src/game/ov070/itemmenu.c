/*
 * file:     itemmenu.c
 * unit:     yes
 * function: func_021B6100, func_021B6120, ITEMMENU_RedrawList, ITEMMENU_GetSlot, ITEMMENU_GetSellTotal, ITEMMENU_GetCursorIndex, ITEMMENU_GetItemCount, ITEMMENU_RegisterItemName, ITEMMENU_RegisterItemNameCounted, ITEMMENU_SwapSlots, ITEMMENU_MoveSlot, ITEMMENU_SwitchPocketCursor, ITEMMENU_MoveCursorDown, ITEMMENU_MoveCursorUp, ITEMMENU_HandleScrollbarTouch, ITEMMENU_HandleMoveModeKeys, ITEMMENU_HandleListKeys, ITEMMENU_HandleListTouch, ITEMMENU_IsBackButtonTouched, ITEMMENU_TaskFinishClose, ITEMMENU_TaskListInput, ITEMMENU_IsRepelItem, ITEMMENU_GetFieldUseKind, ITEMMENU_UseRepel, ITEMMENU_TaskWaitMessage, ITEMMENU_ShowKeyItemRefusal, ITEMMENU_ShowMessageThenWait, ITEMMENU_TryStartUse, ITEMMENU_TryStartGive, ITEMMENU_TryStartRegister, ITEMMENU_TryStartCheck, ITEMMENU_TryStartToss, ITEMMENU_TryStartSort, ITEMMENU_TryStartPlant, ITEMMENU_TryStartSell, ITEMMENU_FindUseRange, ITEMMENU_HandleActionMenuChoice, ITEMMENU_TaskSelectItem, ITEMMENU_TaskBagMain, ITEMMENU_TaskActionMenuInput, ITEMMENU_TaskOpenActionMenu, ITEMMENU_TaskRegisterResultMessage, ITEMMENU_TaskStartRegisterResult, ITEMMENU_TaskUseNoticeMessage, ITEMMENU_TaskReturnToListAfterMessage, ITEMMENU_TaskBeginReturnToList, ITEMMENU_TaskTossConfirmInput, ITEMMENU_TaskOpenTossConfirm, ITEMMENU_TaskTossAskQuantity, ITEMMENU_TaskTossQuantityInput, ITEMMENU_TaskGiveItem, ITEMMENU_TaskSellQuantityInput, ITEMMENU_TaskSellAskConfirm, ITEMMENU_TaskSellConfirmInput, ITEMMENU_TaskWaitMessageDismiss, ITEMMENU_TaskReturnToListFromQuantity, ITEMMENU_RemoveSelectedItems, ITEMMENU_ShowQuantityWindows, ITEMMENU_HideQuantityWindows, ITEMMENU_HandleQuantityInput, ITEMMENU_CompareSortEntries, ITEMMENU_SortPocket, ITEMMENU_ShowInputGuardError, ITEMMENU_SortAndRedraw, ITEMMENU_RefreshInputGuard, ITEMMENU_SetCursorActive, ITEMMENU_IsBrowseMode, ITEMMENU_ToggleRegisteredItem, ITEMMENU_GetPocketSortFlag, ITEMMENU_TogglePocketSortFlag, ITEMMENU_UpdatePocketSortIcon, ITEMMENU_CheckItemFilter, ITEMMENU_BuildActionList, ITEMMENU_OpenActionMenu, ITEMMENU_IsItemRegistered, ITEMMENU_HandleTouchTarget, ITEMMENU_VBlankCallback, ITEMMENU_TaskStartFadeIn, ITEMMENU_TaskWaitFadeIn, ITEMMENU_Init, ITEMMENU_Main, ITEMMENU_Exit, ITEMMENU_ReturnToBagMain, ITEMMENU_ReturnToListInput, ITEMMENU_CreateBlinkPalAnm, ITEMMENU_DeleteBlinkPalAnm, ITEMMENU_TaskSelectItemFlash, ITEMMENU_StartSideButtonPress, ITEMMENU_TaskWaitSideButtonPress, ITEMMENU_StartPocketTabPress, ITEMMENU_TaskWaitPocketTabPress, ITEMMENU_CheckTouchRelease, ITEMMENU_TaskReopenListFromQuantity, ITEMMENU_TaskReturnFromQuantity, ITEMMENU_AllocPalAnmSlots, ITEMMENU_FreePalAnmSlots, ITEMMENU_TaskInputGuardMessage, ITEMMENU_TaskWaitMessageThenList, ITEMMENU_IsCheckModeAllowed, ITEMMENU_ReturnToBagMainAlias, ITEMMENU_InitDisplayBanks, ITEMMENU_ResetDisplayLayers, ITEMMENU_LoadBagGraphics, ITEMMENU_LoadTabGraphics, ITEMMENU_SetupGraphics, ITEMMENU_ApplyBgPalettes, ITEMMENU_SetLayersVisible, ITEMMENU_SetMoveTypeIconsVisible, ITEMMENU_DrawMoveInfo, ITEMMENU_HideMoveInfo, ITEMMENU_FreeGraphics, ITEMMENU_PrintMenuTitle, ITEMMENU_InitWindows, ITEMMENU_DestroyMovingCursor, ITEMMENU_CreateMovingCursor, ITEMMENU_FreeActionMenuResources, ITEMMENU_LoadPocketGraphics, ITEMMENU_CreateCursorActors, ITEMMENU_GetRowColorKind, ITEMMENU_PrintItemList, ITEMMENU_SnapSelectorToCursor, ITEMMENU_UploadSlotGraphics, ITEMMENU_UpdateCursorFromTouch, ITEMMENU_MoveCursorToRow, ITEMMENU_CreateSideButtonActors, ITEMMENU_CreateTabActors, ITEMMENU_SelectTab, ITEMMENU_ClearMessageWindow, ITEMMENU_OpenPopupList, ITEMMENU_LoadBgPaletteMode, ITEMMENU_PrintMoveInfoText, ITEMMENU_ShowMessage, ITEMMENU_ShowMessageDefault, ITEMMENU_ShowItemUseMessage, ITEMMENU_IsMessageFinished, ITEMMENU_PrintPocketName, ITEMMENU_HideSideWindows, ITEMMENU_PrintPocketCount, ITEMMENU_PrintMoney, ITEMMENU_EnterQuantityMode, ITEMMENU_LeaveQuantityMode, ITEMMENU_OpenYesNoList, ITEMMENU_CloseYesNoList, ITEMMENU_LoadSellPalette, ITEMMENU_PrintQuantityPrice, ITEMMENU_PocketToSortFlag, ITEMMENU_UpdateSlotActorPosition, ITEMMENU_UpdateSideButtons, ITEMMENU_SetBackButtonAnim, ITEMMENU_UpdateInputGuardAnim, ITEMMENU_UpdateSideButtonsForMode, ITEMMENU_MoveActorToPoint, ITEMMENU_PrintToWindow, ITEMMENU_FlushWindowAt, ITEMMENU_FlushDirtyWindows
 * address:  0x021B6100
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   func_020355C4 0x020355C4 arm
 *   ITEMMENU_DrawMoveInfo 0x021B9850 thumb ov070
 *   ITEMMENU_HideMoveInfo 0x021B9AAC thumb ov070
 *   ITEMMENU_PrintItemList 0x021BA218 thumb ov070
 *   ITEMMENU_UpdatePocketSortIcon 0x021B81F4 thumb ov070
 *   func_020081DC 0x020081DC thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02007F7C 0x02007F7C thumb
 *   func_02007FA0 0x02007FA0 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF6C 0x0201EF6C thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02008270  0x02008270  thumb
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   ITEMMENU_PrintPocketCount  0x021BAF38  thumb  ov070
 *   ITEMMENU_SelectTab  0x021BA96C  thumb  ov070
 *   ITEMMENU_LoadBgPaletteMode  0x021BAAA4  thumb  ov070
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   func_0202EDE4  0x0202EDE4  thumb
 *   ITEMMENU_UpdateCursorFromTouch  0x021BA654  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02035D20 0x02035D20 arm
 *   ITEMMENU_UpdateSideButtonsForMode 0x021BB5DC thumb ov070
 *   ITEMMENU_ReturnToBagMain 0x021B8AF4 thumb ov070
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_020362DC  0x020362DC  arm
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0200D55C  0x0200D55C  thumb
 *   ITEMMENU_RemoveSelectedItems  0x021B7D20  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   gItemMenuUseRanges  0x021BB9C4  data  a4
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   GAME_BEACON_SetItemUse  0x02027324  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   PALANM_IsOutsideReservedIdRange  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02006238  0x02006238  thumb
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_02021350  0x02021350  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   d_021BB960     0x021BB960  data  a1
 *   func_02030734  0x02030734  arm
 *   MYITEM_SAVEDATA_CopyPocket   0x02007CC8  thumb
 *   func_02020F14  0x02020F14  thumb
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   d_021BBBC0     0x021BBBC0  data  ov070  a1
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   func_0202E448  0x0202E448  thumb
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   func_02020F34  0x02020F34  thumb
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   d_021BB984     0x021BB984  data  a4
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203FB44  0x0203FB44  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   func_020490F4  0x020490F4  arm
 *   BLINK_PALANM_LoadPalettes  0x0202E9AC  thumb
 *   func_0202EA20 0x0202EA20 thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021BB978 0x021BB978 data a4
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02012B70 0x02012B70 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021BBB40     0x021BBB40  data  a4
 *   d_021BBB60     0x021BBB60  data  a4
 *   d_021BBB80     0x021BBB80  data  a4
 *   d_021BBB20     0x021BBB20  data  a4
 *   d_021BBAC0     0x021BBAC0  data  a4
 *   d_021BBAE0     0x021BBAE0  data  a4
 *   d_021BBB00     0x021BBB00  data  a4
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   d_021BBBE0  0x021BBBE0  data a4
 *   d_021BBA8C  0x021BBA8C  data  ov070
 *   d_021BBAB0  0x021BBAB0  data a4
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_0202130C  0x0202130C  thumb
 *   func_02020FB4  0x02020FB4  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   BMP_Delete  0x020437AC  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02020E60  0x02020E60  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BMP_Create  0x02043678  arm
 *   func_02021288  0x02021288  thumb
 *   func_02045730  0x02045730  arm
 *   d_021BBA79     0x021BBA79  data  ov070  a1
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_0202EE0C  0x0202EE0C  thumb
 *   d_021BBAA8     0x021BBAA8  data  ov070  a1
 *   d_021BBA6C     0x021BBA6C  data  a1
 *   d_021BBA68     0x021BBA68  data  a1
 *   d_021BBA64     0x021BBA64  data  ov070  a1
 *   d_021BBA74     0x021BBA74  data  a1
 *   d_021BBBCC     0x021BBBCC  data  a2
 *   d_021BBA81     0x021BBA81  data  a1
 *   func_0201F7A8 0x0201F7A8 thumb
 *   STRBUF_Create  0x020457B0  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt  0x020499D4  arm
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0200C274 0x0200C274 thumb
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02041090  0x02041090  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_020056BC  0x020056BC  thumb
 *   PALANM_RequestFade  0x0202173C  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   KEY_GetRepeatSpeed  0x02036370  arm  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   TCBL_Create  0x0203101C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm  arm9
 *   CLACT_InitSystem  0x0204A48C  arm  arm9
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *   BUTTON_MAN_Create  0x02051B84  arm  arm9
 */

#include "itemmenu_types.h"

#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
#define REG_GX_POWCNT_DSEL_MASK 0x8000
#define REG_GX_POWCNT_DSEL_SHIFT 15
struct MsgBank;
struct WordSet;
struct TaskMenu;
struct PrintSys;
struct Ctx;
struct Blk34;
struct Rec;
struct S02021D50;
struct Tcbl;
struct MyItemSave;
struct Descriptor;
struct Node;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct S020315D4;
struct Actor;
struct PalAnmSlot;
struct BigObj;
struct Sub0200852CObj;
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct CharBuf;
struct Bmp;
struct PtS;
struct Vec2;
struct TaskMenuTmpl;
struct Rec3;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

#include "itemmenu_types.h"





typedef signed int     s32;



















typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct HitRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} HitRect;

typedef struct HitTbl {
    HitRect r[3];
} HitTbl;

typedef struct Ent {
    Item item;
    u32 key;
} Ent;




typedef struct { int v[11]; } T44;

typedef struct { unsigned char v[4]; } T4;


typedef struct TabTbl {
    int v[5];
} TabTbl;

typedef short s16;

typedef struct Parent {
    u8 pad00[0x34];
    u32 f34;
    u32 f38;
} Parent;




typedef enum {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

typedef struct { u16 x, y, z; u8 a, b; } Rect;

typedef struct { u32 w[4]; } Tbl16;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect_021B9850;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021B9EF4;

typedef signed short s16_021BB6E0;

typedef struct {
    unsigned short a, b;
} Pt;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021BA6F4;

typedef struct {
    u8 v[5];
} B5;

typedef struct {
    u8 v[2];
} B2;

typedef struct {
    short x, y;
    unsigned short z;
    unsigned char d, e;
} Rect_021BA8C0;


typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;




typedef struct {
    u16 w;
    u16 h;
    u16 pad[4];
    u16 d[1];
} Img;


typedef short s16_021BB3F4;

typedef struct ItemMenuArgs {
    void *saveData;
    void *optionsSave;
    void *myStatus;
    struct MyItemSave *bagCursor;
    void *bag;
    int actionPermissions[6];
    int bagMode;
    int bagFilter;
} ItemMenuArgs;


extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const struct TaskMenu *p);
extern void GAME_BEACON_SetItemUse(u16 id);
extern u32 func_02020FE4(u16 a, u32 sel, u32 id);
extern u32 func_02028754(struct Actor *obj, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0204B92C(struct Actor *p, u32 v);
extern u8 func_020355C4(void);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 PALANM_IsOutsideReservedIdRange(u16 v);
extern unsigned int func_0202136C(u16 v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int TOUCHPANEL_GetCont(void);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern s32 BLINK_PALANM_Update(struct BlinkPalAnm *p);
extern u32 func_020362DC(void);
extern void func_020061E4(unsigned int se);
extern void func_020355D8(u8 v);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void CLACT_SetActorAnimSeq(struct Actor *p, u16 value);
extern unsigned int func_0203633C(void);
extern void func_020414EC(u32 i);
extern int func_02006238(void);
extern int TOUCHPANEL_GetTrg(void);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern u8 func_02021350(u16 id);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void func_0204B3DC(struct Actor *p, u32 v);
extern int TOUCHPANEL_HitCont(const void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MYITEM_SAVEDATA_CopyPocket(u8 *base, void *buf, u32 id, int save);
extern void *func_02020F14(u32 a);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(Ent *, Ent *), void *buf);
extern void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *p);
extern u32 func_0202E448(u32 id);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);
extern int GAME_DATA_CheckSaveFlag(void *p, int a);
extern void *func_02020F34(unsigned int item, unsigned int which, unsigned int heap);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void CLACT_VBlankSystem();
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern void TCBL_Main(struct Tcbl *p);
extern void func_02030EAC(struct Node *n);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern u32 GF_FONT_Delete(void *ptr);
extern int APP_KEYCURSOR_Delete(int a0);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void BUTTON_MAN_Delete(void *p);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern int KEY_SetRepeatSpeed(int a0, int a1);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern struct BlinkPalAnm *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct BlinkPalAnm *p);
extern void CLACT_SetActorAnimFrame(struct Actor *p, u32 value);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern int func_02012B70(const struct BigObj *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int bg);
extern void func_020409B4(u32 layer);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void func_0201DD60(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_0201DD68(void);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern u32 func_02027610(u32 a);
extern u32 func_020275F8(u32 a);
extern u8 func_02027604(u8 i);
extern u8 func_020275EC(int i);
extern struct Actor *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B6F4(struct Actor *o, u32 v, u32 flag);
extern int WAZA_TOOL_GetDamageType(int);
extern u8 WAZA_TOOL_GetType(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 func_0202130C(u32 id);
extern void func_02020FB4(void *dst, u32 entry, u32 heap);
extern void CLACT_DeleteActor(struct Actor *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void BMP_Delete(struct Bmp *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern int func_02020E60(unsigned short, int);
extern void CLACT_DrawSystem(void);
extern void APP_TASKMENU_UpdateMenu(void *);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02021288(u32 id);
extern u8 func_02045730(struct Descriptor *p);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimIndex(void *, int);
extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void func_020862F0(void *, u32);
extern void func_0207E780(void *, void *, u32);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0201F7A8(void *, unsigned);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
extern u32 func_0201BD28(u16 id, u32 field);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern signed char func_02012FFC(void);
extern int PRINTSYS_PrintStream(int, int, int, void *, int, int, int, int, int, int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_0201CE30(void *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0200C274(struct Blk34 *);
extern void *ARC_UTIL_LoadHandleMember(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern int func_02062B30(void *file, void **out);
extern void func_02041090(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16_021BB3F4 step, u8 b, u8 c, u16 d, u32 ctx);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern u32 func_0204B3F4(struct Actor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, void *d, u32 e, u16 f);
extern void GFL_HEAP_CreateChildHeap();
extern void *PROCSYS_AllocProcWork();
extern void KEY_GetRepeatSpeed();
extern void func_0200816C();
extern int func_02008284(struct MyItemSave *p);
extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b);
extern void *func_02045B38();
extern void *func_0201EC64();
extern void *func_0201C450();
extern int func_02028590();
extern int GF_FONT_Create();
extern void *BUTTON_MAN_Create();
extern int func_020056A0();
extern int TCBL_Create();
extern int APP_TASKMENU_RES_Create();
extern void GFL_NET_RestartWithDefaultTimeout();
void ITEMMENU_HandleActionMenuChoice(ItemMenuWork *work);
void ITEMMENU_TaskSelectItem(ItemMenuWork *work);
void ITEMMENU_TaskBagMain(ItemMenuWork *work);
void ITEMMENU_TaskActionMenuInput(ItemMenuWork *work);
void ITEMMENU_TaskOpenActionMenu(ItemMenuWork *work);
void ITEMMENU_TaskRegisterResultMessage(ItemMenuWork *work);
void ITEMMENU_TaskStartRegisterResult(ItemMenuWork *work);
void ITEMMENU_TaskUseNoticeMessage(ItemMenuWork *work);
void ITEMMENU_TaskReturnToListAfterMessage(ItemMenuWork *work);
void ITEMMENU_TaskBeginReturnToList(ItemMenuWork *work);
void ITEMMENU_TaskTossConfirmInput(ItemMenuWork *work);
void ITEMMENU_TaskOpenTossConfirm(ItemMenuWork *work);
void ITEMMENU_TaskTossAskQuantity(ItemMenuWork *work);
void ITEMMENU_TaskTossQuantityInput(ItemMenuWork *work);
void ITEMMENU_TaskGiveItem(ItemMenuWork *work);
void ITEMMENU_TaskSellQuantityInput(ItemMenuWork *work);
void ITEMMENU_TaskSellAskConfirm(ItemMenuWork *work);
void ITEMMENU_TaskSellConfirmInput(ItemMenuWork *work);
void ITEMMENU_TaskWaitMessageDismiss(ItemMenuWork *work);
void ITEMMENU_TaskReturnToListFromQuantity(ItemMenuWork *work);
void ITEMMENU_RemoveSelectedItems(ItemMenuWork *work, int x);
void ITEMMENU_ShowQuantityWindows(ItemMenuWork *work, int v);
void ITEMMENU_HideQuantityWindows(ItemMenuWork *work);
int ITEMMENU_HandleQuantityInput(ItemMenuWork *work);
int ITEMMENU_CompareSortEntries(Ent *a, Ent *b);
void ITEMMENU_SortPocket(ItemMenuWork *work);
void ITEMMENU_ShowInputGuardError(ItemMenuWork *work);
void ITEMMENU_SortAndRedraw(ItemMenuWork *work);
void ITEMMENU_RefreshInputGuard(ItemMenuWork *work);
void ITEMMENU_SetCursorActive(ItemMenuWork *work, int flag);
int ITEMMENU_IsBrowseMode(ItemMenuWork *work);
int ITEMMENU_ToggleRegisteredItem(ItemMenuWork *work, int k);
int ITEMMENU_GetPocketSortFlag(int x);
void ITEMMENU_TogglePocketSortFlag(ItemMenuWork *work);
void ITEMMENU_UpdatePocketSortIcon(ItemMenuWork *work);
void ITEMMENU_CheckItemFilter(ItemMenuWork *work, void *rec, u16 *p, u8 *out);
void ITEMMENU_BuildActionList(ItemMenuWork *work, unsigned char *q);
void ITEMMENU_OpenActionMenu(ItemMenuWork *work);
int ITEMMENU_IsItemRegistered(ItemMenuWork *work, int value);
void ITEMMENU_HandleTouchTarget(u32 idx, int flag, ItemMenuWork *work);
void ITEMMENU_VBlankCallback(int u, ItemMenuWork *work);
void ITEMMENU_TaskStartFadeIn(ItemMenuWork *work);
void ITEMMENU_TaskWaitFadeIn(ItemMenuWork *work);
int ITEMMENU_Init(void *proc, int st, ItemMenuArgs *a);
int ITEMMENU_Main(int a, int b, int c, ItemMenuWork *work);
int ITEMMENU_Exit(void *proc, int b, Parent *par, ItemMenuWork *work);
void ITEMMENU_ReturnToBagMain(ItemMenuWork *work);
int ITEMMENU_ReturnToListInput(ItemMenuWork *work);
void ITEMMENU_CreateBlinkPalAnm(ItemMenuWork *work);
void ITEMMENU_DeleteBlinkPalAnm(ItemMenuWork *work);
void ITEMMENU_TaskSelectItemFlash(ItemMenuWork *work);
void ITEMMENU_StartSideButtonPress(ItemMenuWork *work, int a, ItemMenuTaskFn callback);
void ITEMMENU_TaskWaitSideButtonPress(ItemMenuWork *work);
void ITEMMENU_StartPocketTabPress(ItemMenuWork *work, int u, int a, ItemMenuTaskFn callback);
void ITEMMENU_TaskWaitPocketTabPress(ItemMenuWork *work);
int ITEMMENU_CheckTouchRelease(void);
void ITEMMENU_TaskReopenListFromQuantity(ItemMenuWork *work);
void ITEMMENU_TaskReturnFromQuantity(ItemMenuWork *work);
void ITEMMENU_AllocPalAnmSlots(ItemMenuWork *work);
void ITEMMENU_FreePalAnmSlots(ItemMenuWork *work);
void ITEMMENU_TaskInputGuardMessage(ItemMenuWork *work);
void ITEMMENU_TaskWaitMessageThenList(ItemMenuWork *work);
int ITEMMENU_IsCheckModeAllowed(ItemMenuWork *work, int value);
void ITEMMENU_ReturnToBagMainAlias(ItemMenuWork *work);
void ITEMMENU_InitDisplayBanks(void);
void ITEMMENU_ResetDisplayLayers(void);
void ITEMMENU_LoadBagGraphics(ItemMenuWork *work, int bg);
void ITEMMENU_LoadTabGraphics(ItemMenuWork *work, void *bg);
void ITEMMENU_SetupGraphics(ItemMenuWork *work);
void ITEMMENU_ApplyBgPalettes(ItemMenuWork *work);
void ITEMMENU_SetLayersVisible(void *p, int v);
void ITEMMENU_SetMoveTypeIconsVisible(ItemMenuWork *work, int mode);
void ITEMMENU_DrawMoveInfo(ItemMenuWork *work);
void ITEMMENU_HideMoveInfo(ItemMenuWork *work);
void ITEMMENU_FreeGraphics(ItemMenuWork *work);
void ITEMMENU_PrintMenuTitle(ItemMenuWork *work);
void ITEMMENU_InitWindows(ItemMenuWork *work);
void ITEMMENU_DestroyMovingCursor(ItemMenuWork *work);
void ITEMMENU_CreateMovingCursor(ItemMenuWork *work, int id);
void ITEMMENU_FreeActionMenuResources(ItemMenuWork *work);
void ITEMMENU_LoadPocketGraphics(ItemMenuWork *work);
void ITEMMENU_CreateCursorActors(ItemMenuWork *work);
int ITEMMENU_GetRowColorKind(u16 x);
void ITEMMENU_PrintItemList(ItemMenuWork *work);
void ITEMMENU_SnapSelectorToCursor(ItemMenuWork *work);
void ITEMMENU_UploadSlotGraphics(ItemMenuWork *work);
void ITEMMENU_UpdateCursorFromTouch(ItemMenuWork *work);
void ITEMMENU_MoveCursorToRow(ItemMenuWork *work);
void ITEMMENU_CreateSideButtonActors(ItemMenuWork *work);
void ITEMMENU_CreateTabActors(ItemMenuWork *work);
void ITEMMENU_SelectTab(ItemMenuWork *work, unsigned sel);
void ITEMMENU_ClearMessageWindow(ItemMenuWork *work);
void ITEMMENU_OpenPopupList(ItemMenuWork *work, int *tbl, int n);
void ITEMMENU_LoadBgPaletteMode(ItemMenuWork *work, int mode);
void ITEMMENU_PrintMoveInfoText(ItemMenuWork *work, int x);
void ITEMMENU_ShowMessage(ItemMenuWork *work, int mode);
void ITEMMENU_ShowMessageDefault(ItemMenuWork *work);
void ITEMMENU_ShowItemUseMessage(ItemMenuWork *work, unsigned v);
int ITEMMENU_IsMessageFinished(ItemMenuWork *work);
void ITEMMENU_PrintPocketName(ItemMenuWork *work);
void ITEMMENU_HideSideWindows(ItemMenuWork *work);
void ITEMMENU_PrintPocketCount(ItemMenuWork *work, int val);
void ITEMMENU_PrintMoney(ItemMenuWork *work);
void ITEMMENU_EnterQuantityMode(ItemMenuWork *work);
void ITEMMENU_LeaveQuantityMode(ItemMenuWork *work);
void ITEMMENU_OpenYesNoList(ItemMenuWork *work);
void ITEMMENU_CloseYesNoList(ItemMenuWork *work);
void ITEMMENU_LoadSellPalette(ItemMenuWork *work);
void ITEMMENU_FlushDirtyWindows(ItemMenuWork *work);
void ITEMMENU_PrintQuantityPrice(ItemMenuWork *work, int val);
int ITEMMENU_PocketToSortFlag(int x);
void ITEMMENU_UpdateSlotActorPosition(ItemMenuWork *work, u32 val);
void ITEMMENU_UpdateSideButtons(ItemMenuWork *work, int mode);
void ITEMMENU_SetBackButtonAnim(ItemMenuWork *work, int v);
void ITEMMENU_UpdateInputGuardAnim(ItemMenuWork *work);
void ITEMMENU_UpdateSideButtonsForMode(ItemMenuWork *work, int mode);
int ITEMMENU_MoveActorToPoint(const char *p);
void ITEMMENU_PrintToWindow(ItemMenuWork *work, u32 *obj, void *str, u16 x, s16_021BB6E0 y, u16 color);
void ITEMMENU_FlushWindowAt(void **p);
extern HitTbl d_021BB960;
extern char d_021BBBC0[];
extern T44 d_021BB998;
extern T4 d_021BB95C;
extern const TabTbl d_021BB984;
extern const char d_021BB978[];
extern const BgTemplate d_021BBB40;
extern const BgTemplate d_021BBB60;
extern const BgTemplate d_021BBB80;
extern const BgTemplate d_021BBB20;
extern const BgTemplate d_021BBAC0;
extern const BgTemplate d_021BBAE0;
extern const BgTemplate d_021BBB00;
extern u8 d_021BBBE0[];
extern u8 d_021BBA8C[];
extern const Tbl16 d_021BBAB0;
extern const u8 d_021BBA79[];
extern const B5 d_021BBAA8;
extern const B5 d_021BBA6C;
extern const B2 d_021BBA68;
extern const B2 d_021BBA64;
extern unsigned char d_021BBA74[];
extern short d_021BBBCC[][2];
extern unsigned char d_021BBA81[];
extern char d_021BBA04[];
/* Item id range with the handler that uses items of that range. */
typedef struct ItemUseRange {
    u16 firstItemId;
    u16 itemCount;
    void (*useHandler)(void *);
} ItemUseRange;
/* Message ids of the bag message bank. */
#define ITEMMENU_MSG_CANT_USE_KEY_ITEM 0x38
#define ITEMMENU_MSG_CANT_USE_IN_CONTEXT 0x39
#define ITEMMENU_MSG_CANT_USE_NOW 0x3A
#define ITEMMENU_MSG_REPEL_USED 0x3F
#define ITEMMENU_MSG_REPEL_STILL_ACTIVE 0x40
extern BagSlot *func_020081DC(void *bag, u32 pocket, u32 index);
extern unsigned int func_02007F7C(const BagSlot *items, unsigned int maxCount);
extern u32 func_02007FA0(void *bag, u32 pocket);
extern void func_0201EF40(void *wordSet, u32 slot, u32 itemId);
extern void func_0201EF6C(void *wordSet, u32 slot, u32 itemId, u32 isPlural, u32 flags);
extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);
extern u32 func_0202EDE4(u32 range, u32 position, u32 thumbSize, u32 trackSize, u32 flags);
extern u32 func_02035D20(u32 *outX, u32 *outY);
extern void *GAME_DATA_GetSaveControl(void *saveData);
extern void *func_0200D418(void *fieldSave);
extern u32 func_0200D58C(void *repelState);
extern void func_0200D55C(void *repelState, u8 steps);
void func_021B6100(ItemMenuWork *work, ItemMenuTaskFn taskFn);
void func_021B6120(ItemMenuWork *work);
void ITEMMENU_RedrawList(ItemMenuWork *work);
BagSlot *ITEMMENU_GetSlot(ItemMenuWork *work, int index);
int ITEMMENU_GetSellTotal(int itemId, int count, unsigned int heapId);
int ITEMMENU_GetCursorIndex(ItemMenuWork *work);
int ITEMMENU_GetItemCount(ItemMenuWork *work);
void ITEMMENU_RegisterItemName(ItemMenuWork *work, int slot, unsigned int itemId);
void ITEMMENU_RegisterItemNameCounted(ItemMenuWork *work, int slot, unsigned int itemId, int isPlural, int flags);
void ITEMMENU_SwapSlots(ItemMenuWork *work, int indexA, int indexB);
void ITEMMENU_MoveSlot(ItemMenuWork *work, int fromIndex, int toIndex);
void ITEMMENU_SwitchPocketCursor(ItemMenuWork *work, int prevPocket, int nextPocket);
int ITEMMENU_MoveCursorDown(ItemMenuWork *work, int itemCount, int canWrap);
int ITEMMENU_MoveCursorUp(ItemMenuWork *work, int itemCount, int canWrap);
u32 ITEMMENU_HandleScrollbarTouch(ItemMenuWork *work);
int ITEMMENU_HandleMoveModeKeys(ItemMenuWork *work);
int ITEMMENU_HandleListKeys(ItemMenuWork *work);
int ITEMMENU_HandleListTouch(ItemMenuWork *work);
int ITEMMENU_IsBackButtonTouched(void);
void ITEMMENU_TaskFinishClose(ItemMenuWork *work);
void ITEMMENU_TaskListInput(ItemMenuWork *work);
int ITEMMENU_IsRepelItem(u16 itemId);
int ITEMMENU_GetFieldUseKind(u16 itemId);
void ITEMMENU_UseRepel(ItemMenuWork *work);
void ITEMMENU_TaskWaitMessage(ItemMenuWork *work);
void ITEMMENU_ShowKeyItemRefusal(ItemMenuWork *work);
void ITEMMENU_ShowMessageThenWait(ItemMenuWork *work);
u32 ITEMMENU_TryStartUse(ItemMenuWork *work);
u32 ITEMMENU_TryStartGive(ItemMenuWork *work);
u32 ITEMMENU_TryStartRegister(ItemMenuWork *work);
u32 ITEMMENU_TryStartCheck(ItemMenuWork *work);
u32 ITEMMENU_TryStartToss(ItemMenuWork *work);
u32 ITEMMENU_TryStartSort(ItemMenuWork *work);
u32 ITEMMENU_TryStartPlant(ItemMenuWork *work);
u32 ITEMMENU_TryStartSell(ItemMenuWork *work);
int ITEMMENU_FindUseRange(u16 itemId);
extern const ItemUseRange gItemMenuUseRanges[8];
extern u32 PRINTSYS_QUE_Main(void *printSys);
extern u32 func_0201C6C4(void *printSys, void *textBuffer);


/* Sets the task function of the screen and the key repeat speed. */
void func_021B6100(ItemMenuWork *work, ItemMenuTaskFn taskFn)
{
    work->taskFn = taskFn;
    KEY_SetRepeatSpeed(work->keyRepeatDelay, work->keyRepeatInterval);
}

/* Forces the list to be drawn again. */
void func_021B6120(ItemMenuWork *work)
{
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
}

void ITEMMENU_RedrawList(ItemMenuWork *work)
{
    if (func_020355C4() == 0)
        ITEMMENU_DrawMoveInfo(work);
    else
        ITEMMENU_HideMoveInfo(work);
    ITEMMENU_PrintItemList(work);
    ITEMMENU_UpdatePocketSortIcon(work);
    work->listDirty = 1;
}

/* Slot of the shown pocket: the work copy while an item is being moved,
 * the bag otherwise. */
BagSlot *ITEMMENU_GetSlot(ItemMenuWork *work, int index)
{
    if (work->usingWorkCopy) return &work->items[index];
    return func_020081DC(work->bag, (u16)(work->currentPocket), (u16)index);
}

/*
 * extent: two bytes of zero alignment follow the 26-byte function.
 * lever: enum quotient preserves its r1 web and the copy to return r0.
 * The signed quotient is multiplied with unsigned modular arithmetic.
 */
int ITEMMENU_GetSellTotal(int itemId, int count, unsigned int heapId)
{
    typedef enum { HALF_ZERO } Half;
    Half unitPrice;
    unitPrice = (Half)((int)func_02020FE4((u16)itemId, 0, heapId) / 2);
    return (int)((unsigned int)unitPrice * (unsigned int)count);
}

/* Index of the selected entry in the whole list. */
int ITEMMENU_GetCursorIndex(ItemMenuWork *work)
{
    return (int)((unsigned int)work->cursorRow + (unsigned int)work->scrollOffset + 1U);
}

int ITEMMENU_GetItemCount(ItemMenuWork *work)
{
    if (work->usingWorkCopy) return func_02007F7C(work->items, ITEMMENU_POCKET_ITEM_COUNT);
    return func_02007FA0(work->bag, work->currentPocket);
}

void ITEMMENU_RegisterItemName(ItemMenuWork *work, int slot, unsigned int itemId)
{
    func_0201EF40(work->wordSet, slot, itemId);
}

/*
 * Extent ends in two zero alignment bytes.
 */
void ITEMMENU_RegisterItemNameCounted(ItemMenuWork *work, int slot, unsigned int itemId, int isPlural, int flags)
{
    func_0201EF6C(work->wordSet, slot, itemId, isPlural, flags);
}

void ITEMMENU_SwapSlots(ItemMenuWork *work, int indexA, int indexB)
{
    int tmp;
    MI_CpuCopy8(&work->items[indexA], &tmp, 4);
    MI_CpuCopy8(&work->items[indexB], &work->items[indexA], 4);
    MI_CpuCopy8(&tmp, &work->items[indexB], 4);
}

/* Moves an entry to a new place by swapping it step by step. */
void ITEMMENU_MoveSlot(ItemMenuWork *work, int fromIndex, int toIndex)
{
    if (fromIndex == toIndex) return;
    if (fromIndex < toIndex) {
        for (; fromIndex < toIndex; fromIndex++) ITEMMENU_SwapSlots(work, fromIndex, fromIndex + 1);
    } else {
        for (; fromIndex > toIndex; fromIndex--) ITEMMENU_SwapSlots(work, fromIndex, fromIndex - 1);
    }
}

/* Stores the cursor of the old pocket and loads the cursor of the new one. */
void ITEMMENU_SwitchPocketCursor(ItemMenuWork *work, int prevPocket, int nextPocket)
{
    s16 loaded[2];

    func_02008298(work->bagCursor, prevPocket);
    func_02008288(work->bagCursor, (u16)prevPocket, work->cursorRow, work->scrollOffset + 1);
    func_02008270(work->bagCursor, (u16)nextPocket, &loaded[1], &loaded[0]);
    work->cursorRow = loaded[1];
    work->scrollOffset = loaded[0] - 1;
    ITEMMENU_MoveCursorToRow(work);
    ITEMMENU_PrintPocketCount(work, nextPocket);
    ITEMMENU_SelectTab(work, nextPocket);
    ITEMMENU_LoadBgPaletteMode(work, nextPocket);
}

/* Cursor one entry down. Six rows are visible; the list scrolls once the
 * cursor is on the last row. Returns 1 when the cursor moved. */
int ITEMMENU_MoveCursorDown(ItemMenuWork *work, int itemCount, int canWrap)
{
    int prevRow, prevScroll;

    if (itemCount == 0)
        return 0;
    prevRow = work->cursorRow;
    prevScroll = work->scrollOffset;
    if (prevRow == 5 && prevScroll + 7 < itemCount) {
        work->scrollOffset = work->scrollOffset + 1;
    } else if (prevRow != 5 && prevRow + 1 < itemCount) {
        work->cursorRow = work->cursorRow + 1;
    } else if (canWrap == 1) {
        work->scrollOffset = -1;
        work->cursorRow = 0;
    }
    return prevRow != work->cursorRow || prevScroll != work->scrollOffset;
}

/* Cursor one entry up, wrapping to the end of the list when allowed. */
int ITEMMENU_MoveCursorUp(ItemMenuWork *work, int itemCount, int canWrap)
{
    int prevRow, prevScroll, lastScroll;

    if (itemCount == 0)
        return 0;
    prevRow = work->cursorRow;
    prevScroll = work->scrollOffset;
    if (prevRow == 0 && prevScroll != -1) {
        work->scrollOffset = work->scrollOffset - 1;
    } else if (prevRow != 0) {
        work->cursorRow = work->cursorRow - 1;
    } else if (canWrap == 1) {
        lastScroll = itemCount - 7;
        work->scrollOffset = lastScroll;
        if (lastScroll < -1)
            work->scrollOffset = -1;
        if ((work->cursorRow = 5) >= itemCount)
            work->cursorRow = itemCount - 1;
    }
    return prevRow != work->cursorRow || prevScroll != work->scrollOffset;
}

/* Touch on the scroll bar at the right edge of the list. */
u32 ITEMMENU_HandleScrollbarTouch(ItemMenuWork *work)
{
    u32 touchX, touchY, prevScroll;
    int itemCount;

    itemCount = ITEMMENU_GetItemCount(work);
    if (itemCount >= 7 && TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchX >= 0x100 || touchX < 0xE0)
            return 0;
        if (work->isTouchActive == 0) {
            if (TOUCHPANEL_GetTrg() == 1) {
                if (touchY < 0x10 || touchY >= 0x98)
                    return 0;
                work->isTouchActive = 1;
            } else
                return 0;
        }
        ITEMMENU_SetCursorActive(work, 0);
        prevScroll = work->scrollOffset;
        work->scrollOffset = func_0202EDE4(itemCount - 6, touchY, 0x1A, 0x8E, 0) - 1;
        ITEMMENU_UpdateCursorFromTouch(work);
        if (work->scrollOffset != prevScroll) {
            func_020061E4(ITEMMENU_SE_CURSOR);
            return 1;
        }
    }
    return 0;
}

/* Key input while an item is being moved: the entry follows the cursor. */
int ITEMMENU_HandleMoveModeKeys(ItemMenuWork *work)
{
    int moved = 0;
    int startIndex, itemCount;
    u32 steps;

    startIndex = ITEMMENU_GetCursorIndex(work);
    itemCount = ITEMMENU_GetItemCount(work);
    if (func_0203633C() & ITEMMENU_KEY_DOWN) {
        moved = ITEMMENU_MoveCursorDown(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_UP) {
        moved = ITEMMENU_MoveCursorUp(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_R) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorDown(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    } else if (func_0203633C() & ITEMMENU_KEY_L) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorUp(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    }
    if (moved) {
        itemCount = ITEMMENU_GetCursorIndex(work);
        func_020061E4(ITEMMENU_SE_CURSOR);
        ITEMMENU_MoveSlot(work, startIndex, itemCount);
    }
    return moved;
}

/* Key input in the plain list: up, down, and six entries with L and R. */
int ITEMMENU_HandleListKeys(ItemMenuWork *work)
{
    int moved = 0;
    int itemCount;
    u32 steps;

    itemCount = ITEMMENU_GetItemCount(work);
    if (func_0203633C() & ITEMMENU_KEY_DOWN) {
        moved = ITEMMENU_MoveCursorDown(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_UP) {
        moved = ITEMMENU_MoveCursorUp(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_R) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorDown(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    } else if (func_0203633C() & ITEMMENU_KEY_L) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorUp(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    }
    return moved;
}

/* Touch on a list row: moves the cursor to it. Rows are 0x18 pixels high. */
int ITEMMENU_HandleListTouch(ItemMenuWork *work)
{
    u32 touchX, touchY;
    int itemCount, startIndex;
    u32 targetRow;
    int rowDistance;
    u32 step;

    if (TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchX < 0x90 || touchX > 0xE7 || touchY < 0xC || touchY > 0x9B)
            return 0;
        targetRow = (touchY - 0xC) / 0x18;
        if ((u32)work->cursorRow == targetRow)
            return 0;
        itemCount = ITEMMENU_GetItemCount(work);
        startIndex = ITEMMENU_GetCursorIndex(work);
        rowDistance = (u32)work->cursorRow - targetRow;
        if (rowDistance < 0)
            rowDistance = -rowDistance;
        if ((u32)work->cursorRow < targetRow) {
            for (step = 0; step < rowDistance; step++) {
                if (ITEMMENU_MoveCursorDown(work, itemCount, 0) == 0)
                    break;
            }
        } else if ((u32)work->cursorRow > targetRow) {
            for (step = 0; step < rowDistance; step++) {
                if (ITEMMENU_MoveCursorUp(work, itemCount, 0) == 0)
                    break;
            }
        }
        if (step == 0)
            return 0;
        ITEMMENU_MoveSlot(work, startIndex, ITEMMENU_GetCursorIndex(work));
        ITEMMENU_SetCursorActive(work, 0);
        return 1;
    }
    return 0;
}

/* Touch on the back button in the bottom right corner. */
int ITEMMENU_IsBackButtonTouched(void)
{
    unsigned int touchX;
    unsigned int touchY;
    if (func_02035D20(&touchX, &touchY) == 1 && touchX >= 0xE0 && touchX <= 0xF7 && touchY >= 0xA8 && touchY <= 0xBF) return 1;
    return 0;
}

/* Task run after the closing transition. */
void ITEMMENU_TaskFinishClose(ItemMenuWork *work)
{
    ITEMMENU_UpdateSideButtonsForMode(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}

/* Main task of the item list: touch, A, B and cursor keys. */
void ITEMMENU_TaskListInput(ItemMenuWork *work)
{
    int startIndex;

    BLINK_PALANM_Update(work->blinkPalAnm);
    if (func_0201C6B4(work->printSys) == 0)
        return;
    startIndex = ITEMMENU_GetCursorIndex(work);
    if (ITEMMENU_HandleScrollbarTouch(work)) {
        ITEMMENU_MoveSlot(work, startIndex, ITEMMENU_GetCursorIndex(work));
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        return;
    }
    if (TOUCHPANEL_GetCont() == 0) {
        work->isTouchActive = 0;
        if (work->isDraggingItem == 1) {
            func_020061E4(ITEMMENU_SE_SELECT);
            work->isDraggingItem = 0;
            func_02007CC8(work->bag, work->items, work->currentPocket, 0);
            CLACT_SetActorAnimSeq(work->selectorActor, 1);
            ITEMMENU_UpdateSideButtonsForMode(work, 1);
            work->usingWorkCopy = 0;
            ITEMMENU_SetCursorActive(work, 0);
            ITEMMENU_ReturnToBagMain(work);
            return;
        }
    }
    if (work->isTouchActive == 1)
        return;
    if (func_020362DC() & (ITEMMENU_KEY_A | ITEMMENU_KEY_SELECT)) {
        func_020061E4(ITEMMENU_SE_SELECT);
        func_02007CC8(work->bag, work->items, work->currentPocket, 0);
        CLACT_SetActorAnimSeq(work->selectorActor, 1);
        ITEMMENU_UpdateSideButtonsForMode(work, 1);
        work->usingWorkCopy = 0;
        ITEMMENU_SetCursorActive(work, 1);
        ITEMMENU_ReturnToBagMain(work);
        return;
    }
    if (func_020362DC() & ITEMMENU_KEY_B) {
        func_020061E4(ITEMMENU_SE_CANCEL);
        CLACT_SetActorAnimSeq(work->selectorActor, 1);
        work->usingWorkCopy = 0;
        ITEMMENU_SetCursorActive(work, 1);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskFinishClose);
        return;
    }
    if (ITEMMENU_IsBackButtonTouched() == 1) {
        func_020061E4(ITEMMENU_SE_CANCEL);
        CLACT_SetActorAnimSeq(work->selectorActor, 1);
        work->usingWorkCopy = 0;
        ITEMMENU_SetCursorActive(work, 0);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskFinishClose);
        return;
    }
    if (ITEMMENU_HandleListTouch(work)) {
        work->isDraggingItem = 1;
        ITEMMENU_MoveCursorToRow(work);
        func_020061E4(ITEMMENU_SE_CURSOR);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        return;
    }
    if (ITEMMENU_HandleMoveModeKeys(work)) {
        ITEMMENU_MoveCursorToRow(work);
        func_020061E4(ITEMMENU_SE_CURSOR);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
    }
}

/* The three repel items (ids 0x4C, 0x4D and 0x4F). */
int ITEMMENU_IsRepelItem(u16 itemId)
{
    int isRepel = 0;
    itemId = (u16)(itemId + 0xFFB4);
    if (itemId <= 3 && ((1 << itemId) & 0xB)) isRepel = 1;
    return isRepel;
}

/* 1 for the repel items, 2 for items 0x268 and 0x269, 0 for all others. */
int ITEMMENU_GetFieldUseKind(u16 itemId)
{
    if (ITEMMENU_IsRepelItem(itemId)) return 1;
    if (itemId == 0x268 || itemId == 0x269) return 2;
    return 0;
}

/* Uses a repel: starts it when none is active, then waits for the message. */
void ITEMMENU_UseRepel(ItemMenuWork *work)
{
    void *repelState;
    u8 steps;

    if (ITEMMENU_IsRepelItem(work->selectedItemId)) {
        repelState = func_0200D418(GAME_DATA_GetSaveControl(work->saveData));
        if (func_0200D58C(repelState)) {
            steps = func_02020FE4(work->selectedItemId, 2, work->heapId);
            func_0200D55C(repelState, steps);
            ITEMMENU_RemoveSelectedItems(work, 1);
            func_02045CAC(work->msgBank, ITEMMENU_MSG_REPEL_USED, work->tempString);
            func_0201F02C(work->wordSet, 0, work->myStatus);
            ITEMMENU_RegisterItemName(work, 1, work->selectedItemId);
            func_0201F250(work->wordSet, work->messageString, work->tempString);
            ITEMMENU_ShowMessage(work, 1);
            func_020061E4(ITEMMENU_SE_REGISTER);
        } else {
            func_02045CAC(work->msgBank, ITEMMENU_MSG_REPEL_STILL_ACTIVE, work->tempString);
            func_0201F250(work->wordSet, work->messageString, work->tempString);
            ITEMMENU_ShowMessage(work, 1);
        }
        func_021B6100(work, ITEMMENU_TaskWaitMessage);
    }
}

/* Task: waits until the message is read, then returns to the list. */
void ITEMMENU_TaskWaitMessage(ItemMenuWork *work)
{
    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if ((func_020362DC() & (ITEMMENU_KEY_A | ITEMMENU_KEY_B)) == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    func_020414EC(3);
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    work->listDirty = 1;
    ITEMMENU_MoveCursorToRow(work);
    func_0204B92C(work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}

/* Shows the refusal message for the items 0x268 and 0x269. */
void ITEMMENU_ShowKeyItemRefusal(ItemMenuWork *work)
{
    if ((unsigned int)work->selectedItemId - 0x268 <= 1) {
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_KEY_ITEM, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessage(work, 1);
        func_021B6100(work, ITEMMENU_TaskWaitMessage);
    }
}

/* Starts the message already prepared and waits for the player. */
void ITEMMENU_ShowMessageThenWait(ItemMenuWork *work) { ITEMMENU_ShowMessage(work, 1); func_021B6100(work, ITEMMENU_TaskWaitMessage); }

/* Action 0 (use). Enters the state when allowed, else shows the refusal. */
u32 ITEMMENU_TryStartUse(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (func_02028754(work->actionPermissions, 0)) {
            work->nextState = 0xA;
            func_021B6100(work, 0);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    } else if (work->usageContext == 1) {
        if (func_02028754(work->actionPermissions, 0)) {
            work->nextState = 0xB;
            func_021B6100(work, 0);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_IN_CONTEXT, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    }
    return 0;
}

/* Action 1 (give). */
u32 ITEMMENU_TryStartGive(ItemMenuWork *work)
{
    u32 started = 1;

    if (func_02028754(work->actionPermissions, 1)) {
        work->nextState = 7;
        func_021B6100(work, 0);
        return started;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 2 (register). */
u32 ITEMMENU_TryStartRegister(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 2)) {
        work->nextState = 8;
        func_021B6100(work, 0);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 6 (check). */
u32 ITEMMENU_TryStartCheck(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 6)) {
        work->nextState = 0x11;
        func_021B6100(work, 0);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 4 (toss): asks for a quantity first. */
u32 ITEMMENU_TryStartToss(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 4)) {
        work->nextState = 0xF;
        func_021B6100(work, 0);
        ITEMMENU_RemoveSelectedItems(work, 1);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 5 (sort). */
u32 ITEMMENU_TryStartSort(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 5)) {
        work->nextState = 0x10;
        func_021B6100(work, 0);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 9 (plant), only in usage context 0. */
u32 ITEMMENU_TryStartPlant(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (func_02028754(work->actionPermissions, 9)) {
            work->nextState = 0x14;
            func_021B6100(work, 0);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    }
    return 0;
}

/* Action 3 (sell): asks for a quantity first, only in usage context 0. */
u32 ITEMMENU_TryStartSell(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (func_02028754(work->actionPermissions, 3)) {
            work->nextState = 0xE;
            func_021B6100(work, 0);
            ITEMMENU_RemoveSelectedItems(work, 1);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    }
    return 0;
}

/*
 * Unlabelled leaf (push {r4,r5}, no lr) called twice by ITEMMENU_HandleActionMenuChoice:
 * finds the entry of the 8-entry range table at 0x021BB9C4 whose
 * [firstItemId, firstItemId + itemCount) holds itemId, or -1.
 */
int ITEMMENU_FindUseRange(u16 itemId)
{
    u32 i;
    const ItemUseRange *range;

    for (i = 0; i < 8; i++) {
        range = &gItemMenuUseRanges[i];
        if (itemId >= range->firstItemId && itemId < range->firstItemId + range->itemCount)
            return i;
    }
    return -1;
}










/*
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is gItemMenuUseRanges[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 */
void ITEMMENU_HandleActionMenuChoice(ItemMenuWork *work)
{
    int flag = 0;
    u32 x;
    int r;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (APP_TASKMENU_IsFinish(work->menuList)) {
        x = work->menuActionTable[APP_TASKMENU_GetCursorPos(work->menuList)];
        work->usageContext = x;
        switch (x) {
        case 0:
            ITEMMENU_SetBackButtonAnim(work, 0);
            if (work->currentPocket != 4)
                GAME_BEACON_SetItemUse(work->selectedItemId);
            if (work->currentPocket == 2) {
                func_021B6100(work, ITEMMENU_TaskUseNoticeMessage);
            } else if (func_02020FE4(work->selectedItemId, 0x1D, work->heapId) == 1) {
                work->nextState = 0xC;
                func_021B6100(work, 0);
            } else if (ITEMMENU_FindUseRange(work->selectedItemId) >= 0) {
                gItemMenuUseRanges[ITEMMENU_FindUseRange(work->selectedItemId)].useHandler(work);
            } else {
                r = ITEMMENU_GetFieldUseKind(work->selectedItemId);
                if (r == 1) {
                    func_021B6100(work, ITEMMENU_UseRepel);
                } else if (r == 2) {
                    func_021B6100(work, ITEMMENU_ShowKeyItemRefusal);
                } else {
                    work->nextState = 5;
                    func_021B6100(work, 0);
                }
            }
            break;
        case 1:
            ITEMMENU_SetBackButtonAnim(work, 0);
            if (func_02028754(work->actionPermissions, 0)) {
                work->nextState = 0xB;
                func_021B6100(work, 0);
            } else {
                func_02045CAC(work->msgBank, 0x39, work->tempString);
                func_0201F02C(work->wordSet, 0, work->myStatus);
                func_0201F250(work->wordSet, work->messageString, work->tempString);
                func_021B6100(work, ITEMMENU_ShowMessageThenWait);
            }
            break;
        case 3:
            func_021B6100(work, ITEMMENU_TaskTossAskQuantity);
            break;
        case 4:
        case 5:
            if (ITEMMENU_IsBrowseMode(work) == 1) {
                ITEMMENU_ToggleRegisteredItem(work, work->cursorRow);
                ITEMMENU_RedrawList(work);
                ITEMMENU_UpdateSideButtons(work, 1);
                func_0204B92C(work->cursorActor, 1);
                ITEMMENU_ReturnToBagMain(work);
            }
            break;
        case 2:
            ITEMMENU_SetBackButtonAnim(work, 0);
            if (work->selectedItemId >= 0x89 && work->selectedItemId <= 0x94) {
                work->nextState = 0x13;
                func_021B6100(work, 0);
            }
            break;
        case 8:
            if (func_020355C4() == 1)
                ITEMMENU_HideMoveInfo(work);
            ITEMMENU_SetCursorActive(work, func_020355C4() == 0);
            ITEMMENU_UpdateSideButtons(work, 1);
            func_0204B92C(work->cursorActor, 1);
            ITEMMENU_ReturnToBagMain(work);
            break;
        case 9:
            work->nextState = 1;
            func_021B6100(work, 0);
            break;
        case 6:
            work->nextState = 2;
            ITEMMENU_SetBackButtonAnim(work, 0);
            func_021B6100(work, 0);
            break;
        case 7:
            break;
        }
        flag = 1;
    }
    if (flag) {
        ITEMMENU_ClearMessageWindow(work);
        APP_TASKMENU_CloseMenu(work->menuList);
        work->menuList = 0;
    }
}









void ITEMMENU_TaskSelectItem(ItemMenuWork *work)
{
    u16 *p;
    int s;

    p = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    work->selectedItemId = 0;
    if (p != 0)
        work->selectedItemId = *p;
    s = work->bagMode;
    if (s == 2) {
        if (func_02020FE4(work->selectedItemId, 3, work->heapId) == 0 && PALANM_IsOutsideReservedIdRange(work->selectedItemId) == 1) {
            if (func_0202136C(work->selectedItemId) != 0)
                work->nextState = 0x12;
            else
                work->nextState = 3;
            func_021B6100(work, 0);
            return;
        }
        func_02045CAC(work->msgBank, 0x2F, work->tempString);
        ITEMMENU_RegisterItemName(work, 0, work->selectedItemId);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_UpdateSideButtons(work, 0);
        ITEMMENU_SetBackButtonAnim(work, 0);
        func_021B6100(work, ITEMMENU_TaskReturnToListAfterMessage);
    } else if (s == 5) {
        work->nextState = 1;
        func_021B6100(work, 0);
    } else if (s == 4) {
        func_021B6100(work, ITEMMENU_TaskGiveItem);
    } else {
        ITEMMENU_OpenActionMenu(work);
        ITEMMENU_ShowItemUseMessage(work, work->selectedItemId);
        ITEMMENU_ShowMessageDefault(work);
        func_0204B92C(work->cursorActor, 0);
        func_021B6100(work, ITEMMENU_HandleActionMenuChoice);
    }
}









void ITEMMENU_TaskBagMain(ItemMenuWork *work)
{
    unsigned int k;
    int v;

    if (func_0201C6B4(work->printSys) == 0)
        return;
    if (TOUCHPANEL_GetCont() == 0)
        work->isTouchActive = 0;
    BUTTON_MAN_UpdateSlots(work->taskSys);
    BLINK_PALANM_Update(work->blinkPalAnm);
    if (work->taskFn != (ItemMenuTaskFn)ITEMMENU_TaskBagMain)
        return;
    if (ITEMMENU_HandleScrollbarTouch(work) != 0) {
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        return;
    }
    if (work->isTouchActive == 1)
        return;
    if (func_020355C4() == 1) {
        k = func_020362DC();
        if (k == 0)
            return;
        if (ITEMMENU_GetItemCount(work) != 0) {
            if ((k & 0xC0A) == 0) {
                func_020061E4(0x548);
                ITEMMENU_DrawMoveInfo(work);
                ITEMMENU_SetCursorActive(work, 1);
                return;
            }
        } else {
            ITEMMENU_SetCursorActive(work, 1);
            if (k & 0xCD)
                return;
        }
    }
    if (func_020362DC() & 2) {
        work->nextState = 1;
        work->selectedItemId = 0;
        func_020355D8(0);
        ITEMMENU_StartSideButtonPress(work, 4, 0);
        return;
    }
    if (func_020362DC() & 0x400) {
        if (work->bagMode == 2)
            return;
        work->nextState = 0;
        work->selectedItemId = 0;
        func_020355D8(0);
        ITEMMENU_StartSideButtonPress(work, 3, 0);
        return;
    }
    if (func_020362DC() & 0x800) {
        if (ITEMMENU_IsBrowseMode(work) != 1)
            return;
        if (work->currentPocket == 4) {
            ITEMMENU_ToggleRegisteredItem(work, work->cursorRow);
            ITEMMENU_RedrawList(work);
        } else {
            ITEMMENU_TogglePocketSortFlag(work);
        }
        if (func_020355C4() != 1)
            return;
        ITEMMENU_DrawMoveInfo(work);
        ITEMMENU_SetCursorActive(work, 1);
        return;
    }
    if ((func_020362DC() & 8) && work->currentPocket != 2 && work->currentPocket != 3 && ITEMMENU_GetItemCount(work) > 1) {
        ITEMMENU_ShowInputGuardError(work);
        ITEMMENU_SetCursorActive(work, 1);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        func_021B6100(work, ITEMMENU_TaskInputGuardMessage);
        return;
    }
    if (func_020362DC() & 1) {
        if (ITEMMENU_GetItemCount(work) > 0) {
            func_021B6100(work, ITEMMENU_TaskSelectItemFlash);
            return;
        }
    } else if (func_020362DC() & 4) {
        if (work->currentPocket != 2 && work->currentPocket != 3 && ITEMMENU_GetItemCount(work) > 1) {
            func_02082BCC(work->items, 0, 0x4D8);
            func_02007CC8(work->bag, work->items, work->currentPocket, 1);
            CLACT_SetActorAnimSeq(work->selectorActor, 2);
            ITEMMENU_UpdateSideButtonsForMode(work, 0);
            work->usingWorkCopy = 1;
            ITEMMENU_ReturnToListInput(work);
        }
        return;
    } else if (ITEMMENU_HandleListKeys(work) != 0) {
        ITEMMENU_MoveCursorToRow(work);
        func_020061E4(0x548);
        ITEMMENU_RedrawList(work);
        return;
    }
    if (func_0203633C() & 0x10) {
        v = work->currentPocket;
        work->currentPocket = v + 1;
        if (work->currentPocket >= 5)
            work->currentPocket = 0;
        func_020355D8(0);
        ITEMMENU_StartPocketTabPress(work, v, 1, ITEMMENU_ReturnToBagMainAlias);
        return;
    }
    if (func_0203633C() & 0x20) {
        v = work->currentPocket;
        work->currentPocket = v - 1;
        if (work->currentPocket < 0)
            work->currentPocket = 4;
        func_020355D8(0);
        ITEMMENU_StartPocketTabPress(work, v, 0, ITEMMENU_ReturnToBagMainAlias);
    }
}








void ITEMMENU_TaskActionMenuInput(ItemMenuWork *work)
{
    if (APP_TASKMENU_IsFinish(work->menuList) == 0)
        return;
    if (APP_TASKMENU_GetCursorPos(work->menuList) == 0) {
        ITEMMENU_ClearMessageWindow(work);
        work->nextState = 6;
        func_021B6100(work, 0);
    } else {
        ITEMMENU_ClearMessageWindow(work);
        func_020414EC(3);
        func_0204B92C(work->cursorActor, 1);
        ITEMMENU_UpdateSideButtons(work, 1);
        if (func_020355C4() == 1) {
            ITEMMENU_HideMoveInfo(work);
            ITEMMENU_SetCursorActive(work, 0);
        } else {
            ITEMMENU_SetCursorActive(work, 1);
        }
        ITEMMENU_ReturnToBagMain(work);
    }
    ITEMMENU_CloseYesNoList(work);
}







void ITEMMENU_TaskOpenActionMenu(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) { ITEMMENU_OpenYesNoList(work); func_021B6100(work,ITEMMENU_TaskActionMenuInput); } }








void ITEMMENU_TaskRegisterResultMessage(ItemMenuWork *work)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    func_02045CAC(work->msgBank, 0x3E, work->tempString);
    func_0201EF34(work->wordSet, 0, func_020212B0(work->selectedItemId));
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessage(work, 1);
    func_021B6100(work, ITEMMENU_TaskOpenActionMenu);
}







void ITEMMENU_TaskStartRegisterResult(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) { func_020061E4(0x55C); func_021B6100(work,ITEMMENU_TaskRegisterResultMessage); } }







void ITEMMENU_TaskUseNoticeMessage(ItemMenuWork *work)
{
    if (func_02021350(work->selectedItemId) == 0xFF)
        func_02045CAC(work->msgBank, 0x3C, work->messageString);
    else
        func_02045CAC(work->msgBank, 0x3D, work->messageString);
    ITEMMENU_ShowMessage(work, 1);
    func_021B6100(work, ITEMMENU_TaskStartRegisterResult);
}







void ITEMMENU_TaskReturnToListAfterMessage(ItemMenuWork *work)
{
    if ((func_020362DC() & 3) || TOUCHPANEL_GetTrg() != 0) {
        func_020414EC(3);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        work->listDirty = 1;
        ITEMMENU_MoveCursorToRow(work);
        func_0204B92C(work->cursorActor, 1);
        ITEMMENU_UpdateSideButtons(work, 1);
        ITEMMENU_ReturnToBagMain(work);
    }
}






void ITEMMENU_TaskBeginReturnToList(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) func_021B6100(work,ITEMMENU_TaskReturnToListAfterMessage); }







void ITEMMENU_TaskTossConfirmInput(ItemMenuWork *work)
{
    int r;
    int v;

    if (APP_TASKMENU_IsFinish(work->menuList) == 0)
        return;
    r = APP_TASKMENU_GetCursorPos(work->menuList);
    ITEMMENU_CloseYesNoList(work);
    func_020414EC(3);
    if (r == 0) {
        func_020061E4(0x647);
        ITEMMENU_RemoveSelectedItems(work, work->listCount);
        func_02045CAC(work->msgBank, 0x36, work->tempString);
        ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, work->listCount > 1, 0);
        func_0201EFA4(work->wordSet, 1, work->listCount, 3, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        func_021B6100(work, ITEMMENU_TaskBeginReturnToList);
    } else {
        func_0204B92C(work->cursorActor, 1);
        v = 1;
        ITEMMENU_UpdateSideButtons(work, 1);
        if (func_020355C4() != 0)
            v = 0;
        ITEMMENU_SetCursorActive(work, v);
        ITEMMENU_ReturnToBagMain(work);
    }
}






void ITEMMENU_TaskOpenTossConfirm(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) { ITEMMENU_OpenYesNoList(work); func_021B6100(work,ITEMMENU_TaskTossConfirmInput); } }







void ITEMMENU_TaskTossAskQuantity(ItemMenuWork *work)
{
    work->listCount = 1;
    ITEMMENU_ShowQuantityWindows(work, 1);
    func_02045CAC(work->msgBank, 0x35, work->tempString);
    ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, 1, 0);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessageDefault(work);
    func_021B6100(work, ITEMMENU_TaskTossQuantityInput);
}







void ITEMMENU_TaskTossQuantityInput(ItemMenuWork *work)
{
    int r;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (ITEMMENU_HandleQuantityInput(work) == 1)
        return;
    r = ITEMMENU_CheckTouchRelease();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        ITEMMENU_HideQuantityWindows(work);
        func_02045CAC(work->msgBank, 0x37, work->tempString);
        ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, work->listCount > 1, 0);
        func_0201EFA4(work->wordSet, 1, work->listCount, 3, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        func_021B6100(work, ITEMMENU_TaskOpenTossConfirm);
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskReopenListFromQuantity);
    }
}







void ITEMMENU_TaskGiveItem(ItemMenuWork *work)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C(work->cursorActor, 0);
    a = func_02020FE4(work->selectedItemId, 0, (u32)work->heapId);
    b = func_02020FE4(work->selectedItemId, 3, (u32)work->heapId);
    if (a == 0 || b != 0) {
        ITEMMENU_UpdateSideButtons(work, 0);
        func_02045CAC(work->msgBank, 0x4D, work->tempString);
        ITEMMENU_RegisterItemName(work, 0, work->selectedItemId);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_SetBackButtonAnim(work, 0);
        func_021B6100(work, ITEMMENU_TaskWaitMessageDismiss);
        return;
    }
    work->listCount = 1;
    ITEMMENU_EnterQuantityMode(work);
    ITEMMENU_UpdateSideButtons(work, 0);
    if (ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work))->count == 1) {
        func_021B6100(work, ITEMMENU_TaskSellAskConfirm);
        return;
    }
    ITEMMENU_ShowQuantityWindows(work, 2);
    func_02045CAC(work->msgBank, 0x4E, work->tempString);
    ITEMMENU_RegisterItemName(work, 0, work->selectedItemId);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessageDefault(work);
    func_021B6100(work, ITEMMENU_TaskSellQuantityInput);
}







void ITEMMENU_TaskSellQuantityInput(ItemMenuWork *work)
{
    int r;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (ITEMMENU_HandleQuantityInput(work) == 1)
        return;
    r = ITEMMENU_CheckTouchRelease();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        ITEMMENU_HideQuantityWindows(work);
        func_021B6100(work, ITEMMENU_TaskSellAskConfirm);
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskReturnFromQuantity);
    }
}







void ITEMMENU_TaskSellAskConfirm(ItemMenuWork *work)
{
    int v;

    ITEMMENU_OpenYesNoList(work);
    v = ITEMMENU_GetSellTotal(work->selectedItemId, work->listCount, work->heapId);
    func_02045CAC(work->msgBank, 0x4F, work->tempString);
    func_0201EFA4(work->wordSet, 0, v, 7, 0, 1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessageDefault(work);
    func_021B6100(work, ITEMMENU_TaskSellConfirmInput);
}






void ITEMMENU_TaskSellConfirmInput(ItemMenuWork *work)
{
    int r;
    int v;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (APP_TASKMENU_IsFinish(work->menuList) == 0)
        return;
    r = APP_TASKMENU_GetCursorPos(work->menuList);
    ITEMMENU_CloseYesNoList(work);
    switch (r) {
    case 0:
        v = ITEMMENU_GetSellTotal(work->selectedItemId, work->listCount, work->heapId);
        ITEMMENU_RemoveSelectedItems(work, work->listCount);
        func_0200C278((struct Blk34 *)((unsigned int)GAME_DATA_GetMiscSave(work->saveData)), v);
        func_020061E4(0x655);
        ITEMMENU_PrintMoney(work);
        func_02045CAC(work->msgBank, 0x50, work->tempString);
        ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, work->listCount > 1, 0);
        func_0201EFA4(work->wordSet, 1, v, 7, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        func_021B6100(work, ITEMMENU_TaskWaitMessageDismiss);
        break;
    case 1:
        ITEMMENU_SetCursorActive(work, func_020355C4() == 0);
        func_021B6100(work, ITEMMENU_TaskReturnToListFromQuantity);
        break;
    }
}






void ITEMMENU_TaskWaitMessageDismiss(ItemMenuWork *work)
{
    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (func_020362DC() & 3) {
        ITEMMENU_SetCursorActive(work, 1);
        func_021B6100(work, ITEMMENU_TaskReturnToListFromQuantity);
        return;
    }
    if (TOUCHPANEL_GetTrg() != 0) {
        ITEMMENU_SetCursorActive(work, 0);
        func_021B6100(work, ITEMMENU_TaskReturnToListFromQuantity);
    }
}







void ITEMMENU_TaskReturnToListFromQuantity(ItemMenuWork *work)
{
    func_020414EC(3);
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    work->listDirty = 1;
    ITEMMENU_MoveCursorToRow(work);
    ITEMMENU_LeaveQuantityMode(work);
    func_0204B92C(work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}







void ITEMMENU_RemoveSelectedItems(ItemMenuWork *work, int x)
{
    int v;

    ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    func_02007F1C(work->bag, work->selectedItemId, x, work->heapId);
    if (func_02007FB8(work->bag, work->selectedItemId, work->heapId) != 0)
        return;
    if (ITEMMENU_GetItemCount(work) + 1 < 7) {
        v = work->cursorRow - 1;
        if (v <= 0)
            v = 0;
        work->cursorRow = v;
    } else {
        v = work->scrollOffset - 1;
        if (v < -1)
            v = -1;
        work->scrollOffset = v;
    }
}





void ITEMMENU_ShowQuantityWindows(ItemMenuWork *work, int v) { work->listMode=v; ITEMMENU_LoadSellPalette(work); ITEMMENU_PrintQuantityPrice(work,work->listCount); func_0204B3DC(work->listWindowA, 1); func_0204B3DC(work->listWindowB, 1); }





void ITEMMENU_HideQuantityWindows(ItemMenuWork *work) { func_020414EC(3); func_0204B3DC(work->listWindowA, 0); func_0204B3DC(work->listWindowB, 0); }






/*
 * Quantity selector input: touch buttons (hit table d_021BB960, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 */
int ITEMMENU_HandleQuantityInput(ItemMenuWork *work)
{
    HitTbl tbl;
    Item *e;
    int saved;
    int hit;
    int changed;
    int dir;

    changed = 0;
    saved = work->listCount;
    e = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    tbl = d_021BB960;
    hit = TOUCHPANEL_HitCont(&tbl);
    if (hit != -1) {
        work->repeatCount++;
        changed = 1;
    } else {
        work->repeatCount = 0;
    }
    if (work->repeatCount == 1 || work->repeatCount > 30) {
        switch (hit) {
        case 0:
            if (work->repeatCount > 120)
                work->listCount += 10;
            else
                work->listCount += 1;
            dir = 0;
            break;
        case 1:
            if (work->repeatCount > 120)
                work->listCount -= 10;
            else
                work->listCount -= 1;
            dir = 1;
            break;
        }
    }
    if (hit == -1) {
        if (func_0203633C() & 0x40) {
            work->listCount += 1;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x80) {
            work->listCount -= 1;
            dir = 1;
            changed = 1;
        } else if (func_0203633C() & 0x10) {
            work->listCount += 10;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x20) {
            work->listCount -= 10;
            dir = 1;
            changed = 1;
        }
    }
    if (e->count < work->listCount)
        work->listCount = 1;
    else if (work->listCount < 1)
        work->listCount = e->count;
    if (work->listCount != saved) {
        func_020061E4(0x548);
        if (dir == 0)
            CLACT_SetActorAnimSeq(work->listWindowA, 0xB);
        else
            CLACT_SetActorAnimSeq(work->listWindowB, 0xA);
        ITEMMENU_PrintQuantityPrice(work, work->listCount);
    }
    return changed;
}






int ITEMMENU_CompareSortEntries(Ent *a, Ent *b)
{
    if (a->key == b->key)
        return 0;
    if (a->key > b->key)
        return 1;
    return -1;
}






void ITEMMENU_SortPocket(ItemMenuWork *work)
{
    int i;
    Ent *ents;
    Item *items;
    int n;
    int h;
    int rec;
    u32 x;
    Ent *e;

    ents = func_02030734(work->heapId, 0x9B0, 0, d_021BBBC0, 0xB35);
    items = func_02030734(work->heapId, 0x4D8, 0, d_021BBBC0, 0xB36);
    MYITEM_SAVEDATA_CopyPocket(work->bag, items, (u32)work->currentPocket, 1);
    n = ITEMMENU_GetItemCount(work);
    h = (int)func_02020F14(work->heapId);
    for (i = 0; i < n; i++) {
        rec = func_02020F20(h, items[i].id, work->heapId);
        e = &ents[i];
        x = func_02021014((struct Rec *)rec, 0xF);
        e->key = (x << 28) + (func_02021014((struct Rec *)rec, 0x11) << 16) + items[i].id;
        e->item = items[i];
        func_020307B0((void *)rec);
    }
    ARC_TOOL_DeleteHandle((void *)h);
    MATH_QSort(ents, n, 8, ITEMMENU_CompareSortEntries, 0);
    for (i = 0; i < n; i++) {
        items[i] = ents[i].item;
    }
    MYITEM_SAVEDATA_CopyPocket(work->bag, items, (u32)work->currentPocket, 0);
    func_020307B0(items);
    func_020307B0(ents);
}





void ITEMMENU_ShowInputGuardError(ItemMenuWork *work) { func_020061E4(0x663); CLACT_SetActorAnimSeq(((work->inputGuard)), 2); }





void ITEMMENU_SortAndRedraw(ItemMenuWork *work) { ITEMMENU_SortPocket(work); work->shownItemId=0xFFFF; ITEMMENU_RedrawList(work); }





void ITEMMENU_RefreshInputGuard(ItemMenuWork *work)
{
    ITEMMENU_UpdateInputGuardAnim(work);
}






void ITEMMENU_SetCursorActive(ItemMenuWork *work, int flag)
{
    if (work->usingWorkCopy == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (ITEMMENU_GetItemCount(work) == 0)
        flag = 0;
    if (flag == 0) {
        ITEMMENU_UpdateSlotActorPosition(work, 0);
    } else {
        ITEMMENU_UpdateSlotActorPosition(work, 1);
        BLINK_PALANM_ResetPhase(work->blinkPalAnm);
    }
    ITEMMENU_SetMoveTypeIconsVisible(work, flag);
}





int ITEMMENU_IsBrowseMode(ItemMenuWork *work) { int v = work->bagMode; if (v==0 || v==1 || v==3) return 1; return 0; }






int ITEMMENU_ToggleRegisteredItem(ItemMenuWork *work, int k)
{
    u16 *p;
    int v;

    k += work->scrollOffset + 1;
    if (work->currentPocket == 4) {
        if (ITEMMENU_GetItemCount(work) <= k)
            return 0;
        p = (void *)ITEMMENU_GetSlot(work, k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (ITEMMENU_IsItemRegistered(work, *p) == 1)
            GAME_DATA_SetSaveFlag(work->saveData, v, 0);
        else
            GAME_DATA_SetSaveFlag(work->saveData, v, 1);
        func_020061E4(0x646);
        work->shownItemId = 0xFFFF;
        return 1;
    }
    return 0;
}





int ITEMMENU_GetPocketSortFlag(int x)
{
    int ITEMMENU_PocketToSortFlag(int);
    return ITEMMENU_PocketToSortFlag(x);
}





void ITEMMENU_TogglePocketSortFlag(ItemMenuWork *work) { int a; int v; a=ITEMMENU_GetPocketSortFlag(work->currentPocket); v=GAME_DATA_CheckSaveFlag(work->saveData,a); GAME_DATA_SetSaveFlag(work->saveData,a,v^1); func_020061E4(0x646); ITEMMENU_UpdatePocketSortIcon(work); }





void ITEMMENU_UpdatePocketSortIcon(ItemMenuWork *work) { if (work->usingWorkCopy!=1) CLACT_SetActorAnimSeq(((work->sideActor[2])), (unsigned int)GAME_DATA_CheckSaveFlag(work->saveData,ITEMMENU_GetPocketSortFlag(work->currentPocket))+6u); }






void ITEMMENU_CheckItemFilter(ItemMenuWork *work, void *rec, u16 *p, u8 *out)
{
    if (func_02021014(rec, 6) != 0) {
        if (func_0202136C(*p) == 1)
            *out = 2;
        else if (*p == 0x1C2 && work->bagFilter == 1)
            *out = 1;
        else
            *out = 0;
    }
    if ((u16)(*p + 0xFD98) <= 1)
        *out = 0;
}





void ITEMMENU_BuildActionList(ItemMenuWork *work, unsigned char *q)
{
    unsigned short *e = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    if (e != 0 && *e != 0) {
        void *h = func_02020F34(*e, 0, work->heapId);
        unsigned char v = work->currentPocket;
        ITEMMENU_CheckItemFilter(work, h, e, q);
        if (ITEMMENU_IsCheckModeAllowed(work, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (func_02021014(h, 3) == 0) {
            if (PALANM_IsOutsideReservedIdRange(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (func_02021014(h, 4) != 0) {
            if (ITEMMENU_IsItemRegistered(work, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}




/*
 * lever: ITEMMENU_OpenPopupList reads the count in r2; passing j keeps it in r2.
 */
void ITEMMENU_OpenActionMenu(ItemMenuWork *work)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    ITEMMENU_BuildActionList(work, (unsigned char *)(&a));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            work->menuActionTable[j] = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    ITEMMENU_OpenPopupList(work, tmp, j);
}




int ITEMMENU_IsItemRegistered(ItemMenuWork *work, int value)
{
    return GAME_DATA_CheckSaveFlag(work->saveData, (int)func_0202E448((u16)value));
}





/*
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of ITEMMENU_TaskBagMain's key handling.
 */
void ITEMMENU_HandleTouchTarget(u32 idx, int flag, ItemMenuWork *work)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = ITEMMENU_GetItemCount(work);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (work->currentPocket != t.v[idx]) {
            tab = t.v[idx];
            ITEMMENU_SetCursorActive(work, 0);
        }
    } else if (idx == 5) {
        ITEMMENU_SetCursorActive(work, 0);
        v = work->currentPocket;
        work->currentPocket = v - 1;
        if (work->currentPocket < 0)
            work->currentPocket = 4;
        ITEMMENU_StartPocketTabPress(work, v, 0, ITEMMENU_ReturnToBagMainAlias);
        return;
    } else if (idx == 6) {
        ITEMMENU_SetCursorActive(work, 0);
        v = work->currentPocket;
        work->currentPocket = v + 1;
        if (work->currentPocket >= 5)
            work->currentPocket = 0;
        ITEMMENU_StartPocketTabPress(work, v, 1, ITEMMENU_ReturnToBagMainAlias);
        return;
    } else if (idx == 7) {
        if (work->currentPocket != 2 && work->currentPocket != 3 && ITEMMENU_GetItemCount(work) > 1) {
            ITEMMENU_ShowInputGuardError(work);
            ITEMMENU_SetCursorActive(work, 0);
            work->shownItemId = 0xFFFF;
            ITEMMENU_RedrawList(work);
            func_021B6100(work, ITEMMENU_TaskInputGuardMessage);
        }
    } else if (idx == 8) {
        if (ITEMMENU_IsBrowseMode(work) == 1) {
            ITEMMENU_TogglePocketSortFlag(work);
            ITEMMENU_SetCursorActive(work, 0);
            work->shownItemId = 0xFFFF;
            ITEMMENU_RedrawList(work);
        }
    } else if (idx == 9) {
        if (work->bagMode != 2) {
            work->nextState = 0;
            work->selectedItemId = 0;
            ITEMMENU_StartSideButtonPress(work, 3, 0);
            func_020355D8(1);
        }
    } else if (idx == 10) {
        work->nextState = 1;
        work->selectedItemId = 0;
        ITEMMENU_StartSideButtonPress(work, 4, 0);
        func_020355D8(1);
    } else if (idx >= 11 && idx < 17) {
        if (work->taskFn != (ItemMenuTaskFn)ITEMMENU_TaskBagMain)
            return;
        saved = work->cursorRow;
        cur = ITEMMENU_GetCursorIndex(work);
        if (ITEMMENU_GetItemCount(work) == 0)
            return;
        if (work->cursorRow != idx - 11) {
            work->cursorRow = idx - 11;
            if (count <= ITEMMENU_GetCursorIndex(work)) {
                work->cursorRow = saved;
                return;
            }
        }
        ITEMMENU_MoveSlot(work, cur, ITEMMENU_GetCursorIndex(work));
        ITEMMENU_SetCursorActive(work, 0);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_DrawMoveInfo(work);
        func_021B6100(work, ITEMMENU_TaskSelectItemFlash);
        return;
    } else if (idx >= 17) {
        if (ITEMMENU_IsBrowseMode(work) == 1 && ITEMMENU_ToggleRegisteredItem(work, idx - 17) == 1) {
            ITEMMENU_SetCursorActive(work, 0);
            ITEMMENU_RedrawList(work);
        }
    }
    if (tab != -1) {
        v = work->currentPocket;
        work->currentPocket = tab;
        func_020061E4(0x7D9);
        ITEMMENU_SwitchPocketCursor(work, v, work->currentPocket);
        ITEMMENU_RefreshInputGuard(work);
        ITEMMENU_SetCursorActive(work, 0);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
    }
}





void ITEMMENU_VBlankCallback(int u, ItemMenuWork *work)
{
    int s = work->screenState;
    if (s == 1) {
        ITEMMENU_SetLayersVisible(work, 1);
        work->screenState = 0;
    } else if (s == 2) {
        ITEMMENU_SetLayersVisible(work, 0);
        work->screenState = 0;
    }
    PALANM_TransferPalettes((struct S02021D50 *)((int)work->palAnmSlot));
    CLACT_VBlankSystem();
}





void ITEMMENU_TaskStartFadeIn(ItemMenuWork *work)
{
    if (func_0201C6B4((const struct PrintSys *)(work->printSys))) {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, work->heapId);
        func_020061E4(0x79F);
        func_021B6100(work, ITEMMENU_TaskWaitFadeIn);
    }
}





/*
 * blocked:
 */
void ITEMMENU_TaskWaitFadeIn(ItemMenuWork *work)
{
    int a = WIPE_SYS_EndCheck();
    int b = ITEMMENU_MoveActorToPoint((const char *)work);
    if (a == 1 && b == 0) {
        func_0204B92C(work->cursorActor, 1);
        ITEMMENU_ReturnToBagMain(work);
    }
}


int ITEMMENU_Init(void *proc, int st, ItemMenuArgs *a)
{
    ItemMenuWork *work; u16 i; s16 scr, cur;
    GFL_HEAP_CreateChildHeap(1, 0xe, 0x34000);
    work = PROCSYS_AllocProcWork(proc, 0x874, 0xe);
    func_02082BCC(work, 0, 0x874);
    KEY_GetRepeatSpeed(&work->keyRepeatDelay, &work->keyRepeatInterval);
    work->heapId = 0xe;
    work->currentPage = 1;
    work->saveData = a->saveData; work->myStatus = a->myStatus; work->optionsSave = a->optionsSave;
    work->bagCursor = a->bagCursor; work->bag = a->bag;
    work->actionPermissions = a->actionPermissions;
    work->bagMode = a->bagMode; work->bagFilter = a->bagFilter;
    func_0200816C(work->bag, work->bagFilter);
    work->currentPocket = func_02008284(work->bagCursor);
    for (i = 0; i < 5; i++) {
        int n;
        func_02008270(work->bagCursor, i, &scr, &cur);
        n = (u16)func_02007FA0(work->bag, i);
        for (;;) {
            if (scr == 0 && cur == 0) break;
            if (cur + 5 >= n && cur != 0) { cur--; continue; }
            if (scr + cur < n) break;
            if (cur != 0) cur--; else scr--;
        }
        if (i == work->currentPocket) { work->cursorRow = scr; work->scrollOffset = cur - 1; }
        func_02008288(work->bagCursor, i, scr, cur);
    }
    work->msgBank = func_02045B38(0, 2, 3, work->heapId);
    work->tempString = STRBUF_Create(0xc8, work->heapId);
    work->messageString = STRBUF_Create(0xc8, work->heapId);
    work->listStrings = STRBUF_Create(0x40, work->heapId);
    work->wordSet = func_0201EC64(work->heapId);
    work->printSys = func_0201C450(0x40 << 6, work->heapId);
    work->itemDescWindow = func_02028590(0xf, 1, 1, work->heapId);
    work->menuTaskArg = GF_FONT_Create(0x17, 0, 0, 0, work->heapId);
    ITEMMENU_SetupGraphics(work);
    ITEMMENU_InitWindows(work);
    ITEMMENU_LoadPocketGraphics(work);
    ITEMMENU_CreateTabActors(work);
    func_021B6120(work);
    ITEMMENU_CreateCursorActors(work);
    work->taskSys = BUTTON_MAN_Create(d_021BBA04, ITEMMENU_HandleTouchTarget, work, work->heapId);
    ITEMMENU_CreateBlinkPalAnm(work);
    ITEMMENU_AllocPalAnmSlots(work);
    work->unitList = func_020056A0(ITEMMENU_VBlankCallback, work, 0);
    work->touchTask = TCBL_Create(work->heapId, work->heapId, 1, 0);
    ITEMMENU_PrintPocketName(work);
    work->taskMenuState = APP_TASKMENU_RES_Create(3, 9, work->menuTaskArg, work->printSys, work->heapId);
    GFL_NET_RestartWithDefaultTimeout(1, work->heapId);
    ITEMMENU_SetCursorActive(work, func_020355C4() ? 0 : 1);
    ITEMMENU_ResetDisplayLayers();
    func_021B6100(work, ITEMMENU_TaskStartFadeIn);
    return 1;
}


int ITEMMENU_Main(int a, int b, int c, ItemMenuWork *work)
{
    ItemMenuTaskFn fn = work->taskFn;
    if (fn == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
        return 1;
    }
    work->shownItemId = work->scrollOffset;
    fn(work);
    if (work->listDirty != 0) {
        ITEMMENU_SnapSelectorToCursor(work);
        work->listDirty = 0;
    }
    if (work->busyCount != 0) {
        ITEMMENU_UploadSlotGraphics(work);
        work->busyCount = 0;
    }
    ITEMMENU_FreeActionMenuResources(work);
    ITEMMENU_FlushDirtyWindows(work);
    TCBL_Main((struct Tcbl *)(work->touchTask));
    return 0;
}








int ITEMMENU_Exit(void *proc, int b, Parent *par, ItemMenuWork *work)
{
    if (WIPE_SYS_EndCheck() != 1)
        return 0;
    if (func_0201C6B4((const struct PrintSys *)work->printSys) == 0)
        return 0;
    func_02030EAC((struct Node *)work->unitList);
    func_02008298(work->bagCursor, work->currentPocket);
    func_02008288(work->bagCursor, (u16)work->currentPocket, work->cursorRow, work->scrollOffset + 1);
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(u32)work->taskMenuState);
    ITEMMENU_FreeGraphics(work);
    ITEMMENU_ApplyBgPalettes(work);
    TCBL_Destroy((struct S02031140 *)(u32)work->touchTask);
    MSGDATA_Delete((struct Rec *)(u32)work->msgBank);
    STRBUF_Delete(work->tempString);
    STRBUF_Delete(work->messageString);
    STRBUF_Delete(work->listStrings);
    func_0201ED04(work->wordSet);
    ITEMMENU_HideSideWindows(work);
    if ((u32)work->messageWindows[0].window != 0) {
        func_0203FB44((int)3, (unsigned short)work->keyRepeatPacked, (unsigned short)(work->keyRepeatPacked >> 16));
        func_020452E8((struct Descriptor *)(u32)work->messageWindows[0].window);
    }
    func_02040DA8(3, 1, 0);
    GF_FONT_Delete((void *)work->menuTaskArg);
    APP_KEYCURSOR_Delete(work->itemDescWindow);
    func_0201C6EC(work->printSys);
    func_0201C4C0(work->printSys);
    ITEMMENU_FreePalAnmSlots(work);
    ITEMMENU_DeleteBlinkPalAnm(work);
    BUTTON_MAN_Delete((void *)(u32)work->taskSys);
    BMP_WIN_Exit();
    func_0203F9B4();
    par->f34 = (u32)work->nextState;
    par->f38 = work->selectedItemId;
    KEY_SetRepeatSpeed(work->keyRepeatDelay, work->keyRepeatInterval);
    func_020315D4(proc);
    func_020306F0(0xE);
    return 1;
}







void ITEMMENU_ReturnToBagMain(ItemMenuWork *work)
{
    func_021B6100(work, ITEMMENU_TaskBagMain);
    KEY_SetRepeatSpeed(3, 6);
}







int ITEMMENU_ReturnToListInput(ItemMenuWork *work)
{
    func_021B6100(work, ITEMMENU_TaskListInput);
    return KEY_SetRepeatSpeed(3, 6);
}








void ITEMMENU_CreateBlinkPalAnm(ItemMenuWork *work)
{
    void *h;
    *(struct BlinkPalAnm * *)&work->blinkPalAnm =
        BLINK_PALANM_Create(0x10, 0x10, 0xFFFE, work->heapId);
    h = func_020490F4(0x58, work->heapId);
    BLINK_PALANM_LoadPalettes(*(struct BlinkPalAnm * *)&work->blinkPalAnm, h, 0x15, 0x10, 0x20);
    ARC_TOOL_DeleteHandle(h);
}







void ITEMMENU_DeleteBlinkPalAnm(ItemMenuWork *work)
{
    func_0202EA20(*(struct BlinkPalAnm * *)&work->blinkPalAnm);
}








void ITEMMENU_TaskSelectItemFlash(ItemMenuWork *work)
{
    switch (work->fadeStep) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        ITEMMENU_UpdateSlotActorPosition(work, 0);
        work->fadeStep += 1;
        return;
    case 1:
    case 4:
    case 6:
        work->fadeTimer += 1;
        if (work->fadeTimer == 4) {
            work->fadeTimer = 0;
            work->fadeStep += 1;
        }
        return;
    case 2:
    case 5:
        ITEMMENU_UpdateSlotActorPosition(work, 2);
        work->fadeStep += 1;
        return;
    case 7:
        work->fadeStep = 0;
        ITEMMENU_UpdateSlotActorPosition(work, 1);
        BLINK_PALANM_ResetPhase(work->blinkPalAnm);
        BLINK_PALANM_Update(work->blinkPalAnm);
        func_021B6100(work, ITEMMENU_TaskSelectItem);
        return;
    }
}








void ITEMMENU_StartSideButtonPress(ItemMenuWork *work, int a, ItemMenuTaskFn callback)
{
    int x;
    if (a == 4) {
        func_020061E4(0x551);
        x = 9;
    } else if (a == 3) {
        func_020061E4(0x556);
        x = 8;
    } else if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    work->fadeStep = a;
    CLACT_SetActorAnimFrame(work->sideActor[work->fadeStep], 0);
    CLACT_SetActorAnimSeq(work->sideActor[work->fadeStep], (unsigned short)x);
    func_0204B92C(work->sideActor[work->fadeStep], 1);
    work->fadeCallback = callback;
    func_021B6100(work, ITEMMENU_TaskWaitSideButtonPress);
}







void ITEMMENU_TaskWaitSideButtonPress(ItemMenuWork *work)
{
    if (CLACT_IsActorAnimActive(work->sideActor[work->fadeStep]) == 0) {
        work->fadeStep = 0;
        func_021B6100(work, work->fadeCallback);
    }
}








void ITEMMENU_StartPocketTabPress(ItemMenuWork *work, int u, int a, ItemMenuTaskFn callback)
{
    int x;
    ITEMMENU_SwitchPocketCursor(work, u, work->currentPocket);
    ITEMMENU_RefreshInputGuard(work);
    ITEMMENU_UpdatePocketSortIcon(work);
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    work->fadeStep = a;
    work->fadeTimer = 6;
    CLACT_SetActorAnimFrame(work->sideActor[work->fadeStep], 0);
    CLACT_SetActorAnimSeq(work->sideActor[work->fadeStep], (unsigned short)x);
    func_0204B92C(work->sideActor[work->fadeStep], 1);
    work->fadeCallback = callback;
    func_021B6100(work, ITEMMENU_TaskWaitPocketTabPress);
}







void ITEMMENU_TaskWaitPocketTabPress(ItemMenuWork *work)
{
    if (work->fadeTimer == 0) {
        work->fadeStep = 0;
        func_021B6100(work, work->fadeCallback);
    } else {
        work->fadeTimer -= 1;
    }
}







/*
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 */
int ITEMMENU_CheckTouchRelease(void)
{
    int result;
    result = TOUCHPANEL_HitTrg(d_021BB978);
    if (result != -1)
        func_020355D8(1);
    return result;
}







void ITEMMENU_TaskReopenListFromQuantity(ItemMenuWork *work)
{
    int flag;
    ITEMMENU_HideQuantityWindows(work);
    func_0204B92C(work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    flag = 1;
    if (func_020355C4())
        flag = 0;
    ITEMMENU_SetCursorActive(work, flag);
    ITEMMENU_ReturnToBagMain(work);
}








void ITEMMENU_TaskReturnFromQuantity(ItemMenuWork *work)
{
    int f;
    ITEMMENU_HideQuantityWindows(work);
    func_0204B92C(work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    f = 1;
    if (func_020355C4()) {
        f = 0;
    }
    ITEMMENU_SetCursorActive(work, f);
    func_021B6100(work, ITEMMENU_TaskReturnToListFromQuantity);
}







void ITEMMENU_AllocPalAnmSlots(ItemMenuWork *work)
{
    work->palAnmSlot = PALANM_Create(work->heapId);
    PALANM_AllocSlotBuffers(work->palAnmSlot, 2, 0x200, work->heapId);
    PALANM_AllocSlotBuffers(work->palAnmSlot, 0, 0x20, work->heapId);
    PALANM_CopyHwPaletteToSlot(work->palAnmSlot, 0, 0, 0x20);
}







/*
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 */
void ITEMMENU_FreePalAnmSlots(ItemMenuWork *work)
{
    PALANM_FreeSlotBuffers(work->palAnmSlot, 0);
    PALANM_FreeSlotBuffers(work->palAnmSlot, 2);
    PALANM_Delete(work->palAnmSlot);
}








void ITEMMENU_TaskInputGuardMessage(ItemMenuWork *work)
{
    if (CLACT_IsActorAnimActive(work->inputGuard) == 0) {
        CLACT_SetActorAnimSeq(work->inputGuard, 0);
        ITEMMENU_SortAndRedraw(work);
        func_0204B92C(work->cursorActor, 0);
        func_02045CAC(work->msgBank, 0x8A, work->messageString);
        ITEMMENU_ShowMessage(work, 0);
        ITEMMENU_SetBackButtonAnim(work, 0);
        ITEMMENU_UpdateSideButtons(work, 0);
        func_021B6100(work, ITEMMENU_TaskWaitMessageThenList);
    }
}








void ITEMMENU_TaskWaitMessageThenList(ItemMenuWork *work)
{
    if (func_020362DC() & 3) {
        ITEMMENU_SetCursorActive(work, 1);
    } else if (TOUCHPANEL_GetTrg()) {
        ITEMMENU_SetCursorActive(work, 0);
    } else {
        return;
    }
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    ITEMMENU_ClearMessageWindow(work);
    func_0204B92C(work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}







int ITEMMENU_IsCheckModeAllowed(ItemMenuWork *work, int value)
{
    if (work->bagMode == 3 || work->bagMode == 1)
        return 0;
    if (func_02012B70((const struct BigObj *)(work->saveData)) == 1 && value == 4)
        return 0;
    return 1;
}








/*
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after ITEMMENU_IsCheckModeAllowed;
 * installed as a callback by ITEMMENU_TaskBagMain and at 0x021B85E0.
 */
void ITEMMENU_ReturnToBagMainAlias(ItemMenuWork *work)
{
    ITEMMENU_ReturnToBagMain(work);
}








static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                          (sel << REG_GX_POWCNT_DSEL_SHIFT));
}








/*
 * BG setup: GX_SetDispSelect(0), then seven 32-byte BG templates copied
 * to the stack and handed to func_0203FCA0 for BGs 0-6, each followed by
 * its clear/enable calls.
 *
 * volatile: 0x04000304 (POWCNT1, read-modify-write at 0x021B8FA0/0x021B8FA8)
 */
void ITEMMENU_InitDisplayBanks(void)
{
    BgTemplate t0;
    BgTemplate t1;
    BgTemplate t2;
    BgTemplate t3;
    BgTemplate t4;
    BgTemplate t5;
    BgTemplate t6;

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    t0 = d_021BBB40;
    func_0203FCA0(0, &t0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 0);

    t1 = d_021BBB60;
    func_0203FCA0(1, &t1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 0);

    t2 = d_021BBB80;
    func_0203FCA0(2, &t2, 0);
    func_020414AC(2);
    func_020409B4(2);
    func_02040588(2, 0);

    t3 = d_021BBB20;
    func_0203FCA0(3, &t3, 0);
    func_02040C14(3, 0, 1, 0);
    func_020414AC(3);
    func_020409B4(3);
    func_02040588(3, 0);

    t4 = d_021BBAC0;
    func_0203FCA0(4, &t4, 0);
    func_02040588(4, 0);
    func_020409B4(4);

    t5 = d_021BBAE0;
    func_0203FCA0(5, &t5, 0);
    func_02040588(5, 0);

    t6 = d_021BBB00;
    func_0203FCA0(6, &t6, 0);
    func_02040588(6, 0);
    func_02040C14(6, 0, 1, 0);
    func_020414EC(6);
}







void ITEMMENU_ResetDisplayLayers(void)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
}






void ITEMMENU_LoadBagGraphics(ItemMenuWork *work, int bg)
{
    int a, b, c, t;
    int r = func_02008550((const struct Sub0200852CObj *)(work->myStatus));
    if (r == 0) {
        a = 4;
        b = 3;
        c = 5;
    } else if (r == 1) {
        a = 1;
        b = 0;
        c = 2;
    }
    func_02049B68((void *)bg, a, 0, 0, 0x20, work->heapId);
    t = func_02049740((void *)bg, b, 0, 0, 0, work->heapId);
    work->frameCounter = t;
    func_02049990((void *)bg, c, 0, 0, (unsigned short)t, 0, 0, work->heapId);
}









void ITEMMENU_LoadTabGraphics(ItemMenuWork *work, void *bg)
{
    int a, b, c, d;
    int r = func_02008550((const struct Sub0200852CObj *)(work->myStatus));
    if (r == 0) {
        a = 0x10;
        b = 0xf;
        c = 0xe;
        d = 0xd;
    } else if (r == 1) {
        a = 0xc;
        b = 0xb;
        c = 0xa;
        d = 9;
    }
    work->tabCharRes = CLACT_RegisterPaletteEx((void *)bg, a, 0, 0xc0, 0, 4, work->heapId);
    work->tabPaletteRes = CLACT_RegisterCharacter((void *)bg, b, 0, 0, work->heapId);
    work->tabCellRes = CLACT_RegisterCellAnim((void *)bg, c, d, work->heapId);
}









static inline void LoadIcons(ItemMenuWork *work)
{
    void *a;
    u32 m;
    u32 i;

    a = func_020490F4(func_020275E4(), work->heapId);
    work->cursorCharRes2 = CLACT_RegisterPaletteEx(a, func_020275E8(), 1, 0x80, 0, 3, work->heapId);
    m = func_020275FC(2);
    work->cursorPaletteRes2 = CLACT_RegisterCellAnim(a, m, func_02027600(2), work->heapId);
    for (i = 0; i < 3; i++)
        work->slotCharRes[i] = CLACT_RegisterCharacter(a, func_02027610((u8)i), 0, 1, work->heapId);
    for (i = 0; i < 17; i++)
        work->typeIconRes[i] = CLACT_RegisterCharacter(a, func_020275F8((u8)i), 0, 1, work->heapId);
    ARC_TOOL_DeleteHandle(a);
}









void ITEMMENU_SetupGraphics(ItemMenuWork *work)
{
    Tbl16 t;
    Rect r2;
    Rect r1;
    Rect r0;
    void *h;
    u32 v;
    u32 i;

    *(volatile u16 *)0x04000050 = 0;
    func_0203F8F4(work->heapId);
    BMP_WIN_Init(work->heapId);
    func_0201DD60();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BBBE0);
    CLACT_InitSystem((const struct Cfg *)d_021BBA8C, (u32)d_021BBBE0, work->heapId);
    t = d_021BBAB0;
    func_0203FC28((struct DispConfig *)(&t));
    func_02043534(0);
    BG_SYS_SetSubVisiblePlanes(0);
    ITEMMENU_InitDisplayBanks();
    func_0201DD68();
    work->keyRepeatPacked = (u32)func_0201F5DC((void *)3, 13, 0, work->heapId);
    h = func_020490F4(0x58, work->heapId);
    func_02049B68(h, 8, 4, 0, 0, work->heapId);
    if (func_02008550((const struct Sub0200852CObj *)(work->myStatus)) == 0)
        ARC_UTIL_UploadPaletteFromHandle(h, 8, 4, 0x20, 0, 0x20, work->heapId);
    v = func_02049740(h, 6, 4, 0, 0, work->heapId);
    work->bgPaletteA = v;
    func_02049990(h, 7, 4, 0, (u16)v, 0, 0, work->heapId);
    ITEMMENU_LoadBagGraphics(work, (int)h);
    v = func_02049740(h, 0x11, 5, 0, 0, work->heapId);
    work->bgPaletteB = v;
    func_02049990(h, 0x17, 5, 0, (u16)v, 0, 0, work->heapId);
    ITEMMENU_LoadTabGraphics(work, h);
    work->bgPaletteD = func_02049740(h, 0x21, 3, 0, 0, work->heapId);
    func_02049B68(h, 0x22, 0, 0x60, 0x20, work->heapId);
    ARC_TOOL_DeleteHandle(h);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, work->heapId);
    work->clactSys = CLACT_CreateUnit(0x34, 0, work->heapId);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    func_020434DC(0x10, 1);
    h = func_020490F4(0x53, work->heapId);
    func_02049B68(h, 0x1B, 0, 0x100, 0x20, work->heapId);
    v = func_02049740(h, 0x1C, 1, 0, 0, work->heapId);
    work->bgPaletteC = v;
    func_02049990(h, 0x1D, 1, 0, (u16)v + 0x8000, 0, 0, work->heapId);
    func_020409B4(1);
    work->iconCharRes = CLACT_RegisterPaletteEx(h, 0x13, 0, 0x140, 0, 3, work->heapId);
    work->iconPaletteRes = CLACT_RegisterCharacter(h, 0x14, 0, 0, work->heapId);
    work->iconCellRes = CLACT_RegisterCellAnim(h, 0x17, 0x1A, work->heapId);
    ARC_TOOL_DeleteHandle(h);
    ITEMMENU_CreateSideButtonActors(work);
    LoadIcons(work);
    r2.x = 0x50;
    r2.y = 0xB8;
    r2.a = 1;
    r2.b = 1;
    r2.z = 0;
    for (i = 0; i < 3; i++) {
        work->damageClassActors[i] = CLACT_CreateActor(work->clactSys, work->slotCharRes[i], work->cursorCharRes2, work->cursorPaletteRes2, &r2, 1, work->heapId);
        func_0204B6F4(work->damageClassActors[i], func_02027604((u8)i), 1);
        func_0204B3DC(work->damageClassActors[i], 0);
    }
    r1.x = 0x52;
    r1.y = 0xA5;
    r1.a = 1;
    r1.b = 1;
    r1.z = 0;
    for (i = 0; i < 17; i++) {
        work->typeActors[i] = CLACT_CreateActor(work->clactSys, work->typeIconRes[i], work->cursorCharRes2, work->cursorPaletteRes2, &r1, 1, work->heapId);
        func_0204B6F4(work->typeActors[i], func_020275EC((u8)i), 1);
        func_0204B3DC(work->typeActors[i], 0);
    }
    h = func_020490F4(0x58, work->heapId);
    work->cursorCharRes = CLACT_RegisterPaletteEx(h, 0x27, 0, 0x80, 0, 2, work->heapId);
    work->cursorPaletteRes = CLACT_RegisterCharacter(h, 0x26, 0, 0, work->heapId);
    work->cursorCellRes = CLACT_RegisterCellAnim(h, 0x25, 0x24, work->heapId);
    ARC_TOOL_DeleteHandle(h);
    r0.a = 10;
    r0.b = 1;
    r0.x = 0x92;
    r0.y = 0xB0;
    r0.z = 0;
    work->inputGuard = CLACT_CreateActor(work->clactSys, work->cursorPaletteRes, work->cursorCharRes, work->cursorCellRes, &r0, 0, work->heapId);
    func_0204B92C(work->inputGuard, 1);
    func_0204B3DC((work->inputGuard), 1);
    ITEMMENU_UpdateInputGuardAnim(work);
}









void ITEMMENU_ApplyBgPalettes(ItemMenuWork *work)
{
    unsigned v;
    v = work->bgPaletteA;
    func_0203FB44((int)4, (unsigned short)v, (unsigned short)(v >> 16));
    v = work->bgPaletteB;
    func_0203FB44((int)5, (unsigned short)v, (unsigned short)(v >> 16));
    v = work->bgPaletteD;
    func_0203FB44((int)3, (unsigned short)v, (unsigned short)(v >> 16));
    v = (unsigned int)work->frameCounter;
    func_0203FB44((int)0, (unsigned short)v, (unsigned short)(v >> 16));
    v = work->bgPaletteC;
    func_0203FB44((int)1, (unsigned short)v, (unsigned short)(v >> 16));
}








void ITEMMENU_SetLayersVisible(void *p, int v) { func_02040588(5, v); func_02040588(6, v); }







/*
 * blocked: WAZA_TOOL_GetDamageType (arm9 unlabelled leaf, the integrator's; 12 bytes, tail stub)
 * has no witness outside this function. Verified C for the leaf (EXACT,
 * thumb, arm9, no region):
 *   extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *   int WAZA_TOOL_GetDamageType(int a) { return func_0201BD28(a, 2); }
 */
void ITEMMENU_SetMoveTypeIconsVisible(ItemMenuWork *work, int mode)
{
    int r;
    if (mode == 1) {
        work->screenState = 1;
    } else {
        work->screenState = 2;
    }
    if (work->movingCursorActor != 0) {
        func_0204B3DC(work->movingCursorActor, mode);
    }
    r = func_020212B0(ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work))->itemId);
    if (r != 0) {
        func_0204B3DC(work->damageClassActors[WAZA_TOOL_GetDamageType(r)], mode);
        func_0204B3DC(work->typeActors[WAZA_TOOL_GetType((void *)r)], mode);
    }
}








void ITEMMENU_DrawMoveInfo(ItemMenuWork *work)
{
    u32 i;
    u32 j;
    u16 *e;
    u16 kind;
    u8 n;

    j = 0;
    for (i = 0; i < 3; i++)
        func_0204B3DC(work->damageClassActors[i], 0);
    for (j = 0; j < 17; j++)
        func_0204B3DC(work->typeActors[j], 0);
    e = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    if (e == 0 || *e == 0) {
        ITEMMENU_SetMoveTypeIconsVisible(work, 0);
        return;
    }
    ITEMMENU_SetMoveTypeIconsVisible(work, 1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window)), 0);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window)), 0);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window)), 0);
    kind = func_020212B0(*e);
    if (kind == 0) {
        func_02045CAC(work->msgBank, 0x86, work->tempString);
        ITEMMENU_RegisterItemName(work, 0, *e);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window, work->messageString, 0, (s16_021BB6E0)4, 0x3DC0);
        if (work->currentPocket != 4) {
            func_02045CAC(work->msgBank, 0x83, work->tempString);
            func_0201EFA4(work->wordSet, 0, e[1], 3, 0, 1);
            func_0201F250(work->wordSet, work->messageString, work->tempString);
            ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window, work->messageString, 0, (s16_021BB6E0)4, 0x3DC0);
        } else {
            BMP_WIN_TransferChars((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
        }
        BMP_WIN_ClearScreen((struct Descriptor *)(*(u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    } else {
        n = func_02021350(*e);
        if (n == 0xFF) {
            func_02045CAC(work->msgBank, 0x45, work->tempString);
            func_0201EFA4(work->wordSet, 0, func_0202130C(*e) + 1, 2, 2, 1);
        } else {
            func_02045CAC(work->msgBank, 0x47, work->tempString);
            func_0201EFA4(work->wordSet, 0, n + 1, 2, 2, 1);
        }
        func_0201EF34(work->wordSet, 1, kind);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window, work->messageString, 0, (s16_021BB6E0)4, 0x3DC0);
        ITEMMENU_PrintMoveInfoText(work, kind);
        BMP_WIN_TransferChars((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
    }
    func_02020FB4(work->tempString, *e, work->heapId);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window, work->tempString, 0, (s16_021BB6E0)4, 0x3DC0);
    ITEMMENU_FlushWindowAt((void **)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window);
    ITEMMENU_FlushWindowAt((void **)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
    ITEMMENU_FlushWindowAt((void **)&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window);
    ITEMMENU_CreateMovingCursor(work, *e);
}









void ITEMMENU_HideMoveInfo(ItemMenuWork *work)
{
    unsigned i;
    unsigned j;
    ITEMMENU_SetMoveTypeIconsVisible(work, 0);
    BMP_WIN_ClearScreen((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    for (i = 0; i < 3; i++) {
        func_0204B3DC(work->damageClassActors[i], 0);
    }
    for (j = 0; j < 0x11; j++) {
        func_0204B3DC(work->typeActors[j], 0);
    }
}









void ITEMMENU_FreeGraphics(ItemMenuWork *work)
{
    int i;
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_0].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_3].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_4].window));
    CLACT_DeleteActor(work->cursorActor);
    if (work->movingCursorActor != 0) {
        CLACT_DeleteActor(work->movingCursorActor);
        CLACT_ReleaseCharacter(work->cellAnimRes);
        CLACT_ReleasePalette(work->cellRes);
    }
    CLACT_ReleaseCellAnim(work->cellTransRes);
    for (i = 0; i < 8; i++) {
        BMP_Delete((struct Bmp *)(*(int *)&work->slotBitmap[i]));
    }
    CLACT_DeleteUnit(work->clactSys);
    CLACT_ExitSystem();
}








void ITEMMENU_PrintMenuTitle(ItemMenuWork *work) { func_02045CAC(work->msgBank, 0x87, work->tempString); ITEMMENU_PrintToWindow(work, (unsigned *)&work->listWindows[ITEMMENU_WINDOW_MENU_4].window, work->tempString, 0, (s16_021BB6E0)4, 0x3DC0); }









void ITEMMENU_InitWindows(ItemMenuWork *work)
{
    void *bg;

    work->listWindows[ITEMMENU_WINDOW_MENU_4].window = BMP_WIN_Create(3, 0x12, 9, 0xc, 3, 3, 1);
    ITEMMENU_PrintMenuTitle(work);
    BMP_WIN_ClearScreen((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_4].window));
    work->listWindows[ITEMMENU_WINDOW_MENU_0].window = BMP_WIN_Create(3, 0x11, 0xd, 0xb, 2, 3, 1);
    work->listWindows[ITEMMENU_WINDOW_MENU_3].window = BMP_WIN_Create(3, 0x11, 0xf, 0xb, 2, 3, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window = BMP_WIN_Create(6, 0, 0x13, 0x20, 5, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window = BMP_WIN_Create(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window = BMP_WIN_Create(6, 0x14, 8, 6, 3, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window = BMP_WIN_Create(6, 2, 0xc, 0x1d, 7, 0, 1);
    BMP_WIN_MakeScreen((struct Cfg *)(work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window));
    BMP_WIN_MakeScreen((struct Cfg *)(*(int *)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window));
    BMP_WIN_MakeScreen((struct Cfg *)(work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window));
    BMP_WIN_MakeScreen((struct Cfg *)(work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    bg = func_020490F4(0x19, work->heapId);
    work->cellTransRes = CLACT_RegisterCellAnim(bg, 1, 0, work->heapId);
    ARC_TOOL_DeleteHandle(bg);
    func_02045CAC(work->msgBank, 0x66, work->tempString);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 8, (s16_021BB6E0)4, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5d, work->tempString);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 8, (s16_021BB6E0)0x18, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5b, work->tempString);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 0x70, (s16_021BB6E0)4, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5c, work->tempString);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 0x70, (s16_021BB6E0)0x18, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5a, work->tempString);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 0xd0, (s16_021BB6E0)4, 0x3DC0);
    if (func_020355C4() == 0) {
        ITEMMENU_DrawMoveInfo(work);
    }
}








void ITEMMENU_DestroyMovingCursor(ItemMenuWork *work) { if (work->movingCursorActor) { CLACT_DeleteActor(work->movingCursorActor); CLACT_ReleaseCharacter(work->cellAnimRes); CLACT_ReleasePalette(work->cellRes); *(void * *)&work->movingCursorActor = 0; } }









void ITEMMENU_CreateMovingCursor(ItemMenuWork *work, int id)
{
    void *bg;
    Rect_021B9850 r;
    if (work->movingCursorActor != 0) {
        ITEMMENU_DestroyMovingCursor(work);
    }
    bg = func_020490F4(0x19, work->heapId);
    work->cellRes = CLACT_RegisterPaletteEx(bg, func_02020E60(id, 2), 1, 0, 0, 1, work->heapId);
    work->cellAnimRes = CLACT_RegisterCharacter(bg, func_02020E60(id, 1), 0, 1, work->heapId);
    ARC_TOOL_DeleteHandle(bg);
    r.a = 0x84;
    r.b = 0x50;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    work->movingCursorActor = CLACT_CreateActor(work->clactSys, work->cellAnimRes, work->cellRes, work->cellTransRes, &r, 1, work->heapId);
    func_0204B92C(work->movingCursorActor, 1);
    func_0204B3DC(work->movingCursorActor, 1);
}








void ITEMMENU_FreeActionMenuResources(ItemMenuWork *work) { CLACT_DrawSystem(); if (work->menuList) APP_TASKMENU_UpdateMenu(work->menuList); }








/*
 * lever:    the loop's array slots are spelled `p + i * 4 + 0x614` (index
 *           before offset), which keeps `p + i*4` in one register across both
 *           calls; `p + 0x614 + i * 4` and `((int *)(p + 0x614))[i]` both DIFF.
 */
void ITEMMENU_LoadPocketGraphics(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    void *bg;
    int i;

    bg = func_020490F4(0x58, work->heapId);
    work->pocketCharRes = CLACT_RegisterPaletteEx(bg, 0x20, 0, 0x1a0, 0, 1, work->heapId);
    work->pocketPaletteRes = CLACT_RegisterCharacter(bg, 0x1f, 0, 0, work->heapId);
    work->pocketCellRes = CLACT_RegisterCellAnim(bg, 0x1e, 0x1d, work->heapId);
    work->bagCharRes = CLACT_RegisterPaletteEx(bg, 0x1c, 0, 0x60, 0, 1, work->heapId);
    work->bagPaletteRes = CLACT_RegisterCharacter(bg, 0x1b, 0, 0, work->heapId);
    work->bagCellRes = CLACT_RegisterCellAnim(bg, 0x1a, 0x19, work->heapId);
    for (i = 0; i < 8; i++) {
        *(int *)(p + i * 4 + 0x614) = (int)BMP_Create(0xc, 2, 0x20, work->heapId);
        *(int *)(p + i * 4 + 0x5F4) =CLACT_RegisterCharacter(bg, 0x14, 0, 0, work->heapId);
    }
    func_02008550((const struct Sub0200852CObj *)(work->myStatus));
    work->barCharRes = CLACT_RegisterPaletteEx(bg, 0x15, 0, 0, 0, 3, work->heapId);
    work->bagAnimRes = CLACT_RegisterCellAnim(bg, 0x13, 0x12, work->heapId);
    ARC_TOOL_DeleteHandle(bg);
}








void ITEMMENU_CreateCursorActors(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    Rect_021B9EF4 r1;
    Rect_021B9EF4 r2;
    Rect_021B9EF4 r3;
    int i;

    r1.a = 0xf8;
    r1.b = 0x1a;
    r1.d = 1;
    r1.e = 2;
    r1.c = 0;
    work->cursorActor = CLACT_CreateActor(work->clactSys, work->bagPaletteRes, work->bagCharRes, work->bagCellRes, &r1, 0, work->heapId);
    func_0204B3DC(work->cursorActor, 1);
    func_0204B92C(work->cursorActor, 1);
    ITEMMENU_MoveCursorToRow(work);
    r2.a = 0x8c;
    r2.b = 0x30;
    r2.d = 1;
    r2.e = 2;
    r2.c = 1;
    work->selectorActor = CLACT_CreateActor(work->clactSys, work->bagPaletteRes, work->bagCharRes, work->bagCellRes, &r2, 0, work->heapId);
    func_0204B3DC(work->selectorActor, 1);
    func_0204B92C(work->selectorActor, 1);
    for (i = 0; i < 8; i++) {
        r3.a = 0x8c;
        r3.b = i * 0x18;
        r3.d = 0xa;
        r3.e = 3;
        r3.c = 0;
        *(struct Actor **)(p + i * 4 + 0x634) = CLACT_CreateActor(work->clactSys, *(int *)(p + i * 4 + 0x5F4), work->barCharRes, work->bagAnimRes, &r3, 0, work->heapId);
        r3.a -= 0x18;
        r3.c = 1;
        *(struct Actor **)(p + i * 4 + 0x674) = CLACT_CreateActor(work->clactSys, work->pocketPaletteRes, work->pocketCharRes, work->pocketCellRes, &r3, 0, work->heapId);
        func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x634), 0);
        func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
    }
}




int ITEMMENU_GetRowColorKind(u16 x)
{
    if (func_02021288(x) == 1) {
        switch (func_020212B0(x)) {
        case 0xF:
        case 0x13:
        case 0x39:
        case 0x46:
        case 0x7F:
        case 0x123:
            return 1;
        }
    }
    return 0;
}









void ITEMMENU_PrintItemList(ItemMenuWork *work)
{
    int h;
    int i;
    int idx;
    u16 *e;
    int rec;
    u32 kind;
    u16 color;
    u16 r;
    u32 w;

    if (ITEMMENU_GetItemCount(work) == 0) {
        ITEMMENU_FlushWindowAt((void **)&work->listWindows[ITEMMENU_WINDOW_MENU_4].window);
    } else {
        w = (unsigned int)work->listWindows[ITEMMENU_WINDOW_MENU_4].window;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    if (work->shownItemId == work->scrollOffset) {
        return;
    }
    h = (int)func_02020F14(work->heapId);
    for (i = 0; i < 8; i++) {
        work->slotAnimIndex[i] = 0;
        idx = work->scrollOffset + i;
        if (idx < 0) {
            continue;
        }
        e = (void *)ITEMMENU_GetSlot(work, idx);
        if (e == 0 || *e == 0) {
            continue;
        }
        rec = func_02020F20(h, *e, work->heapId);
        kind = func_02021014((struct Rec *)rec, 0xf);
        if (d_021BBA79[i] == 0) {
            if (ITEMMENU_GetRowColorKind(*e) == 1) {
                color = 0x18AD;
            } else {
                color = 0x82D;
            }
        } else {
            if (ITEMMENU_GetRowColorKind(*e) == 1) {
                color = 0x20ED;
            } else {
                color = 0x106D;
            }
        }
        BMP_Clear((struct CharBuf *)(work->slotBitmap[i]), 0xd);
        func_02045CAC(work->msgBank, 0x82, work->tempString);
        r = func_020212B0(*e);
        if (r == 0) {
            ITEMMENU_RegisterItemName(work, 0, *e);
        } else {
            func_0201EF34(work->wordSet, 0, r);
        }
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        PRINTSYS_PrintColor((void *)(work->slotBitmap[i]), 0, 0, work->messageString, (void *)(work->menuTaskArg), color);
        if (kind == 4) {
            work->slotAnimIndex[i] = 4;
        } else if (kind == 5) {
            work->slotAnimIndex[i] = 5;
        } else if (kind == 1) {
            work->slotAnimIndex[i] = 6;
        } else if (func_02021350(*e) != 0xff) {
            work->slotAnimIndex[i] = 8;
        } else if (func_0202130C(*e) != 0xff) {
            work->slotAnimIndex[i] = 7;
        } else if (func_02021014((struct Rec *)rec, 4) == 0) {
            work->slotAnimIndex[i] = 3;
        } else if (ITEMMENU_IsItemRegistered(work, *e) == 0) {
            work->slotAnimIndex[i] = 2;
        } else {
            work->slotAnimIndex[i] = 1;
        }
        func_020307B0((void *)rec);
    }
    ARC_TOOL_DeleteHandle((void *)h);
    work->busyCount = 1;
}










void ITEMMENU_SnapSelectorToCursor(ItemMenuWork *work)
{
    Pt pt;
    ITEMMENU_UpdateSlotActorPosition(work, 0);
    CLACT_GetActorSurfacePos(work->selectorActor, (struct PtS *)&pt, 0xFFFF);
    pt.b = (work->cursorRow + 1) * 0x18;
    func_0204B404(work->selectorActor, (const struct Vec2 *)(&pt), 0xFFFF);
    if (func_020355C4() == 0) {
        ITEMMENU_UpdateSlotActorPosition(work, 1);
    }
    BLINK_PALANM_ResetPhase(work->blinkPalAnm);
    func_0204B3DC(work->cursorActor, ITEMMENU_GetItemCount(work) >= 7);
    CLACT_SetActorAnimIndex(work->selectorActor, 0);
    CLACT_SetActorAnimIndex(work->cursorActor, 0);
}










void ITEMMENU_UploadSlotGraphics(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    int i;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 8; i++) {
        src = (u8 *)CLACT_GetCharacterVramAddress(*(u32 *)(p + i * 4 + 0x5F4), 0);
        dst = BMP_GetPixels(*(void **)(p + i * 4 + 0x614));
        func_020862F0(dst, BMP_GetByteSize(*(void **)(p + i * 4 + 0x614)));
        func_0207E780(dst + 0x100, src + 0x80, 0x80);
        func_0207E780(dst + 0x280, src + 0x100, 0x80);
        func_0207E780(dst, src + 0x300, 0x100);
        func_0207E780(dst + 0x180, src + 0x400, 0x100);
        if (*(u32 *)(p + i * 4 + 0x654) != 0) {
            if (work->currentPocket == 4) {
                if (ITEMMENU_IsBrowseMode(work) == 1 && *(u32 *)(p + i * 4 + 0x654) != 3) {
                    CLACT_SetActorAnimSeq(*(struct Actor **)(p + i * 4 + 0x674), *(u32 *)(p + i * 4 + 0x654) - 1);
                    func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 1);
                } else {
                    func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
                }
            } else if (work->currentPocket == 0 && *(u32 *)(p + i * 4 + 0x654) >= 4) {
                CLACT_SetActorAnimSeq(*(struct Actor **)(p + i * 4 + 0x674), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 1);
            } else if (work->currentPocket == 2 && *(u32 *)(p + i * 4 + 0x654) >= 7) {
                CLACT_SetActorAnimSeq(*(struct Actor **)(p + i * 4 + 0x674), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 1);
            } else {
                func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
            }
            func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x634), 1);
        } else {
            func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
            func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x634), 0);
        }
    }
}










void ITEMMENU_UpdateCursorFromTouch(ItemMenuWork *work)
{
    unsigned w;
    unsigned v;
    Pt pt;
    if (TOUCHPANEL_GetPointCont(&w, &v) == 1) {
        if (v < 0x1A) {
            v = 0x1A;
        } else if (v > 0x8E) {
            v = 0x8E;
        }
        CLACT_GetActorSurfacePos(work->cursorActor, (struct PtS *)&pt, 0xFFFF);
        pt.b = v;
        func_0204B404(work->cursorActor, (const struct Vec2 *)(&pt), 0xFFFF);
    }
}










void ITEMMENU_MoveCursorToRow(ItemMenuWork *work)
{
    Pt pt;
    int n = ITEMMENU_GetItemCount(work);
    if (n >= 7) {
        CLACT_GetActorSurfacePos(work->cursorActor, (struct PtS *)&pt, 0xFFFF);
        pt.b = func_0202EE0C(n - 6, work->scrollOffset + 1, 0x1A, 0x8E, 0);
        func_0204B404(work->cursorActor, (const struct Vec2 *)(&pt), 0xFFFF);
    }
}









void ITEMMENU_CreateSideButtonActors(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    Rect_021BA6F4 r;
    B5 t1;
    B5 t2;
    B2 t3;
    B2 t4;
    u8 i;

    r.d = 0xa;
    r.e = 1;
    t1 = d_021BBAA8;
    t2 = d_021BBA6C;
    for (i = 0; i < 5; i++) {
        r.a = t2.v[i];
        r.b = 0xa8;
        r.c = t1.v[i];
        if (i == 2) {
            r.b += 4;
        }
        *(struct Actor **)(p + i * 4 + 0x710) = CLACT_CreateActor(work->clactSys, work->iconPaletteRes, work->iconCharRes, work->iconCellRes, &r, 0, work->heapId);
        func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x710), 1);
    }
    func_0204B92C(work->sideActor[0], 1);
    func_0204B92C(work->sideActor[1], 1);
    if (ITEMMENU_IsBrowseMode(work) == 0) {
        func_0204B3DC(work->sideActor[2], 0);
    }
    if (work->bagMode == 2) {
        func_0204B3DC(work->sideActor[3], 0);
    }
    t3 = d_021BBA68;
    t4 = d_021BBA64;
    for (i = 0; i < 2; i++) {
        r.a = 0xe8;
        r.b = t4.v[i];
        r.c = t3.v[i];
        r.e = 0;
        *(struct Actor **)(p + (u8)(i + 5) * 4 + 0x710) = CLACT_CreateActor(work->clactSys, work->iconPaletteRes, work->iconCharRes, work->iconCellRes, &r, 0, work->heapId);
        func_0204B92C(*(struct Actor **)(p + (u8)(i + 5) * 4 + 0x710), 1);
        func_0204B3DC(*(struct Actor **)(p + (u8)(i + 5) * 4 + 0x710), 0);
    }
}









/*
 * Creates five sprites from three small tables.  The work area must be a
 * struct with the resource triple as an array (args res[1], res[0], res[2]):
 * the same fields spelled as `*(int *)(p + 0x594)` offsets colour the x/y
 * loads into different registers (23 bytes of DIFF).  The tables stay
 * non-const: a const coordinate table lets its load float above the two
 * record stores.
 * The data symbols are declared without an ovNNN token (the hint is
 * contested for 0x021BBA74 and 0x021BBBCC; sole-ref/data resolves them).
 */
void ITEMMENU_CreateTabActors(ItemMenuWork *work)
{
    unsigned i;
    Rect_021BA8C0 r;
    for (i = 0; i < 5; i++) {
        r.d = d_021BBA74[i];
        r.e = 1;
        r.x = d_021BBBCC[i][0] - 0x10;
        r.y = d_021BBBCC[i][1];
        r.z = d_021BBA81[i * 2 + 1];
        work->tabActor[i] = CLACT_CreateActor(work->clactSys, work->tabPaletteRes, work->tabCharRes, work->tabCellRes, &r, 0, work->heapId);
        func_0204B92C(work->tabActor[i], 1);
    }
}









void ITEMMENU_SelectTab(ItemMenuWork *work, unsigned sel)
{
    unsigned i;
    for (i = 0; i < 5; i++) {
        if (i == sel) {
            CLACT_SetActorAnimSeq(work->tabActor[i], d_021BBA81[i * 2]);
        } else {
            CLACT_SetActorAnimSeq(work->tabActor[i], d_021BBA81[i * 2 + 1]);
        }
    }
}







void ITEMMENU_ClearMessageWindow(ItemMenuWork *work) { func_0201F7A8((void *)work->messageWindows[0].window, 1); }








void ITEMMENU_OpenPopupList(ItemMenuWork *work, int *tbl, int n)
{
    Desc s;
    int i;
    void *r;
    ItemMenuWork *e;

    s.a = work->heapId;
    s.b = n;
    s.c = (int)&work->listEntries[0].text;
    s.d = 1;
    s.e = 0x20;
    s.f = 0x18;
    s.g = 0xD;
    s.h = 3;
    for (i = 0; i < n; i++) {
        /* e is the work area shifted by one row (0xC bytes) per entry, so its
         * listEntries[0] is entry i: the byte address is formed before the
         * row offset, as the array form listEntries[i] does not match. */
        e = (ItemMenuWork *)((char *)work + i * 0xC);
        r = STRBUF_Create(0x64, work->heapId);
        e->listEntries[0].text = r;
        func_02045CAC(work->msgBank, tbl[i], r);
        e->listEntries[0].color = 0x39E0;
        e->listEntries[0].extra = 0;
    }
    work->listEntries[i - 1].extra = 1;
    work->menuList = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&s), (void *)(work->taskMenuState));
    for (i = 0; i < n; i++) {
        STRBUF_Delete((struct U16Vec *)(*(int *)&work->listEntries[i].text));
    }
    ITEMMENU_UpdateSideButtons(work, 0);
}






void ITEMMENU_LoadBgPaletteMode(ItemMenuWork *work, int mode)
{
    void *h = func_020490F4(0x58, work->heapId);

    if (mode != 2) {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x17, 5, 0, (u16)work->bgPaletteB, 0, 0, work->heapId);
    } else {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x18, 5, 0, (u16)work->bgPaletteB, 0, 0, work->heapId);
    }
    ARC_TOOL_DeleteHandle((void *)((int)h));
}





void ITEMMENU_PrintMoveInfoText(ItemMenuWork *work, int x)
{
    int a;
    int b;
    int c;
    u32 *win;

    win = &work->listWindows[0].window;

    func_0204B3DC(work->damageClassActors[WAZA_TOOL_GetDamageType((u16)x)], (int)1);
    func_0204B3DC(work->typeActors[WAZA_TOOL_GetType((void *)(u16)x)], (int)1);
    a = (int)WAZA_TOOL_GetMaxPP(x, (int)0);
    b = (int)func_0201BD28(x, (int)3);
    c = (int)func_0201BD28(x, (int)4);
    BMP_FillRect(func_02045770((struct Descriptor *)(*win)), 0xB0, 0, 0x20, 0x28, 0);
    BMP_FillRect(func_02045770((struct Descriptor *)(*win)), 0xE8, 0, 0x18, 0x18, 0);
    if (b <= 1) {
        func_02045CAC(work->msgBank, (int)0x17, work->tempString);
        ITEMMENU_PrintToWindow(work, win, work->tempString, 0xB0, (s16_021BB6E0)4, 0x3DC0);
    } else {
        func_02045CAC(work->msgBank, (int)0x5F, work->tempString);
        func_0201EFA4(work->wordSet, (int)0, (int)b, (int)3, (int)0, (int)1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, win, work->messageString, 0xB0, (s16_021BB6E0)4, 0x3DC0);
    }
    if (c == 0 || (int)WAZA_TOOL_IsAlwaysHit(x) == 1) {
        func_02045CAC(work->msgBank, (int)0x17, work->tempString);
        ITEMMENU_PrintToWindow(work, win, work->tempString, 0xB0, (s16_021BB6E0)0x18, 0x3DC0);
    } else {
        func_02045CAC(work->msgBank, (int)0x5F, work->tempString);
        func_0201EFA4(work->wordSet, (int)0, (int)c, (int)3, (int)0, (int)1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, win, work->messageString, 0xB0, (s16_021BB6E0)0x18, 0x3DC0);
    }
    func_02045CAC(work->msgBank, (int)0x5E, work->tempString);
    func_0201EFA4(work->wordSet, (int)0, (int)a, (int)2, (int)0, (int)1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_PrintToWindow(work, win, work->messageString, 0xE8, (s16_021BB6E0)4, 0x3DC0);
    ITEMMENU_FlushWindowAt((void **)win);
}






/*
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through PRINTSYS_PrintStream (mode 1) or through ITEMMENU_PrintToWindow, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
 */
void ITEMMENU_ShowMessage(ItemMenuWork *work, int mode)
{
    u32 *win;

    if (work->messageWindows[0].window == 0) {
        work->messageWindows[0].window = BMP_WIN_Create(3, 1, 1, 0x1E, 4, 0xC, 1);
    }
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)work->messageWindows[0].window)), 0xF);
    BMP_WIN_TransferChars((struct Descriptor *)work->messageWindows[0].window);
    win = &work->messageWindows[0].window;
    if (mode == 1) {
        work->messageWindow = PRINTSYS_PrintStream(work->messageWindows[0].window, 0, 0, work->messageString,
                                            work->menuTaskArg, func_02012FFC(),
                                            work->touchTask, 2, work->heapId, 0xF);
    } else {
        ITEMMENU_PrintToWindow(work, win, work->messageString, 0, 0, 0x44F);
    }
    func_0201F73C((void *)*win, 1, (u16)work->keyRepeatPacked, 0xD);
    ITEMMENU_FlushWindowAt((void **)win);
}





/*
 * Tail call to ITEMMENU_ShowMessage(p, 0).
 */
void ITEMMENU_ShowMessageDefault(ItemMenuWork *work)
{
    ITEMMENU_ShowMessage(work, 0);
}





void ITEMMENU_ShowItemUseMessage(ItemMenuWork *work, unsigned v) { func_02045CAC(work->msgBank, 0x2B, work->tempString); ITEMMENU_RegisterItemName(work, 0, v); func_0201F250(work->wordSet, work->messageString, work->tempString); }






int ITEMMENU_IsMessageFinished(ItemMenuWork *work)
{
    int r;

    if (work->messageWindow != 0) {
        r = func_0201CE30((void *)(work->messageWindow));
        APP_KEYCURSOR_Update((struct Ctx *)(work->itemDescWindow), (void *)(work->messageWindow), (void *)(work->messageWindows[0].window));
        switch (r) {
        case 2:
            func_0201CE48((struct Rec3 *)(work->messageWindow));
            work->messageWindow = 0;
            work->messageWindowOpen = 0;
            break;
        case 1:
            if (work->messageWindowOpen == 0) {
                if ((func_020362DC() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
                    func_020061E4(0x547);
                    func_0201CE38((void *)(work->messageWindow));
                    work->messageWindowOpen = 1;
                }
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                func_0201CE5C((struct Rec *)(work->messageWindow), 0);
            }
            work->messageWindowOpen = 0;
            break;
        }
        return 0;
    }
    return 1;
}






void ITEMMENU_PrintPocketName(ItemMenuWork *work)
{
    work->messageWindows[1].window = BMP_WIN_Create(2, 3, 0x15, 0xC, 3, 0xC, 1);
    *(int *)&work->listWindows[ITEMMENU_WINDOW_MENU_1].window = BMP_WIN_Create(2, 1, 0x15, 8, 3, 0xC, 1);
    *(int *)&work->listWindows[ITEMMENU_WINDOW_MENU_2].window = BMP_WIN_Create(2, 9, 0x15, 9, 3, 0xC, 1);
    ITEMMENU_PrintPocketCount(work, work->currentPocket);
    ITEMMENU_SelectTab(work, work->currentPocket);
}





void ITEMMENU_HideSideWindows(ItemMenuWork *work) { func_020452E8((struct Descriptor *)work->messageWindows[1].window); func_020452E8((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_2].window); func_020452E8((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_1].window); }






void ITEMMENU_PrintPocketCount(ItemMenuWork *work, int val)
{
    int r;

    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)work->messageWindows[1].window)), 0);
    func_02045CAC(work->msgBank, 0x8B, work->tempString);
    func_0201F14C(work->wordSet, 0, val);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    r = 0x60 - func_0201D304(work->messageString, work->menuTaskArg, 0);
    ITEMMENU_PrintToWindow(work, (u32 *)&work->messageWindows[1].window, work->messageString, (unsigned short)(r >> 1), 4, 0x3C40);
    ITEMMENU_FlushWindowAt((void **)&work->messageWindows[1].window);
}





void ITEMMENU_PrintMoney(ItemMenuWork *work)
{
    BMP_Clear(func_02045770((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_2].window), 0);
    BMP_Clear(func_02045770((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_1].window), 0);
    func_02045CAC(work->msgBank, 0x51, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_MENU_1].window, work->tempString, 0, 4, 0x3C40);
    ITEMMENU_FlushWindowAt((void **)&work->listWindows[ITEMMENU_WINDOW_MENU_1].window);
    func_02045CAC(work->msgBank, 0x52, work->tempString);
    func_0201EFA4(work->wordSet, 0, func_0200C274(GAME_DATA_GetMiscSave(work->saveData)), 7, 1, 1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_MENU_2].window, work->messageString, 0, 4, 0x3C40);
    ITEMMENU_FlushWindowAt((void **)&work->listWindows[ITEMMENU_WINDOW_MENU_2].window);
}





void ITEMMENU_EnterQuantityMode(ItemMenuWork *work) { func_0204B3DC((work->sideActor[0]), 0); func_0204B3DC((work->sideActor[1]), 0); BMP_WIN_ClearScreen((struct Descriptor *)work->messageWindows[1].window); ITEMMENU_PrintMoney(work); }





void ITEMMENU_LeaveQuantityMode(ItemMenuWork *work) { func_0204B3DC((work->sideActor[0]), 1); func_0204B3DC((work->sideActor[1]), 1); BMP_WIN_ClearScreen((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_2].window); BMP_WIN_ClearScreen((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_1].window); ITEMMENU_PrintPocketCount(work, work->currentPocket); }






void ITEMMENU_OpenYesNoList(ItemMenuWork *work)
{
    Desc s;
    int h;
    void *r;

    h = work->heapId;
    s.a = h;
    s.b = 2;
    s.c = (int)work->listEntries;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = STRBUF_Create(0x64, h);
    work->listEntries[0].text = r;
    func_02045CAC(work->msgBank, 0x84, (void *)r);
    work->listEntries[0].color = 0x39E0;
    work->listEntries[0].extra = 0;
    r = STRBUF_Create(0x64, work->heapId);
    work->listEntries[1].text = r;
    func_02045CAC(work->msgBank, 0x85, (void *)r);
    work->listEntries[1].color = 0x39E0;
    work->listEntries[1].extra = 0;
    work->menuList = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&s), (void *)(work->taskMenuState));
    STRBUF_Delete((struct U16Vec *)(work->listEntries[0].text));
    STRBUF_Delete((struct U16Vec *)(work->listEntries[1].text));
    ITEMMENU_SetBackButtonAnim(work, 0);
    ITEMMENU_UpdateSideButtons(work, 0);
}





void ITEMMENU_CloseYesNoList(ItemMenuWork *work) { APP_TASKMENU_CloseMenu(work->menuList); work->menuList = 0; }






void ITEMMENU_LoadSellPalette(ItemMenuWork *work)
{
    void *arc;
    int tex;
    Img *img;
    int i;
    u16 *d;
    int n;

    arc = func_020490F4(0x58, work->heapId);
    tex = (int)ARC_UTIL_LoadHandleMember(arc, 0x23, 0, work->heapId);
    i = 0;
    if (func_02062B30((void *)tex, (void **)(&img))) {
        d = img->d;
        n = ((unsigned)img->w >> 3) * ((unsigned)img->h >> 3);
        for (; i < n; i++) {
            d[i] += (u16)((u16)(int)work->bgPaletteD | 0x3000);
        }
        func_02041090(3, (unsigned int)img->d, 0x10, 0xC, (unsigned)img->w >> 3, (unsigned)img->h >> 3);
        func_02041B6C(3);
    }
    func_020307B0((void *)tex);
    ARC_TOOL_DeleteHandle(arc);
}






void ITEMMENU_PrintQuantityPrice(ItemMenuWork *work, int val)
{
    int v;
    u32 *win2;
    u32 *win;

    win = (u32 *)&work->listWindows[ITEMMENU_WINDOW_MENU_0].window;

    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win)), 5);
    func_02045CAC(work->msgBank, 0x83, work->tempString);
    func_0201EFA4(work->wordSet, 0, val, 3, 0, 1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_PrintToWindow(work, win, work->messageString, 0, 0, 0x3DC5);
    ITEMMENU_FlushWindowAt((void **)win);
    if (work->listMode == 2) {
        win2 = (u32 *)&work->listWindows[ITEMMENU_WINDOW_MENU_3].window;
        v = ITEMMENU_GetSellTotal(work->selectedItemId, work->listCount, work->heapId);
        BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win2)), 5);
        func_02045CAC(work->msgBank, 0x54, work->tempString);
        func_0201EFA4(work->wordSet, 0, v, 7, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, win2, work->messageString, 0, 0, 0x3DC5);
        ITEMMENU_FlushWindowAt((void **)win2);
    }
}





int ITEMMENU_PocketToSortFlag(int x)
{
    switch (x) {
    case 0:
        return 10;
    case 3:
        return 13;
    case 1:
        return 11;
    case 2:
        return 12;
    case 4:
        return 14;
    }
    return x;
}






void ITEMMENU_UpdateSlotActorPosition(ItemMenuWork *work, u32 val)
{
    short b[2];
    short a[2];
    unsigned i;

    CLACT_GetActorSurfacePos(work->selectorActor, (struct PtS *)b, 0);
    for (i = 0; i < 8; i++) {
        CLACT_GetActorSurfacePos(work->slotActorA[i], (struct PtS *)a, 0);
        if (a[1] == b[1]) {
            break;
        }
    }
    func_0204B6F4(work->slotActorA[i], (u8)val, 0);
}






void ITEMMENU_UpdateSideButtons(ItemMenuWork *work, int mode)
{
    int r;

    if (work->currentPage == mode) {
        return;
    }
    work->currentPage = mode;
    r = GAME_DATA_CheckSaveFlag(work->saveData, ITEMMENU_PocketToSortFlag(work->currentPocket));
    if (mode == 1) {
        PALANM_RequestFade(work->palAnmSlot, 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        PALANM_RequestFade(work->palAnmSlot, 1, 1, 0, 0, 0, 0, func_020056BC());
        func_0207D658(0x04000050, 6, 0);
        ITEMMENU_UpdateInputGuardAnim(work);
        CLACT_SetActorAnimSeq(work->sideActor[0], 4);
        CLACT_SetActorAnimSeq(work->sideActor[1], 5);
        CLACT_SetActorAnimSeq(work->sideActor[3], 0);
        if (r == 1) {
            CLACT_SetActorAnimSeq(work->sideActor[2], 7);
        } else {
            CLACT_SetActorAnimSeq(work->sideActor[2], 6);
        }
        ITEMMENU_SetBackButtonAnim(work, 1);
    } else {
        PALANM_CopyHwPaletteToSlot(work->palAnmSlot, 2, 0, 0x200);
        PALANM_RequestFade(work->palAnmSlot, 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        PALANM_RequestFade(work->palAnmSlot, 1, 1, 0, 8, 8, 0, func_020056BC());
        if (work->bagMode == 4 && func_0204B3F4(work->sideActor[0]) == 0) {
            func_0207D658(0x04000050, 2, -8);
        } else {
            func_0207D658(0x04000050, 6, -8);
        }
        CLACT_SetActorAnimSeq(work->inputGuard, 4);
        CLACT_SetActorAnimSeq(work->sideActor[0], 0x12);
        CLACT_SetActorAnimSeq(work->sideActor[1], 0x13);
        CLACT_SetActorAnimSeq(work->sideActor[3], 0xE);
        if (r == 1) {
            CLACT_SetActorAnimSeq(work->sideActor[2], 0x16);
        } else {
            CLACT_SetActorAnimSeq(work->sideActor[2], 0x15);
        }
    }
}





void ITEMMENU_SetBackButtonAnim(ItemMenuWork *work, int v) { if (v == 1) CLACT_SetActorAnimSeq((work->sideActor[4]), 1); else CLACT_SetActorAnimSeq((work->sideActor[4]), 15); }





void ITEMMENU_UpdateInputGuardAnim(ItemMenuWork *work) { if (work->currentPocket == 2 || work->currentPocket == 3 || ITEMMENU_GetItemCount(work) <= 1) CLACT_SetActorAnimSeq((work->inputGuard), 4); else CLACT_SetActorAnimSeq((work->inputGuard), 0); }






void ITEMMENU_UpdateSideButtonsForMode(ItemMenuWork *work, int mode)
{
    int r = GAME_DATA_CheckSaveFlag(work->saveData, ITEMMENU_PocketToSortFlag(work->currentPocket));

    if (mode == 1) {
        ITEMMENU_UpdateInputGuardAnim(work);
        CLACT_SetActorAnimSeq(work->sideActor[0], 4);
        CLACT_SetActorAnimSeq(work->sideActor[1], 5);
        CLACT_SetActorAnimSeq(work->sideActor[3], 0);
        if (r == 1) {
            CLACT_SetActorAnimSeq(work->sideActor[2], 7);
        } else {
            CLACT_SetActorAnimSeq(work->sideActor[2], 6);
        }
    } else {
        CLACT_SetActorAnimSeq(work->inputGuard, 4);
        CLACT_SetActorAnimSeq(work->sideActor[0], 0x12);
        CLACT_SetActorAnimSeq(work->sideActor[1], 0x13);
        CLACT_SetActorAnimSeq(work->sideActor[3], 0xE);
        if (r == 1) {
            CLACT_SetActorAnimSeq(work->sideActor[2], 0x16);
        } else {
            CLACT_SetActorAnimSeq(work->sideActor[2], 0x15);
        }
    }
}





/*
 * lever: expand q at the first call but retain q for the second call.
 */
int ITEMMENU_MoveActorToPoint(const char *p)
{
    unsigned i;
    short v[2];
    const char *q;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        q = p + off;
        CLACT_GetActorSurfacePos(*(struct Actor **)((p + off) + 0x6AC), (struct PtS *)v, 0xFFFF);
        if (v[0] == *((short *)(((char *)d_021BBBCC) + off))) {
            return 0;
        }
        v[0] = v[0] + 4;
        func_0204B404(*(struct Actor **)(q + 0x6AC), (const struct Vec2 *)v, 0xFFFF);
    }
    return 1;
}






void ITEMMENU_PrintToWindow(ItemMenuWork *work, u32 *obj, void *str, u16 x, s16_021BB6E0 y, u16 color)
{
    void *print = work->printSys;

    PRINTSYS_PrintQueColor(print, (u32)func_02045770((struct Descriptor *)*obj), (s16_021BB6E0)x, y, str, work->menuTaskArg, color);
    *((unsigned char *)obj + 4) = 1;
}





void ITEMMENU_FlushWindowAt(void **p)
{
    BMP_WIN_MakeScreen(*p);
    func_02041B6C(func_02045730(*p));
}


/* Window whose text was printed: once the print system has finished with its
 * buffer, flushes the window to VRAM and clears the dirty flag. */
static inline void flushWindow(ItemMenuWork *work, ItemMenuWindow *slot)
{
    void *printSys = work->printSys;
    if (slot->isDirty != 0) {
        if (func_0201C6C4(printSys, (void *)((u32)func_02045770((struct Descriptor *)slot->window))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)slot->window);
            slot->isDirty = 0;
        }
    }
}

void ITEMMENU_FlushDirtyWindows(ItemMenuWork *work)
{
    PRINTSYS_QUE_Main(work->printSys);
    flushWindow(work, &work->listWindows[0]);
    flushWindow(work, &work->listWindows[1]);
    flushWindow(work, &work->listWindows[2]);
    flushWindow(work, &work->listWindows[3]);
    flushWindow(work, &work->listWindows[4]);
    flushWindow(work, &work->listWindows[5]);
    flushWindow(work, &work->listWindows[6]);
    flushWindow(work, &work->listWindows[7]);
    flushWindow(work, &work->listWindows[8]);
    flushWindow(work, &work->messageWindows[0]);
    flushWindow(work, &work->messageWindows[1]);
}
