/*
 * function: func_021FE768
 * address:  0x021FE768
 * packet:   pkt_ov094_021FE768
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9220  0x021F9220  thumb  ov094
 *   func_0200F698  0x0200F698  thumb
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
extern void func_021F9220(int *p, int *d, int *lim, int *flag);
extern void func_0200F698(int id, int v);
extern void func_021F89BC(void *h);

void func_021FE768(void *h, int *s)
{
    int flag = 1;

    func_021F9220(&s[1], &s[3], &s[2], &flag);
    func_0200F698(0xffff, s[1] >> 12);
    if (flag)
        func_021F89BC(h);
}
