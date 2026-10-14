/*
 * function: HALL_OF_FAME_DeleteMonParticle
 * address:  0x021B67B4
 * packet:   pkt_021B67B4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 */
#include "../include/Obj14399.h"

typedef unsigned char  u8;
extern void PARTICLE_DeleteSystem(u8 *p);

void HALL_OF_FAME_DeleteMonParticle(int *p)
{
    PARTICLE_DeleteSystem((u8 *)(((struct Obj14399 *)p)->f28));
    ((struct Obj14399 *)p)->f28 = 0;
}
