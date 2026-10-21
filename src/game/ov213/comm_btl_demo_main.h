#ifndef GAME_OV213_COMM_BTL_DEMO_MAIN_H
#define GAME_OV213_COMM_BTL_DEMO_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of comm_btl_demo_main.c, prototypes copied from their definitions. */

struct CommBtlDemoArgs;
struct ProcOwner;
struct UiScene;
struct CommBtlDemoMain;
struct CommBtlDemoActorRow;
struct CommBtlDemoRow;
struct CommBtlDemoBattleContext;

#include "../types.h"

int COMM_BTL_DEMO_MAIN_Create(void *manager,int *state,struct CommBtlDemoArgs *args);
int COMM_BTL_DEMO_MAIN_Delete(struct ProcOwner *owner,int unused,const void *cfg,char *p);
int COMM_BTL_DEMO_MAIN_Update(int a,int b,int c,char *p);
void COMM_BTL_DEMO_MAIN_LoadGraphics(int a,u16 heap,int index);
void COMM_BTL_DEMO_MAIN_Exit(struct UiScene *task, char *p);
int COMM_BTL_DEMO_MAIN_Step(void *unused, struct CommBtlDemoMain *p);
void COMM_BTL_DEMO_MAIN_SetupFirstSide(struct CommBtlDemoMain *p);
void COMM_BTL_DEMO_MAIN_SetupSecondSide(struct CommBtlDemoMain *p);
int COMM_BTL_DEMO_MAIN_GetSoundId(int a, int b);
int COMM_BTL_DEMO_MAIN_Tick(struct UiScene *task,char *p);
int COMM_BTL_DEMO_MAIN_Exit2(struct UiScene *task,void *p);
int COMM_BTL_DEMO_MAIN_LayoutRows(int unused,char *p);
int COMM_BTL_DEMO_MAIN_UpdateBattle(struct UiScene *state,unsigned char *p);
int COMM_BTL_DEMO_MAIN_UpdateExit(struct UiScene *task,char *p);
int COMM_BTL_DEMO_MAIN_UpdateEnd(struct UiScene *state,char *p);
int COMM_BTL_DEMO_MAIN_UpdateFadeOut(struct UiScene *a,char *b);
int COMM_BTL_DEMO_MAIN_GetModeIndex(const struct CommBtlDemoArgs *p);
int COMM_BTL_DEMO_MAIN_IsFullPartyMode(u32 x);
int COMM_BTL_DEMO_MAIN_HasVisibleActors(u32 x);
int COMM_BTL_DEMO_MAIN_TypeToFrame(void *p,u32 x);
void COMM_BTL_DEMO_MAIN_InitActorRow(struct CommBtlDemoActorRow *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types);
void COMM_BTL_DEMO_MAIN_DeleteActorRow(struct CommBtlDemoActorRow *p);
void COMM_BTL_DEMO_MAIN_UpdateActorRow(struct CommBtlDemoActorRow *p, u32 time);
void COMM_BTL_DEMO_MAIN_UpdateRowDelay(struct CommBtlDemoActorRow *p,unsigned limit);
void COMM_BTL_DEMO_MAIN_MarkRowDone(struct CommBtlDemoActorRow *p);
void COMM_BTL_DEMO_MAIN_SetRowActorAnim(struct CommBtlDemoActorRow *p,void *list,const u8 *flags,int index);
unsigned COMM_BTL_DEMO_MAIN_CreateRowWindow(unsigned kind,unsigned index);
void COMM_BTL_DEMO_MAIN_InitRowContext(struct CommBtlDemoRow *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c);
void COMM_BTL_DEMO_MAIN_RefreshRowText(struct CommBtlDemoRow *a);
void COMM_BTL_DEMO_MAIN_DeleteRowContext(struct CommBtlDemoRow *p);
void COMM_BTL_DEMO_MAIN_DrawRowText(struct CommBtlDemoRow *p, int a);
void COMM_BTL_DEMO_MAIN_InitRows(struct CommBtlDemoMain *p);
void COMM_BTL_DEMO_MAIN_DeleteRows(char *p);
void COMM_BTL_DEMO_MAIN_UpdateRows(char *p);
void COMM_BTL_DEMO_MAIN_MarkRowsDone(char *p);
void COMM_BTL_DEMO_MAIN_SetActorAnimKind(void *p,int kind,int variant);
void COMM_BTL_DEMO_MAIN_UpdateNetKind(char *p);
void COMM_BTL_DEMO_MAIN_InitBattleContext(struct CommBtlDemoBattleContext *p,const void *owner,void *other,u16 a,u16 b,u8 kind);
void COMM_BTL_DEMO_MAIN_DeleteBattleContext(struct CommBtlDemoBattleContext *p);
void COMM_BTL_DEMO_MAIN_UpdateBattleActors(char *p);
void COMM_BTL_DEMO_MAIN_ShowBattleActor(struct CommBtlDemoBattleContext *p,unsigned i,int kind);
void COMM_BTL_DEMO_MAIN_InitCursor(char *p, void *state, int heap);
void COMM_BTL_DEMO_MAIN_DeleteCursor(char *p);
void *COMM_BTL_DEMO_MAIN_CreateActor(char *p,int a,int b,unsigned short c);
void *COMM_BTL_DEMO_MAIN_CreateSideActor(void *p,int kind,unsigned a);
void COMM_BTL_DEMO_MAIN_InitGraphics(char *p,void *state,int heap);
void COMM_BTL_DEMO_MAIN_DeleteGraphics(char *p);
void COMM_BTL_DEMO_MAIN_DrawGraphics(unsigned char *p);
void COMM_BTL_DEMO_MAIN_InitEffect(u8 *p,unsigned code);
void COMM_BTL_DEMO_MAIN_DeleteEffect(char *p, int object);
void COMM_BTL_DEMO_MAIN_DeleteEffectManager(char *p);
int COMM_BTL_DEMO_MAIN_StartEffect(char *p,int b,int c);
void COMM_BTL_DEMO_MAIN_StartEffects(char *p,int v);
int COMM_BTL_DEMO_MAIN_BindModelPalette(int *p,u32 b,u32 c);
void COMM_BTL_DEMO_MAIN_LoadObject(unsigned char *p, int index);
void COMM_BTL_DEMO_MAIN_UnloadObject(char *p);
void COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(void *a);
int COMM_BTL_DEMO_MAIN_UpdateObjectAnime(unsigned char *p);
void COMM_BTL_DEMO_MAIN_InitializeFlags(unsigned char *p);
int COMM_BTL_DEMO_MAIN_CountFlags(char *p);
void COMM_BTL_DEMO_MAIN_Init3dSystem(void);
/* END mkheaders: generated region */

#endif
