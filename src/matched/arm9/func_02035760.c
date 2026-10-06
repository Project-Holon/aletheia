/*
 * function: func_02035760
 * address:  0x02035760
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
 * A one-liner over the object at 0x021469C4: when the kind byte at +0x3D is
 * 0x1E (30) the halfword at +0x64 is reported, otherwise the one at +0x5C.
 * The kind test is on the *argument*, the two halfwords on the object the
 * accessor func_02035750 returns, which is why the argument is kept in r4
 * across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035760.c \
 *       --func func_02035760 --addr 0x02035760 --cc 1.1p1 --arm
 */
#include "../include/Obj11334.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

extern int func_02035750(void);

u16 func_02035760(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11334 *)q)->f64;
    return ((struct Obj11334 *)q)->f5C;
}
