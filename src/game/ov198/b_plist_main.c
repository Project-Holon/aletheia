/*
 * file:     b_plist_main.c
 * unit:     yes
 * function: B_PLIST_MAIN_SyncMoveActors, B_PLIST_MAIN_SetActorAnimSeq, B_PLIST_MAIN_GetMonAnimState, B_PLIST_MAIN_UpdateActorAnims, B_PLIST_MAIN_CreateToolActors, B_PLIST_MAIN_ShiftActors, B_PLIST_MAIN_SwapActorPos, B_PLIST_MAIN_Create, B_PLIST_MAIN_Task, B_PLIST_MAIN_Init, B_PLIST_MAIN_WaitPrintQue, B_PLIST_MAIN_WaitWipe, B_PLIST_MAIN_HandleSelectInput, B_PLIST_MAIN_ConfirmSelect, B_PLIST_MAIN_HandleModeSelect, B_PLIST_MAIN_HandleListSelect, B_PLIST_MAIN_HandleMoveSelect, B_PLIST_MAIN_HandleSlotSelect, B_PLIST_MAIN_HandleSlotSelectFade, B_PLIST_MAIN_HandleItemSelect, B_PLIST_MAIN_HandleConfirmCancel, B_PLIST_MAIN_EnterState1A, B_PLIST_MAIN_HandlePartySelect, B_PLIST_MAIN_ApplyPartyListPage, B_PLIST_MAIN_ApplyMonMenuPage, B_PLIST_MAIN_ApplySummaryPage, B_PLIST_MAIN_ApplyMoveListPage, B_PLIST_MAIN_ApplyMoveDetailPage, B_PLIST_MAIN_ApplyMoveListWithNewMovePage, B_PLIST_MAIN_ApplyMoveDetailWithNewMovePage, B_PLIST_MAIN_ApplyMoveListForItemPage, B_PLIST_MAIN_RedrawByMode, B_PLIST_MAIN_RefreshAndState16, B_PLIST_MAIN_ClearPrintStream, B_PLIST_MAIN_WaitPrintStream, B_PLIST_MAIN_HandleSkipKey, B_PLIST_MAIN_CheckBusyFlag, B_PLIST_MAIN_BeginFadeOut, B_PLIST_MAIN_WaitFadeOut, B_PLIST_MAIN_Delete, B_PLIST_MAIN_InitBg, B_PLIST_MAIN_ExitBg, B_PLIST_MAIN_LoadGraphics, B_PLIST_MAIN_CreateTextResources, B_PLIST_MAIN_DeleteTextResources, B_PLIST_MAIN_ReadSummary, B_PLIST_MAIN_ReadParty, B_PLIST_MAIN_HandleCursorInput, B_PLIST_MAIN_GetSlotState, B_PLIST_MAIN_NextSelectable, B_PLIST_MAIN_DrawExpBar, B_PLIST_MAIN_ApplyMode, B_PLIST_MAIN_LoadModePalette, B_PLIST_MAIN_GetRowStatus, B_PLIST_MAIN_PrintStatusMessage, B_PLIST_MAIN_IsRowFlagged, B_PLIST_MAIN_GetOwnerFlag18, B_PLIST_MAIN_IsBattleSlot, B_PLIST_MAIN_CheckMoveUsable, B_PLIST_MAIN_IsSlotSelectable, B_PLIST_MAIN_IsIndexValid, B_PLIST_MAIN_IsIndexInParty, B_PLIST_MAIN_InitSelectionForMode, B_PLIST_MAIN_InitOrder, B_PLIST_MAIN_SwapOrder, B_PLIST_MAIN_IsInSelection, B_PLIST_MAIN_GetOrderIndex, B_PLIST_MAIN_SetSelectionEntry, B_PLIST_MAIN_PushSelectionPair, B_PLIST_MAIN_PopSelectionPair, B_PLIST_MAIN_BeginMode8, B_PLIST_MAIN_PrintRowMessage, B_PLIST_MAIN_ConfirmSwap, B_PLIST_MAIN_EndSwap, B_PLIST_MAIN_GetFramePos, B_PLIST_MAIN_CopyFrame, B_PLIST_MAIN_MoveActorByFlag, B_PLIST_MAIN_UpdateSwapFrames, B_PLIST_MAIN_FinishSwap, B_PLIST_MAIN_CanSwap, B_PLIST_MAIN_HasSwappable, B_PLIST_MAIN_CommitSwap, B_PLIST_MAIN_ClearSelection, B_PLIST_MAIN_CheckCancel, B_PLIST_MAIN_PlaySe, B_PLIST_MAIN_PlaySe2, B_PLIST_MAIN_CreateCursor, B_PLIST_MAIN_DeleteCursor, B_PLIST_MAIN_RecreateCursor, B_PLIST_MAIN_SetActorsVisible, B_PLIST_MAIN_LayoutCursorActors, B_PLIST_MAIN_ShowCursor, B_PLIST_MAIN_HideCursor, B_PLIST_MAIN_HideCursorOnTouch, B_PLIST_MAIN_MoveCursor
 * address:  0x0220F060
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   B_PLIST_DRAW_TransferCharacter 0x0220E82C thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   d_02211DA0 0x02211DA0 data a4
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   B_APP_TOOL_CreateActors 0x0220AF6C thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   TCB_AddTask 0x02030DA8 arm
 *   d_02212550 0x02212550 data a1
 *   TCBL_Main 0x020310C4 arm
 *   B_PLIST_ANM_StepPaletteAnim 0x0220B7AC thumb ov198
 *   B_PLIST_DRAW_UpdateToolWindows 0x0220E22C thumb ov198
 *   d_0221221C 0x0221221C data a4
 *   d_04001050 0x04001050 data a2
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   TCBL_Create 0x0203101C arm
 *   B_APP_TOOL_Create 0x0220AF40 thumb ov196
 *   B_PLIST_ANM_UpdateByMode 0x0220B848 thumb ov198
 *   B_PLIST_ANM_CopyPaletteSlot 0x0220BB94 thumb ov198
 *   B_PLIST_DRAW_Init 0x0220E2B4 thumb ov198
 *   B_PLIST_DRAW_LayoutActors 0x0220EA68 thumb ov198
 *   B_PLIST_ANM_CreateTileWindows 0x0220BC24 thumb ov198
 *   B_PLIST_DRAW_DrawModePage 0x0220BE2C thumb ov198
 *   B_PLIST_DRAW_ShowToolWindows 0x0220E25C thumb ov198
 *   PALANM_RequestFade 0x0202173C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_DRAW_ClearAndPrintStream 0x0220E13C thumb ov198
 *   B_PLIST_DRAW_FormatRowWord 0x0220E1D4 thumb ov198
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_PLIST_DRAW_PrintWordAndRefresh  0x0220D6AC  thumb  ov198
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   WIPE_SYS_ExeEnd 0x020221B8 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   B_PLIST_DRAW_DeleteActors 0x0220E74C thumb ov198
 *   B_PLIST_DRAW_DeleteAllWindows 0x0220BE04 thumb ov198
 *   TCBL_Destroy 0x02031140 arm
 *   B_APP_TOOL_Delete 0x0220AF64 thumb ov196
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_02212144 0x02212144 data a4
 *   d_02212174 0x02212174 data a4
 *   d_022121B4 0x022121B4 data a4
 *   d_02212154 0x02212154 data a4
 *   d_02212194 0x02212194 data a4
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   B_PLIST_ANM_CopyMonSpriteTiles 0x0220B120 thumb ov198
 *   B_PLIST_ANM_CopySubSpriteTiles 0x0220B3B4 thumb ov198
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   APP_ICON_GetStatusIconAnim 0x020276C4 thumb
 *   POKE_TOOL_GetLevelMinExp 0x02018544 thumb
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   d_02212130 0x02212130 data a1
 *   BGWINFRM_ScaleRatio 0x0202D01C thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   B_PLIST_DRAW_DeleteStateWindows 0x0220BDD4 thumb ov198
 *   B_PLIST_DRAW_CreateStateWindows 0x0220BC70 thumb ov198
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   d_022121D4 0x022121D4 data a4
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WAZA_TOOL_IsHmMove 0x0202F72C thumb
 *   d_02212138 0x02212138 data a4
 *   B_PLIST_DRAW_PrintHeader10 0x0220C688 thumb
 *   B_PLIST_DRAW_ShowSubWindow 0x0220E27C thumb
 *   BG_SYS_GetBuf 0x0204162C arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   data_02212550 0x02212550 data ov198
 *   B_PLIST_ANM_UpdateSelectedTile 0x0220BBF0 thumb ov198
 *   B_PLIST_DRAW_PrintHeader9 0x0220C67C thumb ov198
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   CURSOR_MOVE_SetMode 0x02025D24 thumb
 *   d_022122D4 0x022122D4 data a4
 *   d_022122A0 0x022122A0 data a4
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb
 *   B_APP_TOOL_LayoutActors  0x0220B000  thumb  ov196
 *   BGWINFRM_Create  0x0202C9B4  thumb  arm9
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb  arm9
 *   BGWINFRM_SetFrameData  0x0202CAC4  thumb  arm9
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb  arm9
 *   BGWINFRM_StartMove  0x0202CD64  thumb  arm9
 *   BGWINFRM_UpdateMoves  0x0202CD94  thumb  arm9
 *   BGWINFRM_IsMoving  0x0202CE40  thumb  arm9
 *   BGWINFRM_GetPos  0x0202CF98  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 */
#include "b_plist_types.h"

struct Obj;
struct Actor;
struct ClactVec2;
struct ClactVec2;
struct TcbSystem;
struct TcbTask;
struct Tcbl;
struct PrintSys;
struct MsgBank;
struct Sound;
struct Rec;
struct Rec3;
struct S02031140;
struct BgWinFrmWork;
struct PaletteFade;
struct GfFont;
struct U16Vec;
struct WordSet;
struct Summary;
struct CursorMove;







typedef struct {short x,y;} BPlistMainPair;











/* The DS code was built against a prototype with a byte tile index (the header takes a word). The host build uses the header. */
#ifdef __MWERKS__
#define BG_SYS_MarkTileDirty BG_SYS_MarkTileDirty_header
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_MarkTileDirty
extern void BG_SYS_MarkTileDirty(u8 bit);
#endif

#include "../arm9/arc_tool.h"
#include "../arm9/waza_tool.h"
struct Move {u16 id;u8 pp,up,kind,power,type,accuracy;};

struct Summary {
    void *mon;
    u16 species,attack,defense,speed,spAttack,spDefense,hp,maxHp;
    u8 ability,form;
    u8 level:7,egg:1;
    u8 gender:3,nature:4,flag:1;
    u16 abilityId,heldItem;
    u32 exp,lower,upper,personality;
    struct Move moves[4];
};

struct Order {u8 ids[6];};




























#include "b_plist_draw.h"
struct ClactActor;
#include "../arm9/clact.h"
#include "../arm9/bgwinfrm.h"
#include "../ov196/b_app_tool.h"
struct ClactVec2;
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/tcb_list.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "b_plist_anm.h"
#include "../arm9/gx.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/wipe.h"
#include "../arm9/file_util.h"
struct Strbuf;
#include "../arm9/msgdata.h"
struct Cursor;
#include "../arm9/cursor_move.h"
struct BmpWin;
#include "../arm9/bmp_menuwork.h"
struct TextPrinter;
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
struct BgWinFrmWork;
struct TcbTask;
#include "../arm9/arc_util.h"
#include "../arm9/palanm.h"
/* palanm.h does not declare these yet */
/* palanm.h does not declare these yet */
#include "../arm9/mi_memory.h"
#include "../arm9/gf_font.h"
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
#include "../arm9/app_icon.h"
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/event_id.h"
#include "../arm9/gfl_use.h"
struct CursorVtbl;
struct CursorEntry;
void B_PLIST_MAIN_SyncMoveActors(struct B_PlistWork *p);
void B_PLIST_MAIN_SetActorAnimSeq(struct ClactActor *a, u16 b);
u16 B_PLIST_MAIN_GetMonAnimState(struct B_PlistWork *p);
void B_PLIST_MAIN_UpdateActorAnims(struct B_PlistWork *p);
void B_PLIST_MAIN_CreateToolActors(struct B_PlistWork *p);
void B_PLIST_MAIN_ShiftActors(struct B_PlistWork *p,int a,short delta);
void B_PLIST_MAIN_SwapActorPos(struct B_PlistWork *p, int slotA, int slotB);
void B_PLIST_MAIN_Create(struct B_PlistHost *host);
void B_PLIST_MAIN_Task(struct TcbTask *task, void *arg);
int B_PLIST_MAIN_Init(struct B_PlistWork *p);
int B_PLIST_MAIN_WaitPrintQue(struct B_PlistWork *p);
int B_PLIST_MAIN_WaitWipe(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleSelectInput(struct B_PlistWork *p);
int B_PLIST_MAIN_ConfirmSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleModeSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleListSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleMoveSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleSlotSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleSlotSelectFade(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleItemSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleConfirmCancel(struct B_PlistWork *p);
u32 B_PLIST_MAIN_EnterState1A(struct B_PlistWork *p);
int B_PLIST_MAIN_HandlePartySelect(struct B_PlistWork *p);
u32 B_PLIST_MAIN_ApplyPartyListPage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMonMenuPage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplySummaryPage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMoveListPage(struct B_PlistWork *a);
int B_PLIST_MAIN_ApplyMoveDetailPage(struct B_PlistWork *p);
u32 B_PLIST_MAIN_ApplyMoveListWithNewMovePage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMoveDetailWithNewMovePage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMoveListForItemPage(struct B_PlistWork *a);
int B_PLIST_MAIN_RedrawByMode(struct B_PlistWork *p);
u32 B_PLIST_MAIN_RefreshAndState16(struct B_PlistWork *p);
u32 B_PLIST_MAIN_ClearPrintStream(struct B_PlistWork *p);
int B_PLIST_MAIN_WaitPrintStream(struct B_PlistWork *a);
int B_PLIST_MAIN_HandleSkipKey(struct B_PlistWork *p);
int B_PLIST_MAIN_CheckBusyFlag(struct B_PlistWork *p);
int B_PLIST_MAIN_BeginFadeOut(struct B_PlistWork *p);
u32 B_PLIST_MAIN_WaitFadeOut(struct B_PlistWork *p);
int B_PLIST_MAIN_Delete(struct TcbTask *task,struct B_PlistWork *p);
void B_PLIST_MAIN_InitBg(struct B_PlistWork *p);
void B_PLIST_MAIN_ExitBg(void);
void B_PLIST_MAIN_LoadGraphics(struct B_PlistWork *p);
void B_PLIST_MAIN_CreateTextResources(struct B_PlistWork *p);
void B_PLIST_MAIN_DeleteTextResources(struct B_PlistWork *p);
void B_PLIST_MAIN_ReadSummary(void *unused,void *mon,struct Summary *p);
void B_PLIST_MAIN_ReadParty(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleCursorInput(struct B_PlistWork *p);
int B_PLIST_MAIN_GetSlotState(struct B_PlistWork *p,int i);
u8 B_PLIST_MAIN_NextSelectable(struct B_PlistWork *p,int i,int delta);
void B_PLIST_MAIN_DrawExpBar(struct B_PlistWork *p,int mode);
int B_PLIST_MAIN_ApplyMode(struct B_PlistWork *p,unsigned mode);
void B_PLIST_MAIN_LoadModePalette(struct B_PlistWork *p,u32 n);
int B_PLIST_MAIN_GetRowStatus(struct B_PlistWork *p);
int B_PLIST_MAIN_PrintStatusMessage(struct B_PlistWork *p);
u8 B_PLIST_MAIN_IsRowFlagged(struct B_PlistWork *p);
int B_PLIST_MAIN_GetOwnerFlag18(struct B_PlistWork *p);
u32 B_PLIST_MAIN_IsBattleSlot(struct B_PlistWork *a, u32 b);
u32 B_PLIST_MAIN_CheckMoveUsable(struct B_PlistWork *p);
int B_PLIST_MAIN_IsSlotSelectable(struct B_PlistWork *p,int i);
int B_PLIST_MAIN_IsIndexValid(struct B_PlistWork *p, unsigned int v);
unsigned B_PLIST_MAIN_IsIndexInParty(struct B_PlistWork *p, int index);
void B_PLIST_MAIN_InitSelectionForMode(struct B_PlistWork *p, u32 state);
void B_PLIST_MAIN_InitOrder(struct B_PlistWork *p);
void B_PLIST_MAIN_SwapOrder(struct B_PlistWork *p, int a, int b);
u32 B_PLIST_MAIN_IsInSelection(struct B_PlistWork *p, u32 c);
int B_PLIST_MAIN_GetOrderIndex(struct B_PlistWork *p, int i);
void B_PLIST_MAIN_SetSelectionEntry(struct B_PlistWork *p, u32 b, u32 c);
void B_PLIST_MAIN_PushSelectionPair(struct B_PlistWork *p, int a, int b);
int B_PLIST_MAIN_PopSelectionPair(struct B_PlistWork *p, unsigned char *a, unsigned char *b, int clear);
int B_PLIST_MAIN_BeginMode8(struct B_PlistWork *p);
int B_PLIST_MAIN_PrintRowMessage(struct B_PlistWork *p);
int B_PLIST_MAIN_ConfirmSwap(struct B_PlistWork *p);
int B_PLIST_MAIN_EndSwap(struct B_PlistWork *p);
void B_PLIST_MAIN_GetFramePos(u8 *a, u8 *b, unsigned int c);
void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which);
void B_PLIST_MAIN_MoveActorByFlag(struct B_PlistWork *p, int a, int b);
int B_PLIST_MAIN_UpdateSwapFrames(struct B_PlistWork *p);
int B_PLIST_MAIN_FinishSwap(struct B_PlistWork *p);
int B_PLIST_MAIN_CanSwap(struct B_PlistWork *p);
int B_PLIST_MAIN_HasSwappable(struct B_PlistWork *p);
void B_PLIST_MAIN_CommitSwap(struct B_PlistWork *p);
void B_PLIST_MAIN_ClearSelection(struct B_PlistWork *p);
u32 B_PLIST_MAIN_CheckCancel(struct B_PlistWork *p);
void B_PLIST_MAIN_PlaySe(struct B_PlistWork *p, u32 b);
void B_PLIST_MAIN_PlaySe2(struct B_PlistWork *p, u32 b);
void B_PLIST_MAIN_CreateCursor(struct B_PlistWork *p,u32 index,u32 b);
u32 B_PLIST_MAIN_DeleteCursor(struct B_PlistWork *p);
void B_PLIST_MAIN_RecreateCursor(struct B_PlistWork *p, u32 a, u32 b);
void B_PLIST_MAIN_SetActorsVisible(struct B_PlistWork *p, u32 v);
void B_PLIST_MAIN_LayoutCursorActors(struct B_PlistWork *p, u32 idx);
extern u32 d_02211DA0[];
extern const char d_02212550[];
extern volatile u16 d_04001050[];
extern const struct DispConfig d_02212144;
extern const struct BgTemplate d_02212174,d_022121B4,d_02212154,d_02212194;
extern const struct Order d_02212130;
extern const u32 d_022121D4[];
extern u8 d_02212138[][6];
extern u8 data_02212550[];
extern struct CursorEntry *const d_022122D4[];
extern const struct CursorVtbl d_022122A0;




void B_PLIST_MAIN_SyncMoveActors(struct B_PlistWork *p)
{
  struct B_PlistSlot *rec;
  u8 *objects;
  int base;
  unsigned long offset;
  int i;
  u8 *b;
  int slot;
  u8 *tmp;
  rec = &p->slot[B_PLIST_MAIN_GetOrderIndex(p, p->owner->orderIndex)];
  if (p->winFlags.flipB == 0)
  {
    base = 29;
    slot = 12;
  }
  else
  {
    base = 34;
    slot = 17;
  }
  objects = (u8 *)p + (base * (int)sizeof(void *));
  for (i = 0; i < 4u; i++)
  {
    if (rec->move[i].id != 0)
    {
      offset = i * 4;
      b = objects + offset * (sizeof(void *) / 4);
      B_PLIST_DRAW_TransferCharacter(p, ((struct B_PlistWork *)b)->actor[0], slot + i, rec->move[i].type);
      tmp = (u8 *) d_02211DA0;
      B_PLIST_DRAW_PlaceActor(((struct B_PlistWork *)b)->actor[0], (const struct ClactVec2 *)(tmp + offset));
    }
  }

  if ((p->owner->moveId != 0) && (p->owner->listType == 4))
  {
    B_PLIST_DRAW_TransferCharacter(p, p->actor[base + i], slot + i, WAZA_TOOL_GetParam(p->owner->moveId, 0));
    B_PLIST_DRAW_PlaceActor(p->actor[base + i], (const struct ClactVec2 *)(d_02211DA0 + i));
  }
  p->winFlags.flipB ^= 1;
}





void B_PLIST_MAIN_SetActorAnimSeq(struct ClactActor *a, u16 b)
{
    if (b != CLACT_GetActorAnimSeq(a))
    {
        CLACT_SetActorAnimFrame(a, 0);
        CLACT_SetActorAnimSeq(a, b);
    }
}




u16 B_PLIST_MAIN_GetMonAnimState(struct B_PlistWork *p)
{
    u16 a=((struct B_PlistSlot *)p)->hp;
    if (a==0) return 0;
    if (((struct B_PlistSlot *)p)->statusFlags.kind!=8 && ((struct B_PlistSlot *)p)->statusFlags.kind!=6) return 5;
    if (a==((struct B_PlistSlot *)p)->maxHp) return 1;
    switch (BGWINFRM_GetScaleRank(a,((struct B_PlistSlot *)p)->maxHp)) {
    case 0: return 2;
    case 1: return 3;
    case 2: return 4;
    }
    return 0;
}




void B_PLIST_MAIN_UpdateActorAnims(struct B_PlistWork *p)
{
    u16 i;
    int j;
    for (i=0;i<6;i++) {
        j=B_PLIST_MAIN_GetOrderIndex(p,i);
        if (p->slot[j].species) {
            u16 k=B_PLIST_MAIN_GetMonAnimState(((void *)&p->slot[j]));
            B_PLIST_MAIN_SetActorAnimSeq(p->actor[j + 7],k);
            CLACT_AddActorAnimFrame(p->actor[j + 7],0x1000);
        }
    }
}




void B_PLIST_MAIN_CreateToolActors(struct B_PlistWork *p) { B_APP_TOOL_CreateActors(*(char * *)&p->appTool,*(struct Unit **)&p->unit,p->charId[24],p->palId[4],p->cellId[4]);B_APP_TOOL_SetActorsVisible(*(char * *)&p->appTool,0); }




void B_PLIST_MAIN_ShiftActors(struct B_PlistWork *p,int a,short delta)
{
    int i=B_PLIST_MAIN_GetOrderIndex(p,a);
    BPlistMainPair pair;
    CLACT_GetActorSurfacePos(*(void **)((char *)&p->actor[0] + i * (int)sizeof(void *)),(struct ClactVec2 *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)((char *)&p->actor[0] + i * (int)sizeof(void *)),(struct ClactVec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)((char *)&p->actor[7] + i * (int)sizeof(void *)),(struct ClactVec2 *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)((char *)&p->actor[7] + i * (int)sizeof(void *)),(struct ClactVec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)((char *)&p->actor[13] + i * (int)sizeof(void *)),(struct ClactVec2 *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)((char *)&p->actor[13] + i * (int)sizeof(void *)),(struct ClactVec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)((char *)&p->actor[19] + i * (int)sizeof(void *)),(struct ClactVec2 *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)((char *)&p->actor[19] + i * (int)sizeof(void *)),(struct ClactVec2 *)(&pair),1);
}





void B_PLIST_MAIN_SwapActorPos(struct B_PlistWork *p, int slotA, int slotB)
{
    int i1 = B_PLIST_MAIN_GetOrderIndex(p, slotA);
    int i2 = B_PLIST_MAIN_GetOrderIndex(p, slotB);
    u32 x;
    u32 y;

    CLACT_GetActorSurfacePos((&p->actor[0])[i1], (struct ClactVec2 *)&x, 1);
    CLACT_GetActorSurfacePos((&p->actor[0])[i2], (struct ClactVec2 *)&y, 1);
    CLACT_AddActorSurfacePos((&p->actor[0])[i1], (struct ClactVec2 *)(&y), 1);
    CLACT_AddActorSurfacePos((&p->actor[0])[i2], (struct ClactVec2 *)(&x), 1);

    CLACT_GetActorSurfacePos((&p->actor[7])[i1], (struct ClactVec2 *)&x, 1);
    CLACT_GetActorSurfacePos((&p->actor[7])[i2], (struct ClactVec2 *)&y, 1);
    CLACT_AddActorSurfacePos((&p->actor[7])[i1], (struct ClactVec2 *)(&y), 1);
    CLACT_AddActorSurfacePos((&p->actor[7])[i2], (struct ClactVec2 *)(&x), 1);

    CLACT_GetActorSurfacePos((&p->actor[13])[i1], (struct ClactVec2 *)&x, 1);
    CLACT_GetActorSurfacePos((&p->actor[13])[i2], (struct ClactVec2 *)&y, 1);
    CLACT_AddActorSurfacePos((&p->actor[13])[i1], (struct ClactVec2 *)(&y), 1);
    CLACT_AddActorSurfacePos((&p->actor[13])[i2], (struct ClactVec2 *)(&x), 1);

    CLACT_GetActorSurfacePos((&p->actor[19])[i1], (struct ClactVec2 *)&x, 1);
    CLACT_GetActorSurfacePos((&p->actor[19])[i2], (struct ClactVec2 *)&y, 1);
    CLACT_AddActorSurfacePos((&p->actor[19])[i1], (struct ClactVec2 *)(&y), 1);
    CLACT_AddActorSurfacePos((&p->actor[19])[i2], (struct ClactVec2 *)(&x), 1);
}




void B_PLIST_MAIN_Create(struct B_PlistHost *host)
{
    struct B_PlistWork *work;
    if (host->orderIndex>5) host->orderIndex=0;
    work=GFL_HEAP_Alloc(host->heapId,sizeof(struct B_PlistWork),1,d_02212550,0x130);
    TCB_AddTask((struct TcbSystem *)host->fadeContext,B_PLIST_MAIN_Task,(void *)work,100);
    work->owner=host;
    if (host->listType!=5) host->order[3]=0;
    else if (B_PLIST_MAIN_GetOwnerFlag18(work)==1 && host->isSecondTeam==1) host->orderIndex++;
    work->palAnm=host->palAnm;
    work->state=0;
    work->orderIndex=host->orderIndex;
    work->done=0;
}




extern int (*const d_0221221C[])(struct B_PlistWork *);




void B_PLIST_MAIN_Task(struct TcbTask *task, void *arg)
{
    struct B_PlistWork *p = arg;
    if (p->owner->exitRequest==1) {
        B_PLIST_MAIN_ClearSelection(p);
        p->state=33;
    }
    if (p->state!=33)
        p->state=d_0221221C[p->state](p);
    if (p->state==33 && B_PLIST_MAIN_Delete(task,p)==1) return;
    TCBL_Main(p->tcbl);
    B_PLIST_MAIN_UpdateActorAnims(p);
    B_PLIST_ANM_StepPaletteAnim(p);
    B_PLIST_DRAW_UpdateToolWindows(p);
}




/*
 * volatile: hardware halfword store at 0220F4EC writes display register 04001050.
 */
int B_PLIST_MAIN_Init(struct B_PlistWork *p)
{
    d_04001050[0]=0;
    GXx_SetMasterBrightness_((u16 *)((char *)d_04001050+28),-16);
    p->tcbl=TCBL_Create(p->owner->heapId,p->owner->heapId,1,4);
    if(p->owner->listType==4) p->mode=6;
    else if(p->owner->listType==5) p->mode=4;
    else p->mode=0;
    p->appTool=B_APP_TOOL_Create(p->owner->heapId);
    B_PLIST_MAIN_InitOrder(p);B_PLIST_MAIN_ReadParty(p);B_PLIST_MAIN_InitBg(p);B_PLIST_MAIN_LoadGraphics(p);B_PLIST_MAIN_CreateTextResources(p);
    B_PLIST_MAIN_LoadModePalette(p,p->mode);B_PLIST_ANM_UpdateByMode(p,p->mode);B_PLIST_ANM_CopyPaletteSlot(p,p->mode);
    B_PLIST_DRAW_Init(p);
    if(p->owner->listType==5) B_PLIST_MAIN_SyncMoveActors(p);
    B_PLIST_DRAW_LayoutActors(p,p->mode);B_PLIST_ANM_CreateTileWindows(p);B_PLIST_DRAW_DrawModePage(p,p->mode);B_PLIST_DRAW_ShowToolWindows(p);
    if(**(u8 * *)&p->owner->syncFlagPtr==1) *(u32 *)&p->syncRequested=1;
    else *(u32 *)&p->syncRequested=0;
    B_APP_TOOL_SetActorsVisible((char *)(*(u8 * *)&p->appTool),p->syncRequested);
    if(p->mode==0) {
        if(B_PLIST_MAIN_IsBattleSlot(p,B_PLIST_MAIN_GetOrderIndex(p,0))==1) p->owner->orderIndex=1;
        B_PLIST_MAIN_CreateCursor(p,p->mode,p->owner->orderIndex);
    } else if(p->owner->listType==5) B_PLIST_MAIN_CreateCursor(p,p->mode,p->owner->order[3]);
    else B_PLIST_MAIN_CreateCursor(p,p->mode,0);
    B_PLIST_MAIN_DrawExpBar(p,p->mode);
    PALANM_RequestFade((struct PaletteFade *)(const struct PaletteFade *)p->palAnm,10,65535,0,16,0,0,p->owner->fadeContext);
    p->done=1;
    return 1;
}




int B_PLIST_MAIN_WaitPrintQue(struct B_PlistWork *p) { if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(const struct PrintSys * *)&p->printQue))==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,p->owner->heapId);return 2;}return 1; }




int B_PLIST_MAIN_WaitWipe(struct B_PlistWork *p) { if(WIPE_SYS_EndCheck()==1) { if(p->owner->listType==4)return 25; if(p->owner->listType==5)return 30; return 3; } return 2; }




int B_PLIST_MAIN_HandleSelectInput(struct B_PlistWork *p)
{
    u8 pair[2];
    if(PALANM_GetFadeRequestBits((const struct PaletteFade *)*(char * *)&p->palAnm)!=0) return 3;
    if(B_PLIST_MAIN_CheckCancel(p)==1) return 31;
    if(B_PLIST_MAIN_HandleCursorInput(p)==1) {
        if(p->owner->orderIndex==6) {
            if(p->owner->listType==2) {
                if(B_PLIST_MAIN_PopSelectionPair(p,pair+1,pair,1)==1) {
                    if(pair[1]<pair[0]) (*(u8 * *)&p->owner+pair[1])[72]=255;
                    else (*(u8 * *)&p->owner+pair[0])[72]=255;
                    p->flag2499=pair[1];
                    p->flag249A=pair[0];
                    p->animStep=0;
                    B_PLIST_MAIN_PlaySe(p,1362);
                    return 9;
                }
            } else if(p->owner->listType!=1) {
                B_PLIST_MAIN_PlaySe(p,1362);
                B_PLIST_ANM_StartPaletteAnim(p,6);
                B_PLIST_MAIN_ClearSelection(p);
                return 31;
            }
        } else {
            B_PLIST_MAIN_PlaySe(p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,p->owner->orderIndex);
            if(p->owner->listType==3) return B_PLIST_MAIN_ConfirmSelect(p);
            p->nextState=12;
            return 29;
        }
    }
    return 3;
}




int B_PLIST_MAIN_ConfirmSelect(struct B_PlistWork *p)
{
    struct B_PlistHost *q = p->owner;
    if ((&p->slot[B_PLIST_MAIN_GetOrderIndex(p,q->orderIndex)])->statusFlags.high != 0) {
        MSGDATA_ReadString(p->msgBank,91,p->strBuf);
        B_PLIST_DRAW_ClearAndPrintStream(p);
        p->owner->orderIndex = 6;
        p->nextState = 31;
        B_PLIST_MAIN_ClearSelection(p);
        return 23;
    }
    if (q->slotFlags[B_PLIST_MAIN_GetOrderIndex(p,q->orderIndex)] != 0) {
        B_PLIST_DRAW_FormatRowWord(p);
        B_PLIST_DRAW_ClearAndPrintStream(p);
        p->owner->orderIndex = 6;
        p->nextState = 31;
        B_PLIST_MAIN_ClearSelection(p);
        return 23;
    }
    if (FILE_UTIL_GetItemParam((unsigned int)q->itemId,39,q->heapId) != 0 &&
        FILE_UTIL_GetItemParam((unsigned int)q->itemId,40,q->heapId) == 0) {
        p->nextState = 18;
        return 29;
    }
    q->order[0] = B_PLIST_MAIN_GetOrderIndex(p,q->orderIndex);
    return 31;
}




int B_PLIST_MAIN_HandleModeSelect(struct B_PlistWork *p)
{
    u32 sel;
    struct B_PlistHost *q;
    if(B_PLIST_MAIN_CheckCancel(p)==1) return 31;
    sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel) {
    case 0:
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,7);
        if(B_PLIST_MAIN_PrintStatusMessage(p)==1) {
            q=p->owner;
            if(q->listType!=2) {
                q->order[q->pickIndex]=B_PLIST_MAIN_GetOrderIndex(p,q->orderIndex);
                return 31;
            }
            if(B_PLIST_MAIN_CanSwap(p)==0) {B_PLIST_MAIN_CommitSwap(p);return 31;}
            p->nextState=19;return 29;
        }
        p->nextState=21;return 29;
    case 1:
        if(B_PLIST_MAIN_IsRowFlagged(p)==1) break;
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,8);
        p->nextState=13;return 29;
    case 2:
        if(B_PLIST_MAIN_IsRowFlagged(p)==1) break;
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,10);
        p->nextState=14;return 29;
    case 3:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->nextState=11;return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->nextState=11;return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 4;
}




int B_PLIST_MAIN_HandleListSelect(struct B_PlistWork *p)
{
    u32 sel;
    u8 next;
    if(B_PLIST_MAIN_CheckCancel(p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel){
    case 0:
        next=B_PLIST_MAIN_NextSelectable(p,p->owner->orderIndex,-1);
        if(next!=255){
            p->owner->orderIndex=next;
            B_PLIST_MAIN_PlaySe(p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,12);
            p->nextState=20;
            return 29;
        }
        break;
    case 1:
        next=B_PLIST_MAIN_NextSelectable(p,p->owner->orderIndex,1);
        if(next!=255){
            p->owner->orderIndex=next;
            B_PLIST_MAIN_PlaySe(p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,13);
            p->nextState=20;
            return 29;
        }
        break;
    case 2:
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,11);
        p->nextState=14;
        return 29;
    case 3:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->flag2190=1;
        p->nextState=12;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->flag2190=1;
        p->nextState=12;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 5;
}




/*
 * Width: original narrows state to u8 before 0220B760; extern preserves caller truncation despite owner u32 state.
 */
int B_PLIST_MAIN_HandleMoveSelect(struct B_PlistWork *p)
{
    u32 sel;
    struct B_PlistWork *row;
    u8 next;
    if(B_PLIST_MAIN_CheckCancel(p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel){
    case 0: case 1: case 2: case 3:
        row=(struct B_PlistWork *)((u8 *)p+B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex)*sizeof(struct B_PlistSlot));
        if(row->slot[0].move[sel].id!=0){
            B_PLIST_MAIN_PlaySe(p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)(sel+14));
            p->owner->order[3]=sel;
            p->nextState=15;
            return 29;
        }
        break;
    case 4:
        next=B_PLIST_MAIN_NextSelectable(p,p->owner->orderIndex,-1);
        if(next!=255){
            p->owner->orderIndex=next;
            B_PLIST_MAIN_PlaySe(p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)12);
            p->nextState=20;
            return 29;
        }
        break;
    case 5:
        next=B_PLIST_MAIN_NextSelectable(p,p->owner->orderIndex,1);
        if(next!=255){
            p->owner->orderIndex=next;
            B_PLIST_MAIN_PlaySe(p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)13);
            p->nextState=20;
            return 29;
        }
        break;
    case 6:
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)9);
        p->nextState=13;
        return 29;
    case 7:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        p->flag2190=2;
        p->nextState=12;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        p->flag2190=2;
        p->nextState=12;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 6;
}




int B_PLIST_MAIN_HandleSlotSelect(struct B_PlistWork *p)
{
    u32 sel;
    struct B_PlistWork *row;
    if(B_PLIST_MAIN_CheckCancel(p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel){
    case 0: case 1: case 2: case 3:
        if(p->owner->order[3]!=sel){
            row=(struct B_PlistWork *)((u8 *)p+B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex)*sizeof(struct B_PlistSlot));
            if(row->slot[0].move[sel].id!=0){
                B_PLIST_MAIN_PlaySe(p,1357);
                p->owner->order[3]=sel;
                return 15;
            }
        }
        break;
    case 4:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->nextState=14;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->nextState=14;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 7;
}




int B_PLIST_MAIN_HandleSlotSelectFade(struct B_PlistWork *p)
{
    u32 sel;
    struct B_PlistWork *row;
    if(PALANM_GetFadeRequestBits((const struct PaletteFade *)*(const char * *)&p->palAnm)!=0)return 30;
    if(B_PLIST_MAIN_CheckCancel(p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel){
    case 0: case 1: case 2: case 3:
        if(p->owner->order[3]!=sel){
            row=(struct B_PlistWork *)((u8 *)p+B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex)*sizeof(struct B_PlistSlot));
            if(row->slot[0].move[sel].id!=0){
                B_PLIST_MAIN_PlaySe(p,1357);
                p->owner->order[3]=sel;
                return 15;
            }
        }
        break;
    case 4:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        return 31;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        return 31;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 30;
}




int B_PLIST_MAIN_HandleItemSelect(struct B_PlistWork *p)
{
    u32 sel;
    u8 value;
    if(PALANM_GetFadeRequestBits((const struct PaletteFade *)*(const char * *)&p->palAnm)!=0)return 25;
    sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel){
    case 0: case 1: case 2: case 3: case 4:
        value=sel;
        p->owner->order[3]=value;
        p->flag2191=value;
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)(sel+22));
        p->nextState=17;
        return 29;
    case 5:
        B_PLIST_MAIN_PlaySe(p,1362);
        p->owner->order[3]=4;
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        return 31;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        p->owner->order[3]=4;
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        return 31;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 25;
}




int B_PLIST_MAIN_HandleConfirmCancel(struct B_PlistWork *p)
{
    u32 sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel){
    case 0:
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,27);
        if(B_PLIST_MAIN_CheckMoveUsable(p)==0)p->nextState=31;
        else p->nextState=27;
        return 29;
    case 1:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->flag2192=0;
        p->nextState=16;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->flag2192=0;
        p->nextState=16;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 26;
}





/*
 * Addresses are Black-image addresses.
 */
u32 B_PLIST_MAIN_EnterState1A(struct B_PlistWork *p)
{
    B_PLIST_DRAW_PrintWordAndRefresh(p);
    p->flag2193 = 1;
    p->nextState = 0x1a;
    return 0x17;
}




/*
 * lever: bounded permuter expanded row use, cast the row/column sum to u32,
 *   and captured the byte selection in tmp before calling B_PLIST_MAIN_GetOrderIndex.
 * Caller truncates the selection+18 argument to u8 before B_PLIST_ANM_StartPaletteAnim.
 */
int B_PLIST_MAIN_HandlePartySelect(struct B_PlistWork *p)
{
    u32 selection=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    u8 tmp;
    switch(selection) {
    case 0: case 1: case 2: case 3: {
        unsigned idx;
        u8 *row;
        tmp=p->owner->orderIndex;
        idx=B_PLIST_MAIN_GetOrderIndex(p,tmp);
        row=(u8 *)&p->slot[idx];
        if(((struct B_PlistSlot *)row)->move[selection].id==0) break;
        p->owner->order[3]=selection;
        p->owner->order[0]=idx;
        B_PLIST_MAIN_PlaySe(p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)(selection+18));
        return 31;
    }
    case 4:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->nextState=11;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe(p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p->nextState=11;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5:
    case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 28;
}





u32 B_PLIST_MAIN_ApplyPartyListPage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 0) == 0) {
        return 0xb;
    }
    return 0x3;
}





u32 B_PLIST_MAIN_ApplyMonMenuPage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 1) == 0) {
        return 0xc;
    }
    return 0x4;
}





u32 B_PLIST_MAIN_ApplySummaryPage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 2) == 0) {
        return 0xd;
    }
    return 0x5;
}





u32 B_PLIST_MAIN_ApplyMoveListPage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 3) == 0) {
        return 0xe;
    }
    return 0x6;
}





int B_PLIST_MAIN_ApplyMoveDetailPage(struct B_PlistWork *p)
{
    if (B_PLIST_MAIN_ApplyMode(p, 4) == 0)
    {
        return 0xf;
    }
    if (p->owner->listType == 5)
    {
        return 0x1e;
    }
    return 7;
}





u32 B_PLIST_MAIN_ApplyMoveListWithNewMovePage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 6) == 0) {
        return 0x10;
    }
    return 0x19;
}





u32 B_PLIST_MAIN_ApplyMoveDetailWithNewMovePage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 7) == 0) {
        return 0x11;
    }
    return 0x1a;
}





u32 B_PLIST_MAIN_ApplyMoveListForItemPage(struct B_PlistWork *a)
{
    if (B_PLIST_MAIN_ApplyMode(a, 5) == 0) {
        return 0x12;
    }
    return 0x1c;
}




int B_PLIST_MAIN_RedrawByMode(struct B_PlistWork *p) { B_PLIST_DRAW_LayoutActors(p,p->mode);B_PLIST_DRAW_DrawModePage(p,p->mode);B_PLIST_ANM_UpdateByMode(p,p->mode);B_PLIST_MAIN_DrawExpBar(p,p->mode);if(p->mode==2)return 5;return 6; }





u32 B_PLIST_MAIN_RefreshAndState16(struct B_PlistWork *p)
{
    B_PLIST_DRAW_ClearAndPrintStream(p);
    p->nextState = 0x16;
    return 0x17;
}





u32 B_PLIST_MAIN_ClearPrintStream(struct B_PlistWork *p)
{
    BMP_MENUWORK_DrawWindowBorder((void *)(p->win[1].handle), 0);
    return 4;
}





int B_PLIST_MAIN_WaitPrintStream(struct B_PlistWork *a)
{
    switch (PRINTSYS_PrintStreamGetState((void *)a->printStream)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3) != 0)
            PRINTSYS_PrintStreamShortWait((struct TextPrinter *)a->printStream, 0);
        a->printStreamFlags = 0;
        break;
    case 1:
        if (a->printStreamFlags != 0)
            break;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            B_PLIST_MAIN_PlaySe2(a, 0x547);
            PRINTSYS_PrintStreamReleasePause((void *)a->printStream);
            a->printStreamFlags = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)a->printStream);
        a->printStream = 0;
        a->printStreamFlags = 0;
        return 0x18;
    }
    return 0x17;
}




/*
 * remainder: separate conditional follower B_PLIST_MAIN_CheckBusyFlag.c (28 bytes).
 */
int B_PLIST_MAIN_HandleSkipKey(struct B_PlistWork *p)
{
    if (B_PLIST_MAIN_CheckCancel(p)==1) return 0x1f;
    if ((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()==1) {
        if (p->flag2193==1) {
            BMP_MENUWORK_DrawWindowBorder(p->win[1].handle,0);
            p->flag2193=0;
        }
        return p->nextState;
    }
    return 0x18;
}




int B_PLIST_MAIN_CheckBusyFlag(struct B_PlistWork *p)
{
    if (p->animFlags.active==0) return p->nextState;
    return 0x1d;
}




int B_PLIST_MAIN_BeginFadeOut(struct B_PlistWork *p)
{
    if (B_PLIST_MAIN_GetOwnerFlag18(p)==1 && p->owner->orderIndex!=6)
        p->owner->orderIndex/=2u;
    PALANM_RequestFade((struct PaletteFade *)(const struct PaletteFade *)p->palAnm,10,0xffff,0,0,0x10,0,p->owner->fadeContext);
    return 0x20;
}





u32 B_PLIST_MAIN_WaitFadeOut(struct B_PlistWork *p)
{
    if (PALANM_GetFadeRequestBits((const struct PaletteFade *)(const char *)((p->palAnm))) == 0) {
        return 0x21;
    }
    return 0x20;
}




int B_PLIST_MAIN_Delete(struct TcbTask *task,struct B_PlistWork *p)
{
    if(p->done==1) {
        if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&p->printQue))==0) {
            if(p->owner->exitRequest==1) PRINTSYS_QUE_Clear((struct PrintQueue *)(*(struct PrintSys * *)&p->printQue));
            else return 0;
        }
        if(WIPE_SYS_EndCheck()==0) {
            if(p->owner->exitRequest==1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if(*(struct Rec3 * *)&p->printStream) PRINTSYS_PrintStreamDelete((struct TextPrinter *)(*(struct Rec3 * *)&p->printStream));
        if(*(struct Obj * *)&p->bgWinFrame) BGWINFRM_Delete((struct BgWinFrmWork *)(*(struct Obj * *)&p->bgWinFrame));
        B_PLIST_MAIN_DeleteTextResources(p);
        B_PLIST_DRAW_DeleteActors(p);
        B_PLIST_DRAW_DeleteAllWindows(p);
        B_PLIST_MAIN_ExitBg();
        TCBL_Destroy((struct TcblSystem *)(*(struct S02031140 * *)&p->tcbl));
        B_PLIST_MAIN_DeleteCursor(p);
        B_APP_TOOL_Delete(p->appTool);
        if(p->syncRequested==1) **(u8 * *)&p->owner->syncFlagPtr=1;
        else **(u8 * *)&p->owner->syncFlagPtr=0;
    }
    p->owner->done=1;
    TCB_DeleteTask((struct TcbTask *)task);
    GFL_HEAP_Free(p);
    return 1;
}




void B_PLIST_MAIN_InitBg(struct B_PlistWork *p)
{
    struct DispConfig req=d_02212144;
    struct BgTemplate cfg7,cfg6,cfg5,cfg4;
    BG_SYS_ApplyGraphicsMode(&req,1);
    cfg7=d_02212174;
    BG_SYS_InitBgLayer(7,&cfg7,0);
    cfg6=d_022121B4;
    BG_SYS_InitBgLayer(6,&cfg6,0);
    cfg5=d_02212154;
    BG_SYS_InitBgLayer(5,&cfg5,0);
    BG_SYS_ClearSlot(5);
    cfg4=d_02212194;
    BG_SYS_InitBgLayer(4,&cfg4,0);
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(5,32,0,p->owner->heapId);
    BG_SYS_InitRun(4,32,0,p->owner->heapId);
    BG_SYS_MarkTileDirty(5);
    BG_SYS_MarkTileDirty(4);
    BG_SYS_SetSubPlaneVisible(15,1);
}





void B_PLIST_MAIN_ExitBg(void)
{
    BG_SYS_SetSubPlaneVisible(0x1f, 0);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}




void B_PLIST_MAIN_LoadGraphics(struct B_PlistWork *p)
{
    void *owner=ARC_TOOL_CreateHandle(100,(u16)((p->owner->heapId&0x7fff)|0x8000));
    void *handle;
    char *data;
    ARC_UTIL_UploadBgCharFromHandle(owner,18,7,0,0,1,p->owner->heapId);
    handle=ARC_UTIL_LoadPaletteDataFromHandle(owner,16,1,(void **)&data,p->owner->heapId);
    B_PLIST_ANM_CopyMonSpriteTiles(p,(u16 *)(data+12));
    GFL_HEAP_Free(handle);
    handle=ARC_UTIL_LoadPaletteDataFromHandle(owner,17,1,(void **)&data,p->owner->heapId);
    B_PLIST_ANM_CopySubSpriteTiles(p,(u16 *)(data+12));
    GFL_HEAP_Free(handle);
    PALANM_LoadArcPaletteToSlot(*(struct PaletteFade * *)&p->palAnm,100,19,p->owner->heapId,1,0x1e0,0);
    ARC_TOOL_DeleteHandle(owner);
    MI_CpuCopy8((void *)(PALANM_GetDefaultWork(p->palAnm,1) + 0xc0),p->palette,32);
    BMP_MENUWORK_LoadCharAndPltt(4,1,14,0,p->owner->heapId);
    PALANM_CopyHwPaletteToSlot(*(struct PaletteFade * *)&p->palAnm,1,0xe0,32);
    PALANM_LoadArcPaletteToSlot(*(struct PaletteFade * *)&p->palAnm,23,5,p->owner->heapId,1,32,0xd0);
}




void B_PLIST_MAIN_CreateTextResources(struct B_PlistWork *p)
{
    p->msgBank=MSGDATA_CreateFromArchive(0,2,0x12,p->owner->heapId);
    p->fontSmall=GF_FONT_Create(0x17,3,0,0,p->owner->heapId);
    p->wordSet=WORDSET_CreateDefault(p->owner->heapId);
    p->printQue=PRINTSYS_QUE_CreateEx(0x800,p->owner->heapId);
    p->strBuf=STRBUF_Create(0x200,p->owner->heapId);
}




void B_PLIST_MAIN_DeleteTextResources(struct B_PlistWork *p) { MSGDATA_Delete((struct MsgBank *)(*(struct Rec * *)&p->msgBank));GF_FONT_Delete(p->fontSmall);WORDSET_Delete(*(struct WordSet * *)&p->wordSet);PRINTSYS_QUE_Delete((struct PrintQueue *)(*(struct PrintSys * *)&p->printQue));STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&p->strBuf)); }




/*
 * lever: write upper experience to the same field in both if/else arms;
 *   one common store or a switch removes the original two-byte branch.
 * 2026-10-04: filed src/matched/arm9/POKE_TOOL_GetLevelMinExp.c (EXACT, 8 bytes); needs the label registered by the integrator, then this resolves.
 *   022107A8..0221099C. integrator-owned ARM9 Thumb tail stub, verified EXACT
 *   (8 bytes, 1/1 relocation resolved) in B9/blocker18544.log:
 *    *   extern u32 POKE_TOOL_GetBoxLevelMinExp(void *);
 *   u32 POKE_TOOL_GetLevelMinExp(void *p) {return POKE_TOOL_GetBoxLevelMinExp(p);}
 * 020276C4's matched legacy C has unused a1/a2/a3 parameters; this caller
 * and the callee body use only a0, so its declaration here has one argument.
 */
void B_PLIST_MAIN_ReadSummary(void *unused,void *mon,struct Summary *p)
{
    u32 exp;
    unsigned i;
    struct Move *move;
    struct Move *moves;
    p->mon=mon;
    if(mon==0) {
        p->species=0;
        return;
    }
    p->species=POKE_TOOL_GetPartyValue(mon,5,0);
    if(p->species==0) return;
    p->attack=POKE_TOOL_GetPartyValue(p->mon,0xa2,0);
    p->defense=POKE_TOOL_GetPartyValue(p->mon,0xa3,0);
    p->speed=POKE_TOOL_GetPartyValue(p->mon,0xa4,0);
    p->spAttack=POKE_TOOL_GetPartyValue(p->mon,0xa5,0);
    p->spDefense=POKE_TOOL_GetPartyValue(p->mon,0xa6,0);
    p->hp=POKE_TOOL_GetPartyValue(p->mon,0xa0,0);
    p->maxHp=POKE_TOOL_GetPartyValue(p->mon,0xa1,0);
    p->ability=POKE_TOOL_GetPartyValue(p->mon,0xae,0);
    p->form=POKE_TOOL_GetPartyValue(p->mon,0xaf,0);
    p->level=(u8)POKE_TOOL_GetPartyValue(p->mon,0x9e,0);
    if(POKE_TOOL_GetPartyValue(p->mon,0xad,0)==1) p->egg=0;
    else p->egg=1;
    p->gender=POKE_TOOL_GetGender(p->mon);
    p->nature=(u8)APP_ICON_GetStatusIconAnim(p->mon);
    p->flag=(u8)POKE_TOOL_GetPartyValue(p->mon,0x4c,0);
    p->abilityId=POKE_TOOL_GetPartyValue(p->mon,10,0);
    p->heldItem=POKE_TOOL_GetPartyValue(p->mon,6,0);
    p->personality=POKE_TOOL_GetPartyValue(p->mon,0x6f,0);
    p->exp=POKE_TOOL_GetPartyValue(p->mon,8,0);
    exp=POKE_TOOL_GetLevelMinExp(p->mon);
    p->lower=exp;
    if(p->level==100) p->upper=p->lower;
    else p->upper=POKE_TOOL_GetExpForLevel(p->species,(u16)p->personality,(u16)(p->level+1));
    i=0;
    moves=p->moves;
    for(;i<4;i++) {
        move=&moves[i];
        moves[i].id=POKE_TOOL_GetPartyValue(p->mon,i+0x36,0);
        if(moves[i].id==0) continue;
        move->pp=POKE_TOOL_GetPartyValue(p->mon,i+0x3a,0);
        move->up=POKE_TOOL_GetPartyValue(p->mon,i+0x3e,0);
        move->up=WAZA_TOOL_GetMaxPP(move->id,move->up);
        move->kind=WAZA_TOOL_GetParam(move->id,0);
        move->power=WAZA_TOOL_GetParam(move->id,2);
        if(WAZA_TOOL_IsAlwaysHit(move->id)==1) move->type=0;
        else move->type=WAZA_TOOL_GetParam(move->id,4);
        move->accuracy=WAZA_TOOL_GetParam(move->id,3);
    }
}




/*
 * remainder: two-byte alignment padding at 02210A4A.
 */
void B_PLIST_MAIN_ReadParty(struct B_PlistWork *p)
{
    unsigned i;
    if (p->owner->hasPartner==0) {
        for (i=0;i<6;i++) {
            if (i<POKEPARTY_GetCount(p->owner->party))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(p->owner->party,i),(struct Summary *)((char *)p->slot + i * (int)sizeof(struct B_PlistSlot)));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)((char *)p->slot + i * (int)sizeof(struct B_PlistSlot)));
        }
    } else {
        for (i=0;i<3;i++) {
            if (i<POKEPARTY_GetCount(p->owner->party))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(p->owner->party,i),(struct Summary *)((char *)p->slot + i * (int)sizeof(struct B_PlistSlot)));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)((char *)p->slot + i * (int)sizeof(struct B_PlistSlot)));
            if (i<POKEPARTY_GetCount(p->owner->partnerParty))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(p->owner->partnerParty,i),(struct Summary *)((char *)p->slot + (i+3) * (int)sizeof(struct B_PlistSlot)));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)((char *)p->slot + (i+3) * (int)sizeof(struct B_PlistSlot)));
        }
    }
}




int B_PLIST_MAIN_HandleCursorInput(struct B_PlistWork *p)
{
    u32 sel=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&p->cursorMove));
    switch(sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if(B_PLIST_MAIN_GetSlotState(p,sel)) {
            p->owner->orderIndex=sel;
            return 1;
        }
        break;
    case 6:
        p->owner->orderIndex=6;
        return 1;
    case (u32)-2:
        p->owner->orderIndex=6;
        return 1;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe(p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 0;
}




int B_PLIST_MAIN_GetSlotState(struct B_PlistWork *p,int i) { if(!p->slot[B_PLIST_MAIN_GetOrderIndex(p,i)].species)return 0;if(B_PLIST_MAIN_IsSlotSelectable(p,i)==1)return 1;return 2; }




u8 B_PLIST_MAIN_NextSelectable(struct B_PlistWork *p,int i,int delta)
{
    int current=i;
    if(B_PLIST_MAIN_GetOwnerFlag18(p)==1) {
        struct Order order=d_02212130;
        u8 selected;
        for(i=0;i<6;i++) if(current==order.ids[i]) break;
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            selected=order.ids[i];
            if(current==selected) break;
            if(!B_PLIST_MAIN_GetSlotState(p,selected)) continue;
            if((&p->slot[B_PLIST_MAIN_GetOrderIndex(p,selected)])->statusFlags.high) continue;
            return selected;
        }
    } else {
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            if(current==i) break;
            if(!B_PLIST_MAIN_GetSlotState(p,i)) continue;
            if((&p->slot[B_PLIST_MAIN_GetOrderIndex(p,i)])->statusFlags.high) continue;
            return i;
        }
    }
    return 255;
}


/*
 * Lever: the seven-bit unsigned byte field emits shifts and an unsigned
 * comparison while retaining the original entry-pointer scheduling.
 */
void B_PLIST_MAIN_DrawExpBar(struct B_PlistWork *p,int mode)
{
    u8 *q;
    u32 numerator,denominator;
    u8 amount,i;
    u16 tile;
    if(mode!=2) return;
    q=((void *)&p->slot[B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex)]);
    if(((struct B_PlistSlot *)q)->levelBits.level<100U) {
        denominator=((struct B_PlistSlot *)q)->expMax-((struct B_PlistSlot *)q)->expMin;
        numerator=((struct B_PlistSlot *)q)->expCurrent-((struct B_PlistSlot *)q)->expMin;
    } else { denominator=0; numerator=0; }
    amount=BGWINFRM_ScaleRatio(numerator,denominator,64);
    for(i=0;i<8;i++) {
        if(amount>=8) tile=30; else tile=amount+22;
        BG_SYS_SetTileEntry(7,tile,i+10,8,1,1,16);
        if(amount<8) amount=0; else amount-=8;
    }
    BG_SYS_MarkTileDirty(7);
}





/*
 * FCC receives only two loaded arguments here; mode is in 0..8, so its
 * out-of-domain incoming-r2 fallback is unused. BB94 receives live mode.
 */
int B_PLIST_MAIN_ApplyMode(struct B_PlistWork *p,unsigned mode)
{
    switch(p->stateFlags.step) {
    case 0:
        if(PRINTSYS_QUE_IsFinished(p->printQue)==1) {
            B_PLIST_DRAW_DeleteStateWindows(p);
            B_PLIST_DRAW_CreateStateWindows(p,mode);
            B_PLIST_DRAW_DrawModePage(p,mode);
            p->stateFlags.step=(u8)(p->stateFlags.step+1);
        }
        break;
    case 1:
        if(PRINTSYS_QUE_IsFinished(p->printQue)==1) {
            B_PLIST_MAIN_LoadModePalette(p,mode);
            BG_SYS_ClearLayerEx(4,0);
            BG_SYS_ClearLayerEx(5,0);
            B_PLIST_DRAW_ShowToolWindows(p);
            B_PLIST_MAIN_DrawExpBar(p,mode);
            B_PLIST_DRAW_LayoutActors(p,mode);
            B_PLIST_MAIN_InitSelectionForMode(p,mode);
            B_PLIST_ANM_UpdateByMode(p,mode);
            B_PLIST_ANM_CopyPaletteSlot(p,mode);
            p->mode=mode;
            p->stateFlags.step=0;
            return 1;
        }
        break;
    }
    return 0;
}





void B_PLIST_MAIN_LoadModePalette(struct B_PlistWork *p,u32 n)
{
    u32 i=0;
    const u32 *table=d_022121D4+n*2;
    u8 *out;
    void *buf;
    for(;i<2;i++) {
        buf=ARC_UTIL_LoadPaletteDataFromArchive(100,table[i],1,(&out),p->owner->heapId);
        BG_SYS_DrawTile((u8)(i+6),(out+12),0,0,32,24);
        BG_SYS_MarkTileDirty(i+6);
        GFL_HEAP_Free(buf);
    }
}





/*
 * Trailing 02210E1E halfword is zero alignment padding.
 */
int B_PLIST_MAIN_GetRowStatus(struct B_PlistWork *p)
{
    int index=B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex);
    u8 *q=((void *)&p->slot[index]);
    if(B_PLIST_MAIN_IsBattleSlot(p,index)==1) return 1;
    if(((struct B_PlistSlot *)q)->hp==0) return 2;
    if(B_PLIST_MAIN_IsSlotSelectable(p,p->owner->orderIndex)==1) return 3;
    if(B_PLIST_MAIN_IsRowFlagged(p)==1) return 5;
    if(B_PLIST_MAIN_IsIndexInParty(p,p->owner->orderIndex)==1) return 4;
    if(p->owner->moveId!=0) return 6;
    return 0;
}





/*
 * lever (wave 82 R8): the switch has no default arm. The image's `bhi`
 *   for a selector above 6 goes straight to the shared tail with `text`
 *   (r7) never assigned, exactly what the C says (see
 *   docs/idioms/switch-arms-tail-merge.md); matched B_PLIST_MAIN_GetRowStatus returns
 *   only 0..6, so that path is never taken. A `case 0: default: return 1;`
 *   arm is DIFF54. The `adds r5,r4,#4` above the multiply needs the index
 *   multiplied in its own statement after base (`index*=76;`); `76*f()`
 *   and `f()*76` initialisers are DIFF4.
 */
int B_PLIST_MAIN_PrintStatusMessage(struct B_PlistWork *p)
{
    u32 index=B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex);
    struct B_PlistSlot *base=p->slot;
    void *text;
    index*=sizeof(struct B_PlistSlot);
    switch((u32)B_PLIST_MAIN_GetRowStatus(p)) {
    case 1: text=MSGDATA_AllocString(p->msgBank,90); break;
    case 2:
        text=MSGDATA_AllocString(p->msgBank,87);
        WORDSET_SetSlotMonNickname(p->wordSet,0,((struct B_PlistSlot *)((u8 *)base+index))->mon);
        break;
    case 3:
        text=MSGDATA_AllocString(p->msgBank,86);
        WORDSET_SetSlotMonNickname(p->wordSet,0,((struct B_PlistSlot *)((u8 *)base+index))->mon);
        break;
    case 4:
        text=MSGDATA_AllocString(p->msgBank,103);
        WORDSET_SetSlotMonNickname(p->wordSet,0,((struct B_PlistSlot *)((u8 *)base+index))->mon);
        break;
    case 5: text=MSGDATA_AllocString(p->msgBank,89); break;
    case 6:
        index=sizeof(struct B_PlistSlot)*p->owner->pickIndex;
        text=MSGDATA_AllocString(p->msgBank,88);
        WORDSET_SetSlotMonNickname(p->wordSet,0,((struct B_PlistSlot *)((u8 *)base+index))->mon);
        break;
    case 0: return 1;
    }
    WORDSET_CopyTaggedText(p->wordSet,p->strBuf,text);
    STRBUF_Delete(text);
    return 0;
}





u8 B_PLIST_MAIN_IsRowFlagged(struct B_PlistWork *p) { 
if((&p->slot[B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex)])->statusFlags.high) return 1;
 return 0; }




int B_PLIST_MAIN_GetOwnerFlag18(struct B_PlistWork *p) { return p->owner->hasPartner; }





u32 B_PLIST_MAIN_IsBattleSlot(struct B_PlistWork *a, u32 b)
{
    if (B_PLIST_MAIN_GetOwnerFlag18(a) == 1 && b >= 3) {
        return 1;
    }
    return 0;
}




/*
 * lever: Group the unsigned address sum as base plus row, then column, then offset.
 */
u32 B_PLIST_MAIN_CheckMoveUsable(struct B_PlistWork *p)
{
    struct B_PlistHost *q;
    unsigned long i;
    struct B_PlistSlot *row;
    q=p->owner;
    i=q->order[3];
    if(i==4)return 0;
    row=&p->slot[q->orderIndex];
    return WAZA_TOOL_IsHmMove(q->gameData,row->move[i].id,q->heapId);
}




int B_PLIST_MAIN_IsSlotSelectable(struct B_PlistWork *p,int i) { u32 v;v=B_PLIST_MAIN_GetOrderIndex(p,i);if(B_PLIST_MAIN_GetOwnerFlag18(p)==1) {if(v==0 || v==3)return 1;return 0;}else {if(v<p->owner->partyCount)return 1;return 0;} }





int B_PLIST_MAIN_IsIndexValid(struct B_PlistWork *p, unsigned int v)
{
    return v < p->owner->partyCount;
}




unsigned B_PLIST_MAIN_IsIndexInParty(struct B_PlistWork *p, int index)
{
    unsigned selected = B_PLIST_MAIN_GetOrderIndex(p, index);
    struct B_PlistHost *q = p->owner;
    if (q->partyCount != 1) {
        if (selected == q->selected[0] || selected == q->selected[1]) return 1;
        return B_PLIST_MAIN_IsInSelection(p, selected);
    }
    return 0;
}




void B_PLIST_MAIN_InitSelectionForMode(struct B_PlistWork *p, u32 state)
{
    u32 value;
    switch(state) {
    case 0: case 8:
        p->flag2190=0;
        p->owner->order[3]=0;
        value=p->owner->orderIndex;
        break;
    case 1:
        p->owner->order[3]=0;
        value=p->flag2190;
        break;
    case 3: case 4:
        value=p->owner->order[3];
        break;
    case 6: value=p->flag2191; break;
    case 7: value=p->flag2192; break;
    case 2: case 5: value=0; break;
    }
    B_PLIST_MAIN_RecreateCursor(p,state,value);
}




/*
 * Lead 112 bytes includes two pool words; follower 022110A4 is a
 * 20-byte independent push/pop swap leaf. No padding remains.
 */
void B_PLIST_MAIN_InitOrder(struct B_PlistWork *p)
{
    unsigned i;
    if(p->owner->hasPartner==1) {
        for(i=0;i<6;i++) p->order[i]=d_02212138[p->owner->isSecondTeam][i];
    } else {
        for(i=0;i<6;i++) p->order[i]=i;
    }
    for(i=0;i<3;i++) (*(u8 * *)&p->owner+i)[72]=255;
    for(i=0;i<2;i++) {
        p->selPair[i].first=255;
        p->selPair[i].second=255;
    }
}




void B_PLIST_MAIN_SwapOrder(struct B_PlistWork *p, int a, int b)
{
    u8 *q=p->order;
    u8 t=q[a];
    q[a]=q[b];
    q[b]=t;
}





u32 B_PLIST_MAIN_IsInSelection(struct B_PlistWork *p, u32 c)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        if (c == p->owner->order[i]) {
            return 1;
        }
    }
    return 0;
}





/*
 * Recursive MATCH unblocker: named callee of the parked ov198 B_PLIST_DRAW_PrintStatRow0
 * (the first statement, `B_PLIST_MAIN_GetOrderIndex(a0)`, and every later use of the
 * resulting entry pointer).  `((struct B_PlistWork *)p)->order[i]` is what keeps the added index in
 * r1 and the 0x1cc constant in r0 (`ldrb r0,[r1,r0]`); the subscript form folds
 * the constant into the pointer add.  The two-byte follower is the listing's
 * alignment word, so the extent runs one word long.
 *
 * Addresses are Black-image addresses.
 */
int B_PLIST_MAIN_GetOrderIndex(struct B_PlistWork *p, int i)
{
    return p->order[i];
}





void B_PLIST_MAIN_SetSelectionEntry(struct B_PlistWork *p, u32 b, u32 c)
{
    u8 v = B_PLIST_MAIN_GetOrderIndex(p, c);

    p->owner->order[b] = v;
}




void B_PLIST_MAIN_PushSelectionPair(struct B_PlistWork *p, int a, int b)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (p->selPair[i].first == 0xff) {
            p->selPair[i].first = a;
            p->selPair[i].second = b;
            return;
        }
    }
}



int B_PLIST_MAIN_PopSelectionPair(struct B_PlistWork *p, unsigned char *a, unsigned char *b, int clear)
{
    int i;

    for (i = 1; i >= 0; i--) {
        if (*(unsigned short *)((u8 *)&p->selPair[0].first + i * (int)sizeof(p->selPair[0])) == 0xff) {
            continue;
        }
        *a = (unsigned char)*(unsigned short *)((u8 *)&p->selPair[0].first + i * (int)sizeof(p->selPair[0]));
        *b = (unsigned char)*(unsigned short *)((u8 *)&p->selPair[0].second + i * (int)sizeof(p->selPair[0]));
        if (clear == 1) {
            *(unsigned short *)((u8 *)&p->selPair[0].first + i * (int)sizeof(p->selPair[0])) = 0xff;
            *(unsigned short *)((u8 *)&p->selPair[0].second + i * (int)sizeof(p->selPair[0])) = 0xff;
        }
        return 1;
    }
    return 0;
}



int B_PLIST_MAIN_BeginMode8(struct B_PlistWork *p)
{
    int mode = 8;
    if (B_PLIST_MAIN_ApplyMode(p, mode) == 0) {
        p->flag2498 = p->owner->orderIndex;
        return 0x13;
    }
    return mode;
}



int B_PLIST_MAIN_PrintRowMessage(struct B_PlistWork *p)
{
    u8 *row;
    int idx;
    void *text;
    idx = B_PLIST_MAIN_GetOrderIndex(p, p->owner->orderIndex);
    row = ((void *)&p->slot[idx]);
    if (B_PLIST_MAIN_IsBattleSlot(p, idx) == 1) {
        text = MSGDATA_AllocString(p->msgBank, 0x5a);
        WORDSET_CopyTaggedText(p->wordSet, p->strBuf, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (B_PLIST_MAIN_IsIndexValid(p, p->owner->orderIndex) == 0) {
        if (B_PLIST_MAIN_IsIndexValid(p, idx) == 1)
            text = MSGDATA_AllocString(p->msgBank, 0x6b);
        else
            text = MSGDATA_AllocString(p->msgBank, 0x6a);
        WORDSET_SetSlotMonNickname(p->wordSet, 0, ((struct B_PlistSlot *)row)->mon);
        WORDSET_CopyTaggedText(p->wordSet, p->strBuf, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (B_PLIST_MAIN_IsIndexInParty(p, p->owner->orderIndex) == 1) {
        text = MSGDATA_AllocString(p->msgBank, 0x56);
        WORDSET_SetSlotMonNickname(p->wordSet, 0, ((struct B_PlistSlot *)row)->mon);
        WORDSET_CopyTaggedText(p->wordSet, p->strBuf, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (((struct B_PlistSlot *)row)->hp != 0) {
        text = MSGDATA_AllocString(p->msgBank, 0x56);
        WORDSET_SetSlotMonNickname(p->wordSet, 0, ((struct B_PlistSlot *)row)->mon);
        WORDSET_CopyTaggedText(p->wordSet, p->strBuf, text);
        STRBUF_Delete(text);
        return 0;
    }
    return 1;
}



int B_PLIST_MAIN_ConfirmSwap(struct B_PlistWork *p)
{
    if (PALANM_GetFadeRequestBits(p->palAnm) != 0) return 8;
    if (B_PLIST_MAIN_CheckCancel(p) == 1) return 0x1f;
    if (B_PLIST_MAIN_HandleCursorInput(p) == 1) {
        if (p->owner->orderIndex == 6) {
            B_PLIST_MAIN_PlaySe(p, 0x552);
            B_PLIST_ANM_StartPaletteAnim(p, 6);
            p->owner->orderIndex = p->flag2498;
            p->nextState = 0xc;
            return 0x1d;
        }
        if (p->owner->orderIndex == p->flag2498) return 0xc;
        if (B_PLIST_MAIN_PrintRowMessage(p) == 1) {
            B_PLIST_MAIN_PushSelectionPair(p, p->owner->orderIndex, p->flag2498);
            B_PLIST_MAIN_SetSelectionEntry(p, p->owner->orderIndex, p->flag2498);
            p->flag2499 = p->owner->orderIndex;
            p->flag249A = p->flag2498;
            p->animStep = 0;
            return 9;
        }
        B_PLIST_DRAW_ClearAndPrintStream(p);
        p->nextState = 0xa;
        return 0x17;
    }
    return 8;
}




int B_PLIST_MAIN_EndSwap(struct B_PlistWork *p)
{
    BMP_MENUWORK_DrawWindowBorder(p->win[1].handle, 0);
    B_PLIST_DRAW_PrintHeader10(p);
    B_PLIST_DRAW_ShowSubWindow(p);
    return 8;
}




void B_PLIST_MAIN_GetFramePos(u8 *a, u8 *b, unsigned int c)
{
    int lo = c & 1;

    *a = (u8)(lo << 4);
    *b = (u8)(lo + (c >> 1) * 6);
}



/*
 * Trailing 022113FA halfword is zero alignment padding, not a follower.
 */
void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which)
{
    u8 xy[2];
    u8 *src = (u8 *)BG_SYS_GetBuf(bg);
    u8 i;
    B_PLIST_MAIN_GetFramePos(&xy[1], &xy[0], which);
    for (i = 0; i < 6; i++) {
        MIi_CpuCopy16(src + 2 * (xy[1] + ((xy[0] + i) << 5)), dst + (i << 5), 32);
    }
}



/*
 * prototype: delta is word-wide at this call; the callee's short extern inserts lsls/asrs absent from 0x02211418.
 */
void B_PLIST_MAIN_MoveActorByFlag(struct B_PlistWork *p, int a, int b)
{
    short delta = 1;
    if (a & delta) {
        if (b == 0) delta = 8;
        else delta = -8;
    } else {
        delta = -8;
        if (b != 0) delta = 8;
    }
    B_PLIST_MAIN_ShiftActors(p, a, delta);
}




int B_PLIST_MAIN_UpdateSwapFrames(struct B_PlistWork *p)
{
    s8 xy[4];
    s8 pos[4];
    s8 pos2[4];
    switch (p->animStep) {
    case 0: {
        u8 *buf;
        p->bgWinFrame = BGWINFRM_Create(2, 4, p->owner->heapId);
        BGWINFRM_AddFrame(p->bgWinFrame, 0, 5, 0x10, 6);
        BGWINFRM_AddFrame(p->bgWinFrame, 1, 6, 0x10, 6);
        BGWINFRM_AddFrame(p->bgWinFrame, 2, 5, 0x10, 6);
        BGWINFRM_AddFrame(p->bgWinFrame, 3, 6, 0x10, 6);
        buf = GFL_HEAP_Alloc((u16)(0x8000 | (p->owner->heapId & 0x7fff)), 0xc0, 0, (const char *)data_02212550, 0xb89);
        B_PLIST_MAIN_CopyFrame(buf, 5, p->flag2499);
        BGWINFRM_SetFrameData(p->bgWinFrame, 0, buf);
        B_PLIST_MAIN_CopyFrame(buf, 6, p->flag2499);
        BGWINFRM_SetFrameData(p->bgWinFrame, 1, buf);
        B_PLIST_MAIN_CopyFrame(buf, 5, p->flag249A);
        BGWINFRM_SetFrameData(p->bgWinFrame, 2, buf);
        B_PLIST_MAIN_CopyFrame(buf, 6, p->flag249A);
        BGWINFRM_SetFrameData(p->bgWinFrame, 3, buf);
        GFL_HEAP_Free(buf);
        B_PLIST_MAIN_GetFramePos((u8 *)&xy[1], (u8 *)&xy[0], p->flag2499);
        BGWINFRM_PutFrame(p->bgWinFrame, 0, xy[1], xy[0]);
        BGWINFRM_PutFrame(p->bgWinFrame, 1, xy[1], xy[0]);
        B_PLIST_MAIN_GetFramePos((u8 *)&xy[1], (u8 *)&xy[0], p->flag249A);
        BGWINFRM_PutFrame(p->bgWinFrame, 2, xy[1], xy[0]);
        BGWINFRM_PutFrame(p->bgWinFrame, 3, xy[1], xy[0]);
        BGWINFRM_UpdateMoves(p->bgWinFrame);
        p->animStep++;
        break;
    }
    case 1:
        if (p->flag2499 & 1) {
            BGWINFRM_StartMove(p->bgWinFrame, 0, 1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 1, 1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(p->bgWinFrame, 0, -1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 1, -1, 0, 0x10);
        }
        if (p->flag249A & 1) {
            BGWINFRM_StartMove(p->bgWinFrame, 2, 1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 3, 1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(p->bgWinFrame, 2, -1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 3, -1, 0, 0x10);
        }
        p->animStep++;
        break;
    case 2: {
        BGWINFRM_UpdateMoves(p->bgWinFrame);
        B_PLIST_MAIN_MoveActorByFlag(p, p->flag2499, 0);
        B_PLIST_MAIN_MoveActorByFlag(p, p->flag249A, 0);
        BGWINFRM_GetPos(p->bgWinFrame, 0, &pos[3], &pos[2]);
        BGWINFRM_GetPos(p->bgWinFrame, 2, &pos[1], &pos[0]);
        if (BGWINFRM_IsMoving(p->bgWinFrame, 0) != 0) break;
        B_PLIST_MAIN_SwapOrder(p, p->flag2499, p->flag249A);
        BGWINFRM_PutFrame(p->bgWinFrame, 0, pos[1], pos[0]);
        BGWINFRM_PutFrame(p->bgWinFrame, 1, pos[1], pos[0]);
        BGWINFRM_PutFrame(p->bgWinFrame, 2, pos[3], pos[2]);
        BGWINFRM_PutFrame(p->bgWinFrame, 3, pos[3], pos[2]);
        B_PLIST_MAIN_SwapActorPos(p, p->flag2499, p->flag249A);
        p->animStep++;
        break;
    }
    case 3:
        BGWINFRM_UpdateMoves(p->bgWinFrame);
        if (p->flag249A & 1) {
            BGWINFRM_StartMove(p->bgWinFrame, 0, -1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 1, -1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(p->bgWinFrame, 0, 1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 1, 1, 0, 0x10);
        }
        if (p->flag2499 & 1) {
            BGWINFRM_StartMove(p->bgWinFrame, 2, -1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 3, -1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(p->bgWinFrame, 2, 1, 0, 0x10);
            BGWINFRM_StartMove(p->bgWinFrame, 3, 1, 0, 0x10);
        }
        p->animStep++;
        break;
    case 4: {
        BGWINFRM_UpdateMoves(p->bgWinFrame);
        B_PLIST_MAIN_MoveActorByFlag(p, p->flag2499, 1);
        B_PLIST_MAIN_MoveActorByFlag(p, p->flag249A, 1);
        BGWINFRM_GetPos(p->bgWinFrame, 0, &pos2[3], &pos2[2]);
        BGWINFRM_GetPos(p->bgWinFrame, 2, &pos2[1], &pos2[0]);
        if (BGWINFRM_IsMoving(p->bgWinFrame, 0) == 0) p->animStep++;
        break;
    }
    case 5:
        BGWINFRM_Delete(p->bgWinFrame);
        p->bgWinFrame = 0;
        p->animStep = 0;
        return 0;
    }
    return 1;
}



int B_PLIST_MAIN_FinishSwap(struct B_PlistWork *p)
{
    if (B_PLIST_MAIN_UpdateSwapFrames(p) == 0) {
        if (B_PLIST_MAIN_HasSwappable(p) == 0) return 31;
        B_PLIST_ANM_UpdateSelectedTile(p);
        B_PLIST_DRAW_PrintHeader9(p);
        B_PLIST_DRAW_ShowSubWindow(p);
        return 3;
    }
    return 9;
}



/*
 * tail: 0221189A..0221189C is zero alignment padding.
 */
int B_PLIST_MAIN_CanSwap(struct B_PlistWork *p)
{
    u8 count,i,bound;
    if(B_PLIST_MAIN_GetOwnerFlag18(p)==1) return 0;
    bound=p->owner->partyCount;
    if(bound==1) return 0;
    count=0;
    for(i=0;i<bound;i++) {
        if(p->slot[B_PLIST_MAIN_GetOrderIndex(p,i)].hp==0) {
            count++;
            if(count==2) return 1;
        }
    }
    return 0;
}



int B_PLIST_MAIN_HasSwappable(struct B_PlistWork *p)
{
    u8 i;
    if(B_PLIST_MAIN_GetOwnerFlag18(p)==1) return 0;
    i=p->owner->partyCount;
    if(i==1) return 0;
    for(;i<6;i++) {
        struct B_PlistWork *record=(struct B_PlistWork *)((u8 *)p+B_PLIST_MAIN_GetOrderIndex(p,i)*sizeof(struct B_PlistSlot));
        if(record->slot[0].species!=0 && record->slot[0].statusFlags.high==0 && record->slot[0].hp!=0) return 1;
    }
    return 0;
}



/*
 * lever: associate the index with the destination pointer before adding 0x48.
 */
void B_PLIST_MAIN_CommitSwap(struct B_PlistWork *p)
{
    unsigned i;
    if(B_PLIST_MAIN_GetOwnerFlag18(p)==1) {
        p->owner->order[0]=B_PLIST_MAIN_GetOrderIndex(p,p->owner->orderIndex);
    } else {
        for(i=0;i<3;i++) {
            if(p->slot[B_PLIST_MAIN_GetOrderIndex(p,i)].hp==0) {
                ((*(u8 * *)&p->owner)+i)[0x48]=p->owner->orderIndex;
                break;
            }
        }
    }
}




void B_PLIST_MAIN_ClearSelection(struct B_PlistWork *p)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        p->owner->order[i] = 0xff;
    }
}




u32 B_PLIST_MAIN_CheckCancel(struct B_PlistWork *p)
{
    if (p->owner->cancelRequest == 1) {
        B_PLIST_MAIN_ClearSelection(p);
        return 1;
    }
    return 0;
}




void B_PLIST_MAIN_PlaySe(struct B_PlistWork *p, u32 b)
{
    if (p->owner->seEnabled == 1) {
        GFL_USE_PlaySeDefaultVolume(b);
    }
}




void B_PLIST_MAIN_PlaySe2(struct B_PlistWork *p, u32 b)
{
    if (p->owner->seEnabled == 1) {
        GFL_USE_PlaySeDefaultVolume(b);
    }
}



/*
 * ABI: 02211A24 explicitly receives the forwarded entry r2 as its r1.
 */
void B_PLIST_MAIN_CreateCursor(struct B_PlistWork *p,u32 index,u32 b)
{
    struct CursorMove *result;
    result=(struct CursorMove *)CURSOR_MOVE_Create(d_022122D4[index],(struct CursorVtbl *)&d_022122A0,p,(u32)p->syncRequested,b,p->owner->heapId);
    p->cursorMove=result;
    CURSOR_MOVE_EnableInput((struct Cursor *)result);
    CURSOR_MOVE_SetMode((struct Cursor *)p->cursorMove);
    B_PLIST_MAIN_LayoutCursorActors(p,b);
}




u32 B_PLIST_MAIN_DeleteCursor(struct B_PlistWork *p)
{
    return CURSOR_MOVE_Delete((void *)((p->cursorMove)));
}




void B_PLIST_MAIN_RecreateCursor(struct B_PlistWork *p, u32 a, u32 b)
{
    B_PLIST_MAIN_DeleteCursor(p);
    B_PLIST_MAIN_CreateCursor(p, a, b);
}




/*
 * note:     the callee takes (p, v); passing v as the second argument keeps r1 live
 *           across the store.
 */
void B_PLIST_MAIN_SetActorsVisible(struct B_PlistWork *p, u32 v)
{
    p->syncRequested = v;
    B_APP_TOOL_SetActorsVisible(*(char **)&p->appTool, v);
}




void B_PLIST_MAIN_LayoutCursorActors(struct B_PlistWork *p, u32 idx)
{
    void *t = CURSOR_MOVE_GetEntry((struct Cursor *)(*(void ** *)&p->cursorMove), idx);

    B_APP_TOOL_LayoutActors((struct ClactActor **)(p->appTool), (u8 *)(t));
}




void B_PLIST_MAIN_ShowCursor(struct B_PlistWork *p, unsigned idx)
{
    B_PLIST_MAIN_LayoutCursorActors(p, idx);
    B_PLIST_MAIN_SetActorsVisible(p, 1);
}




/*
 * The cursor callbacks of d_022122A0 (CursorVtbl: onStart ShowCursor, onCancel
 * HideCursor, onMove MoveCursor, onCommit HideCursorOnTouch).  Only that table
 * names the last three.
 */
void B_PLIST_MAIN_HideCursor(struct B_PlistWork *p)
{
    B_PLIST_MAIN_SetActorsVisible(p, 0);
}




void B_PLIST_MAIN_HideCursorOnTouch(struct B_PlistWork *p)
{
    B_PLIST_MAIN_SetActorsVisible(p, 0);
}




void B_PLIST_MAIN_MoveCursor(struct B_PlistWork *p, u32 idx)
{
    B_PLIST_MAIN_LayoutCursorActors(p, idx);
}
