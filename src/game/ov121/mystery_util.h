#ifndef GAME_OV121_MYSTERY_UTIL_H
#define GAME_OV121_MYSTERY_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_util.c, prototypes copied from their definitions. */

struct MsgBank;
struct MysteryUtilDetailWindow;
struct MysteryUtilDetailDef;

#include "../types.h"

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap);
void MYSTERY_UTIL_DeleteWindow(u8 *p);
void MYSTERY_UTIL_ClearWindow(u8 *p);
void MYSTERY_UTIL_ShowMessage(u8 *p, struct MsgBank *a, int b, int c);
void MYSTERY_UTIL_ShowString(u8 *p, int a, int b);
void MYSTERY_UTIL_SetColor(u8 *p,unsigned v);
void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);
int MYSTERY_UTIL_IsMessageDone(u8 *p);
void MYSTERY_UTIL_TransferWindowChars(u8 *p);
void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap);
void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, void *c, void *d, u16 heap);
void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);
void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode);
unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
void MYSTERY_UTIL_ResetMenuWindow(u8 *p);
void *MYSTERY_UTIL_CreateMenu(const u8 *p,u16 heap);
void MYSTERY_UTIL_DeleteMenu(u8 *p);
int MYSTERY_UTIL_UpdateMenu(char *p);
void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,struct MsgBank *e,int f,u16 heap);
void MYSTERY_UTIL_DeleteWindowList(u8 *p);
void MYSTERY_UTIL_ClearWindowList(u8 *p);
int MYSTERY_UTIL_IsWindowListDone(u8 *p);
void MYSTERY_UTIL_ClearListWindow(u8 *p,u32 i);
void MYSTERY_UTIL_TransferWindowList(u8 *p);
void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap);
void MYSTERY_UTIL_DeleteBmpList(u8 *p);
void MYSTERY_UTIL_DrawBmpList(char *p,char *desc,void *dst);
void MYSTERY_UTIL_CopyBmpList(u8 *p);
struct MysteryUtilDetailWindow *MYSTERY_UTIL_CreateDetailWindow(const struct MysteryUtilDetailDef *in, u16 heap);
void MYSTERY_UTIL_DeleteDetailWindow(u8 *p);
int MYSTERY_UTIL_SetVoice(u8 *p);
int MYSTERY_UTIL_Update(void **p);
void MYSTERY_UTIL_SetListValue(u8 *p,u32 i,u32 value);
void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap);
void MYSTERY_UTIL_DeleteTask(void *p);
void MYSTERY_UTIL_DispatchTask(char *p);
int MYSTERY_UTIL_IsTaskDone(u32 *p);
void MYSTERY_UTIL_SetTaskHandler(u32 *p,u32 a);
void MYSTERY_UTIL_MarkTaskDone(u32 *p);
void MYSTERY_UTIL_SetTaskArg(u32 *p,u32 a);
void MYSTERY_UTIL_GetTaskArg(u32 *p);
void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);
void MYSTERY_UTIL_DeleteActorPair(u8 *p);
void MYSTERY_UTIL_UpdateActorPair(char *p);
void MYSTERY_UTIL_SetActorPairText(char *p,int a,int b,int c);
void MYSTERY_UTIL_SetActorPairColor(u8 *p,int a);
void MYSTERY_UTIL_SetVec(u32 *p,u32 a,u32 b,u32 c);
int MYSTERY_UTIL_IsMenuFinished(u8 *p);
void MYSTERY_UTIL_BuildPaletteRow(char *p,int a,int *out);
s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);
void MYSTERY_UTIL_BlendPaletteRange(u32 a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
/* END mkheaders: generated region */

#endif
