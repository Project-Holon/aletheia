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
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   gGtsnegoIconX 0x021D892C data a2
 *   gGtsnegoIconY 0x021D8924 data a2
 *   gGtsnegoIconZ 0x021D893C data a2
 *   gGtsnegoIconW 0x021D8934 data a2
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   MYSTATUS_GetOutfit 0x02008554 thumb
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   _s32_div_f 0x0209C0A4 arm
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
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb  arm9
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb  arm9
 *   MYSTATUS_GetIdLow16  0x02008534  thumb  arm9
 *   MYSTATUS_GetGender  0x02008564  thumb  arm9
 *   MYSTATUS_GetLanguage  0x0200856C  thumb  arm9
 *   MYSTATUS_GetVersion  0x02008570  thumb  arm9
 *   BMP_OAM_CheckRangeGetId  0x02025C1C  thumb  arm9
 *   BMP_OAM_CheckRangeGetMin  0x02025C30  thumb  arm9
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
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);
extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_SetupTileScreen(u32 idx, u32 x, u32 y, u16 value);
extern void *GTSNEGO_DISP_GetEntry(void **p, int i);
extern void BG_SYS_SetFlagField06(u32 bit);
extern void BG_SYS_SetTileEntry(u32, int, int, int, u8, u8, u8);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_PushTile(u32);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 MYSTATUS_GetOutfit(const struct Sub0200852CObj *obj);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern int _s32_div_f(int, int);
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void CLACT_SetActorAnimIndex(int actor, int anim_idx);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BUTTON_MAN_Delete(void *);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_InitTextColor(void);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, u32 font, u32 printQue, u16 heap);
extern void *BMP_MENUWORK_LoadFrameGfx(void *,u32,u32,u32);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);
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
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_MENUWORK_DrawWindow(void *win, int commitMode, int tileBase, int palette);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern u32 KEY_GetTrg(void);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *res);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void *BUTTON_MAN_Create(u8 *rects, int a1, int arg, int heap);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern u32 *APP_TASKMENU_WIN_CreateEx(u32 res, u32 item, u32 charPosX, u32 charPosY, u8 width, u8 height, u32 anmSpeed, u32 isCenter, u16 heapId);
extern u8 MYSTATUS_GetLanguage(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetVersion(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetGender(const struct Sub0200852CObj *obj);
extern u32 BMP_OAM_CheckRangeGetId(u32,u32,u32);
extern u32 BMP_OAM_CheckRangeGetMin(u32,u32,u32);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u16 MYSTATUS_GetIdLow16(const struct Sub0200852CObj *obj);
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
extern u8 UI_GetInputMode(void);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoActorSys *p,u32 n);
int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoActorSys *p);
void GTSNEGO_MSG_CreateActorAt(u8 *p,u16 x,u16 y,int flag);
void GTSNEGO_MSG_DeleteActors(u8 *p);
void GTSNEGO_MSG_SetActorMode(u8 *p,u32 n);
void GTSNEGO_MSG_InitWindows(u8 *p, int n);
void GTSNEGO_MSG_DeleteTileHandle(u8 *p);
void GTSNEGO_MSG_DrawTileRow(struct GtsnegoActorSys *p, int n);
void GTSNEGO_MSG_FillTileRow(struct GtsnegoActorSys *p, int n);
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoActorSys *p,void *list,int first);
void GTSNEGO_MSG_TeardownActorList(u8 *p);
void GTSNEGO_MSG_TeardownTileRows(u8 *p);
int GTSNEGO_MSG_CursorDown(void *unused,int *p);
int GTSNEGO_MSG_CursorUp(void *unused,int *p);
void GTSNEGO_MSG_SetCursorIndex(void *unused, int *p, int n);
void GTSNEGO_MSG_CreateCursorActor(u8 *p);
void GTSNEGO_MSG_DeleteCursorActor(u8 *p);
void GTSNEGO_MSG_CreateIconActors(u8 *p,int flag);
void GTSNEGO_MSG_DeleteIconActors(u8 *p);
void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoActorSys *p, u32 flag);
void GTSNEGO_MSG_SetScrollState(struct GtsnegoActorSys *p, int state);
void GTSNEGO_MSG_ClearScrollState(struct GtsnegoActorSys *p);
int GTSNEGO_MSG_StepScroll(u8 *p, int *out);
void GTSNEGO_MSG_ScrollAllRows(u8 *p, int flag);
void GTSNEGO_MSG_SetupRowBg(void *actorSys);
void GTSNEGO_MSG_CreateListActor(u8 *p, int n, int k);
void GTSNEGO_MSG_SetListActorPos(u8 *p, int index, int x, int y);
void GTSNEGO_MSG_SetListEntry(u8 *p, void *entry, int index);
void GTSNEGO_MSG_MoveListActor(u8 *p, int index, int delta);
void GTSNEGO_MSG_ScrollListDown(u8 *p, void *q);
void GTSNEGO_MSG_ScrollListUp(u8 *p, void *q);
void GTSNEGO_MSG_FillListRange(u8 *p, void *container, int offset);
int GTSNEGO_MSG_GetListRowY(struct GtsnegoActorSys *p, int index, int count);
int GTSNEGO_MSG_GetListRowYF(struct GtsnegoActorSys *p, int n, int count);
void GTSNEGO_MSG_SetIconY(struct GtsnegoActorSys *p, int index, int count);
int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoActorSys *p,int y,int count);
void GTSNEGO_MSG_CycleIdleAnim(char *p);
void GTSNEGO_MSG_CreateIdleActors(u8 *p);
void GTSNEGO_MSG_DeleteIdleActors(char *p);
void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoActorSys *p,int n);
void GTSNEGO_MSG_CreateIdleUi(u8 *p);
void GTSNEGO_MSG_StepIdleFade(struct GtsnegoActorSys *p);
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
void GTSNEGO_MSG_FlushRowLayer(char *msgCtx);
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

int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoActorSys *actorSys,u32 position){void *obj=actorSys->cursorActor;if(!obj)return 0;CLACT_SetActorAnimSeq(obj,gGtsnegoEntryTable[position][3]);return 1;}

int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoActorSys *actorSys){if(!actorSys->cursorActor)return 0;if((u32)CLACT_GetActorAnimSeq(actorSys->cursorActor)>=29){if(CLACT_IsActorAnimActive(actorSys->cursorActor)==0)return 1;return 0;}return 0;}

void GTSNEGO_MSG_CreateActorAt(u8 *actorSys,u16 x,u16 y,int isRightSide) {
PosRecord actorPos;int i;
for(i=0;i<12;i++) {
if(!*(void **)(actorSys+i*4+0xc4)) {
actorPos.x=x;actorPos.y=y;actorPos.z=isRightSide?2:0;actorPos.a=0;actorPos.b=1;
*(void **)(actorSys+0xc4+i*4)=CLACT_CreateActor((void *)((struct GtsnegoActorSys *)actorSys)->clactUnit,((struct GtsnegoActorSys *)actorSys)->uiChar,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->uiPalette,((struct GtsnegoActorSys *)actorSys)->uiCellAnim,&actorPos,1,((struct GtsnegoActorSys *)actorSys)->heapId);
CLACT_SetActorAutoAnim(*(void **)(actorSys+0xc4+i*4),1);
CLACT_SetActorDrawEnable(*(void **)(actorSys+0xc4+i*4),1);
return;
}
}
}

/*
 * extent: two-byte zero alignment padding follows.
 * lever: base + index*4 + 0xc4 preserves the original add order.
 */
void GTSNEGO_MSG_DeleteActors(u8 *actorSys){int i;for(i=0;i<12;i++){if(*(void **)(actorSys+i*4+0xc4)){CLACT_DeleteActor(*(void **)(actorSys+i*4+0xc4));*(int *)(actorSys+i*4+0xc4)=0;}}}

void GTSNEGO_MSG_SetActorMode(u8 *actorSys,u32 slot){int got;int mode;got=CLACT_GetActorAnimSeq(*(void **)(actorSys+0xc4+slot*4));mode=1;if(got>=2)mode=3;CLACT_SetActorAnimSeq(*(void **)(actorSys+0xc4+slot*4),mode);CLACT_SetActorAutoAnim(*(void **)(actorSys+0xc4+slot*4),1);}

void GTSNEGO_MSG_InitWindows(u8 *actorSys, int includeFirstIcon)
{
    void *arcHandle;
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys, 8);
    GTSNEGO_DISP_Noop(actorSys, 1);
    arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->tileScreenBuf = ARC_UTIL_LoadPaletteDataFromHandle(arcHandle, 21, 0, (void **)(actorSys + 0x11c), ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle, 0, 5, 0, 320, 32, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    arcHandle = ARC_TOOL_CreateHandle(32, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle, 0, 5, 0, 0, 256, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_MSG_CreateCursorActor(actorSys);
    GTSNEGO_MSG_CreateIconActors(actorSys, includeFirstIcon);
    *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->scrollDirty = 1;
}


/*
 * Addresses are Black-image addresses.
 */
void GTSNEGO_MSG_DeleteTileHandle(u8 *actorSys)
{
    void *buf = ((struct GtsnegoActorSys *)actorSys)->tileScreenBuf;
    if (buf) {
        GFL_HEAP_Free(buf);
        *(u32 *)&((struct GtsnegoActorSys *)actorSys)->tileScreenBuf = 0;
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
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoActorSys *actorSys,void *list,int first){int i;for(i=0;i<6;i++){if(GTSNEGO_DISP_GetEntry(list,first+i))GTSNEGO_MSG_DrawTileRow(actorSys,i);else GTSNEGO_MSG_FillTileRow(actorSys,i);}BG_SYS_SetFlagField06(4);}

void GTSNEGO_MSG_TeardownActorList(u8 *actorSys)
{
    void *arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(actorSys + i * 4 + 0x14c)) {
            CLACT_DeleteActor(*(void **)(actorSys + i * 4 + 0x14c));
            *(void **)(actorSys + i * 4 + 0x14c) = 0;
        }
    }
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys, 0);
    GTSNEGO_MSG_DeleteCursorActor(actorSys);
    ARC_TOOL_DeleteHandle(arcHandle);
}

void GTSNEGO_MSG_TeardownTileRows(u8 *actorSys)
{
    void *arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    GTSNEGO_MSG_DeleteTileHandle(actorSys);
    GTSNEGO_MSG_DeleteIconActors(actorSys);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 32, 32, 17);
    BG_SYS_SetFlagField06(6);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle, 2, 5, 0, 256, 256, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle, 18, 4, 0, (u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4), 0, 0, ((struct GtsnegoActorSys *)actorSys)->heapId);
    BG_SYS_SetFlagField06(4);
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
void GTSNEGO_MSG_CreateCursorActor(u8 *actorSys)
{
    PosRecord actorPos;
    actorPos.x = 128; actorPos.y = 200; actorPos.z = 0; actorPos.a = 1; actorPos.b = 1;
    ((struct GtsnegoActorSys *)actorSys)->selectorActor = CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->clactUnit, *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->cursorChar, *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->cursorPalette, *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->cursorCellAnim, &actorPos, 1, ((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->selectorActor, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->selectorActor, 1);
}


void GTSNEGO_MSG_DeleteCursorActor(u8 *actorSys)
{
    void *actor = ((struct GtsnegoActorSys *)actorSys)->selectorActor;
    if (actor)
        CLACT_DeleteActor(actor);
    *(u32 *)&((struct GtsnegoActorSys *)actorSys)->selectorActor = 0;
}

/*
 * lever: declarations x,y,z,b reproduce the descending stack slots; p+i*4+offset keeps the per-element pointer.
 */
void GTSNEGO_MSG_CreateIconActors(u8 *actorSys,int flag)
{
    PosRecord actorPos;
    Triple iconX=gGtsnegoIconX;
    Triple iconY=gGtsnegoIconY;
    Triple iconZ=gGtsnegoIconZ;
    Triple b=gGtsnegoIconW;
    int i;
    for(i=0;i<3;i++) {
        if(flag || i!=0) {
            actorPos.x=iconX.a[i]; actorPos.y=iconY.a[i]; actorPos.z=iconZ.a[i]; actorPos.a=i; actorPos.b=b.a[i];
            *(void **)(actorSys+i*4+0x140)=CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->clactUnit,((struct GtsnegoActorSys *)actorSys)->uiChar,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->uiPalette,((struct GtsnegoActorSys *)actorSys)->uiCellAnim,&actorPos,1,((struct GtsnegoActorSys *)actorSys)->heapId);
            CLACT_SetActorAutoAnim(*(void **)(actorSys+i*4+0x140),1);
            CLACT_SetActorDrawEnable(*(void **)(actorSys+i*4+0x140),1);
        }
    }
}

/*
 * matching: declaring element after i puts the element in r4 and the counter in r5.
 */
void GTSNEGO_MSG_DeleteIconActors(u8 *actorSys)
{
    int i;
    u32 element;
    for (i = 0; i < 3; i++) {
        element = (u32)actorSys + (u32)i * 4;
        if (((struct GtsnegoActorSys *)element)->iconActor != 0) {
            CLACT_DeleteActor(((struct GtsnegoActorSys *)element)->iconActor);
            ((struct GtsnegoActorSys *)element)->iconActor = 0;
        }
    }
}

void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoActorSys *actorSys, u32 flag)
{
    if (actorSys->iconActor != 0) {
        CLACT_RestartActorAnim(actorSys->iconActor);
        CLACT_SetActorAutoAnim(actorSys->iconActor, flag);
    }
}


void GTSNEGO_MSG_SetScrollState(struct GtsnegoActorSys *actorSys, int state)
{
    actorSys->scrollState = state;
    if (state == 2) actorSys->scrollTarget = *(unsigned int *)&actorSys->scrollOffset + 48;
    else if (state == 1) actorSys->scrollTarget = *(unsigned int *)&actorSys->scrollOffset - 48;
}


void GTSNEGO_MSG_ClearScrollState(struct GtsnegoActorSys *actorSys)
{
    *(unsigned int *)&actorSys->scrollState = 0;
}

/*
 * lever: pass the named loaded state to out instead of rematerializing 1 or 2.
 */
int GTSNEGO_MSG_StepScroll(u8 *actorSys, int *out)
{
    int i;
    int state;
    state=((struct GtsnegoActorSys *)actorSys)->scrollState;
    if (state==2) {
        ((struct GtsnegoActorSys *)actorSys)->scrollOffset+=8;
        if (*(int *)&((struct GtsnegoActorSys *)actorSys)->scrollTarget==((struct GtsnegoActorSys *)actorSys)->scrollOffset) {
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
        if (*(int *)&((struct GtsnegoActorSys *)actorSys)->scrollTarget==((struct GtsnegoActorSys *)actorSys)->scrollOffset) {
            *out=state;
            ((struct GtsnegoActorSys *)actorSys)->scrollState=0;
            ((struct GtsnegoActorSys *)actorSys)->scrollOffset+=48;
        }
        for (i=0;i<6;i++) GTSNEGO_MSG_MoveListActor(actorSys,i,8);
        ((struct GtsnegoActorSys *)actorSys)->scrollDirty=1;
    }
    return ((struct GtsnegoActorSys *)actorSys)->scrollState;
}

void GTSNEGO_MSG_ScrollAllRows(u8 *actorSys, int flag)
{
    int i;
    int direction = 1;
    int step;
    if (flag != 0) direction -= 2;
    i = 0;
    step = direction * 48;
    for (; i < 6; i++) GTSNEGO_MSG_MoveListActor(actorSys, i, step);
}

void GTSNEGO_MSG_SetupRowBg(void *actorSys)
{
    BG_SYS_FillScrollArea(4, 3, 0);
    BG_SYS_FillScrollArea(6, 3, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(1);
}

void GTSNEGO_MSG_CreateListActor(u8 *actorSys, int slot, int outfit)
{
    PosRecord actorPos;
    if (*(void **)(actorSys + 0x14c + slot * 4)) CLACT_DeleteActor(*(void **)(actorSys + 0x14c + slot * 4));
    actorPos.x = 0; actorPos.y = 0; actorPos.z = 1; actorPos.a = 10; actorPos.b = 2;
    *(void **)(actorSys + 0x14c + slot * 4) = CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->clactUnit, *(u32 *)(actorSys + (outfit + 6) * 4 + 0x18), *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->listPalette, *(u32 *)(actorSys + (outfit + 25) * 4 + 0x18), &actorPos, 1, ((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(*(void **)(actorSys + 0x14c + slot * 4), 1);
    CLACT_SetActorDrawEnable(*(void **)(actorSys + 0x14c + slot * 4), 0);
}

void GTSNEGO_MSG_SetListActorPos(u8 *actorSys, int index, int x, int y)
{
    Vec pos;
    if (index < 6) {
        pos.x = x;
        pos.y = y;
        CLACT_AddActorSurfacePos(*(void **)((u32)actorSys + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable(*(void **)((u32)actorSys + 0x14c + (u32)index * 4), 1);
    }
}

void GTSNEGO_MSG_SetListEntry(u8 *actorSys, void *entry, int index)
{
    if (entry != 0) {
        GTSNEGO_MSG_CreateListActor(actorSys, index, MYSTATUS_GetOutfit((const struct Sub0200852CObj *)((int)entry)));
        GTSNEGO_MSG_SetListActorPos(actorSys, index, 16, -48 * (1 - index));
    }
}

void GTSNEGO_MSG_MoveListActor(u8 *actorSys, int index, int delta)
{
    Vec pos;
    if (*(void **)((u32)actorSys + 0x14c + (u32)index * 4) != 0) {
        CLACT_GetActorSurfacePos(*(void **)((u32)actorSys + 0x14c + (u32)index * 4), (struct PtS *)&pos, 1);
        pos.y += (s16)delta;
        CLACT_AddActorSurfacePos(*(void **)((u32)actorSys + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
    }
}

void GTSNEGO_MSG_ScrollListDown(u8 *actorSys, void *entry)
{
    int i;
    if (entry) {
        if (((struct GtsnegoActorSys *)actorSys)->listActorFirst) CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->listActorFirst);
        for (i = 0; i < 5; i++) *(void **)(actorSys + 0x14c + i * 4) = *(void **)(actorSys + 0x150 + i * 4);
        ((struct GtsnegoActorSys *)actorSys)->listActorLast = 0;
        GTSNEGO_MSG_SetListEntry(actorSys, entry, 5);
    }
}

void GTSNEGO_MSG_ScrollListUp(u8 *actorSys, void *entry)
{
    int i;
    if (entry) {
        if (((struct GtsnegoActorSys *)actorSys)->listActorLast) CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->listActorLast);
        for (i = 5; i > 0; i--) *(void **)(actorSys + 0x14c + i * 4) = *(void **)(actorSys + 0x148 + i * 4);
        ((struct GtsnegoActorSys *)actorSys)->listActorFirst = 0;
        GTSNEGO_MSG_SetListEntry(actorSys, entry, 0);
    }
}

void GTSNEGO_MSG_FillListRange(u8 *actorSys, void *container, int offset)
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
    return _s32_div_f((int)((u32)index * 132), count);
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
    Vec pos;
    if (actorSys->iconActor != 0) {
        CLACT_GetActorSurfacePos(actorSys->iconActor, (struct PtS *)&pos, 1);
        pos.y = GTSNEGO_MSG_GetListRowY(actorSys, index, count) + 26;
        CLACT_AddActorSurfacePos(actorSys->iconActor, (const struct Vec2 *)(&pos), 1);
    }
}

int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoActorSys *actorSys,int y,int count) { Pt pt; int result; result=0; if(actorSys->iconActor) { CLACT_GetActorSurfacePos(actorSys->iconActor,(struct PtS *)&pt,1); pt.y=y; CLACT_AddActorSurfacePos(actorSys->iconActor,(const struct Vec2 *)(&pt),1); result=GTSNEGO_MSG_GetListRowYF(actorSys,y,count); } return result; }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void GTSNEGO_MSG_CycleIdleAnim(char *actorSys) { u16 next; next=CLACT_GetActorAnimSeq(((struct GtsnegoActorSys *)actorSys)->idleCharActor)+1; if(next>26) next=11; CLACT_SetActorAnimSeq(((struct GtsnegoActorSys *)actorSys)->idleCharActor,next); }

void GTSNEGO_MSG_CreateIdleActors(u8 *actorSys)
{
    Callback c;
    PosRecord actorPos;
    actorPos.x=128; actorPos.y=52; actorPos.z=27; actorPos.a=2; actorPos.b=1;
    ((struct GtsnegoActorSys *)actorSys)->idleFrameActor=CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->clactUnit,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->idleChar,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->idlePalette,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->idleCellAnim,&actorPos,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->idleFrameActor,1);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->idleFrameActor,1);
    actorPos.z=11; actorPos.a=1;
    ((struct GtsnegoActorSys *)actorSys)->idleCharActor=CLACT_CreateActor((void *)*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->clactUnit,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->idleChar,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->idlePalette,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->idleCellAnim,&actorPos,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->idleCharActor,1);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->idleCharActor,1);
    c.n=0; c.p=actorSys; c.f=(void (*)(u8 *))GTSNEGO_MSG_CycleIdleAnim;
    CLACT_ApplyActorAnimCommand(((struct GtsnegoActorSys *)actorSys)->idleCharActor,(const struct Cmd *)(&c));
    BG_SYS_SetMainVisiblePlanes(31);
}

void GTSNEGO_MSG_DeleteIdleActors(char *actorSys) { CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->idleFrameActor,0); CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->idleFrameActor); CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->idleCharActor,0); CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->idleCharActor); }

void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoActorSys *actorSys,int outfit)
{
    Table a=gGtsnegoIdleAnimTable;
    void *arcHandle=ARC_TOOL_CreateHandle(144,actorSys->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,15,0,0,(u16)(actorSys->bgCharLayer0),0,0,actorSys->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    CLACT_SetActorAutoAnim(actorSys->idleCharActor,0);
    CLACT_SetActorAnimSeq(actorSys->idleCharActor,a.a[outfit]+11);
    CLACT_SetActorAnimIndex((int)(actorSys->idleCharActor),4);
    CLACT_SetActorAnimSeq(actorSys->idleFrameActor,28);
    BG_SYS_SetFlagField06(0);
    actorSys->idleFadePos=0;
    actorSys->idleFadeActive=0;
}

void GTSNEGO_MSG_CreateIdleUi(u8 *actorSys)
{
    void *arcHandle=ARC_TOOL_CreateHandle(144,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,14,2,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,13,0,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,16,3,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_MSG_CreateIdleActors(actorSys);
    BG_SYS_SetFlagField06(2); BG_SYS_SetFlagField06(0); BG_SYS_SetFlagField06(3);
    ((struct GtsnegoActorSys *)actorSys)->idleFadePos=0;
    ((struct GtsnegoActorSys *)actorSys)->idleFadeActive=1;
}

void GTSNEGO_MSG_StepIdleFade(struct GtsnegoActorSys *actorSys) { if(actorSys->idleFadeActive) { BG_SYS_FillScrollArea(2,3,actorSys->idleFadePos); actorSys->idleFadePos+=1; } }

/*
 * trailing: 2-byte zero alignment padding at 0x021D770E.
 * lever: indexed pointer sum before the far field offset preserves the base.
 */
void GTSNEGO_MSG_Teardown(u8 *actorSys)
{
    int i;
    void *arcHandle;
    for(i=0;i<6;i++) {
        if(*(void **)(actorSys+i*4+0x14c)) {
            CLACT_SetActorDrawEnable(*(void **)(actorSys+i*4+0x14c),0);
            CLACT_DeleteActor(*(void **)(actorSys+i*4+0x14c));
            *(u32 *)(actorSys+i*4+0x14c)=0;
        }
    }
    GTSNEGO_MSG_DeleteCursorActor(actorSys);
    GTSNEGO_MSG_DeleteTileHandle(actorSys);
    GTSNEGO_MSG_DeleteIdleActors((char *)actorSys);
    GTSNEGO_MSG_DeleteIconActors(actorSys);
    GTSNEGO_MSG_DeleteActors(actorSys);
    arcHandle=ARC_TOOL_CreateHandle((u32)((void *)144),((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,12,0,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,18,4,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(arcHandle,2,5,0,0x100,0x100,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys,0);
    BG_SYS_SetPlaneVisible(2,0);
    BG_SYS_SetFlagField06(0);
    BG_SYS_SetPlaneVisible(3,0);
    ((struct GtsnegoActorSys *)actorSys)->idleFadePos=0;
    ((struct GtsnegoActorSys *)actorSys)->idleFadeActive=0;
}


void GTSNEGO_MSG_DeleteButtons(u8 *msgCtx)
{
    if (((struct GtsnegoMsgCtx *)msgCtx)->buttonMan) {
        BUTTON_MAN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->buttonMan);
        *(u32 *)&((struct GtsnegoMsgCtx *)msgCtx)->buttonMan = 0;
    }
}

/*
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 */
char *GTSNEGO_MSG_Create(u32 heap,u32 msgFileId)
{
    char *p=GFL_HEAP_Alloc(heap,0xd0,1,sGtsnegoMsgHeapName,0xa9);
    ((struct GtsnegoMsgCtx *)p)->heapId=heap;
    BMP_WIN_Init(((struct GtsnegoMsgCtx *)p)->heapId);
    GF_FONT_InitTextColor();
    ((struct GtsnegoMsgCtx *)p)->tcbList=TCBL_Create(((struct GtsnegoMsgCtx *)p)->heapId,((struct GtsnegoMsgCtx *)p)->heapId,1,0);
    ((struct GtsnegoMsgCtx *)p)->printQueue=(void *)PRINTSYS_QUE_Create((void *)(u32)((struct GtsnegoMsgCtx *)p)->heapId);
    ((struct GtsnegoMsgCtx *)p)->windowText=STRBUF_Create(240,((struct GtsnegoMsgCtx *)p)->heapId);
    ((struct GtsnegoMsgCtx *)p)->srcText=STRBUF_Create(240,((struct GtsnegoMsgCtx *)p)->heapId);
    ((struct GtsnegoMsgCtx *)p)->expandedText=STRBUF_Create(240,((struct GtsnegoMsgCtx *)p)->heapId);
    ((struct GtsnegoMsgCtx *)p)->font=GF_FONT_Create(23,0,0,0,((struct GtsnegoMsgCtx *)p)->heapId);
    ((struct GtsnegoMsgCtx *)p)->msgData=MSGDATA_CreateFromArchive(0,2,(u16)msgFileId,(u16)(((struct GtsnegoMsgCtx *)p)->heapId));
    ((struct GtsnegoMsgCtx *)p)->wordSet=WORDSET_Create(6,64,((struct GtsnegoMsgCtx *)p)->heapId);
    ((struct GtsnegoMsgCtx *)p)->taskMenuRes=APP_TASKMENU_RES_Create(5,9,*(u32 *)&((struct GtsnegoMsgCtx *)p)->font,*(u32 *)&((struct GtsnegoMsgCtx *)p)->printQueue,((struct GtsnegoMsgCtx *)p)->heapId);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->windowFrameTiles=BMP_MENUWORK_LoadFrameGfx((void *)1,12,0,((struct GtsnegoMsgCtx *)p)->heapId);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->sysFrameTiles=BMP_MENUWORK_LoadFrameGfx((void *)6,12,0,((struct GtsnegoMsgCtx *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x160,32,((struct GtsnegoMsgCtx *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,0x160,32,((struct GtsnegoMsgCtx *)p)->heapId);
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
void GTSNEGO_MSG_Delete(char *msgCtx)
{
    int i;
    u32 frameTiles;
    frameTiles=((struct GtsnegoMsgCtx *)msgCtx)->windowFrameTiles;
    BG_SYS_DeleteHalf(1,(u16)frameTiles,decodeHighHalfword(frameTiles));
    frameTiles=((struct GtsnegoMsgCtx *)msgCtx)->sysFrameTiles;
    BG_SYS_DeleteHalf(6,(u16)frameTiles,decodeHighHalfword(frameTiles));
    GTSNEGO_MSG_DeleteButtons((u8 *)msgCtx);
    GF_FONT_SetDefaultTextColor();
    MSGDATA_Delete(((struct GtsnegoMsgCtx *)msgCtx)->msgData);
    GF_FONT_Delete(((struct GtsnegoMsgCtx *)msgCtx)->font);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->srcText);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->windowText);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->expandedText);
    GTSNEGO_MSG_DeleteDraw((u8 *)msgCtx);
    if(((struct GtsnegoMsgCtx *)msgCtx)->printStream) {PRINTSYS_PrintStreamDelete(((struct GtsnegoMsgCtx *)msgCtx)->printStream);((struct GtsnegoMsgCtx *)msgCtx)->printStream=0;}
    WORDSET_DeleteStrbufED04(((struct GtsnegoMsgCtx *)msgCtx)->wordSet);
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
    for(i=0;i<12;i++) if(*(void **)(msgCtx+i*4+0x38)) BMP_WIN_Delete(*(void **)(msgCtx+i*4+0x38));
    for(i=0;i<6;i++) if(*(void **)(msgCtx+i*4+0x6c)) BMP_WIN_Delete(*(void **)(msgCtx+i*4+0x6c));
    BMP_WIN_Exit();
    GFL_HEAP_Free(msgCtx);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *msgCtx,u16 msgId)
{
    void *window;
    MSGDATA_ReadString(msgCtx->msgData,msgId,(void *)(*(int *)&msgCtx->windowText));
    if (!msgCtx->messageWindow) msgCtx->messageWindow=(void *)BMP_WIN_Create(1,1,19,30,4,11,1);
    window=msgCtx->messageWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,(void *)(*(int *)&msgCtx->windowText),(void *)(*(int *)&msgCtx->font));
    BMP_MENUWORK_DrawWindow(window,1,(u16)(msgCtx->windowFrameTiles),12);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_SetFlagField06(1);
}

void GTSNEGO_MSG_PrintWindowB(u8 *msgCtx, int msgId)
{
    void *window;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText));
    if (!((struct GtsnegoMsgCtx *)msgCtx)->messageWindow) ((struct GtsnegoMsgCtx *)msgCtx)->messageWindow=(void *)BMP_WIN_Create(1,1,21,30,2,11,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->messageWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText),(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->font));
    BMP_MENUWORK_DrawWindow(window,1,(u16)(((struct GtsnegoMsgCtx *)msgCtx)->windowFrameTiles),12);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_SetFlagField06(1);
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

void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *msgCtx) { if(msgCtx->messageWindow) { BMP_MENUWORK_DrawWindowBorder(msgCtx->messageWindow,2); BMP_WIN_ClearScreen(msgCtx->messageWindow); BG_SYS_SetFlagField06(1); BMP_WIN_Delete(msgCtx->messageWindow); msgCtx->messageWindow=0; } }

void *GTSNEGO_MSG_OpenMenu(char *msgCtx,int position)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)msgCtx)->heapId;
    config.count=2;
    config.entries=msgCtx+0xa8;
    switch(position) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,25,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryColor0=0x39e0;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText1=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,26,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryColor1=0x39e0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&config),((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText1);
    return result;
}

int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *msgCtx) { return BUTTON_MAN_UpdateSlots(msgCtx->buttonMan); }

void GTSNEGO_MSG_DeleteRows(char *msgCtx) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)msgCtx+(u32)i*4); if(((struct GtsnegoMsgCtx *)q)->rowWindow) { BMP_WIN_Delete(((struct GtsnegoMsgCtx *)q)->rowWindow); ((struct GtsnegoMsgCtx *)q)->rowWindow=0; } } GF_FONT_SetTextColor(1,2,0); }

int GTSNEGO_MSG_CreateRow(u8 *msgCtx, int msgId, int x, int y, int width, int bgLayer)
{
    int i;
    void *window;
    for(i=0;i<12;i++) {
        if(!*(void **)(msgCtx+i*4+0x38)) {
            ((void **)(msgCtx+0x38))[i]=(void *)BMP_WIN_Create((u8)bgLayer,(u8)x,(u8)y,(u8)width,2,11,1);
            window=((void **)(msgCtx+0x38))[i];
            BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)window),0);
            MSGDATA_ReadString(*(struct MsgBank **)(msgCtx+0xc),msgId,*(void **)(msgCtx+0x18));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)window),2,2,*(void **)(msgCtx+0x18),*(void **)(msgCtx+0x14));
            BMP_WIN_TransferChars((struct Descriptor *)window);
            BMP_WIN_MakeScreen((struct Cfg *)window);
            return i;
        }
    }
    return 0;
}


int GTSNEGO_MSG_CreateRowEx(int msgCtx, int msgId, int x, int y)
{
    return GTSNEGO_MSG_CreateRow((u8 *)msgCtx, msgId, x, y, 0x14, 6);
}

/*
 * follower: two zero padding bytes at 021D7D2E.
 */
void GTSNEGO_MSG_RedrawRow(char *msgCtx,u16 msgId,int row)
{
    void *q=*(void **)(msgCtx+0x38+4*row);
    if(q) {
        BMP_Clear(BMP_WIN_GetBmp(q),0);
        MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText));
        PRINTSYS_Print(BMP_WIN_GetBmp(q),2,2,(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText),(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->font));
        BMP_WIN_TransferChars(q);
    }
}

void GTSNEGO_MSG_FlushRowLayer(char *msgCtx) { BG_SYS_SetFlagField06(6); }

void GTSNEGO_MSG_ClearRows(char *msgCtx) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)msgCtx+(u32)i*4); if(((struct GtsnegoMsgCtx *)q)->rowWindow) { BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(((struct GtsnegoMsgCtx *)q)->rowWindow)); BMP_MENUWORK_DrawWindowBorder(((struct GtsnegoMsgCtx *)q)->rowWindow,2); BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)q)->rowWindow); } } }

void GTSNEGO_MSG_CreateYesNoUi(char *msgCtx,int callback,int callbackWork)
{
    GTSNEGO_MSG_DeleteRows(msgCtx);
    GTSNEGO_MSG_CreateRow((unsigned char *)msgCtx,0,8,7,16,6);
    GTSNEGO_MSG_CreateRow((unsigned char *)msgCtx,1,8,13,16,6);
    GTSNEGO_MSG_FlushRowLayer(msgCtx);
    GTSNEGO_MSG_DeleteButtons((unsigned char *)msgCtx);
    ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan=BUTTON_MAN_Create((u8 *)gGtsnegoButtonYesNo,callback,callbackWork,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
}

/*
 * follower: existing 021D7E88, 021D7E9C, 021D7EB0 files remain separate.
 */
void GTSNEGO_MSG_CreateListUi(char *msgCtx,int callback,int callbackWork,int rowAIndex,int rowBIndex,int rowCIndex)
{
    GTSNEGO_MSG_DeleteRows(msgCtx);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx((int)msgCtx,2,0,0);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx((int)msgCtx,3,3,6);
    GTSNEGO_MSG_CreateRowEx((int)msgCtx,23,1,11);
    GTSNEGO_MSG_CreateRowEx((int)msgCtx,24,1,16);
    GF_FONT_SetTextColor(1,2,0);
    *(int *)&((struct GtsnegoMsgCtx *)msgCtx)->rowAHandle=GTSNEGO_MSG_CreateRowEx((int)msgCtx,gGtsnegoRowLabelA[rowAIndex],13,6);
    *(int *)&((struct GtsnegoMsgCtx *)msgCtx)->rowBHandle=GTSNEGO_MSG_CreateRowEx((int)msgCtx,gGtsnegoRowLabelB[rowBIndex],16,11);
    *(int *)&((struct GtsnegoMsgCtx *)msgCtx)->rowCHandle=GTSNEGO_MSG_CreateRowEx((int)msgCtx,gGtsnegoRowLabelB[rowCIndex],16,16);
    GTSNEGO_MSG_FlushRowLayer(msgCtx);
    GTSNEGO_MSG_DeleteButtons((unsigned char *)msgCtx);
    ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan=BUTTON_MAN_Create((u8 *)gGtsnegoButtonList,callback,callbackWork,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
}

/*
 * follower: separately filed 021D7E9C.
 */
void GTSNEGO_MSG_RedrawRowA(char *msgCtx,int index) {GTSNEGO_MSG_RedrawRow(msgCtx,gGtsnegoRowLabelA[index],*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->rowAHandle);}

/*
 * follower: separately filed 021D7EB0.
 */
void GTSNEGO_MSG_RedrawRowB(char *msgCtx,int index) {GTSNEGO_MSG_RedrawRow(msgCtx,gGtsnegoRowLabelB[index],*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->rowBHandle);}

void GTSNEGO_MSG_RedrawRowC(char *msgCtx,int index) {GTSNEGO_MSG_RedrawRow(msgCtx,gGtsnegoRowLabelB[index],*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->rowCHandle);}

void GTSNEGO_MSG_DeleteButtonsKeep(u8 *msgCtx) { GTSNEGO_MSG_DeleteButtons(msgCtx); }

void *GTSNEGO_MSG_CreateTooltip(char *msgCtx,u16 msgId)
{
    int width;
    void *result;
    void *text;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryColor0=0x39e3;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryType0=0;
    width=((int)GF_FONT_MeasureWidestLine(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0,(int)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->font),(int)0)+32)/16;
    result=APP_TASKMENU_WIN_CreateEx((u32)(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes),(u32)(msgCtx+0xa8),(u8)(16-width),(u8)21,width*2,3,(int)0,(int)1,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0);
    return result;
}

void GTSNEGO_MSG_PrintTooltip(char *msgCtx,u16 msgId)
{
    void *window;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,msgId,(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText));
    if(!((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow) ((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow=(void *)BMP_WIN_Create(1,1,13,14,3,4,1);
    window=((struct GtsnegoMsgCtx *)msgCtx)->tooltipWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),2,3,(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText),(void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->font));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
}

/*
 * follower: two zero padding bytes at 021D80D2.
 */
void GTSNEGO_MSG_PrintEntry(char *msgCtx,void *status)
{
    u32 language,version,checkedLanguage,checkedVersion;
    void *window;
    language=MYSTATUS_GetLanguage(status);
    version=MYSTATUS_GetVersion(status);
    checkedLanguage=BMP_OAM_CheckRangeGetId(language,version,MYSTATUS_GetGender(status));
    checkedVersion=BMP_OAM_CheckRangeGetMin(language,version,MYSTATUS_GetGender(status));
    if(language==checkedLanguage && version==checkedVersion) {
        WORDSET_SetSlotFromMsgE7(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,0,MYSTATUS_GetLanguage(status));
        language=MYSTATUS_GetLanguage(status);
        WORDSET_DeleteMsgdataF094(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,1,language,MYSTATUS_GetVersion(status));
    } else {
        WORDSET_SetSlotFromMsgE7(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,0,0);
        WORDSET_DeleteMsgdataF094(((struct GtsnegoMsgCtx *)msgCtx)->wordSet,1,0,0);
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
    BG_SYS_SetFlagField06(1);
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
        BG_SYS_SetFlagField06(1);
        BMP_WIN_Delete(msgCtx->entryWindow);
        msgCtx->entryWindow=0;
    }
}

int GTSNEGO_MSG_PrintListEntry(char *msgCtx, void *status, int row)
{
    void **listWindows=(void **)(msgCtx+0x6c);
    void *window;
    if(!listWindows[row]) listWindows[row]=(void *)BMP_WIN_Create((u8)6,(u8)6,(u8)(row*6+1),(u8)24,4,11,1);
    window=listWindows[row];
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    STRBUF_Clear(*(void **)(msgCtx+0x20));
    STRBUF_Clear(*(void **)(msgCtx+0x18));
    WORDSET_SetSlotMyStatus(*(void **)(msgCtx+0x10),0,status);
    WORDSET_SetSlotNumber(*(void **)(msgCtx+0x10),1,MYSTATUS_GetIdLow16(status),5,2,1);
    WORDSET_SetSlotFromMsgE7(*(void **)(msgCtx+0x10),2,MYSTATUS_GetLanguage(status));
    MSGDATA_ReadString(*(void **)(msgCtx+0xc),28,*(void **)(msgCtx+0x20));
    WORDSET_CopyTaggedText(*(void **)(msgCtx+0x10),*(void **)(msgCtx+0x18),*(void **)(msgCtx+0x20));
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,*(void **)(msgCtx+0x18),*(void **)(msgCtx+0x14));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    return 0;
}

void GTSNEGO_MSG_PrintList(char *msgCtx,void *list)
{
    int i;
    void *entry;
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRow((u8 *)msgCtx,30,0,0,20,5);
    for(i=0;i<3;i++) {
        entry=GTSNEGO_DISP_GetEntry(list,i);
        if(entry) GTSNEGO_MSG_PrintListEntry(msgCtx,entry,i+2);
    }
    BG_SYS_SetFlagField06(5);
}

void GTSNEGO_MSG_PrintListEntryAt(char *msgCtx,void *list,int index) { GTSNEGO_MSG_PrintListEntry(msgCtx,GTSNEGO_DISP_GetEntry(list,index),5); BG_SYS_SetFlagField06(6); }

void GTSNEGO_MSG_ShiftListDown(char *msgCtx)
{
    int i;
    char *slot;
    if(((struct GtsnegoMsgCtx *)msgCtx)->listWindow) {BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->listWindow);((struct GtsnegoMsgCtx *)msgCtx)->listWindow=0;}
    for(i=1;i<6;i++) {
        slot=msgCtx+4*i;
        if(((struct GtsnegoMsgCtx *)slot)->listWindow) {
            BMP_WIN_SetPosY(((struct GtsnegoMsgCtx *)slot)->listWindow,BMP_WIN_GetPosY(((struct GtsnegoMsgCtx *)slot)->listWindow)-6);
            BMP_WIN_MakeScreen(((struct GtsnegoMsgCtx *)slot)->listWindow);
        }
    }
    BG_SYS_SetFlagField06(6);
    for(i=0;i<5;i++) *(void **)(msgCtx+0x6c+4*i)=*(void **)(msgCtx+0x70+4*i);
    ((struct GtsnegoMsgCtx *)msgCtx)->lastListWindow=0;
}

void GTSNEGO_MSG_PrintListRange(char *msgCtx,void *list,int start) { int i; void *entry; for(i=0;i<6;i++) { if((int)((u32)i+(u32)start)>=0) { entry=GTSNEGO_DISP_GetEntry(list,(int)((u32)i+(u32)start)); if(entry) GTSNEGO_MSG_PrintListEntry(msgCtx,entry,i); } } BG_SYS_SetFlagField06(6); }

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void GTSNEGO_MSG_PrintListEntryN(char *msgCtx,void *list,int index)
{
    GTSNEGO_MSG_PrintListEntry(msgCtx,GTSNEGO_DISP_GetEntry(list,index),0);
    BG_SYS_SetFlagField06(6);
}

void GTSNEGO_MSG_ShiftListUp(char *msgCtx)
{
    int i;
    char *slot;
    if(((struct GtsnegoMsgCtx *)msgCtx)->lastListWindow) {BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->lastListWindow);((struct GtsnegoMsgCtx *)msgCtx)->lastListWindow=0;}
    for(i=0;i<6;i++) {
        slot=msgCtx+4*i;
        if(((struct GtsnegoMsgCtx *)slot)->listWindow) {
            BMP_WIN_SetPosY(((struct GtsnegoMsgCtx *)slot)->listWindow,BMP_WIN_GetPosY(((struct GtsnegoMsgCtx *)slot)->listWindow)+6);
            BMP_WIN_MakeScreen(((struct GtsnegoMsgCtx *)slot)->listWindow);
        }
    }
    BG_SYS_SetFlagField06(6);
    for(i=5;i>0;i--) *(void **)(msgCtx+0x6c+4*i)=*(void **)(msgCtx+0x68+4*i);
    ((struct GtsnegoMsgCtx *)msgCtx)->listWindow=0;
}

void *GTSNEGO_MSG_OpenMenuB(char *msgCtx,int position)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)msgCtx)->heapId;
    config.count=2;
    config.entries=msgCtx+0xa8;
    switch(position) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,27,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryColor0=0x39e0;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryType0=0;
    text=STRBUF_Create(100,((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText1=text;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData,33,text);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryColor1=0x39e0;
    *(int *)&((struct GtsnegoMsgCtx *)msgCtx)->menuEntryType1=0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&config),((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText1);
    return result;
}


void GTSNEGO_MSG_CloseMenu(int taskMenu)
{
    if (taskMenu != 0) {
        *(volatile u16 *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu((struct TaskMenu *)taskMenu);
    }
}

void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *msgCtx,void *actorSys)
{
    if(!msgCtx->pmsDraw)
        msgCtx->pmsDraw=PMS_DRAW_Create(GTSNEGO_DISP_GetUnit(actorSys),0,(u32)(msgCtx->printQueue),(u32)(msgCtx->font),8,4,msgCtx->heapId);
}


void GTSNEGO_MSG_DeleteDraw(u8 *msgCtx)
{
    if (((struct GtsnegoMsgCtx *)msgCtx)->pmsDraw) {
        PMS_DRAW_Delete(((struct GtsnegoMsgCtx *)msgCtx)->pmsDraw);
        *(u32 *)&((struct GtsnegoMsgCtx *)msgCtx)->pmsDraw = 0;
    }
}

void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *msgCtx, void *sentence)
{
    Pair c = gGtsnegoMsgDrawConfig;
    void *window;
    if (!msgCtx->drawWindow) msgCtx->drawWindow = (void *)BMP_WIN_Create(1, 1, 15, 30, 5, 11, 1);
    window = msgCtx->drawWindow;
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PMS_DRAW_SetNullColorPalette(msgCtx->pmsDraw, 0);
    PMS_DRAW_SetPrintColor(msgCtx->pmsDraw, 0x3c40);
    PMS_DRAW_PrintOffset(msgCtx->pmsDraw, (u32)window, sentence, 0, (u32)(&c));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_SetFlagField06(1);
}

void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *msgCtx, u16 msgId)
{
    void *window;
    MSGDATA_ReadString(msgCtx->msgData, msgId, (void *)(*(int *)&msgCtx->srcText));
    if (!msgCtx->statusWindow) msgCtx->statusWindow = (void *)BMP_WIN_Create(1, 0, 0, 14, 2, 11, 1);
    window = msgCtx->statusWindow;
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 2, 2, (void *)(*(int *)&msgCtx->srcText), (void *)(*(int *)&msgCtx->font));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_SetFlagField06(1);
}

void GTSNEGO_MSG_CreateConfirmUi(u8 *msgCtx, int callback, int callbackWork)
{
    void *label = STRBUF_Create(100, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0 = label;
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData, 15, label);
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryColor0 = 0x39e3;
    ((struct GtsnegoMsgCtx *)msgCtx)->menuEntryType0 = 0;
    ((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin = APP_TASKMENU_WIN_CreateEx((u32)(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuRes), (u32)(msgCtx + 0xa8), 10, 21, 12, 3, 0, 1, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    if (!UI_GetInputMode()) APP_TASKMENU_WIN_SetActive(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin, 1);
    STRBUF_Delete(((struct GtsnegoMsgCtx *)msgCtx)->menuEntryText0);
    GTSNEGO_MSG_DeleteButtons(msgCtx);
    ((struct GtsnegoMsgCtx *)msgCtx)->buttonMan = BUTTON_MAN_Create((u8 *)gGtsnegoButtonConfirm, callback, callbackWork, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
}


void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *msgCtx)
{
    APP_TASKMENU_WIN_SetDecide(msgCtx->taskMenuWin, 1);
}


void GTSNEGO_MSG_DeleteConfirmWindow(u8 *msgCtx)
{
    APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin);
    BG_SYS_SetFlagField06(5);
    *(u32 *)&((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin = 0;
}

int GTSNEGO_MSG_IsConfirmFinished(u8 *msgCtx)
{
    if(APP_TASKMENU_WIN_IsFinish(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin)){
        GTSNEGO_MSG_DeleteConfirmWindow((u8 *)((int)msgCtx));
        return 1;
    }
    return 0;
}

void GTSNEGO_MSG_PrintPair(char *msgCtx,int unused,u32 tradeCount)
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

void GTSNEGO_MSG_PrintSingle(char *msgCtx, void *status)
{
    void *window;
    WORDSET_SetSlotMyStatus(((struct GtsnegoMsgCtx *)msgCtx)->wordSet, 0, status);
    MSGDATA_ReadString(((struct GtsnegoMsgCtx *)msgCtx)->msgData, 37, (void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->expandedText));
    WORDSET_CopyTaggedText(((struct GtsnegoMsgCtx *)msgCtx)->wordSet, (void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText), (void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->expandedText));
    if (!((struct GtsnegoMsgCtx *)msgCtx)->singleWindow) ((struct GtsnegoMsgCtx *)msgCtx)->singleWindow = (void *)BMP_WIN_Create(1, 11, 10, 10, 3, 11, 1);
    window = ((struct GtsnegoMsgCtx *)msgCtx)->singleWindow;
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(1, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 0, 0, (void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->srcText), (void *)(*(int *)&((struct GtsnegoMsgCtx *)msgCtx)->font));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
}

void GTSNEGO_MSG_PrintSummary(char *msgCtx,void *status,u32 tradeCount)
{
    GTSNEGO_MSG_PrintSingle(msgCtx,(void *)status);
    GTSNEGO_MSG_PrintPair(msgCtx,36,tradeCount);
    GTSNEGO_MSG_PrintTooltip(msgCtx,41);
    GTSNEGO_MSG_PrintEntry(msgCtx,status);
    GTSNEGO_MSG_PrintWindowB((u8 *)msgCtx,17);
}


void GTSNEGO_MSG_DeleteAll(char *msgCtx)
{
    int i;

    if (((struct GtsnegoMsgCtx *)msgCtx)->statusWindow != 0) {
        BMP_MENUWORK_DrawWindowBorder(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow, 2);
        BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow);
        BG_SYS_SetFlagField06(1);
        BMP_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->statusWindow);
        ((struct GtsnegoMsgCtx *)msgCtx)->statusWindow = 0;
    }
    if (((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin != 0) {
        APP_TASKMENU_WIN_Delete(((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin);
        ((struct GtsnegoMsgCtx *)msgCtx)->taskMenuWin = 0;
    }
    for (i = 0; i < 6; i++) {
        char *q = msgCtx + i * 4;

        if (((struct GtsnegoMsgCtx *)q)->listWindow != 0) {
            BMP_WIN_ClearScreen(((struct GtsnegoMsgCtx *)q)->listWindow);
            BMP_WIN_Delete(((struct GtsnegoMsgCtx *)q)->listWindow);
            ((struct GtsnegoMsgCtx *)q)->listWindow = 0;
        }
    }
    GTSNEGO_MSG_ClearRows(msgCtx);
    GTSNEGO_MSG_DeleteRows(msgCtx);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x160, 0x20, ((struct GtsnegoMsgCtx *)msgCtx)->heapId);
    BG_SYS_SetFlagField06(5);
}
