/*
 * function: func_021EF68C
 * address:  0x021EF68C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Forward the word at +0x74 plus constants to func_0202CB4C.
 */

extern void func_0202CB4C(int, int, int, int);

void func_021EF68C(char *p)
{
    func_0202CB4C(*(int *)(p + 0x74), 0xb, 0, 0x15);
}

