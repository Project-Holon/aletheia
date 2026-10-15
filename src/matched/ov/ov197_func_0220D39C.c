/*
 * function: B_BAG_MAIN_StateWaitFade
 * address:  0x0220D39C
 * packet:   pkt_0220D39C
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 */
#include "../include/Obj25090.h"

typedef unsigned int   u32;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);

int B_BAG_MAIN_StateWaitFade(char *a)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct Obj25090 *)a)->f8)) == 0)
        return 0x14;
    return 0x13;
}