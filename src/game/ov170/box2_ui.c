/*
 * file:     box2_ui.c
 * unit:     yes
 * function: BOX2_UI_CreatePartyActors, BOX2_UI_ToggleSlotPair, BOX2_UI_LayoutPartySlots, BOX2_UI_RefreshBoxName, BOX2_UI_MoveSlotIcon, BOX2_UI_SetCloseButtonPos, BOX2_UI_RefreshBoxHeader, BOX2_UI_FindSlotPos, BOX2_UI_DrawSlot, BOX2_UI_DrawAllSlots, BOX2_UI_DrawSlotByName, BOX2_UI_UploadSlotChar, BOX2_UI_FindAndDrawSlot, BOX2_UI_ReplaceColorIndex, BOX2_UI_LoadMonIcon, BOX2_UI_AddSlotIcon, BOX2_UI_HideSlotIcon, BOX2_UI_DeleteSlotIcon, BOX2_UI_ShowMiniIcon, BOX2_UI_SetMiniIconVisible, BOX2_UI_DeleteSlotObjects, BOX2_UI_HideSlots678, BOX2_UI_CreateBmpOam, BOX2_UI_DeleteBmpOam, BOX2_UI_SetSlotOamEnabled, BOX2_UI_GetSlotOamEnabled, BOX2_UI_MoveSlotOam, BOX2_UI_ShiftSlotOams, BOX2_UI_CreateCursor, BOX2_UI_MoveCursor, BOX2_UI_DeleteSound, BOX2_UI_SetCursorPos, BOX2_UI_UpdateCursor, BOX2_UI_ShowCursor, BOX2_UI_HideCursor, BOX2_UI_SetCursorSeq, BOX2_UI_PlayAndUpdateCursor, BOX2_UI_Dummy, BOX2_UI_UpdateCursorInputA, BOX2_UI_CursorTagA, BOX2_UI_PlaceCursorAtIcon, BOX2_UI_PlaceCursorAtMon, BOX2_UI_UpdateCursorInputB, BOX2_UI_CursorTagB, BOX2_UI_UpdateCursorInputC, BOX2_UI_SetCursorSeqB, BOX2_UI_CursorTagC, BOX2_UI_SelectSlot, BOX2_UI_PickSlot, BOX2_UI_ConfirmSlot, BOX2_UI_CursorInputLeft, BOX2_UI_UpdateCursorInputD, BOX2_UI_SetCursorSeqC, BOX2_UI_CursorTagD, BOX2_UI_CursorInputRight, BOX2_UI_PickSlotB, BOX2_UI_ConfirmSlotB, BOX2_UI_UpdateCursorInputE, BOX2_UI_SetCursorSeqD, BOX2_UI_CursorTagE, BOX2_UI_UpdateCursorInputF, BOX2_UI_SetCursorSeqE, BOX2_UI_CursorTagF, BOX2_UI_SetCursorSeqF, BOX2_UI_PlayAndUpdateCursorB, BOX2_UI_SetCursorSeqG, BOX2_UI_PlayAndUpdateCursorC, BOX2_UI_PickIconSlot, BOX2_UI_MoveCursorToHeld, BOX2_UI_UpdateCursorInputG, BOX2_UI_SetCursorSeqH, BOX2_UI_CursorTagG, BOX2_UI_UpdateCursorInputH, BOX2_UI_SetCursorSeqI, BOX2_UI_CursorTagH, BOX2_UI_CursorInputPage, BOX2_UI_SetCursorSeqJ, BOX2_UI_CursorTagI, BOX2_UI_MoveCursorBetweenIcons, BOX2_UI_PlaceCursorBetween, BOX2_UI_HitTableTrg, BOX2_UI_HitTableCont, BOX2_UI_HitTablePoint, BOX2_UI_GetPartySlotHit, BOX2_UI_GetPartySlotPoint, BOX2_UI_GetHandSlotHit, BOX2_UI_GetBodySlotHit, BOX2_UI_GetCloseButtonHit, BOX2_UI_GetExitButtonHit, BOX2_UI_GetExitButtonPoint, BOX2_UI_GetBackButtonPoint, BOX2_UI_GetGridSlotPoint, BOX2_UI_GetPageButtonHit, BOX2_UI_GetPageButtonHit2, BOX2_UI_InitWindowFrames, BOX2_UI_DeleteWindowFrames, BOX2_UI_SetFrameData, BOX2_UI_PutTopBarOpen, BOX2_UI_PutTopBarClosed, BOX2_UI_PutBottomBarOpen, BOX2_UI_PutBottomBarClosed, BOX2_UI_CloseBar, BOX2_UI_OpenBar, BOX2_UI_SlideBarIn, BOX2_UI_SlideBarOut, BOX2_UI_UpdateBarMove, BOX2_UI_IsTopBarOpen, BOX2_UI_IsTopBarClosed, BOX2_UI_IsTopBarMid, BOX2_UI_PutSlotFrames, BOX2_UI_PutListFrames, BOX2_UI_ResetSlotFrames, BOX2_UI_CloseListPack, BOX2_UI_OpenListPack, BOX2_UI_UpdateListPacks, BOX2_UI_IsListOpen, BOX2_UI_IsListClosed, BOX2_UI_AddFadeFrame, BOX2_UI_PutFadeFrame, BOX2_UI_ShowWindowA, BOX2_UI_HideWindowA, BOX2_UI_ShowWindowB, BOX2_UI_HideWindowB, BOX2_UI_PutTopBarThenClose, BOX2_UI_RepenTopBar, BOX2_UI_UpdateTopBarMove, BOX2_UI_PutInfoBar, BOX2_UI_CloseInfoBar, BOX2_UI_IsInfoBarOpen
 * address:  0x021ED824
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021EFD1C 0x021EFD1C data a4
 *   BOX2_SEQ_CreateActorFromDesc 0x021EBEE0 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb  ov170
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BMP_OAM_GetPos 0x020258E8 thumb
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BOX2_MAIN_WrapOffset 0x021DEB14 thumb ov170
 *   BOX2_SEQ_DrawMonName 0x021EB874 thumb ov170
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb ov170
 *   g_021EFCEC  0x021EFCEC  data  ov170
 *   func_02007A18  0x02007A18  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   MIi_CpuClear16  0x02082A48  arm
 *   BOX2_SEQ_GetActorDrawEnable 0x021EC01C thumb
 *   d_021EFCD8 0x021EFCD8 data a2
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   BOX2_SEQ_SetActorAutoAnim 0x021EBFCC thumb
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BMP_Create 0x02043678 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_GetEnabled  0x020257C4  thumb
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   d_021F02F0 0x021F02F0 data a4
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   CURSOR_MOVE_GetEntry 0x0202616C thumb
 *   BOX2_SEQ_RefreshHandSlot  0x021ECC1C  thumb  ov170
 *   BOX2_MAIN_SetSeqParam  0x021DC9B4  thumb  ov170
 *   BOX2_MAIN_SceneApplyScroll  0x021E066C  thumb  ov170
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   d_021F0188  0x021F0188  data
 *   d_021F0DCC  0x021F0DCC  data
 *   d_021F0370  0x021F0370  data
 *   KEY_GetRepeat 0x0203633C arm
 *   BOX2_MAIN_PlayCursorSound 0x021DD238 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   func_02030734 0x02030734 arm
 *   d_021F1418 0x021F1418 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F0020 0x021F0020 data a4
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 *   g_021F0DCC  0x021F0DCC  data  ov170
 *   d_021F0F40 0x021F0F40 data
 *   d_021F0040 0x021F0040 data
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   d_021F0034 0x021F0034 data a1
 *   d_021F0024 0x021F0024 data a1
 *   d_021F002C 0x021F002C data a4
 *   d_021F0F58 0x021F0F58 data
 *   BOX2_SEQ_AddTextFrame 0x021EB744 thumb ov170
 *   BOX2_SEQ_AddMsgFrame 0x021EB79C thumb ov170
 *   BOX2_SEQ_AddNameFrame 0x021EB7C8 thumb ov170
 *   BOX2_SEQ_PutNameFrame 0x021EB95C thumb ov170
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_Delete  0x0202CA0C  thumb  ov170
 *   BGWINFRM_UpdateMove 0x0202CDD4 thumb
 *   BOX2_SEQ_MoveActorToWindow 0x021EC8E4 thumb
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   BGWINFRM_SetFrameData  0x0202CAC4  thumb  arm9
 *   BGWINFRM_SetFrameDataArc  0x0202CAE4  thumb  arm9
 *   CLACT_TransferCharacterPart  0x0204AA94  arm  arm9
 *   CLACT_GetActorCharacterIndex  0x0204B7F0  arm  arm9
 *   BMP_OAM_DeleteSys  0x02025588  thumb  arm9
 *   BMP_OAM_Delete  0x0202570C  thumb  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BG_SYS_GetBuf  0x0204162C  arm  arm9
 */
#include "box2_types.h"

struct WinMgr;
struct Grid;
struct BmpOam;
struct Personal;
struct Sav;
struct Sub020079BCEntry;
struct Bmp;
struct Sys;
struct Bmp;
struct CursorMoveObj;
struct Sound;
struct Ctx;
typedef struct { short x, y; int b, c, d, e; short f, g; } Desc;



typedef signed short   s16;



struct Param {void *bmp; short x,y; u32 f8,fc; u8 f10,f11; u16 f12;u32 f14;};

typedef struct { unsigned a, b; } U32Pair;

typedef struct { unsigned char a, b, pad[10]; } E;

typedef struct {
    int pad[9];
    int x24;
} Top;

typedef struct {
    unsigned char x,y,dx,dy;
    unsigned negx:1;
    unsigned negy:1;
    unsigned steps:30;
} Motion;

typedef struct { unsigned char a,b,c,d; } Bytes;

typedef struct { Bytes first, second; } Object;

extern void *BOX2_SEQ_CreateActorFromDesc(BoxWork *, const Desc *);
extern void BOX2_SEQ_SetActorDrawEnable(BoxWork *, int, int);
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void BOX2_SEQ_AddActorSurfacePos(BoxWork *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_GetActorSurfacePos(BoxWork *, int, short *, short *, unsigned short);
extern void BMP_OAM_GetPos(struct BmpOam *p, s16 *out_x, s16 *out_y);
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
extern unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);
extern void BOX2_SEQ_DrawMonName(char **, unsigned, int);
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void MI_CpuCopy8(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern int BOX2_MAIN_GetBoxFormId(BoxTask *p, int box);
extern u16 CLACT_GetActorCharacterIndex(u8 *p);
extern void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void MIi_CpuClear16(u32 value, void *dest, u32 size);
extern u32 BOX2_SEQ_GetActorDrawEnable(BoxWork *p, int i);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
extern void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i);
extern void BOX2_SEQ_SetActorAutoAnim(BoxWork *p, int i, int v);
extern void *BMP_OAM_CreateSys(u32,void *);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Bmp *p);
extern void BMP_OAM_DeleteSys(void *p);
extern int BMP_OAM_GetEnabled(const int *p);
extern u8 func_020355C4(void);
extern struct CursorMoveObj *CURSOR_MOVE_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void CURSOR_MOVE_EnableInput(struct CursorMoveObj *obj);
extern void BOX2_SEQ_SetCursorDraw(char **, int);
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void CURSOR_MOVE_Delete(void);
extern void *CURSOR_MOVE_GetEntry(void **obj, u32 idx);
extern void BOX2_SEQ_RefreshHandSlot(BoxTask *p);
extern void BOX2_MAIN_SetSeqParam(BoxWork *p, int v);
extern int BOX2_MAIN_SceneApplyScroll(BoxTask *p);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern unsigned int KEY_GetRepeat(void);
extern void BOX2_MAIN_PlayCursorSound(BoxTask *p);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int TOUCHPANEL_HitTrg(const void *);
extern int TOUCHPANEL_HitCont(const void *);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BOX2_SEQ_AddTextFrame(BoxWork *);
extern void BOX2_SEQ_AddMsgFrame(unsigned char *p);
extern void BOX2_SEQ_AddNameFrame(char *);
extern void BOX2_SEQ_PutNameFrame(char *);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
extern void BOX2_SEQ_MoveActorToWindow(BoxTask *p);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern u32 BG_SYS_GetBuf(int channel);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32 idx, const void *src);
void BOX2_UI_CreatePartyActors(BoxWork *p);
void BOX2_UI_ToggleSlotPair(BoxWork *p, int a);
void BOX2_UI_LayoutPartySlots(BoxTask *p);
void BOX2_UI_RefreshBoxName(unsigned char *p);
void BOX2_UI_MoveSlotIcon(BoxTask *p, int d);
void BOX2_UI_SetCloseButtonPos(BoxWork *a);
void BOX2_UI_RefreshBoxHeader(BoxTask *p);
void BOX2_UI_FindSlotPos(BoxWork *a0, int a1, short *a2, short *a3);
void BOX2_UI_DrawSlot(BoxTask *p, int i);
void BOX2_UI_DrawAllSlots(int p);
void BOX2_UI_DrawSlotByName(char *p, int a);
void BOX2_UI_UploadSlotChar(BoxTask *p, int a, int i);
void BOX2_UI_FindAndDrawSlot(BoxTask *p, int a, int b);
void BOX2_UI_ReplaceColorIndex(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n);
void BOX2_UI_LoadMonIcon(int **a, int box, u8 *dest);
void BOX2_UI_AddSlotIcon(BoxTask *p, int d);
void BOX2_UI_HideSlotIcon(BoxTask *p, int d);
void BOX2_UI_DeleteSlotIcon(BoxTask *p);
void BOX2_UI_ShowMiniIcon(BoxTask *p, int i);
void BOX2_UI_SetMiniIconVisible(BoxTask *p, int a, int b);
void BOX2_UI_DeleteSlotObjects(BoxTask *p, int a, int b, int c);
void BOX2_UI_HideSlots678(BoxTask *p);
void BOX2_UI_CreateBmpOam(BoxWork *p);
void BOX2_UI_DeleteBmpOam(char *p);
void BOX2_UI_SetSlotOamEnabled(BoxWork *p, int i, int v);
int BOX2_UI_GetSlotOamEnabled(BoxWork *a, int i);
void BOX2_UI_MoveSlotOam(BoxWork *p, int i, int flag);
void BOX2_UI_ShiftSlotOams(BoxWork *p, int d);
void BOX2_UI_CreateCursor(char **p);
void BOX2_UI_MoveCursor(char **p, int idx, int v);
void BOX2_UI_DeleteSound(int *p);
void BOX2_UI_SetCursorPos(char **p, unsigned idx);
void BOX2_UI_UpdateCursor(char *p, int v);
void BOX2_UI_ShowCursor(BoxTask *p, int v);
void BOX2_UI_HideCursor(BoxTask *p);
void BOX2_UI_SetCursorSeq(BoxTask *p, int a, int b);
void BOX2_UI_PlayAndUpdateCursor(BoxTask *p, unsigned int a);
void BOX2_UI_Dummy(void);
unsigned BOX2_UI_UpdateCursorInputA(BoxTask *p);
void BOX2_UI_CursorTagA(void *a, int tag);
void BOX2_UI_PlaceCursorAtIcon(BoxTask *p, unsigned idx);
void BOX2_UI_PlaceCursorAtMon(BoxTask *p, unsigned int i);
unsigned BOX2_UI_UpdateCursorInputB(BoxTask *p);
void BOX2_UI_CursorTagB(void *a, int tag);
unsigned BOX2_UI_UpdateCursorInputC(BoxTask *p);
void BOX2_UI_SetCursorSeqB(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagC(void *a, int tag);
void BOX2_UI_SelectSlot(BoxTask *p, unsigned r);
void BOX2_UI_PickSlot(BoxTask *p, int a, int b);
void BOX2_UI_ConfirmSlot(BoxTask *p, unsigned r);
unsigned BOX2_UI_CursorInputLeft(BoxTask *p);
unsigned BOX2_UI_UpdateCursorInputD(BoxTask *p);
void BOX2_UI_SetCursorSeqC(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagD(void *a, int tag);
unsigned BOX2_UI_CursorInputRight(BoxTask *p);
void BOX2_UI_PickSlotB(BoxTask *p, int a, int b);
void BOX2_UI_ConfirmSlotB(BoxTask *p, unsigned r);
unsigned BOX2_UI_UpdateCursorInputE(BoxTask *p);
void BOX2_UI_SetCursorSeqD(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagE(void *a, int tag);
unsigned BOX2_UI_UpdateCursorInputF(BoxTask *p);
void BOX2_UI_SetCursorSeqE(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagF(void *a, int tag);
void BOX2_UI_SetCursorSeqF(BoxTask *p, int a, int b);
void BOX2_UI_PlayAndUpdateCursorB(BoxTask *p, unsigned int a);
void BOX2_UI_SetCursorSeqG(BoxTask *p, int a, int b);
void BOX2_UI_PlayAndUpdateCursorC(BoxTask *p, unsigned int a);
void BOX2_UI_PickIconSlot(BoxTask *p, int k, int v);
void BOX2_UI_MoveCursorToHeld(BoxTask *p, int a);
unsigned BOX2_UI_UpdateCursorInputG(BoxTask *p);
void BOX2_UI_SetCursorSeqH(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagG(void *a, int tag);
unsigned BOX2_UI_UpdateCursorInputH(BoxTask *p);
void BOX2_UI_SetCursorSeqI(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagH(void *a, int tag);
unsigned BOX2_UI_CursorInputPage(BoxTask *p);
void BOX2_UI_SetCursorSeqJ(BoxTask *p, int a, int b);
void BOX2_UI_CursorTagI(char *a, int b);
void BOX2_UI_MoveCursorBetweenIcons(BoxWork *q, int a, int b);
void BOX2_UI_PlaceCursorBetween(BoxWork *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
int BOX2_UI_HitTableTrg(const char *p, unsigned n);
int BOX2_UI_HitTableCont(const char *p, unsigned n);
int BOX2_UI_HitTablePoint(const char *p, unsigned n, int a, int b);
u32 BOX2_UI_GetPartySlotHit(void);
int BOX2_UI_GetPartySlotPoint(int a, int b);
u32 BOX2_UI_GetHandSlotHit(void);
u32 BOX2_UI_GetBodySlotHit(void);
int BOX2_UI_GetCloseButtonHit(void);
int BOX2_UI_GetExitButtonHit(void);
int BOX2_UI_GetExitButtonPoint(unsigned *a, unsigned *b);
int BOX2_UI_GetBackButtonPoint(unsigned*a,unsigned*b);
int BOX2_UI_GetGridSlotPoint(int a, int b);
int BOX2_UI_GetPageButtonHit(void);
int BOX2_UI_GetPageButtonHit2(void);
void BOX2_UI_InitWindowFrames(BoxTask *p);
void BOX2_UI_DeleteWindowFrames(BoxWork *p);
void BOX2_UI_SetFrameData(struct WinMgr *mgr, int a1, int a2);
void BOX2_UI_PutTopBarOpen(struct WinMgr *mgr);
void BOX2_UI_PutTopBarClosed(struct WinMgr *mgr);
void BOX2_UI_PutBottomBarOpen(struct WinMgr *mgr);
void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
void BOX2_UI_CloseBar(struct WinMgr *mgr);
void BOX2_UI_OpenBar(struct WinMgr *mgr);
void BOX2_UI_SlideBarIn(struct WinMgr *mgr);
void BOX2_UI_SlideBarOut(struct WinMgr *mgr);
int BOX2_UI_UpdateBarMove(BoxTask *p);
int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
int BOX2_UI_IsTopBarMid(struct WinMgr *mgr);
void BOX2_UI_PutSlotFrames(struct WinMgr *mgr);
void BOX2_UI_PutListFrames(struct WinMgr *mgr);
void BOX2_UI_ResetSlotFrames(struct WinMgr *mgr);
void BOX2_UI_CloseListPack(struct WinMgr *mgr);
void BOX2_UI_OpenListPack(struct WinMgr *mgr);
int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
int BOX2_UI_IsListOpen(struct WinMgr *mgr);
int BOX2_UI_IsListClosed(struct WinMgr *mgr);
void BOX2_UI_AddFadeFrame(BoxTask *p);
void BOX2_UI_PutFadeFrame(struct WinMgr *mgr);
void BOX2_UI_ShowWindowA(BoxWork *p);
void BOX2_UI_HideWindowA(BoxWork *p);
void BOX2_UI_ShowWindowB(BoxWork *p);
void BOX2_UI_HideWindowB(BoxWork *p);
void BOX2_UI_PutTopBarThenClose(struct WinMgr *mgr);
void BOX2_UI_RepenTopBar(struct WinMgr *mgr);
unsigned BOX2_UI_UpdateTopBarMove(BoxTask *p);
void BOX2_UI_PutInfoBar(struct WinMgr *mgr);
void BOX2_UI_CloseInfoBar(struct WinMgr *mgr);
extern const Desc d_021EFD1C;
extern const unsigned char g_021EFCEC[];
extern const short d_021EFCD8[];
extern const U32Pair d_021F02F0[];
extern const unsigned char d_021F0188[];
extern E d_021F0DCC[];
extern E d_021F0370[];
extern const char d_021F1418[];
extern const Bytes d_021F0020;
extern const unsigned char d_021F0F40[];
extern const unsigned char d_021F0040[];
extern const unsigned char d_021F0034[];
extern const u8 d_021F0024[];
extern const unsigned char d_021F002C[];
extern const unsigned char d_021F0F58[];






void BOX2_UI_CreatePartyActors(BoxWork *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    unsigned i;
    for (i = 0; i < 6; i++) {
        t = base;
        t.y += (short)(i * 0x22);
        t.c = i + 0x39;
        p->partyActors[i] = BOX2_SEQ_CreateActorFromDesc(p, &t);
    }
}






/*
 * Release slots 0 and 1 of the 0x9E74 array.
 */
void BOX2_UI_ToggleSlotPair(BoxWork *p, int a)
{
    BOX2_SEQ_SetActorDrawEnable(p, 0, a);
    BOX2_SEQ_SetActorDrawEnable(p, 1, a);
}






void BOX2_UI_LayoutPartySlots(BoxTask *p)
{
    signed char t[2];
    unsigned i;
    short x, y;
    BGWINFRM_GetPos(p->work->winMgr, 7, &t[1], &t[0]);
    i = 0;
    y = t[0] * 8 + 8;
    x = t[1] * 8 + 0x17;
    for (; i < 6; i++)
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, i + 0xd, (short)(x + (i % 2) * 0x20), (short)(y + (i / 2) * 0x18), (short)0);
}






/*
 * Seat one entry, then re-sort.
 */
void BOX2_UI_RefreshBoxName(unsigned char *p)
{
    BOX2_UI_DrawSlot((BoxTask *)p, p[0x14]);
    BOX2_UI_RefreshBoxHeader((BoxTask *)p);
}






/*
 * extent: Two trailing zero bytes at 0x021ED9B2 are alignment padding.
 */
void BOX2_UI_MoveSlotIcon(BoxTask *p, int d)
{
    short t[2];
    int i = 0;
    BOX2_SEQ_GetActorSurfacePos(p->work, 2, &t[1], &t[0], 0);
    BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 2, (short)(t[1] - d), (short)t[0], (short)0);
    for (; i < 6u; i++) {
        BOX2_SEQ_GetActorSurfacePos(p->work, i + 0x2d, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, i + 0x2d, (short)(t[1] - d), (short)t[0], (short)0);
        BMP_OAM_GetPos(p->work->oamSlots[i + 1].obj, &t[1], &t[0]);
        BMP_OAM_SetPos(p->work->oamSlots[i + 1].obj, t[1] - d, t[0]);
    }
}






/*
 * One range call with fixed arguments.
 */
void BOX2_UI_SetCloseButtonPos(BoxWork *a)
{
    BOX2_SEQ_AddActorSurfacePos((BoxWork *)a, 2, 0x4b * 4, 0x22, 0);
}






void BOX2_UI_RefreshBoxHeader(BoxTask *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    short i;
    int a, y;
    for (i = 0; i < 6; i++) {
        a = BOX2_MAIN_WrapOffset((unsigned char *)p, (signed char)(i - 1));
        t = base;
        y = i * 0x22;
        t.y += (short)y;
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, i + 0x2d, t.x, t.y, 0);
        BOX2_UI_UploadSlotChar((BoxTask *)p, a, i + 0x2d);
        BMP_OAM_SetPos(p->work->oamSlots[i + 1].obj, 0x13c, y + 2);
        BOX2_SEQ_DrawMonName((char **)p, a, i + 1);
    }
}






/*
 * Scan six 0x2d-spaced panel rows for the (a1+1)*0x22 key and clear
 *   both shorts when nothing matched.  The key must be written as an
 *   ASSIGNMENT TO THE PARAMETER,
 *       a1 = (a1 + 1) * 0x22;
 *   then tested as `if (a1 == a3[0])`.  A separate `int k = ...` local
 *   loses the image's two-instruction parameter home (r6 = a1, r1 =
 *   r6+1, r6 = r1, muls r6) and swaps a2/a3 between r6 and r7.
 */
void BOX2_UI_FindSlotPos(BoxWork *a0, int a1, short *a2, short *a3)
{
    unsigned i;
    a1 = (a1 + 1) * 0x22;
    for (i = 0; i < 6; i++) {
        BOX2_SEQ_GetActorSurfacePos(a0, i + 0x2d, a2, a3, 0);
        if (a1 == a3[0])
            return;
    }
    *a2 = 0;
    *a3 = 0;
}






void BOX2_UI_DrawSlot(BoxTask *p, int i)
{
    void *t;
    void *q = ARC_UTIL_LoadScreenDataFromArchive(0x74, 0x47, 1, (u32)(&t), 0x4c);
    MI_CpuCopy8(((BoxArcRes *)(t))->data, p->work->charPool[i], 0x400);
    func_020307B0((void *)q);
    BOX2_UI_ReplaceColorIndex((int)p, (unsigned char *)(p->work->charPool[i]), BOX2_MAIN_GetBoxFormId((BoxTask *)p, i), 8, 0x400);
    BOX2_UI_LoadMonIcon((int **)p, i, (unsigned char *)(p->work->charPool[i]));
}






/*
 * Clear all 24 entries.
 */
void BOX2_UI_DrawAllSlots(int p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        BOX2_UI_DrawSlot((BoxTask *)p, i);
}






/*
 * Scan channels -1..4 for the one that reports a; on a hit run the
 *   sub-range call with the channel index.  The compared result must live in a
 *   LOCAL, or mwccarm emits `cmp r5,r0` where the image has `cmp r0,r5`.
 */
void BOX2_UI_DrawSlotByName(char *p, int a)
{
    short i;
    for (i = 0; i < 6; i++) {
        unsigned char c = BOX2_MAIN_WrapOffset((unsigned char *)p, (signed char)(i - 1));
        if (c != a)
            continue;
        BOX2_UI_FindAndDrawSlot((BoxTask *)p, a, i);
        return;
    }
}






/*
 * Detach slot i then hand the a*0x400 span of the 0x3E70 pool to
 *   the 0x400/0/0 emitter.
 */
void BOX2_UI_UploadSlotChar(BoxTask *p, int a, int i)
{
    int q = (int)p->work;
    int x = CLACT_GetActorCharacterIndex((u8 *)(*(int *)(q + i * 4 + 0x9E74)));
    CLACT_TransferCharacterPart(x, (void *)(q + 0x3E70 + a * 0x400), 0x400, 0, 0);
}






/*
 * extent: Two trailing zero bytes at 0x021EDBE6 are alignment padding.
 */
void BOX2_UI_FindAndDrawSlot(BoxTask *p, int a, int b)
{
    short t[2];
    int i = 0;
    b *= 0x22;
    for (; i < 6u; i++) {
        BOX2_SEQ_GetActorSurfacePos(p->work, i + 0x2d, &t[1], &t[0], 0);
        if (b == t[0]) {
            BOX2_UI_UploadSlotChar((BoxTask *)p, a, i + 0x2d);
            BOX2_SEQ_DrawMonName((char **)p, a, i + 1);
            return;
        }
    }
}






void BOX2_UI_ReplaceColorIndex(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++)
        if (a[i] == d)
            a[i] = g_021EFCEC[c];
}







/*
 * lever: the u16 fill value reuses the colour-index local t (t = (u16)((t << 8) | t));
 *   a separate v local takes the spill slot above ty instead of below it.
 */
void BOX2_UI_LoadMonIcon(int **a, int box, u8 *dest)
{
    void *e;
    u32 sv;
    u8 y, x, tx, ty;
    u8 i;
    u32 sp, t;
    u16 form;
    for (ty = 11, y = 0; y < 5; ty += 2, y++) {
        tx = 10;
        for (x = 0; x < 6; tx += 2, x++) {
            e = func_02007A18((void *)(*a)[1], box, x + y * 6);
            sv = POKE_TOOL_DecodeBoxParam((struct Sav *)e);
            sp = POKE_TOOL_GetBoxValue((void *)e, 5, 0);
            if (POKE_TOOL_GetBoxValue((void *)e, 0xa9, 0)) {
                if (POKE_TOOL_GetBoxValue((void *)e, 0x4c, 0) == 0) {
                    void *pd;
                    form = POKE_TOOL_GetBoxValue((void *)e, 0x6f, 0);
                    pd = POKE_PERSONAL_Create((u16)sp, form, 0x4c);
                    t = (u16)POKE_PERSONAL_GetParam((const struct Personal *)pd, 0x21);
                    POKE_PERSONAL_Delete((void *)pd);
                } else {
                    t = (sp == 490) ? 1 : 8;
                }
                t = (u16)(t + 16);
                t = (u16)((t << 8) | t);
                for (i = ty; i < ty + 2; i++)
                    MIi_CpuClear16(t, dest + ((((i & 7) << 3) + ((((i >> 3) << 2) + (tx >> 3)) << 6)) + (tx & 7)), 2);
            }
            POKE_TOOL_EncodeBoxParam((struct Sav *)e, sv);
        }
    }
}







void BOX2_UI_AddSlotIcon(BoxTask *p, int d)
{
    short t[4];
    int step;
    int i;
    short x, y;
    int k;
    step = ((d < 0 ? -d : d) == 5) ? 2 : 8;
    if (d < 0)
        step *= -1;
    for (i = 0; i < 6u; i++) {
        BOX2_SEQ_GetActorSurfacePos(p->work, i + 0x2D, &t[3], &t[2], 0);
        x = t[2] + step;
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, i + 0x2D, (short)t[3], (short)x, (short)0);
        BMP_OAM_GetPos(p->work->oamSlots[i + 1].obj, &t[1], &t[0]);
        y = t[0] + step;
        BMP_OAM_SetPos(p->work->oamSlots[i + 1].obj, t[1], y);
        if (x < -0x10) {
            k = BOX2_MAIN_WrapOffset((unsigned char *)p, 4);
            BOX2_UI_UploadSlotChar((BoxTask *)p, k, i + 0x2D);
            BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, i + 0x2D, (short)t[3], (short)(x + 0xCC), (short)0);
            BOX2_SEQ_DrawMonName((char **)p, k, i + 1);
            BMP_OAM_SetPos(p->work->oamSlots[i + 1].obj, t[1], y + 0xCC);
        } else if (x >= 0xBA) {
            k = BOX2_MAIN_WrapOffset((unsigned char *)p, -1);
            BOX2_UI_UploadSlotChar((BoxTask *)p, k, i + 0x2D);
            BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, i + 0x2D, (short)t[3], (short)(x - 0xCC), (short)0);
            BOX2_SEQ_DrawMonName((char **)p, k, i + 1);
            BMP_OAM_SetPos(p->work->oamSlots[i + 1].obj, t[1], y - 0xCC);
        }
    }
    if (BOX2_SEQ_GetActorDrawEnable((BoxWork *)p->work, 2) == 1) {
        BOX2_SEQ_GetActorSurfacePos(p->work, 2, &t[3], &t[2], 0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 2, (short)t[3], (short)(t[2] + step), (short)0);
    }
}






void BOX2_UI_HideSlotIcon(BoxTask *p, int d)
{
    short t[2];
    if (d < 0 && p->curBox == BOX2_MAIN_WrapOffset((unsigned char *)p, -1)) {
        BOX2_SEQ_GetActorSurfacePos(p->work, 2, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 2, t[1], -0x22, 0);
        BOX2_SEQ_SetActorDrawEnable(p->work, 2, 1);
        return;
    }
    if (d > 0 && p->curBox == BOX2_MAIN_WrapOffset((unsigned char *)p, 4)) {
        BOX2_SEQ_GetActorSurfacePos(p->work, 2, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 2, t[1], 0xcc, 0);
        BOX2_SEQ_SetActorDrawEnable(p->work, 2, 1);
    }
}







void BOX2_UI_DeleteSlotIcon(BoxTask *p)
{
    unsigned i;
    short xy[2];
    for (i = 0; i < 6; i++) {
        if (p->curBox == BOX2_MAIN_WrapOffset((unsigned char *)p, (signed char)(i - 1))) {
            BOX2_SEQ_GetActorSurfacePos(p->work, 2, &xy[1], &xy[0], 0);
            BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 2, (short)xy[1], (short)(i * 0x22), (short)0);
            BOX2_SEQ_SetActorDrawEnable(p->work, 2, 1);
            return;
        }
    }
    BOX2_SEQ_SetActorDrawEnable(p->work, 2, 0);
}






void BOX2_UI_ShowMiniIcon(BoxTask *p, int i)
{
    short y = d_021EFCD8[i];
    BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 3, 0xce, y, 0);
    BOX2_SEQ_SetActorDrawEnable(p->work, 3, 1);
    BMP_OAM_SetPos(p->work->oamSlots[0].obj, 0x9e, y - 8);
    BMP_OAM_SetEnabled(p->work->oamSlots[0].obj, 1);
}






/*
 * Two-way: with flag 1 run the pair update, otherwise release slot 3
 *   and post 0 to the p+0x2c+4 object.
 */
void BOX2_UI_SetMiniIconVisible(BoxTask *p, int a, int b)
{
    if (b == 1) {
        BOX2_SEQ_DrawOffsetName((unsigned char *)p, a);
        BOX2_UI_ShowMiniIcon((BoxTask *)p, a);
        return;
    }
    BOX2_SEQ_SetActorDrawEnable(p->work, 3, 0);
    BMP_OAM_SetEnabled((u8 *)((*(int *)&p->work->oamSlots[0].obj)), 0);
}







void BOX2_UI_DeleteSlotObjects(BoxTask *p, int a, int b, int c)
{
    p->slot6Mode = a;
    p->slot7Mode = b;
    p->slot8Mode = c;
    if (a == 0) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 6, 1);
        BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, 6, 1);
    } else if (a == 1) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 6, 0);
    } else {
        BOX2_SEQ_SetActorDrawEnable(p->work, 6, 1);
        BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, 6, 0xF);
    }
    if (b == 0) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 7, 1);
        BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, 7, 0);
    } else if (b == 1) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 7, 0);
    } else {
        BOX2_SEQ_SetActorDrawEnable(p->work, 7, 1);
        BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, 7, 0xE);
    }
    if (c == 0) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 8, 1);
        BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, 8, 0);
    } else if (c == 1) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 8, 0);
    } else {
        BOX2_SEQ_SetActorDrawEnable(p->work, 8, 1);
        BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, 8, 2);
    }
}






/*
 * Release slots 6, 7 and 8 of the 0x9E74 array.
 */
void BOX2_UI_HideSlots678(BoxTask *p)
{
    BOX2_SEQ_SetActorDrawEnable(p->work, 6, 0);
    BOX2_SEQ_SetActorDrawEnable(p->work, 7, 0);
    BOX2_SEQ_SetActorDrawEnable(p->work, 8, 0);
}






void BOX2_UI_CreateBmpOam(BoxWork *p)
{
    struct Param s;
    u32 i;
    p->oamSys=BMP_OAM_CreateSys(76,(*(void * *)&p->clactUnit));
    p->oamSlots[0].aux=BMP_Create(12,2,32,76);
    s.bmp=p->oamSlots[0].aux;s.x=0;s.y=0;
    s.f8=p->iconFlags;s.fc=0;
    s.f10=4;s.f11=1;s.f12=65535;s.f14=0;
    p->oamSlots[0].obj=BMP_OAM_Create(p->oamSys,&s);
    BMP_OAM_SetEnabled(p->oamSlots[0].obj,0);
    for (i=7;i<=8;i++) {
        ((void **)((char *)p+4))[i*2+1]=BMP_Create(12,2,32,76);
        s.bmp=((void **)((char *)p+4))[i*2+1];s.x=36;s.y=20;s.f11=3;
        ((void **)((char *)p+4))[i*2]=BMP_OAM_Create(p->oamSys,&s);
    }
    for (i=0;i<6;i++) {
        ((void **)((char *)p+4))[(i+1)*2+1]=BMP_Create(2,1,32,76);
        s.bmp=((void **)((char *)p+4))[(i+1)*2+1];s.x=316;s.y=i*34+2;s.f11=1;
        ((void **)((char *)p+4))[(i+1)*2]=BMP_OAM_Create(p->oamSys,&s);
    }
}





void BOX2_UI_DeleteBmpOam(char *p)
{
    unsigned i;
    for (i = 0; i < 9; i++) {
        BMP_OAM_Delete((struct Grid *)(*(int *)(p + i * 8 + 4)));
        BMP_Delete((struct Bmp *)(*(int *)(p + i * 8 + 8)));
    }
    BMP_OAM_DeleteSys((void *)(((BoxOamSys *)(p))->sys));
}






void BOX2_UI_SetSlotOamEnabled(BoxWork *p, int i, int v)
{
    BMP_OAM_SetEnabled((u8 *)((*(int *)&p->oamSlots[i].obj)), v);
}






/*
 *   BMP_OAM_GetEnabled ((const int *)0x020257C4) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int BOX2_UI_GetSlotOamEnabled(BoxWork *a, int i)
{
    return BMP_OAM_GetEnabled((const int *)((*(int *)&a->oamSlots[i].obj)));
}






void BOX2_UI_MoveSlotOam(BoxWork *p, int i, int flag)
{
    if (flag == 0)
        BMP_OAM_SetPos(p->oamSlots[i].obj, -0x94, 0x14);
    else
        BMP_OAM_SetPos(p->oamSlots[i].obj, 0xDC, 0x14);
}






void BOX2_UI_ShiftSlotOams(BoxWork *p, int d)
{
    unsigned i;
    short x;
    short y;
    for (i = 7; i <= 8; i++) {
        BoxObjSlot *e = (BoxObjSlot *)((char *)p + i * 8 + 4);
        BMP_OAM_GetPos((struct BmpOam *)e->obj, &x, &y);
        BMP_OAM_SetPos(e->obj, x + d, y);
        if (x + d == -0x94 || x + d == 0xDC)
            BOX2_UI_SetSlotOamEnabled((BoxWork *)p, i, 0);
    }
}





void BOX2_UI_CreateCursor(char **p)
{
    int f;
    int i;
    f = func_020355C4() == 1 ? 0 : 1;
    switch (((BoxParam *)p[0])->mode) {
    case 0: i = 0; break;
    case 1: i = 2; break;
    case 2: i = 3; break;
    case 3: i = 7; break;
    case 4: i = 13; break;
    case 5: i = 15; break;
    }
    BOX2_UI_DeleteSound((int *)p);
    ((BoxWork *)p[11])->sound = CURSOR_MOVE_Create(d_021F02F0[i].a, d_021F02F0[i].b, (u32)p, f, ((unsigned *)p)[9], 0x4c);
    CURSOR_MOVE_EnableInput(((BoxWork *)p[11])->sound);
    BOX2_UI_UpdateCursor((char *)p, ((int *)p)[9]);
    BOX2_SEQ_SetCursorDraw(p, f);
    ((BoxWork *)p[11])->heldSlot = ((int *)p)[9];
}






void BOX2_UI_MoveCursor(char **p, int idx, int v)
{
    int r = CURSOR_MOVE_GetState(((BoxWork *)p[11])->sound);
    BOX2_UI_DeleteSound((int *)p);
    ((BoxWork *)p[11])->sound = CURSOR_MOVE_Create(d_021F02F0[idx].a, d_021F02F0[idx].b, (u32)p, r, v, 0x4C);
    CURSOR_MOVE_EnableInput(((BoxWork *)p[11])->sound);
    BOX2_UI_UpdateCursor((char *)p, v);
    BOX2_SEQ_SetCursorDraw(p, r);
    ((BoxWork *)p[11])->heldSlot = v;
}






/*
 *   CURSOR_MOVE_Delete (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void BOX2_UI_DeleteSound(int *p)
{
    if ((*(int *)&((BoxTask *)p)->work->sound)) {
        CURSOR_MOVE_Delete();
        (*(int *)&((BoxTask *)p)->work->sound) = 0;
    }
}





void BOX2_UI_SetCursorPos(char **p, unsigned idx)
{
    unsigned char *c = CURSOR_MOVE_GetEntry(((BoxWork *)p[11])->sound, idx);
    BOX2_SEQ_AddActorSurfacePos(((BoxTask *)p)->work, 4, c[0], c[1], 0);
}




/*
 * Update the sub-object, then rebuild the panel.
 */
void BOX2_UI_UpdateCursor(char *p, int v)
{
    BOX2_UI_SetCursorPos((char **)p, v);
    BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
}


/*
 * Run the frame update, then release slot 4 with force 1.
 */
void BOX2_UI_ShowCursor(BoxTask *p, int v)
{
    BOX2_UI_UpdateCursor((char *)p, v);
    BOX2_SEQ_SetActorDrawEnable(p->work, 4, 1);
}


void BOX2_UI_HideCursor(BoxTask *p)
{
    BOX2_SEQ_SetActorDrawEnable(p->work, 4, 0);
}




/*
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
void BOX2_UI_SetCursorSeq(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}



/*
 * Twin of BOX2_UI_PlayAndUpdateCursorB.
 */
void BOX2_UI_PlayAndUpdateCursor(BoxTask *p, unsigned int a)
{
    CURSOR_MOVE_SetCurrent((struct Sound *)((*(int *)&p->work->sound)), (unsigned char)a);
    BOX2_UI_UpdateCursor((char *)p, a);
}



void BOX2_UI_Dummy(void) {}
















unsigned BOX2_UI_UpdateCursorInputA(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent(p->work->sound);
    unsigned r = CURSOR_MOVE_PollRepeatInput(p->work->sound);

    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r >= 8 && r <= 12) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 6;
        }
        if (r == 6) {
            func_020355D8(1);
            return 6;
        }
        if (r == 7) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            return 7;
        }
    } else if (r - 6 <= 1) {
        CURSOR_MOVE_SetCurrent(p->work->sound, sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    return r;
}








/*
 * Ignore the two known tags, otherwise run the update.
 */
void BOX2_UI_CursorTagA(void *a, int tag)
{
    if (tag != 0x6 && tag != 0x7)
        BOX2_UI_UpdateCursor((char *)a, tag);
}







/*
 * Hand the two tag bytes of the p+0x2c+0x70 object to the 0x54/0x10
 * emitter.
 */
void BOX2_UI_PlaceCursorAtIcon(BoxTask *p, unsigned idx)
{
    unsigned char *q = CURSOR_MOVE_GetEntry(*(void ** *)&p->work->sound, idx);
    BOX2_UI_PlaceCursorBetween((BoxWork *)p->work, 0x54, 0x10, q[0], q[1]);
}






void BOX2_UI_PlaceCursorAtMon(BoxTask *p, unsigned int i)
{
    E *e; const unsigned char *g = d_021F0188;
    if (i < 0x1e) { e = &d_021F0DCC[i]; } else { e = &d_021F0370[i - 0x1e]; }
    BOX2_UI_PlaceCursorBetween((BoxWork *)p->work, e->a, e->b, g[0], g[1]);
}







unsigned BOX2_UI_UpdateCursorInputB(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent((p->work->sound));
    unsigned r = CURSOR_MOVE_PollRepeatInput((p->work->sound));
    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r >= 0x23 && r <= 0x27) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0x21;
        }
        if (r == 0x21) {
            func_020355D8(1);
            return 0x21;
        }
        if (r == 0x22) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            return 0x22;
        }
    } else if (r - 0x21 <= 1) {
        CURSOR_MOVE_SetCurrent((p->work->sound), sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    if (r == -1) {
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x20;
        }
    }
    return r;
}







void BOX2_UI_CursorTagB(void *a, int tag)
{
    if (tag != 0x21 && tag != 0x22)
        BOX2_UI_UpdateCursor((char *)a, tag);
}







unsigned BOX2_UI_UpdateCursorInputC(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent((p->work->sound));
    unsigned r = CURSOR_MOVE_PollRepeatInput((p->work->sound));
    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r >= 0x24 && r <= 0x29) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        CURSOR_MOVE_SetCurrent((p->work->sound), sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    if (r == -1) {
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x20;
        }
    }
    return r;
}







void BOX2_UI_SetCursorSeqB(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}







void BOX2_UI_CursorTagC(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        BOX2_UI_UpdateCursor((char *)a, tag);
}







void BOX2_UI_SelectSlot(BoxTask *p, unsigned r)
{
    int a = 0;
    int f = 0;
    if (p->handMode == 1) {
        a = 2;
        if (p->params->mode == 3)
            f = 1;
    } else if (p->params->mode == 3) {
        f = 1;
    } else if (r >= 0x1E) {
        if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0 || BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, a) == 0)
            f = 2;
    } else {
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, a) == 0)
            f = 2;
    }
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, a, 1, f);
}






/*
 * Stage the pair, forward it, re-key the queue with the
 *   0x021E066D selector and record the first argument at 0xA168.
 */
void BOX2_UI_PickSlot(BoxTask *p, int a, int b)
{
    BOX2_UI_SelectSlot((BoxTask *)p, a);
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, 0x021E066D);
    p->work->heldSlot = a;
}
















void BOX2_UI_ConfirmSlot(BoxTask *p, unsigned r)
{
    if (r - 0x1f <= 1) {
        CURSOR_MOVE_SetCurrent(p->work->sound, 0x1e);
        r = 0x1e;
    } else if (r == 0x21 || r == 0x26 || r - 0x28 <= 2) {
        CURSOR_MOVE_SetCurrent(p->work->sound, (*(unsigned *)&p->work->heldSlot));
        r = (*(unsigned *)&p->work->heldSlot);
    } else {
        BOX2_UI_UpdateCursor((char *)p, r);
    }
    BOX2_UI_SelectSlot((BoxTask *)p, r);
    (*(unsigned *)&p->work->heldSlot) = r;
}






unsigned BOX2_UI_CursorInputLeft(BoxTask *p)
{
    unsigned r = CURSOR_MOVE_PollRepeatInput(p->work->sound);
    if (r == -1) {
        if (KEY_GetTrg() & 0x800) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x28;
        }
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x20;
        }
    }
    return r;
}






















unsigned BOX2_UI_UpdateCursorInputD(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent(p->work->sound);
    unsigned r = CURSOR_MOVE_PollRepeatInput(p->work->sound);

    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r >= 9 && r <= 14) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        CURSOR_MOVE_SetCurrent(p->work->sound, sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    return r;
}






void BOX2_UI_SetCursorSeqC(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}






void BOX2_UI_CursorTagD(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        BOX2_UI_UpdateCursor((char *)a, tag);
}






unsigned BOX2_UI_CursorInputRight(BoxTask *p)
{
    unsigned r = CURSOR_MOVE_PollRepeatInput(p->work->sound);
    if (r == -1) {
        if (KEY_GetTrg() & 0x800) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x28;
        }
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x25;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x26;
        }
    }
    return r;
}





/*
 * Twin of BOX2_UI_PickSlot with the same selector and target word.
 */
void BOX2_UI_PickSlotB(BoxTask *p, int a, int b)
{
    BOX2_UI_SelectSlot((BoxTask *)p, a);
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, 0x021E066D);
    p->work->heldSlot = a;
}




















void BOX2_UI_ConfirmSlotB(BoxTask *p, unsigned r)
{
    if (r - 0x25 <= 1) {
        CURSOR_MOVE_SetCurrent(p->work->sound, 0x24);
        r = 0x24;
    } else if (r - 0x28 <= 2) {
        CURSOR_MOVE_SetCurrent(p->work->sound, (*(unsigned *)&p->work->heldSlot));
        r = (*(unsigned *)&p->work->heldSlot);
    } else {
        BOX2_UI_UpdateCursor((char *)p, r);
    }
    BOX2_UI_SelectSlot((BoxTask *)p, r);
    (*(unsigned *)&p->work->heldSlot) = r;
}






















unsigned BOX2_UI_UpdateCursorInputE(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent((p->work->sound));
    unsigned r = CURSOR_MOVE_PollRepeatInput((p->work->sound));
    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r - 0x24 <= 2) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        CURSOR_MOVE_SetCurrent((p->work->sound), sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    if (r == -1) {
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x20;
        }
    }
    return r;
}






void BOX2_UI_SetCursorSeqD(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}






void BOX2_UI_CursorTagE(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        BOX2_UI_UpdateCursor((char *)a, tag);
}






















/*
 * Twin of src/matched/ov170_func_021EE8A8.c.  The image tests the first
 * range as subs/cmp #2, which only the `r - 9 <= 2` spelling gives; the
 * two-compare form r >= 9 && r <= 11 keeps two branches.
 */
unsigned BOX2_UI_UpdateCursorInputF(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent(p->work->sound);
    unsigned r = CURSOR_MOVE_PollRepeatInput(p->work->sound);

    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r - 9 <= 2) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        CURSOR_MOVE_SetCurrent(p->work->sound, sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    return r;
}






void BOX2_UI_SetCursorSeqE(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}






void BOX2_UI_CursorTagF(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        BOX2_UI_UpdateCursor((char *)a, tag);
}






void BOX2_UI_SetCursorSeqF(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}





/*
 * Queue the byte-narrowed index, then re-run the frame update.
 */
void BOX2_UI_PlayAndUpdateCursorB(BoxTask *p, unsigned int a)
{
    CURSOR_MOVE_SetCurrent((struct Sound *)((*(int *)&p->work->sound)), (unsigned char)a);
    BOX2_UI_UpdateCursor((char *)p, a);
}





void BOX2_UI_SetCursorSeqG(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}




void BOX2_UI_PlayAndUpdateCursorC(BoxTask *p, unsigned int a)
{
    CURSOR_MOVE_SetCurrent((struct Sound *)((*(int *)&p->work->sound)), (unsigned char)a);
    BOX2_UI_UpdateCursor((char *)p, a);
}











void BOX2_UI_PickIconSlot(BoxTask *p, int k, int v)
{
    if (k >= 1 && k <= 4) BOX2_UI_SetMiniIconVisible((BoxTask *)p, k-1, 1);
    else BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
    BOX2_UI_MoveCursorBetweenIcons(p->work, k, v);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)BOX2_MAIN_SceneApplyScroll);
    p->work->heldSlot = k;
}




void BOX2_UI_MoveCursorToHeld(BoxTask *p, int a)
{
    int v;
    if (a == 0 || (unsigned)(a - 5) <= 1) {
        CURSOR_MOVE_SetCurrent((struct Sound *)((*(int *)&p->work->sound)),
                      p->work->heldSlot & 0xff);
        v = p->work->heldSlot;
    } else {
        BOX2_UI_UpdateCursor((char *)p, a);
        v = a;
    }
    p->work->heldSlot = v;
}























unsigned BOX2_UI_UpdateCursorInputG(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent((p->work->sound));
    unsigned r = CURSOR_MOVE_PollRepeatInput((p->work->sound));
    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r >= 0x24 && r <= 0x27) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            CURSOR_MOVE_SetCurrent((p->work->sound), sel);
            return 0x23;
        }
    } else if (r == 0x1E || r - 0x21 <= 2) {
        CURSOR_MOVE_SetCurrent((p->work->sound), sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    if (r == -1) {
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound((BoxTask *)p);
            return 0x20;
        }
    }
    return r;
}





void BOX2_UI_SetCursorSeqH(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}





void BOX2_UI_CursorTagG(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        BOX2_UI_UpdateCursor((char *)a, tag);
}
















unsigned BOX2_UI_UpdateCursorInputH(BoxTask *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent(p->work->sound);
    unsigned r = CURSOR_MOVE_PollRepeatInput(p->work->sound);

    if (BOX2_UI_IsListOpen(p->work->winMgr) == 0) {
        if (r >= 9 && r <= 12) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            BOX2_UI_UpdateCursor((char *)p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            CURSOR_MOVE_SetCurrent(p->work->sound, sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        CURSOR_MOVE_SetCurrent(p->work->sound, sel);
        BOX2_UI_UpdateCursor((char *)p, sel);
        return -1;
    }
    return r;
}




/*
 * Detach the sub-object and seat the reset handler.
 */
void BOX2_UI_SetCursorSeqI(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)BOX2_MAIN_SceneApplyScroll);
}





void BOX2_UI_CursorTagH(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        BOX2_UI_UpdateCursor((char *)a, tag);
}
























unsigned BOX2_UI_CursorInputPage(BoxTask *p)
{
    unsigned char sel=CURSOR_MOVE_GetCurrent((p->work->sound));
    unsigned r=CURSOR_MOVE_PollRepeatInput((p->work->sound));
    if(BOX2_UI_IsListOpen(p->work->winMgr)==0) {
        if(r>=0x22 && r<=0x23) {
            CURSOR_MOVE_SetCurrent((p->work->sound),sel);
            BOX2_UI_UpdateCursor((char *)p,sel);
            return -1;
        }
        if(r==0x21) {
            CURSOR_MOVE_SetCurrent((p->work->sound),sel);
            return 0x21;
        }
    } else if(r==0x1e || r==0x21) {
        CURSOR_MOVE_SetCurrent((p->work->sound),sel);
        BOX2_UI_UpdateCursor((char *)p,sel);
        return -1;
    }
    if(r==-1) {
        if(KEY_GetRepeat()&0x200) { BOX2_MAIN_PlayCursorSound((BoxTask *)p); return 0x1f; }
        if(KEY_GetRepeat()&0x100) { BOX2_MAIN_PlayCursorSound((BoxTask *)p); return 0x20; }
    }
    return r;
}




void BOX2_UI_SetCursorSeqJ(BoxTask *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(p->work, a, b);
    BOX2_MAIN_SetSeqParam((BoxWork *)p->work, (int)BOX2_MAIN_SceneApplyScroll);
}




/*
 * Run the attached handler unless the key is 0x21.
 */
void BOX2_UI_CursorTagI(char *a, int b)
{
    if (b != 0x21)
        BOX2_UI_UpdateCursor((char *)a, b);
}




/*
 * Pull the two tag records through the p+0x70 lookup and hand both
 * pairs to the 0x54/0x10 emitter.
 */
void BOX2_UI_MoveCursorBetweenIcons(BoxWork *q, int a, int b)
{
    unsigned char *x = CURSOR_MOVE_GetEntry((void **)((*(int *)&q->sound)), a);
    unsigned char *y = CURSOR_MOVE_GetEntry((void **)((*(int *)&q->sound)), b);
    BOX2_UI_PlaceCursorBetween((BoxWork *)q, x[0], x[1], y[0], y[1]);
}




void BOX2_UI_PlaceCursorBetween(BoxWork *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty)
{
    Motion *s;
    s=func_02030734(0x4c,8,0,d_021F1418,0x98f);
    s->steps=4;
    s->x=x;
    s->y=y;
    if(x>=tx) { s->dx=x-tx; s->negx=0; }
    else { s->dx=tx-x; s->negx=1; }
    if(y>=ty) { s->dy=y-ty; s->negy=0; }
    else { s->dy=ty-y; s->negy=1; }
    s->dx=((unsigned)(s->dx<<8)/(unsigned)s->steps)>>8;
    s->dy=((unsigned)(s->dy<<8)/(unsigned)s->steps)>>8;
    *(Motion * *)&p->seq.entry=s;
}




int BOX2_UI_HitTableTrg(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(TOUCHPANEL_HitTrg(&obj)!=-1) return i;
    }
    return -1;
}




int BOX2_UI_HitTableCont(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(TOUCHPANEL_HitCont(&obj)!=-1) return i;
    }
    return -1;
}




int BOX2_UI_HitTablePoint(const char *p, unsigned n, int a, int b)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(TOUCHPANEL_HitPoint((struct Ctx *)(&obj),a,b)!=-1) return i;
    }
    return -1;
}




/*
 * Register a table with the loader.
 */
u32 BOX2_UI_GetPartySlotHit(void)
{
    return BOX2_UI_HitTableTrg((const char *)0x021F0DCC, 0x1e);
}




int BOX2_UI_GetPartySlotPoint(int a, int b)
{
    return BOX2_UI_HitTablePoint((const char *)0x021F0DCC, 0x1e, a, b);
}




u32 BOX2_UI_GetHandSlotHit(void)
{
    return BOX2_UI_HitTableTrg((const char *)0x021F0574, 6);
}




u32 BOX2_UI_GetBodySlotHit(void)
{
    return BOX2_UI_HitTableTrg((const char *)0x021F1354, 6);
}





int BOX2_UI_GetCloseButtonHit(void)
{
    return BOX2_UI_HitTableCont((const char *)d_021F0F40, 2);
}





int BOX2_UI_GetExitButtonHit(void)
{
    return TOUCHPANEL_HitCont((const void *)d_021F0040);
}





int BOX2_UI_GetExitButtonPoint(unsigned *a, unsigned *b)
{
    if (TOUCHPANEL_HitCont((const void *)d_021F0034) != -1) {
        TOUCHPANEL_GetPointCont(a, b);
        return 1;
    }
    return 0;
}




int BOX2_UI_GetBackButtonPoint(unsigned*a,unsigned*b){if(TOUCHPANEL_HitCont((const void *)d_021F0024)!=-1){TOUCHPANEL_GetPointCont(a,b);return 1;}return 0;}




/*
 * Query the 0x021F1174 table with index 4; -1 becomes 0xff,
 *   otherwise the answer plus 0x24.  The -1 arm must be the branch target.
 */
int BOX2_UI_GetGridSlotPoint(int a, int b)
{
    int v = BOX2_UI_HitTablePoint((const char *)0x021F1174, 4, a, b);
    if (v != -1)
        return v + 0x24;
    return 0xff;
}





int BOX2_UI_GetPageButtonHit(void)
{
    if (TOUCHPANEL_HitCont((const void *)d_021F002C) != -1)
        return 1;
    return 0;
}





int BOX2_UI_GetPageButtonHit2(void)
{
    return BOX2_UI_HitTableCont((const char *)d_021F0F58, 1);
}








/*
 * trailing: two zero alignment bytes at 0x021EF30E.
 */
void BOX2_UI_InitWindowFrames(BoxTask *p)
{
    BoxWork *w=p->work;
    (w->winMgr)=BGWINFRM_Create(2,12,0x4c);
    BOX2_SEQ_AddTextFrame(w);
    BOX2_UI_AddFadeFrame((BoxTask *)p);
    BOX2_SEQ_AddMsgFrame((unsigned char *)p);
    BOX2_SEQ_AddNameFrame((char *)p);
    BGWINFRM_AddFrame((w->winMgr),8,1,11,15);
    if(p->params->mode==4) BOX2_UI_SetFrameData((w->winMgr),8,8);
    else BOX2_UI_SetFrameData((w->winMgr),8,9);
    BGWINFRM_AddFrame((w->winMgr),7,1,11,15);
    BOX2_UI_SetFrameData((w->winMgr),7,10);
    BOX2_SEQ_PutNameFrame((char *)p);
    BGWINFRM_AddFrame((w->winMgr),9,1,11,21);
    BOX2_UI_SetFrameData((w->winMgr),9,11);
    BOX2_UI_PutSlotFrames((w->winMgr));
}





/*
 * Forward the word at +0x74.
 */
void BOX2_UI_DeleteWindowFrames(BoxWork *p)
{
    BGWINFRM_Delete(*(struct WinMgr * *)&p->winMgr);
}





/*
 * Forward the three arguments with a literal third argument, in place of the fourth.
 */
void BOX2_UI_SetFrameData(struct WinMgr *mgr, int a1, int a2)
{
    BGWINFRM_SetFrameDataArc(mgr, a1, 0x74, a2, 1);
}





/*
 * Forward a plus constants to BGWINFRM_PutFrame.
 */
void BOX2_UI_PutTopBarOpen(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 8, 2, 6);
}





void BOX2_UI_PutTopBarClosed(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 8, 0x15, 6);
}





void BOX2_UI_PutBottomBarOpen(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 8, 2, 0x18);
}





void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 8, 0x15, 0x18);
}




/*
 * Probe the 8-byte tag; unless the tag byte is 6, patch the row
 *   with (tag - 6) through channel 8.
 */
void BOX2_UI_CloseBar(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 6)
        BGWINFRM_StartMove(mgr, 8, 0, -1, (unsigned char)(buf[0] - 6));
}




/*
 * Probe the 8-byte tag; unless the tag byte is 0x18, patch the row
 *   with (0x18 - tag) as a flagged close.
 */
void BOX2_UI_OpenBar(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 0x18)
        BGWINFRM_StartMove(mgr, 8, 0, 1, (unsigned char)(0x18 - buf[0]));
}





/*
 * Forward a plus constants to BGWINFRM_StartMove.
 */
void BOX2_UI_SlideBarIn(struct WinMgr *mgr)
{
    BGWINFRM_StartMove(mgr, 8, 1, 0, 0x13);
}





void BOX2_UI_SlideBarOut(struct WinMgr *mgr)
{
    BGWINFRM_StartMove(mgr, 8, -1, 0, 0x13);
}





int BOX2_UI_UpdateBarMove(BoxTask *p)
{
    signed char a[2];
    signed char b[2];
    unsigned r;
    BGWINFRM_GetPos(p->work->winMgr, 8, &a[1], &a[0]);
    r = BGWINFRM_UpdateMove(p->work->winMgr, 8);
    BGWINFRM_GetPos(p->work->winMgr, 8, &b[1], &b[0]);
    if (a[1] != b[1] || a[0] != b[0])
        BOX2_SEQ_MoveActorToWindow((BoxTask *)p);
    {
        int ret = 0;
        if (r != 0)
            ret = 1;
        return ret;
    }
}




/*
 * Read the 8-byte tag at the top of the frame; 1 when byte 1 is
 *   0x15 and byte 0 is 6.
 */
int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 8, buf + 1, buf);
    return buf[1] == 0x15 && buf[0] == 6;
}




/*
 * Same probe as BOX2_UI_IsTopBarOpen with tag byte 1 compared to 2.
 */
int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 8, buf + 1, buf);
    return buf[1] == 0x2 && buf[0] == 6;
}




/*
 * Probe the 8-byte tag at the top of the frame; 1 when its first
 *   byte is 6.
 */
int BOX2_UI_IsTopBarMid(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 8, buf + 1, buf);
    return buf[0] == 6;
}




/*
 * Push tag rows 0x20 for six entries; element (i*3+2) is a
 *   signed char.  The counter is UNSIGNED or the image's blo becomes blt.
 */
void BOX2_UI_PutSlotFrames(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        BGWINFRM_PutFrame(mgr, i, 0x20, (signed char)(i * 3 + 2));
}




void BOX2_UI_PutListFrames(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        BGWINFRM_PutFrame(mgr, i, 0x15, (signed char)(i * 3 + 2));
}





void BOX2_UI_ResetSlotFrames(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        BGWINFRM_HideFrame(mgr, i);
        BGWINFRM_PutFrame(mgr, i, 0x20, i * 3 + 2);
    }
}





void BOX2_UI_CloseListPack(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    BGWINFRM_GetPos(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x15)
        return;
    for (; i < 6; i++)
        BGWINFRM_StartMove(mgr, i, -1, 0, buf[1] - 0x15);
}





void BOX2_UI_OpenListPack(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    BGWINFRM_GetPos(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x20)
        return;
    for (; i < 6; i++)
        BGWINFRM_StartMove(mgr, i, 1, 0, 0x20 - buf[1]);
}




/*
 * 1 when probe 1..6 reports 1.
 */
int BOX2_UI_UpdateListPacks(struct WinMgr *mgr)
{
    unsigned i;
    int found = 0;
    for (i = 0; i < 6; i++) {
        if (BGWINFRM_UpdateMove(mgr, i) == 1)
            found = 1;
    }
    return found;
}




int BOX2_UI_IsListOpen(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 0, buf + 1, buf);
    return buf[1] != 0x20;
}




/*
 * 1 when the tag's byte 1 is 0x15.
 */
int BOX2_UI_IsListClosed(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 0, buf + 1, buf);
    return buf[1] == 0x15;
}




/*
 * Spin up the 0x0204162C resource, arm channel 6 with tag 0x20,
 *   then hand row 6 of the 0x540 span.
 */
void BOX2_UI_AddFadeFrame(BoxTask *p)
{
    int x = BG_SYS_GetBuf(0);
    BGWINFRM_AddFrame(p->work->winMgr, 6, 0, 0x20, 3);
    BGWINFRM_SetFrameData(p->work->winMgr, 6, (const void *)(x + 0x540));
}





void BOX2_UI_PutFadeFrame(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 6, 0, 0x15);
}





/*
 * Forward the word at +0x74 plus constants to BGWINFRM_PutFrame.
 */
void BOX2_UI_ShowWindowA(BoxWork *p)
{
    BGWINFRM_PutFrame(*(struct WinMgr * *)&p->winMgr, 0xa, 0, 0x15);
}





/*
 * Forward the word at +0x74 with index 10.
 */
void BOX2_UI_HideWindowA(BoxWork *p)
{
    BGWINFRM_HideFrame(*(struct WinMgr * *)&p->winMgr, 0xa);
}





void BOX2_UI_ShowWindowB(BoxWork *p)
{
    BGWINFRM_PutFrame(*(struct WinMgr * *)&p->winMgr, 0xb, 0, 0x15);
}





/*
 * Forward the word at +0x74 with index 11.
 */
void BOX2_UI_HideWindowB(BoxWork *p)
{
    BGWINFRM_HideFrame(*(struct WinMgr * *)&p->winMgr, 0xb);
}




void BOX2_UI_PutTopBarThenClose(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 7, 0x15, 0x18);
    BGWINFRM_StartMove(mgr, 7, 0, -1, 0x13);
}





void BOX2_UI_RepenTopBar(struct WinMgr *mgr)
{
    BGWINFRM_StartMove(mgr, 7, 0, 1, 0x13);
}














/*
 * trailing: two zero alignment bytes at 0x021EF736.
 */
unsigned BOX2_UI_UpdateTopBarMove(BoxTask *p)
{
    signed char a[2], b[2];
    unsigned r;
    BGWINFRM_GetPos(p->work->winMgr,7,&a[1],&a[0]);
    r=BGWINFRM_UpdateMove(p->work->winMgr,7);
    BGWINFRM_GetPos(p->work->winMgr,7,&b[1],&b[0]);
    if(a[1]!=b[1] || a[0]!=b[0]) BOX2_UI_LayoutPartySlots((BoxTask *)p);
    return r;
}




/*
 * Stage row 0x20 at channel 9 then patch with -1.
 */
void BOX2_UI_PutInfoBar(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 9, 0x20, 0);
    BGWINFRM_StartMove(mgr, 9, -1, 0, 0xb);
}





void BOX2_UI_CloseInfoBar(struct WinMgr *mgr)
{
    BGWINFRM_StartMove(mgr, 9, 1, 0, 0xb);
}

int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr)
{
    s8 buf[2];
    BGWINFRM_GetPos(mgr, 9, &buf[1], &buf[0]);
    if (buf[1] == 0x15) {
        return 1;
    }
    return 0;
}

