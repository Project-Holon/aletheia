#ifndef GAME_OV065_FIELD_GIMMICK_TIME_EFFECT_H
#define GAME_OV065_FIELD_GIMMICK_TIME_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_time_effect.c, prototypes copied from their definitions. */

struct FieldMap;

void FIELD_GIMMICK_TIME_EFFECT_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_TIME_EFFECT_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_TIME_EFFECT_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_TIME_EFFECT_StartEffect(struct FieldMap *fieldMap);
void *FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent(void *gameSystem);
int FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain(void *event);
/* END mkheaders: generated region */

#endif
