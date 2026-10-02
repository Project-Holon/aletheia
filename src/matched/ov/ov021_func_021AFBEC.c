/*
 * function: func_021AFBEC
 * address:  0x021AFBEC
 * packet:   pkt_ov021_021AFBEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx;

extern int func_02159B10();
extern void *func_0215A5F4(void *p);
extern int func_02158F74();

int func_021AFBEC(Ctx *a0, int a1, int (*fn)())
{
    u8 *p = a0->cur;
    int b = *p;
    int t;

    a0->cur = p + 1;
    t = func_02159B10(a0, a1);
    fn(func_02158F74(func_0215A5F4((void *)a1)), b, (u8)t);
    return 0;
}
