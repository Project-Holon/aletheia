/*
 * function: func_02169E98
 * address:  0x02169E98
 * packet:   pkt_02169E98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020452E8  0x020452E8  arm
 */

typedef unsigned int u32;

void func_020452E8(u32 x);

void func_02169E98(char *p)
{
    func_020452E8(*(u32 *)(*(char **)(p + 0x18) + 8));
}
