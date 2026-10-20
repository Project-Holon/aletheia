#ifndef GAME_OV021_FIELDMAP_CTRL_HYBRID_H
#define GAME_OV021_FIELDMAP_CTRL_HYBRID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fieldmap_ctrl_hybrid.c, prototypes copied from their definitions. */

struct FieldMapCtrlHybridWork;
typedef struct FieldMapCtrlHybridWork FieldMapCtrlHybridWork;

#include "../types.h"
#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"
#include "../arm9/zonedata_types.h"

u32 FIELDMAP_CTRL_HYBRID_GetMode(FieldMapCtrlHybridWork *work);
void FIELDMAP_CTRL_HYBRID_ReplacePlayer(FieldMapCtrlHybridWork *work, FieldMap *fieldMap);
void FIELDMAP_CTRL_HYBRID_Create(FieldMap *fieldMap, VecFx32 *pos, u16 dir);
void FIELDMAP_CTRL_HYBRID_Destroy(FieldMap *fieldMap);
void FIELDMAP_CTRL_HYBRID_Main(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *FIELDMAP_CTRL_HYBRID_GetTargetPos(FieldMap *fieldMap);
void FIELDMAP_CTRL_HYBRID_UpdateGrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);
void FIELDMAP_CTRL_HYBRID_UpdateNogrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);
void FIELDMAP_CTRL_HYBRID_SwitchToNogrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, RailLocation *railLocation, u32 keyTrg, u32 keyCont);
void FIELDMAP_CTRL_HYBRID_SwitchToGrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, VecFx32 *gridPos, u32 keyTrg, u32 keyCont);
int FIELDMAP_CTRL_HYBRID_FindGridPos(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, VecFx32 *outPos, u32 dir);
int FIELDMAP_CTRL_HYBRID_FindRailLocation(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, RailLocation *outLocation, u32 dir);
void FIELDMAP_CTRL_HYBRID_SetMode(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, int mode, const void *place, u16 dir, u16 blactAnime, u16 blactFrame);
/* END mkheaders: generated region */

#endif
