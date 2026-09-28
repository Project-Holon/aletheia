/*
 * function: func_021C4024
 * address:  0x021C4024
 * packet:   pkt_021C4024
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C4078  0x021C4078  thumb
 */

typedef unsigned int u32;

u32 func_021C4078(void);

void func_021C4024(int a, char *p)
{
    *(u32 *)(p + 0x34) = func_021C4078();
}
