/*
 * function: NNSi_G2dSetCellAnimationFrame
 * address:  0x02062D08
 * packet:   pkt_02062BF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj07015.h"
#include "../include/Obj11525.h"
#include "../include/Obj16406.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int NNSi_G2dSetCellAnimationFrame(void *p, u32 i)
{
    u8 *s = (u8 *)p;
    u8 *t = *(u8 * *)&((struct Obj07015 *)s)->f1C;
    u8 *e;

    if (i < ((struct Obj11525 *)t)->f0) {
        e = *(u8 * *)&((struct Obj11525 *)t)->fC + i * 8;
        *(u8 * *)&((struct Obj07015 *)s)->f0 = e;
        if (((struct Obj16406 *)e)->f4 != 0) {
            *(u8 * *)&((struct Obj07015 *)s)->f4 = e;
        }
        return 1;
    }
    return 0;
}
