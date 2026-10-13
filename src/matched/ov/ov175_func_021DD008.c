/*
 * function: func_021DD008
 * address:  0x021DD008
 * packet:   pkt_021DD008
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *
 * Conditional notify: when the flag is set, halt for the halfword at +0x124
 * through 0x0203D34C.
 */
#include "../include/Obj24396.h"

typedef unsigned int   u32;
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void func_021DD008(char *p, int flag)
{
    if (flag == 0)
        return;
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj24396 *)p)->f124);
}

