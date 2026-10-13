/*
 * function: func_021E203C
 * address:  0x021E203C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_GetFadeRequestBits   0x02021ED8  thumb
 *
 * Return the +0x28 field when the +0x6c sub-object test is zero, else 3.
 */
#include "../include/Obj12157.h"

typedef unsigned int   u32;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);


int func_021E203C(void *p)
{
    if (PALANM_GetFadeRequestBits((const char *)(*(int *)(((struct Obj12157 *)p)->f2C + 0x6c))) == 0)
        return ((struct Obj12157 *)p)->f28;
    return 3;
}

