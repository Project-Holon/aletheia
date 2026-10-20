#ifndef GAME_OV021_FIELDMAP_CTRL_NOGRID_WORK_H
#define GAME_OV021_FIELDMAP_CTRL_NOGRID_WORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fieldmap_ctrl_nogrid_work.c, prototypes copied from their definitions. */

struct FieldMapCtrlNogridWork;
typedef struct FieldMapCtrlNogridWork FieldMapCtrlNogridWork;

#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"
#include "../types.h"

void FIELDMAP_CTRL_NOGRID_WORK_Create(FieldMap *fieldMap, VecFx32 *pos, u32 dir);
void FIELDMAP_CTRL_NOGRID_WORK_Destroy(FieldMap *fieldMap);
void FIELDMAP_CTRL_NOGRID_WORK_Main(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *FIELDMAP_CTRL_NOGRID_WORK_GetTargetPos(FieldMap *fieldMap);
FieldMapCtrlNogridWork *FIELDMAP_CTRL_NOGRID_WORK_CreateWork(FieldMap *fieldMap, u32 heapId);
void FIELDMAP_CTRL_NOGRID_WORK_FreeWork(void *work);
void FIELDMAP_CTRL_NOGRID_WORK_MovePlayer(FieldMapCtrlNogridWork *work);
/* END mkheaders: generated region */

#endif
