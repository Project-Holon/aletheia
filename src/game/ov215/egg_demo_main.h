#ifndef GAME_OV215_EGG_DEMO_MAIN_H
#define GAME_OV215_EGG_DEMO_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of egg_demo_main.c, prototypes copied from their definitions. */

struct EggDemoArgs;
struct Proc;
struct TcbTask;
struct EggDemoWork;

#include "../types.h"

int EGG_DEMO_MAIN_Create(void *owner,int unused,struct EggDemoArgs *args);
int EGG_DEMO_MAIN_Delete(struct Proc *task,int unused,struct EggDemoArgs *args,char *work);
int EGG_DEMO_MAIN_Update(u32 unused0,u32 unused1,struct EggDemoArgs *args,u32 *work);
void EGG_DEMO_MAIN_OnVBlank(struct TcbTask *unused, void *work);
void EGG_DEMO_MAIN_Init(struct EggDemoArgs *args,char *work);
void EGG_DEMO_MAIN_DeleteResources(struct EggDemoArgs *args,char *work);
void EGG_DEMO_MAIN_LoadGraphics(void *unused, char *work);
void EGG_DEMO_MAIN_Noop(struct EggDemoArgs *args, char *work);
void EGG_DEMO_MAIN_InitActors(void *unused, struct EggDemoWork *work);
void EGG_DEMO_MAIN_DeleteActors(void *unused, char *work);
void EGG_DEMO_MAIN_StartActorAnims(void *unused, struct EggDemoWork *work);
int EGG_DEMO_MAIN_AreActorAnimsDone(void *unused, struct EggDemoWork *work);
int EGG_DEMO_MAIN_StartFadeOutBgm(struct EggDemoArgs *args, char *work);
void EGG_DEMO_MAIN_NoopB(struct EggDemoArgs *args, char *work);
void EGG_DEMO_MAIN_UpdateBgm(u8 *args, u8 *work);
int EGG_DEMO_MAIN_IsBgmFadeOut(void *unused,char *work);
void EGG_DEMO_MAIN_PlayBgm(void *unused, char *work);
int EGG_DEMO_MAIN_IsBgmPlaying(void *unused, char *work);
void EGG_DEMO_MAIN_LoadBgm1(void *unused, char *work);
int EGG_DEMO_MAIN_IsBgm1Loaded(void *unused, char *work);
void EGG_DEMO_MAIN_PushBgm(void *args, void *work);
void EGG_DEMO_MAIN_PopBgm(void *args, void *work);
void EGG_DEMO_MAIN_LoadBgm2(void *unused, char *work);
int EGG_DEMO_MAIN_IsBgm2Loading(void *unused, char *work);
void EGG_DEMO_MAIN_StopBgm(void *unused, char *work);
int EGG_DEMO_MAIN_IsBgmStopped(void *unused, char *work);
/* END mkheaders: generated region */

#endif
