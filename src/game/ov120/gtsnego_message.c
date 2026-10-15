/*
 * file:     gtsnego_message.c
 * unit:     yes
 * function: GTSNEGO_MSG_SetCursorAnimSeq, GTSNEGO_MSG_IsCursorAnimDone, GTSNEGO_MSG_CreateActorAt, GTSNEGO_MSG_DeleteActors, GTSNEGO_MSG_SetActorMode, GTSNEGO_MSG_InitWindows, GTSNEGO_MSG_DeleteTileHandle, GTSNEGO_MSG_DrawTileRow, GTSNEGO_MSG_FillTileRow, GTSNEGO_MSG_DrawTileRows, GTSNEGO_MSG_TeardownActorList, GTSNEGO_MSG_TeardownTileRows, GTSNEGO_MSG_CursorDown, GTSNEGO_MSG_CursorUp, GTSNEGO_MSG_SetCursorIndex, GTSNEGO_MSG_CreateCursorActor, GTSNEGO_MSG_DeleteCursorActor, GTSNEGO_MSG_CreateIconActors, GTSNEGO_MSG_DeleteIconActors, GTSNEGO_MSG_RestartIconAnim, GTSNEGO_MSG_SetScrollState, GTSNEGO_MSG_ClearScrollState, GTSNEGO_MSG_StepScroll, GTSNEGO_MSG_ScrollAllRows, GTSNEGO_MSG_SetupRowBg, GTSNEGO_MSG_CreateListActor, GTSNEGO_MSG_SetListActorPos, GTSNEGO_MSG_SetListEntry, GTSNEGO_MSG_MoveListActor, GTSNEGO_MSG_ScrollListDown, GTSNEGO_MSG_ScrollListUp, GTSNEGO_MSG_FillListRange, GTSNEGO_MSG_GetListRowY, GTSNEGO_MSG_GetListRowYF, GTSNEGO_MSG_SetIconY, GTSNEGO_MSG_SetIconYClamped, GTSNEGO_MSG_CycleIdleAnim, GTSNEGO_MSG_CreateIdleActors, GTSNEGO_MSG_DeleteIdleActors, GTSNEGO_MSG_SetIdleAnim, GTSNEGO_MSG_CreateIdleUi, GTSNEGO_MSG_StepIdleFade, GTSNEGO_MSG_Teardown, GTSNEGO_MSG_DeleteButtons, GTSNEGO_MSG_Create, GTSNEGO_MSG_Main, GTSNEGO_MSG_Delete, GTSNEGO_MSG_PrintWindow, GTSNEGO_MSG_PrintWindowB, GTSNEGO_MSG_UpdatePrintStream, GTSNEGO_MSG_DeleteWindow, GTSNEGO_MSG_OpenMenu, GTSNEGO_MSG_UpdateButtons, GTSNEGO_MSG_DeleteRows, GTSNEGO_MSG_CreateRow, GTSNEGO_MSG_CreateRowEx, GTSNEGO_MSG_RedrawRow, GTSNEGO_MSG_FlushRowLayer, GTSNEGO_MSG_ClearRows, GTSNEGO_MSG_CreateYesNoUi, GTSNEGO_MSG_CreateListUi, GTSNEGO_MSG_RedrawRowA, GTSNEGO_MSG_RedrawRowB, GTSNEGO_MSG_RedrawRowC, GTSNEGO_MSG_DeleteButtonsKeep, GTSNEGO_MSG_CreateTooltip, GTSNEGO_MSG_PrintTooltip, GTSNEGO_MSG_PrintEntry, GTSNEGO_MSG_DeleteEntryWindow, GTSNEGO_MSG_PrintListEntry, GTSNEGO_MSG_PrintList, GTSNEGO_MSG_PrintListEntryAt, GTSNEGO_MSG_ShiftListDown, GTSNEGO_MSG_PrintListRange, GTSNEGO_MSG_PrintListEntryN, GTSNEGO_MSG_ShiftListUp, GTSNEGO_MSG_OpenMenuB, GTSNEGO_MSG_CloseMenu, GTSNEGO_MSG_CreateDraw, GTSNEGO_MSG_DeleteDraw, GTSNEGO_MSG_PrintDraw, GTSNEGO_MSG_PrintStatus, GTSNEGO_MSG_CreateConfirmUi, GTSNEGO_MSG_SetDecide, GTSNEGO_MSG_DeleteConfirmWindow, GTSNEGO_MSG_IsConfirmFinished, GTSNEGO_MSG_PrintPair, GTSNEGO_MSG_PrintSingle, GTSNEGO_MSG_PrintSummary, GTSNEGO_MSG_DeleteAll
 * address:  0x021D6A9C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gGtsnegoEntryTable 0x021D8B70 data a1
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GTSNEGO_DISP_DeleteTouchbar 0x021D698C thumb ov120
 *   GTSNEGO_DISP_CreateTouchbar 0x021D692C thumb ov120
 *   GTSNEGO_DISP_Noop 0x021D6810 thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0  0x020307B0  arm
 *   func_02042FB0 0x02042FB0 arm
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02049990 0x02049990 arm
 *   gGtsnegoIconX 0x021D892C data a2
 *   gGtsnegoIconY 0x021D8924 data a2
 *   gGtsnegoIconZ 0x021D893C data a2
 *   gGtsnegoIconW 0x021D8934 data a2
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_02008554 0x02008554 thumb
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fgeq 0x0209BB54 arm
 *   _ffix 0x0209C494 arm
 *   func_0204BA00 0x0204BA00 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   gGtsnegoIdleAnimTable 0x021D8AB0 data a4
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   func_02040588 0x02040588 arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   sGtsnegoMsgHeapName 0x021D8BEC data a1
 *   func_02030734 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   KEY_GetTrg 0x020362DC arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   gGtsnegoButtonYesNo 0x021D8AF8 data a4
 *   gGtsnegoRowLabelA 0x021D8BD8 data a2
 *   gGtsnegoRowLabelB 0x021D8BE0 data a2
 *   gGtsnegoButtonList 0x021D8B04 data a4
 *   STRBUF_Clear 0x0204581C arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   GTSNEGO_DISP_GetUnit 0x021D60FC thumb ov120
 *   PMS_DRAW_Create 0x0202DB0C thumb
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   gGtsnegoMsgDrawConfig 0x021D8B20 data ov120 a4
 *   func_020355C4 0x020355C4 arm
 *   gGtsnegoButtonConfirm 0x021D8AF0 data a4
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_CreateEx  0x0202800C  thumb  arm9
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb  arm9
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb  arm9
 *   PMS_DRAW_SetPrintColor  0x0202DE64  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb  arm9
 */
#include "ov120_types.h"

struct Obj;
struct Actor;
struct Vec2;
struct Sub0200852CObj;
struct PtS;
struct Cmd;
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct Cfg;
struct CharBuf;
struct TaskMenu;
struct TaskMenuTmpl;
struct Ctx;
struct StrObj;
struct PmsDraw;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct PosRecord {u16 x,y,z;u8 a,b;} PosRecord;

typedef signed int     s32;

typedef signed short s16;


typedef struct Triple { u16 a[3]; } Triple;










typedef struct { s16 x, y; } Vec;







typedef struct Pt { s16 x,y; } Pt;



typedef struct Callback { u16 n; u8 *p; void (*f)(u8 *); } Callback;


typedef struct Table { u32 a[16]; } Table;





typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;













typedef struct { int a, b; } Pair;




extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern void GTSNEGO_DISP_DeleteTouchbar(u8 *);
extern void GTSNEGO_DISP_CreateTouchbar(u8 *, int);
extern void GTSNEGO_DISP_Noop(u8 *, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern void func_02041B6C(u32 bit);
extern void BG_SYS_SetTileEntry(u32, int, int, int, u8, u8, u8);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_PushTile(u32);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern int _s32_div_f(int, int);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BUTTON_MAN_Delete(void *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_InitTextColor(void);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *BMP_MENUWORK_LoadFrameGfx(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void PMS_DRAW_Main(u8 *p);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern u32 KEY_GetTrg(void);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 GTSNEGO_DISP_GetUnit(u8 *p);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *p, u16 v);
extern void PMS_DRAW_PrintOffset(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern u8 func_020355C4(void);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoMsgCtx *p,u32 n);
int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_CreateActorAt(u8 *p,u16 x,u16 y,int flag);
void GTSNEGO_MSG_DeleteActors(u8 *p);
void GTSNEGO_MSG_SetActorMode(u8 *p,u32 n);
void GTSNEGO_MSG_InitWindows(u8 *p, int n);
void GTSNEGO_MSG_DeleteTileHandle(u8 *p);
void GTSNEGO_MSG_DrawTileRow(struct GtsnegoMsgCtx *p, int n);
void GTSNEGO_MSG_FillTileRow(struct GtsnegoMsgCtx *p, int n);
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoMsgCtx *p,void *list,int first);
void GTSNEGO_MSG_TeardownActorList(u8 *p);
void GTSNEGO_MSG_TeardownTileRows(u8 *p);
int GTSNEGO_MSG_CursorDown(void *unused,int *p);
int GTSNEGO_MSG_CursorUp(void *unused,int *p);
void GTSNEGO_MSG_SetCursorIndex(void *unused, int *p, int n);
void GTSNEGO_MSG_CreateCursorActor(u8 *p);
void GTSNEGO_MSG_DeleteCursorActor(u8 *p);
void GTSNEGO_MSG_CreateIconActors(u8 *p,int flag);
void GTSNEGO_MSG_DeleteIconActors(u8 *p);
void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoMsgCtx *p, u32 flag);
void GTSNEGO_MSG_SetScrollState(struct GtsnegoMsgCtx *p, int state);
void GTSNEGO_MSG_ClearScrollState(struct GtsnegoMsgCtx *p);
int GTSNEGO_MSG_StepScroll(u8 *p, int *out);
void GTSNEGO_MSG_ScrollAllRows(u8 *p, int flag);
void GTSNEGO_MSG_SetupRowBg(void *a0);
void GTSNEGO_MSG_CreateListActor(u8 *p, int n, int k);
void GTSNEGO_MSG_SetListActorPos(u8 *p, int index, int x, int y);
void GTSNEGO_MSG_SetListEntry(u8 *p, void *entry, int index);
void GTSNEGO_MSG_MoveListActor(u8 *p, int index, int delta);
void GTSNEGO_MSG_ScrollListDown(u8 *p, void *q);
void GTSNEGO_MSG_ScrollListUp(u8 *p, void *q);
void GTSNEGO_MSG_FillListRange(u8 *p, void *container, int offset);
int GTSNEGO_MSG_GetListRowY(struct GtsnegoMsgCtx *p, int index, int count);
int GTSNEGO_MSG_GetListRowYF(struct GtsnegoMsgCtx *p, int n, int count);
void GTSNEGO_MSG_SetIconY(struct GtsnegoMsgCtx *p, int index, int count);
int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoMsgCtx *p,int y,int count);
void GTSNEGO_MSG_CycleIdleAnim(char *p);
void GTSNEGO_MSG_CreateIdleActors(u8 *p);
void GTSNEGO_MSG_DeleteIdleActors(char *p);
void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoMsgCtx *p,int n);
void GTSNEGO_MSG_CreateIdleUi(u8 *p);
void GTSNEGO_MSG_StepIdleFade(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_Teardown(u8 *p);
void GTSNEGO_MSG_DeleteButtons(u8 *p);
char *GTSNEGO_MSG_Create(u32 heap,u32 n);
void GTSNEGO_MSG_Main(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_Delete(char *p);
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *p,u16 n);
void GTSNEGO_MSG_PrintWindowB(u8 *p, int n);
int GTSNEGO_MSG_UpdatePrintStream(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *p);
void *GTSNEGO_MSG_OpenMenu(char *p,int n);
int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_DeleteRows(char *p);
int GTSNEGO_MSG_CreateRow(u8 *p, int n, int a, int b, int c, int d);
int GTSNEGO_MSG_CreateRowEx(int a, int b, int c, int d);
void GTSNEGO_MSG_RedrawRow(char *p,u16 n,int i);
void GTSNEGO_MSG_FlushRowLayer(char *a0);
void GTSNEGO_MSG_ClearRows(char *p);
void GTSNEGO_MSG_CreateYesNoUi(char *p,int a,int b);
void GTSNEGO_MSG_CreateListUi(char *p,int a,int b,int c,int d,int e);
void GTSNEGO_MSG_RedrawRowA(char *p,int i);
void GTSNEGO_MSG_RedrawRowB(char *p,int i);
void GTSNEGO_MSG_RedrawRowC(char *p,int i);
void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p);
void *GTSNEGO_MSG_CreateTooltip(char *p,u16 n);
void GTSNEGO_MSG_PrintTooltip(char *p,u16 n);
void GTSNEGO_MSG_PrintEntry(char *p,void *r);
void GTSNEGO_MSG_DeleteEntryWindow(struct GtsnegoMsgCtx *p);
int GTSNEGO_MSG_PrintListEntry(char *p, void *r, int n);
void GTSNEGO_MSG_PrintList(char *p,void *q);
void GTSNEGO_MSG_PrintListEntryAt(char *p,void *q,int index);
void GTSNEGO_MSG_ShiftListDown(char *p);
void GTSNEGO_MSG_PrintListRange(char *p,void *q,int start);
void GTSNEGO_MSG_PrintListEntryN(char *p,void *q,int n);
void GTSNEGO_MSG_ShiftListUp(char *p);
void *GTSNEGO_MSG_OpenMenuB(char *p,int n);
void GTSNEGO_MSG_CloseMenu(int a);
void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *p,void *q);
void GTSNEGO_MSG_DeleteDraw(u8 *p);
void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *p, void *n);
void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *p, u16 n);
void GTSNEGO_MSG_CreateConfirmUi(u8 *p, int a, int b);
void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_DeleteConfirmWindow(u8 *p);
int GTSNEGO_MSG_IsConfirmFinished(u8 *p);
void GTSNEGO_MSG_PrintPair(char *p,int unused,u32 n);
void GTSNEGO_MSG_PrintSingle(char *p, void *n);
void GTSNEGO_MSG_PrintSummary(char *p,void *q,u32 n);
extern const u8 gGtsnegoEntryTable[][4];
extern const Triple gGtsnegoIconX,gGtsnegoIconY,gGtsnegoIconZ,gGtsnegoIconW;
extern const Table gGtsnegoIdleAnimTable;
extern const char sGtsnegoMsgHeapName[];
extern const int gGtsnegoButtonYesNo[];
extern const u16 gGtsnegoRowLabelA[],gGtsnegoRowLabelB[];
extern const int gGtsnegoButtonList[];
extern const u16 gGtsnegoRowLabelA[];
extern const Pair gGtsnegoMsgDrawConfig;
extern const int gGtsnegoButtonConfirm[];

int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoMsgCtx *p,u32 n){void *obj=p->f134;if(!obj)return 0;CLACT_SetActorAnimSeq(obj,gGtsnegoEntryTable[n][3]);return 1;}

int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoMsgCtx *p){if(!p->f134)return 0;if((u32)CLACT_GetActorAnimSeq(p->f134)>=29){if(CLACT_IsActorAnimActive(p->f134)==0)return 1;return 0;}return 0;}

void GTSNEGO_MSG_CreateActorAt(u8 *p,u16 x,u16 y,int flag) {
PosRecord r;int i;
for(i=0;i<12;i++) {
if(!*(void **)(p+i*4+0xc4)) {
r.x=x;r.y=y;r.z=flag?2:0;r.a=0;r.b=1;
*(void **)(p+0xc4+i*4)=CLACT_CreateActor((void *)((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f28,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f74,&r,1,((struct GtsnegoMsgCtx *)p)->fF4);
CLACT_SetActorAutoAnim(*(void **)(p+0xc4+i*4),1);
CLACT_SetActorDrawEnable(*(void **)(p+0xc4+i*4),1);
return;
}
}
}

/*
 * extent: two-byte zero alignment padding follows.
 * lever: base + index*4 + 0xc4 preserves the original add order.
 */
void GTSNEGO_MSG_DeleteActors(u8 *p){int i;for(i=0;i<12;i++){if(*(void **)(p+i*4+0xc4)){CLACT_DeleteActor(*(void **)(p+i*4+0xc4));*(int *)(p+i*4+0xc4)=0;}}}

void GTSNEGO_MSG_SetActorMode(u8 *p,u32 n){int got;int mode;got=CLACT_GetActorAnimSeq(*(void **)(p+0xc4+n*4));mode=1;if(got>=2)mode=3;CLACT_SetActorAnimSeq(*(void **)(p+0xc4+n*4),mode);CLACT_SetActorAutoAnim(*(void **)(p+0xc4+n*4),1);}

void GTSNEGO_MSG_InitWindows(u8 *p, int n)
{
    void *t;
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_DISP_CreateTouchbar(p, 8);
    GTSNEGO_DISP_Noop(p, 1);
    t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f120 = func_02049EF4(t, 21, 0, (void **)(p + 0x11c), ((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_UTIL_UploadPaletteFromHandle(t, 0, 5, 0, 320, 32, ((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    t = func_020490F4(32, ((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_UTIL_UploadPaletteFromHandle(t, 0, 5, 0, 0, 256, ((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_MSG_CreateCursorActor(p);
    GTSNEGO_MSG_CreateIconActors(p, n);
    *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f100 = 1;
}


/*
 * Addresses are Black-image addresses.
 */
void GTSNEGO_MSG_DeleteTileHandle(u8 *p)
{
    void *q = ((struct GtsnegoMsgCtx *)p)->f120;
    if (q) {
        func_020307B0(q);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->f120 = 0;
    }
}

void GTSNEGO_MSG_DrawTileRow(struct GtsnegoMsgCtx *p, int n)
{
    u16 *q = (u16 *)(*(u8 * *)&p->f11C + 0xc);
    int base = (u16)p->f0;
    int off;
    int index = 0;
    int y, x;
    y = 0;
    off = 6 * n;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++, index++)
            func_02042FB0(4, x, y + off, base + q[index]);
}

void GTSNEGO_MSG_FillTileRow(struct GtsnegoMsgCtx *p, int n)
{
    u8 *q = *(u8 * *)&p->f11C + 0xc;
    int base = (u16)p->f0;
    int off;
    int x, y;
    y = 0;
    off = 6 * n;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++)
            func_02042FB0(4, x, y + off, ((struct GtsnegoMsgCtx *)q)->f3E + base);
}

/*
 * extent: two-byte zero alignment padding follows.
 */
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoMsgCtx *p,void *list,int first){int i;for(i=0;i<6;i++){if(GTSNEGO_DISP_GetEntry(list,first+i))GTSNEGO_MSG_DrawTileRow(p,i);else GTSNEGO_MSG_FillTileRow(p,i);}func_02041B6C(4);}

void GTSNEGO_MSG_TeardownActorList(u8 *p)
{
    void *t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x14c)) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x14c));
            *(void **)(p + i * 4 + 0x14c) = 0;
        }
    }
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_DISP_CreateTouchbar(p, 0);
    GTSNEGO_MSG_DeleteCursorActor(p);
    ARC_TOOL_DeleteHandle(t);
}

void GTSNEGO_MSG_TeardownTileRows(u8 *p)
{
    void *t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    GTSNEGO_MSG_DeleteTileHandle(p);
    GTSNEGO_MSG_DeleteIconActors(p);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    ARC_UTIL_UploadPaletteFromHandle(t, 2, 5, 0, 256, 256, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t, 18, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 0, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02041B6C(4);
    ARC_TOOL_DeleteHandle(t);
}


/*
 * lever: name the p[2]+3 bound and reread p[2] for the increment;
 * retaining a named offset instead exchanges r3 and r4 (4-byte DIFF).
 */
int GTSNEGO_MSG_CursorDown(void *unused,int *p){int idx=p[1];int ret=0;if(idx<2 && idx<p[0]-1){p[1]=idx+1;return 1;}else if(idx==2){int bound=p[2]+3;if(bound<p[0]){p[2]=p[2]+1;ret=2;}}return ret;}


int GTSNEGO_MSG_CursorUp(void *unused,int *p){int idx=p[1];int ret=0;if(idx>0){p[1]=idx-1;return 1;}else if(idx==0 && p[2]!=0){p[2]=p[2]-1;ret=2;}return ret;}

void GTSNEGO_MSG_SetCursorIndex(void *unused, int *p, int n)
{
    if(n<(u32)p[0])p[1]=n;
    if(p[1]>2)p[1]=2;
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D6ED6.
 */
void GTSNEGO_MSG_CreateCursorActor(u8 *p)
{
    PosRecord r;
    r.x = 128; r.y = 200; r.z = 0; r.a = 1; r.b = 1;
    ((struct GtsnegoMsgCtx *)p)->f138 = CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f70, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f24, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->fBC, &r, 1, ((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct GtsnegoMsgCtx *)p)->f138, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f138, 1);
}


void GTSNEGO_MSG_DeleteCursorActor(u8 *p)
{
    void *q = ((struct GtsnegoMsgCtx *)p)->f138;
    if (q)
        CLACT_DeleteActor(q);
    *(u32 *)&((struct GtsnegoMsgCtx *)p)->f138 = 0;
}

/*
 * lever: declarations x,y,z,b reproduce the descending stack slots; p+i*4+offset keeps the per-element pointer.
 */
void GTSNEGO_MSG_CreateIconActors(u8 *p,int flag)
{
    PosRecord r;
    Triple x=gGtsnegoIconX;
    Triple y=gGtsnegoIconY;
    Triple z=gGtsnegoIconZ;
    Triple b=gGtsnegoIconW;
    int i;
    for(i=0;i<3;i++) {
        if(flag || i!=0) {
            r.x=x.a[i]; r.y=y.a[i]; r.z=z.a[i]; r.a=i; r.b=b.a[i];
            *(void **)(p+i*4+0x140)=CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f28,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f74,&r,1,((struct GtsnegoMsgCtx *)p)->fF4);
            CLACT_SetActorAutoAnim(*(void **)(p+i*4+0x140),1);
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x140),1);
        }
    }
}

/*
 * matching: declaring element after i puts the element in r4 and the counter in r5.
 */
void GTSNEGO_MSG_DeleteIconActors(u8 *p)
{
    int i;
    u32 element;
    for (i = 0; i < 3; i++) {
        element = (u32)p + (u32)i * 4;
        if (((struct GtsnegoMsgCtx *)element)->f140 != 0) {
            CLACT_DeleteActor(((struct GtsnegoMsgCtx *)element)->f140);
            ((struct GtsnegoMsgCtx *)element)->f140 = 0;
        }
    }
}

void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoMsgCtx *p, u32 flag)
{
    if (p->f140 != 0) {
        CLACT_RestartActorAnim(p->f140);
        CLACT_SetActorAutoAnim(p->f140, flag);
    }
}


void GTSNEGO_MSG_SetScrollState(struct GtsnegoMsgCtx *p, int state)
{
    p->f108 = state;
    if (state == 2) p->f10C = *(unsigned int *)&p->f104 + 48;
    else if (state == 1) p->f10C = *(unsigned int *)&p->f104 - 48;
}


void GTSNEGO_MSG_ClearScrollState(struct GtsnegoMsgCtx *p)
{
    *(unsigned int *)&p->f108 = 0;
}

/*
 * lever: pass the named loaded state to out instead of rematerializing 1 or 2.
 */
int GTSNEGO_MSG_StepScroll(u8 *p, int *out)
{
    int i;
    int state;
    state=((struct GtsnegoMsgCtx *)p)->f108;
    if (state==2) {
        ((struct GtsnegoMsgCtx *)p)->f104+=8;
        if (*(int *)&((struct GtsnegoMsgCtx *)p)->f10C==((struct GtsnegoMsgCtx *)p)->f104) {
            *out=state;
            ((struct GtsnegoMsgCtx *)p)->f108=0;
            ((struct GtsnegoMsgCtx *)p)->f104-=48;
        }
        for (i=0;i<6;i++) GTSNEGO_MSG_MoveListActor(p,i,-8);
        ((struct GtsnegoMsgCtx *)p)->f100=1;
    }
    state=((struct GtsnegoMsgCtx *)p)->f108;
    if (state==1) {
        ((struct GtsnegoMsgCtx *)p)->f104-=8;
        if (*(int *)&((struct GtsnegoMsgCtx *)p)->f10C==((struct GtsnegoMsgCtx *)p)->f104) {
            *out=state;
            ((struct GtsnegoMsgCtx *)p)->f108=0;
            ((struct GtsnegoMsgCtx *)p)->f104+=48;
        }
        for (i=0;i<6;i++) GTSNEGO_MSG_MoveListActor(p,i,8);
        ((struct GtsnegoMsgCtx *)p)->f100=1;
    }
    return ((struct GtsnegoMsgCtx *)p)->f108;
}

void GTSNEGO_MSG_ScrollAllRows(u8 *p, int flag)
{
    int i;
    int direction = 1;
    int step;
    if (flag != 0) direction -= 2;
    i = 0;
    step = direction * 48;
    for (; i < 6; i++) GTSNEGO_MSG_MoveListActor(p, i, step);
}

void GTSNEGO_MSG_SetupRowBg(void *a0)
{
    BG_SYS_FillScrollArea(4, 3, 0);
    BG_SYS_FillScrollArea(6, 3, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(1);
}

void GTSNEGO_MSG_CreateListActor(u8 *p, int n, int k)
{
    PosRecord r;
    if (*(void **)(p + 0x14c + n * 4)) CLACT_DeleteActor(*(void **)(p + 0x14c + n * 4));
    r.x = 0; r.y = 0; r.z = 1; r.a = 10; r.b = 2;
    *(void **)(p + 0x14c + n * 4) = CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10, *(u32 *)(p + (k + 6) * 4 + 0x18), *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f20, *(u32 *)(p + (k + 25) * 4 + 0x18), &r, 1, ((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_SetActorAutoAnim(*(void **)(p + 0x14c + n * 4), 1);
    CLACT_SetActorDrawEnable(*(void **)(p + 0x14c + n * 4), 0);
}

void GTSNEGO_MSG_SetListActorPos(u8 *p, int index, int x, int y)
{
    Vec pos;
    if (index < 6) {
        pos.x = x;
        pos.y = y;
        CLACT_AddActorSurfacePos(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable(*(void **)((u32)p + 0x14c + (u32)index * 4), 1);
    }
}

void GTSNEGO_MSG_SetListEntry(u8 *p, void *entry, int index)
{
    if (entry != 0) {
        GTSNEGO_MSG_CreateListActor(p, index, func_02008554((const struct Sub0200852CObj *)((int)entry)));
        GTSNEGO_MSG_SetListActorPos(p, index, 16, -48 * (1 - index));
    }
}

void GTSNEGO_MSG_MoveListActor(u8 *p, int index, int delta)
{
    Vec pos;
    if (*(void **)((u32)p + 0x14c + (u32)index * 4) != 0) {
        CLACT_GetActorSurfacePos(*(void **)((u32)p + 0x14c + (u32)index * 4), (struct PtS *)&pos, 1);
        pos.y += (s16)delta;
        CLACT_AddActorSurfacePos(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
    }
}

void GTSNEGO_MSG_ScrollListDown(u8 *p, void *q)
{
    int i;
    if (q) {
        if (((struct GtsnegoMsgCtx *)p)->f14C) CLACT_DeleteActor(((struct GtsnegoMsgCtx *)p)->f14C);
        for (i = 0; i < 5; i++) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x150 + i * 4);
        ((struct GtsnegoMsgCtx *)p)->f160 = 0;
        GTSNEGO_MSG_SetListEntry(p, q, 5);
    }
}

void GTSNEGO_MSG_ScrollListUp(u8 *p, void *q)
{
    int i;
    if (q) {
        if (((struct GtsnegoMsgCtx *)p)->f160) CLACT_DeleteActor(((struct GtsnegoMsgCtx *)p)->f160);
        for (i = 5; i > 0; i--) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x148 + i * 4);
        ((struct GtsnegoMsgCtx *)p)->f14C = 0;
        GTSNEGO_MSG_SetListEntry(p, q, 0);
    }
}

void GTSNEGO_MSG_FillListRange(u8 *p, void *container, int offset)
{
    int i;
    void *entry;
    for (i = 0; i < 6; i++) {
        if ((int)((u32)i + (u32)offset) >= 0) {
            entry = GTSNEGO_DISP_GetEntry(container, (int)((u32)i + (u32)offset));
            if (entry != 0) GTSNEGO_MSG_SetListEntry(p, entry, i);
        }
    }
}

int GTSNEGO_MSG_GetListRowY(struct GtsnegoMsgCtx *p, int index, int count)
{
    if (index == 0) return 0;
    count = (int)((u32)count - 1);
    if (index == count) return 132;
    return _s32_div_f((int)((u32)index * 132), count);
}

int GTSNEGO_MSG_GetListRowYF(struct GtsnegoMsgCtx *p, int n, int count)
{
    float f;
    float scale;
    f = (float)(n - 26);
    scale = 132.0f;
    if (count <= 3) return 0;
    f = f / (scale / (float)(count - 2));
    if (f >= (float)(count - 2)) f = (float)(count - 3);
    return (int)f;
}

void GTSNEGO_MSG_SetIconY(struct GtsnegoMsgCtx *p, int index, int count)
{
    Vec pos;
    if (p->f140 != 0) {
        CLACT_GetActorSurfacePos(p->f140, (struct PtS *)&pos, 1);
        pos.y = GTSNEGO_MSG_GetListRowY(p, index, count) + 26;
        CLACT_AddActorSurfacePos(p->f140, (const struct Vec2 *)(&pos), 1);
    }
}

int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoMsgCtx *p,int y,int count) { Pt pt; int result; result=0; if(p->f140) { CLACT_GetActorSurfacePos(p->f140,(struct PtS *)&pt,1); pt.y=y; CLACT_AddActorSurfacePos(p->f140,(const struct Vec2 *)(&pt),1); result=GTSNEGO_MSG_GetListRowYF(p,y,count); } return result; }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void GTSNEGO_MSG_CycleIdleAnim(char *p) { u16 next; next=CLACT_GetActorAnimSeq(((struct GtsnegoMsgCtx *)p)->f130)+1; if(next>26) next=11; CLACT_SetActorAnimSeq(((struct GtsnegoMsgCtx *)p)->f130,next); }

void GTSNEGO_MSG_CreateIdleActors(u8 *p)
{
    Callback c;
    PosRecord r;
    r.x=128; r.y=52; r.z=27; r.a=2; r.b=1;
    ((struct GtsnegoMsgCtx *)p)->f12C=CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f2C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f1C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f78,&r,0,((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct GtsnegoMsgCtx *)p)->f12C,1);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f12C,1);
    r.z=11; r.a=1;
    ((struct GtsnegoMsgCtx *)p)->f130=CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f2C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f1C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f78,&r,0,((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct GtsnegoMsgCtx *)p)->f130,1);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f130,1);
    c.n=0; c.p=p; c.f=(void (*)(u8 *))GTSNEGO_MSG_CycleIdleAnim;
    func_0204BA00(((struct GtsnegoMsgCtx *)p)->f130,(const struct Cmd *)(&c));
    BG_SYS_SetMainVisiblePlanes(31);
}

void GTSNEGO_MSG_DeleteIdleActors(char *p) { CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f12C,0); CLACT_DeleteActor(((struct GtsnegoMsgCtx *)p)->f12C); CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f130,0); CLACT_DeleteActor(((struct GtsnegoMsgCtx *)p)->f130); }

void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoMsgCtx *p,int n)
{
    Table a=gGtsnegoIdleAnimTable;
    void *t=func_020490F4(144,p->fF4);
    func_02049990(t,15,0,0,(u16)(p->f4),0,0,p->fF4);
    ARC_TOOL_DeleteHandle(t);
    CLACT_SetActorAutoAnim(p->f130,0);
    CLACT_SetActorAnimSeq(p->f130,a.a[n]+11);
    CLACT_SetActorAnimIndex((int)(p->f130),4);
    CLACT_SetActorAnimSeq(p->f12C,28);
    func_02041B6C(0);
    p->f110=0;
    p->f114=0;
}

void GTSNEGO_MSG_CreateIdleUi(u8 *p)
{
    void *t=func_020490F4(144,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,14,2,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,13,0,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,16,3,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_MSG_CreateIdleActors(p);
    func_02041B6C(2); func_02041B6C(0); func_02041B6C(3);
    ((struct GtsnegoMsgCtx *)p)->f110=0;
    ((struct GtsnegoMsgCtx *)p)->f114=1;
}

void GTSNEGO_MSG_StepIdleFade(struct GtsnegoMsgCtx *p) { if(p->f114) { BG_SYS_FillScrollArea(2,3,p->f110); p->f110+=1; } }

/*
 * trailing: 2-byte zero alignment padding at 0x021D770E.
 * lever: indexed pointer sum before the far field offset preserves the base.
 */
void GTSNEGO_MSG_Teardown(u8 *p)
{
    int i;
    void *t;
    for(i=0;i<6;i++) {
        if(*(void **)(p+i*4+0x14c)) {
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x14c),0);
            CLACT_DeleteActor(*(void **)(p+i*4+0x14c));
            *(u32 *)(p+i*4+0x14c)=0;
        }
    }
    GTSNEGO_MSG_DeleteCursorActor(p);
    GTSNEGO_MSG_DeleteTileHandle(p);
    GTSNEGO_MSG_DeleteIdleActors((char *)p);
    GTSNEGO_MSG_DeleteIconActors(p);
    GTSNEGO_MSG_DeleteActors(p);
    t=func_020490F4((u32)((void *)144),((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,12,0,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,18,4,0,(u16)(((struct GtsnegoMsgCtx *)p)->f0),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_UTIL_UploadPaletteFromHandle(t,2,5,0,0x100,0x100,((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_DISP_CreateTouchbar(p,0);
    func_02040588(2,0);
    func_02041B6C(0);
    func_02040588(3,0);
    ((struct GtsnegoMsgCtx *)p)->f110=0;
    ((struct GtsnegoMsgCtx *)p)->f114=0;
}


void GTSNEGO_MSG_DeleteButtons(u8 *p)
{
    if (((struct GtsnegoMsgCtx *)p)->f8) {
        BUTTON_MAN_Delete(((struct GtsnegoMsgCtx *)p)->f8);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->f8 = 0;
    }
}

/*
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 */
char *GTSNEGO_MSG_Create(u32 heap,u32 n)
{
    char *p=func_02030734(heap,0xd0,1,sGtsnegoMsgHeapName,0xa9);
    ((struct GtsnegoMsgCtx *)p)->fC8=heap;
    BMP_WIN_Init(((struct GtsnegoMsgCtx *)p)->fC8);
    GF_FONT_InitTextColor();
    ((struct GtsnegoMsgCtx *)p)->fA0=TCBL_Create(((struct GtsnegoMsgCtx *)p)->fC8,((struct GtsnegoMsgCtx *)p)->fC8,1,0);
    ((struct GtsnegoMsgCtx *)p)->fA4=(void *)PRINTSYS_QUE_Create((void *)(u32)((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f1C=STRBUF_Create(240,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f18=STRBUF_Create(240,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f20=STRBUF_Create(240,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f14=GF_FONT_Create(23,0,0,0,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fC=func_02045B38(0,2,(u16)n,(u16)(((struct GtsnegoMsgCtx *)p)->fC8));
    ((struct GtsnegoMsgCtx *)p)->f10=WORDSET_Create(6,64,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fC0=APP_TASKMENU_RES_Create(5,9,*(u32 *)&((struct GtsnegoMsgCtx *)p)->f14,*(u32 *)&((struct GtsnegoMsgCtx *)p)->fA4,((struct GtsnegoMsgCtx *)p)->fC8);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f4=BMP_MENUWORK_LoadFrameGfx((void *)1,12,0,((struct GtsnegoMsgCtx *)p)->fC8);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f0=BMP_MENUWORK_LoadFrameGfx((void *)6,12,0,((struct GtsnegoMsgCtx *)p)->fC8);
    func_02049B40(23,5,4,0x160,32,((struct GtsnegoMsgCtx *)p)->fC8);
    func_02049B40(23,5,0,0x160,32,((struct GtsnegoMsgCtx *)p)->fC8);
    return p;
}

void GTSNEGO_MSG_Main(struct GtsnegoMsgCtx *p)
{
    GF_FONT_SetTextColor(1, 2, 15);
    TCBL_Main(p->fA0);
    PRINTSYS_QUE_Main(p->fA4);
    if (p->fC4) APP_TASKMENU_WIN_Update(p->fC4);
    if (p->fCC) PMS_DRAW_Main(p->fCC);
}

static inline u16 decodeHighHalfword(u32 value)
{
    u32 n=value >> 16;
    return (u16)n;
}

/*
 * trailing: two zero alignment bytes at 0x021D79F2.
 * lever: decode the high halfword, retain u16 payload arguments, remove
 * the p+16 address temporary and declare every Thumb callee explicitly.
 */
void GTSNEGO_MSG_Delete(char *p)
{
    int i;
    u32 t;
    t=((struct GtsnegoMsgCtx *)p)->f4;
    BG_SYS_DeleteHalf(1,(u16)t,decodeHighHalfword(t));
    t=((struct GtsnegoMsgCtx *)p)->f0;
    BG_SYS_DeleteHalf(6,(u16)t,decodeHighHalfword(t));
    GTSNEGO_MSG_DeleteButtons((u8 *)p);
    GF_FONT_SetDefaultTextColor();
    MSGDATA_Delete(((struct GtsnegoMsgCtx *)p)->fC);
    GF_FONT_Delete(((struct GtsnegoMsgCtx *)p)->f14);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->f18);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->f1C);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->f20);
    GTSNEGO_MSG_DeleteDraw((u8 *)p);
    if(((struct GtsnegoMsgCtx *)p)->f9C) {PRINTSYS_PrintStreamDelete(((struct GtsnegoMsgCtx *)p)->f9C);((struct GtsnegoMsgCtx *)p)->f9C=0;}
    WORDSET_DeleteStrbufED04(((struct GtsnegoMsgCtx *)p)->f10);
    if(((struct GtsnegoMsgCtx *)p)->fC4) {APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)p)->fC4);((struct GtsnegoMsgCtx *)p)->fC4=0;}
    APP_TASKMENU_RES_Delete(((struct GtsnegoMsgCtx *)p)->fC0);
    TCBL_Destroy(((struct GtsnegoMsgCtx *)p)->fA0);
    PRINTSYS_QUE_Clear(((struct GtsnegoMsgCtx *)p)->fA4);
    PRINTSYS_QUE_Delete(((struct GtsnegoMsgCtx *)p)->fA4);
    if(((struct GtsnegoMsgCtx *)p)->f30) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f30);
    if(((struct GtsnegoMsgCtx *)p)->f84) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f84);
    if(((struct GtsnegoMsgCtx *)p)->f98) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f98);
    if(((struct GtsnegoMsgCtx *)p)->f90) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f90);
    if(((struct GtsnegoMsgCtx *)p)->f8C) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f8C);
    if(((struct GtsnegoMsgCtx *)p)->f94) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f94);
    if(((struct GtsnegoMsgCtx *)p)->f88) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f88);
    if(((struct GtsnegoMsgCtx *)p)->f34) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f34);
    if(((struct GtsnegoMsgCtx *)p)->f68) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f68);
    for(i=0;i<12;i++) if(*(void **)(p+i*4+0x38)) BMP_WIN_Delete(*(void **)(p+i*4+0x38));
    for(i=0;i<6;i++) if(*(void **)(p+i*4+0x6c)) BMP_WIN_Delete(*(void **)(p+i*4+0x6c));
    BMP_WIN_Exit();
    func_020307B0(p);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *p,u16 n)
{
    void *q;
    func_02045CAC(p->fC,n,(void *)(*(int *)&p->f1C));
    if (!p->f30) p->f30=(void *)BMP_WIN_Create(1,1,19,30,4,11,1);
    q=p->f30;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,(void *)(*(int *)&p->f1C),(void *)(*(int *)&p->f14));
    BMP_MENUWORK_DrawWindow(q,1,(u16)(p->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}

void GTSNEGO_MSG_PrintWindowB(u8 *p, int n)
{
    void *q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18));
    if (!((struct GtsnegoMsgCtx *)p)->f30) ((struct GtsnegoMsgCtx *)p)->f30=(void *)BMP_WIN_Create(1,1,21,30,2,11,1);
    q=((struct GtsnegoMsgCtx *)p)->f30;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18),(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
    BMP_MENUWORK_DrawWindow(q,1,(u16)(((struct GtsnegoMsgCtx *)p)->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}

/*
 * follower: two zero padding bytes at 021D7B36.
 */
int GTSNEGO_MSG_UpdatePrintStream(struct GtsnegoMsgCtx *p)
{
    if (p->f9C) {
        switch (PRINTSYS_PrintStreamGetState(p->f9C)) {
        case 2: PRINTSYS_PrintStreamDelete(p->f9C); p->f9C=0; break;
        case 1: if (KEY_GetTrg()==1) PRINTSYS_PrintStreamReleasePause(p->f9C); break;
        }
        return 0;
    }
    return 1;
}

void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *p) { if(p->f30) { BMP_MENUWORK_DrawWindowBorder(p->f30,2); BMP_WIN_ClearScreen(p->f30); func_02041B6C(1); BMP_WIN_Delete(p->f30); p->f30=0; } }

void *GTSNEGO_MSG_OpenMenu(char *p,int n)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)p)->fC8;
    config.count=2;
    config.entries=p+0xa8;
    switch(n) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,25,text);
    ((struct GtsnegoMsgCtx *)p)->fAC=0x39e0;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fB4=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,26,text);
    ((struct GtsnegoMsgCtx *)p)->fB8=0x39e0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&config),((struct GtsnegoMsgCtx *)p)->fC0);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->fA8);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->fB4);
    return result;
}

int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *p) { return BUTTON_MAN_UpdateSlots(p->f8); }

void GTSNEGO_MSG_DeleteRows(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(((struct GtsnegoMsgCtx *)q)->f38) { BMP_WIN_Delete(((struct GtsnegoMsgCtx *)q)->f38); ((struct GtsnegoMsgCtx *)q)->f38=0; } } GF_FONT_SetTextColor(1,2,0); }

int GTSNEGO_MSG_CreateRow(u8 *p, int n, int a, int b, int c, int d)
{
    int i;
    void *q;
    for(i=0;i<12;i++) {
        if(!*(void **)(p+i*4+0x38)) {
            ((void **)(p+0x38))[i]=(void *)BMP_WIN_Create((u8)d,(u8)a,(u8)b,(u8)c,2,11,1);
            q=((void **)(p+0x38))[i];
            BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)q),0);
            func_02045CAC(*(struct MsgBank **)(p+0xc),n,*(void **)(p+0x18));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)q),2,2,*(void **)(p+0x18),*(void **)(p+0x14));
            BMP_WIN_TransferChars((struct Descriptor *)q);
            BMP_WIN_MakeScreen((struct Cfg *)q);
            return i;
        }
    }
    return 0;
}


int GTSNEGO_MSG_CreateRowEx(int a, int b, int c, int d)
{
    return GTSNEGO_MSG_CreateRow((u8 *)a, b, c, d, 0x14, 6);
}

/*
 * follower: two zero padding bytes at 021D7D2E.
 */
void GTSNEGO_MSG_RedrawRow(char *p,u16 n,int i)
{
    void *q=*(void **)(p+0x38+4*i);
    if(q) {
        BMP_Clear(BMP_WIN_GetBmp(q),0);
        func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18));
        PRINTSYS_Print(BMP_WIN_GetBmp(q),2,2,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18),(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
        BMP_WIN_TransferChars(q);
    }
}

void GTSNEGO_MSG_FlushRowLayer(char *a0) { func_02041B6C(6); }

void GTSNEGO_MSG_ClearRows(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(((struct GtsnegoMsgCtx *)q)->f38) { func_02041B6C(BMP_WIN_GetBgLayer(((struct GtsnegoMsgCtx *)q)->f38)); BMP_MENUWORK_DrawWindowBorder(((struct GtsnegoMsgCtx *)q)->f38,2); BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)q)->f38); } } }

void GTSNEGO_MSG_CreateYesNoUi(char *p,int a,int b)
{
    GTSNEGO_MSG_DeleteRows(p);
    GTSNEGO_MSG_CreateRow((unsigned char *)p,0,8,7,16,6);
    GTSNEGO_MSG_CreateRow((unsigned char *)p,1,8,13,16,6);
    GTSNEGO_MSG_FlushRowLayer(p);
    GTSNEGO_MSG_DeleteButtons((unsigned char *)p);
    ((struct GtsnegoMsgCtx *)p)->f8=BUTTON_MAN_Create((u8 *)gGtsnegoButtonYesNo,a,b,((struct GtsnegoMsgCtx *)p)->fC8);
}

/*
 * follower: existing 021D7E88, 021D7E9C, 021D7EB0 files remain separate.
 */
void GTSNEGO_MSG_CreateListUi(char *p,int a,int b,int c,int d,int e)
{
    GTSNEGO_MSG_DeleteRows(p);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx((int)p,2,0,0);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx((int)p,3,3,6);
    GTSNEGO_MSG_CreateRowEx((int)p,23,1,11);
    GTSNEGO_MSG_CreateRowEx((int)p,24,1,16);
    GF_FONT_SetTextColor(1,2,0);
    *(int *)&((struct GtsnegoMsgCtx *)p)->f24=GTSNEGO_MSG_CreateRowEx((int)p,gGtsnegoRowLabelA[c],13,6);
    *(int *)&((struct GtsnegoMsgCtx *)p)->f28=GTSNEGO_MSG_CreateRowEx((int)p,gGtsnegoRowLabelB[d],16,11);
    *(int *)&((struct GtsnegoMsgCtx *)p)->f2C=GTSNEGO_MSG_CreateRowEx((int)p,gGtsnegoRowLabelB[e],16,16);
    GTSNEGO_MSG_FlushRowLayer(p);
    GTSNEGO_MSG_DeleteButtons((unsigned char *)p);
    ((struct GtsnegoMsgCtx *)p)->f8=BUTTON_MAN_Create((u8 *)gGtsnegoButtonList,a,b,((struct GtsnegoMsgCtx *)p)->fC8);
}

/*
 * follower: separately filed 021D7E9C.
 */
void GTSNEGO_MSG_RedrawRowA(char *p,int i) {GTSNEGO_MSG_RedrawRow(p,gGtsnegoRowLabelA[i],*(int *)&((struct GtsnegoMsgCtx *)p)->f24);}

/*
 * follower: separately filed 021D7EB0.
 */
void GTSNEGO_MSG_RedrawRowB(char *p,int i) {GTSNEGO_MSG_RedrawRow(p,gGtsnegoRowLabelB[i],*(int *)&((struct GtsnegoMsgCtx *)p)->f28);}

void GTSNEGO_MSG_RedrawRowC(char *p,int i) {GTSNEGO_MSG_RedrawRow(p,gGtsnegoRowLabelB[i],*(int *)&((struct GtsnegoMsgCtx *)p)->f2C);}

void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p) { GTSNEGO_MSG_DeleteButtons(p); }

void *GTSNEGO_MSG_CreateTooltip(char *p,u16 n)
{
    int width;
    void *result;
    void *text;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,text);
    ((struct GtsnegoMsgCtx *)p)->fAC=0x39e3;
    ((struct GtsnegoMsgCtx *)p)->fB0=0;
    width=((int)func_0201D304(((struct GtsnegoMsgCtx *)p)->fA8,(int)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14),(int)0)+32)/16;
    result=APP_TASKMENU_WIN_CreateEx((u32)(((struct GtsnegoMsgCtx *)p)->fC0),(u32)(p+0xa8),(u8)(16-width),(u8)21,width*2,3,(int)0,(int)1,((struct GtsnegoMsgCtx *)p)->fC8);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->fA8);
    return result;
}

void GTSNEGO_MSG_PrintTooltip(char *p,u16 n)
{
    void *q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18));
    if(!((struct GtsnegoMsgCtx *)p)->f94) ((struct GtsnegoMsgCtx *)p)->f94=(void *)BMP_WIN_Create(1,1,13,14,3,4,1);
    q=((struct GtsnegoMsgCtx *)p)->f94;
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),2,3,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18),(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
}

/*
 * follower: two zero padding bytes at 021D80D2.
 */
void GTSNEGO_MSG_PrintEntry(char *p,void *r)
{
    u32 a,b,c,d;
    void *q;
    a=func_0200856C(r);
    b=func_02008570(r);
    c=func_02025C1C(a,b,func_02008564(r));
    d=func_02025C30(a,b,func_02008564(r));
    if(a==c && b==d) {
        WORDSET_SetSlotFromMsgE7(((struct GtsnegoMsgCtx *)p)->f10,0,func_0200856C(r));
        a=func_0200856C(r);
        WORDSET_DeleteMsgdataF094(((struct GtsnegoMsgCtx *)p)->f10,1,a,func_02008570(r));
    } else {
        WORDSET_SetSlotFromMsgE7(((struct GtsnegoMsgCtx *)p)->f10,0,0);
        WORDSET_DeleteMsgdataF094(((struct GtsnegoMsgCtx *)p)->f10,1,0,0);
    }
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,34,((struct GtsnegoMsgCtx *)p)->f20);
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f20);
    if(!((struct GtsnegoMsgCtx *)p)->f84) ((struct GtsnegoMsgCtx *)p)->f84=(void *)BMP_WIN_Create(1,1,15,30,5,11,1);
    q=((struct GtsnegoMsgCtx *)p)->f84;
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),5,5,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f14);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}

/*
 * follower: two zero padding bytes at 021D8116.
 */
void GTSNEGO_MSG_DeleteEntryWindow(struct GtsnegoMsgCtx *p)
{
    if (p->f84) {
        BMP_Clear(BMP_WIN_GetBmp(p->f84),0);
        BMP_WIN_TransferChars(p->f84);
        BMP_WIN_ClearScreen(p->f84);
        func_02041B6C(1);
        BMP_WIN_Delete(p->f84);
        p->f84=0;
    }
}

int GTSNEGO_MSG_PrintListEntry(char *p, void *r, int n)
{
    void **t=(void **)(p+0x6c);
    void *q;
    if(!t[n]) t[n]=(void *)BMP_WIN_Create((u8)6,(u8)6,(u8)(n*6+1),(u8)24,4,11,1);
    q=t[n];
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    STRBUF_Clear(*(void **)(p+0x20));
    STRBUF_Clear(*(void **)(p+0x18));
    WORDSET_SetSlotMyStatus(*(void **)(p+0x10),0,r);
    WORDSET_SetSlotNumber(*(void **)(p+0x10),1,func_02008534(r),5,2,1);
    WORDSET_SetSlotFromMsgE7(*(void **)(p+0x10),2,func_0200856C(r));
    func_02045CAC(*(void **)(p+0xc),28,*(void **)(p+0x20));
    WORDSET_CopyTaggedText(*(void **)(p+0x10),*(void **)(p+0x18),*(void **)(p+0x20));
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,*(void **)(p+0x18),*(void **)(p+0x14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    return 0;
}

void GTSNEGO_MSG_PrintList(char *p,void *q)
{
    int i;
    void *r;
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRow((u8 *)p,30,0,0,20,5);
    for(i=0;i<3;i++) {
        r=GTSNEGO_DISP_GetEntry(q,i);
        if(r) GTSNEGO_MSG_PrintListEntry(p,r,i+2);
    }
    func_02041B6C(5);
}

void GTSNEGO_MSG_PrintListEntryAt(char *p,void *q,int index) { GTSNEGO_MSG_PrintListEntry(p,GTSNEGO_DISP_GetEntry(q,index),5); func_02041B6C(6); }

void GTSNEGO_MSG_ShiftListDown(char *p)
{
    int i;
    char *t;
    if(((struct GtsnegoMsgCtx *)p)->f6C) {BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f6C);((struct GtsnegoMsgCtx *)p)->f6C=0;}
    for(i=1;i<6;i++) {
        t=p+4*i;
        if(((struct GtsnegoMsgCtx *)t)->f6C) {
            BMP_WIN_SetPosY(((struct GtsnegoMsgCtx *)t)->f6C,BMP_WIN_GetPosY(((struct GtsnegoMsgCtx *)t)->f6C)-6);
            BMP_WIN_MakeScreen(((struct GtsnegoMsgCtx *)t)->f6C);
        }
    }
    func_02041B6C(6);
    for(i=0;i<5;i++) *(void **)(p+0x6c+4*i)=*(void **)(p+0x70+4*i);
    ((struct GtsnegoMsgCtx *)p)->f80=0;
}

void GTSNEGO_MSG_PrintListRange(char *p,void *q,int start) { int i; void *r; for(i=0;i<6;i++) { if((int)((u32)i+(u32)start)>=0) { r=GTSNEGO_DISP_GetEntry(q,(int)((u32)i+(u32)start)); if(r) GTSNEGO_MSG_PrintListEntry(p,r,i); } } func_02041B6C(6); }

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void GTSNEGO_MSG_PrintListEntryN(char *p,void *q,int n)
{
    GTSNEGO_MSG_PrintListEntry(p,GTSNEGO_DISP_GetEntry(q,n),0);
    func_02041B6C(6);
}

void GTSNEGO_MSG_ShiftListUp(char *p)
{
    int i;
    char *t;
    if(((struct GtsnegoMsgCtx *)p)->f80) {BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f80);((struct GtsnegoMsgCtx *)p)->f80=0;}
    for(i=0;i<6;i++) {
        t=p+4*i;
        if(((struct GtsnegoMsgCtx *)t)->f6C) {
            BMP_WIN_SetPosY(((struct GtsnegoMsgCtx *)t)->f6C,BMP_WIN_GetPosY(((struct GtsnegoMsgCtx *)t)->f6C)+6);
            BMP_WIN_MakeScreen(((struct GtsnegoMsgCtx *)t)->f6C);
        }
    }
    func_02041B6C(6);
    for(i=5;i>0;i--) *(void **)(p+0x6c+4*i)=*(void **)(p+0x68+4*i);
    ((struct GtsnegoMsgCtx *)p)->f6C=0;
}

void *GTSNEGO_MSG_OpenMenuB(char *p,int n)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)p)->fC8;
    config.count=2;
    config.entries=p+0xa8;
    switch(n) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,27,text);
    ((struct GtsnegoMsgCtx *)p)->fAC=0x39e0;
    ((struct GtsnegoMsgCtx *)p)->fB0=0;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fB4=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,33,text);
    ((struct GtsnegoMsgCtx *)p)->fB8=0x39e0;
    *(int *)&((struct GtsnegoMsgCtx *)p)->fBC=0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&config),((struct GtsnegoMsgCtx *)p)->fC0);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->fA8);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->fB4);
    return result;
}


void GTSNEGO_MSG_CloseMenu(int a)
{
    if (a != 0) {
        *(volatile u16 *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu((struct TaskMenu *)a);
    }
}

void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *p,void *q)
{
    if(!p->fCC)
        p->fCC=PMS_DRAW_Create(GTSNEGO_DISP_GetUnit(q),0,(u32)(p->fA4),(u32)(p->f14),8,4,p->fC8);
}


void GTSNEGO_MSG_DeleteDraw(u8 *p)
{
    if (((struct GtsnegoMsgCtx *)p)->fCC) {
        PMS_DRAW_Delete(((struct GtsnegoMsgCtx *)p)->fCC);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->fCC = 0;
    }
}

void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *p, void *n)
{
    Pair c = gGtsnegoMsgDrawConfig;
    void *q;
    if (!p->f88) p->f88 = (void *)BMP_WIN_Create(1, 1, 15, 30, 5, 11, 1);
    q = p->f88;
    BMP_Clear(BMP_WIN_GetBmp(q), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PMS_DRAW_SetNullColorPalette(p->fCC, 0);
    PMS_DRAW_SetPrintColor(p->fCC, 0x3c40);
    PMS_DRAW_PrintOffset(p->fCC, (u32)q, n, 0, (u32)(&c));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}

void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *p, u16 n)
{
    void *q;
    func_02045CAC(p->fC, n, (void *)(*(int *)&p->f18));
    if (!p->f68) p->f68 = (void *)BMP_WIN_Create(1, 0, 0, 14, 2, 11, 1);
    q = p->f68;
    BMP_Clear(BMP_WIN_GetBmp(q), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q), 2, 2, (void *)(*(int *)&p->f18), (void *)(*(int *)&p->f14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}

void GTSNEGO_MSG_CreateConfirmUi(u8 *p, int a, int b)
{
    void *q = STRBUF_Create(100, ((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8 = q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC, 15, q);
    ((struct GtsnegoMsgCtx *)p)->fAC = 0x39e3;
    ((struct GtsnegoMsgCtx *)p)->fB0 = 0;
    ((struct GtsnegoMsgCtx *)p)->fC4 = APP_TASKMENU_WIN_CreateEx((u32)(((struct GtsnegoMsgCtx *)p)->fC0), (u32)(p + 0xa8), 10, 21, 12, 3, 0, 1, ((struct GtsnegoMsgCtx *)p)->fC8);
    if (!func_020355C4()) APP_TASKMENU_WIN_SetActive(((struct GtsnegoMsgCtx *)p)->fC4, 1);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)p)->fA8);
    GTSNEGO_MSG_DeleteButtons(p);
    ((struct GtsnegoMsgCtx *)p)->f8 = BUTTON_MAN_Create((u8 *)gGtsnegoButtonConfirm, a, b, ((struct GtsnegoMsgCtx *)p)->fC8);
}


void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *p)
{
    APP_TASKMENU_WIN_SetDecide(p->fC4, 1);
}


void GTSNEGO_MSG_DeleteConfirmWindow(u8 *p)
{
    APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)p)->fC4);
    func_02041B6C(5);
    *(u32 *)&((struct GtsnegoMsgCtx *)p)->fC4 = 0;
}

int GTSNEGO_MSG_IsConfirmFinished(u8 *p)
{
    if(APP_TASKMENU_WIN_IsFinish(((struct GtsnegoMsgCtx *)p)->fC4)){
        GTSNEGO_MSG_DeleteConfirmWindow((u8 *)((int)p));
        return 1;
    }
    return 0;
}

void GTSNEGO_MSG_PrintPair(char *p,int unused,u32 n)
{
    void *q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,40,((struct GtsnegoMsgCtx *)p)->f18);
    if(!((struct GtsnegoMsgCtx *)p)->f8C) ((struct GtsnegoMsgCtx *)p)->f8C=(void *)BMP_WIN_Create(1,21,4,10,2,4,1);
    q=((struct GtsnegoMsgCtx *)p)->f8C;
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,3,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f14);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    WORDSET_SetSlotNumber(((struct GtsnegoMsgCtx *)p)->f10,0,n,5,1,1);
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,36,((struct GtsnegoMsgCtx *)p)->f20);
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f20);
    if(!((struct GtsnegoMsgCtx *)p)->f90) ((struct GtsnegoMsgCtx *)p)->f90=(void *)BMP_WIN_Create(1,21,6,10,3,11,1);
    q=((struct GtsnegoMsgCtx *)p)->f90;
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,5,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f14);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
}

void GTSNEGO_MSG_PrintSingle(char *p, void *n)
{
    void *q;
    WORDSET_SetSlotMyStatus(((struct GtsnegoMsgCtx *)p)->f10, 0, n);
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC, 37, (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f20));
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)p)->f10, (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18), (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f20));
    if (!((struct GtsnegoMsgCtx *)p)->f98) ((struct GtsnegoMsgCtx *)p)->f98 = (void *)BMP_WIN_Create(1, 11, 10, 10, 3, 11, 1);
    q = ((struct GtsnegoMsgCtx *)p)->f98;
    BMP_Clear(BMP_WIN_GetBmp(q), 0);
    GF_FONT_SetTextColor(1, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q), 0, 0, (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18), (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
}

void GTSNEGO_MSG_PrintSummary(char *p,void *q,u32 n)
{
    GTSNEGO_MSG_PrintSingle(p,(void *)q);
    GTSNEGO_MSG_PrintPair(p,36,n);
    GTSNEGO_MSG_PrintTooltip(p,41);
    GTSNEGO_MSG_PrintEntry(p,q);
    GTSNEGO_MSG_PrintWindowB((u8 *)p,17);
}


void GTSNEGO_MSG_DeleteAll(char *p)
{
    int i;

    if (((struct GtsnegoMsgCtx *)p)->f68 != 0) {
        BMP_MENUWORK_DrawWindowBorder(((struct GtsnegoMsgCtx *)p)->f68, 2);
        BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)p)->f68);
        func_02041B6C(1);
        BMP_WIN_Delete(((struct GtsnegoMsgCtx *)p)->f68);
        ((struct GtsnegoMsgCtx *)p)->f68 = 0;
    }
    if (((struct GtsnegoMsgCtx *)p)->fC4 != 0) {
        APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)p)->fC4);
        ((struct GtsnegoMsgCtx *)p)->fC4 = 0;
    }
    for (i = 0; i < 6; i++) {
        char *q = p + i * 4;

        if (((struct GtsnegoMsgCtx *)q)->f6C != 0) {
            BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)q)->f6C);
            BMP_WIN_Delete(((struct GtsnegoMsgCtx *)q)->f6C);
            ((struct GtsnegoMsgCtx *)q)->f6C = 0;
        }
    }
    GTSNEGO_MSG_ClearRows(p);
    GTSNEGO_MSG_DeleteRows(p);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, ((struct GtsnegoMsgCtx *)p)->fC8);
    func_02041B6C(5);
}
