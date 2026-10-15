/*
 * function: RESEARCH_LIST_CreateOamSys
 * address:  0x021BD38C
 * packet:   pkt_021BD38C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25885.h"

typedef unsigned short u16;

extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);

void RESEARCH_LIST_CreateOamSys(char *p)
{
    int i = 0x47;
    *(void **)(p + (i << 2) + 0x10) =
        BMP_OAM_CreateSys(((struct Obj25885 *)p)->f8, *(void **)(p + (i << 2)));
}
