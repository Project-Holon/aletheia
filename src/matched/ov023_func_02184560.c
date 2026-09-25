/*
 * function: func_02184560
 * address:  0x02184560
 * packet:   pkt_02184560
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02184148  0x02184148  thumb
 */

typedef unsigned int u32;

void func_02184148(u32 x);

void func_02184560(char *p)
{
    func_02184148(*(u32 *)*(u32 **)(p + 4));
}
