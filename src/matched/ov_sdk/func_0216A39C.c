/*
 * function: func_0216A39C
 * address:  0x0216A39C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x1c of the block held at +0x0 of the module state object, zero when the block is unset.
 *
 * symbols:
 *   g_021AA874  0x021AA874  data
 */

extern char g_021AA874[];

int func_0216A39C(void)
{
    int *p = *(int **)g_021AA874;

    return p != 0 ? *(int *)((char *)p + 0x1c) : 0;
}
