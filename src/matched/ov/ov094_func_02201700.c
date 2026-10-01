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
extern char **func_02030EE8(void *h);

void func_02201700(void *h)
{
    char *p = *func_02030EE8(h);
    *(u32 *)(p + 0x510) &= ~4;
}
