/*
 * function: func_021F8914
 * address:  0x021F8914
 * packet:   pkt_ov094_021F8914
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns func_021BA20C of the handle at 0x1e4 of the global work block, or 0 when it is null.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021BA20C 0x021BA20C thumb ov093
 */
extern char *d_0220AF20;
extern int func_021BA20C(void *);

int func_021F8914(void)
{
    int r = 0;
    void *h = *(void **)(d_0220AF20 + 0x1e4);
    if (h != 0)
        r = func_021BA20C(h);
    return r;
}
