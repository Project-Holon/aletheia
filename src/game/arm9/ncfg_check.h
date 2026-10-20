#ifndef GAME_ARM9_NCFG_CHECK_H
#define GAME_ARM9_NCFG_CHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ncfg_check.c, prototypes copied from their definitions. */

#include "../sdk_ncfg.h"
#include "../types.h"

int NCFGi_CheckApInfo(NCFGApInfo *info);
int NCFGi_CheckApInfoEx(NCFGApInfo *info, NCFGApInfoEx *infoEx);
int NCFGi_CheckIpInfo(NCFGApInfo *info);
void NCFGi_ConvMaskAddr(int mask, unsigned char *buf);
int NCFGi_CheckSsid(unsigned char *ssid);
int NCFGi_CheckIp(u8 *ip, u8 *mask);
int NCFGi_CheckAddress(unsigned char *address);
/* END mkheaders: generated region */

#endif
