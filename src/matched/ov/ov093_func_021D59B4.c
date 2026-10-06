/*
 * function: func_021D59B4
 * address:  0x021D59B4
 * packet:   pkt_ov093_021D59B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the switch value stays in r1 and is the hidden second argument of
 * func_021D58A8; case 17 falls through into case 16.
 *
 * symbols:
 *   func_021D587C  0x021D587C  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D78E4  0x021D78E4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00041.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern int func_021D587C(void *p, int k);
extern int func_021D58A8(u8 *, int);
extern unsigned short func_021D78E4(unsigned short a, int i);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);

int func_021D59B4(u8 *p, int k)
{
    int v = func_021D587C(p, k);

    switch (v) {
    case 8:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFC);
    case 9:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFD);
    case 10:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFE);
    case 11:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFF);
    case 12:
        return func_021D78E4(func_021D58A8(p, v), ((struct Obj00041 *)p)->f100);
    case 1:
        return ((struct Obj00041 *)p)->fFC;
    case 2:
        return ((struct Obj00041 *)p)->fFD;
    case 3:
        return ((struct Obj00041 *)p)->fFE;
    case 4:
        return ((struct Obj00041 *)p)->fFF;
    case 5:
        return *(s8 *)&((struct Obj00041 *)p)->f100;
    case 6:
        return ((struct Obj00041 *)p)->f101;
    case 7:
        return ((struct Obj00041 *)p)->f102;
    case 15:
        return ((struct Obj00041 *)p)->f18;
    case 18:
        return ((struct Obj00041 *)p)->fFA;
    case 13:
        return ((struct Obj00041 *)p)->f10;
    case 14:
        return ((struct Obj00041 *)p)->fE;
    case 21:
        return ((struct Obj00041 *)p)->f1A;
    case 17:
        if (func_021D62C4((struct Unk021D62A8 *)p, 0x10) != 0)
            return 0;
    case 16:
        return ((struct Obj00041 *)p)->f13C;
    case 19:
        return ((struct Obj00041 *)p)->f141;
    case 20:
        return ((struct Obj00041 *)p)->f8;
    case 0:
        break;
    }
    return 0;
}
