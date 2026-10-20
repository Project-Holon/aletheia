#ifndef GAME_OV009_SOCL_MISC_H
#define GAME_OV009_SOCL_MISC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_misc.c, prototypes copied from their definitions. */

#include "../types.h"

u32 SOCLi_RoundUp4(u32 size);
void SOCLi_InitResource(void);
int SOCLi_IsIPv4ValidDNSAddr(unsigned long netmask, unsigned long dns, unsigned long addr);
int SOCLi_IsIPv4ValidNodeAddr(unsigned long netmask, unsigned long addr);
int SOCLi_CheckNConfig(void);
/* END mkheaders: generated region */

#endif
