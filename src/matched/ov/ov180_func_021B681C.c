/*
 * function: func_021B681C
 * address:  0x021B681C
 * packet:   pkt_021B681C
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
#include "../include/Obj14401.h"

typedef unsigned char  u8;
extern void PARTICLE_DeleteSystem(u8 *p);

void func_021B681C(int *p)
{
    PARTICLE_DeleteSystem((u8 *)(((struct Obj14401 *)p)->f2C));
    ((struct Obj14401 *)p)->f2C = 0;
}
