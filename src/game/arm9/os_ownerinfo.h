#ifndef GAME_ARM9_OS_OWNERINFO_H
#define GAME_ARM9_OS_OWNERINFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_ownerinfo.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_os.h"

void OS_GetMacAddress(u8 *macAddress);
void OS_GetOwnerInfo(OSOwnerInfo *info);
long long OS_GetOwnerRtcOffset(void);
/* END mkheaders: generated region */

#endif
