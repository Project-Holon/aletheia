#ifndef GAME_OV042_FIELD_GIMMICK_BUTTON_STATES_H
#define GAME_OV042_FIELD_GIMMICK_BUTTON_STATES_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_button_states.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct GameSystem;

#include "../types.h"

void FIELD_GIMMICK_BUTTON_STATES_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BUTTON_STATES_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BUTTON_STATES_Update(struct FieldMap *fieldMap);
struct GameEvent *FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(struct GameSystem *gameSystem, u32 stateModel, u32 showLastFrame);
struct GameEvent *FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(struct GameSystem *gameSystem, u32 oneShotIndex);
int FIELD_GIMMICK_BUTTON_STATES_EventSetState(struct GameEvent *event, int *seq, void *eventWork);
int FIELD_GIMMICK_BUTTON_STATES_EventPlayOneShot(struct GameEvent *event, int *seq, void *eventWork);
/* END mkheaders: generated region */

#endif
