/*
 * function: TOUCHPANEL_ReadPointY
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
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *
 * The second halfword pair of the same accessor family as
 * src/matched/TOUCHPANEL_ReadPointX.c: kind byte +0x3D == 0x1E selects +0x66, else
 * +0x5E.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_ReadPointY.c \
 *       --func TOUCHPANEL_ReadPointY --addr 0x02035780 --cc 1.1p1 --arm
 */
#include "../include/Obj11335.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

extern int TOUCHPANEL_GetWork(void);

u16 TOUCHPANEL_ReadPointY(struct Kind *p)
{
    u8 *q;

    q = (u8 *)TOUCHPANEL_GetWork();
    if (p->unk3D == 0x1E)
        return ((struct Obj11335 *)q)->f66;
    return ((struct Obj11335 *)q)->f5E;
}
