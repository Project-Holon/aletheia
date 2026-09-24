/*
 * function: func_0217F790
 * address:  0x0217F790
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * probe
 *
 * symbols:
 *   g_021A37C8  0x021A37C8  data
 */

extern char g_021A37C8[];

void func_0217F790(unsigned int v)
{
    *(int *)g_021A37C8 = v ? (int)(v & 0x7fffffff) : 1;
}

