/*
 * function: IRCNET_IsLinkAlive
 * address:  0x02179D3C
 * packet:   pkt_ov015_02179D3C
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0217A024  0x0217A024  arm  ov015
 *   d_0217AB40  0x0217AB40  data  ov015
 */

#include "../include/G_s_ab40.h"

typedef unsigned int u32;

extern int func_0217A024(void);
extern struct s_ab40 d_0217AB40;

int IRCNET_IsLinkAlive(void)
{
    u32 a;
    u32 b;

    if (func_0217A024() == 1)
        return 1;
    a = ((u32 *)&d_0217AB40)[0x3c / 4];
    b = ((u32 *)&d_0217AB40)[0x40 / 4];
    if (b < a || (b == 0 && a == 0))
        return 1;
    return 0;
}
