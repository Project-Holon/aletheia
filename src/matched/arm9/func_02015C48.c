/*
 * function: MCSS_SetPosition
 * address:  0x02015C48
 * packet:   pkt_02015C48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xE0. The inverse of MCSS_GetPosition; in the ov118 event state
 * machine (0x021D7130) and func_021D6E04 it is the in-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00933.h"

typedef unsigned int u32;

void MCSS_SetPosition(void *p, u32 *src)
{
    ((struct Obj00933 *)p)->fE0 = src[0];
    ((struct Obj00933 *)p)->fE4 = src[1];
    ((struct Obj00933 *)p)->fE8 = src[2];
}
