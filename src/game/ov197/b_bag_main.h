#ifndef GAME_OV197_B_BAG_MAIN_H
#define GAME_OV197_B_BAG_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_bag_main.c, prototypes copied from their definitions. */

struct ClactActor;
struct ClactVec2;
struct BBagMainPair;
struct Node;

#include "../types.h"

struct TcbTask;

void B_BAG_MAIN_InitWindows(char *p);
void B_BAG_MAIN_CreateWindows(char *p,u8 unused);
void B_BAG_MAIN_DeleteWindows(char *a);
void B_BAG_MAIN_ExitWindows(char *a);
void B_BAG_MAIN_DrawPage(char *a, int which);
void B_BAG_MAIN_PrintLabel(char *p,int i,int id,int y,u16 colour);
void B_BAG_MAIN_DrawLabels(char *p);
void B_BAG_MAIN_DrawItemName(char *p,u32 i,int id,int w,int unused,int unused2);
void B_BAG_MAIN_DrawItemInfo(char *p, u32 i, int id, int w, int unused, int y, int unused2);
void B_BAG_MAIN_DrawSlot(char *p,u16 i);
void B_BAG_MAIN_DrawPocket(char *p);
void B_BAG_MAIN_DrawHeader(char *p);
void B_BAG_MAIN_DrawInfoBox(char *p);
void B_BAG_MAIN_DrawItemsPage(char *a);
void B_BAG_MAIN_DrawDescription(u8 *p, u32 idx);
void B_BAG_MAIN_DrawItemUsage(char *p,int n);
void B_BAG_MAIN_DrawOtherPage(char *p);
void B_BAG_MAIN_PrintItemMsg(char *p);
void B_BAG_MAIN_StartItemMsg(char *p);
void B_BAG_MAIN_UpdateTool(char *a);
void B_BAG_MAIN_ShowWindows(u8 *p);
int B_BAG_MAIN_CheckKeyItem(char *p);
void B_BAG_MAIN_SyncCursorToItem(u8 *p);
void B_BAG_MAIN_BuildPocketLists(u8 *p);
void B_BAG_MAIN_BuildOtherList(char *p);
void B_BAG_MAIN_InitOtherPage(char *p);
u16 B_BAG_MAIN_GetSlotItem(const char *p, unsigned n);
int B_BAG_MAIN_GetItemFlag(u32 key);
void B_BAG_MAIN_InitFrames(char *p);
void B_BAG_MAIN_DeleteFrames(char *a);
void B_BAG_MAIN_LayoutFrames(char *p, int mode);
void B_BAG_MAIN_StartFrameAnim(char *p, int v);
void B_BAG_MAIN_StepFrameAnim(char *p);
void B_BAG_MAIN_CreateItemGraphics(char *p);
void B_BAG_MAIN_ClearHandles(char *p);
void B_BAG_MAIN_RegisterItemChars(char *p);
void B_BAG_MAIN_LoadItemGraphic(char *p,u16 item,unsigned slot,unsigned offset);
void B_BAG_MAIN_LoadItemPalette(char *p,unsigned item,unsigned slot);
void B_BAG_MAIN_RegisterCursorGraphics(char *p);
void B_BAG_MAIN_RegisterIconGraphics(char *p);
struct ClactActor *B_BAG_MAIN_CreateItemActor(char *p,const int *indices);
void B_BAG_MAIN_CreateItemActors(char *p);
void B_BAG_MAIN_DeleteItemGraphics(char *p);
void B_BAG_MAIN_PlaceActor(struct ClactActor *a, struct ClactVec2 *b);
void B_BAG_MAIN_SetDisplayMode(char *p, int mode);
void B_BAG_MAIN_DisplaySingle(char *p);
void B_BAG_MAIN_DisplayList(char *p);
void B_BAG_MAIN_DisplaySelected(char *p);
void B_BAG_MAIN_CreateToolActors(char *p);
void B_BAG_MAIN_DeleteToolActors(char *a);
void B_BAG_MAIN_CreateFingerCursor(char *a);
void B_BAG_MAIN_DeleteFingerCursor(char *a);
void B_BAG_MAIN_StartFingerCursor(u8 *p, u32 a, u32 b);
void B_BAG_MAIN_DeleteFingerCursorActor(char *a);
void B_BAG_MAIN_DrawItemRow(char *p,u16 slot,u8 a,u8 b,const struct BBagMainPair *src);
void B_BAG_MAIN_Create(u8 *arg);
void B_BAG_MAIN_Main(struct TcbTask *task, void *arg);
int B_BAG_MAIN_StateInit(char *p);
int B_BAG_MAIN_StateInitOther(char *p);
int B_BAG_MAIN_StateWaitPrintWipe(char *p);
int B_BAG_MAIN_StateWipeEnd(char *p);
int B_BAG_MAIN_StateSelectPocket(char *p);
int B_BAG_MAIN_StateSelectItem(char *p);
int B_BAG_MAIN_StateChangeCount(char *p);
int B_BAG_MAIN_StateWaitPrintRedraw(char *p);
int B_BAG_MAIN_StateChooseItem(char *p);
int B_BAG_MAIN_StateShowMessage(char *p);
int B_BAG_MAIN_StateShowPocket0(char *p);
int B_BAG_MAIN_StateShowPocket1(char *p);
int B_BAG_MAIN_StateShowPocket2(char *p);
int B_BAG_MAIN_StateWaitPrintSetMode(char *p);
int B_BAG_MAIN_StateStartMessage(char *a);
int B_BAG_MAIN_StateMessageInput(char *p);
int B_BAG_MAIN_StateMessageDone(char *p);
int B_BAG_MAIN_StateWaitKey(char *p);
int B_BAG_MAIN_StateFadeOut(char *p);
int B_BAG_MAIN_StateWaitFade(char *a);
int B_BAG_MAIN_StateExit(struct TcbTask *task, char *p);
int B_BAG_MAIN_StateOtherFlow(char *p);
void B_BAG_MAIN_InitBg(char *p);
void B_BAG_MAIN_ExitBg(void);
void B_BAG_MAIN_LoadBgGraphics(char *p);
void B_BAG_MAIN_CreateText(char *p);
void B_BAG_MAIN_DeleteText(char *p);
void B_BAG_MAIN_ResetBgSlot(void *unused, int mode);
void B_BAG_MAIN_SwitchPage(char *p,int mode);
int B_BAG_MAIN_CheckCancel(char **p);
void B_BAG_MAIN_PlaySe(char **a, int b);
void B_BAG_MAIN_PlaySe2(char **a, int b);
void B_BAG_MAIN_CreateCursor(u8 *p, u32 index, u32 value);
u32 B_BAG_MAIN_DeleteCursor(u8 *p);
void B_BAG_MAIN_RecreateCursor(u8 *p, int state, int value);
void B_BAG_MAIN_SetCursorVisible(char *a, int b);
void B_BAG_MAIN_LayoutCursor(u8 *p, u32 idx);
void B_BAG_MAIN_ShowCursorAt(u8 *p,u32 i);
void B_BAG_MAIN_HideCursor(char *p);
void B_BAG_MAIN_HideCursor2(char *p);
void B_BAG_MAIN_LayoutCursorOnly(u8 *p,u32 i);
void B_BAG_MAIN_HandleSelection(char *p, int b);
/* END mkheaders: generated region */

#endif
