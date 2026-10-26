#ifndef GAME_OV195_SHINKA_DEMO_H
#define GAME_OV195_SHINKA_DEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shinka_demo.c, prototypes copied from their definitions. */

struct App;
struct Scene;
struct TcbTask;
struct MsgBank;
struct Strbuf;
typedef struct App App;
typedef struct Scene Scene;

#include "../types.h"
#include "../arm9/printsys_shared_types.h"

int SHINKA_DEMO_Create(void *owner,int unused,App *app);
int SHINKA_DEMO_Destroy(void *a, int unused, App *b, Scene *scene);
int SHINKA_DEMO_Main(int unused0,int unused1,App *a,Scene *s);
void SHINKA_DEMO_SetupScene(App *a, Scene *s);
void SHINKA_DEMO_DeleteScene(App *unused, Scene *scene);
void SHINKA_DEMO_StartBgm(App *app, Scene *scene);
void SHINKA_DEMO_Noop(App *unused0, Scene *unused1);
void SHINKA_DEMO_UpdateBgm(App *app, Scene *scene);
int SHINKA_DEMO_IsBgmState1(App *unused, Scene *scene);
void SHINKA_DEMO_RestoreBgm(App *app, Scene *scene);
void SHINKA_DEMO_PlayEvolutionBgm(App *unused, Scene *scene);
int SHINKA_DEMO_IsBgmState2(App *unused, Scene *scene);
void SHINKA_DEMO_StartEvolutionBgm(App *unused, Scene *scene);
void SHINKA_DEMO_PushBgm(App *unused, Scene *scene);
void SHINKA_DEMO_PopBgm(App *unused, Scene *scene);
int SHINKA_DEMO_IsBgmState4(App *unused, Scene *scene);
void SHINKA_DEMO_FadeOutBgm(App *unused, Scene *scene);
int SHINKA_DEMO_IsBgmState6(App *unused, Scene *scene);
void SHINKA_DEMO_StartResultBgm(App *unused, Scene *scene);
int SHINKA_DEMO_IsBgmState7Or8(App *unused, Scene *scene);
void SHINKA_DEMO_PlayResultBgm(App *unused, Scene *scene);
void SHINKA_DEMO_StopBgm(App *unused, Scene *scene);
void SHINKA_DEMO_LoadSprites(App *unused, Scene *scene);
void SHINKA_DEMO_Noop2(App *unused0, Scene *unused1);
void SHINKA_DEMO_CreateActors(App *unused, Scene *scene);
void SHINKA_DEMO_DeleteActors(App *unused,Scene *scene);
void SHINKA_DEMO_ResetActorAnims(App *unused, Scene *scene);
int SHINKA_DEMO_AreActorAnimsDone(App *unused, Scene *scene);
void SHINKA_DEMO_MainTask(struct TcbTask *task, void *sceneArg);
void SHINKA_DEMO_SetupWindows(App *unused, Scene *scene);
void SHINKA_DEMO_DeleteWindows(App *task, Scene *scene);
void SHINKA_DEMO_UpdateWindows(App *unused, Scene *scene);
int SHINKA_DEMO_PrintStreamCallback(int a);
void SHINKA_DEMO_PrintText(Scene *scene, struct MsgBank *msgBank, u32 msgId, PrintCallback callback, u32 kind0, void *value0, u32 kind1, void *value1);
int SHINKA_DEMO_AdvanceText(Scene *scene);
int SHINKA_DEMO_IsConfirmPressed(Scene *unused);
void SHINKA_DEMO_ClearText(Scene *scene, int fillColor);
void SHINKA_DEMO_SetupMessageBox(App *unused, Scene *p, int flag);
void SHINKA_DEMO_CreateConfirmMenu(App *unused, Scene *scene);
void SHINKA_DEMO_DeleteConfirmMenu(App *unused,Scene *scene);
void SHINKA_DEMO_SetMenuText(Scene *scene, struct MsgBank *msgBankC, u32 msgIdC, u32 kindC0, void *valueC0, u32 kindC1, void *valueC1, struct MsgBank *msgBankD, u32 msgIdD, u32 kindD0, void *valueD0, u32 kindD1, void *valueD1);
struct Strbuf *SHINKA_DEMO_BuildString(u32 heap, struct MsgBank *msgBank, u32 msgId, u32 kind0, void *value0, u32 kind1, void *value1);
void SHINKA_DEMO_AddShedinja(App *app, Scene *scene);
void SHINKA_DEMO_ClearHeldItem(App *unused, Scene *scene);
void SHINKA_DEMO_Setup3d(void);
/* END mkheaders: generated region */

#endif
