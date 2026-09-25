/*
 * function: func_021F5EB8
 * address:  0x021F5EB8
 * packet:   pkt_021F5EB8
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E30 0x02005E30 thumb
 */

extern void func_02005E30(int);

int func_021F5EB8(int a, char *b)
{
    func_02005E30(0x1e);
    *(int *)(b + 0x18) = 1;
    return 1;
}