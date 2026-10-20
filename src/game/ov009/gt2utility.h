#ifndef GAME_OV009_GT2UTILITY_H
#define GAME_OV009_GT2UTILITY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2utility.c, prototypes copied from their definitions. */

#include "../types.h"

char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
int gt2StringToAddress(char *string, u32 *ip, u16 *port);
void gti2MessageCheck(unsigned char **message, int *len);
/* END mkheaders: generated region */

#endif
