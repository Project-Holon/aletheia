/*
 * function: func_022043AC
 * address:  0x022043AC
 * packet:   pkt_ov094_022043AC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 */
typedef unsigned int u32;
extern char **func_02030EE8(void *h);

void func_022043AC(void *h)
{
    char *p = *func_02030EE8(h);
    *(u32 *)(p + 0x68) &= ~1;
}
