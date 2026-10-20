#ifndef GAME_OV080_ENCEFF_GRID_COLUMN_FLIP_H
#define GAME_OV080_ENCEFF_GRID_COLUMN_FLIP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_grid_column_flip.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;

#include "../ov077/enceff_grid_types.h"

struct GameEvent *ENCEFF_BuildGridColumnFlip(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *ENCEFF_StartGridColumnFlip(struct GameSystem *gameSystem);
void ENCEFF_StepGridColumnFlip(EncEffGridWork *work);
int ENCEFF_UpdateGridColumnFlipCell(EncEffGridCell *cell);
/* END mkheaders: generated region */

#endif
