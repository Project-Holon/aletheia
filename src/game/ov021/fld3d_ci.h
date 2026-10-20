#ifndef GAME_OV021_FLD3D_CI_H
#define GAME_OV021_FLD3D_CI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld3d_ci.c, prototypes copied from their definitions. */

#include "../ov021/fld3d_ci_types.h"
#include "../types.h"
#include "../ov021/fld3d_ci_types.h"

Fld3dCi *FLD3D_CI_Create(u32 heapId, FldParticle *particle);
void FLD3D_CI_Delete(Fld3dCi *ci);
int FLD3D_CI_SetupEffectUnit(Fld3dCi *ci, G3dUtilSetup *setup);
void FLD3D_CI_DrawEffect(Fld3dCi *ci);
void *FLD3D_CI_StartSequence(void *gameSystem, Fld3dCi *ci, int sequenceId);
void *FLD3D_CI_StartPokemonSequence(void *gameSystem, Fld3dCi *ci, int species, int form, int attr6E, int personality, int attr4C);
void *FLD3D_CI_StartPartyMemberSequence(void *gameSystem, Fld3dCi *ci, int partyPos);
void *FLD3D_CI_StartNameSequence(void *gameSystem, Fld3dCi *ci, int tableIndex, int fadeVariant);
int FLD3D_CI_EventMain(void *event, int *state, Fld3dCiEventWork *work);
int FLD3D_CI_UpdateStartDelays(Fld3dCi *ci);
int FLD3D_CI_UpdateTrackA(Fld3dCi *ci);
int FLD3D_CI_UpdateTrackB(Fld3dCi *ci);
void FLD3D_CI_SetupSequence(void *event, Fld3dCi *ci, Fld3dCiSeq *seq, int sequenceId);
void FLD3D_CI_EndSequence(Fld3dCi *ci, Fld3dCiSeq *seq);
void FLD3D_CI_StartTrack(Fld3dCi *ci, int track);
void FLD3D_CI_FollowTargetCallback(Fld3dCiFollow *follow);
void FLD3D_CI_LoadSequence(Fld3dCiSeq *seq, u32 sequenceId, u32 heapId);
void FLD3D_CI_FreeSequence(Fld3dCiSeq *seq);
void FLD3D_CI_StartScreenCapture(Fld3dCi *ci);
void FLD3D_CI_CaptureTask(void *task, u32 *done);
void FLD3D_CI_SaveLayerPriorities(Fld3dCi *ci);
void FLD3D_CI_SaveVisiblePlanes(Fld3dCi *ci);
void FLD3D_CI_RestoreLayerPriorities(Fld3dCi *ci);
void FLD3D_CI_RestoreVisiblePlanes(Fld3dCi *ci);
int FLD3D_CI_PokemonExtraTask(void *event, int *state);
int FLD3D_CI_PokemonFinishStep(void *event, Fld3dCi *ci);
void FLD3D_CI_LoadPokemonIconTexture(Fld3dCi *ci);
int FLD3D_CI_FadeOutTask(void *event, int *state);
int FLD3D_CI_FadeInTask(void *event, int *state);
int FLD3D_CI_FadeInAltTask(void *event, u32 *state);
int FLD3D_CI_IsAltFadeSequence(u16 sequenceId);
void FLD3D_CI_LoadNameTexture(Fld3dCi *ci, const char *texName, const char *plttName, u32 chrFile, u32 plttFile);
int FLD3D_CI_NameFinishStep(void *event, Fld3dCi *ci);
int FLD3D_CI_NameExtraTask(void *event, int *state);
int FLD3D_CI_GetTexDataOffset(Fld3dCiTexBlock *texBlock, Fld3dCiTexDictEntry *entry);
int FLD3D_CI_GetPlttDataOffset(Fld3dCiTexBlock *texBlock, Fld3dCiPlttDictEntry *entry);
int FLD3D_CI_FindTexture(Fld3dCiTexBlock *texBlock, const char *name);
int FLD3D_CI_FindPalette(Fld3dCiTexBlock *texBlock, const char *name);
void FLD3D_CI_CopyName(char *dst, const char *src);
void FLD3D_CI_DrawMessageTexture(void *playerStatus, Fld3dCi *ci, const char *texName, const char *plttName, u32 msgId, u32 centered);
void *FLD3D_CI_StartMessageSequence(void *gameSystem, Fld3dCi *ci, u32 nameMsgId);
void FLD3D_CI_DarkenCapturedScreen(u32 unused);
void FLD3D_CI_InitEventWork(Fld3dCi *ci, Fld3dCiEventWork *work);
void FLD3D_CI_PlayCueSound(Fld3dCi *ci);
void FLD3D_CI_DisplayRestoreTask(void *task, u32 *done);
/* END mkheaders: generated region */

#endif
