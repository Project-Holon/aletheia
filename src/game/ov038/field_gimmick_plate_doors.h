#ifndef GAME_OV038_FIELD_GIMMICK_PLATE_DOORS_H
#define GAME_OV038_FIELD_GIMMICK_PLATE_DOORS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_plate_doors.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;

#include "../ov037/gimmick_save_types.h"

void FIELD_GIMMICK_PLATE_DOORS_Init(void *fieldMap);
void FIELD_GIMMICK_PLATE_DOORS_Exit(void *fieldMap);
void FIELD_GIMMICK_PLATE_DOORS_Update(void *fieldMap);
int FIELD_GIMMICK_PLATE_DOORS_FindDoor(FieldGimmickPlateDoorsWork *work, int cellX, int cellZ, int *doorOpen, int *exactCell);
struct GameEvent *FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(struct GameSystem *gameSystem, int cellX, int cellZ);
int FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor(struct GameEvent *event, int *state, void *work);
int FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor(struct GameEvent *event, int *state, void *work);
int FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide(struct GameEvent *event, int *state, void *work);
int FIELD_GIMMICK_PLATE_DOORS_EventBumpClosedDoor(struct GameEvent *event, int *state, void *work);
struct GameEvent *FIELD_GIMMICK_PLATE_DOORS_StartSwitchEvent(struct GameSystem *gameSystem, int switchIdx);
struct GameEvent *FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(struct GameSystem *gameSystem, int plateIdx);
struct GameEvent *FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(struct GameSystem *gameSystem, int variant);
int FIELD_GIMMICK_PLATE_DOORS_EventPressSwitch(struct GameEvent *event, int *state, void *work);
int FIELD_GIMMICK_PLATE_DOORS_EventPressPlate(struct GameEvent *event, int *state, void *work);
int FIELD_GIMMICK_PLATE_DOORS_EventScripted(struct GameEvent *event, int *state, void *work);
/* END mkheaders: generated region */

#endif
