/*
 * unit:     no
 * function: GFL_NET_IsParentAid
 * address:  0x0203D378
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *
 * TU: net.c.
 *
 * Inverted forward: 1 when GFL_NET_SYSTEM_GetCurrentAid reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsParentAid.c \
 *       --func GFL_NET_IsParentAid --addr 0x0203D378 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

u32 GFL_NET_IsParentAid(void)
{
    u32 res = 0;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        res = 1;
    }
    return res;
}
