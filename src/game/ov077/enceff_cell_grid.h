#ifndef GAME_OV077_ENCEFF_CELL_GRID_H
#define GAME_OV077_ENCEFF_CELL_GRID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_cell_grid.c, prototypes copied from their definitions. */

struct GameEvent;
struct EncEffWork;

#include "../ov077/enceff_grid_types.h"
#include "../types.h"

void *ENCEFF_StartCellGrid(void *gameSystem, const EncEffGridParam *param, int useSubScreen);
int ENCEFF_CellGridEventMain(struct GameEvent *event, u32 *state, void *eventWork);
int ENCEFF_StepCellGrid(EncEffGridWork *work);
void ENCEFF_UpdateCellGrid(struct EncEffWork *eff);
void ENCEFF_DrawCellGrid(EncEffGridWork *work);
/* END mkheaders: generated region */

#endif
