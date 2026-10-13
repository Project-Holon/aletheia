/*
 * function: FLD_PARTICLE_DeleteEffect
 * address:  0x021C1A84
 * packet:   pkt_021C1A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09206.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void PARTICLE_DeleteSystem(u8 *p);

void FLD_PARTICLE_DeleteEffect(u8 *p)
{
    u32 v = ((struct Obj09206 *)p)->fC;
    if (v != 0) {
        PARTICLE_DeleteSystem((u8 *)v);
        ((struct Obj09206 *)p)->fC = 0;
    }
}
