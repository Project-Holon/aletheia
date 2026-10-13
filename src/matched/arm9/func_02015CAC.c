/*
 * function: MCSS_SetScale
 * address:  0x02015CAC
 * packet:   pkt_02015CAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xEC. The inverse of MCSS_GetScale.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00933.h"

typedef unsigned int u32;

void MCSS_SetScale(void *p, u32 *src)
{
    ((struct Obj00933 *)p)->fEC = src[0];
    ((struct Obj00933 *)p)->fF0 = src[1];
    ((struct Obj00933 *)p)->fF4 = src[2];
}
