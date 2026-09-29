/*
 * function: func_02005DA4
 * address:  0x02005DA4
 * packet:   pkt_02005DA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sub_02005F70  0x02005F70  thumb
 *
 * Wrapper that forwards all four arguments to sub_02005F70.  Seeded in
 * layout/function_starts.txt from its only caller, the bl at ov012
 * 0x021745D0 (w6_fix18).
 */

extern void sub_02005F70(unsigned int a, unsigned short b, int c, int d);

void func_02005DA4(unsigned int a, unsigned short b, int c, int d)
{
    sub_02005F70(a, b, c, d);
}
