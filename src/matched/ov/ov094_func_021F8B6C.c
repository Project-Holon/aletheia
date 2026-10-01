/*
 * function: func_021F8B6C
 * address:  0x021F8B6C
 * packet:   pkt_ov094_021F8B6C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs func_021F89BC on each of the 32 live objects at 8 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 */
extern char *d_0220AF20;
extern void func_021F89BC(void *);

void func_021F8B6C(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (((void **)(d_0220AF20 + 8))[i] != 0)
            func_021F89BC(((void **)(d_0220AF20 + 8))[i]);
    }
}
