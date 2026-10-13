/*
 * file:     dwc_auth_1.c
 * function: func_02177EC8
 * address:  0x02177EC8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the word at the state object.
 *
 * symbols:
 *   g_021A2358  0x021A2358  data
 */

extern char g_021A2358[];

void func_02177EC8(int v)
{
    *(int *)g_021A2358 = v;
}

