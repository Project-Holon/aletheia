/*
 * function: func_02201FD8
 * address:  0x02201FD8
 * packet:   pkt_ov094_02201FD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned int u32;
extern int *func_02030EE8(void *h);

void func_02201FD8(void *h)
{
    int *q = func_02030EE8(h);
    char *p = (char *)q[0];
    *(u32 *)(p + 0x78) &= (1 << q[4]) ^ -1;
}
