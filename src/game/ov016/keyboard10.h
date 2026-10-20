#ifndef GAME_OV016_KEYBOARD10_H
#define GAME_OV016_KEYBOARD10_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of keyboard10.c, prototypes copied from their definitions. */

void DWCi_KB10lInit(void);
void DWCi_KB10lEnd(void);
unsigned char DWCi_KB10lGet(void);
void DWCi_KB10lSetErase(unsigned char v);
void DWCi_KB10lSetInput(unsigned char v);
void DWCi_KB10lSetShift(unsigned char v);
int DWCi_KB10lIsInit(void);
/* END mkheaders: generated region */

#endif
