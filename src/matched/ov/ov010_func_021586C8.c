/*
 * function: func_021586C8
 * address:  0x021586C8
 * packet:   pkt_ov010_021586C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158344  0x02158344  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02175B14  0x02175B14  thumb
 *   func_02176230  0x02176230  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008500  0x02008500  thumb
 */

extern char *func_02158344(int);
extern int func_02026478(int);
extern int func_02175B14(void *);
extern int func_02176230(void *, void *);
extern int func_02012950(int, int);
extern void func_02008500(int, int);

int func_021586C8(int a, int b)
{
    char *q = func_02158344(a);
    int r = func_02026478(a);
    if (q == 0 || func_02175B14(q + 0x1AC) == 0)
        return 0;
    func_02008500(func_02012950(r, func_02176230(q, q + 0x1AC)), b);
    return 1;
}
