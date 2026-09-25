/*
 * function: func_021BF78C
 * address:  0x021BF78C
 * packet:   pkt_021BF78C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE9B8 0x021BE9B8 thumb
 */

extern int func_021BE9B8(int, int, int);

void func_021BF78C(char *a, int unused, int *p)
{
    *(int *)(a + 0x2c) = func_021BE9B8(*(int *)(a + 0x20), p[0], p[1]);
}
