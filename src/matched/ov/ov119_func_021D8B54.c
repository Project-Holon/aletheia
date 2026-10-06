/*
 * function: func_021D8B54
 * address:  0x021D8B54
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035CB8  0x02035CB8  arm
 */
#include "../include/Obj01726.h"

typedef signed short s16;

typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);

void func_021D8B54(void *p)
{
    int o1, o2;
    int d;

    if (func_02035CB8((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    if (((struct Obj01726 *)p)->fF60 == 0)
        ((struct Obj01726 *)p)->fF5C = 0;
    if (((struct Obj01726 *)p)->fF60 != 0) {
        d = ((s16)((struct Obj01726 *)p)->fF64 - (s16)((struct Obj01726 *)p)->fF68) - o1;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((struct Obj01726 *)p)->fF5C = 1;
        d = ((s16)((struct Obj01726 *)p)->fF66 - (s16)((struct Obj01726 *)p)->fF6A) - o2;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((struct Obj01726 *)p)->fF5C = 1;
        d = (s16)((struct Obj01726 *)p)->fF64 - o1;
        if (d < 0)
            d = -d;
        if (d > 6) {
            d = (s16)((struct Obj01726 *)p)->fF66 - o2;
            if (d < 0)
                d = -d;
            if (d > 6)
                ((struct Obj01726 *)p)->fF70 = 0;
        }
    }
    if ((unsigned int)o2 >= 0x10 && (unsigned int)o2 < 0x90) {
        ((struct Obj01726 *)p)->fF54 = o1;
        ((struct Obj01726 *)p)->fF58 = o2;
    }
}
