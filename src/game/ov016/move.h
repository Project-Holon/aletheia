#ifndef GAME_OV016_MOVE_H
#define GAME_OV016_MOVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of move.c, prototypes copied from their definitions. */

void DWCi_MOVlInit(void (*callback)(int));
void DWCi_MOVlEnd(void);
int DWCi_MOVlIsEnd(void);
void DWCi_MOVlChangeCallback(unsigned int v);
void DWCi_MOVlAdmitChild(void);
char *DWCi_MOVlGetChild(void);
void taskFramework(void *task);
/* END mkheaders: generated region */

#endif
