/*
 * function: func_021AFC88
 * address:  0x021AFC88
 * packet:   pkt_ov021_021AFC88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0200C1C4  0x0200C1C4  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(void *p);
extern void *func_0200C0F0(void *sys);
extern int func_02158F74();
extern int func_0200C1C4();
extern int func_0201EFA4();

int func_021AFC88(Ctx *a0, int a1)
{
    void *t = func_0215A5F4((void *)a1);
    void *h;
    int r;
    u8 *p;
    int b;

    h = func_0200C0F0(func_02012EBC(func_0215A5E4((void *)a1)));
    r = func_02158F74(t);
    p = a0->cur;
    b = *p;
    a0->cur = p + 1;
    func_0201EFA4(r, b, func_0200C1C4(h), 9, 1, 1);
    return 0;
}
