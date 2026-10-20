#ifndef GAME_OV049_FIELD_GIMMICK_MODELS_A_H
#define GAME_OV049_FIELD_GIMMICK_MODELS_A_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_models_a.c, prototypes copied from their definitions. */

struct FieldMap;
struct FieldGimmickModelsAWork;

#include "../ov049/field_gimmick_models_a_types.h"

void FIELD_GIMMICK_MODELS_A_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_A_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_A_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_A_PlaceModels(FieldGimmickModelsAWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_A_InitExtra(FieldGimmickModelsAWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_A_ExitExtra(struct FieldGimmickModelsAWork *work, struct FieldMap *fieldMap);
/* END mkheaders: generated region */

#endif
