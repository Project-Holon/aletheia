/*
 * file:     b_plist_main.c
 * unit:     yes
 * function: B_PLIST_MAIN_SyncMoveActors, B_PLIST_MAIN_SetActorAnimSeq, B_PLIST_MAIN_GetMonAnimState, B_PLIST_MAIN_UpdateActorAnims, B_PLIST_MAIN_CreateToolActors, B_PLIST_MAIN_ShiftActors, B_PLIST_MAIN_SwapActorPos, B_PLIST_MAIN_Create, B_PLIST_MAIN_Task, B_PLIST_MAIN_Init, B_PLIST_MAIN_WaitPrintQue, B_PLIST_MAIN_WaitWipe, B_PLIST_MAIN_HandleSelectInput, B_PLIST_MAIN_ConfirmSelect, B_PLIST_MAIN_HandleModeSelect, B_PLIST_MAIN_HandleListSelect, B_PLIST_MAIN_HandleMoveSelect, B_PLIST_MAIN_HandleSlotSelect, B_PLIST_MAIN_HandleSlotSelectFade, B_PLIST_MAIN_HandleItemSelect, B_PLIST_MAIN_HandleConfirmCancel, B_PLIST_MAIN_EnterState1A, B_PLIST_MAIN_HandlePartySelect, B_PLIST_MAIN_ApplyMode0, B_PLIST_MAIN_ApplyMode1, B_PLIST_MAIN_ApplyMode2, B_PLIST_MAIN_ApplyMode3, B_PLIST_MAIN_ApplyMode4, B_PLIST_MAIN_ApplyMode6, B_PLIST_MAIN_ApplyMode7, B_PLIST_MAIN_ApplyMode5, B_PLIST_MAIN_RedrawByMode, B_PLIST_MAIN_RefreshAndState16, B_PLIST_MAIN_ClearPrintStream, B_PLIST_MAIN_WaitPrintStream, B_PLIST_MAIN_HandleSkipKey, B_PLIST_MAIN_CheckBusyFlag, B_PLIST_MAIN_BeginFadeOut, B_PLIST_MAIN_WaitFadeOut, B_PLIST_MAIN_Delete, B_PLIST_MAIN_InitBg, B_PLIST_MAIN_ExitBg, B_PLIST_MAIN_LoadGraphics, B_PLIST_MAIN_CreateTextResources, B_PLIST_MAIN_DeleteTextResources, B_PLIST_MAIN_ReadSummary, B_PLIST_MAIN_ReadParty, B_PLIST_MAIN_HandleCursorInput, B_PLIST_MAIN_GetSlotState, B_PLIST_MAIN_NextSelectable, B_PLIST_MAIN_DrawExpBar, B_PLIST_MAIN_ApplyMode, B_PLIST_MAIN_LoadModePalette, B_PLIST_MAIN_GetRowStatus, B_PLIST_MAIN_PrintStatusMessage, B_PLIST_MAIN_IsRowFlagged, B_PLIST_MAIN_GetOwnerFlag18, B_PLIST_MAIN_IsBattleSlot, B_PLIST_MAIN_CheckMoveUsable, B_PLIST_MAIN_IsSlotSelectable, B_PLIST_MAIN_IsIndexValid, B_PLIST_MAIN_IsIndexInParty, B_PLIST_MAIN_InitSelectionForMode, B_PLIST_MAIN_InitOrder, B_PLIST_MAIN_IsInSelection, B_PLIST_MAIN_GetOrderIndex, B_PLIST_MAIN_SetSelectionEntry, B_PLIST_MAIN_PushSelectionPair, B_PLIST_MAIN_PopSelectionPair, B_PLIST_MAIN_BeginMode8, B_PLIST_MAIN_PrintRowMessage, B_PLIST_MAIN_ConfirmSwap, B_PLIST_MAIN_EndSwap, B_PLIST_MAIN_GetFramePos, B_PLIST_MAIN_CopyFrame, B_PLIST_MAIN_MoveActorByFlag, B_PLIST_MAIN_UpdateSwapFrames, B_PLIST_MAIN_FinishSwap, B_PLIST_MAIN_CanSwap, B_PLIST_MAIN_HasSwappable, B_PLIST_MAIN_CommitSwap, B_PLIST_MAIN_ClearSelection, B_PLIST_MAIN_CheckCancel, B_PLIST_MAIN_PlaySe, B_PLIST_MAIN_PlaySe2, B_PLIST_MAIN_CreateCursor, B_PLIST_MAIN_DeleteCursor, B_PLIST_MAIN_RecreateCursor, B_PLIST_MAIN_SetActorsVisible, B_PLIST_MAIN_LayoutCursorActors, B_PLIST_MAIN_ShowCursor
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
 *   func_0202D034 0x0202D034 thumb
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   B_APP_TOOL_CreateActors 0x0220AF6C thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
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
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   func_02045CAC 0x02045CAC arm
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
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_02212144 0x02212144 data a4
 *   d_02212174 0x02212174 data a4
 *   d_022121B4 0x022121B4 data a4
 *   d_02212154 0x02212154 data a4
 *   d_02212194 0x02212194 data a4
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   func_02049EF4 0x02049EF4 arm
 *   B_PLIST_ANM_CopyMonSpriteTiles 0x0220B120 thumb ov198
 *   B_PLIST_ANM_CopySubSpriteTiles 0x0220B3B4 thumb ov198
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   func_020276C4 0x020276C4 thumb
 *   POKE_TOOL_GetLevelMinExp 0x02018544 thumb
 *   func_02018584 0x02018584 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   d_02212130 0x02212130 data a1
 *   func_0202D01C 0x0202D01C thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   B_PLIST_DRAW_DeleteStateWindows 0x0220BDD4 thumb ov198
 *   B_PLIST_DRAW_CreateStateWindows 0x0220BC70 thumb ov198
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   d_022121D4 0x022121D4 data a4
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_0202F72C 0x0202F72C thumb
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
#include "../../matched/include/Obj10848.h"
#include "../../matched/include/Obj00172.h"
#include "../../matched/include/Obj02915.h"
#include "../../matched/include/Obj06654.h"
#include "../../matched/include/Obj01006.h"
#include "../../matched/include/Obj25225.h"
#include "../../matched/include/Obj00633.h"
#include "../../matched/include/Obj25226.h"
#include "../../matched/include/Obj25227.h"
#include "../../matched/include/Obj25228.h"
#include "../../matched/include/Obj25229.h"
#include "../../matched/include/Obj25231.h"
#include "../../matched/include/Obj14564.h"
#include "../../matched/include/Obj25232.h"
#include "../../matched/include/Obj04601.h"
#include "../../matched/include/Obj03907.h"
#include "../../matched/include/Obj03908.h"
#include "../../matched/include/Obj03349.h"
#include "../../matched/include/Obj10850.h"
#include "../../matched/include/Obj14565.h"
#include "../../matched/include/Obj08361.h"
#include "../../matched/include/Obj04602.h"
#include "../../matched/include/Obj14566.h"
#include "../../matched/include/Obj10851.h"
#include "../../matched/include/Obj03351.h"
#include "../../matched/include/Obj25233.h"
#include "../../matched/include/Obj25234.h"
#include "../../matched/include/Obj25235.h"
#include "../../matched/include/Obj08362.h"
#include "../../matched/include/Obj25236.h"
#include "../../matched/include/Obj14567.h"
#include "../../matched/include/Obj25237.h"
#include "../../matched/include/Obj25238.h"
#include "../../matched/include/Obj25239.h"
#include "../../matched/include/Obj25240.h"
#include "../../matched/include/Obj25241.h"
#include "../../matched/include/Obj25243.h"
#include "../../matched/include/Obj14568.h"
#include "../../matched/include/Obj25245.h"
#include "../../matched/include/Obj25246.h"
#include "../../matched/include/Obj02535.h"
#include "../../matched/include/Obj25247.h"
#include "../../matched/include/Obj25248.h"
#include "../../matched/include/Obj25249.h"
#include "../../matched/include/Obj25250.h"
#include "../../matched/include/Obj25251.h"
#include "../../matched/include/Obj25252.h"
#include "../../matched/include/Obj25253.h"
#include "../../matched/include/Obj02916.h"
#include "../../matched/include/Obj25254.h"
#include "../../matched/include/Obj25255.h"
#include "../../matched/include/Obj25256.h"
#include "../../matched/include/Obj25257.h"
#include "../../matched/include/Obj25258.h"
#include "../../matched/include/Obj06656.h"
#include "../../matched/include/Obj04603.h"
#include "../../matched/include/Obj25259.h"
#include "../../matched/include/Obj25260.h"
#include "../../matched/include/Obj25261.h"
#include "../../matched/include/Obj25262.h"
#include "../../matched/include/Obj25263.h"
#include "../../matched/include/Obj25264.h"
#include "../../matched/include/Obj25265.h"
#include "../../matched/include/Obj25266.h"
#include "../../matched/include/Obj08363.h"
#include "../../matched/include/Obj25267.h"
#include "../../matched/include/Obj25269.h"
#include "../../matched/include/Obj10852.h"
#include "../../matched/include/Obj25270.h"
#include "../../matched/include/Obj25271.h"
#include "../../matched/include/Obj25272.h"
#include "../../matched/include/Obj08364.h"
#include "../../matched/include/Obj25273.h"
#include "../../matched/include/Obj25275.h"
#include "../../matched/include/Obj14569.h"
#include "../../matched/include/Obj25276.h"
#include "../../matched/include/Obj10854.h"
#include "../../matched/include/Obj01431.h"
#include "../../matched/include/Obj08366.h"
#include "../../matched/include/Obj02536.h"
#include "../../matched/include/Obj25281.h"
#include "../../matched/include/Obj14570.h"
#include "../../matched/include/Obj14571.h"
#include "../../matched/include/Obj25284.h"
#include "../../matched/include/Obj25286.h"
#include "../../matched/include/Obj25288.h"
#include "../../matched/include/Obj10855.h"
#include "../../matched/include/Obj25289.h"
#include "../../matched/include/Obj25290.h"

#define MGR (*(struct WinMgr **)(p + 0x2194))
struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Ctx;
struct Node;
struct Tcbl;
struct PrintSys;
struct MsgBank;
struct Sound;
struct Rec;
struct Rec3;
struct S02031140;
struct WinMgr;
struct PalAnmSlot;
struct GfFont;
struct U16Vec;
struct WordSet;
struct Summary;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct 
{
  u8 low : 6;
  u8 bit : 1;
  u8 high : 1;
} Flag_0220F060;

struct Bits { u8 low:3; u8 kind:4; u8 high:1; };

typedef struct {short x,y;} Pair;

typedef struct {u8 low:7;u8 high:1;} Flag_0220F7C4;

typedef signed short   s16;

typedef signed char    s8;

struct S {
    unsigned char pad[0x1eb0];
    int f1eb0;
    int f1eb4;
};

typedef signed int     s32;

struct Flag_0221039C {u8 low:7;u8 bit:1;};

struct BgVramReq {u32 unk00,unk04,unk08,unk0c;};

struct BgTemplate {
    u32 unk00,unk04,bufSize,unk0c;
    u8 unk10,unk11,unk12,unk13;
    u32 unk14;
    u8 unk18,unk19,unk1a,unk1b;
    u32 unk1c;
};

struct Move {u16 id;u8 pp,up,kind,power,type,accuracy;};

struct Summary {
    void *mon;
    u16 species,hp,attack,defense,speed,stat6,spatk,spdef;
    u8 ability,form;
    u8 level:7,egg:1;
    u8 gender:3,nature:4,flag:1;
    u16 item,unknown;
    u32 exp,lower,upper,personality;
    struct Move moves[4];
};

struct Order {u8 ids[6];};

struct Flags {u8 low:7,high:1;};

typedef struct Level {u8 pad[22];u8 level:7;u8 flag:1;} Level;

typedef struct State {u8 pad[0x2177];u8 step:4;u8 flags:4;} State;

typedef struct {u8 low:7,high:1;} Bits_02210C88;

typedef unsigned u32_02211190;

typedef unsigned int   u32_022112AC;

typedef unsigned int   u32_02211378;

typedef unsigned int u32_0221139C;

typedef unsigned int   u32_022113B8;

typedef unsigned int u32_02211420;

typedef struct {u8 lo:7;u8 high:1;} Bits_022110F8;

typedef unsigned int   u32_02211944;

typedef unsigned int   u32_02211958;

typedef unsigned int   u32_02211970;

typedef unsigned int   u32_02211984;

typedef unsigned u32_02211998;

typedef enum {task_offset=0x218c} Offset;

typedef unsigned int   u32_022119E8;

typedef unsigned int   u32_022119F8;

typedef unsigned int   u32_02211A10;

typedef unsigned int   u32_02211A24;

extern void B_PLIST_DRAW_TransferCharacter(char *p, void *obj, int index, int which);
extern void B_PLIST_DRAW_PlaceActor(u8 *, u32);
extern u32 WAZA_TOOL_GetParam(u16, u32);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(void *, int);
extern int func_0202D034(unsigned,unsigned);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void B_APP_TOOL_CreateActors(char *,int,int,int,int);
extern unsigned B_APP_TOOL_SetActorsVisible();
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void TCBL_Main(struct Tcbl *p);
extern void B_PLIST_ANM_StepPaletteAnim(u8 *);
extern void B_PLIST_DRAW_UpdateToolWindows(u8 *);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *B_APP_TOOL_Create(u16 v);
extern void B_PLIST_ANM_UpdateByMode(u8 *,u32);
extern void B_PLIST_ANM_CopyPaletteSlot(u8 *,u32);
extern void B_PLIST_DRAW_Init(char *);
extern void B_PLIST_DRAW_LayoutActors(char *,u32);
extern void B_PLIST_ANM_CreateTileWindows(u8 *);
extern int B_PLIST_DRAW_DrawModePage(char *,int);
extern void B_PLIST_DRAW_ShowToolWindows(u8 *);
extern int PALANM_RequestFade(void *,u16,u16,short,u8,u8,u16,void *);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *,u32);
extern void B_PLIST_DRAW_ClearAndPrintStream(u8 *);
extern void B_PLIST_DRAW_FormatRowWord(u8 *);
extern u32 FILE_UTIL_Get_0FE4(void *,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern void B_PLIST_DRAW_PrintWordAndRefresh(u8 *);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void WIPE_SYS_ExeEnd(void);
extern void BGWINFRM_Delete(struct WinMgr *obj);
extern void B_PLIST_DRAW_DeleteActors(char *);
extern void B_PLIST_DRAW_DeleteAllWindows(u8 *p);
extern void TCBL_Destroy(struct S02031140 *);
extern void B_APP_TOOL_Delete(void *);
extern void TCB_DeleteTask(struct Node *);
extern u32 func_020307B0(void *p);
extern void BG_SYS_ApplyGraphicsMode(const struct BgVramReq *,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetFlagField06(u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void func_020403F4(u32 i);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *,u32,u32,void **,u16);
extern void B_PLIST_ANM_CopyMonSpriteTiles(char *,u16 *);
extern void B_PLIST_ANM_CopySubSpriteTiles(char *,u16 *);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern int PALANM_GetDefaultWork(char *,int);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *,u32,u32,u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void *PRINTSYS_QUE_CreateEx(u16,u32);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 func_02017E1C(void *,u32,u32);
extern u8 POKE_TOOL_GetGender(void *);
extern int func_020276C4(int a0);
extern u32 POKE_TOOL_GetLevelMinExp(void *);
extern u32 func_02018584(u16,u16,u16);
extern u8 WAZA_TOOL_GetMaxPP(u16,u32);
extern u32 WAZA_TOOL_IsAlwaysHit(u16);
extern unsigned POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *,unsigned);
extern u8 func_0202D01C(u32,u32,u32);
extern void BG_SYS_SetTileEntry(u32,u16,u8,int,u8,u8,u8);
extern void func_02041B6C(u8);
extern void B_PLIST_DRAW_DeleteStateWindows(char *);
extern void B_PLIST_DRAW_CreateStateWindows(u8 *,u32);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void BG_SYS_DrawTile(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 func_0202F72C(void *,u16,u16);
extern void B_PLIST_DRAW_PrintHeader10(char *p);
extern void B_PLIST_DRAW_ShowSubWindow(u8 *p);
extern u32_022113B8 BG_SYS_GetBuf(int channel);
extern void MIi_CpuCopy16(const void *, void *, unsigned);
extern struct WinMgr *BGWINFRM_Create(u32_02211420 a0, u32_02211420 a1, u32_02211420 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32_02211420 idx, u32_02211420 a, u32_02211420 b, u32_02211420 c);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32_02211420 idx, const void *src);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32_02211420 idx, s8 x, s8 y);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32_02211420 idx, s8 dx, s8 dy, u8 frames);
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32_02211420 idx, s8 *x, s8 *y);
extern u32_02211420 BGWINFRM_IsMoving(struct WinMgr *mgr, u32_02211420 idx);
extern void B_PLIST_ANM_UpdateSelectedTile(u8 *);
extern void B_PLIST_DRAW_PrintHeader9(char *p);
extern void GFL_USE_PlaySeDefaultVolume(u32_02211970);
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32_02211998,u32_02211998,u32_02211998,u32_02211998,u8,u16);
extern void CURSOR_MOVE_EnableInput(struct Struct_02025D1C *);
extern void CURSOR_MOVE_SetMode(struct Struct_02025D24 *);
extern u32_022119E8 CURSOR_MOVE_Delete(void *a0);
extern void *CURSOR_MOVE_GetEntry(void **obj, u32_02211A24 idx);
extern void B_APP_TOOL_LayoutActors(int *p, u8 *q);
void B_PLIST_MAIN_SyncMoveActors(u8 *p);
void B_PLIST_MAIN_SetActorAnimSeq(void *a, int b);
int B_PLIST_MAIN_GetMonAnimState(char *p);
void B_PLIST_MAIN_UpdateActorAnims(u8 *p);
void B_PLIST_MAIN_CreateToolActors(u8 *p);
void B_PLIST_MAIN_ShiftActors(u8 *p,int a,short delta);
void B_PLIST_MAIN_SwapActorPos(char *p, int a1, int a2);
void B_PLIST_MAIN_Create(u8 *p);
void B_PLIST_MAIN_Task(void *task,u8 *p);
int B_PLIST_MAIN_Init(u8 *p);
int B_PLIST_MAIN_WaitPrintQue(u8 *p);
int B_PLIST_MAIN_WaitWipe(u8 *p);
int B_PLIST_MAIN_HandleSelectInput(u8 *p);
int B_PLIST_MAIN_ConfirmSelect(u8 *p);
int B_PLIST_MAIN_HandleModeSelect(u8 *p);
int B_PLIST_MAIN_HandleListSelect(u8 *p);
int B_PLIST_MAIN_HandleMoveSelect(u8 *p);
int B_PLIST_MAIN_HandleSlotSelect(u8 *p);
int B_PLIST_MAIN_HandleSlotSelectFade(u8 *p);
int B_PLIST_MAIN_HandleItemSelect(u8 *p);
int B_PLIST_MAIN_HandleConfirmCancel(u8 *p);
u32 B_PLIST_MAIN_EnterState1A(u8 *p);
int B_PLIST_MAIN_HandlePartySelect(u8 *p);
u32 B_PLIST_MAIN_ApplyMode0(u32 a);
u32 B_PLIST_MAIN_ApplyMode1(u32 a);
u32 B_PLIST_MAIN_ApplyMode2(u32 a);
u32 B_PLIST_MAIN_ApplyMode3(u32 a);
int B_PLIST_MAIN_ApplyMode4(char *p);
u32 B_PLIST_MAIN_ApplyMode6(u32 a);
u32 B_PLIST_MAIN_ApplyMode7(u32 a);
u32 B_PLIST_MAIN_ApplyMode5(u32 a);
int B_PLIST_MAIN_RedrawByMode(u8 *p);
u32 B_PLIST_MAIN_RefreshAndState16(u8 *p);
u32 B_PLIST_MAIN_ClearPrintStream(u8 *p);
int B_PLIST_MAIN_WaitPrintStream(struct S *a);
int B_PLIST_MAIN_HandleSkipKey(char *p);
int B_PLIST_MAIN_CheckBusyFlag(char *p);
int B_PLIST_MAIN_BeginFadeOut(char *p);
u32 B_PLIST_MAIN_WaitFadeOut(u8 *p);
int B_PLIST_MAIN_Delete(struct Node *task,char *p);
void B_PLIST_MAIN_InitBg(u8 *p);
void B_PLIST_MAIN_ExitBg(void);
void B_PLIST_MAIN_LoadGraphics(char *p);
void B_PLIST_MAIN_CreateTextResources(char *p);
void B_PLIST_MAIN_DeleteTextResources(u8 *p);
void B_PLIST_MAIN_ReadSummary(void *unused,void *mon,struct Summary *p);
void B_PLIST_MAIN_ReadParty(u8 *p);
int B_PLIST_MAIN_HandleCursorInput(u8 *p);
int B_PLIST_MAIN_GetSlotState(u8 *p,int i);
u8 B_PLIST_MAIN_NextSelectable(u8 *p,int i,int delta);
void B_PLIST_MAIN_DrawExpBar(u8 *p,int mode);
int B_PLIST_MAIN_ApplyMode(u8 *p,unsigned mode);
void B_PLIST_MAIN_LoadModePalette(u8 *p,u32 n);
int B_PLIST_MAIN_GetRowStatus(u8 *p);
int B_PLIST_MAIN_PrintStatusMessage(u8 *p);
u8 B_PLIST_MAIN_IsRowFlagged(u8 *p);
int B_PLIST_MAIN_GetOwnerFlag18(char **p);
u32 B_PLIST_MAIN_IsBattleSlot(u32 a, u32 b);
u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p);
int B_PLIST_MAIN_IsSlotSelectable(u8 *p,int i);
int B_PLIST_MAIN_IsIndexValid(char **p, unsigned int v);
unsigned B_PLIST_MAIN_IsIndexInParty(u8 *p, int index);
void B_PLIST_MAIN_InitSelectionForMode(u8 *p, u32 state);
void B_PLIST_MAIN_InitOrder(u8 *p);
void B_PLIST_MAIN_SwapOrder(u8 *p, int a, int b);
u32 B_PLIST_MAIN_IsInSelection(u8 **p, u32 c);
int B_PLIST_MAIN_GetOrderIndex(u8 *p, int i);
void B_PLIST_MAIN_SetSelectionEntry(u8 **p, u32 b, u32 c);
void B_PLIST_MAIN_PushSelectionPair(u8 *p, int a, int b);
int B_PLIST_MAIN_PopSelectionPair(unsigned char *p, unsigned char *a, unsigned char *b, int clear);
int B_PLIST_MAIN_BeginMode8(u8 *p);
int B_PLIST_MAIN_PrintRowMessage(u8 *p);
int B_PLIST_MAIN_ConfirmSwap(u8 *p);
int B_PLIST_MAIN_EndSwap(char *p);
void B_PLIST_MAIN_GetFramePos(u8 *a, u8 *b, unsigned int c);
void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which);
void B_PLIST_MAIN_MoveActorByFlag(u8 *p, int a, int b);
int B_PLIST_MAIN_UpdateSwapFrames(u8 *p);
int B_PLIST_MAIN_FinishSwap(u8 *p);
int B_PLIST_MAIN_CanSwap(u8 *p);
int B_PLIST_MAIN_HasSwappable(u8 *p);
void B_PLIST_MAIN_CommitSwap(u8 *p);
void B_PLIST_MAIN_ClearSelection(u8 **p);
u32_02211958 B_PLIST_MAIN_CheckCancel(u8 **p);
void B_PLIST_MAIN_PlaySe(u8 **p, u32_02211970 b);
void B_PLIST_MAIN_PlaySe2(u8 **p, u32_02211984 b);
void B_PLIST_MAIN_CreateCursor(u8 *p,u32_02211998 index,u32_02211998 b);
u32_022119E8 B_PLIST_MAIN_DeleteCursor(u8 *p);
void B_PLIST_MAIN_RecreateCursor(u8 *p, u32_022119F8 a, u32_022119F8 b);
u32_02211A10 B_PLIST_MAIN_SetActorsVisible(u8 *p, u32_02211A10 v);
void B_PLIST_MAIN_LayoutCursorActors(u8 *p, u32_02211A24 idx);
extern u32 d_02211DA0[];
extern const char d_02212550[];
extern volatile u16 d_04001050[];
extern const struct BgVramReq d_02212144;
extern const struct BgTemplate d_02212174,d_022121B4,d_02212154,d_02212194;
extern const struct Order d_02212130;
extern const u32 d_022121D4[];
extern u8 d_02212138[][6];
extern u8 data_02212550[];
extern const u32_02211998 d_022122D4[];
extern const u32_02211998 d_022122A0[];




void B_PLIST_MAIN_SyncMoveActors(u8 *p)
{
  u8 *rec;
  u8 *objects;
  int base;
  unsigned long offset;
  int i;
  u8 *entry;
  u8 *b;
  int slot;
  u8 *tmp;
  Flag_0220F060 *tmp1;
  tmp1 = (Flag_0220F060 *) (p + 0x2175);
  rec = (p + 4) + (B_PLIST_MAIN_GetOrderIndex(p, (*((u8 **) p))[32]) * 76);
  if (tmp1->bit == 0)
  {
    base = 29;
    slot = 12;
  }
  else
  {
    base = 34;
    slot = 17;
  }
  objects = p + (base * 4);
  for (i = 0; i < 4u; i++)
  {
    entry = rec + (i * 8);
    if ((*((u16 *) (entry + 44))) != 0)
    {
      offset = i * 4;
      b = objects + offset;
      B_PLIST_DRAW_TransferCharacter((char *)p, *((void **) (b + 0x1ebc)), slot + i, entry[48]);
      tmp = (u8 *) d_02211DA0;
      B_PLIST_DRAW_PlaceActor(*((u8 **) (b + 0x1ebc)), (u32) (tmp + offset));
    }
  }

  if (((*((u16 *) ((*((u8 **) p)) + 38))) != 0) && ((*((u8 **) p))[31] == 4))
  {
    offset = (base + i) * 4;
    b = p + 0x1ebc;
    B_PLIST_DRAW_TransferCharacter((char *)p, *((void **) (b + offset)), slot + i, WAZA_TOOL_GetParam(*((u16 *) ((*((u8 **) p)) + 38)), 0));
    B_PLIST_DRAW_PlaceActor(*((u8 **) (b + offset)), (u32) (d_02211DA0 + i));
  }
  ((Flag_0220F060 *) (p + 0x2175))->bit ^= 1;
}





void B_PLIST_MAIN_SetActorAnimSeq(void *a, int b)
{
    if (b != CLACT_GetActorAnimSeq(a))
    {
        CLACT_SetActorAnimFrame(a, 0);
        CLACT_SetActorAnimSeq(a, b);
    }
}




int B_PLIST_MAIN_GetMonAnimState(char *p)
{
    u16 a=((struct Obj10848 *)p)->f10;
    if (a==0) return 0;
    if (((struct Bits *)(p+0x17))->kind!=8 && ((struct Bits *)(p+0x17))->kind!=6) return 5;
    if (a==((struct Obj10848 *)p)->f12) return 1;
    switch (func_0202D034(a,((struct Obj10848 *)p)->f12)) {
    case 0: return 2;
    case 1: return 3;
    case 2: return 4;
    }
    return 0;
}




void B_PLIST_MAIN_UpdateActorAnims(u8 *p)
{
    u16 i;
    int j;
    for (i=0;i<6;i++) {
        j=B_PLIST_MAIN_GetOrderIndex(p,i);
        if (*(u16 *)(p+j*0x4c+8)) {
            int k=B_PLIST_MAIN_GetMonAnimState((char *)p+4+j*0x4c);
            B_PLIST_MAIN_SetActorAnimSeq(*(void **)(p+j*4+0x1ed8),k);
            CLACT_AddActorAnimFrame(*(void **)(p+j*4+0x1ed8),0x1000);
        }
    }
}




void B_PLIST_MAIN_CreateToolActors(u8 *p) { B_APP_TOOL_CreateActors(*(char * *)&((struct Obj00172 *)p)->f2188,*(int *)&((struct Obj00172 *)p)->f1EB8,((struct Obj00172 *)p)->f2504,((struct Obj00172 *)p)->f251C,((struct Obj00172 *)p)->f2534);B_APP_TOOL_SetActorsVisible(*(char * *)&((struct Obj00172 *)p)->f2188,0); }




void B_PLIST_MAIN_ShiftActors(u8 *p,int a,short delta)
{
    int i=B_PLIST_MAIN_GetOrderIndex(p,a);
    Pair pair;
    CLACT_GetActorSurfacePos(*(void **)(p+0x1ebc+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1ebc+i*4),(const struct Vec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)(p+0x1ed8+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1ed8+i*4),(const struct Vec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)(p+0x1ef0+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1ef0+i*4),(const struct Vec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)(p+0x1f08+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1f08+i*4),(const struct Vec2 *)(&pair),1);
}





void B_PLIST_MAIN_SwapActorPos(char *p, int a1, int a2)
{
    int i1 = B_PLIST_MAIN_GetOrderIndex((u8 *)p, a1);
    int i2 = B_PLIST_MAIN_GetOrderIndex((u8 *)p, a2);
    u32 x;
    u32 y;

    CLACT_GetActorSurfacePos(((void **)(p + 0x1ebc))[i1], (struct PtS *)&x, 1);
    CLACT_GetActorSurfacePos(((void **)(p + 0x1ebc))[i2], (struct PtS *)&y, 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1ebc))[i1], (const struct Vec2 *)(&y), 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1ebc))[i2], (const struct Vec2 *)(&x), 1);

    CLACT_GetActorSurfacePos(((void **)(p + 0x1ed8))[i1], (struct PtS *)&x, 1);
    CLACT_GetActorSurfacePos(((void **)(p + 0x1ed8))[i2], (struct PtS *)&y, 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1ed8))[i1], (const struct Vec2 *)(&y), 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1ed8))[i2], (const struct Vec2 *)(&x), 1);

    CLACT_GetActorSurfacePos(((void **)(p + 0x1ef0))[i1], (struct PtS *)&x, 1);
    CLACT_GetActorSurfacePos(((void **)(p + 0x1ef0))[i2], (struct PtS *)&y, 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1ef0))[i1], (const struct Vec2 *)(&y), 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1ef0))[i2], (const struct Vec2 *)(&x), 1);

    CLACT_GetActorSurfacePos(((void **)(p + 0x1f08))[i1], (struct PtS *)&x, 1);
    CLACT_GetActorSurfacePos(((void **)(p + 0x1f08))[i2], (struct PtS *)&y, 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1f08))[i1], (const struct Vec2 *)(&y), 1);
    CLACT_AddActorSurfacePos(((void **)(p + 0x1f08))[i2], (const struct Vec2 *)(&x), 1);
}




void B_PLIST_MAIN_Create(u8 *p)
{
    u8 *q;
    if (p[0x20]>5) p[0x20]=0;
    q=func_02030734(((struct Obj02915 *)p)->f10,0x2544,1,d_02212550,0x130);
    func_02030DA8(((struct Obj02915 *)p)->f28,(unsigned)B_PLIST_MAIN_Task,(unsigned)q,100);
    *(u8 * *)&((struct Obj06654 *)q)->f0=p;
    if (p[0x1f]!=5) p[0x4b]=0;
    else if (B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)q))==1 && p[0x1c]==1) p[0x20]++;
    ((struct Obj06654 *)q)->f1D8=((struct Obj02915 *)p)->f2C;
    ((struct Obj06654 *)q)->f2178=0;
    q[0x2176]=p[0x20];
    ((struct Obj06654 *)q)->f2540=0;
}




extern int (*const d_0221221C[])(u8 *);




void B_PLIST_MAIN_Task(void *task,u8 *p)
{
    if (((struct Obj25225 *)(*(u8 * *)&((struct Obj01006 *)p)->f0))->f34==1) {
        B_PLIST_MAIN_ClearSelection((u8 **)p);
        ((struct Obj01006 *)p)->f2178=33;
    }
    if (((struct Obj01006 *)p)->f2178!=33)
        ((struct Obj01006 *)p)->f2178=d_0221221C[*(int *)(p+0x2178)](p);
    if (((struct Obj01006 *)p)->f2178==33 && B_PLIST_MAIN_Delete(task,(char *)p)==1) return;
    TCBL_Main(((struct Obj01006 *)p)->f1D4);
    B_PLIST_MAIN_UpdateActorAnims(p);
    B_PLIST_ANM_StepPaletteAnim(p);
    B_PLIST_DRAW_UpdateToolWindows(p);
}




/*
 * volatile: hardware halfword store at 0220F4EC writes display register 04001050.
 */
int B_PLIST_MAIN_Init(u8 *p)
{
    d_04001050[0]=0;
    GXx_SetMasterBrightness_((u16 *)((u32)d_04001050+28),-16);
    ((struct Obj00633 *)p)->f1D4=TCBL_Create(((struct Obj25226 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,((struct Obj25227 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,1,4);
    if((*(u8 **)p)[31]==4) p[0x2180]=6;
    else if((*(u8 **)p)[31]==5) p[0x2180]=4;
    else p[0x2180]=0;
    ((struct Obj00633 *)p)->f2188=B_APP_TOOL_Create(((struct Obj25228 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10);
    B_PLIST_MAIN_InitOrder(p);B_PLIST_MAIN_ReadParty(p);B_PLIST_MAIN_InitBg(p);B_PLIST_MAIN_LoadGraphics((char *)p);B_PLIST_MAIN_CreateTextResources((char *)p);
    B_PLIST_MAIN_LoadModePalette(p,p[0x2180]);B_PLIST_ANM_UpdateByMode(p,p[0x2180]);B_PLIST_ANM_CopyPaletteSlot(p,p[0x2180]);
    B_PLIST_DRAW_Init((char *)p);
    if((*(u8 **)p)[31]==5) B_PLIST_MAIN_SyncMoveActors(p);
    B_PLIST_DRAW_LayoutActors((char *)p,p[0x2180]);B_PLIST_ANM_CreateTileWindows(p);B_PLIST_DRAW_DrawModePage((char *)p,p[0x2180]);B_PLIST_DRAW_ShowToolWindows(p);
    if(**(u8 * *)&((struct Obj25229 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f44==1) *(u32 *)&((struct Obj00633 *)p)->f218C=1;
    else *(u32 *)&((struct Obj00633 *)p)->f218C=0;
    B_APP_TOOL_SetActorsVisible((char *)(*(u8 * *)&((struct Obj00633 *)p)->f2188),((struct Obj00633 *)p)->f218C);
    if(p[0x2180]==0) {
        if(B_PLIST_MAIN_IsBattleSlot((u32)p,B_PLIST_MAIN_GetOrderIndex(p,0))==1) (*(u8 **)p)[32]=1;
        B_PLIST_MAIN_CreateCursor(p,p[0x2180],(*(u8 **)p)[32]);
    } else if((*(u8 **)p)[31]==5) B_PLIST_MAIN_CreateCursor(p,p[0x2180],(*(u8 **)p)[75]);
    else B_PLIST_MAIN_CreateCursor(p,p[0x2180],0);
    B_PLIST_MAIN_DrawExpBar(p,p[0x2180]);
    PALANM_RequestFade(((struct Obj00633 *)p)->f1D8,10,65535,0,16,0,0,((struct Obj25231 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f28);
    ((struct Obj00633 *)p)->f2540=1;
    return 1;
}




int B_PLIST_MAIN_WaitPrintQue(u8 *p) { if(PRINTSYS_QUE_IsFinished(*(const struct PrintSys * *)&((struct Obj14564 *)p)->f1EAC)==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct Obj25232 *)(*(u8 * *)&((struct Obj14564 *)p)->f0))->f10);return 2;}return 1; }




int B_PLIST_MAIN_WaitWipe(u8 *p) { if(WIPE_SYS_EndCheck()==1) { if((*(u8 **)p)[31]==4)return 25; if((*(u8 **)p)[31]==5)return 30; return 3; } return 2; }




int B_PLIST_MAIN_HandleSelectInput(u8 *p)
{
    u8 pair[2];
    if(PALANM_GetFadeRequestBits(*(char * *)&((struct Obj04601 *)p)->f1D8)!=0) return 3;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1) return 31;
    if(B_PLIST_MAIN_HandleCursorInput(p)==1) {
        if((*(u8 **)p)[32]==6) {
            if((*(u8 **)p)[31]==2) {
                if(B_PLIST_MAIN_PopSelectionPair(p,pair+1,pair,1)==1) {
                    if(pair[1]<pair[0]) (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[1])[72]=255;
                    else (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[0])[72]=255;
                    p[0x2499]=pair[1];
                    p[0x249a]=pair[0];
                    p[0x1e98]=0;
                    B_PLIST_MAIN_PlaySe((u8 **)p,1362);
                    return 9;
                }
            } else if((*(u8 **)p)[31]!=1) {
                B_PLIST_MAIN_PlaySe((u8 **)p,1362);
                B_PLIST_ANM_StartPaletteAnim(p,6);
                B_PLIST_MAIN_ClearSelection((u8 **)p);
                return 31;
            }
        } else {
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(*(u8 **)p)[32]);
            if((*(u8 **)p)[31]==3) return B_PLIST_MAIN_ConfirmSelect(p);
            ((struct Obj04601 *)p)->f217C=12;
            return 29;
        }
    }
    return 3;
}




int B_PLIST_MAIN_ConfirmSelect(u8 *p)
{
    u8 *q = *(u8 **)p;
    if (((Flag_0220F7C4 *)(p+B_PLIST_MAIN_GetOrderIndex(p,q[32])*76))[27].high != 0) {
        func_02045CAC(*(void **)(p+0x1ea0),91,*(void **)(p+0x1ea8));
        B_PLIST_DRAW_ClearAndPrintStream(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        B_PLIST_MAIN_ClearSelection((u8 **)p);
        return 23;
    }
    if ((q+B_PLIST_MAIN_GetOrderIndex(p,q[32]))[56] != 0) {
        B_PLIST_DRAW_FormatRowWord(p);
        B_PLIST_DRAW_ClearAndPrintStream(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        B_PLIST_MAIN_ClearSelection((u8 **)p);
        return 23;
    }
    if (FILE_UTIL_Get_0FE4((void *)*(u16 *)(q+36),39,*(u16 *)(q+16)) != 0 &&
        FILE_UTIL_Get_0FE4((void *)*(u16 *)(q+36),40,*(u16 *)(q+16)) == 0) {
        *(u32 *)(p+0x217c) = 18;
        return 29;
    }
    q[72] = B_PLIST_MAIN_GetOrderIndex(p,q[32]);
    return 31;
}




int B_PLIST_MAIN_HandleModeSelect(u8 *p)
{
    u32 sel;
    u8 *q;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1) return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj03907 *)p)->f2184);
    switch(sel) {
    case 0:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,7);
        if(B_PLIST_MAIN_PrintStatusMessage(p)==1) {
            q=*(u8 * *)&((struct Obj03907 *)p)->f0;
            if(q[31]!=2) {
                (q+q[33])[72]=B_PLIST_MAIN_GetOrderIndex(p,q[32]);
                return 31;
            }
            if(B_PLIST_MAIN_CanSwap(p)==0) {B_PLIST_MAIN_CommitSwap(p);return 31;}
            ((struct Obj03907 *)p)->f217C=19;return 29;
        }
        ((struct Obj03907 *)p)->f217C=21;return 29;
    case 1:
        if(B_PLIST_MAIN_IsRowFlagged(p)==1) break;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,8);
        ((struct Obj03907 *)p)->f217C=13;return 29;
    case 2:
        if(B_PLIST_MAIN_IsRowFlagged(p)==1) break;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,10);
        ((struct Obj03907 *)p)->f217C=14;return 29;
    case 3:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 4;
}




int B_PLIST_MAIN_HandleListSelect(u8 *p)
{
    u32 sel;
    u8 next;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj03908 *)p)->f2184);
    switch(sel){
    case 0:
        next=B_PLIST_MAIN_NextSelectable(p,(*(u8 **)p)[0x20],-1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,12);
            ((struct Obj03908 *)p)->f217C=20;
            return 29;
        }
        break;
    case 1:
        next=B_PLIST_MAIN_NextSelectable(p,(*(u8 **)p)[0x20],1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,13);
            ((struct Obj03908 *)p)->f217C=20;
            return 29;
        }
        break;
    case 2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,11);
        ((struct Obj03908 *)p)->f217C=14;
        return 29;
    case 3:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2190]=1;
        ((struct Obj03908 *)p)->f217C=12;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2190]=1;
        ((struct Obj03908 *)p)->f217C=12;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 5;
}




/*
 * Width: original narrows state to u8 before 0220B760; extern preserves caller truncation despite owner u32 state.
 */
int B_PLIST_MAIN_HandleMoveSelect(u8 *p)
{
    u32 sel;
    int row;
    u8 next;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj03349 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        row=(u32)p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20])*0x4C;
        if(*(u16 *)(row+sel*8+0x30)!=0){
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)(sel+14));
            (*(u8 **)p)[0x4B]=sel;
            ((struct Obj03349 *)p)->f217C=15;
            return 29;
        }
        break;
    case 4:
        next=B_PLIST_MAIN_NextSelectable(p,(*(u8 **)p)[0x20],-1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)12);
            ((struct Obj03349 *)p)->f217C=20;
            return 29;
        }
        break;
    case 5:
        next=B_PLIST_MAIN_NextSelectable(p,(*(u8 **)p)[0x20],1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(u8)13);
            ((struct Obj03349 *)p)->f217C=20;
            return 29;
        }
        break;
    case 6:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)9);
        ((struct Obj03349 *)p)->f217C=13;
        return 29;
    case 7:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        p[0x2190]=2;
        ((struct Obj03349 *)p)->f217C=12;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        p[0x2190]=2;
        ((struct Obj03349 *)p)->f217C=12;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 6;
}




int B_PLIST_MAIN_HandleSlotSelect(u8 *p)
{
    u32 sel;
    int row;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj10850 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        if((*(u8 **)p)[0x4B]!=sel){
            row=(u32)p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20])*0x4C;
            if(*(u16 *)(row+sel*8+0x30)!=0){
                B_PLIST_MAIN_PlaySe((u8 **)p,1357);
                (*(u8 **)p)[0x4B]=sel;
                return 15;
            }
        }
        break;
    case 4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj10850 *)p)->f217C=14;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj10850 *)p)->f217C=14;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 7;
}




int B_PLIST_MAIN_HandleSlotSelectFade(u8 *p)
{
    u32 sel;
    int row;
    if(PALANM_GetFadeRequestBits(*(const char * *)&((struct Obj14565 *)p)->f1D8)!=0)return 30;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1)return 31;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj14565 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        if((*(u8 **)p)[0x4B]!=sel){
            row=(u32)p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20])*0x4C;
            if(*(u16 *)(row+sel*8+0x30)!=0){
                B_PLIST_MAIN_PlaySe((u8 **)p,1357);
                (*(u8 **)p)[0x4B]=sel;
                return 15;
            }
        }
        break;
    case 4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        return 31;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        return 31;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 30;
}




int B_PLIST_MAIN_HandleItemSelect(u8 *p)
{
    u32 sel;
    u8 value;
    if(PALANM_GetFadeRequestBits(*(const char * *)&((struct Obj08361 *)p)->f1D8)!=0)return 25;
    sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj08361 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3: case 4:
        value=sel;
        (*(u8 **)p)[0x4B]=value;
        p[0x2191]=value;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)(sel+22));
        ((struct Obj08361 *)p)->f217C=17;
        return 29;
    case 5:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        return 31;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        B_PLIST_ANM_StartPaletteAnim(p,(u8)6);
        return 31;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 25;
}




int B_PLIST_MAIN_HandleConfirmCancel(u8 *p)
{
    u32 sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj04602 *)p)->f2184);
    switch(sel){
    case 0:
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,27);
        if(B_PLIST_MAIN_CheckMoveUsable(p)==0)((struct Obj04602 *)p)->f217C=31;
        else ((struct Obj04602 *)p)->f217C=27;
        return 29;
    case 1:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2192]=0;
        ((struct Obj04602 *)p)->f217C=16;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        p[0x2192]=0;
        ((struct Obj04602 *)p)->f217C=16;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 26;
}





/*
 * Addresses are Black-image addresses.
 */
u32 B_PLIST_MAIN_EnterState1A(u8 *p)
{
    B_PLIST_DRAW_PrintWordAndRefresh(p);
    ((struct Obj14566 *)p)->f2193 = 1;
    ((struct Obj14566 *)p)->f217C = 0x1a;
    return 0x17;
}




/*
 * lever: bounded permuter expanded row use, cast the row/column sum to u32,
 *   and captured the byte selection in tmp before calling B_PLIST_MAIN_GetOrderIndex.
 * Caller truncates the selection+18 argument to u8 before B_PLIST_ANM_StartPaletteAnim.
 */
int B_PLIST_MAIN_HandlePartySelect(u8 *p)
{
    u32 selection=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj10851 *)p)->f2184);
    u8 tmp;
    switch(selection) {
    case 0: case 1: case 2: case 3: {
        unsigned idx;
        u8 *row;
        tmp=(*(u8 **)p)[0x20];
        idx=B_PLIST_MAIN_GetOrderIndex(p,tmp);
        row=(u8 *)((u32)p+idx*0x4c);
        if(*(u16 *)((u32)((u32)((u8 *)((u32)p+idx*0x4c))+selection*8)+0x30)==0) break;
        (*(u8 **)p)[0x4b]=selection;
        (*(u8 **)p)[0x48]=idx;
        B_PLIST_MAIN_PlaySe((u8 **)p,1357);
        B_PLIST_ANM_StartPaletteAnim(p,(u8)(selection+18));
        return 31;
    }
    case 4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj10851 *)p)->f217C=11;
        return 29;
    case (u32)-2:
        B_PLIST_MAIN_PlaySe((u8 **)p,1362);
        B_PLIST_ANM_StartPaletteAnim(p,6);
        ((struct Obj10851 *)p)->f217C=11;
        return 29;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5:
    case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 28;
}





u32 B_PLIST_MAIN_ApplyMode0(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 0) == 0) {
        return 0xb;
    }
    return 0x3;
}





u32 B_PLIST_MAIN_ApplyMode1(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 1) == 0) {
        return 0xc;
    }
    return 0x4;
}





u32 B_PLIST_MAIN_ApplyMode2(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 2) == 0) {
        return 0xd;
    }
    return 0x5;
}





u32 B_PLIST_MAIN_ApplyMode3(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 3) == 0) {
        return 0xe;
    }
    return 0x6;
}





int B_PLIST_MAIN_ApplyMode4(char *p)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)p, 4) == 0)
    {
        return 0xf;
    }
    if (((struct Obj25233 *)((char *)((struct Obj03351 *)p)->f0))->f1F == 5)
    {
        return 0x1e;
    }
    return 7;
}





u32 B_PLIST_MAIN_ApplyMode6(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 6) == 0) {
        return 0x10;
    }
    return 0x19;
}





u32 B_PLIST_MAIN_ApplyMode7(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 7) == 0) {
        return 0x11;
    }
    return 0x1a;
}





u32 B_PLIST_MAIN_ApplyMode5(u32 a)
{
    if (B_PLIST_MAIN_ApplyMode((u8 *)a, 5) == 0) {
        return 0x12;
    }
    return 0x1c;
}




int B_PLIST_MAIN_RedrawByMode(u8 *p) { B_PLIST_DRAW_LayoutActors((char *)p,p[0x2180]);B_PLIST_DRAW_DrawModePage((char *)p,p[0x2180]);B_PLIST_ANM_UpdateByMode(p,p[0x2180]);B_PLIST_MAIN_DrawExpBar(p,p[0x2180]);if(p[0x2180]==2)return 5;return 6; }





u32 B_PLIST_MAIN_RefreshAndState16(u8 *p)
{
    B_PLIST_DRAW_ClearAndPrintStream(p);
    ((struct Obj25234 *)p)->f217C = 0x16;
    return 0x17;
}





u32 B_PLIST_MAIN_ClearPrintStream(u8 *p)
{
    BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj25235 *)p)->f1F68), 0);
    return 4;
}





int B_PLIST_MAIN_WaitPrintStream(struct S *a)
{
    switch (PRINTSYS_PrintStreamGetState((void *)a->f1eb0)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3) != 0)
            PRINTSYS_PrintStreamShortWait((struct Rec *)a->f1eb0, 0);
        a->f1eb4 = 0;
        break;
    case 1:
        if (a->f1eb4 != 0)
            break;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            B_PLIST_MAIN_PlaySe2((u8 **)a, 0x547);
            PRINTSYS_PrintStreamReleasePause((void *)a->f1eb0);
            a->f1eb4 = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete((struct Rec3 *)a->f1eb0);
        a->f1eb0 = 0;
        a->f1eb4 = 0;
        return 0x18;
    }
    return 0x17;
}




/*
 * remainder: separate conditional follower ov198_func_0221039C.c (28 bytes).
 */
int B_PLIST_MAIN_HandleSkipKey(char *p)
{
    if (B_PLIST_MAIN_CheckCancel((u8 **)p)==1) return 0x1f;
    if ((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()==1) {
        if (((struct Obj08362 *)p)->f2193==1) {
            BMP_MENUWORK_DrawWindowBorder(((struct Obj08362 *)p)->f1F68,0);
            ((struct Obj08362 *)p)->f2193=0;
        }
        return ((struct Obj08362 *)p)->f217C;
    }
    return 0x18;
}




int B_PLIST_MAIN_CheckBusyFlag(char *p)
{
    if (((struct Flag_0221039C *)(p+0x1e9b))->bit==0) return ((struct Obj25236 *)p)->f217C;
    return 0x1d;
}




int B_PLIST_MAIN_BeginFadeOut(char *p)
{
    if (B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1 && (*(u8 **)p)[0x20]!=6)
        (*(u8 **)p)[0x20]/=2u;
    PALANM_RequestFade(((struct Obj14567 *)p)->f1D8,10,0xffff,0,0,0x10,0,((struct Obj25237 *)(*(char * *)&((struct Obj14567 *)p)->f0))->f28);
    return 0x20;
}





u32 B_PLIST_MAIN_WaitFadeOut(u8 *p)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct Obj25238 *)p)->f1D8)) == 0) {
        return 0x21;
    }
    return 0x20;
}




int B_PLIST_MAIN_Delete(struct Node *task,char *p)
{
    if(((struct Obj01006 *)p)->f2540==1) {
        if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC)==0) {
            if(((struct Obj25239 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC);
            else return 0;
        }
        if(WIPE_SYS_EndCheck()==0) {
            if(((struct Obj25240 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0) PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0);
        if(*(struct Obj * *)&((struct Obj01006 *)p)->f2194) BGWINFRM_Delete((struct WinMgr *)(*(struct Obj * *)&((struct Obj01006 *)p)->f2194));
        B_PLIST_MAIN_DeleteTextResources((u8 *)p);
        B_PLIST_DRAW_DeleteActors(p);
        B_PLIST_DRAW_DeleteAllWindows((u8 *)p);
        B_PLIST_MAIN_ExitBg();
        TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01006 *)p)->f1D4);
        B_PLIST_MAIN_DeleteCursor((u8 *)p);
        B_APP_TOOL_Delete(((struct Obj01006 *)p)->f2188);
        if(((struct Obj01006 *)p)->f218C==1) **(u8 * *)&((struct Obj25241 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=1;
        else **(u8 * *)&((struct Obj25243 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=0;
    }
    (*(u8 **)p)[0x4c]=1;
    TCB_DeleteTask(task);
    func_020307B0(p);
    return 1;
}




void B_PLIST_MAIN_InitBg(u8 *p)
{
    struct BgVramReq req=d_02212144;
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
    BG_SYS_InitRun(5,32,0,((struct Obj25245 *)(*(u8 * *)&((struct Obj14568 *)p)->f0))->f10);
    BG_SYS_InitRun(4,32,0,((struct Obj25246 *)(*(u8 * *)&((struct Obj14568 *)p)->f0))->f10);
    BG_SYS_SetFlagField06(5);
    BG_SYS_SetFlagField06(4);
    BG_SYS_SetSubPlaneVisible(15,1);
}





void B_PLIST_MAIN_ExitBg(void)
{
    BG_SYS_SetSubPlaneVisible(0x1f, 0);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}




void B_PLIST_MAIN_LoadGraphics(char *p)
{
    void *owner=ARC_TOOL_CreateHandle(100,(u16)((((struct Obj25247 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10&0x7fff)|0x8000));
    void *handle;
    char *data;
    ARC_UTIL_UploadBgCharFromHandle(owner,18,7,0,0,1,((struct Obj25248 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    handle=func_02049EF4(owner,16,1,(void **)&data,((struct Obj25249 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    B_PLIST_ANM_CopyMonSpriteTiles(p,(u16 *)(data+12));
    func_020307B0(handle);
    handle=func_02049EF4(owner,17,1,(void **)&data,((struct Obj25250 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    B_PLIST_ANM_CopySubSpriteTiles(p,(u16 *)(data+12));
    func_020307B0(handle);
    PALANM_LoadArcPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,100,19,((struct Obj25251 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,0x1e0,0);
    ARC_TOOL_DeleteHandle(owner);
    MI_CpuCopy8((void *)(PALANM_GetDefaultWork(*(char * *)&((struct Obj02535 *)p)->f1D8,1)+0x180),p+0x1e78,32);
    BMP_MENUWORK_LoadCharAndPltt(4,1,14,0,((struct Obj25252 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,1,0xe0,32);
    PALANM_LoadArcPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,23,5,((struct Obj25253 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,32,0xd0);
}




void B_PLIST_MAIN_CreateTextResources(char *p)
{
    ((struct Obj02916 *)p)->f1EA0=func_02045B38(0,2,0x12,((struct Obj25254 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1E9C=GF_FONT_Create(0x17,3,0,0,((struct Obj25255 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EA4=GF_FONT_Create_EC64(((struct Obj25256 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EAC=PRINTSYS_QUE_CreateEx(0x800,((struct Obj25257 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EA8=STRBUF_Create(0x200,((struct Obj25258 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
}




void B_PLIST_MAIN_DeleteTextResources(u8 *p) { MSGDATA_Delete(*(struct Rec * *)&((struct Obj06656 *)p)->f1EA0);GF_FONT_Delete(((struct Obj06656 *)p)->f1E9C);WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct Obj06656 *)p)->f1EA4);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj06656 *)p)->f1EAC);STRBUF_Delete(*(struct U16Vec * *)&((struct Obj06656 *)p)->f1EA8); }




/*
 * lever: write upper experience to the same field in both if/else arms;
 *   one common store or a switch removes the original two-byte branch.
 * 2026-10-04: filed src/matched/arm9/POKE_TOOL_GetLevelMinExp.c (EXACT, 8 bytes); needs the label registered by the integrator, then this resolves.
 *   022107A8..0221099C. integrator-owned ARM9 Thumb tail stub, verified EXACT
 *   (8 bytes, 1/1 relocation resolved) in B9/blocker18544.log:
 *   typedef unsigned int u32;
 *   extern u32 POKE_TOOL_GetBoxLevelMinExp(void *);
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
    p->species=func_02017E1C(mon,5,0);
    if(p->species==0) return;
    p->hp=func_02017E1C(p->mon,0xa2,0);
    p->attack=func_02017E1C(p->mon,0xa3,0);
    p->defense=func_02017E1C(p->mon,0xa4,0);
    p->speed=func_02017E1C(p->mon,0xa5,0);
    p->stat6=func_02017E1C(p->mon,0xa6,0);
    p->spatk=func_02017E1C(p->mon,0xa0,0);
    p->spdef=func_02017E1C(p->mon,0xa1,0);
    p->ability=func_02017E1C(p->mon,0xae,0);
    p->form=func_02017E1C(p->mon,0xaf,0);
    p->level=(u8)func_02017E1C(p->mon,0x9e,0);
    if(func_02017E1C(p->mon,0xad,0)==1) p->egg=0;
    else p->egg=1;
    p->gender=POKE_TOOL_GetGender(p->mon);
    p->nature=(u8)func_020276C4((int)p->mon);
    p->flag=(u8)func_02017E1C(p->mon,0x4c,0);
    p->item=func_02017E1C(p->mon,10,0);
    p->unknown=func_02017E1C(p->mon,6,0);
    p->personality=func_02017E1C(p->mon,0x6f,0);
    p->exp=func_02017E1C(p->mon,8,0);
    exp=POKE_TOOL_GetLevelMinExp(p->mon);
    p->lower=exp;
    if(p->level==100) p->upper=p->lower;
    else p->upper=func_02018584(p->species,(u16)p->personality,(u16)(p->level+1));
    i=0;
    moves=p->moves;
    for(;i<4;i++) {
        move=&moves[i];
        moves[i].id=func_02017E1C(p->mon,i+0x36,0);
        if(moves[i].id==0) continue;
        move->pp=func_02017E1C(p->mon,i+0x3a,0);
        move->up=func_02017E1C(p->mon,i+0x3e,0);
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
void B_PLIST_MAIN_ReadParty(u8 *p)
{
    unsigned i;
    if (((struct Obj25259 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f18==0) {
        for (i=0;i<6;i++) {
            if (i<POKEPARTY_GetCount(((struct Obj25260 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(((struct Obj25261 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)(p+4+i*76));
        }
    } else {
        for (i=0;i<3;i++) {
            if (i<POKEPARTY_GetCount(((struct Obj25262 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(((struct Obj25263 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)(p+4+i*76));
            if (i<POKEPARTY_GetCount(((struct Obj25264 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(((struct Obj25265 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8,i),(struct Summary *)(p+4+(i+3)*76));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)(p+4+(i+3)*76));
        }
    }
}




int B_PLIST_MAIN_HandleCursorInput(u8 *p)
{
    u32 sel=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct Obj25266 *)p)->f2184);
    switch(sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if(B_PLIST_MAIN_GetSlotState(p,sel)) {
            (*(u8 **)p)[32]=sel;
            return 1;
        }
        break;
    case 6:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-2:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-3: case (u32)-4:
        B_PLIST_MAIN_PlaySe((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 0;
}




int B_PLIST_MAIN_GetSlotState(u8 *p,int i) { if(!*(u16 *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*76+8))return 0;if(B_PLIST_MAIN_IsSlotSelectable(p,i)==1)return 1;return 2; }




u8 B_PLIST_MAIN_NextSelectable(u8 *p,int i,int delta)
{
    int current=i;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) {
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
            if(((struct Flags *)(p+B_PLIST_MAIN_GetOrderIndex(p,selected)*0x4c+0x1b))->high) continue;
            return selected;
        }
    } else {
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            if(current==i) break;
            if(!B_PLIST_MAIN_GetSlotState(p,i)) continue;
            if(((struct Flags *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c+0x1b))->high) continue;
            return i;
        }
    }
    return 255;
}


/*
 * Lever: the seven-bit unsigned byte field emits shifts and an unsigned
 * comparison while retaining the original entry-pointer scheduling.
 */
void B_PLIST_MAIN_DrawExpBar(u8 *p,int mode)
{
    u8 *q;
    u32 numerator,denominator;
    u8 amount,i;
    u16 tile;
    if(mode!=2) return;
    q=p+4+76*B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32]);
    if(((Level *)q)->level<100U) {
        denominator=((struct Obj08363 *)q)->f24-((struct Obj08363 *)q)->f20;
        numerator=((struct Obj08363 *)q)->f1C-((struct Obj08363 *)q)->f20;
    } else { denominator=0; numerator=0; }
    amount=func_0202D01C(numerator,denominator,64);
    for(i=0;i<8;i++) {
        if(amount>=8) tile=30; else tile=amount+22;
        BG_SYS_SetTileEntry(7,tile,i+10,8,1,1,16);
        if(amount<8) amount=0; else amount-=8;
    }
    func_02041B6C(7);
}





/*
 * FCC receives only two loaded arguments here; mode is in 0..8, so its
 * out-of-domain incoming-r2 fallback is unused. BB94 receives live mode.
 */
int B_PLIST_MAIN_ApplyMode(u8 *p,unsigned mode)
{
    switch(((State *)p)->step) {
    case 0:
        if(PRINTSYS_QUE_IsFinished(((struct Obj03351 *)p)->f1EAC)==1) {
            B_PLIST_DRAW_DeleteStateWindows((char *)p);
            B_PLIST_DRAW_CreateStateWindows(p,mode);
            B_PLIST_DRAW_DrawModePage((char *)p,mode);
            ((State *)p)->step=(u8)(((State *)p)->step+1);
        }
        break;
    case 1:
        if(PRINTSYS_QUE_IsFinished(((struct Obj03351 *)p)->f1EAC)==1) {
            B_PLIST_MAIN_LoadModePalette(p,mode);
            BG_SYS_ClearLayerEx(4,0);
            BG_SYS_ClearLayerEx(5,0);
            B_PLIST_DRAW_ShowToolWindows(p);
            B_PLIST_MAIN_DrawExpBar(p,mode);
            B_PLIST_DRAW_LayoutActors((char *)p,mode);
            B_PLIST_MAIN_InitSelectionForMode(p,mode);
            B_PLIST_ANM_UpdateByMode(p,mode);
            B_PLIST_ANM_CopyPaletteSlot(p,mode);
            p[0x2180]=mode;
            ((State *)p)->step=0;
            return 1;
        }
        break;
    }
    return 0;
}





void B_PLIST_MAIN_LoadModePalette(u8 *p,u32 n)
{
    u32 i=0;
    const u32 *table=d_022121D4+n*2;
    u8 *out;
    void *buf;
    for(;i<2;i++) {
        buf=ARC_UTIL_LoadPaletteDataFromArchive(100,table[i],1,(u32)(&out),((struct Obj25269 *)(*(u8 * *)&((struct Obj25267 *)p)->f0))->f10);
        BG_SYS_DrawTile((u8)(i+6),(u32)(out+12),0,0,32,24);
        func_02041B6C(i+6);
        func_020307B0(buf);
    }
}





/*
 * Trailing 02210E1E halfword is zero alignment padding.
 */
int B_PLIST_MAIN_GetRowStatus(u8 *p)
{
    int index=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32]);
    u8 *q=p+4+76*index;
    if(B_PLIST_MAIN_IsBattleSlot((u32)p,index)==1) return 1;
    if(((struct Obj25270 *)q)->f10==0) return 2;
    if(B_PLIST_MAIN_IsSlotSelectable(p,(*(u8 **)p)[32])==1) return 3;
    if(B_PLIST_MAIN_IsRowFlagged(p)==1) return 5;
    if(B_PLIST_MAIN_IsIndexInParty(p,(*(u8 **)p)[32])==1) return 4;
    if(((struct Obj25271 *)(*(u8 * *)&((struct Obj10852 *)p)->f0))->f26!=0) return 6;
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
int B_PLIST_MAIN_PrintStatusMessage(u8 *p)
{
    u32 index=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32]);
    u8 *base=p+4;
    void *text;
    index*=76;
    switch((u32)B_PLIST_MAIN_GetRowStatus(p)) {
    case 1: text=func_02045EC0(*(void **)(p+0x1EA0),90); break;
    case 2:
        text=func_02045EC0(*(void **)(p+0x1EA0),87);
        WORDSET_SetSlotMonSpecies(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 3:
        text=func_02045EC0(*(void **)(p+0x1EA0),86);
        WORDSET_SetSlotMonSpecies(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 4:
        text=func_02045EC0(*(void **)(p+0x1EA0),103);
        WORDSET_SetSlotMonSpecies(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 5: text=func_02045EC0(*(void **)(p+0x1EA0),89); break;
    case 6:
        index=76*(*(u8 **)p)[33];
        text=func_02045EC0(*(void **)(p+0x1EA0),88);
        WORDSET_SetSlotMonSpecies(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 0: return 1;
    }
    WORDSET_CopyTaggedText(*(void **)(p+0x1EA4),*(void **)(p+0x1EA8),text);
    STRBUF_Delete(text);
    return 0;
}





u8 B_PLIST_MAIN_IsRowFlagged(u8 *p) { if(((Bits_02210C88 *)(p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32])*76+27))->high) return 1; return 0; }




int B_PLIST_MAIN_GetOwnerFlag18(char **p) { return ((struct Obj25272 *)(*p))->f18; }





u32 B_PLIST_MAIN_IsBattleSlot(u32 a, u32 b)
{
    if (B_PLIST_MAIN_GetOwnerFlag18((char **)a) == 1 && b >= 3) {
        return 1;
    }
    return 0;
}




/*
 * lever: Group the unsigned address sum as base plus row, then column, then offset.
 */
u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p) { u8 *q;unsigned long i;int row;q=*(u8 * *)&((struct Obj25273 *)p)->f0;i=q[75];if(i==4)return 0;row=(u32)p+q[32]*76;return func_0202F72C(((struct Obj08364 *)q)->f0,*(u16 *)(row+i*8+48),((struct Obj08364 *)q)->f10); }




int B_PLIST_MAIN_IsSlotSelectable(u8 *p,int i) { u32 v;v=B_PLIST_MAIN_GetOrderIndex(p,i);if(B_PLIST_MAIN_GetOwnerFlag18((char **)p)==1) {if(v==0 || v==3)return 1;return 0;}else {if(v<(*(u8 **)p)[34])return 1;return 0;} }





int B_PLIST_MAIN_IsIndexValid(char **p, unsigned int v)
{
    return v < ((struct Obj25275 *)(*p))->f22;
}




unsigned B_PLIST_MAIN_IsIndexInParty(u8 *p, int index)
{
    unsigned selected = B_PLIST_MAIN_GetOrderIndex(p, index);
    u8 *q = *(u8 * *)&((struct Obj10852 *)p)->f0;
    if (q[0x22] != 1) {
        if (selected == q[0x1d] || selected == q[0x1e]) return 1;
        return B_PLIST_MAIN_IsInSelection((u8 **)p, selected);
    }
    return 0;
}




void B_PLIST_MAIN_InitSelectionForMode(u8 *p, u32 state)
{
    u32 value;
    switch(state) {
    case 0: case 8:
        p[0x2190]=0;
        (*(u8 **)p)[0x4B]=0;
        value=(*(u8 **)p)[0x20];
        break;
    case 1:
        (*(u8 **)p)[0x4B]=0;
        value=p[0x2190];
        break;
    case 3: case 4:
        value=(*(u8 **)p)[0x4B];
        break;
    case 6: value=p[0x2191]; break;
    case 7: value=p[0x2192]; break;
    case 2: case 5: value=0; break;
    }
    B_PLIST_MAIN_RecreateCursor(p,state,value);
}




/*
 * Lead 112 bytes includes two pool words; follower 022110A4 is a
 * 20-byte independent push/pop swap leaf. No padding remains.
 */
void B_PLIST_MAIN_InitOrder(u8 *p)
{
    unsigned i;
    if(((struct Obj25276 *)(*(u8 * *)&((struct Obj14569 *)p)->f0))->f18==1) {
        for(i=0;i<6;i++) (p+i)[0x1CC]=d_02212138[(*(u8 **)p)[28]][i];
    } else {
        for(i=0;i<6;i++) (p+i)[0x1CC]=i;
    }
    for(i=0;i<3;i++) (*(u8 * *)&((struct Obj14569 *)p)->f0+i)[72]=255;
    for(i=0;i<2;i++) {
        *(u16 *)(p+i*4+0x249C)=255;
        *(u16 *)(p+i*4+0x249E)=255;
    }
}




void B_PLIST_MAIN_SwapOrder(u8 *p, int a, int b)
{
    u8 *q=p+0x1CC;
    u8 t=q[a];
    q[a]=q[b];
    q[b]=t;
}





u32 B_PLIST_MAIN_IsInSelection(u8 **p, u32 c)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        if (c == *(u8 *)(*p + i + 0x48)) {
            return 1;
        }
    }
    return 0;
}





/*
 * Recursive MATCH unblocker: named callee of the parked ov198 B_PLIST_DRAW_PrintStatRow0
 * (the first statement, `B_PLIST_MAIN_GetOrderIndex(a0)`, and every later use of the
 * resulting entry pointer).  `(p + i)[0x1cc]` is what keeps the added index in
 * r1 and the 0x1cc constant in r0 (`ldrb r0,[r1,r0]`); the subscript form folds
 * the constant into the pointer add.  The two-byte follower is the listing's
 * alignment word, so the extent runs one word long.
 *
 * Addresses are Black-image addresses.
 */
int B_PLIST_MAIN_GetOrderIndex(u8 *p, int i)
{
    return (p + i)[0x1cc];
}





void B_PLIST_MAIN_SetSelectionEntry(u8 **p, u32 b, u32 c)
{
    u8 v = B_PLIST_MAIN_GetOrderIndex((u8 *)p, c);

    *(u8 *)(*p + b + 0x48) = v;
}




void B_PLIST_MAIN_PushSelectionPair(u8 *p, int a, int b)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        u8 *q = p + i * 4;
        if (((struct Obj10854 *)q)->f249C == 0xff) {
            ((struct Obj10854 *)q)->f249C = a;
            ((struct Obj10854 *)q)->f249E = b;
            return;
        }
    }
}



int B_PLIST_MAIN_PopSelectionPair(unsigned char *p, unsigned char *a, unsigned char *b, int clear)
{
    int i;

    for (i = 1; i >= 0; i--) {
        if (*(unsigned short *)(p + 0x249c + i * 4) == 0xff) {
            continue;
        }
        *a = (unsigned char)*(unsigned short *)(p + 0x249c + i * 4);
        *b = (unsigned char)*(unsigned short *)(p + 0x249c + 2 + i * 4);
        if (clear == 1) {
            *(unsigned short *)(p + 0x249c + i * 4) = 0xff;
            *(unsigned short *)(p + 0x249c + 2 + i * 4) = 0xff;
        }
        return 1;
    }
    return 0;
}



int B_PLIST_MAIN_BeginMode8(u8 *p)
{
    int mode = 8;
    if (B_PLIST_MAIN_ApplyMode(p, mode) == 0) {
        p[0x2498] = (*(u8 **)p)[0x20];
        return 0x13;
    }
    return mode;
}



int B_PLIST_MAIN_PrintRowMessage(u8 *p)
{
    u8 *row;
    int idx;
    void *text;
    idx = B_PLIST_MAIN_GetOrderIndex(p, (*(u8 **)p)[0x20]);
    row = p + 4 + idx * 0x4c;
    if (B_PLIST_MAIN_IsBattleSlot((u32_02211190)p, idx) == 1) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x5a);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (B_PLIST_MAIN_IsIndexValid((char **)p, (*(u8 **)p)[0x20]) == 0) {
        if (B_PLIST_MAIN_IsIndexValid((char **)p, idx) == 1)
            text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x6b);
        else
            text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x6a);
        WORDSET_SetSlotMonSpecies(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (B_PLIST_MAIN_IsIndexInParty(p, (*(u8 **)p)[0x20]) == 1) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x56);
        WORDSET_SetSlotMonSpecies(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (((struct Obj08366 *)row)->f10 != 0) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x56);
        WORDSET_SetSlotMonSpecies(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    return 1;
}



int B_PLIST_MAIN_ConfirmSwap(u8 *p)
{
    if (PALANM_GetFadeRequestBits(((struct Obj02536 *)p)->f1D8) != 0) return 8;
    if (B_PLIST_MAIN_CheckCancel((u8 **)p) == 1) return 0x1f;
    if (B_PLIST_MAIN_HandleCursorInput(p) == 1) {
        if ((*(u8 **)p)[0x20] == 6) {
            B_PLIST_MAIN_PlaySe((u8 **)p, 0x552);
            B_PLIST_ANM_StartPaletteAnim(p, 6);
            (*(u8 **)p)[0x20] = p[0x2498];
            ((struct Obj02536 *)p)->f217C = 0xc;
            return 0x1d;
        }
        if ((*(u8 **)p)[0x20] == p[0x2498]) return 0xc;
        if (B_PLIST_MAIN_PrintRowMessage(p) == 1) {
            B_PLIST_MAIN_PushSelectionPair(p, (*(u8 **)p)[0x20], p[0x2498]);
            B_PLIST_MAIN_SetSelectionEntry((u8 **)p, (*(u8 **)p)[0x20], p[0x2498]);
            p[0x2499] = (*(u8 **)p)[0x20];
            p[0x249a] = p[0x2498];
            p[0x1e98] = 0;
            return 9;
        }
        B_PLIST_DRAW_ClearAndPrintStream(p);
        ((struct Obj02536 *)p)->f217C = 0xa;
        return 0x17;
    }
    return 8;
}




int B_PLIST_MAIN_EndSwap(char *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj25281 *)p)->f1F68, 0);
    B_PLIST_DRAW_PrintHeader10(p);
    B_PLIST_DRAW_ShowSubWindow((u8 *)p);
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
void B_PLIST_MAIN_MoveActorByFlag(u8 *p, int a, int b)
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




int B_PLIST_MAIN_UpdateSwapFrames(u8 *p)
{
    s8 xy[4];
    s8 pos[4];
    s8 pos2[4];
    switch (p[0x1e98]) {
    case 0: {
        u8 *buf;
        MGR = BGWINFRM_Create(2, 4, *(u16 *)(*(u8 **)p + 0x10));
        BGWINFRM_AddFrame(MGR, 0, 5, 0x10, 6);
        BGWINFRM_AddFrame(MGR, 1, 6, 0x10, 6);
        BGWINFRM_AddFrame(MGR, 2, 5, 0x10, 6);
        BGWINFRM_AddFrame(MGR, 3, 6, 0x10, 6);
        buf = func_02030734((u16)(0x8000 | (*(u16 *)(*(u8 **)p + 0x10) & 0x7fff)), 0xc0, 0, (const char *)data_02212550, 0xb89);
        B_PLIST_MAIN_CopyFrame(buf, 5, p[0x2499]);
        BGWINFRM_SetFrameData(MGR, 0, buf);
        B_PLIST_MAIN_CopyFrame(buf, 6, p[0x2499]);
        BGWINFRM_SetFrameData(MGR, 1, buf);
        B_PLIST_MAIN_CopyFrame(buf, 5, p[0x249a]);
        BGWINFRM_SetFrameData(MGR, 2, buf);
        B_PLIST_MAIN_CopyFrame(buf, 6, p[0x249a]);
        BGWINFRM_SetFrameData(MGR, 3, buf);
        func_020307B0(buf);
        B_PLIST_MAIN_GetFramePos((u8 *)&xy[1], (u8 *)&xy[0], p[0x2499]);
        BGWINFRM_PutFrame(MGR, 0, xy[1], xy[0]);
        BGWINFRM_PutFrame(MGR, 1, xy[1], xy[0]);
        B_PLIST_MAIN_GetFramePos((u8 *)&xy[1], (u8 *)&xy[0], p[0x249a]);
        BGWINFRM_PutFrame(MGR, 2, xy[1], xy[0]);
        BGWINFRM_PutFrame(MGR, 3, xy[1], xy[0]);
        BGWINFRM_UpdateMoves(MGR);
        p[0x1e98]++;
        break;
    }
    case 1:
        if (p[0x2499] & 1) {
            BGWINFRM_StartMove(MGR, 0, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, 1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 0, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, -1, 0, 0x10);
        }
        if (p[0x249a] & 1) {
            BGWINFRM_StartMove(MGR, 2, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, 1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 2, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, -1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 2: {
        BGWINFRM_UpdateMoves(MGR);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x2499], 0);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x249a], 0);
        BGWINFRM_GetPos(MGR, 0, &pos[3], &pos[2]);
        BGWINFRM_GetPos(MGR, 2, &pos[1], &pos[0]);
        if (BGWINFRM_IsMoving(MGR, 0) != 0) break;
        B_PLIST_MAIN_SwapOrder(p, p[0x2499], p[0x249a]);
        BGWINFRM_PutFrame(MGR, 0, pos[1], pos[0]);
        BGWINFRM_PutFrame(MGR, 1, pos[1], pos[0]);
        BGWINFRM_PutFrame(MGR, 2, pos[3], pos[2]);
        BGWINFRM_PutFrame(MGR, 3, pos[3], pos[2]);
        B_PLIST_MAIN_SwapActorPos((char *)p, p[0x2499], p[0x249a]);
        p[0x1e98]++;
        break;
    }
    case 3:
        BGWINFRM_UpdateMoves(MGR);
        if (p[0x249a] & 1) {
            BGWINFRM_StartMove(MGR, 0, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, -1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 0, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, 1, 0, 0x10);
        }
        if (p[0x2499] & 1) {
            BGWINFRM_StartMove(MGR, 2, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, -1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 2, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, 1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 4: {
        BGWINFRM_UpdateMoves(MGR);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x2499], 1);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x249a], 1);
        BGWINFRM_GetPos(MGR, 0, &pos2[3], &pos2[2]);
        BGWINFRM_GetPos(MGR, 2, &pos2[1], &pos2[0]);
        if (BGWINFRM_IsMoving(MGR, 0) == 0) p[0x1e98]++;
        break;
    }
    case 5:
        BGWINFRM_Delete(MGR);
        MGR = 0;
        p[0x1e98] = 0;
        return 0;
    }
    return 1;
}



int B_PLIST_MAIN_FinishSwap(u8 *p)
{
    if (B_PLIST_MAIN_UpdateSwapFrames(p) == 0) {
        if (B_PLIST_MAIN_HasSwappable(p) == 0) return 31;
        B_PLIST_ANM_UpdateSelectedTile(p);
        B_PLIST_DRAW_PrintHeader9((char *)p);
        B_PLIST_DRAW_ShowSubWindow(p);
        return 3;
    }
    return 9;
}



/*
 * tail: 0221189A..0221189C is zero alignment padding.
 */
int B_PLIST_MAIN_CanSwap(u8 *p)
{
    u8 count,i,bound;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) return 0;
    bound=(*(u8 **)p)[0x22];
    if(bound==1) return 0;
    count=0;
    for(i=0;i<bound;i++) {
        if(*(unsigned short *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c+0x14)==0) {
            count++;
            if(count==2) return 1;
        }
    }
    return 0;
}



int B_PLIST_MAIN_HasSwappable(u8 *p)
{
    u8 i;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) return 0;
    i=(*(u8 **)p)[0x22];
    if(i==1) return 0;
    for(;i<6;i++) {
        u8 *record=p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c;
        if(((struct Obj14570 *)record)->f8!=0 && ((Bits_022110F8 *)(record+0x1b))->high==0 && ((struct Obj14570 *)record)->f14!=0) return 1;
    }
    return 0;
}



/*
 * lever: associate the index with the destination pointer before adding 0x48.
 */
void B_PLIST_MAIN_CommitSwap(u8 *p)
{
    unsigned i;
    if(B_PLIST_MAIN_GetOwnerFlag18((char **)((unsigned)p))==1) {
        (*(u8 **)p)[0x48]=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    } else {
        for(i=0;i<3;i++) {
            if(*(unsigned short *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*0x4c+0x14)==0) {
                ((*(u8 * *)&((struct Obj14571 *)p)->f0)+i)[0x48]=(*(u8 **)p)[0x20];
                break;
            }
        }
    }
}




void B_PLIST_MAIN_ClearSelection(u8 **p)
{
    u32_02211944 i;

    for (i = 0; i < 3; i++) {
        *(u8 *)(*p + i + 0x48) = 0xff;
    }
}




u32_02211958 B_PLIST_MAIN_CheckCancel(u8 **p)
{
    if (((struct Obj25284 *)(*p))->f30 == 1) {
        B_PLIST_MAIN_ClearSelection(p);
        return 1;
    }
    return 0;
}




void B_PLIST_MAIN_PlaySe(u8 **p, u32_02211970 b)
{
    if (((struct Obj25286 *)(*p))->f40 == 1) {
        GFL_USE_PlaySeDefaultVolume(b);
    }
}




void B_PLIST_MAIN_PlaySe2(u8 **p, u32_02211984 b)
{
    if (((struct Obj25288 *)(*p))->f40 == 1) {
        GFL_USE_PlaySeDefaultVolume(b);
    }
}



/*
 * lever: enum offset retains 0x218C across calls and derives 0x2184.
 * ABI: 02211A24 explicitly receives the forwarded entry r2 as its r1.
 */
void B_PLIST_MAIN_CreateCursor(u8 *p,u32_02211998 index,u32_02211998 b)
{
    Offset offset=task_offset;
    struct Struct_02025CD0 *result;
    result=CURSOR_MOVE_Create(d_022122D4[index],(u32_02211998)d_022122A0,(u32_02211998)p,*(u32_02211998 *)(p+offset),b,((struct Obj25289 *)(*(u8 * *)&((struct Obj10855 *)p)->f0))->f10);
    *(struct Struct_02025CD0 **)(p+(offset-8))=result;
    CURSOR_MOVE_EnableInput((struct Struct_02025D1C *)result);
    offset-=8;
    CURSOR_MOVE_SetMode(*(struct Struct_02025D24 **)(p+offset));
    B_PLIST_MAIN_LayoutCursorActors(p,b);
}




u32_022119E8 B_PLIST_MAIN_DeleteCursor(u8 *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct Obj25290 *)p)->f2184));
}




void B_PLIST_MAIN_RecreateCursor(u8 *p, u32_022119F8 a, u32_022119F8 b)
{
    B_PLIST_MAIN_DeleteCursor(p);
    B_PLIST_MAIN_CreateCursor(p, a, b);
}




/*
 * note:     the callee takes (p, v); passing v as the second argument keeps r1 live
 *           across the store, so the index decrement stays in r2.
 */
u32_02211A10 B_PLIST_MAIN_SetActorsVisible(u8 *p, u32_02211A10 v)
{
    u32_02211A10 i = 0x218c;

    *(u32_02211A10 *)(p + i) = v;
    i -= 4;
    return B_APP_TOOL_SetActorsVisible(*(u32_02211A10 *)(p + i), v);
}




void B_PLIST_MAIN_LayoutCursorActors(u8 *p, u32_02211A24 idx)
{
    void *t = CURSOR_MOVE_GetEntry(*(void ** *)&((struct Obj10855 *)p)->f2184, idx);

    B_APP_TOOL_LayoutActors((int *)(((struct Obj10855 *)p)->f2188), (u8 *)((u32_02211A24)t));
}




void B_PLIST_MAIN_ShowCursor(u8 *p, unsigned idx)
{
    B_PLIST_MAIN_LayoutCursorActors(p, idx);
    B_PLIST_MAIN_SetActorsVisible(p, 1);
}
