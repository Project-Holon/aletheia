#ifndef GAME_OV081_ENCEFF_GRID_SPREAD_H
#define GAME_OV081_ENCEFF_GRID_SPREAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_grid_spread.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;

#include "../ov077/enceff_grid_types.h"
#include "../ov081/enceff_grid_spread_types.h"

struct GameEvent *ENCEFF_BuildGridSpread(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *ENCEFF_StartGridSpread(struct GameSystem *gameSystem);
void ENCEFF_InitGridSpread(EncEffGridWork *work);
void ENCEFF_StepGridSpread(EncEffGridWork *work);
int ENCEFF_UpdateGridSpreadCell(EncEffGridCell *cell);
int ENCEFF_IsGridSpreadQueued(int cellIndex, EncEffSpreadState *spread);
void ENCEFF_QueueGridSpreadCell(EncEffGridWork *work, int x, int y);
void ENCEFF_QueueGridSpreadNeighbors(EncEffGridWork *work, int cellIndex);
void ENCEFF_StartGridSpreadWave(EncEffGridWork *work);
/* END mkheaders: generated region */

#endif
