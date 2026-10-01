/*
 * function: func_02209A40
 * address:  0x02209A40
 * packet:   pkt_ov094_02209A40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

extern int **func_02030EE8(void *h);

void func_02209A40(void *h)
{
    int *w = *func_02030EE8(h);
    w[1] &= ~1;
}
