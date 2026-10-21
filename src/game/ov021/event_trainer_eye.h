#ifndef GAME_OV021_EVENT_TRAINER_EYE_H
#define GAME_OV021_EVENT_TRAINER_EYE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_trainer_eye.c, prototypes copied from their definitions. */

struct GridPos;
typedef struct GridPos GridPos;

#include "../ov020/event_mapchange_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../types.h"
#include "../ov021/field_encount_types.h"
#include "../ov021/event_trainer_eye_types.h"

struct GameEvent *EVENT_TRAINER_EYE_Check(FieldMap *fieldMap);
int EVENT_TRAINER_EYE_GetPlayerDistance(Mmdl *mmdl, u16 dir, int range, FieldEncount *encount);
int EVENT_TRAINER_EYE_FindTrainer(FieldMap *fieldMap, Mmdl *exclude, TrainerEyeHit *out);
int EVENT_TRAINER_EYE_GetSightDistance(FieldEncount *encount, Mmdl *trainer, Mmdl *player, u16 *outDir);
int EVENT_TRAINER_EYE_CheckSight(int dir, int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightUp(int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightDown(int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightLeft(int range, const GridPos *trainerPos, const GridPos *targetPos);
int EVENT_TRAINER_EYE_CheckSightRight(int range, const GridPos *trainerPos, const GridPos *targetPos);
GameEvent *EVENT_TRAINER_EYE_CreatePairEvent(void *owner, TrainerEyeWork *first, TrainerEyeWork *second);
TrainerEyeWork *EVENT_TRAINER_EYE_Create(u32 heapId, FieldMap *fieldMap, TrainerEyeHit *hit, int recordIndex);
int EVENT_TRAINER_EYE_StepResumeMove(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepFaceTarget(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitPlayer(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepStartTurn(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitTurn(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepStartMark(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitMark(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepStartAlert(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitAlert(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepDelay(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepSelectApproach(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepApproach(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitStep(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepAdjacent(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepPlayerFaceTrainer(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepWaitPlayerFace(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepRelease(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_StepDone(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_Run(TrainerEyeWork *work);
int EVENT_TRAINER_EYE_UpdatePairEvent(void *eventSys, void *gameSystem, void *work);
int EVENT_TRAINER_EYE_GetSightType(Mmdl *mmdl);
int EVENT_TRAINER_EYE_IsPathBlocked(Mmdl *mmdl, u16 dir, int distance, FieldEncount *encount);
int EVENT_TRAINER_EYE_GetTrainerId(Mmdl *mmdl);
int EVENT_TRAINER_EYE_IsTrainerDefeated(FieldMap *fieldMap, Mmdl *mmdl);
void EVENT_TRAINER_EYE_FillHit(TrainerEyeHit *hit, Mmdl *trainer, u32 distance, u32 direction);
Mmdl *EVENT_TRAINER_EYE_FindPartner(Mmdl *mmdl, u16 trainerId);
struct GameEvent *EVENT_TRAINER_EYE_CreateScriptWork(FieldMap *fieldMap, Mmdl *trainer);
/* END mkheaders: generated region */

#endif
