#ifndef GAME_OV010_FIELD_ENCOUNT_ST_H
#define GAME_OV010_FIELD_ENCOUNT_ST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_encount_st.c, prototypes copied from their definitions. */

struct EncountRow;
struct ArcFile;
struct FieldMap;
struct FieldGimmickWork;
struct GameData;
typedef struct EncountRow EncountRow;
typedef struct FieldGimmickWork FieldGimmickWork;

#include "../types.h"

int FIELD_ENCOUNT_ST_LoadEncountData(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex);
void *FIELD_ENCOUNT_ST_Create(u32 heapId);
void FIELD_ENCOUNT_ST_Delete(void *encountState);
int FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap);
FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData);
/* END mkheaders: generated region */

#endif
