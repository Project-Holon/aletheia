#ifndef GAME_OV021_RAIL_ATTR_H
#define GAME_OV021_RAIL_ATTR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of rail_attr.c, prototypes copied from their definitions. */

struct RailAttr;
typedef struct RailAttr RailAttr;

#include "../types.h"
#include "../arm9/zonedata_types.h"

RailAttr *RAIL_ATTR_Create(int heapId);
void RAIL_ATTR_Delete(RailAttr *attr);
void RAIL_ATTR_Load(RailAttr *attr, u32 dataId, u32 heapId);
void RAIL_ATTR_Release(RailAttr *attr);
int RAIL_ATTR_GetAttribute(const RailAttr *attr, const RailLocation *location);
int RAIL_ATTR_IsSignBoard(u16 value);
int RAIL_ATTR_IsJumpStart(int value);
int RAIL_ATTR_IsForceMoveUp(int value);
int RAIL_ATTR_IsForceMoveDown(int value);
int RAIL_ATTR_IsForceMoveLeft(int value);
int RAIL_ATTR_IsForceMoveRight(int value);
int RAIL_ATTR_IsForceMoveStop(int value);
int RAIL_ATTR_IsSlipDown(int value);
/* END mkheaders: generated region */

#endif
