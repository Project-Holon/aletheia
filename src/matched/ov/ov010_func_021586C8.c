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

typedef unsigned int   u32;
struct Rec44;
struct Sub24;
extern int func_02158344(int a0);
extern u32 func_02026478(void *obj);
extern int func_02175B14(void *);
extern int func_02176230(void *, void *);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008500(void *a, void *b);

int func_021586C8(int a, int b)
{
    char *q = (char *)func_02158344(a);
    int r = func_02026478((void *)a);
    if (q == 0 || func_02175B14(q + 0x1AC) == 0)
        return 0;
    func_02008500(func_02012950((struct Sub24 *)r, func_02176230(q, q + 0x1AC)), (void *)b);
    return 1;
}
