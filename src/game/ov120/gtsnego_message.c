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
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BG_SYS_SetupTileScreen 0x02042FB0 arm
 *   GTSNEGO_DISP_GetEntry 0x021D4F70 thumb ov120
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   gGtsnegoIconX 0x021D892C data a2
 *   gGtsnegoIconY 0x021D8924 data a2
 *   gGtsnegoIconZ 0x021D893C data a2
 *   gGtsnegoIconW 0x021D8934 data a2
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   MYSTATUS_GetTrainerView 0x02008554 thumb
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fgeq 0x0209BB54 arm
 *   _ffix 0x0209C494 arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   gGtsnegoIdleAnimTable 0x021D8AB0 data a4
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   sGtsnegoMsgHeapName 0x021D8BEC data a1
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   MSGDATA_ReadString 0x02045CAC arm
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
 *   UI_GetInputMode 0x020355C4 arm
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
 *   WORDSET_SetSlotFromKeyedMessage  0x0201F094  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb  arm9
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb  arm9
 *   MYSTATUS_GetIdLow16  0x02008534  thumb  arm9
 *   MYSTATUS_GetLanguage  0x02008564  thumb  arm9
 *   MYSTATUS_GetNation  0x0200856C  thumb  arm9
 *   MYSTATUS_GetArea  0x02008570  thumb  arm9
 *   NATION_AREA_SanitizeNation  0x02025C1C  thumb  arm9
 *   NATION_AREA_SanitizeArea  0x02025C30  thumb  arm9
 */
#include "ov120_types.h"

struct Obj;
struct Actor;
struct Vec2;
struct Sub0200852CObj;
struct PtS;
struct Cmd;
struct GfFont;
struct TaskMenuRes;
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
#include "../types.h"

typedef struct PosRecord {u16 x,y,z;u8 a,b;} PosRecord;

typedef struct GtsnegoMessageTriple { u16 a[3]; } GtsnegoMessageTriple;

typedef struct { s16 x, y; } GtsnegoMessageVec;

typedef struct GtsnegoMessagePt { s16 x,y; } GtsnegoMessagePt;

typedef struct GtsnegoMessageTable { u32 a[16]; } GtsnegoMessageTable;

typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;

typedef struct { int a, b; } GtsnegoMessagePair;

#include "../arm9/clact.h"
#include "gtsnego_disp.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/bg_sys.h"
struct MyStatus;
#include "../arm9/mystatus.h"
struct ButtonMan;
#include "../arm9/button_man.h"
#include "../arm9/bmp_win.h"
#include "../arm9/gf_font.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/msgdata.h"
#include "../arm9/wordset.h"
struct GFont;
#include "../arm9/app_taskmenu.h"
#include "../arm9/bmp_menuwork.h"
struct TaskMenuWin;
#include "../arm9/pms_draw.h"
struct TextPrinter;
struct BmpWin;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/key.h"
struct TaskMenuInitWork;
struct TaskMenuWork;
struct TaskMenuItem;
#include "../arm9/bmp_oam.h"
struct GtsnegoActorSys;
#include "../arm9/ui.h"
#include "../sdk_ioreg.h"
int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoActorSys *p,u32 n);
int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_CreateActorAt(struct GtsnegoActorSys *p,u16 x,u16 y,int flag);
void GTSNEGO_MSG_DeleteActors(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_SetActorMode(struct GtsnegoActorSys *p,u32 n);
void GTSNEGO_MSG_InitWindows(struct GtsnegoActorSys *p, int n);
void GTSNEGO_MSG_DeleteTileHandle(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_DrawTileRow(struct GtsnegoActorSys *p, int n);
void GTSNEGO_MSG_FillTileRow(struct GtsnegoActorSys *p, int n);
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoActorSys *p,void *list,int first);
void GTSNEGO_MSG_TeardownActorList(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_TeardownTileRows(struct GtsnegoActorSys *p);
int GTSNEGO_MSG_CursorDown(void *unused,int *p);
int GTSNEGO_MSG_CursorUp(void *unused,int *p);
void GTSNEGO_MSG_SetCursorIndex(void *unused, int *p, int n);
void GTSNEGO_MSG_CreateCursorActor(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_DeleteCursorActor(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_CreateIconActors(struct GtsnegoActorSys *p,int flag);
void GTSNEGO_MSG_DeleteIconActors(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoActorSys *p, u32 flag);
void GTSNEGO_MSG_SetScrollState(struct GtsnegoActorSys *p, int state);
void GTSNEGO_MSG_ClearScrollState(struct GtsnegoActorSys *p);
int GTSNEGO_MSG_StepScroll(struct GtsnegoActorSys *p, int *out);
void GTSNEGO_MSG_ScrollAllRows(struct GtsnegoActorSys *p, int flag);
void GTSNEGO_MSG_SetupRowBg(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_CreateListActor(struct GtsnegoActorSys *p, int n, int k);
void GTSNEGO_MSG_SetListActorPos(struct GtsnegoActorSys *p, int index, int x, int y);
void GTSNEGO_MSG_SetListEntry(struct GtsnegoActorSys *p, void *entry, int index);
void GTSNEGO_MSG_MoveListActor(struct GtsnegoActorSys *p, int index, int delta);
void GTSNEGO_MSG_ScrollListDown(struct GtsnegoActorSys *p, void *q);
void GTSNEGO_MSG_ScrollListUp(struct GtsnegoActorSys *p, void *q);
void GTSNEGO_MSG_FillListRange(struct GtsnegoActorSys *p, void *container, int offset);
int GTSNEGO_MSG_GetListRowY(struct GtsnegoActorSys *p, int index, int count);
int GTSNEGO_MSG_GetListRowYF(struct GtsnegoActorSys *p, int n, int count);
void GTSNEGO_MSG_SetIconY(struct GtsnegoActorSys *p, int index, int count);
int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoActorSys *p,int y,int count);
void GTSNEGO_MSG_CycleIdleAnim(void *actorSys, u32 frame);
void GTSNEGO_MSG_CreateIdleActors(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_DeleteIdleActors(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoActorSys *p,int n);
void GTSNEGO_MSG_CreateIdleUi(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_StepIdleFade(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_Teardown(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_DeleteButtons(struct GtsnegoMsgCtx *p);
struct GtsnegoMsgCtx *GTSNEGO_MSG_Create(u32 heap,u32 n);
void GTSNEGO_MSG_Main(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_Delete(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *p,u16 n);
void GTSNEGO_MSG_PrintWindowB(struct GtsnegoMsgCtx *p, int n);
int GTSNEGO_MSG_UpdatePrintStream(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *p);
void *GTSNEGO_MSG_OpenMenu(struct GtsnegoMsgCtx *p,int n);
int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_DeleteRows(struct GtsnegoMsgCtx *p);
int GTSNEGO_MSG_CreateRow(struct GtsnegoMsgCtx *p, int n, int a, int b, int c, int d);
int GTSNEGO_MSG_CreateRowEx(struct GtsnegoMsgCtx *a, int b, int c, int d);
void GTSNEGO_MSG_RedrawRow(struct GtsnegoMsgCtx *p,u16 n,int i);
void GTSNEGO_MSG_FlushRowLayer(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_ClearRows(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_CreateYesNoUi(struct GtsnegoMsgCtx *p,void (*a)(u32, s32, void *),void *b);
void GTSNEGO_MSG_CreateListUi(struct GtsnegoMsgCtx *p,void (*a)(u32, s32, void *),void *b,int c,int d,int e);
void GTSNEGO_MSG_RedrawRowA(struct GtsnegoMsgCtx *p,int i);
void GTSNEGO_MSG_RedrawRowB(struct GtsnegoMsgCtx *p,int i);
void GTSNEGO_MSG_RedrawRowC(struct GtsnegoMsgCtx *p,int i);
void GTSNEGO_MSG_DeleteButtonsKeep(struct GtsnegoMsgCtx *p);
void *GTSNEGO_MSG_CreateTooltip(struct GtsnegoMsgCtx *p,u16 n);
void GTSNEGO_MSG_PrintTooltip(struct GtsnegoMsgCtx *p,u16 n);
void GTSNEGO_MSG_PrintEntry(struct GtsnegoMsgCtx *p,void *r);
void GTSNEGO_MSG_DeleteEntryWindow(struct GtsnegoMsgCtx *p);
int GTSNEGO_MSG_PrintListEntry(struct GtsnegoMsgCtx *p, void *r, int n);
void GTSNEGO_MSG_PrintList(struct GtsnegoMsgCtx *p,void *q);
void GTSNEGO_MSG_PrintListEntryAt(struct GtsnegoMsgCtx *p,void *q,int index);
void GTSNEGO_MSG_ShiftListDown(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_PrintListRange(struct GtsnegoMsgCtx *p,void *q,int start);
void GTSNEGO_MSG_PrintListEntryN(struct GtsnegoMsgCtx *p,void *q,int n);
void GTSNEGO_MSG_ShiftListUp(struct GtsnegoMsgCtx *p);
void *GTSNEGO_MSG_OpenMenuB(struct GtsnegoMsgCtx *p,int n);
void GTSNEGO_MSG_CloseMenu(struct TaskMenuWork *a);
void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *p,struct GtsnegoActorSys *q);
void GTSNEGO_MSG_DeleteDraw(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *p, void *n);
void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *p, u16 n);
void GTSNEGO_MSG_CreateConfirmUi(struct GtsnegoMsgCtx *p, void (*a)(u32, s32, void *), void *b);
void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_DeleteConfirmWindow(struct GtsnegoMsgCtx *p);
int GTSNEGO_MSG_IsConfirmFinished(struct GtsnegoMsgCtx *p);
void GTSNEGO_MSG_PrintPair(struct GtsnegoMsgCtx *p,int unused,u32 n);
void GTSNEGO_MSG_PrintSingle(struct GtsnegoMsgCtx *p, void *n);
void GTSNEGO_MSG_PrintSummary(struct GtsnegoMsgCtx *p,void *q,u32 n);
extern const u8 gGtsnegoEntryTable[][4];
extern const GtsnegoMessageTriple gGtsnegoIconX,gGtsnegoIconY,gGtsnegoIconZ,gGtsnegoIconW;
extern const GtsnegoMessageTable gGtsnegoIdleAnimTable;
extern const char sGtsnegoMsgHeapName[];
extern const int gGtsnegoButtonYesNo[];
extern const u16 gGtsnegoRowLabelA[],gGtsnegoRowLabelB[];
extern const int gGtsnegoButtonList[];
extern const u16 gGtsnegoRowLabelA[];
extern const GtsnegoMessagePair gGtsnegoMsgDrawConfig;
extern const int gGtsnegoButtonConfirm[];

int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoActorSys *actorSys,u32 position){void *obj=actorSys->cursorActor;if(!obj)return 0;CLACT_SetActorAnimSeq(obj,gGtsnegoEntryTable[position][3]);return 1;}

int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoActorSys *actorSys){if(!actorSys->cursorActor)return 0;if((u32)CLACT_GetActorAnimSeq(actorSys->cursorActor)>=29){if(CLACT_IsActorAnimActive(actorSys->cursorActor)==0)return 1;return 0;}return 0;}

void GTSNEGO_MSG_CreateActorAt(struct GtsnegoActorSys *actorSys,u16 x,u16 y,int isRightSide) {
PosRecord actorPos;int i;
for(i=0;i<12;i++) {
if(!actorSys->slotActors[i]) {
actorPos.x=x;actorPos.y=y;actorPos.z=isRightSide?2:0;actorPos.a=0;actorPos.b=1;
actorSys->slotActors[i]=CLACT_CreateActor((struct Unit *)((void *)((struct GtsnegoActorSys *)actorSys)->clactUnit),((struct GtsnegoActorSys *)actorSys)->uiChar,((struct GtsnegoActorSys *)actorSys)->uiPalette,((struct GtsnegoActorSys *)actorSys)->uiCellAnim,(const struct ActorInitParam *)&actorPos,1,((struct GtsnegoActorSys *)actorSys)->heapId);
CLACT_SetActorAutoAnim(actorSys->slotActors[i],1);
CLACT_SetActorDrawEnable(actorSys->slotActors[i],1);
return;
}
}
}

/*
 * extent: two-byte zero alignment padding follows.
 * lever: base + index*4 + 0xc4 preserves the original add order.
 */
void GTSNEGO_MSG_DeleteActors(struct GtsnegoActorSys *actorSys){int i;for(i=0;i<12;i++){if(((struct GtsnegoActorSys *)actorSys)->slotActors[i]){CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->slotActors[i]);((struct GtsnegoActorSys *)actorSys)->slotActors[i]=0;}}}

void GTSNEGO_MSG_SetActorMode(struct GtsnegoActorSys *actorSys,u32 slot){
int got;int mode;got=CLACT_GetActorAnimSeq((*(void **)((u8 *)actorSys->slotActors + slot * (int)sizeof(void *))));mode=1;if(got>=2)mode=3;CLACT_SetActorAnimSeq((*(void **)((u8 *)actorSys->slotActors + slot * (int)sizeof(void *))),mode);CLACT_SetActorAutoAnim((*(void **)((u8 *)actorSys->slotActors + slot * (int)sizeof(void *))),1);
}

void GTSNEGO_MSG_InitWindows(struct GtsnegoActorSys *actorSys, int includeFirstIcon)
{
    void *arcHandle;
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys, 8);
    GTSNEGO_DISP_Noop(actorSys, 1);
    arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->tileScreenBuf = ARC_UTIL_LoadPaletteDataFromHandle(arcHandle, 21, 0, (void **)&((struct GtsnegoActorSys *)actorSys)->tileScreen, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle, 0, 5, 0, 320, 32, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    arcHandle = ARC_TOOL_CreateHandle(32, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle, 0, 5, 0, 0, 256, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_MSG_CreateCursorActor(actorSys);
    GTSNEGO_MSG_CreateIconActors(actorSys, includeFirstIcon);
    ((struct GtsnegoActorSys *)actorSys)->scrollDirty = 1;
}

/*
 * Addresses are Black-image addresses.
 */
void GTSNEGO_MSG_DeleteTileHandle(struct GtsnegoActorSys *actorSys)
{
    void *buf = ((struct GtsnegoActorSys *)actorSys)->tileScreenBuf;
    if (buf) {
        GFL_HEAP_Free(buf);
        ((struct GtsnegoActorSys *)actorSys)->tileScreenBuf = 0;
    }
}

void GTSNEGO_MSG_DrawTileRow(struct GtsnegoActorSys *actorSys, int row)
{
    u16 *tiles = (u16 *)(*(u8 * *)&actorSys->tileScreen + 0xc);
    int base = (u16)actorSys->bgCharLayer4;
    int off;
    int index = 0;
    int y, x;
    y = 0;
    off = 6 * row;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++, index++)
            BG_SYS_SetupTileScreen(4, x, y + off, base + tiles[index]);
}

void GTSNEGO_MSG_FillTileRow(struct GtsnegoActorSys *actorSys, int row)
{
    u8 *screen = *(u8 * *)&actorSys->tileScreen + 0xc;
    int base = (u16)actorSys->bgCharLayer4;
    int off;
    int x, y;
    y = 0;
    off = 6 * row;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++)
            BG_SYS_SetupTileScreen(4, x, y + off, ((struct GtsnegoTileScreen *)screen)->blankTile + base);
}

/*
 * extent: two-byte zero alignment padding follows.
 */
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoActorSys *actorSys,void *list,int first){int i;for(i=0;i<6;i++){if(GTSNEGO_DISP_GetEntry(list,first+i))GTSNEGO_MSG_DrawTileRow(actorSys,i);else GTSNEGO_MSG_FillTileRow(actorSys,i);}BG_SYS_MarkTileDirty(4);}

void GTSNEGO_MSG_TeardownActorList(struct GtsnegoActorSys *actorSys)
{
    void *arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    int i;
    for (i = 0; i < 6; i++) {
        if (((struct GtsnegoActorSys *)actorSys)->listActors[i]) {
            CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->listActors[i]);
            ((struct GtsnegoActorSys *)actorSys)->listActors[i] = 0;
        }
    }
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys, 0);
    GTSNEGO_MSG_DeleteCursorActor(actorSys);
    ARC_TOOL_DeleteHandle(arcHandle);
}

void GTSNEGO_MSG_TeardownTileRows(struct GtsnegoActorSys *actorSys)
{
    void *arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    GTSNEGO_MSG_DeleteTileHandle(actorSys);
    GTSNEGO_MSG_DeleteIconActors(actorSys);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 32, 32, 17);
    BG_SYS_MarkTileDirty(6);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle, 2, 5, 0, 256, 256, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle, 18, 4, 0, (u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4), 0, 0, ((struct GtsnegoActorSys *)actorSys)->heapId);
    BG_SYS_MarkTileDirty(4);
    ARC_TOOL_DeleteHandle(arcHandle);
}

/*
 * lever: name the p[2]+3 bound and reread p[2] for the increment;
 * retaining a named offset instead exchanges r3 and r4 (4-byte DIFF).
 */
int GTSNEGO_MSG_CursorDown(void *unused,int *listState){int idx=listState[1];int ret=0;if(idx<2 && idx<listState[0]-1){listState[1]=idx+1;return 1;}else if(idx==2){int bound=listState[2]+3;if(bound<listState[0]){listState[2]=listState[2]+1;ret=2;}}return ret;}

int GTSNEGO_MSG_CursorUp(void *unused,int *listState){int idx=listState[1];int ret=0;if(idx>0){listState[1]=idx-1;return 1;}else if(idx==0 && listState[2]!=0){listState[2]=listState[2]-1;ret=2;}return ret;}

void GTSNEGO_MSG_SetCursorIndex(void *unused, int *listState, int index)
{
    if(index<(u32)listState[0])listState[1]=index;
    if(listState[1]>2)listState[1]=2;
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D6ED6.
 */
void GTSNEGO_MSG_CreateCursorActor(struct GtsnegoActorSys *actorSys)
{
    PosRecord actorPos;
    actorPos.x = 128; actorPos.y = 200; actorPos.z = 0; actorPos.a = 1; actorPos.b = 1;
    ((struct GtsnegoActorSys *)actorSys)->selectorActor = CLACT_CreateActor((struct Unit *)(*(void **)&((struct GtsnegoActorSys *)actorSys)->clactUnit), ((struct GtsnegoActorSys *)actorSys)->cursorChar, ((struct GtsnegoActorSys *)actorSys)->cursorPalette, ((struct GtsnegoActorSys *)actorSys)->cursorCellAnim, (const struct ActorInitParam *)&actorPos, 1, ((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->selectorActor, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->selectorActor, 1);
}

void GTSNEGO_MSG_DeleteCursorActor(struct GtsnegoActorSys *actorSys)
{
    void *actor = ((struct GtsnegoActorSys *)actorSys)->selectorActor;
    if (actor)
        CLACT_DeleteActor(actor);
    ((struct GtsnegoActorSys *)actorSys)->selectorActor = 0;
}

/*
 * lever: declarations x,y,z,b reproduce the descending stack slots; p+i*4+offset keeps the per-element pointer.
 */
void GTSNEGO_MSG_CreateIconActors(struct GtsnegoActorSys *actorSys,int flag)
{
    PosRecord actorPos;
    GtsnegoMessageTriple iconX=gGtsnegoIconX;
    GtsnegoMessageTriple iconY=gGtsnegoIconY;
    GtsnegoMessageTriple iconZ=gGtsnegoIconZ;
    GtsnegoMessageTriple b=gGtsnegoIconW;
    int i;
    for(i=0;i<3;i++) {
        if(flag || i!=0) {
            actorPos.x=iconX.a[i]; actorPos.y=iconY.a[i]; actorPos.z=iconZ.a[i]; actorPos.a=i; actorPos.b=b.a[i];
            ((struct GtsnegoActorSys *)actorSys)->iconActors[i]=CLACT_CreateActor((struct Unit *)(*(void **)&((struct GtsnegoActorSys *)actorSys)->clactUnit),((struct GtsnegoActorSys *)actorSys)->uiChar,((struct GtsnegoActorSys *)actorSys)->uiPalette,((struct GtsnegoActorSys *)actorSys)->uiCellAnim,(const struct ActorInitParam *)&actorPos,1,((struct GtsnegoActorSys *)actorSys)->heapId);
            CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->iconActors[i],1);
            CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->iconActors[i],1);
        }
    }
}

/*
 * matching: declaring element after i puts the element in r4 and the counter in r5.
 */
void GTSNEGO_MSG_DeleteIconActors(struct GtsnegoActorSys *actorSys)
{
    int i;
        for (i = 0; i < 3; i++) {
                if (((struct GtsnegoActorSys *)actorSys)->iconActors[i] != 0) {
            CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->iconActors[i]);
            ((struct GtsnegoActorSys *)actorSys)->iconActors[i] = 0;
        }
    }
}

void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoActorSys *actorSys, u32 flag)
{
    if (actorSys->iconActors[0] != 0) {
        CLACT_RestartActorAnim(actorSys->iconActors[0]);
        CLACT_SetActorAutoAnim(actorSys->iconActors[0], flag);
    }
}

void GTSNEGO_MSG_SetScrollState(struct GtsnegoActorSys *actorSys, int state)
{
    actorSys->scrollState = state;
    if (state == 2) actorSys->scrollTarget = actorSys->scrollOffset + 48;
    else if (state == 1) actorSys->scrollTarget = actorSys->scrollOffset - 48;
}

void GTSNEGO_MSG_ClearScrollState(struct GtsnegoActorSys *actorSys)
{
    actorSys->scrollState = 0;
}

/*
 * lever: pass the named loaded state to out instead of rematerializing 1 or 2.
 */
int GTSNEGO_MSG_StepScroll(struct GtsnegoActorSys *actorSys, int *out)
{
    int i;
    int state;
    state=((struct GtsnegoActorSys *)actorSys)->scrollState;
    if (state==2) {
        ((struct GtsnegoActorSys *)actorSys)->scrollOffset+=8;
        if (((struct GtsnegoActorSys *)actorSys)->scrollTarget==((struct GtsnegoActorSys *)actorSys)->scrollOffset) {
            *out=state;
            ((struct GtsnegoActorSys *)actorSys)->scrollState=0;
            ((struct GtsnegoActorSys *)actorSys)->scrollOffset-=48;
        }
        for (i=0;i<6;i++) GTSNEGO_MSG_MoveListActor(actorSys,i,-8);
        ((struct GtsnegoActorSys *)actorSys)->scrollDirty=1;
    }
    state=((struct GtsnegoActorSys *)actorSys)->scrollState;
    if (state==1) {
        ((struct GtsnegoActorSys *)actorSys)->scrollOffset-=8;
        if (((struct GtsnegoActorSys *)actorSys)->scrollTarget==((struct GtsnegoActorSys *)actorSys)->scrollOffset) {
            *out=state;
            ((struct GtsnegoActorSys *)actorSys)->scrollState=0;
            ((struct GtsnegoActorSys *)actorSys)->scrollOffset+=48;
        }
        for (i=0;i<6;i++) GTSNEGO_MSG_MoveListActor(actorSys,i,8);
        ((struct GtsnegoActorSys *)actorSys)->scrollDirty=1;
    }
    return ((struct GtsnegoActorSys *)actorSys)->scrollState;
}

void GTSNEGO_MSG_ScrollAllRows(struct GtsnegoActorSys *actorSys, int flag)
{
    int i;
    int direction = 1;
    int step;
    if (flag != 0) direction -= 2;
    i = 0;
    step = direction * 48;
    for (; i < 6; i++) GTSNEGO_MSG_MoveListActor(actorSys, i, step);
}

void GTSNEGO_MSG_SetupRowBg(struct GtsnegoActorSys *actorSys)
{
    BG_SYS_ChangeScrollImmediate(4, 3, 0);
    BG_SYS_ChangeScrollImmediate(6, 3, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(1);
}

void GTSNEGO_MSG_CreateListActor(struct GtsnegoActorSys *actorSys, int slot, int outfit)
{
    PosRecord actorPos;
    if (*(void **)((u8 *)actorSys->listActors+slot*(int)sizeof(void *))) CLACT_DeleteActor((struct ClactActor *)(*(void **)((u8 *)actorSys->listActors+slot*(int)sizeof(void *))));
    actorPos.x = 0; actorPos.y = 0; actorPos.z = 1; actorPos.a = 10; actorPos.b = 2;
    *(void **)((u8 *)actorSys->listActors+slot*(int)sizeof(void *)) = CLACT_CreateActor((struct Unit *)(*(void **)&((struct GtsnegoActorSys *)actorSys)->clactUnit), *(u32 *)((u8 *)actorSys->listChars + (outfit + 6) * 4 - 6 * 4), ((struct GtsnegoActorSys *)actorSys)->listPalette, *(u32 *)((u8 *)actorSys->listCellAnims + (outfit + 25) * 4 - 25 * 4), (const struct ActorInitParam *)&actorPos, 1, ((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(*(void **)((u8 *)actorSys->listActors+slot*(int)sizeof(void *)), 1);
    CLACT_SetActorDrawEnable(*(void **)((u8 *)actorSys->listActors+slot*(int)sizeof(void *)), 0);
}

void GTSNEGO_MSG_SetListActorPos(struct GtsnegoActorSys *actorSys, int index, int x, int y)
{
    GtsnegoMessageVec pos;
    if (index < 6) {
        pos.x = x;
        pos.y = y;
        CLACT_AddActorSurfacePos((struct ClactActor *)(*(void **)((u8 *)actorSys->listActors + (u32)index * (int)sizeof(void *))), (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 1);
        CLACT_SetActorDrawEnable((*(void **)((u8 *)actorSys->listActors + (u32)index * (int)sizeof(void *))), 1);
    }
}

void GTSNEGO_MSG_SetListEntry(struct GtsnegoActorSys *actorSys, void *entry, int index)
{
    if (entry != 0) {
        GTSNEGO_MSG_CreateListActor(actorSys, index, MYSTATUS_GetTrainerView((struct MyStatus *)(entry)));
        GTSNEGO_MSG_SetListActorPos(actorSys, index, 16, -48 * (1 - index));
    }
}

void GTSNEGO_MSG_MoveListActor(struct GtsnegoActorSys *actorSys, int index, int delta)
{
    GtsnegoMessageVec pos;
    if ((*(void **)((u8 *)actorSys->listActors + (u32)index * (int)sizeof(void *))) != 0) {
        CLACT_GetActorSurfacePos((struct ClactActor *)(*(void **)((u8 *)actorSys->listActors + (u32)index * (int)sizeof(void *))), (struct ClactVec2 *)&pos, 1);
        pos.y += (s16)delta;
        CLACT_AddActorSurfacePos((struct ClactActor *)(*(void **)((u8 *)actorSys->listActors + (u32)index * (int)sizeof(void *))), (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 1);
    }
}

void GTSNEGO_MSG_ScrollListDown(struct GtsnegoActorSys *actorSys, void *entry)
{
    int i;
    if (entry) {
        if (((struct GtsnegoActorSys *)actorSys)->listActors[0]) CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->listActors[0]);
        for (i = 0; i < 5; i++) ((struct GtsnegoActorSys *)actorSys)->listActors[i] = ((struct GtsnegoActorSys *)actorSys)->listActors[i + 1];
        ((struct GtsnegoActorSys *)actorSys)->listActors[5] = 0;
        GTSNEGO_MSG_SetListEntry(actorSys, entry, 5);
    }
}

void GTSNEGO_MSG_ScrollListUp(struct GtsnegoActorSys *actorSys, void *entry)
{
    int i;
    if (entry) {
        if (((struct GtsnegoActorSys *)actorSys)->listActors[5]) CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->listActors[5]);
        for (i = 5; i > 0; i--) ((struct GtsnegoActorSys *)actorSys)->listActors[i] = ((struct GtsnegoActorSys *)actorSys)->listActors[i - 1];
        ((struct GtsnegoActorSys *)actorSys)->listActors[0] = 0;
        GTSNEGO_MSG_SetListEntry(actorSys, entry, 0);
    }
}

void GTSNEGO_MSG_FillListRange(struct GtsnegoActorSys *actorSys, void *container, int offset)
{
    int i;
    void *entry;
    for (i = 0; i < 6; i++) {
        if ((int)((u32)i + (u32)offset) >= 0) {
            entry = GTSNEGO_DISP_GetEntry(container, (int)((u32)i + (u32)offset));
            if (entry != 0) GTSNEGO_MSG_SetListEntry(actorSys, entry, i);
        }
    }
}

int GTSNEGO_MSG_GetListRowY(struct GtsnegoActorSys *actorSys, int index, int count)
{
    if (index == 0) return 0;
    count = (int)((u32)count - 1);
    if (index == count) return 132;
    return (int)((u32)index * 132) / count;
}

int GTSNEGO_MSG_GetListRowYF(struct GtsnegoActorSys *actorSys, int y, int count)
{
    float f;
    float scale;
    f = (float)(y - 26);
    scale = 132.0f;
    if (count <= 3) return 0;
    f = f / (scale / (float)(count - 2));
    if (f >= (float)(count - 2)) f = (float)(count - 3);
    return (int)f;
}

void GTSNEGO_MSG_SetIconY(struct GtsnegoActorSys *actorSys, int index, int count)
{
    GtsnegoMessageVec pos;
    if (actorSys->iconActors[0] != 0) {
        CLACT_GetActorSurfacePos((struct ClactActor *)actorSys->iconActors[0], (struct ClactVec2 *)&pos, 1);
        pos.y = GTSNEGO_MSG_GetListRowY(actorSys, index, count) + 26;
        CLACT_AddActorSurfacePos((struct ClactActor *)actorSys->iconActors[0], (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 1);
    }
}

int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoActorSys *actorSys,int y,int count) { GtsnegoMessagePt pt; int result; result=0; if(actorSys->iconActors[0]) { CLACT_GetActorSurfacePos((struct ClactActor *)actorSys->iconActors[0],(struct ClactVec2 *)&pt,1); pt.y=y; CLACT_AddActorSurfacePos((struct ClactActor *)actorSys->iconActors[0],(const struct ClactVec2 *)( &pt),1); result=GTSNEGO_MSG_GetListRowYF(actorSys,y,count); } return result; }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void GTSNEGO_MSG_CycleIdleAnim(void *actorSys, u32 frame) { u16 next; next=CLACT_GetActorAnimSeq(((struct GtsnegoActorSys *)actorSys)->idleCharActor)+1; if(next>26) next=11; CLACT_SetActorAnimSeq(((struct GtsnegoActorSys *)actorSys)->idleCharActor,next); }

void GTSNEGO_MSG_CreateIdleActors(struct GtsnegoActorSys *actorSys)
{
    struct ClactAnimCommand c;
    PosRecord actorPos;
    actorPos.x=128; actorPos.y=52; actorPos.z=27; actorPos.a=2; actorPos.b=1;
    ((struct GtsnegoActorSys *)actorSys)->idleFrameActor=CLACT_CreateActor((struct Unit *)(*(void **)&((struct GtsnegoActorSys *)actorSys)->clactUnit),((struct GtsnegoActorSys *)actorSys)->idleChar,((struct GtsnegoActorSys *)actorSys)->idlePalette,((struct GtsnegoActorSys *)actorSys)->idleCellAnim,(const struct ActorInitParam *)&actorPos,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->idleFrameActor,1);
    CLACT_SetActorDrawEnable((struct ClactActor *)(((struct GtsnegoActorSys *)actorSys)->idleFrameActor),1);
    actorPos.z=11; actorPos.a=1;
    ((struct GtsnegoActorSys *)actorSys)->idleCharActor=CLACT_CreateActor((struct Unit *)(*(void **)&((struct GtsnegoActorSys *)actorSys)->clactUnit),((struct GtsnegoActorSys *)actorSys)->idleChar,((struct GtsnegoActorSys *)actorSys)->idlePalette,((struct GtsnegoActorSys *)actorSys)->idleCellAnim,(const struct ActorInitParam *)&actorPos,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->idleCharActor,1);
    CLACT_SetActorDrawEnable((struct ClactActor *)(((struct GtsnegoActorSys *)actorSys)->idleCharActor),1);
    c.op=0; c.param=actorSys; c.func=GTSNEGO_MSG_CycleIdleAnim;
    CLACT_ApplyActorAnimCommand((struct ClactActor *)(((struct GtsnegoActorSys *)actorSys)->idleCharActor),&c);
    BG_SYS_SetMainVisiblePlanes(31);
}

void GTSNEGO_MSG_DeleteIdleActors(struct GtsnegoActorSys *actorSys) { CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->idleFrameActor,0); CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->idleFrameActor); CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->idleCharActor,0); CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->idleCharActor); }

void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoActorSys *actorSys,int outfit)
{
    GtsnegoMessageTable a=gGtsnegoIdleAnimTable;
    void *arcHandle=ARC_TOOL_CreateHandle(144,actorSys->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,15,0,0,(u16)(actorSys->bgCharLayer0),0,0,actorSys->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    CLACT_SetActorAutoAnim((struct ClactActor *)actorSys->idleCharActor,0);
    CLACT_SetActorAnimSeq((struct ClactActor *)actorSys->idleCharActor,a.a[outfit]+11);
    CLACT_SetActorAnimIndex((struct ClactActor *)((struct Actor *)(actorSys->idleCharActor)),4);
    CLACT_SetActorAnimSeq(actorSys->idleFrameActor,28);
    BG_SYS_MarkTileDirty(0);
    actorSys->idleFadePos=0;
    actorSys->idleFadeActive=0;
}

void GTSNEGO_MSG_CreateIdleUi(struct GtsnegoActorSys *actorSys)
{
    void *arcHandle=ARC_TOOL_CreateHandle(144,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,14,2,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,13,0,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,16,3,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_MSG_CreateIdleActors(actorSys);
    BG_SYS_MarkTileDirty(2); BG_SYS_MarkTileDirty(0); BG_SYS_MarkTileDirty(3);
    ((struct GtsnegoActorSys *)actorSys)->idleFadePos=0;
    ((struct GtsnegoActorSys *)actorSys)->idleFadeActive=1;
}

void GTSNEGO_MSG_StepIdleFade(struct GtsnegoActorSys *actorSys) { if(actorSys->idleFadeActive) { BG_SYS_ChangeScrollImmediate(2,3,actorSys->idleFadePos); actorSys->idleFadePos+=1; } }

/*
 * trailing: 2-byte zero alignment padding at 0x021D770E.
 * lever: indexed pointer sum before the far field offset preserves the base.
 */
void GTSNEGO_MSG_Teardown(struct GtsnegoActorSys *actorSys)
{
    int i;
    void *arcHandle;
    for(i=0;i<6;i++) {
        if(((struct GtsnegoActorSys *)actorSys)->listActors[i]) {
            CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->listActors[i],0);
            CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->listActors[i]);
            ((struct GtsnegoActorSys *)actorSys)->listActors[i]=0;
        }
    }
    GTSNEGO_MSG_DeleteCursorActor(actorSys);
    GTSNEGO_MSG_DeleteTileHandle(actorSys);
    GTSNEGO_MSG_DeleteIdleActors(actorSys);
    GTSNEGO_MSG_DeleteIconActors(actorSys);
    GTSNEGO_MSG_DeleteActors(actorSys);
    arcHandle=ARC_TOOL_CreateHandle((uptr)((void *)144),((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,12,0,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,18,4,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle,2,5,0,0x100,0x100,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys,0);
    BG_SYS_SetPlaneVisible(2,0);
    BG_SYS_MarkTileDirty(0);
    BG_SYS_SetPlaneVisible(3,0);
    ((struct GtsnegoActorSys *)actorSys)->idleFadePos=0;
    ((struct GtsnegoActorSys *)actorSys)->idleFadeActive=0;
}

void GTSNEGO_MSG_DeleteButtons(struct GtsnegoMsgCtx *msgCtx)
{
    if (((struct GtsnegoMsgCtx *)msgCtx)->buttonMan) {
        BUTTON_MAN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->buttonMan);
        ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan = 0;
    }
}

/*
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 */
struct GtsnegoMsgCtx *GTSNEGO_MSG_Create(u32 heap,u32 msgFileId)
{
    struct GtsnegoMsgCtx *p=GFL_HEAP_Alloc(heap,sizeof(*p),1,sGtsnegoMsgHeapName,0xa9);
    p->heapId=heap;
    BMP_WIN_Init(p->heapId);
    GF_FONT_InitTextColor();
    p->tcbList=TCBL_Create(p->heapId,p->heapId,1,0);
    p->printQueue=(void *)PRINTSYS_QUE_Create((u32)(u32)p->heapId);
    p->windowText=STRBUF_Create(240,p->heapId);
    p->srcText=STRBUF_Create(240,p->heapId);
    p->expandedText=STRBUF_Create(240,p->heapId);
    p->font=GF_FONT_Create(23,0,0,0,p->heapId);
    p->msgData=MSGDATA_CreateFromArchive(0,2,(u16)msgFileId,(u16)(p->heapId));
    p->wordSet=WORDSET_Create(6,64,p->heapId);
    p->taskMenuRes=APP_TASKMENU_RES_Create(5,9,p->font,p->printQueue,p->heapId);
    p->windowFrameTiles=BMP_MENUWORK_LoadFrameGfx(1,12,0,p->heapId);
    p->sysFrameTiles=BMP_MENUWORK_LoadFrameGfx(6,12,0,p->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x160,32,p->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,0x160,32,p->heapId);
    return p;
}

void GTSNEGO_MSG_Main(struct GtsnegoMsgCtx *msgCtx)
{
    GF_FONT_SetTextColor(1, 2, 15);
    TCBL_Main(msgCtx->tcbList);
    PRINTSYS_QUE_Main(msgCtx->printQueue);
    if (msgCtx->taskMenuWin) APP_TASKMENU_WIN_Update(msgCtx->taskMenuWin);
    if (msgCtx->pmsDraw) PMS_DRAW_Main(msgCtx->pmsDraw);
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
void GTSNEGO_MSG_Delete(struct GtsnegoMsgCtx *msgCtx)
{
    int i;
    u32 frameTiles;
    frameTiles=((struct GtsnegoMsgCtx *)msgCtx)->windowFrameTiles;
    BG_SYS_FreeTileRun(1,(u16)frameTiles,decodeHighHalfword(frameTiles));
    frameTiles=((struct GtsnegoMsgCtx *)msgCtx)->sysFrameTiles;
    BG_SYS_FreeTileRun(6,(u16)frameTiles,decodeHighHalfword(frameTiles));
    GTSNEGO_MSG_DeleteButtons(msgCtx);
    GF_FONT_SetDefaultTextColor();
    MSGDATA_Delete(((struct GtsnegoMsgCtx *)msgCtx)->msgData);
    GF_FONT_Delete(((struct GtsnegoMsgCtx *)msgCtx)->font);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->srcText);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->windowText);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    GTSNEGO_MSG_DeleteDraw(msgCtx);
    if(((struct GtsnegoMsgCtx *)msgCtx)->printStream) {PRINTSYS_PrintStreamDelete(((struct GtsnegoMsgCtx *)msgCtx)->printStream);((struct GtsnegoMsgCtx *)msgCtx)->printStream=0;}
    WORDSET_Delete(((struct GtsnegoMsgCtx *)msgCtx)->wordSet);
    if(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin) {APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin);((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin=0;}
    APP_TASKMENU_RES_Delete(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes);
    TCBL_Destroy(((struct GtsnegoMsgCtx *)msgCtx)->tcbList);
    PRINTSYS_QUE_Clear(((struct GtsnegoMsgCtx *)msgCtx)->printQueue);
    PRINTSYS_QUE_Delete(((struct GtsnegoMsgCtx *)msgCtx)->printQueue);
    if(((struct GtsnegoMsgCtx *)msgCtx)->messageWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->messageWindow);
    if(((struct GtsnegoMsgCtx *)msgCtx)->entryWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->entryWindow);
    if(((struct GtsnegoMsgCtx *)msgCtx)->singleWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->singleWindow);
    if(((struct GtsnegoMsgCtx *)msgCtx)->pairWindowBottom) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->pairWindowBottom);
    if(((struct GtsnegoMsgCtx *)msgCtx)->pairWindowTop) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->pairWindowTop);
    if(((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow);
    if(((struct GtsnegoMsgCtx *)msgCtx)->drawWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->drawWindow);
    if(((struct GtsnegoMsgCtx *)msgCtx)->extraWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->extraWindow);
    if(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow) BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow);
    for(i=0;i<12;i++) if(msgCtx->rowWindows[i]) BMP_WIN_Delete(msgCtx->rowWindows[i]);
    for(i=0;i<6;i++) if(msgCtx->listWindows[i]) BMP_WIN_Delete(msgCtx->listWindows[i]);
    BMP_WIN_Exit();
    GFL_HEAP_Free(msgCtx);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *msgCtx,u16 msgId)
{
    void *window;
    MSGDATA_ReadString(msgCtx->msgData,msgId,*(void **)&msgCtx->windowText);
    if (!msgCtx->messageWindow) msgCtx->messageWindow=(void *)BMP_WIN_Create(1,1,19,30,4,11,1);
    window=msgCtx->messageWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,*(void **)&msgCtx->windowText,*(void **)&msgCtx->font);
    BMP_MENUWORK_DrawWindow(window,1,(u16)(msgCtx->windowFrameTiles),12);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(1);
}

void GTSNEGO_MSG_PrintWindowB(struct GtsnegoMsgCtx *msgCtx, int msgId)
{
    void *window;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText);
    if (!((struct GtsnegoMsgCtx *)msgCtx)->messageWindow) ((struct GtsnegoMsgCtx *)msgCtx)->messageWindow=(void *)BMP_WIN_Create(1,1,21,30,2,11,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->messageWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->font);
    BMP_MENUWORK_DrawWindow(window,1,(u16)(((struct GtsnegoMsgCtx *)msgCtx)->windowFrameTiles),12);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(1);
}

/*
 * follower: two zero padding bytes at 021D7B36.
 */
int GTSNEGO_MSG_UpdatePrintStream(struct GtsnegoMsgCtx *msgCtx)
{
    if (msgCtx->printStream) {
        switch (PRINTSYS_PrintStreamGetState(msgCtx->printStream)) {
        case 2: PRINTSYS_PrintStreamDelete(msgCtx->printStream); msgCtx->printStream=0; break;
        case 1: if (KEY_GetTrg()==1) PRINTSYS_PrintStreamReleasePause(msgCtx->printStream); break;
        }
        return 0;
    }
    return 1;
}

void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *msgCtx) { if(msgCtx->messageWindow) { BMP_MENUWORK_DrawWindowBorder(msgCtx->messageWindow,2); BMP_WIN_ClearScreen(msgCtx->messageWindow); BG_SYS_MarkTileDirty(1); BMP_WIN_Delete(msgCtx->messageWindow); msgCtx->messageWindow=0; } }

void *GTSNEGO_MSG_OpenMenu(struct GtsnegoMsgCtx *msgCtx,int position)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)msgCtx)->heapId;
    config.count=2;
    config.entries=msgCtx->menuEntries;
    switch(position) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,25,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].msgColor=0x39e0;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].str=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,26,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].msgColor=0x39e0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&config),((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].str);
    return result;
}

int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *msgCtx) { return BUTTON_MAN_UpdateSlots(msgCtx->buttonMan); }

void GTSNEGO_MSG_DeleteRows(struct GtsnegoMsgCtx *msgCtx) { int i; for(i=0;i<12;i++) { if(msgCtx->rowWindows[i]) { BMP_WIN_Delete(msgCtx->rowWindows[i]); msgCtx->rowWindows[i]=0; } } GF_FONT_SetTextColor(1,2,0); }

int GTSNEGO_MSG_CreateRow(struct GtsnegoMsgCtx *msgCtx, int msgId, int x, int y, int width, int bgLayer)
{
    int i;
    void *window;
    for(i=0;i<12;i++) {
        if(!msgCtx->rowWindows[i]) {
            msgCtx->rowWindows[i]=(void *)BMP_WIN_Create((u8)bgLayer,(u8)x,(u8)y,(u8)width,2,11,1);
            window=msgCtx->rowWindows[i];
            BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)window),0);
            MSGDATA_ReadString(msgCtx->msgData,msgId,msgCtx->srcText);
            PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)window),2,2,msgCtx->srcText,msgCtx->font);
            BMP_WIN_TransferChars((struct BmpWin *)window);
            BMP_WIN_MakeScreen((struct BmpWin *)window);
            return i;
        }
    }
    return 0;
}

int GTSNEGO_MSG_CreateRowEx(struct GtsnegoMsgCtx *msgCtx, int msgId, int x, int y)
{
    return GTSNEGO_MSG_CreateRow(msgCtx, msgId, x, y, 0x14, 6);
}

/*
 * follower: two zero padding bytes at 021D7D2E.
 */
void GTSNEGO_MSG_RedrawRow(struct GtsnegoMsgCtx *msgCtx,u16 msgId,int row)
{
    void *q=msgCtx->rowWindows[row];
    if(q) {
        BMP_Clear(BMP_WIN_GetBmp(q),0);
        MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText);
        PRINTSYS_Print(BMP_WIN_GetBmp(q),2,2,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->font);
        BMP_WIN_TransferChars(q);
    }
}

void GTSNEGO_MSG_FlushRowLayer(struct GtsnegoMsgCtx *msgCtx) { BG_SYS_MarkTileDirty(6); }

void GTSNEGO_MSG_ClearRows(struct GtsnegoMsgCtx *msgCtx) { int i; for(i=0;i<12;i++) { if(msgCtx->rowWindows[i]) { BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(msgCtx->rowWindows[i])); BMP_MENUWORK_DrawWindowBorder(msgCtx->rowWindows[i],2); BMP_WIN_ClearScreen(msgCtx->rowWindows[i]); } } }

void GTSNEGO_MSG_CreateYesNoUi(struct GtsnegoMsgCtx *msgCtx,void (*callback)(u32, s32, void *),void *callbackWork)
{
    GTSNEGO_MSG_DeleteRows(msgCtx);
    GTSNEGO_MSG_CreateRow(msgCtx,0,8,7,16,6);
    GTSNEGO_MSG_CreateRow(msgCtx,1,8,13,16,6);
    GTSNEGO_MSG_FlushRowLayer(msgCtx);
    GTSNEGO_MSG_DeleteButtons(msgCtx);
    ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan=BUTTON_MAN_Create((u8 *)gGtsnegoButtonYesNo,callback,callbackWork,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
}

/*
 * follower: existing 021D7E88, 021D7E9C, 021D7EB0 files remain separate.
 */
void GTSNEGO_MSG_CreateListUi(struct GtsnegoMsgCtx *msgCtx,void (*callback)(u32, s32, void *),void *callbackWork,int rowAIndex,int rowBIndex,int rowCIndex)
{
    GTSNEGO_MSG_DeleteRows(msgCtx);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx(msgCtx,2,0,0);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx(msgCtx,3,3,6);
    GTSNEGO_MSG_CreateRowEx(msgCtx,23,1,11);
    GTSNEGO_MSG_CreateRowEx(msgCtx,24,1,16);
    GF_FONT_SetTextColor(1,2,0);
    msgCtx->rowAHandle=GTSNEGO_MSG_CreateRowEx(msgCtx,gGtsnegoRowLabelA[rowAIndex],13,6);
    msgCtx->rowBHandle=GTSNEGO_MSG_CreateRowEx(msgCtx,gGtsnegoRowLabelB[rowBIndex],16,11);
    msgCtx->rowCHandle=GTSNEGO_MSG_CreateRowEx(msgCtx,gGtsnegoRowLabelB[rowCIndex],16,16);
    GTSNEGO_MSG_FlushRowLayer(msgCtx);
    GTSNEGO_MSG_DeleteButtons(msgCtx);
    ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan=BUTTON_MAN_Create((u8 *)gGtsnegoButtonList,callback,callbackWork,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
}

/*
 * follower: separately filed 021D7E9C.
 */
void GTSNEGO_MSG_RedrawRowA(struct GtsnegoMsgCtx *msgCtx,int index) {GTSNEGO_MSG_RedrawRow(msgCtx,gGtsnegoRowLabelA[index],msgCtx->rowAHandle);}

/*
 * follower: separately filed 021D7EB0.
 */
void GTSNEGO_MSG_RedrawRowB(struct GtsnegoMsgCtx *msgCtx,int index) {GTSNEGO_MSG_RedrawRow(msgCtx,gGtsnegoRowLabelB[index],msgCtx->rowBHandle);}

void GTSNEGO_MSG_RedrawRowC(struct GtsnegoMsgCtx *msgCtx,int index) {GTSNEGO_MSG_RedrawRow(msgCtx,gGtsnegoRowLabelB[index],msgCtx->rowCHandle);}

void GTSNEGO_MSG_DeleteButtonsKeep(struct GtsnegoMsgCtx *msgCtx) { GTSNEGO_MSG_DeleteButtons(msgCtx); }

void *GTSNEGO_MSG_CreateTooltip(struct GtsnegoMsgCtx *msgCtx,u16 msgId)
{
    int width;
    void *result;
    void *text;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].msgColor=0x39e3;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].type=0;
    width=((int)PRINTSYS_MeasureWidestLine(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str,*(struct GfFont **)&((struct GtsnegoMsgCtx *)msgCtx)->font,(int)0)+32)/16;
    result=APP_TASKMENU_WIN_CreateEx((struct TaskMenuRes *)(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes),msgCtx->menuEntries,(u8)(16-width),(u8)21,width*2,3,(int)0,(int)1,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str);
    return result;
}

void GTSNEGO_MSG_PrintTooltip(struct GtsnegoMsgCtx *msgCtx,u16 msgId)
{
    void *window;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText);
    if(!((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow) ((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow=(void *)BMP_WIN_Create(1,1,13,14,3,4,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),2,3,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText,*(void **)&((struct GtsnegoMsgCtx *)msgCtx)->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
}

/*
 * follower: two zero padding bytes at 021D80D2.
 */
void GTSNEGO_MSG_PrintEntry(struct GtsnegoMsgCtx *msgCtx,void *status)
{
    u32 language,version,checkedLanguage,checkedVersion;
    void *window;
    language=MYSTATUS_GetNation(status);
    version=MYSTATUS_GetArea(status);
    checkedLanguage=NATION_AREA_SanitizeNation(language,version,MYSTATUS_GetLanguage(status));
    checkedVersion=NATION_AREA_SanitizeArea(language,version,MYSTATUS_GetLanguage(status));
    if(language==checkedLanguage && version==checkedVersion) {
        WORDSET_SetSlotFromMsgE7(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,0,MYSTATUS_GetNation(status));
        language=MYSTATUS_GetNation(status);
        WORDSET_SetSlotFromKeyedMessage(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,1,language,MYSTATUS_GetArea(status));
    } else {
        WORDSET_SetSlotFromMsgE7(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,0,0);
        WORDSET_SetSlotFromKeyedMessage(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,1,0,0);
    }
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,34,((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,((struct GtsnegoMsgCtx *)msgCtx)->srcText,((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    if(!((struct GtsnegoMsgCtx *)msgCtx)->entryWindow) ((struct GtsnegoMsgCtx *)msgCtx)->entryWindow=(void *)BMP_WIN_Create(1,1,15,30,5,11,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->entryWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),5,5,((struct GtsnegoMsgCtx *)msgCtx)->srcText,((struct GtsnegoMsgCtx *)msgCtx)->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(1);
}

/*
 * follower: two zero padding bytes at 021D8116.
 */
void GTSNEGO_MSG_DeleteEntryWindow(struct GtsnegoMsgCtx *msgCtx)
{
    if (msgCtx->entryWindow) {
        BMP_Clear(BMP_WIN_GetBmp(msgCtx->entryWindow),0);
        BMP_WIN_TransferChars(msgCtx->entryWindow);
        BMP_WIN_ClearScreen(msgCtx->entryWindow);
        BG_SYS_MarkTileDirty(1);
        BMP_WIN_Delete(msgCtx->entryWindow);
        msgCtx->entryWindow=0;
    }
}

int GTSNEGO_MSG_PrintListEntry(struct GtsnegoMsgCtx *msgCtx, void *status, int row)
{
    void **listWindows=msgCtx->listWindows;
    void *window;
    if(!listWindows[row]) listWindows[row]=(void *)BMP_WIN_Create((u8)6,(u8)6,(u8)(row*6+1),(u8)24,4,11,1);
    window=listWindows[row];
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    STRBUF_Clear(msgCtx->expandedText);
    STRBUF_Clear(msgCtx->srcText);
    WORDSET_SetSlotMyStatus(msgCtx->wordSet,0,status);
    WORDSET_SetSlotNumber(msgCtx->wordSet,1,MYSTATUS_GetIdLow16(status),5,2,1);
    WORDSET_SetSlotFromMsgE7(msgCtx->wordSet,2,MYSTATUS_GetNation(status));
    MSGDATA_ReadString(msgCtx->msgData,28,msgCtx->expandedText);
    WORDSET_CopyTaggedText(msgCtx->wordSet,msgCtx->srcText,msgCtx->expandedText);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,msgCtx->srcText,msgCtx->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    return 0;
}

void GTSNEGO_MSG_PrintList(struct GtsnegoMsgCtx *msgCtx,void *list)
{
    int i;
    void *entry;
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRow(msgCtx,30,0,0,20,5);
    for(i=0;i<3;i++) {
        entry=GTSNEGO_DISP_GetEntry(list,i);
        if(entry) GTSNEGO_MSG_PrintListEntry(msgCtx,entry,i+2);
    }
    BG_SYS_MarkTileDirty(5);
}

void GTSNEGO_MSG_PrintListEntryAt(struct GtsnegoMsgCtx *msgCtx,void *list,int index) { GTSNEGO_MSG_PrintListEntry(msgCtx,GTSNEGO_DISP_GetEntry(list,index),5); BG_SYS_MarkTileDirty(6); }

void GTSNEGO_MSG_ShiftListDown(struct GtsnegoMsgCtx *msgCtx)
{
    int i;
    if(msgCtx->listWindows[0]) {BMP_WIN_Delete(msgCtx->listWindows[0]);msgCtx->listWindows[0]=0;}
    for(i=1;i<6;i++) {
        if(msgCtx->listWindows[i]) {
            BMP_WIN_SetPosY(msgCtx->listWindows[i],BMP_WIN_GetPosY(msgCtx->listWindows[i])-6);
            BMP_WIN_MakeScreen(msgCtx->listWindows[i]);
        }
    }
    BG_SYS_MarkTileDirty(6);
    for(i=0;i<5;i++) msgCtx->listWindows[i]=msgCtx->listWindows[i+1];
    msgCtx->listWindows[5]=0;
}

void GTSNEGO_MSG_PrintListRange(struct GtsnegoMsgCtx *msgCtx,void *list,int start) { int i; void *entry; for(i=0;i<6;i++) { if((int)((u32)i+(u32)start)>=0) { entry=GTSNEGO_DISP_GetEntry(list,(int)((u32)i+(u32)start)); if(entry) GTSNEGO_MSG_PrintListEntry(msgCtx,entry,i); } } BG_SYS_MarkTileDirty(6); }

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void GTSNEGO_MSG_PrintListEntryN(struct GtsnegoMsgCtx *msgCtx,void *list,int index)
{
    GTSNEGO_MSG_PrintListEntry(msgCtx,GTSNEGO_DISP_GetEntry(list,index),0);
    BG_SYS_MarkTileDirty(6);
}

void GTSNEGO_MSG_ShiftListUp(struct GtsnegoMsgCtx *msgCtx)
{
    int i;
    if(msgCtx->listWindows[5]) {BMP_WIN_Delete(msgCtx->listWindows[5]);msgCtx->listWindows[5]=0;}
    for(i=0;i<6;i++) {
        if(msgCtx->listWindows[i]) {
            BMP_WIN_SetPosY(msgCtx->listWindows[i],BMP_WIN_GetPosY(msgCtx->listWindows[i])+6);
            BMP_WIN_MakeScreen(msgCtx->listWindows[i]);
        }
    }
    BG_SYS_MarkTileDirty(6);
    for(i=5;i>0;i--) msgCtx->listWindows[i]=msgCtx->listWindows[i-1];
    msgCtx->listWindows[0]=0;
}

void *GTSNEGO_MSG_OpenMenuB(struct GtsnegoMsgCtx *msgCtx,int position)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)msgCtx)->heapId;
    config.count=2;
    config.entries=msgCtx->menuEntries;
    switch(position) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,27,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].msgColor=0x39e0;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].type=0;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].str=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,33,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].msgColor=0x39e0;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].type=0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&config),((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[1].str);
    return result;
}

void GTSNEGO_MSG_CloseMenu(struct TaskMenuWork *taskMenu)
{
    if (taskMenu != 0) {
        *(volatile u16 *)REG_BLDCNT_ADDR = 0;
        APP_TASKMENU_CloseMenu((struct TaskMenuWork *)taskMenu);
    }
}

void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *msgCtx,struct GtsnegoActorSys *actorSys)
{
    if(!msgCtx->pmsDraw)
        msgCtx->pmsDraw=PMS_DRAW_Create(GTSNEGO_DISP_GetUnit(actorSys),0,(msgCtx->printQueue),(msgCtx->font),8,4,msgCtx->heapId);
}

void GTSNEGO_MSG_DeleteDraw(struct GtsnegoMsgCtx *msgCtx)
{
    if (((struct GtsnegoMsgCtx *)msgCtx)->pmsDraw) {
        PMS_DRAW_Delete(((struct GtsnegoMsgCtx *)msgCtx)->pmsDraw);
        ((struct GtsnegoMsgCtx *)msgCtx)->pmsDraw = 0;
    }
}

void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *msgCtx, void *sentence)
{
    GtsnegoMessagePair c = gGtsnegoMsgDrawConfig;
    void *window;
    if (!msgCtx->drawWindow) msgCtx->drawWindow = (void *)BMP_WIN_Create(1, 1, 15, 30, 5, 11, 1);
    window = msgCtx->drawWindow;
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PMS_DRAW_SetNullColorPalette(msgCtx->pmsDraw, 0);
    PMS_DRAW_SetPrintColor(msgCtx->pmsDraw, 0x3c40);
    PMS_DRAW_PrintOffset(msgCtx->pmsDraw, (void *)window, (void *)sentence, 0, (void *)(&c));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(1);
}

void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *msgCtx, u16 msgId)
{
    void *window;
    MSGDATA_ReadString(msgCtx->msgData, msgId, *(void **)&msgCtx->srcText);
    if (!msgCtx->statusWindow) msgCtx->statusWindow = (void *)BMP_WIN_Create(1, 0, 0, 14, 2, 11, 1);
    window = msgCtx->statusWindow;
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 2, 2, *(void **)&msgCtx->srcText, *(void **)&msgCtx->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(1);
}

void GTSNEGO_MSG_CreateConfirmUi(struct GtsnegoMsgCtx *msgCtx, void (*callback)(u32, s32, void *), void *callbackWork)
{
    void *label = STRBUF_Create(100, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str = label;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData, 15, label);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].msgColor = 0x39e3;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].type = 0;
    ((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin = APP_TASKMENU_WIN_CreateEx((struct TaskMenuRes *)(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes), msgCtx->menuEntries, 10, 21, 12, 3, 0, 1, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    if (!UI_GetInputMode()) APP_TASKMENU_WIN_SetActive(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin, 1);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntries[0].str);
    GTSNEGO_MSG_DeleteButtons(msgCtx);
    ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan = BUTTON_MAN_Create((u8 *)gGtsnegoButtonConfirm, callback, callbackWork, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
}

void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *msgCtx)
{
    APP_TASKMENU_WIN_SetDecide(msgCtx->taskMenuWin, 1);
}

void GTSNEGO_MSG_DeleteConfirmWindow(struct GtsnegoMsgCtx *msgCtx)
{
    APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin);
    BG_SYS_MarkTileDirty(5);
    ((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin = 0;
}

int GTSNEGO_MSG_IsConfirmFinished(struct GtsnegoMsgCtx *msgCtx)
{
    if(APP_TASKMENU_WIN_IsFinish(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin)){
        GTSNEGO_MSG_DeleteConfirmWindow((msgCtx));
        return 1;
    }
    return 0;
}

void GTSNEGO_MSG_PrintPair(struct GtsnegoMsgCtx *msgCtx,int unused,u32 tradeCount)
{
    void *window;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,40,((struct GtsnegoMsgCtx *)msgCtx)->srcText);
    if(!((struct GtsnegoMsgCtx *)msgCtx)->pairWindowTop) ((struct GtsnegoMsgCtx *)msgCtx)->pairWindowTop=(void *)BMP_WIN_Create(1,21,4,10,2,4,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->pairWindowTop;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,3,((struct GtsnegoMsgCtx *)msgCtx)->srcText,((struct GtsnegoMsgCtx *)msgCtx)->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    WORDSET_SetSlotNumber(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,0,tradeCount,5,1,1);
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,36,((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,((struct GtsnegoMsgCtx *)msgCtx)->srcText,((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    if(!((struct GtsnegoMsgCtx *)msgCtx)->pairWindowBottom) ((struct GtsnegoMsgCtx *)msgCtx)->pairWindowBottom=(void *)BMP_WIN_Create(1,21,6,10,3,11,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->pairWindowBottom;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,5,((struct GtsnegoMsgCtx *)msgCtx)->srcText,((struct GtsnegoMsgCtx *)msgCtx)->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
}

void GTSNEGO_MSG_PrintSingle(struct GtsnegoMsgCtx *msgCtx, void *status)
{
    void *window;
    WORDSET_SetSlotMyStatus(((struct GtsnegoMsgCtx *)msgCtx)->wordSet, 0, status);
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData, 37, *(void **)&((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)msgCtx)->wordSet, *(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText, *(void **)&((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    if (!((struct GtsnegoMsgCtx *)msgCtx)->singleWindow) ((struct GtsnegoMsgCtx *)msgCtx)->singleWindow = (void *)BMP_WIN_Create(1, 11, 10, 10, 3, 11, 1);
    window = ((struct GtsnegoMsgCtx *)msgCtx)->singleWindow;
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(1, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 0, 0, *(void **)&((struct GtsnegoMsgCtx *)msgCtx)->srcText, *(void **)&((struct GtsnegoMsgCtx *)msgCtx)->font);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
}

void GTSNEGO_MSG_PrintSummary(struct GtsnegoMsgCtx *msgCtx,void *status,u32 tradeCount)
{
    GTSNEGO_MSG_PrintSingle(msgCtx,(void *)status);
    GTSNEGO_MSG_PrintPair(msgCtx,36,tradeCount);
    GTSNEGO_MSG_PrintTooltip(msgCtx,41);
    GTSNEGO_MSG_PrintEntry(msgCtx,status);
    GTSNEGO_MSG_PrintWindowB(msgCtx,17);
}

void GTSNEGO_MSG_DeleteAll(struct GtsnegoMsgCtx *msgCtx)
{
    int i;

    if (((struct GtsnegoMsgCtx *)msgCtx)->statusWindow != 0) {
        BMP_MENUWORK_DrawWindowBorder(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow, 2);
        BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow);
        BG_SYS_MarkTileDirty(1);
        BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow);
        ((struct GtsnegoMsgCtx *)msgCtx)->statusWindow = 0;
    }
    if (((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin != 0) {
        APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin);
        ((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin = 0;
    }
    for (i = 0; i < 6; i++) {
        if (msgCtx->listWindows[i] != 0) {
            BMP_WIN_ClearScreen(msgCtx->listWindows[i]);
            BMP_WIN_Delete(msgCtx->listWindows[i]);
            msgCtx->listWindows[i] = 0;
        }
    }
    GTSNEGO_MSG_ClearRows(msgCtx);
    GTSNEGO_MSG_DeleteRows(msgCtx);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x160, 0x20, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    BG_SYS_MarkTileDirty(5);
}
