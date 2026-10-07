/*
 * function: func_021C6054
 * address:  0x021C6054
 * packet:   pkt_ov021_021C6054
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb  ov021
 */

typedef unsigned int u32;
extern void func_021AC154(u32 a);
void func_021C6054(u32 *p)
{
    if (p[12] != 0) {
        func_021AC154(p[12]);
        p[12] = 0;
    }
}
