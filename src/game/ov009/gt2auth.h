#ifndef GAME_OV009_GT2AUTH_H
#define GAME_OV009_GT2AUTH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2auth.c, prototypes copied from their definitions. */

int gti2VerifyChallenge(unsigned char *buffer);
unsigned char *gti2GetChallenge(unsigned char *buffer);
unsigned char *gti2GetResponse(unsigned char *buffer, unsigned char *challenge);
int gti2CheckResponse(unsigned char *p, unsigned char *q);
/* END mkheaders: generated region */

#endif
