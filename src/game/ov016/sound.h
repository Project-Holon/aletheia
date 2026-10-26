#ifndef GAME_OV016_SOUND_H
#define GAME_OV016_SOUND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sound.c, prototypes copied from their definitions. */

void DWCi_SNDlInit(void);
void DWCi_SNDlEnd(void);
void DWCi_SNDlPlay(unsigned int v);
void DWCi_SNDlSetVolume(unsigned int v);
void DWCi_SNDlSetPitch(unsigned int a, unsigned int b);
void DWCi_SNDlStop(void);
void taskSound(void * unused0, void * unused1);
/* END mkheaders: generated region */

#endif
