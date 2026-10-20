#ifndef GAME_OV195_SHINKA_DEMO_EFFECT_H
#define GAME_OV195_SHINKA_DEMO_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of shinka_demo_effect.c, prototypes copied from their definitions. */

struct EffectModel;
struct Ptc;
struct EffectParticle;
typedef struct EffectModel EffectModel;
typedef struct Ptc Ptc;
typedef struct EffectParticle EffectParticle;

#include "../ov195/shinka_demo_graphic_shared_types.h"
#include "../types.h"

ShinkaDemoGraphicNode *SHINKA_DEMO_EFFECT_CreateNodes(u16 heap, u16 n);
void SHINKA_DEMO_EFFECT_FreeNode(void *node);
EffectModel *SHINKA_DEMO_EFFECT_Create(u16 heap, u32 x);
void SHINKA_DEMO_EFFECT_Destroy(char *model);
void SHINKA_DEMO_EFFECT_Main(EffectModel *model);
void SHINKA_DEMO_EFFECT_Draw(char *model);
void SHINKA_DEMO_EFFECT_Trigger(char *model);
void SHINKA_DEMO_EFFECT_StartIntro(int *model);
void SHINKA_DEMO_EFFECT_AdvanceState(int *model);
int SHINKA_DEMO_EFFECT_IsState4(int *model);
int SHINKA_DEMO_EFFECT_IsCameraReady(int *model);
Ptc *SHINKA_DEMO_EFFECT_CreateParticle(u16 heap, u16 cueCount, void *cueTable);
void SHINKA_DEMO_EFFECT_DeleteParticle(char *particle);
void SHINKA_DEMO_EFFECT_UpdateParticle(EffectParticle *particle);
void SHINKA_DEMO_EFFECT_DrawParticle(int unused);
void SHINKA_DEMO_EFFECT_SetParticleActive(char *particle);
void SHINKA_DEMO_EFFECT_SetParticleTimer(char *particle,u32 timer);
void SHINKA_DEMO_EFFECT_SetParticleTimerRaw(EffectParticle *particle, s32 timer);
void SHINKA_DEMO_EFFECT_InitUnit(char *model);
void SHINKA_DEMO_EFFECT_DeleteUnit(char *model);
void SHINKA_DEMO_EFFECT_DrawNodes(EffectModel *model);
void SHINKA_DEMO_EFFECT_SetupNode(EffectModel *model);
void SHINKA_DEMO_EFFECT_RemoveUnit(char *model);
void SHINKA_DEMO_EFFECT_UpdateAnime(char *model);
void SHINKA_DEMO_EFFECT_AnimSetState1(EffectModel *model);
int SHINKA_DEMO_EFFECT_AnimIsState2(EffectModel *model);
void SHINKA_DEMO_EFFECT_AnimSetState3(EffectModel *model);
int SHINKA_DEMO_EFFECT_AnimIsState0(EffectModel *model);
/* END mkheaders: generated region */

#endif
