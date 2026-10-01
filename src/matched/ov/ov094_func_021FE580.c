/*
 * function: func_021FE580
 * address:  0x021FE580
 * packet:   pkt_ov094_021FE580
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 */
extern unsigned int **func_02030EE8(void *h);

void func_021FE580(void *h)
{
    unsigned int *p = *func_02030EE8(h);

    *p &= ~4u;
}
