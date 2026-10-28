#ifndef GAME_OV186_BR_UTIL_H
#define GAME_OV186_BR_UTIL_H
struct BrListMenuConfig;

#include "../types.h"

/* Not in the generated region: its definition takes a file-local typedef. */
struct BrListMenu *BR_UTIL_CreateListMenu(const struct BrListMenuConfig *cfg, u16 heap);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_util.c, prototypes copied from their definitions. */

struct Bmp;
struct BrRes;
struct BrProfileScreen;
struct BrUtilTask;
struct BrUtilEffect;
struct BrUtilFollow;
typedef struct BrUtilEffect BrUtilEffect;
typedef struct BrUtilFollow BrUtilFollow;

#include "../types.h"
#include "../ov186/br_types.h"
#include "../ov186/br_types.h"

void *BR_UTIL_Create(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap);
void BR_UTIL_Delete(u8*p);
void BR_UTIL_SetTextFromMessage(char *p,void *a,u32 b,void *font,unsigned short value);
void BR_UTIL_SetTextFromBuffer(char *p,void *text,void *font,unsigned short value);
int BR_UTIL_FlushText(u8*p);
void BR_UTIL_SetTextLayout(u8*p,u32 a,u32 b,u32 c);
void BR_UTIL_AlignText(int mode,BrPair *base,const void *bmp,void *text,void *font,BrPair *out);
void BR_UTIL_DeleteListMenu(char *p);
void BR_UTIL_MainListMenu(char *p);
int BR_UTIL_ListMenuIsScrollable(char *p);
int BR_UTIL_GetListMenuHitId(char *p);
void BR_UTIL_SetListItemBitmap(u8 *p, u16 i, struct Bmp *v);
struct Bmp *BR_UTIL_GetListItemBitmap(u8 *p, u16 i);
int BR_UTIL_GetListMenuField(char *p,unsigned field);
void BR_UTIL_RefreshList(char *p);
void BR_UTIL_DrawListRows(char *p,int start);
int BR_UTIL_PollScrollDrag(char *p);
void BR_UTIL_BlitRows(struct Bmp *dest,struct Bmp *src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height);
int BR_UTIL_ScrollRows(char *p,int change);
int BR_UTIL_ScrollWithCursor(char *p,int step);
int BR_UTIL_NeedsScroll(char *p);
int BR_UTIL_HasMultipleRows(char *p);
void BR_UTIL_HandleRowTouch(char *p);
void BR_UTIL_UpdateRowSelection(char *p);
void *BR_UTIL_CreateTextWin(void *a, void *owner, u16 heap);
void BR_UTIL_DeleteTextWin(void *p, struct BrRes *res);
void BR_UTIL_SetWindowText(char *p,struct BrRes *q,u32 text);
void BR_UTIL_SetWindowTextBuf(char *p,void *q,void *text);
void BR_UTIL_FlushWindow(void *p);
struct BrProfileScreen *BR_UTIL_CreateProfileScreen(void *prof,struct BrRes *q,void *unit,void *printQue,int mode,u16 heap);
void BR_UTIL_DeleteProfileScreen(struct BrProfileScreen *p);
int BR_UTIL_MainProfileScreen(struct BrProfileScreen *p);
struct BrUtilTask *BR_UTIL_CreateTask(void *payload,BrUtilTaskStep step,int heap);
void BR_UTIL_DeleteTask(void *p);
void BR_UTIL_RunTask(struct BrUtilTask *p);
int BR_UTIL_IsTaskIdle(struct BrUtilTask *p);
struct BrUtilTask *BR_UTIL_SetTaskStep(struct BrUtilTask *p, BrUtilTaskStep v);
struct BrUtilTask *BR_UTIL_ClearTaskStep(struct BrUtilTask *a);
int BR_UTIL_IsTaskStep(struct BrUtilTask *p, BrUtilTaskStep v);
char *BR_UTIL_CreateHandles(void *owner, struct BrRes *resources, int index, int heap);
void BR_UTIL_DeleteHandles(char *r5);
void BR_UTIL_RunHandles(char *p);
void BR_UTIL_StartEffect(char *p,u32 mode,const BrPair *pair);
int BR_UTIL_IsEffectDone(char *p);
void BR_UTIL_SetHandlesAnimSeq(u8 *p,u32 value);
void BR_UTIL_EffectIdle(struct BrUtilTask *unused,int *state,u8 *p);
void BR_UTIL_EffectSpiral(struct BrUtilTask *unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFollow12(struct BrUtilTask *unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFollow6(struct BrUtilTask *unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFlyIn(struct BrUtilTask *unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectFlyInSlow(struct BrUtilTask *unused,int *state,BrUtilEffect *p);
void BR_UTIL_EffectNoop(void);
void BR_UTIL_EffectToTarget(struct BrUtilTask *obj,int *state,BrUtilEffect *p);
void BR_UTIL_EffectToPoint(struct BrUtilTask *task,int *state,BrUtilEffect *p);
int BR_UTIL_InitOrbit(u8 *p,const BrPair *origin,u16 a,u16 b,u16 c,u16 d,int duration);
int BR_UTIL_StepOrbit(char *p, int *out, int step);
int BR_UTIL_InitSpiral(u8 *p,const BrPair *origin,u16 a,u16 b,int duration);
int BR_UTIL_StepSpiral(char *p, int *out, int step);
void BR_UTIL_InitLine(int *p,const BrPair *a,const BrPair *b,int c,int d);
int BR_UTIL_StepLine(int *p, BrPair *out, int step);
void BR_UTIL_Init(BrUtilFollow *p, const int *a, const int *values, int duration);
int BR_UTIL_StepFollow(char *p,int *out);
/* END mkheaders: generated region */

#endif
