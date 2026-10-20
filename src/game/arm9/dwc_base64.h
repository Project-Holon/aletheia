#ifndef GAME_ARM9_DWC_BASE64_H
#define GAME_ARM9_DWC_BASE64_H

/* Public functions of dwc_base64.c, prototypes copied from their definitions. */

#include "../types.h"

int DWC_Base64Encode(const char *src, u32 srclen, char *dst, u32 dstlen);
int DWC_Base64Decode(const char *src, u32 srclen, char *dst, u32 dstlen);

#endif
