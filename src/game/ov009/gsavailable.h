#ifndef GAME_OV009_GSAVAILABLE_H
#define GAME_OV009_GSAVAILABLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsavailable.c, prototypes copied from their definitions. */

struct SOCSockAddrIn;

void GSIStartAvailableCheckA(char *gamename);
int HandlePacket(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices);
int GSIAvailableCheckThink(void);
/* END mkheaders: generated region */

#endif
