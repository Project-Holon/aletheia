/*
 * function: func_021BF79C
 * address:  0x021BF79C
 * packet:   pkt_021BF79C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE9E8 0x021BE9E8 thumb
 */

extern void func_021BE9E8(int);

void func_021BF79C(char *a)
{
    func_021BE9E8(*(int *)(a + 0x2c));
    *(int *)(a + 0x2c) = 0;
}
