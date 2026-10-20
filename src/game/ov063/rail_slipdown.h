#ifndef GAME_OV063_RAIL_SLIPDOWN_H
#define GAME_OV063_RAIL_SLIPDOWN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of rail_slipdown.c, prototypes copied from their definitions. */

struct Mmdl;

#include "../ov063/rail_slipdown_types.h"

RailSlipdown *RAIL_SLIPDOWN_Create(void *gameSystem, void *fieldMap, struct Mmdl *mmdl, int isPlayer);
void RAIL_SLIPDOWN_Delete(RailSlipdown *slipdown);
int RAIL_SLIPDOWN_IsDone(RailSlipdown *slipdown);
void RAIL_SLIPDOWN_TaskMain(void *tcb, RailSlipdown *slipdown);
/* END mkheaders: generated region */

#endif
