#ifndef GAME_OV128_WF2DMAP_TOUCH_H
#define GAME_OV128_WF2DMAP_TOUCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_touch.c, prototypes copied from their definitions. */

#include "../ov010/namein_args.h"
#include "../types.h"
#include "../ov128/wf2dmap_ui_types.h"

NameInArgs *WF2DMAP_TOUCH_CreateNameEntry(void *unused,char *q,int mode,int heap);
void WF2DMAP_TOUCH_DrawFriendKeyThunk(void *p,void *q,void *r,u16 s);
int WF2DMAP_TOUCH_FriendKeyScreen(void *p, u8 *q, u8 *r, int heap);
void WF2DMAP_TOUCH_DeleteScreenThunk(void *p, void *q, void *r);
int WF2DMAP_TOUCH_GetFriendKeyInput(void *unused,int *q);
void WF2DMAP_TOUCH_DrawFriendKey(u8 *p, u8 *q, u8 *ctx, u16 heap);
void WF2DMAP_TOUCH_DeleteScreens(char *p,int unused,char *q);
void WF2DMAP_TOUCH_InitGfx(char *p,char *q,char *r);
void WF2DMAP_TOUCH_ClearScreens(char *p,void *q);
void WF2DMAP_TOUCH_StartFriendEdit(u8 *p,u8 *b,u8 *c,u16 d);
int WF2DMAP_TOUCH_FriendEditScreen(u8 *p,u8 *q,u8 *r,u16 heap);
int WF2DMAP_TOUCH_SelectMenu(char *p,void *q,void *r,int n);
int WF2DMAP_TOUCH_GetMenuKeyInput(void *p,int *q,void *r);
int WF2DMAP_TOUCH_GetMenuTouchInput(void *p,void *q,void *r,int *flag);
int WF2DMAP_TOUCH_GetMenuInput(void *p,int *q,char *r);
void WF2DMAP_TOUCH_StartEditAnim(char *p, void *q, void *r, int s);
int WF2DMAP_TOUCH_StepSlideIn(u8 *p,void *a,void *b,int c);
void WF2DMAP_TOUCH_CreateEditWidgets(u8 *p, void *unused, u8 *q, u16 heap);
void WF2DMAP_TOUCH_DeleteEditWidgets(u8 *p,void *unused,u8 *q);
void WF2DMAP_TOUCH_InitEditScreen(u8 *p,u8 *q,u8 *r,u16 heap);
void WF2DMAP_TOUCH_CloseEditScreen(u8 *p,u8 *q);
void WF2DMAP_TOUCH_ReleaseEditWidgets(char *p,u8 *q);
void WF2DMAP_TOUCH_CreateTrainerWidgets(u8 *p,u8 *q,u8 *ctx,u16 heap);
void WF2DMAP_TOUCH_ClearTrainerScreens(Wf2dmapTouchEdit *p);
void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int unused);
void WF2DMAP_TOUCH_DrawSlider(u8 *p,u8 *q,int idx);
void WF2DMAP_TOUCH_DrawCursorBg(void *unused,u8 *p);
int WF2DMAP_TOUCH_FindPrevEntry(u8 *p,int direction);
int WF2DMAP_TOUCH_FindNextEntry(u8 *p,int direction);
void WF2DMAP_TOUCH_CreateWidgetHandles(u8 *p,u8 *q,u16 heap);
void WF2DMAP_TOUCH_DeleteWidgetHandles(u8 *p);
void WF2DMAP_TOUCH_CreateTileWidgets(u8 *p,void *q);
void WF2DMAP_TOUCH_DeleteTileScreens(u8 *p, void *unused);
void WF2DMAP_TOUCH_InitTileRecord(Wf2dmapTouchTileRecord *p,int unused,const u16 *q,u32 value,u16 heap);
void WF2DMAP_TOUCH_Noop(void *unused);
void WF2DMAP_TOUCH_SetTileRecordField(Wf2dmapTouchTileRecord *p,int unused,u32 index,u32 value,u32 unused5,u16 heap);
void WF2DMAP_TOUCH_ClearTileRecord(Wf2dmapTouchTileRecord *p,u32 index);
void WF2DMAP_TOUCH_ClearScreenAt(char *p,u32 index);
void WF2DMAP_TOUCH_ClearAllScreens(char *p,void *q);
void WF2DMAP_TOUCH_SetBgScroll(void *q,char *p);
void WF2DMAP_TOUCH_PrintItem(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color);
u64 WF2DMAP_TOUCH_ParseKey(void *p,int *ok);
int WF2DMAP_TOUCH_GetConfirmInput(int *p);
void WF2DMAP_TOUCH_CreatePalAnims(u8 *p,u16 heap);
void WF2DMAP_TOUCH_DeletePalAnims(u8 *p);
void WF2DMAP_TOUCH_DrawTopHighlight(u32 a,u32 b);
void WF2DMAP_TOUCH_SetTopHighlight1(u8 *p, int a);
void WF2DMAP_TOUCH_SetTopHighlight3(u8 *p, int a);
void WF2DMAP_TOUCH_SetTopHighlight(u8 *p, int a, int b);
void WF2DMAP_TOUCH_UpdateTopBar(unsigned *p);
int WF2DMAP_TOUCH_StepTopBarBlink(char *p);
void WF2DMAP_TOUCH_DrawItemHighlight(u32 a,u32 b);
void WF2DMAP_TOUCH_SetItemHighlight1(u8 *p, int a);
void WF2DMAP_TOUCH_SetItemHighlight3(u8 *p, int a);
void WF2DMAP_TOUCH_SetItemHighlight(u8 *p, int a, int b);
void WF2DMAP_TOUCH_UpdateItemBar(char *p);
int WF2DMAP_TOUCH_StepItemBarBlink(char *p);
void WF2DMAP_TOUCH_PlayActorAnimA(char *p);
void WF2DMAP_TOUCH_PlayActorAnimB(char *p);
void WF2DMAP_TOUCH_SetScreenBrightness(int a);
void WF2DMAP_TOUCH_SetActorAnimSeq(char *p, int n);
void WF2DMAP_TOUCH_MakeScreen(char *p);
void WF2DMAP_TOUCH_ClearSlotArray(char *p);
void WF2DMAP_TOUCH_AddSlot(char *p,void *q);
void WF2DMAP_TOUCH_UpdateSlots(char *p);
void WF2DMAP_TOUCH_TransferScreen(char *p);
void WF2DMAP_TOUCH_ReleaseActor(Wf2dmapTouchEdit *p);
/* END mkheaders: generated region */

#endif
