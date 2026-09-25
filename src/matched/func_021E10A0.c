/*
 * function: func_021E10A0
 * address:  0x021E10A0
 * packet:   pkt_021E10A0
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025538  0x02025538  thumb
 */

extern int func_02025538(int, int);

void func_021E10A0(char *p)
{
    *(int *)(p + 0x300) =
        func_02025538(*(unsigned short *)(p + 0x34c), *(int *)(p + 0x25c));
}
