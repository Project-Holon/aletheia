#ifndef GAME_OV038_FIELD_GIMMICK_PLATE_DOORS_H
#define GAME_OV038_FIELD_GIMMICK_PLATE_DOORS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_plate_doors.c, prototypes copied from their definitions. */

#include "../ov037/gimmick_save_types.h"

void FIELD_GIMMICK_PLATE_DOORS_Init(void *fieldMap);
void FIELD_GIMMICK_PLATE_DOORS_Exit(void *fieldMap);
void FIELD_GIMMICK_PLATE_DOORS_Update(void *fieldMap);
int FIELD_GIMMICK_PLATE_DOORS_FindDoor(FieldGimmickPlateDoorsWork *work, int cellX, int cellZ, int *doorOpen, int *exactCell);
int FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(int gameSystem, int cellX, int cellZ);
int FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventBumpClosedDoor(int event, int *state);
void *FIELD_GIMMICK_PLATE_DOORS_StartSwitchEvent(void *gameSystem, int switchIdx);
void *FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(void *gameSystem, int plateIdx);
void *FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(void *gameSystem, int variant);
int FIELD_GIMMICK_PLATE_DOORS_EventPressSwitch(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventPressPlate(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventScripted(void *event, int *state);
/* END mkheaders: generated region */

#endif
