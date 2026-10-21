#ifndef GAME_OV186_BR_UTIL_H
#define GAME_OV186_BR_UTIL_H

/* Not in the generated region: its definition takes a file-local typedef. */
struct BrListMenu *BR_UTIL_CreateListMenu(const struct BrListMenuConfig *cfg, u16 heap);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_util.c, prototypes copied from their definitions. */

struct BrUtilEffect;
typedef struct BrUtilEffect BrUtilEffect;

#include "../types.h"
#include "../ov186/br_types.h"
#include "../ov186/br_types.h"

void *BR_UTIL_Create(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap);
void BR_UTIL_Delete(u8*p);
void BR_UTIL_SetTextFromMessage(char *p,void *a,void *b,void *font,unsigned short value);
void BR_UTIL_SetTextFromBuffer(char *p,void *text,void *font,unsigned short value);
int BR_UTIL_FlushText(u8*p);
void BR_UTIL_SetTextLayout(u8*p,u32 a,u32 b,u32 c);
void BR_UTIL_AlignText(int mode,BrPair *base,const void *bmp,void *text,void *font,BrPair *out);
void BR_UTIL_DeleteListMenu(char *p);
void BR_UTIL_MainListMenu(char *p);
int BR_UTIL_ListMenuIsScrollable(char *p);
int BR_UTIL_GetListMenuHitId(char *p);
void BR_UTIL_SetListItemBitmap(u8 *p, u16 i, u32 v);
u32 BR_UTIL_GetListItemBitmap(u8 *p, u16 i);
int BR_UTIL_GetListMenuField(char *p,unsigned field);
void BR_UTIL_RefreshList(char *p);
void BR_UTIL_DrawListRows(char *p,int start);
int BR_UTIL_PollScrollDrag(char *p);
void BR_UTIL_BlitRows(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height);
int BR_UTIL_ScrollRows(char *p,int change);
int BR_UTIL_ScrollWithCursor(char *p,int step);
int BR_UTIL_NeedsScroll(char *p);
int BR_UTIL_HasMultipleRows(char *p);
void BR_UTIL_HandleRowTouch(char *p);
void BR_UTIL_UpdateRowSelection(char *p);
void *BR_UTIL_CreateTextWin(void *a, void *owner, u16 heap);
void BR_UTIL_DeleteTextWin(void *p, int res);
void BR_UTIL_SetWindowText(char *p,char *q,void *text);
void BR_UTIL_SetWindowTextBuf(char *p,void *q,void *text);
void BR_UTIL_FlushWindow(void *p);
char *BR_UTIL_CreateProfileScreen(void *prof,char *q,void *unit,void *printQue,int mode,u16 heap);
void BR_UTIL_DeleteProfileScreen(int *p);
int BR_UTIL_MainProfileScreen(u8 *p);
int *BR_UTIL_CreateTask(int payload,int callback,int heap);
void BR_UTIL_DeleteTask(void *p);
void BR_UTIL_RunTask(u8 *p);
int BR_UTIL_IsTaskIdle(int *p);
int *BR_UTIL_SetTaskStep(int *p, int v);
int BR_UTIL_ClearTaskStep(int *a);
int BR_UTIL_IsTaskStep(int *p, int v);
char *BR_UTIL_CreateHandles(void *owner, char *resources, int index, int heap);
void BR_UTIL_DeleteHandles(char *r5);
void BR_UTIL_RunHandles(char *p);
void BR_UTIL_StartEffect(char *p,u32 mode,const BrPair *pair);
int BR_UTIL_IsEffectDone(char *p);
void BR_UTIL_SetHandlesAnimSeq(u8 *p,u32 value);
void BR_UTIL_EffectIdle(void *unused,int *state,u8 *p);
void BR_UTIL_EffectSpiral(int unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFollow12(int unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFollow6(int unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFlyIn(int unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFlyInSlow(int unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectNoop(void);
void BR_UTIL_EffectToTarget(int *obj,int *state,BrUtilEffect *p);
void BR_UTIL_EffectToPoint(int *task,int *state,char *p);
int BR_UTIL_InitOrbit(u8 *p,const BrPair *origin,u16 a,u16 b,u16 c,u16 d,int duration);
int BR_UTIL_StepOrbit(char *p, int *out, int step);
int BR_UTIL_InitSpiral(u8 *p,const BrPair *origin,u16 a,u16 b,int duration);
int BR_UTIL_StepSpiral(char *p, int *out, int step);
void BR_UTIL_InitLine(int *p,const BrPair *a,const BrPair *b,int c,int d);
int BR_UTIL_StepLine(int *p, BrPair *out, int step);
void BR_UTIL_Init(int *p, int a, const int *values, int duration);
int BR_UTIL_StepFollow(char *p,int *out);
/* END mkheaders: generated region */

#endif
