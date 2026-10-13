/*
 * function: func_0220AFDC
 * address:  0x0220AFDC
 * packet:   pkt_0220AFDC
 * region:   ov196
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj14540.h"

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

void func_0220AFDC(char *p, void *v)
{
    if (((struct Obj14540 *)p)->f14 != v)
    {
        unsigned int i;
        for (i = 0; i < 4; i++)
        {
            CLACT_SetActorDrawEnable(*(void **)(p + i * 4), (unsigned int)v);
        }
        ((struct Obj14540 *)p)->f14 = v;
    }
}
