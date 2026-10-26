#ifndef GAME_OV044_FIELD_GIMMICK_LIFT_H
#define GAME_OV044_FIELD_GIMMICK_LIFT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_lift.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov044/field_gimmick_lift_types.h"

void FIELD_GIMMICK_LIFT_Init(void *fieldMap);
void FIELD_GIMMICK_LIFT_Exit(u8 *fieldMap);
void FIELD_GIMMICK_LIFT_Update(void *fieldMap);
struct GameEvent;
struct GameSystem;
struct GameEvent *FIELD_GIMMICK_LIFT_CallEvent(struct GameSystem *gameSystem, int isDescending);
int FIELD_GIMMICK_LIFT_LiftEventMain(struct GameEvent *event, int *seq, void *eventWork);
int FIELD_GIMMICK_LIFT_IsLiftArrived(FieldGimmickLiftWork *work);
void FIELD_GIMMICK_LIFT_ShowIdleAnime(void *expObj);
void FIELD_GIMMICK_LIFT_SnapLiftToBottom(void *gameSystem);
/* END mkheaders: generated region */

#endif
