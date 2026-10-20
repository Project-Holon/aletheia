#ifndef GAME_OV021_FIELD_GIMMICK_H
#define GAME_OV021_FIELD_GIMMICK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick.c, prototypes copied from their definitions. */

struct FieldMap;

#include "../ov020/event_mapchange_types.h"

void FIELD_GIMMICK_Setup(FieldMap *fieldMap);
void FIELD_GIMMICK_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_RunMapCallback(struct FieldMap *fieldMap);
int FIELD_GIMMICK_IsGimmickId(struct FieldMap *fieldMap, int gimmickId);
/* END mkheaders: generated region */

#endif
