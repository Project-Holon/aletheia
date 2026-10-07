/*
 * function: func_021799CC
 * address:  0x021799CC
 * packet:   pkt_021799CC
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015
 *   d_0217AAAC  0x0217AAAC  data  ov015
 *   func_02034714  0x02034714  arm
 */

#include "../include/G_State.h"

extern struct State d_0217AB80;
extern unsigned char d_0217AAAC[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_021799CC(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] != 0)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    ((unsigned char *)&d_0217AB80)[0xc] = 1;
}
