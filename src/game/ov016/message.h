#ifndef GAME_OV016_MESSAGE_H
#define GAME_OV016_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of message.c, prototypes copied from their definitions. */

void DWCi_MSGlInit(void);
void DWCi_MSGlEnd(void);
void *DWCi_MSGlRead(char *file);
void DWCi_MSGlRelease(void *msg);
unsigned int DWCi_MSGlGet(unsigned int *p, unsigned int idx);
unsigned short *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
/* END mkheaders: generated region */

#endif
