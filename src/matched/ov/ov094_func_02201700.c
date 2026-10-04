/*
 * function: func_02201700
 * address:  0x02201700
 * packet:   pkt_ov094_02201700
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 */
typedef unsigned int u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

void func_02201700(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    *(u32 *)(p + 0x510) &= ~4;
}
