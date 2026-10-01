/*
 * function: func_022047CC
 * address:  0x022047CC
 * packet:   pkt_ov094_022047CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0220687C  0x0220687C  thumb  ov094
 */
extern int func_0204B98C(void *h);
extern void func_0220687C(void *p, void *a);

void func_022047CC(void *a, void **s)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (s[i + 2] != 0 && func_0204B98C(s[i + 2]) != 0)
            return;
    }
    func_0220687C(s[0], a);
}
