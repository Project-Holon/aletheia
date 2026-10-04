/*
 * function: func_021BFB2C
 * address: 0x021BFB2C
 * packet: pkt_ov204_021BFB2C
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFBC8 0x021BFBC8 thumb ov204
 */
#include "../include/Obj01974.h"

extern void func_021BFBC8(char *, unsigned int);

int func_021BFB2C(char *p)
{
    switch (((struct Obj01974 *)p)->f1C)
    {
    case 0: break;
    case 1:
        --((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 50) return 1;
        break;
    case 2:
        ++((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 70) return 1;
        break;
    case 3:
        --((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 0) return 1;
        break;
    case 4:
        ++((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 120) return 1;
        break;
    }
    return 0;
}
