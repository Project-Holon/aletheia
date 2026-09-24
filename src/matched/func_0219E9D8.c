/*
 * function: func_0219E9D8
 * address:  0x0219E9D8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the argument equals the word at +0x8 of the module state object.
 *
 * symbols:
 *   g_021AEAF8  0x021AEAF8  data
 */

extern char g_021AEAF8[];

int func_0219E9D8(int v)
{
    return v == *(int *)(g_021AEAF8 + 0x8);
}

