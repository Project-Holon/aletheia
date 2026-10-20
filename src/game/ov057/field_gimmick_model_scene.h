#ifndef GAME_OV057_FIELD_GIMMICK_MODEL_SCENE_H
#define GAME_OV057_FIELD_GIMMICK_MODEL_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_model_scene.c, prototypes copied from their definitions. */

struct FieldMap;

#include "../ov057/field_gimmick_model_scene_types.h"

void FIELD_GIMMICK_MODEL_SCENE_Load(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void FIELD_GIMMICK_MODEL_SCENE_DeleteModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void FIELD_GIMMICK_MODEL_SCENE_AdvanceModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
void FIELD_GIMMICK_MODEL_SCENE_DrawModelScene(void *unused, struct FieldMap *fieldMap, ModelScene *scene);
/* END mkheaders: generated region */

#endif
