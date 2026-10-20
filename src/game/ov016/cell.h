#ifndef GAME_OV016_CELL_H
#define GAME_OV016_CELL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cell.c, prototypes copied from their definitions. */

struct CellInfo;
typedef struct CellInfo CellInfo;

#include "../sdk_gx.h"
#include "../types.h"

void DWCi_CELLlInit(void);
void DWCi_CELLlEnd(void);
void *DWCi_CELLlForm(int lcd, int num, int head);
void DWCi_CELLlDelete(CellInfo *p);
GXOamAttr *DWCi_CELLlGetObj(CellInfo *p, unsigned int i);
unsigned char DWCi_CELLlGetState(CellInfo *cell);
void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
void DWCi_CELLlSetPalette(u8 *obj, int idx, u32 v, u32 w);
void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
/* END mkheaders: generated region */

#endif
