#ifndef GAME_OV009_NATIFY_H
#define GAME_OV009_NATIFY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of natify.c, prototypes copied from their definitions. */

#include "../ov009/natneg_types.h"

char *AddressToString(unsigned int ip, unsigned short port, char *string);
void OutputMapping(AddressMapping *theMap);
int Think(int sock, NAT *nat);
int NatifyThink(int sock, void *nat);
int DetermineNatType(NAT *nat);
/* END mkheaders: generated region */

#endif
