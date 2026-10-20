#ifndef GAME_OV021_FIELDSKILL_MAPEFF_H
#define GAME_OV021_FIELDSKILL_MAPEFF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fieldskill_mapeff.c, prototypes copied from their definitions. */

struct FieldSkillMapEff;
typedef struct FieldSkillMapEff FieldSkillMapEff;

#include "../types.h"
#include "../ov021/field_flash_shared_types.h"

FieldSkillMapEff *FIELDSKILL_MAPEFF_Create(u32 flags, u32 heapId);
void FIELDSKILL_MAPEFF_Delete(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_Update(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_Apply(FieldSkillMapEff *mapEff);
FieldFlash *FIELDSKILL_MAPEFF_GetFlash(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_InitFlash(FieldSkillMapEff *mapEff, u32 flags, u32 heapId);
void FIELDSKILL_MAPEFF_FreeFlash(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_UpdateFlash(FieldSkillMapEff *mapEff);
void FIELDSKILL_MAPEFF_ApplyFlash(FieldSkillMapEff *mapEff);
/* END mkheaders: generated region */

#endif
