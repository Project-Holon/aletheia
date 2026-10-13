/*
 * function: func_02210408
 * address:  0x02210408
 * packet:   pkt_02210408
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_GetFadeRequestBits   0x02021ED8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25238.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);

u32 func_02210408(u8 *p)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct Obj25238 *)p)->f1D8)) == 0) {
        return 0x21;
    }
    return 0x20;
}

