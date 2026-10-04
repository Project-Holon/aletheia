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
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

void func_022043AC(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    *(u32 *)(p + 0x68) &= ~1;
}
