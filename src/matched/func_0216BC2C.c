/*
 * function: func_0216BC2C
 * address:  0x0216BC2C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Address of the i-th entry of the eight-byte table.
 *
 * symbols:
 *   g_021AA920  0x021AA920  data
 */

extern char g_021AA920[];

void *func_0216BC2C(int i)
{
    return g_021AA920 + i * 8;
}

