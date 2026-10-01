/*
 * function: func_0220203C
 * address:  0x0220203C
 * packet:   pkt_ov094_0220203C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned int u32;
extern int *func_02030EE8(void *h);

void func_0220203C(void *h)
{
    int *q = func_02030EE8(h);
    char *p = (char *)q[0];
    *(u32 *)(p + 0x7c) &= (1 << q[4]) ^ -1;
}
