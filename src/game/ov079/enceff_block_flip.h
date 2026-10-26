#ifndef GAME_OV079_ENCEFF_BLOCK_FLIP_H
#define GAME_OV079_ENCEFF_BLOCK_FLIP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_block_flip.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;

#include "../ov077/enceff_grid_types.h"

void *ENCEFF_BuildBlockFlip(void *gameSystem, struct FieldMap *fieldMap);
struct GameEvent *ENCEFF_StartBlockFlip(struct GameSystem *gameSystem);
void ENCEFF_StepBlockFlip(EncEffGridWork *work);
int ENCEFF_StepFlipCell(EncEffGridCell *cell);
/* END mkheaders: generated region */

#endif
