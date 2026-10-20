#ifndef GAME_OV112_STA_ACT_OBJ_H
#define GAME_OV112_STA_ACT_OBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_obj.c, prototypes copied from their definitions. */

#include "../ov112/sta_act_types.h"
#include "../types.h"

StaActObjObject *STA_ACT_OBJ_Create(u16 heap, void *board);
void STA_ACT_OBJ_Delete(char *p);
void STA_ACT_OBJ_Update(char *p);
void STA_ACT_OBJ_UpdateEntry(char *o, StaActObjEntry *entry);
void STA_ACT_OBJ_SetCount(StaActObjObject *o, u16 count);
StaActObjEntry *STA_ACT_OBJ_AddEntry(StaActObjObject *o, u32 unused);
void STA_ACT_OBJ_FreeEntry(u32 *o, StaActObjEntry *entry);
void STA_ACT_OBJ_SetEntryTarget(void *a, StaActObjEntry *entry, u32 *target);
void STA_ACT_OBJ_GetEntryTarget(void *a, StaActObjEntry *entry, u32 *target);
/* END mkheaders: generated region */

#endif
