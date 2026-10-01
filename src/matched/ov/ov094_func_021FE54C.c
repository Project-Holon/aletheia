/*
 * function: func_021FE54C
 * address:  0x021FE54C
 * packet:   pkt_ov094_021FE54C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FDB40  0x021FDB40  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
extern void func_021FDB40(int a, int b, int c, int d, int e, int f, int g);
extern void func_021F89BC(void *h);

void func_021FE54C(void *h, int *s)
{
    if (--s[4] == 0) {
        func_021FDB40(s[1], s[2], s[3], s[5], s[6], s[7], s[8]);
        func_021F89BC(h);
    }
}
