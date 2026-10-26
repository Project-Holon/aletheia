#ifndef GAME_OV218_UN_SELECT_H
#define GAME_OV218_UN_SELECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of un_select.c, prototypes copied from their definitions. */

struct Proc;
struct TouchBar;
struct TaskMenu;
struct MsgBank;
struct Obj;
struct Unit;
typedef struct Obj Obj;

#include "../types.h"

struct TcbTask;

int UN_SELECT_SceneCreate(void *owner,int *state,char *input,u8 *p);
int UN_SELECT_SceneDelete(struct Proc *ctx, int *state, void *unused, char *p);
int UN_SELECT_SceneUpdate(void *ctx, int *state, void *unused, char *p);
void UN_SELECT_LoadBg(u8 *p, u16 heap);
struct TouchBar *UN_SELECT_CreateTouchBar(struct Unit *unit, int heap);
void UN_SELECT_Delete(u8 *p);
void UN_SELECT_UpdateTouchBar(struct TouchBar *p);
struct TaskMenu *UN_SELECT_OpenTaskMenu(void *arg, struct MsgBank *bank, u32 heap);
void UN_SELECT_CloseTaskMenu(struct TaskMenu *p);
void UN_SELECT_UpdateTaskMenu(Obj *p);
void UN_SELECT_InitRecord(void);
void UN_SELECT_RequestBrightness(void);
void *UN_SELECT_Create(u16 heap);
void UN_SELECT_DeleteRecord(char *p);
void UN_SELECT_Main(char *p);
void UN_SELECT_DrawMessage(char *p, u32 id);
int UN_SELECT_UpdateMessage(char *p);
void UN_SELECT_DrawWindowBorder(u8 *p);
void *UN_SELECT_GetMsgData(u8 *p);
void *UN_SELECT_GetPrintQue(u8 *p);
struct MsgBank *UN_SELECT_GetFont(char *p);
void UN_SELECT_UpdateFrameList(u8 *p, u32 a, u32 b, u8 *c, u32 d);
void UN_SELECT_ScrollFrameList(u8 *p);
void UN_SELECT_ScrollFrameListDelta(u8 *p,int delta);
void UN_SELECT_CreateFrameList(char *p);
void UN_SELECT_DeleteFrameList(char *p);
char *UN_SELECT_CreateSceneWork(void *owner,char *input);
void UN_SELECT_SetMode(u8 *p, int mode);
int UN_SELECT_IsListDone(void);
int UN_SELECT_SceneStepList(unsigned char *task,char *p);
int UN_SELECT_IsMessageDone(void);
u32 UN_SELECT_SceneStepMessage(u8 *a, u8 *b);
int UN_SELECT_SceneStepMenu(unsigned char *task, char *ctx);
int UN_SELECT_IsFadeDone(void);
int UN_SELECT_SceneStepFade(unsigned char *task, char *ctx);
int UN_SELECT_SceneStepMessageIdle(void *unused, char *p);
int UN_SELECT_SceneStepMenuOut(unsigned char *task, char *ctx);
void UN_SELECT_Callback(struct TcbTask *unused0, void *unused1);
void UN_SELECT_LoadActors(char *ctx);
void UN_SELECT_ReleaseActors(char *p);
void UN_SELECT_SetupActors(char *p);
void UN_SELECT_DeleteActor(char *p);
struct Obj *UN_SELECT_CreateActor(struct Unit *owner,char *p);
void UN_SELECT_SetActorVisible(char *ctx);
void UN_SELECT_ScrollActorsBy(const char *p,int delta);
void UN_SELECT_InitActorPositions(char *ctx);
void UN_SELECT_SetActorX(char *p,int v);
void UN_SELECT_SetActorY(char *p,int y);
void UN_SELECT_SetActorPos(char *p, int sel, u32 y);
int UN_SELECT_SetActorPosEx(void **base,u32 i,u32 space,int y);
int UN_SELECT_ContainsItem(char *p, int v);
unsigned int UN_SELECT_FindTableIndex(int v);
void UN_SELECT_SetupDisplay(void);
/* END mkheaders: generated region */

#endif
