#ifndef GAME_OV043_FIELD_GIMMICK_LIFT_ELEVATOR_H
#define GAME_OV043_FIELD_GIMMICK_LIFT_ELEVATOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_lift_elevator.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov043/field_gimmick_lift_elevator_types.h"

void FIELD_GIMMICK_LIFT_ELEVATOR_Init(void *fieldMap);
void FIELD_GIMMICK_LIFT_ELEVATOR_Exit(u8 *fieldMap);
void FIELD_GIMMICK_LIFT_ELEVATOR_Update(u8 *fieldMap);
void *FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent(void *gameSystem, int liftIndex);
struct GameEvent;
struct GameSystem;
struct GameEvent *FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent(struct GameSystem *gameSystem, int isRising);
int FIELD_GIMMICK_LIFT_ELEVATOR_LiftEventMain(void *event, int *seq);
int FIELD_GIMMICK_LIFT_ELEVATOR_ElevatorEventMain(void *event, int *seq);
int FIELD_GIMMICK_LIFT_ELEVATOR_IsLiftArrived(FieldGimmickLiftElevatorWork *work);
int FIELD_GIMMICK_LIFT_ELEVATOR_IsInLiftZone(u8 liftIndex, int tileX, int tileZ);
void FIELD_GIMMICK_LIFT_ELEVATOR_ShowLiftAnime(FieldGimmickLiftElevatorSave *save, void *expObj, int liftIndex);
int FIELD_GIMMICK_LIFT_ELEVATOR_GetLiftAnimeIndex(FieldGimmickLiftElevatorSave *save, int liftIndex);
void FIELD_GIMMICK_LIFT_ELEVATOR_UpdateBigLift(void *gameSystem);
void FIELD_GIMMICK_LIFT_ELEVATOR_ShowElevatorIdleAnime(void *expObj);
void FIELD_GIMMICK_LIFT_ELEVATOR_StartCameraShake(u8 liftIndex, int stepY, int isStart, struct FieldCamera *camera, CameraShake *shake);
int FIELD_GIMMICK_LIFT_ELEVATOR_UpdateCameraShake(CameraShake *shake);
void FIELD_GIMMICK_LIFT_ELEVATOR_SnapElevatorToTop(void *gameSystem);
/* END mkheaders: generated region */

#endif
