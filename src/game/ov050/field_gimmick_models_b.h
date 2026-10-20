#ifndef GAME_OV050_FIELD_GIMMICK_MODELS_B_H
#define GAME_OV050_FIELD_GIMMICK_MODELS_B_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_models_b.c, prototypes copied from their definitions. */

struct FieldMap;
struct FieldGimmickModelsBWork;

#include "../ov050/field_gimmick_models_b_types.h"

void FIELD_GIMMICK_MODELS_B_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_StartModel0Anime(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_StopModel0Anime(struct FieldMap *fieldMap);
int FIELD_GIMMICK_MODELS_B_IsModel0AnimeDone(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_HideModel1(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_ShowModel1(struct FieldMap *fieldMap);
int FIELD_GIMMICK_MODELS_B_IsModel1AnimeDone(struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_InitModels(FieldGimmickModelsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_InitExtra(FieldGimmickModelsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_MODELS_B_ExitExtra(struct FieldGimmickModelsBWork *work, struct FieldMap *fieldMap);
/* END mkheaders: generated region */

#endif
