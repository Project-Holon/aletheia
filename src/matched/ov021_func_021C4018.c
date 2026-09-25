/*
 * function: func_021C4018
 * address:  0x021C4018
 * packet:   pkt_021C4018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02008530  0x02008530  thumb
 */

typedef unsigned int u32;

u32 func_02008530(void);

void func_021C4018(int a, char *p)
{
    *(u32 *)(p + 0x30) = func_02008530();
}
