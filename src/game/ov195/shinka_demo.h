#ifndef GAME_OV195_SHINKA_DEMO_H
#define GAME_OV195_SHINKA_DEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shinka_demo.c, prototypes copied from their definitions. */

#include "../types.h"

int SHINKA_DEMO_Create(void *owner,int unused,u8 *app);
int SHINKA_DEMO_Destroy(void *a, int unused, int b, int *scene);
int SHINKA_DEMO_Main(int unused0,int unused1,char *a,char *s);
void SHINKA_DEMO_DeleteScene(int unused, int *scene);
void SHINKA_DEMO_StartBgm(u8 *app, u8 *scene);
void SHINKA_DEMO_Noop(int unused0, int *unused1);
void SHINKA_DEMO_UpdateBgm(char *app, char *scene);
int SHINKA_DEMO_IsBgmState1(int unused, int *scene);
void SHINKA_DEMO_RestoreBgm(char *app, char *scene);
void SHINKA_DEMO_PlayEvolutionBgm(int unused, int *scene);
int SHINKA_DEMO_IsBgmState2(int unused, int *scene);
void SHINKA_DEMO_StartEvolutionBgm(int unused, char *scene);
void SHINKA_DEMO_PushBgm(int unused, int *scene);
void SHINKA_DEMO_PopBgm(int unused, int *scene);
int SHINKA_DEMO_IsBgmState4(int unused, int *scene);
void SHINKA_DEMO_FadeOutBgm(int unused, char *scene);
int SHINKA_DEMO_IsBgmState6(int unused, char *scene);
void SHINKA_DEMO_StartResultBgm(int unused, int *scene);
int SHINKA_DEMO_IsBgmState7Or8(int unused, int *scene);
void SHINKA_DEMO_PlayResultBgm(int unused, int *scene);
void SHINKA_DEMO_StopBgm(int unused, char *scene);
void SHINKA_DEMO_LoadSprites(int unused, char *scene);
void SHINKA_DEMO_Noop2(int unused0, int *unused1);
void SHINKA_DEMO_CreateActors(int unused, char *scene);
void SHINKA_DEMO_DeleteActors(void *unused,char *scene);
void SHINKA_DEMO_ResetActorAnims(int unused, int *scene);
int SHINKA_DEMO_AreActorAnimsDone(int unused, int *scene);
void SHINKA_DEMO_MainTask(struct TcbTask *task, void *scene);
void SHINKA_DEMO_SetupWindows(int unused, char *scene);
void SHINKA_DEMO_DeleteWindows(int task, int *scene);
void SHINKA_DEMO_UpdateWindows(int unused, char *scene);
int SHINKA_DEMO_PrintStreamCallback(int a);
void SHINKA_DEMO_PrintText(char *scene, u32 msgBank, u32 msgId, u32 callback, u32 kind0, u32 value0, u32 kind1, u32 value1);
int SHINKA_DEMO_AdvanceText(char *scene);
int SHINKA_DEMO_IsConfirmPressed(char *unused);
void SHINKA_DEMO_ClearText(char *scene, int fillColor);
void SHINKA_DEMO_SetupMessageBox(int unused, int *p, int flag);
void SHINKA_DEMO_CreateConfirmMenu(int unused, char *scene);
void SHINKA_DEMO_DeleteConfirmMenu(void *unused,char *scene);
void SHINKA_DEMO_SetMenuText(char *scene, u32 msgBankC, u32 msgIdC, u32 kindC0, u32 valueC0, u32 kindC1, u32 valueC1, u32 msgBankD, u32 msgIdD, u32 kindD0, u32 valueD0, u32 kindD1, u32 valueD1);
u32 SHINKA_DEMO_BuildString(u32 heap, u32 msgBank, u32 msgId, u32 kind0, u32 value0, u32 kind1, u32 value1);
void SHINKA_DEMO_AddShedinja(u32 *app, char *scene);
void SHINKA_DEMO_ClearHeldItem(int unused, char *scene);
void SHINKA_DEMO_Setup3d(void);
/* END mkheaders: generated region */

#endif
