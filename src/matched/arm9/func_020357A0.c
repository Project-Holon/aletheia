/*
 * function: func_020357A0
 * address:  0x020357A0
 * packet:   pkt_02035760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035750  0x02035750  arm
 *
 * Third of the family in src/matched/func_02035760.c: kind byte +0x3D == 0x1E
 * selects +0x6A, else +0x62.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357A0.c \
 *       --func func_020357A0 --addr 0x020357A0 --cc 1.1p1 --arm
 */
#include "../include/Obj11336.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

extern int func_02035750(void);

int func_020357A0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11336 *)q)->f6A;
    return ((struct Obj11336 *)q)->f62;
}
