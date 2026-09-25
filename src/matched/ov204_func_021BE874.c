/*
 * function: func_021BE874
 * address:  0x021BE874
 * packet:   pkt_021BE874
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFBC8 0x021BFBC8 thumb
 */

extern void func_021BFBC8(int, int);

int func_021BE874(char *a, int b, int *p)
{
    func_021BFBC8(*(int *)(a + 0xc), *p);
    return 1;
}
