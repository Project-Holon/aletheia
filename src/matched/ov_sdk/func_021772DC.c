/*
 * function: func_021772DC
 * address:  0x021772DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x724 of the block held at +0x0 of the module state object, zero when the block is unset.
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 */

extern char g_021AB180[];

int func_021772DC(void)
{
    int *p = *(int **)g_021AB180;

    return p != 0 ? *(int *)((char *)p + 0x724) : 0;
}
