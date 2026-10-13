/*
 * function: TOUCHPANEL_SetPoint
 * address:  0x02035E84
 * packet:   pkt_02035E84
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
 * The setter that mirrors the four accessors of src/matched/TOUCHPANEL_ReadPointX.c:
 * four halfword stores into the object TOUCHPANEL_GetWork returns, at +0x64 and
 * +0x66 from the third and fifth arguments and at +0x6C and +0x6E from the
 * second and fourth.  The fifth argument is a stack argument, which is why
 * `ldrh r1, [sp, #0x10]` sits second - the argument area is above the pushed
 * {r4,r5,r6,lr}.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_SetPoint.c \
 *       --func TOUCHPANEL_SetPoint --addr 0x02035E84 --cc 1.1p1 --arm
 */
#include "../include/Obj06933.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern int TOUCHPANEL_GetWork(void);

void TOUCHPANEL_SetPoint(void *p, u16 a, u16 b, u16 c, u16 d)
{
    u8 *q;

    q = (u8 *)TOUCHPANEL_GetWork();
    ((struct Obj06933 *)q)->f64 = c;
    ((struct Obj06933 *)q)->f66 = d;
    ((struct Obj06933 *)q)->f5C = a;
    ((struct Obj06933 *)q)->f5E = b;
}
