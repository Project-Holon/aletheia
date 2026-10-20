#ifndef GAME_OV180_HALL_OF_FAME_SCENE_H
#define GAME_OV180_HALL_OF_FAME_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hall_of_fame_scene.c, prototypes copied from their definitions. */

struct ClactActor;

#include "../ov180/hall_of_fame_types.h"

void HALL_OF_FAME_InitBackgrounds(void);
void HALL_OF_FAME_ExitBackgrounds(void);
void HALL_OF_FAME_LoadBackgroundGraphics(void);
void HALL_OF_FAME_SetupBlendRegs(void);
void HALL_OF_FAME_InitText(HallOfFameWork *work);
void HALL_OF_FAME_ExitText(HallOfFameWork *work);
void HALL_OF_FAME_StartBgm(HallOfFameWork *work);
void HALL_OF_FAME_ReleaseWaveArc(HallOfFameWork *work);
void HALL_OF_FAME_CollectPartyMons(HallOfFameWork *work);
void HALL_OF_FAME_LoadMonInfo(HallOfFameWork *work);
void HALL_OF_FAME_PrepareMonVoice(HallOfFameWork *work);
void HALL_OF_FAME_Setup3dState(void);
void HALL_OF_FAME_Init3d(HallOfFameWork *work);
void HALL_OF_FAME_Exit3d(HallOfFameWork *work);
void HALL_OF_FAME_DrawMonSprite3d(HallOfFameWork *work);
void HALL_OF_FAME_DrawParticles(HallOfFameWork *work);
void HALL_OF_FAME_InitParticleHeap(void);
void HALL_OF_FAME_ExitParticleHeap(void);
void HALL_OF_FAME_InitParticleManager(void);
void HALL_OF_FAME_ExitParticleManager(void);
void HALL_OF_FAME_CreateMonParticle(HallOfFameWork *work);
void HALL_OF_FAME_DeleteMonParticle(HallOfFameWork *work);
void HALL_OF_FAME_StartMonParticle(HallOfFameWork *work, int effect);
void HALL_OF_FAME_CreateBackdropParticle(HallOfFameWork *work);
void HALL_OF_FAME_DeleteBackdropParticle(HallOfFameWork *work);
void HALL_OF_FAME_StartBackdropParticle(HallOfFameWork *work, int effect);
void HALL_OF_FAME_SetParticleCamera(HallOfFameWork *work, void *particle, int mode);
void HALL_OF_FAME_InitMcss(HallOfFameWork *work);
void HALL_OF_FAME_ExitMcss(HallOfFameWork *work);
void HALL_OF_FAME_AddMonSprite(HallOfFameWork *work);
void HALL_OF_FAME_DeleteMonSprite(HallOfFameWork *work);
void HALL_OF_FAME_MoveMonSpriteX(HallOfFameWork *work, int step);
void HALL_OF_FAME_OnMonAnimDone(HallOfFameWork *work);
void HALL_OF_FAME_StartMonAnimCallback(HallOfFameWork *work);
int HALL_OF_FAME_RunState(HallOfFameWork *work);
int HALL_OF_FAME_StateInit(HallOfFameWork *work);
int HALL_OF_FAME_StateExit(HallOfFameWork *work);
int HALL_OF_FAME_StateWaitFade(HallOfFameWork *work);
int HALL_OF_FAME_StateWaitCounter(HallOfFameWork *work);
int HALL_OF_FAME_StateSetupMonScene(HallOfFameWork *work);
int HALL_OF_FAME_StateTeardownMonScene(HallOfFameWork *work);
int HALL_OF_FAME_StateMonSequence(HallOfFameWork *work);
int HALL_OF_FAME_StateSetupTrainerScene(HallOfFameWork *work);
int HALL_OF_FAME_StateTeardownTrainerScene(HallOfFameWork *work);
int HALL_OF_FAME_StateTrainerScene(HallOfFameWork *work);
int HALL_OF_FAME_BeginFadeIn(HallOfFameWork *work, int nextState);
int HALL_OF_FAME_BeginFadeOut(HallOfFameWork *work, int nextState, int duration);
int HALL_OF_FAME_BeginCountdown(HallOfFameWork *work, int frames);
void HALL_OF_FAME_RandomizeJitter(HallOfFameWork *work);
int HALL_OF_FAME_ApplyJitterStep(HallOfFameWork *work, int actor);
void HALL_OF_FAME_EnableBgEffects(HallOfFameWork *work);
void HALL_OF_FAME_InitActorSystem(HallOfFameWork *work, int subScreen);
void HALL_OF_FAME_ExitActorSystem(HallOfFameWork *work);
void HALL_OF_FAME_UpdateActors(HallOfFameWork *work);
void HALL_OF_FAME_MoveActorBy(HallOfFameWork *work, int actor, short x, short y);
void HALL_OF_FAME_GetActorPos(HallOfFameWork *work, int actor, short *x, short *y);
void HALL_OF_FAME_MoveActorRelative(HallOfFameWork *work, int actor, int dx, int dy);
void HALL_OF_FAME_SetActorVisible(HallOfFameWork *work, int actor, int visible);
void HALL_OF_FAME_PlayActorAnim(HallOfFameWork *work, int actor, int seq);
int HALL_OF_FAME_IsActorAnimActive(HallOfFameWork *work, int actor);
void HALL_OF_FAME_ResetResourceIds(HallOfFameWork *work);
void HALL_OF_FAME_ReleaseCharacter(HallOfFameWork *work, int index);
void HALL_OF_FAME_ReleasePalette(HallOfFameWork *work, int index);
void HALL_OF_FAME_ReleaseCellAnim(HallOfFameWork *work, int index);
void HALL_OF_FAME_ReleaseAllResources(HallOfFameWork *work);
struct ClactActor *HALL_OF_FAME_CreateActorFromTemplate(HallOfFameWork *work, const HallOfFameActorTemplate *tmpl);
void HALL_OF_FAME_DeleteActor(HallOfFameWork *work, int actor);
void HALL_OF_FAME_DeleteAllActors(HallOfFameWork *work);
void HALL_OF_FAME_LoadMonActors(HallOfFameWork *work);
/* END mkheaders: generated region */

#endif
