/*
 * function: func_02158630
 * address:  0x02158630
 * packet:   pkt_ov010_02158630
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02158344  0x02158344  thumb
 *   func_02175B14  0x02175B14  thumb
 *   func_02176258  0x02176258  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02158590  0x02158590  thumb
 */

extern int func_02158344(void);
extern int func_02175B14(int);
extern int func_02176258(int);
extern int func_02026478(int);
extern int func_02158590(void);

int func_02158630(int a)
{
    int q = func_02158344();
    if (q == 0)
        return 0;
    if (func_02175B14(q + 0x1AC) == 1) {
        if (func_02176258(q) == 1)
            return 2;
        func_02026478(a);
        if (func_02158590() == 0)
            return 1;
        return 3;
    }
    return 1;
}
