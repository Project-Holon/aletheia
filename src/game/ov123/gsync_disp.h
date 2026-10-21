#ifndef GAME_OV123_GSYNC_DISP_H
#define GAME_OV123_GSYNC_DISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsync_disp.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov123/gsync_common_types.h"

struct ClactAnimCommand;

u8 *GSYNC_DISP_Init(u32 heap);
void GSYNC_DISP_Draw(GsyncDispWork *disp);
void GSYNC_DISP_Exit(GsyncDispWork *disp);
void GSYNC_DISP_InitBgLayers(GsyncDispWork *disp);
void GSYNC_DISP_VBlankTask(void *unused, GsyncDispWork *disp);
void GSYNC_DISP_LoadResources(GsyncDispWork *disp);
void GSYNC_DISP_CreateEffectActorDefault(GsyncDispWork *disp);
void GSYNC_DISP_CreateSlotActor(GsyncDispWork *disp,unsigned int slotIndex);
void GSYNC_DISP_SetSlotAnimSeq(GsyncDispWork *disp, int slotIndex, u32 animSeq);
void GSYNC_DISP_SetSlotAnimCommand(GsyncDispWork *disp, int slotIndex, struct ClactAnimCommand *command);
void GSYNC_DISP_DeleteSlotActor(GsyncDispWork *disp, int slotIndex);
void GSYNC_DISP_CreateEffectActorAt(GsyncDispWork *disp, int posX, int posY);
void GSYNC_DISP_CreateSlotActorAt(GsyncDispWork *disp, unsigned int slotIndex);
void GSYNC_DISP_SetMainActorAnimSeq(GsyncDispWork *disp);
void GSYNC_DISP_DeleteMainActor(GsyncDispWork *disp);
void GSYNC_DISP_LoadEffectResources(GsyncDispWork *disp);
void GSYNC_DISP_CreateMonIconActor(GsyncDispWork *disp, void *mon, int slotIndex);
void GSYNC_DISP_EnableActorAutoAnim(GsyncDispWork *disp);
void GSYNC_DISP_RestartActorAnim(GsyncDispWork *disp);
void GSYNC_DISP_PaletteWaveTask(void *unused, GsyncDispWork *disp);
void GSYNC_DISP_StartPaletteWave(GsyncDispWork *disp);
void GSYNC_DISP_SetFadeDirection(GsyncDispWork *disp,int flag);
void GSYNC_DISP_UpdateBlendFade(GsyncDispWork *disp);
void GSYNC_DISP_UpdateProgressPosition(GsyncDispWork *disp, int progress);
void GSYNC_DISP_SpawnParticleLeft(GsyncDispWork *disp, int slotIndex);
void GSYNC_DISP_HideParticle(GsyncDispParticle *particle);
void GSYNC_DISP_SpawnParticleRight(GsyncDispWork *disp, int slotIndex);
void GSYNC_DISP_UpdateParticle(GsyncDispParticle *particle);
void GSYNC_DISP_UpdateParticles(GsyncDispWork *disp);
void GSYNC_DISP_SetIconRecord(GsyncDispWork *disp,int slotIndex,int species,int form,int gender);
void GSYNC_DISP_SetIconRecordSpecies(GsyncDispWork *disp, int slotIndex, u16 species);
void GSYNC_DISP_LoadIconResources(GsyncDispWork *disp);
void GSYNC_DISP_CopyIconPaletteMain(GsyncDispWork *disp,int slotIndex,void *actor);
void GSYNC_DISP_CopyIconPaletteSub(GsyncDispWork *disp,int slotIndex,void *actor);
void GSYNC_DISP_CreatePokeIconActor(GsyncDispWork *disp);
void GSYNC_DISP_CreateBackdropActors(GsyncDispWork *disp);
/* END mkheaders: generated region */

#endif
