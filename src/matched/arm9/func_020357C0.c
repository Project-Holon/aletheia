/*
 * function: func_020357C0
 * address:  0x020357C0
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
 * Fourth of the family in src/matched/func_02035760.c: kind byte +0x3D ==
 * 0x1E selects +0x68, else +0x60.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357C0.c \
 *       --func func_020357C0 --addr 0x020357C0 --cc 1.1p1 --arm
 */
#include "../include/Obj11337.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

extern int func_02035750(void);

u16 func_020357C0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11337 *)q)->f68;
    return ((struct Obj11337 *)q)->f60;
}
