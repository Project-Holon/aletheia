#ifndef GAME_OV016_KEYBOARD_H
#define GAME_OV016_KEYBOARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of keyboard.c, prototypes copied from their definitions. */

void DWCi_KBlInit(void);
void DWCi_KBlEnd(void);
unsigned char DWCi_KBlGet(void);
void DWCi_KBlSetErase(unsigned char v);
void DWCi_KBlSetInput(unsigned char v);
int DWCi_KBlIsInit(void);
/* END mkheaders: generated region */

#endif
