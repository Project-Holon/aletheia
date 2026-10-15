/*
 * file:     poke_summary_main.c
 * unit:     yes
 * function: POKE_SUMMARY_MAIN_Create, POKE_SUMMARY_MAIN_Update, POKE_SUMMARY_MAIN_Delete, POKE_SUMMARY_MAIN_CreateTaskMenu, POKE_SUMMARY_MAIN_DeleteTaskMenu, POKE_SUMMARY_MAIN_UpdateTaskMenu, POKE_SUMMARY_MAIN_InitScreen, POKE_SUMMARY_MAIN_ExitScreen, POKE_SUMMARY_MAIN_VBlankCallback, POKE_SUMMARY_MAIN_SetVramBanks, POKE_SUMMARY_MAIN_InitDisplay, POKE_SUMMARY_MAIN_ExitDisplay, POKE_SUMMARY_MAIN_CreateMsgWindows, POKE_SUMMARY_MAIN_DeleteMsgWindow, POKE_SUMMARY_MAIN_CreateBmpWindows, POKE_SUMMARY_MAIN_DeleteBmpWindows, POKE_SUMMARY_MAIN_CreateText, POKE_SUMMARY_MAIN_DeleteText, POKE_SUMMARY_MAIN_WaitWipe, POKE_SUMMARY_MAIN_HandleInput, POKE_SUMMARY_MAIN_UpdateText, POKE_SUMMARY_MAIN_OpenMenu, POKE_SUMMARY_MAIN_UpdateMenu, POKE_SUMMARY_MAIN_ApplyMove, POKE_SUMMARY_MAIN_ShowTextKind6, POKE_SUMMARY_MAIN_ShowMoveText, POKE_SUMMARY_MAIN_StartWipe, POKE_SUMMARY_MAIN_RefreshMoveList, POKE_SUMMARY_MAIN_PrintAligned, POKE_SUMMARY_MAIN_PrintValue, POKE_SUMMARY_MAIN_DrawMovesPage, POKE_SUMMARY_MAIN_CountMoves, POKE_SUMMARY_MAIN_DrawMoveRow, POKE_SUMMARY_MAIN_RedrawMoveList, POKE_SUMMARY_MAIN_BuildMoveList, POKE_SUMMARY_MAIN_DeleteMoveList, POKE_SUMMARY_MAIN_DrawMoveDetail, POKE_SUMMARY_MAIN_SetTextByKind, POKE_SUMMARY_MAIN_GetRecordWord, POKE_SUMMARY_MAIN_GetMoveWord, POKE_SUMMARY_MAIN_StartTextStream, POKE_SUMMARY_MAIN_ClearWindow, POKE_SUMMARY_MAIN_SoundStateCallback, POKE_SUMMARY_MAIN_CountFreeMoves, POKE_SUMMARY_MAIN_ShowTextKind3, POKE_SUMMARY_MAIN_ClearWindowWaitA, POKE_SUMMARY_MAIN_SetFlagReturn8, POKE_SUMMARY_MAIN_ClearWindowWaitB, POKE_SUMMARY_MAIN_Finish
 * address:  0x021B6100
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   POKE_SUMMARY_ACTOR_PositionMonActor 0x021B7ADC thumb ov173
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   POKE_SUMMARY_ACTOR_StartWipe 0x021B7B60 thumb ov173
 *   POKE_SUMMARY_ACTOR_StartProc 0x021B7B8C thumb ov173
 *   POKE_SUMMARY_ACTOR_StartNetRestart 0x021B7C00 thumb ov173
 *   POKE_SUMMARY_ACTOR_WaitDecide 0x021B8110 thumb ov173
 *   POKE_SUMMARY_ACTOR_ShowTextKind2 0x021B815C thumb ov173
 *   POKE_SUMMARY_ACTOR_ShowTextKind1Or4 0x021B817C thumb ov173
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   d_021B81FC 0x021B81FC data a4
 *   d_021B81EC 0x021B81EC data a4
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_020490F4  0x020490F4  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   BMP_SetDisplaySwap  0x0204363C  arm
 *   func_020056A0  0x020056A0  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKE_SUMMARY_ACTOR_CreateActors  0x021B7A00  thumb  ov173
 *   POKE_SUMMARY_ACTOR_CreateSound  0x021B7C44  thumb  ov173
 *   POKE_SUMMARY_ACTOR_SetIdleAnim  0x021B8040  thumb  ov173
 *   POKE_SUMMARY_ACTOR_UpdateSound 0x021B7C7C thumb ov173
 *   POKE_SUMMARY_ACTOR_DeleteSystem 0x021B7694 thumb ov173
 *   func_02030EAC 0x02030EAC arm
 *   POKE_SUMMARY_ACTOR_FlushPendingTransfers 0x021B7908 thumb ov173
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   d_021B8280 0x021B8280 data a4
 *   d_021B82F0 0x021B82F0 data a4
 *   d_021B8330 0x021B8330 data a4
 *   d_021B8290 0x021B8290 data a4
 *   d_021B82B0 0x021B82B0 data a4
 *   d_021B82D0 0x021B82D0 data a4
 *   d_021B8310 0x021B8310 data a4
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049B40  0x02049B40  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021B8420 0x021B8420 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKE_SUMMARY_ACTOR_IsTaskMenuOpen 0x021B7F50 thumb ov173
 *   POKE_SUMMARY_ACTOR_ConfirmDecideById 0x021B80EC thumb ov173
 *   POKE_SUMMARY_ACTOR_OpenDecideWin 0x021B80A4 thumb ov173
 *   POKE_SUMMARY_ACTOR_ConfirmDecide 0x021B80C4 thumb ov173
 *   POKE_SUMMARY_ACTOR_UpdateScrollArrows 0x021B7F64 thumb ov173
 *   POKE_SUMMARY_ACTOR_SetScrollAnim 0x021B7FD0 thumb ov173
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   POKE_SUMMARY_ACTOR_SetSubBrightness 0x021B81B0 thumb ov173
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   d_021B8228 0x021B8228 data a4
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_SUMMARY_ACTOR_LayoutMoveActors 0x021B7968 thumb ov173
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKE_SUMMARY_ACTOR_SetMoveIcon 0x021B78CC thumb ov173
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 *   POKE_SUMMARY_ACTOR_SetMoveAnim 0x021B79E0 thumb ov173
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   d_021B8350 0x021B8350 data a4
 *   func_02017E1C  0x02017E1C  thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 */

#include "poke_summary_types.h"

struct ProcOwner;
struct GfFont;
struct Tcbl;
struct PrintSys;
struct TcblWork;
struct ProcOwner;
struct MsgBank;
struct R;
struct TaskMenuState;
struct U16Vec;
struct Node;
struct DispVram;
struct Descriptor;
struct CharBuf;
struct WordSet;
struct Rec;
struct Sound;
struct Ctx;
struct Rec3;
struct TaskMenu;
struct TaskMenuTmpl;
struct StrObj;
struct Cfg;
struct Obj;
struct ScanContext;
struct Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 id,value;} Row;

typedef enum { FLAGS_OFFSET=0x3ff8, OFFSET_FORCE_UNSIGNED=0xffffffffu } SharedOffset;

struct DispConfig {u32 unk_00,unk_04,unk_08,unk_0c;};

struct BgTemplate {u32 unk_00,unk_04,bufSize,unk_0c;u8 unk_10,unk_11,unk_12,unk_13;u32 unk_14;u8 unk_18,unk_19,unk_1a,unk_1b;u32 unk_1c;};

typedef struct { u32 a,b,c,d,e,f,g; } Entry;

typedef signed int     s32;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;

typedef int (*Callback)(u8 *);

typedef struct { Callback a,b; } Pair;

typedef signed short s16;

struct ScanOwner { u8 pad[16]; u16 *table; };

struct ScanContext { struct ScanOwner *owner; };

typedef signed char s8;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct ProcOwner *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int POKE_SUMMARY_ACTOR_StartWipe(u8 *p);
extern int POKE_SUMMARY_ACTOR_StartProc(char *p);
extern int POKE_SUMMARY_ACTOR_StartNetRestart(void *);
extern int POKE_SUMMARY_ACTOR_WaitDecide(u8 *p);
extern int POKE_SUMMARY_ACTOR_ShowTextKind2(char *p);
extern int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p);
extern void CLACT_DrawSystem(void);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Destroy(struct TcblWork *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct ProcOwner *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *p, int flag);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void BMP_SetDisplaySwap(u32 swap);
extern u32 func_020056A0(void (*cb)(void), void *p, int n);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern void POKE_SUMMARY_ACTOR_CreateActors(char *p, void *arg);
extern void POKE_SUMMARY_ACTOR_CreateSound(u8 *p);
extern void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *p);
extern int POKE_SUMMARY_ACTOR_UpdateSound(int *);
extern void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *p);
extern void func_02030EAC(struct Node *n);
extern void POKE_SUMMARY_ACTOR_FlushPendingTransfers(char *);
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_FreeLayerBuf(unsigned int);
extern void BG_SYS_Delete(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_020307B0(void *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 APP_KEYCURSOR_CreateDefault(int,int,int,int);
extern int APP_KEYCURSOR_Delete(int);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 WIPE_SYS_EndCheck(void);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *);
extern int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *,u16);
extern int POKE_SUMMARY_ACTOR_OpenDecideWin(char *,u16);
extern int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *p, u16 n);
extern void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *);
extern void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *,int);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void POKE_SUMMARY_ACTOR_SetSubBrightness(int);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_UpdateMenu(u32);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
extern void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u32 PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void *POKE_TOOL_GetBoxParam(void *);
extern u32 func_02017E88(void *,u32,u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void POKE_SUMMARY_ACTOR_SetMoveIcon(u8 *p, u16 id, u16 i);
extern void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon);
extern void *BMP_MENUWORK_Create(u32, u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 BMP_MENUWORK_Delete(void *p);
extern u32 WAZA_TOOL_GetParam(u16,u32);
extern u32 WAZA_TOOL_IsAlwaysHit(u16);
extern void POKE_SUMMARY_ACTOR_SetMoveAnim(u8 *p, u16 id);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);
extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void BG_SYS_PushTile(u32);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern int GFL_USE_IsAnySeBusy(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned int, unsigned int);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
int POKE_SUMMARY_MAIN_Create(struct ProcOwner *obj, int unused, u8 *input);
int POKE_SUMMARY_MAIN_Update(void *unused0,u32 *state,void *unused2,u8 *p);
int POKE_SUMMARY_MAIN_Delete(void *p,u32 a,u32 b,char *ctx);
void POKE_SUMMARY_MAIN_CreateTaskMenu(u8 *p);
void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *p);
void POKE_SUMMARY_MAIN_UpdateTaskMenu(int *p);
void POKE_SUMMARY_MAIN_InitScreen(u8 *p);
void POKE_SUMMARY_MAIN_ExitScreen(char *p);
void POKE_SUMMARY_MAIN_VBlankCallback(void *unused,char *p);
void POKE_SUMMARY_MAIN_SetVramBanks(void);
void POKE_SUMMARY_MAIN_InitDisplay(void);
void POKE_SUMMARY_MAIN_ExitDisplay(void);
void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *p, u8 *q);
int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *p);
void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *p);
void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *p);
void POKE_SUMMARY_MAIN_CreateText(char *p);
void POKE_SUMMARY_MAIN_DeleteText(char *p);
int POKE_SUMMARY_MAIN_WaitWipe(int *p);
int POKE_SUMMARY_MAIN_HandleInput(char *p);
int POKE_SUMMARY_MAIN_UpdateText(char *p);
int POKE_SUMMARY_MAIN_OpenMenu(u8 *p);
int POKE_SUMMARY_MAIN_UpdateMenu(u8 *p);
int POKE_SUMMARY_MAIN_ApplyMove(char **p);
int POKE_SUMMARY_MAIN_ShowTextKind6(int *p);
int POKE_SUMMARY_MAIN_ShowMoveText(char *p);
int POKE_SUMMARY_MAIN_StartWipe(char *p);
void POKE_SUMMARY_MAIN_RefreshMoveList(char *p);
u32 POKE_SUMMARY_MAIN_PrintAligned(char *p, int index, u32 font, u16 w, int align, u8 y);
void POKE_SUMMARY_MAIN_PrintValue(char *p,u32 idx,u32 a,u32 b,u8 c);
void POKE_SUMMARY_MAIN_DrawMovesPage(char *p);
u32 POKE_SUMMARY_MAIN_CountMoves(struct ScanContext *p);
void POKE_SUMMARY_MAIN_DrawMoveRow(char *p,u8 first,u8 row);
void POKE_SUMMARY_MAIN_RedrawMoveList(char *p);
void POKE_SUMMARY_MAIN_BuildMoveList(char *p);
void POKE_SUMMARY_MAIN_DeleteMoveList(char *p);
void POKE_SUMMARY_MAIN_DrawMoveDetail(char *p,int move);
void POKE_SUMMARY_MAIN_SetTextByKind(char *p, u32 kind);
u16 POKE_SUMMARY_MAIN_GetRecordWord(char **p);
unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *p);
void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);
void POKE_SUMMARY_MAIN_ClearWindow(char *p);
int POKE_SUMMARY_MAIN_SoundStateCallback(unsigned int state);
u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***p);
int POKE_SUMMARY_MAIN_ShowTextKind3(u8 *p);
int POKE_SUMMARY_MAIN_ClearWindowWaitA(char *p);
int POKE_SUMMARY_MAIN_ClearWindowWaitB(char *p);
extern Row d_021B81EC[];
extern const Row d_021B81FC[];
extern u8 d_02FE0000[];
extern const struct DispConfig d_021B8280;
extern const struct BgTemplate d_021B82F0,d_021B8330,d_021B8290,d_021B82B0,d_021B82D0,d_021B8310;
extern const Entry d_021B8420[];
extern Pair d_021B8228[];
extern const u32 d_021B8350[][11];




int POKE_SUMMARY_MAIN_Create(struct ProcOwner *obj, int unused, u8 *input)
{
    u8 *p;
    GFL_HEAP_CreateChildHeap(1,79,0x50000);
    p=PROCSYS_AllocProcWork(obj,0x228,79);
    MI_CpuFill8(p,0,0x228);
    ((struct PokeSummaryWork *)p)->mon=(struct PokeSummaryMon *)input;
    ((struct PokeSummaryWork *)p)->font=(void *)GF_FONT_Create(23,0,0,0,79);
    ((struct PokeSummaryWork *)p)->tcbl=(void *)TCBL_Create(79,79,32,32);
    POKE_SUMMARY_MAIN_InitScreen(p);
    POKE_SUMMARY_ACTOR_PositionMonActor(p,(u8)(((struct PokeSummaryWork *)p)->mon->selectedIndex),3);
    ((struct PokeSummaryWork *)p)->state=1;
    GFL_NET_RestartWithDefaultTimeout(1,79);
    return 1;
}




/*
 * extent: final 2 bytes are alignment padding
 */
int POKE_SUMMARY_MAIN_Update(void *unused0,u32 *state,void *unused2,u8 *p)
{
    switch(*state) {
    case 0: *state=POKE_SUMMARY_MAIN_WaitWipe((int *)p);break;
    case 1: *state=POKE_SUMMARY_MAIN_HandleInput((char *)p);break;
    case 2: *state=POKE_SUMMARY_MAIN_UpdateText((char *)p);break;
    case 3: *state=POKE_SUMMARY_MAIN_OpenMenu(p);break;
    case 4: *state=POKE_SUMMARY_MAIN_UpdateMenu(p);break;
    case 5: *state=POKE_SUMMARY_MAIN_ApplyMove((char **)p);break;
    case 6: *state=POKE_SUMMARY_MAIN_ShowTextKind6((int *)p);break;
    case 7: *state=POKE_SUMMARY_MAIN_ShowMoveText((char *)p);break;
    case 8: *state=POKE_SUMMARY_MAIN_StartWipe((char *)p);break;
    case 9: return 1;
    case 10: *state=POKE_SUMMARY_ACTOR_StartWipe(p);break;
    case 11: *state=POKE_SUMMARY_ACTOR_StartProc((char *)p);return 0;
    case 12: *state=POKE_SUMMARY_ACTOR_StartNetRestart(p);return 0;
    case 13: *state=POKE_SUMMARY_ACTOR_WaitDecide(p);break;
    case 14: *state=POKE_SUMMARY_ACTOR_ShowTextKind2((char *)p);break;
    case 15: *state=POKE_SUMMARY_ACTOR_ShowTextKind1Or4((char *)p);break;
    }
    POKE_SUMMARY_MAIN_UpdateTaskMenu((int *)p);
    CLACT_DrawSystem();
    TCBL_Main(((struct PokeSummaryWork *)p)->tcbl);
    PRINTSYS_QUE_Main(((struct PokeSummaryWork *)p)->printQueue);
    return 0;
}




int POKE_SUMMARY_MAIN_Delete(void *p,u32 a,u32 b,char *ctx) { POKE_SUMMARY_MAIN_ExitScreen(ctx); TCBL_Destroy(((struct PokeSummaryWork *)ctx)->tcbl); GF_FONT_Delete(((struct PokeSummaryWork *)ctx)->font); func_020315D4(p); GFL_HEAP_DeleteChecked(79); return 1; }




void POKE_SUMMARY_MAIN_CreateTaskMenu(u8 *p)
{
    int i;
    const Row *r;
    ((struct PokeSummaryWork *)p)->printQueue=(void *)PRINTSYS_QUE_Create((void *)79);
    ((struct PokeSummaryWork *)p)->taskMenuRes=APP_TASKMENU_RES_Create(4,10,(u32)((struct PokeSummaryWork *)p)->font,(u32)((struct PokeSummaryWork *)p)->printQueue,79);
    for(i=0;i<2;i++) {
        r=&d_021B81FC[i];
        ((struct PokeSummaryWork *)p)->moveEntries[i].text=func_02045EC0(((struct PokeSummaryWork *)p)->msgBank,r->id);
        ((struct PokeSummaryWork *)p)->moveEntries[i].number=14819;
        ((struct PokeSummaryWork *)p)->moveEntries[i].value=r->value;
    }
    for(i=0;i<2;i++) {
        r=&((Row *)d_021B81EC)[i];
        ((struct PokeSummaryWork *)p)->moveEntries[2+i].text=func_02045EC0(((struct PokeSummaryWork *)p)->msgBank,r->id);
        ((struct PokeSummaryWork *)p)->moveEntries[2+i].number=14819;
        ((struct PokeSummaryWork *)p)->moveEntries[2+i].value=r->value;
    }
    ((struct PokeSummaryWork *)p)->taskMenuWindows[0]=0;((struct PokeSummaryWork *)p)->taskMenuWindows[1]=0;
}




/*
 * Extent remainder: two zero alignment bytes at 021B638E.
 */
void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *p)
{
    POKE_SUMMARY_ACTOR_ToggleTaskMenu((char *)p, 0);
    STRBUF_Delete((struct U16Vec *)(((struct PokeSummaryWork *)p)->moveEntries[0].text));
    STRBUF_Delete((struct U16Vec *)(((struct PokeSummaryWork *)p)->moveEntries[1].text));
    STRBUF_Delete((struct U16Vec *)(((struct PokeSummaryWork *)p)->moveEntries[2].text));
    STRBUF_Delete((struct U16Vec *)(((struct PokeSummaryWork *)p)->moveEntries[3].text));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct PokeSummaryWork *)p)->taskMenuRes));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct PokeSummaryWork *)p)->printQueue));
}





void POKE_SUMMARY_MAIN_UpdateTaskMenu(int *p)
{
    if (((struct PokeSummaryWork *)p)->taskMenuWindows[0]) {
        APP_TASKMENU_WIN_Update((u8 *)(((struct PokeSummaryWork *)p)->taskMenuWindows[0]));
        APP_TASKMENU_WIN_Update((u8 *)(((struct PokeSummaryWork *)p)->taskMenuWindows[1]));
    }
}





void POKE_SUMMARY_MAIN_InitScreen(u8 *p)
{
    u8 *q;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    q = func_020490F4(0x7c, 0x4f);
    POKE_SUMMARY_MAIN_SetVramBanks();
    POKE_SUMMARY_MAIN_InitDisplay();
    POKE_SUMMARY_MAIN_CreateMsgWindows(p, q);
    POKE_SUMMARY_ACTOR_CreateActors((char *)p, q);
    POKE_SUMMARY_MAIN_CreateText((char *)p);
    POKE_SUMMARY_MAIN_CreateBmpWindows(p);
    POKE_SUMMARY_MAIN_BuildMoveList((char *)p);
    POKE_SUMMARY_MAIN_RefreshMoveList((char *)p);
    POKE_SUMMARY_MAIN_DrawMovesPage((char *)p);
    POKE_SUMMARY_ACTOR_CreateSound(p);
    POKE_SUMMARY_ACTOR_SetIdleAnim(p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4f);
    BMP_SetDisplaySwap(1);
    ((struct PokeSummaryWork *)p)->vblankTask = (void *)func_020056A0((void (*)(void))POKE_SUMMARY_MAIN_VBlankCallback, p, 0x10);
    ARC_TOOL_DeleteHandle((u32)q);
    POKE_SUMMARY_MAIN_CreateTaskMenu(p);
}




void POKE_SUMMARY_MAIN_ExitScreen(char *p) { POKE_SUMMARY_MAIN_DeleteTaskMenu((u8 *)p); POKE_SUMMARY_ACTOR_UpdateSound((int *)p); POKE_SUMMARY_MAIN_DeleteMoveList(p); POKE_SUMMARY_MAIN_DeleteBmpWindows(p); POKE_SUMMARY_MAIN_DeleteMsgWindow((int *)p); POKE_SUMMARY_MAIN_ExitDisplay(); POKE_SUMMARY_MAIN_DeleteText(p); POKE_SUMMARY_ACTOR_DeleteSystem((u8 *)p); func_02030EAC(((struct PokeSummaryWork *)p)->vblankTask); }




static inline void setShared(u32 base,SharedOffset off) { *(u32 *)(base+off)|=1; }




void POKE_SUMMARY_MAIN_VBlankCallback(void *unused,char *p) { POKE_SUMMARY_ACTOR_FlushPendingTransfers(p); BG_SYS_Update(); CLACT_VBlankSystem(); setShared((u32)d_02FE0000,FLAGS_OFFSET); }





void POKE_SUMMARY_MAIN_SetVramBanks(void)
{
    BG_SYS_SetVramBanks((void *)0x021B8250);
}




void POKE_SUMMARY_MAIN_InitDisplay(void)
{
    struct DispConfig cfg;
    struct BgTemplate a,b,c,d,e,f;
    BG_SYS_Create(79);BMP_WIN_Init(79);
    cfg=d_021B8280;BG_SYS_SetGraphicsMode(&cfg);
    a=d_021B82F0;BG_SYS_InitBgLayer(2,&a,0);BG_SYS_ClearSlot(2);
    b=d_021B8330;BG_SYS_InitBgLayer(3,&b,0);BG_SYS_ClearSlot(3);
    c=d_021B8290;BG_SYS_InitBgLayer(4,&c,0);BG_SYS_ClearSlot(4);
    d=d_021B82B0;BG_SYS_InitBgLayer(6,&d,0);BG_SYS_ClearSlot(6);
    e=d_021B82D0;BG_SYS_InitBgLayer(5,&e,0);BG_SYS_ClearSlot(5);
    f=d_021B8310;BG_SYS_InitBgLayer(7,&f,0);BG_SYS_ClearSlot(7);
    func_02040588(2,1);func_02040588(3,1);func_02040588(4,1);
    func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    BG_SYS_InitRun(2,32,0,79);BG_SYS_InitRun(4,32,0,79);
    BG_SYS_InitRun(5,32,0,79);BG_SYS_InitRun(2,32,0,79);BG_SYS_InitRun(4,32,0,79);
    *(u16 *)0x04000050=0;*(u16 *)0x04001050=0;
}




/*
 * volatile: 021B66A8 reads and 021B66AE writes hardware halfword.
 */
void POKE_SUMMARY_MAIN_ExitDisplay(void)
{
    BG_SYS_SetSubPlaneVisible(29, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    *(volatile unsigned short *)0x04000304 |= 0x8000;
    BG_SYS_Delete();
}





void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *p, u8 *q)
{
    u32 v = 1 << 0xb;
    void *t;

    func_02049658(q, 1, 3, 0, 0, 0, 0x4f);
    func_020498F4(q, 4, 3, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 0, 0, 0, 0x4f);
    func_02049658(q, 1, 7, 0, 0, 0, 0x4f);
    func_020498F4(q, 2, 7, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 4, 0, 0, 0x4f);
    t = func_02049EF4(q, 3, 0, (void **)&((struct PokeSummaryWork *)p)->tmpHandle, 0x4f);
    ((struct PokeSummaryWork *)p)->msgWindow = t;
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4f);
    BMP_MENUWORK_LoadCharAndPltt(4, 1, 0xd, 0, 0x4f);
}





int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *p)
{
    return func_020307B0((void *)(((struct PokeSummaryWork *)p)->msgWindow));
}




void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *p)
{
    u32 i;
    u32 h;
    for (i=0;i<16;i++) {
        ((struct PokeSummaryWork *)p)->bmpWindows[i]=(void *)BMP_WIN_Create((u8)d_021B8420[i].a,(u8)d_021B8420[i].b,(u8)d_021B8420[i].c,(u8)d_021B8420[i].d,d_021B8420[i].e,d_021B8420[i].f,(int)1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct PokeSummaryWork *)p)->bmpWindows[i])),0);
    }
    h=(u32)((struct PokeSummaryWork *)p)->bmpWindows[9];
    BMP_WIN_ClearScreen((struct Descriptor *)h);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    ((struct PokeSummaryWork *)p)->keyCursor=(void *)APP_KEYCURSOR_CreateDefault(15,1,1,79);
}




/*
 * extent: 2 zero alignment bytes at 0x021B684E follow the 38-byte function; no follower.
 */
void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *p) { u32 i; APP_KEYCURSOR_Delete((int)((struct PokeSummaryWork *)p)->keyCursor); for(i=0;i<16;i++) BMP_WIN_Delete(((struct PokeSummaryWork *)p)->bmpWindows[i]); BMP_WIN_Exit(); }




void POKE_SUMMARY_MAIN_CreateText(char *p) { ((struct PokeSummaryWork *)p)->msgBank=func_02045B38(0,2,204,79); ((struct PokeSummaryWork *)p)->wordSet=WORDSET_CreateDefault(79); ((struct PokeSummaryWork *)p)->strBufA=STRBUF_Create(256,79); ((struct PokeSummaryWork *)p)->strBufB=func_02045EC0(((struct PokeSummaryWork *)p)->msgBank,25); ((struct PokeSummaryWork *)p)->strBufC=func_02045EC0(((struct PokeSummaryWork *)p)->msgBank,31); }




void POKE_SUMMARY_MAIN_DeleteText(char *p) { MSGDATA_Delete(((struct PokeSummaryWork *)p)->msgBank); WORDSET_DeleteStrbufED04(((struct PokeSummaryWork *)p)->wordSet); STRBUF_Delete(((struct PokeSummaryWork *)p)->strBufA); STRBUF_Delete(((struct PokeSummaryWork *)p)->strBufB); STRBUF_Delete(((struct PokeSummaryWork *)p)->strBufC); }





int POKE_SUMMARY_MAIN_WaitWipe(int *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct PokeSummaryWork *)p)->state;
    return 0;
}




int POKE_SUMMARY_MAIN_HandleInput(char *p)
{
    u32 v;
    ((struct PokeSummaryWork *)p)->cursorIndex=CURSOR_MOVE_GetCurrent(*(struct Sound * *)&((struct PokeSummaryWork *)p)->sound);
    v=CURSOR_MOVE_PollRepeatInput(*(struct Sound * *)&((struct PokeSummaryWork *)p)->sound);
    switch(v) {
    case 0:case 1:case 2:case 3:
        if(TOUCHPANEL_GetTrg()==0) {
            if(((struct PokeSummaryWork *)p)->mon->scrollIndex+v < ((struct PokeSummaryWork *)p)->moveCount) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                return POKE_SUMMARY_ACTOR_ShowTextKind1Or4(p);
            }
        } else {
            if(((struct PokeSummaryWork *)p)->mon->scrollIndex+v < ((struct PokeSummaryWork *)p)->moveCount)
                GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 4:case 5:break;
    case 6:case 8:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(POKE_SUMMARY_ACTOR_IsTaskMenuOpen(p)) return POKE_SUMMARY_ACTOR_ConfirmDecideById(p,14);
        else return POKE_SUMMARY_ACTOR_OpenDecideWin(p,14);
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
        return POKE_SUMMARY_ACTOR_OpenDecideWin(p,14);
    case 7:
        if(POKE_SUMMARY_ACTOR_IsTaskMenuOpen(p)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return POKE_SUMMARY_ACTOR_ConfirmDecide((u8 *)p,15);
        }
        break;
    case -8:
        if(((struct PokeSummaryWork *)p)->mon->scrollIndex!=0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            --((struct PokeSummaryWork *)p)->mon->scrollIndex;
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
            POKE_SUMMARY_MAIN_RedrawMoveList(p);
            POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
            POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,-1);
        }
        break;
    case -4:case -3:case -1:break;
    }
    return 1;
}





int POKE_SUMMARY_MAIN_UpdateText(char *p)
{
    u32 r = PRINTSYS_PrintStreamGetState(((struct PokeSummaryWork *)p)->printStream);
    APP_KEYCURSOR_Update(((struct PokeSummaryWork *)p)->keyCursor, ((struct PokeSummaryWork *)p)->printStream, ((struct PokeSummaryWork *)p)->bmpWindows[7]);
    if (r == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(((struct PokeSummaryWork *)p)->printStream, 0);
    } else if (r == 2) {
        PRINTSYS_PrintStreamDelete(((struct PokeSummaryWork *)p)->printStream);
        return (int)((struct PokeSummaryWork *)p)->state;
    } else if (r == 1) {
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg()) {
            PRINTSYS_PrintStreamReleasePause(((struct PokeSummaryWork *)p)->printStream);
            GFL_USE_PlaySeDefaultVolume(0x547);
        }
    }
    return 2;
}




int POKE_SUMMARY_MAIN_OpenMenu(u8 *p)
{
    Descriptor x;
    x.heap = 79;
    x.count = 2;
    x.items = &((struct PokeSummaryWork *)p)->moveEntries[2];
    x.zero = 0;
    x.a = 21;
    x.b = 8;
    x.c = 10;
    x.d = 3;
    ((struct PokeSummaryWork *)p)->taskMenu = (void *)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&x), (void *)(((struct PokeSummaryWork *)p)->taskMenuRes));
    POKE_SUMMARY_ACTOR_SetSubBrightness(1);
    return 4;
}




int POKE_SUMMARY_MAIN_UpdateMenu(u8 *p)
{
    int result=4;
    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((struct PokeSummaryWork *)p)->taskMenu))) {
        if (APP_TASKMENU_GetCursorPos((const u8 *)(((struct PokeSummaryWork *)p)->taskMenu)) == 0)
            result=d_021B8228[((struct PokeSummaryWork *)p)->textKind].a(p);
        else
            result=d_021B8228[((struct PokeSummaryWork *)p)->textKind].b(p);
        POKE_SUMMARY_ACTOR_SetSubBrightness(0);
    }
    APP_TASKMENU_UpdateMenu((u32)((struct PokeSummaryWork *)p)->taskMenu);
    if (result != 4) APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct PokeSummaryWork *)p)->taskMenu));
    return result;
}




int POKE_SUMMARY_MAIN_ApplyMove(char **p)
{
    char *q;
    u32 zero;
    q = *p;
    POKE_TOOL_SetPartyValue(((struct PokeSummaryMon *)q)->party, ((struct PokeSummaryMon *)q)->variant + 0x36, POKE_SUMMARY_MAIN_GetRecordWord(p));
    q = *p;
    zero = 0;
    POKE_TOOL_SetPartyValue(((struct PokeSummaryMon *)q)->party, ((struct PokeSummaryMon *)q)->variant + 0x3e, 0);
    q = *p;
    POKE_TOOL_SetPartyValue(((struct PokeSummaryMon *)q)->party, ((struct PokeSummaryMon *)q)->variant + 0x3a, WAZA_TOOL_GetMaxPP(POKE_SUMMARY_MAIN_GetRecordWord(p), 0));
    ((struct PokeSummaryMon *)(*p))->applyFlag = zero;
    return 8;
}





int POKE_SUMMARY_MAIN_ShowTextKind6(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 6);
    ((struct PokeSummaryWork *)p)->state = 5;
    return 2;
}




int POKE_SUMMARY_MAIN_ShowMoveText(char *p)
{
    if (((struct PokeSummaryWork *)p)->mon->variant < 4) {
        POKE_SUMMARY_MAIN_StartTextStream(p, 10);
        ((struct PokeSummaryWork *)p)->textKind = 4;
    } else {
        POKE_SUMMARY_MAIN_StartTextStream(p, 7);
        ((struct PokeSummaryWork *)p)->textKind = 3;
    }
    ((struct PokeSummaryWork *)p)->state = 3;
    return 2;
}




int POKE_SUMMARY_MAIN_StartWipe(char *p) { WIPE_SYS_Start(0,0,0,0,6,1,79); ((struct PokeSummaryWork *)p)->state=9; return 0; }




void POKE_SUMMARY_MAIN_RefreshMoveList(char *p) { int n; n=POKE_SUMMARY_MAIN_GetRecordWord((char **)p); if(n!=65535) POKE_SUMMARY_MAIN_DrawMoveDetail(p,n); else POKE_SUMMARY_MAIN_DrawMoveDetail(p,-2); POKE_SUMMARY_ACTOR_LayoutMoveActors(p); }




/*
 * lever: separate u8 width result from u8 coordinate x; otherwise 16 bytes
 *   differ from index/font/x register rotation. Both cases preserve byte
 *   width narrowing and signed division by two before coordinate wrap.
 * domain: all nine direct ov173 calls use align 0..2; sites 021B6CE2=2,
 *   6D00=0,6D36=0,6D90=0,6E24=0,6F88=1,7242=1,728C=1,72B8=0.
 *   At 6DC4 r7 copies zero r4 and stays invariant; at 6F5E r4 becomes 1.
 *   No defined coordinate exists in the original outside this domain.
 * extent: 138 bytes code; +0x8A 00 00 alignment padding, next labelled
 *   function 021B6C84 at +0x8C. No follower or unit.
 */
u32 POKE_SUMMARY_MAIN_PrintAligned(char *p, int index, u32 font, u16 w, int align, u8 y)
{
    u8 x;
    u8 width;
    switch (align) {
    case 0: x = 0; break;
    case 1:
        width = (u8)func_0201D304(((struct PokeSummaryWork *)p)->strBufA, font, 0);
        x = (u8)((u8)(BMP_WIN_GetWidth(((struct PokeSummaryWork *)p)->bmpWindows[index]) * 8) - width);
        break;
    case 2:
        width = (u8)func_0201D304(((struct PokeSummaryWork *)p)->strBufA, font, 0);
        x = (u8)(((int)(u8)(BMP_WIN_GetWidth(((struct PokeSummaryWork *)p)->bmpWindows[index]) * 8) - width) / 2);
        break;
    }
    return PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[index]), x, y, ((struct PokeSummaryWork *)p)->strBufA, (void *)font, w);
}







void POKE_SUMMARY_MAIN_PrintValue(char *p,u32 idx,u32 a,u32 b,u8 c) { void *s; s=func_02045EC0(((struct PokeSummaryWork *)p)->msgBank,idx); WORDSET_SetSlotNumber(((struct PokeSummaryWork *)p)->wordSet,0,a,b,c,1); WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet,((struct PokeSummaryWork *)p)->strBufA,s); STRBUF_Delete(s); }







static inline void flush(void *win)
{
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}







/*
 * lever: temp,bank,mon declarations restore stack homes; derived wide coord=y+16 restores both narrowing sites and the early coordinate update (existing derived-wide-local idiom).
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * abi: 6BF8 font widened to u32 because original forwards a full word without truncation; 185F4 bare return preserves the visibly loaded pointer argument and live r0 result.
 */
void POKE_SUMMARY_MAIN_DrawMovesPage(char *p)
{
    u32 i;
    u16 move;
    int y;
    int coord;
    void *temp;
    void *bank;
    void *mon;
    func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x23,((struct PokeSummaryWork *)p)->strBufA);
    POKE_SUMMARY_MAIN_PrintAligned(p,9,(u32)((struct PokeSummaryWork *)p)->font,0x3c40,2,4);
    func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x17,((struct PokeSummaryWork *)p)->strBufA);
    POKE_SUMMARY_MAIN_PrintAligned(p,2,(u32)((struct PokeSummaryWork *)p)->font,0x440,0,0);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[2]);
    func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x18,((struct PokeSummaryWork *)p)->strBufA);
    POKE_SUMMARY_MAIN_PrintAligned(p,3,(u32)((struct PokeSummaryWork *)p)->font,0x440,0,0);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[3]);
    temp=STRBUF_Create(256,79);
    func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x27,temp);
    WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet,0,((struct PokeSummaryWork *)p)->mon->party);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet,((struct PokeSummaryWork *)p)->strBufA,temp);
    POKE_SUMMARY_MAIN_PrintAligned(p,13,(u32)((struct PokeSummaryWork *)p)->font,0x3c40,0,4);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[13]);
    bank=func_02045B38(0,2,0xcb,79);
    mon=POKE_TOOL_GetBoxParam(((struct PokeSummaryWork *)p)->mon->party);
    for(i=0;i<4;i++) {
        move=func_02017E88(mon,0x36+i,0);
        if(move==0) CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)p)->actors[8+i],0);
        else {
            CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)p)->actors[8+i],1);
            POKE_SUMMARY_ACTOR_SetMoveIcon((u8 *)p,move,i);
            func_02045CAC(bank,move,((struct PokeSummaryWork *)p)->strBufA);
            y=i*32;
            POKE_SUMMARY_MAIN_PrintAligned(p,14,(u32)((struct PokeSummaryWork *)p)->font,0x3c40,0,y);
            coord=y+16;
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[14]),8,coord,((struct PokeSummaryWork *)p)->strBufB,((struct PokeSummaryWork *)p)->font,0x440);
            flush(((struct PokeSummaryWork *)p)->bmpWindows[14]);
            WORDSET_SetSlotNumber(((struct PokeSummaryWork *)p)->wordSet,0,func_02017E88(mon,0x3a+i,0),2,1,1);
            WORDSET_SetSlotNumber(((struct PokeSummaryWork *)p)->wordSet,1,func_02017E88(mon,0x42+i,0),2,0,1);
            WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet,((struct PokeSummaryWork *)p)->strBufA,((struct PokeSummaryWork *)p)->strBufC);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[14]),32,coord,((struct PokeSummaryWork *)p)->strBufA,((struct PokeSummaryWork *)p)->font,0x440);
            flush(((struct PokeSummaryWork *)p)->bmpWindows[14]);
        }
    }
    flush(((struct PokeSummaryWork *)p)->bmpWindows[14]);
    func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x25,temp);
    WORDSET_SetSlotMonName(((struct PokeSummaryWork *)p)->wordSet,0,((struct PokeSummaryWork *)p)->mon->party);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet,((struct PokeSummaryWork *)p)->strBufA,temp);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[15]),0,0,((struct PokeSummaryWork *)p)->strBufA,((struct PokeSummaryWork *)p)->font,0x440);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[15]);
    func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x26,temp);
    WORDSET_SetSlotNumber(((struct PokeSummaryWork *)p)->wordSet,0,func_02017E88(mon,0x9e,0),3,1,1);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet,((struct PokeSummaryWork *)p)->strBufA,temp);
    POKE_SUMMARY_MAIN_PrintAligned(p,15,(u32)((struct PokeSummaryWork *)p)->font,0x440,1,16);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[15]);
    MSGDATA_Delete(bank);
    STRBUF_Delete(temp);
}







/*
 * Inline owner/table struct access restores the bound/index register allocation;
 * an extracted table pointer compiled 36 bytes with 18 concrete differences.
 */
u32 POKE_SUMMARY_MAIN_CountMoves(struct ScanContext *p) { u32 i;for(i=0;i<256;i++)if(p->owner->table[i]==0xffff)break;return i; }







void POKE_SUMMARY_MAIN_DrawMoveRow(char *p,u8 first,u8 row)
{
    int y;
    int index;
    u32 value;
    y=row*24;
    index=first+row;
    if(index>=((struct PokeSummaryWork *)p)->moveCount) return;
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[11]),0,y,*(void **)(*(char * *)&((struct PokeSummaryWork *)p)->menuWork+index*8),((struct PokeSummaryWork *)p)->font,0x3c40);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[11]);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[11]),96,y,((struct PokeSummaryWork *)p)->strBufB,((struct PokeSummaryWork *)p)->font,0x440);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[11]);
    value=WAZA_TOOL_GetMaxPP(*(u32 *)(*(char * *)&((struct PokeSummaryWork *)p)->menuWork+index*8+4),0);
    WORDSET_SetSlotNumber(((struct PokeSummaryWork *)p)->wordSet,0,value,2,1,1);
    WORDSET_SetSlotNumber(((struct PokeSummaryWork *)p)->wordSet,1,value,2,0,1);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet,((struct PokeSummaryWork *)p)->strBufA,((struct PokeSummaryWork *)p)->strBufC);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[11]),120,y,((struct PokeSummaryWork *)p)->strBufA,((struct PokeSummaryWork *)p)->font,0x440);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[11]);
}







void POKE_SUMMARY_MAIN_RedrawMoveList(char *p)
{
    u32 i;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[11]), 0);
    for (i = 0; i < 4; i++)
        POKE_SUMMARY_MAIN_DrawMoveRow(p, ((struct PokeSummaryWork *)p)->mon->scrollIndex, i);
    q = ((struct PokeSummaryWork *)p)->bmpWindows[11];
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(BMP_WIN_GetBgLayer(q));
    func_02041B6C(7);
    POKE_SUMMARY_ACTOR_LayoutMoveActors(p);
}







void POKE_SUMMARY_MAIN_BuildMoveList(char *p)
{
    u32 i;
    u16 move;
    void *bank;
    ((struct PokeSummaryWork *)p)->moveCount = POKE_SUMMARY_MAIN_CountMoves((struct ScanContext *)p);
    ((struct PokeSummaryWork *)p)->menuWork = BMP_MENUWORK_Create(((struct PokeSummaryWork *)p)->moveCount, 0x4f);
    i = 0;
    bank = func_02045B38(0, 2, 0xcb, 0x4f);
    for (; i < ((struct PokeSummaryWork *)p)->moveCount; i++) {
        move = ((u16 *)((struct PokeSummaryWork *)p)->mon->moveList)[i];
        if (move != 0xffff) {
            BMP_MENUWORK_AddMsgItem(((struct PokeSummaryWork *)p)->menuWork, (u32)bank, move, move, 0x4f);
        } else {
            BMP_MENUWORK_AddMsgItem(((struct PokeSummaryWork *)p)->menuWork, *(u32 *)&((struct PokeSummaryWork *)p)->msgBank, 0x20, -2, 0x4f);
            break;
        }
    }
    MSGDATA_Delete(bank);
    ((struct PokeSummaryWork *)p)->field1BB = 0;
    ((struct PokeSummaryWork *)p)->field1BC = ((struct PokeSummaryWork *)p)->mon->selectedIndex;
    POKE_SUMMARY_MAIN_RedrawMoveList(p);
}







void POKE_SUMMARY_MAIN_DeleteMoveList(char *p)
{
    BMP_MENUWORK_Delete(((struct PokeSummaryWork *)p)->menuWork);
}







static inline void clear(void *win)
{
    BMP_WIN_ClearScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}







/*
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * abi: 6BF8 font extern widened to u32: the original forwards the full p+0x60 word without narrowing.
 */
void POKE_SUMMARY_MAIN_DrawMoveDetail(char *p,int move)
{
    u32 value;
    void *bank;
    int zero;
    zero=0;
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[6]),0);
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[4]),0);
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[5]),0);
    CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)p)->actors[3],0);
    if(move!=zero-2) {
        value=WAZA_TOOL_GetParam(move,3);
        if(value<=1) func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x21,((struct PokeSummaryWork *)p)->strBufA);
        else POKE_SUMMARY_MAIN_PrintValue(p,0x1d,value,3,0);
        POKE_SUMMARY_MAIN_PrintAligned(p,4,(u32)((struct PokeSummaryWork *)p)->font,0x440,1,0);
        value=WAZA_TOOL_GetParam(move,4);
        if(value==0 || WAZA_TOOL_IsAlwaysHit(move)!=0) func_02045CAC(((struct PokeSummaryWork *)p)->msgBank,0x21,((struct PokeSummaryWork *)p)->strBufA);
        else POKE_SUMMARY_MAIN_PrintValue(p,0x1e,value,3,0);
        POKE_SUMMARY_MAIN_PrintAligned(p,5,(u32)((struct PokeSummaryWork *)p)->font,0x440,1,0);
        bank=func_02045B38(0,2,0xca,79);
        func_02045CAC(bank,move,((struct PokeSummaryWork *)p)->strBufA);
        POKE_SUMMARY_MAIN_PrintAligned(p,6,(u32)((struct PokeSummaryWork *)p)->font,0x440,0,0);
        MSGDATA_Delete(bank);
        POKE_SUMMARY_ACTOR_SetMoveAnim((u8 *)p,move);
        CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)p)->actors[3],1);
        flush(((struct PokeSummaryWork *)p)->bmpWindows[2]);
        flush(((struct PokeSummaryWork *)p)->bmpWindows[3]);
    } else {
        clear(((struct PokeSummaryWork *)p)->bmpWindows[2]);
        clear(((struct PokeSummaryWork *)p)->bmpWindows[3]);
    }
    flush(((struct PokeSummaryWork *)p)->bmpWindows[6]);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[4]);
    flush(((struct PokeSummaryWork *)p)->bmpWindows[5]);
}







void POKE_SUMMARY_MAIN_SetTextByKind(char *p, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party); break;
    case 1: WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 2: WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party); break;
    case 3:
        WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 4:
        WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 5:
        WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetMoveWord((int *)p)); break;
    case 6:
        WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 7: WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 8:
        WORDSET_SetSlotMonSpecies(((struct PokeSummaryWork *)p)->wordSet, 0, ((struct PokeSummaryWork *)p)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 9: WORDSET_SetSlotMyStatus(((struct PokeSummaryWork *)p)->wordSet, 2, (void *)(((struct PokeSummaryWork *)p)->mon->myStatus)); break;
    case 10: WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)p)->wordSet, 0, POKE_SUMMARY_MAIN_GetMoveWord((int *)p)); break;
    }
    str = func_02045EC0(((struct PokeSummaryWork *)p)->msgBank, d_021B8350[((struct PokeSummaryWork *)p)->mon->messageTableIndex][kind]);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)p)->wordSet, ((struct PokeSummaryWork *)p)->strBufA, str);
    STRBUF_Delete(str);
}








u16 POKE_SUMMARY_MAIN_GetRecordWord(char **p)
{
    struct PokeSummaryMon *q = (struct PokeSummaryMon *)*p;

    return *(u16 *)((char *)q->moveList + (q->scrollIndex + q->selectedIndex) * 2);
}








unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *p)
{
    struct PokeSummaryMon *q = ((struct PokeSummaryWork *)p)->mon;

    return func_02017E1C((void *)q->party, q->variant + 0x36, 0);
}







void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind)
{
    u32 zero;
    int speed;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)p)->bmpWindows[7]), 15);
    zero = 0;
    BMP_MENUWORK_DrawWindow(((struct PokeSummaryWork *)p)->bmpWindows[7], 0, 1, 13);
    POKE_SUMMARY_MAIN_SetTextByKind(p, kind);
    speed = MSG_SPEED_GetWait();
    ((struct PokeSummaryWork *)p)->printStream = PRINTSYS_PrintStreamCallBack(*(u32 *)&((struct PokeSummaryWork *)p)->bmpWindows[7], 0, 0, (u32)((struct PokeSummaryWork *)p)->strBufA, (u32)((struct PokeSummaryWork *)p)->font, speed, (u32)((struct PokeSummaryWork *)p)->tcbl, zero, 0x4f, 0xffff, (u32)POKE_SUMMARY_MAIN_SoundStateCallback);
    q = ((struct PokeSummaryWork *)p)->bmpWindows[7];
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
}







void POKE_SUMMARY_MAIN_ClearWindow(char *p)
{
    u32 x;

    BMP_MENUWORK_DrawWindowBorder((void *)(((struct PokeSummaryWork *)p)->bmpWindows[7]), 2);
    x = (u32)((struct PokeSummaryWork *)p)->bmpWindows[7];
    BMP_WIN_ClearScreen((struct Descriptor *)x);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)x));
}






int POKE_SUMMARY_MAIN_SoundStateCallback(unsigned int state)
{
    switch (state) {
    case 1: return GFL_USE_IsAnySeBusy();
    case 2: return GFL_USE_IsAnySeBusy();
    case 3: GFL_USE_PlaySeDefaultVolume(0x56b); break;
    case 4:
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 5:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}






u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***p) {u8 i;for(i=0;i<4;i++)if(!func_02017E1C(**p,i+54,0))break;return i;}




int POKE_SUMMARY_MAIN_ShowTextKind3(u8 *p) {POKE_SUMMARY_MAIN_StartTextStream((char *)p,3);(*(u8 **)p)[27]=POKE_SUMMARY_MAIN_CountFreeMoves((void ***)p);((struct PokeSummaryWork *)p)->state=5;return 2;}




/*
 * Extent runs long: 0x021B75BC is an unlabelled follower leaf, so EXACT*.
 */
int POKE_SUMMARY_MAIN_ClearWindowWaitA(char *p)
{
    POKE_SUMMARY_MAIN_ClearWindow(p);
    return 1;
}


int POKE_SUMMARY_MAIN_SetFlagReturn8(u8 **pp) { (*pp)[0x1a] = 1; return 8; }

/*
 * Extent runs long: 0x021B75D4 is an unlabelled follower leaf, so EXACT*.
 */
int POKE_SUMMARY_MAIN_ClearWindowWaitB(char *p)
{
    POKE_SUMMARY_MAIN_ClearWindow(p);
    return 1;
}

int POKE_SUMMARY_MAIN_Finish(u8 *p) { ((struct PokeSummaryWork *)p)->state = 10; return 0; }
