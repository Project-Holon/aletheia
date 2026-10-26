#ifndef OV180_HALL_OF_FAME_H
#define OV180_HALL_OF_FAME_H
/* Functions of the Hall of Fame ceremony, shared by its three source files. */
#include "hall_of_fame_types.h"

struct Proc;
struct ClactActor;

/* hall_of_fame_proc.c */
int HALL_OF_FAME_ProcInit(struct Proc *proc, void *unused, HallOfFameArgs *args);
int HALL_OF_FAME_ProcMain(int proc, int unused, int unused2, HallOfFameWork *work);
int HALL_OF_FAME_ProcExit(struct Proc *proc);
void HALL_OF_FAME_AddVBlankTaskMon(HallOfFameWork *work);
void HALL_OF_FAME_AddVBlankTaskTrainer(HallOfFameWork *work);
void HALL_OF_FAME_RemoveVBlankTask(HallOfFameWork *work);
void HALL_OF_FAME_VBlankMon(void);
void HALL_OF_FAME_VBlankTrainer(void);
void HALL_OF_FAME_SetVramBanks(int subScreen);
struct DispVramCfg *HALL_OF_FAME_GetVramBanksAddr(int subScreen);
void HALL_OF_FAME_InitGraphicsSystem(void);
void HALL_OF_FAME_ExitGraphicsSystem(void);
void HALL_OF_FAME_SetupDisplay(void);

/* hall_of_fame_scene.c */
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
void HALL_OF_FAME_OnMonAnimDone(void *param, u32 frame);
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

/* hall_of_fame_sprites.c */
void HALL_OF_FAME_LoadUiPalette(HallOfFameWork *work);
void HALL_OF_FAME_DeleteTextPlate(HallOfFameWork *work, int plate);
void HALL_OF_FAME_DeleteAllTextPlates(HallOfFameWork *work);
void HALL_OF_FAME_PrintToPlate(HallOfFameWork *work, int plate, void *font, void *str, int x, int y);
void HALL_OF_FAME_CreateMonPlates(HallOfFameWork *work);
void HALL_OF_FAME_PrintMonInfo(HallOfFameWork *work);
void HALL_OF_FAME_CreateTrainerPlates(HallOfFameWork *work);
void HALL_OF_FAME_UpdatePlatePositions(HallOfFameWork *work);
void HALL_OF_FAME_SetPlateEnabled(HallOfFameWork *work, int plate, unsigned enabled);
void HALL_OF_FAME_LoadUiResources(HallOfFameWork *work);
void HALL_OF_FAME_CreateMonSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DeleteMonSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DrawMonScene(HallOfFameWork *work);
void HALL_OF_FAME_CreateTrainerSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DeleteTrainerSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DrawTrainerScene(HallOfFameWork *work);
void HALL_OF_FAME_SpawnSparkles(HallOfFameWork *work);

#endif
