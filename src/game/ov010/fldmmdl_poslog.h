#ifndef GAME_OV010_FLDMMDL_POSLOG_H
#define GAME_OV010_FLDMMDL_POSLOG_H

struct VecFx32;
int FLDMMDL_GetMovedPos(void *mmdl, struct VecFx32 *out);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_poslog.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov010/fldmmdl_types.h"
#include "../sdk_fx.h"

u32 FLDMMDL_GetMovedPosSaveSize(void);
void FLDMMDL_InitMovedPosSave(void *block);
int FLDMMDL_FindMovedPosSlot(int gridX, int gridZ);
int FLDMMDL_GetMovedPosSlot(Mmdl *mmdl);
void FLDMMDL_StoreMovedPos(void *mmdl);
int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos);
int FLDMMDL_IsMovedPosObjCode(u16 objCode);
void FLDMMDL_InitPosRecord(MmdlHeader *header, u16 gridX, u16 gridZ, int posY);
void FLDMMDL_ApplyBurmyFormForPlace(void *saveData, void *mon, int placeId);
/* END mkheaders: generated region */

#endif
