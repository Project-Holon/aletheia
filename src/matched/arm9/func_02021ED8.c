/*
 * function: PALANM_GetFadeRequestBits
 * address:  0x02021ED8
 * packet:   pkt_02021EE4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15732.h"

typedef unsigned short u16;
typedef unsigned int   u32;

u32 PALANM_GetFadeRequestBits(const char *ptr)
{
    u16 v = ((struct Obj15732 *)ptr)->f118;
    return (u32)(v << 16) >> 18;
}
