/*
 * function: func_021FE750
 * address:  0x021FE750
 * packet:   pkt_ov094_021FE750
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 */
typedef unsigned int   u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

void func_021FE750(void *h)
{
    unsigned int *p = *((unsigned int **)func_02030EE8(h));

    *p &= ~0x800u;
}
