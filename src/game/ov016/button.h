#ifndef GAME_OV016_BUTTON_H
#define GAME_OV016_BUTTON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of button.c, prototypes copied from their definitions. */

void DWCi_BTNlInit(int kind);
void DWCi_BTNlEnd(void);
signed char DWCi_BTNlGet(void);
void DWCi_BTNlSet(signed char v);
void DWCi_BTNlSetForce(int a);
int DWCi_BTNlIsEnd(void);
void DWCi_BTNlEnable(void);
void DWCi_BTNlDisable(void);
/* END mkheaders: generated region */

#endif
