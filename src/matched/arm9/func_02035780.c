/*
 * function: func_02035780
 * address:  0x02035780
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
 * The second halfword pair of the same accessor family as
 * src/matched/func_02035760.c: kind byte +0x3D == 0x1E selects +0x66, else
 * +0x5E.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035780.c \
 *       --func func_02035780 --addr 0x02035780 --cc 1.1p1 --arm
 */
#include "../include/Obj11335.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

extern u8 *func_02035750(void *p);

u16 func_02035780(struct Kind *p)
{
    u8 *q;

    q = func_02035750(p);
    if (p->unk3D == 0x1E)
        return ((struct Obj11335 *)q)->f66;
    return ((struct Obj11335 *)q)->f5E;
}
