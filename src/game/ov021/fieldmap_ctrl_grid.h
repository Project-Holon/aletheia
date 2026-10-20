#ifndef GAME_OV021_FIELDMAP_CTRL_GRID_H
#define GAME_OV021_FIELDMAP_CTRL_GRID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fieldmap_ctrl_grid.c, prototypes copied from their definitions. */

#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"
#include "../types.h"

void FIELDMAP_CTRL_GRID_Create(FieldMap *fieldMap, VecFx32 *pos, int dir);
void FIELDMAP_CTRL_GRID_Destroy(FieldMap *fieldMap);
void FIELDMAP_CTRL_GRID_Main(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *FIELDMAP_CTRL_GRID_GetTargetPos(FieldMap *fieldMap);
void FIELDMAP_CTRL_GRID_SetBusy(FieldMap *fieldMap, u32 busy);
/* END mkheaders: generated region */

#endif
