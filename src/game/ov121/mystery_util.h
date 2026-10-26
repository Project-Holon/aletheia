#ifndef GAME_OV121_MYSTERY_UTIL_H
#define GAME_OV121_MYSTERY_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_util.c, prototypes copied from their definitions. */

struct PrintQueue;
struct MsgBank;
struct GfFont;
struct Strbuf;
struct MysteryUtilDetailWindow;
struct MysteryUtilDetailDef;
struct MysteryUtilTask;
struct MysteryUtilActorPair;
typedef struct MysteryUtilDetailWindow MysteryUtilDetailWindow;
typedef struct MysteryUtilTask MysteryUtilTask;
typedef struct MysteryUtilActorPair MysteryUtilActorPair;

#include "../types.h"
#include "../ov121/mystery_util_shared_types.h"

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, struct PrintQueue *h, u16 heap);
void MYSTERY_UTIL_DeleteWindow(u8 *p);
void MYSTERY_UTIL_ClearWindow(u8 *p);
void MYSTERY_UTIL_ShowMessage(u8 *p, struct MsgBank *a, int b, struct GfFont *c);
void MYSTERY_UTIL_ShowString(u8 *p, struct Strbuf *a, struct GfFont *b);
void MYSTERY_UTIL_SetColor(u8 *p,unsigned v);
void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);
int MYSTERY_UTIL_IsMessageDone(u8 *p);
void MYSTERY_UTIL_TransferWindowChars(u8 *p);
void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, struct PrintQueue *c, struct GfFont *d, u16 heap);
void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, struct PrintQueue *c, struct GfFont *d, u16 heap);
void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);
void MYSTERY_UTIL_SetMenuMessage(u8 *a, struct MsgBank *b, int c, int d);
void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode);
unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
void MYSTERY_UTIL_ResetMenuWindow(u8 *p);
void *MYSTERY_UTIL_CreateMenu(const MysteryUtilMenuDef *p,u16 heap);
void MYSTERY_UTIL_DeleteMenu(u8 *p);
int MYSTERY_UTIL_UpdateMenu(char *p);
void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,struct PrintQueue *d,struct MsgBank *e,struct GfFont *f,u16 heap);
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
void MYSTERY_UTIL_DeleteDetailWindow(MysteryUtilDetailWindow *p);
int MYSTERY_UTIL_SetVoice(MysteryUtilDetailWindow *p);
int MYSTERY_UTIL_Update(MysteryUtilDetailWindow *p);
void MYSTERY_UTIL_SetListValue(MysteryUtilDetailWindow *p,u32 i,u32 value);
void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap);
void MYSTERY_UTIL_DeleteTask(void *p);
void MYSTERY_UTIL_DispatchTask(char *p);
int MYSTERY_UTIL_IsTaskDone(MysteryUtilTask *p);
void MYSTERY_UTIL_SetTaskHandler(MysteryUtilTask *p, void (*a)(void *, int *, void *));
void MYSTERY_UTIL_MarkTaskDone(MysteryUtilTask *p);
void MYSTERY_UTIL_SetTaskArg(MysteryUtilTask *p,u32 a);
void MYSTERY_UTIL_GetTaskArg(MysteryUtilTask *p);
void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);
void MYSTERY_UTIL_DeleteActorPair(MysteryUtilActorPair *p);
void MYSTERY_UTIL_UpdateActorPair(MysteryUtilActorPair *p);
void MYSTERY_UTIL_SetActorPairText(MysteryUtilActorPair *p,struct MsgBank *a,int b,struct GfFont *c);
void MYSTERY_UTIL_SetActorPairColor(MysteryUtilActorPair *p,int a);
void MYSTERY_UTIL_SetVec(MysteryUtilActorPair *p,u32 a,u32 b,u32 c);
int MYSTERY_UTIL_IsMenuFinished(MysteryUtilActorPair *p);
void MYSTERY_UTIL_BuildPaletteRow(MysteryUtilActorPair *p,struct GfFont *a,int *out);
s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);
void MYSTERY_UTIL_BlendPaletteRange(u32 a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
/* END mkheaders: generated region */

#endif
