/*
 * function: func_021F878C
 * address:  0x021F878C
 * packet:   pkt_ov094_021F878C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_022088F4  0x022088F4  thumb  ov094
 *   func_02208900  0x02208900  thumb  ov094
 *   func_0220893C  0x0220893C  thumb  ov094
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005D90  0x02005D90  thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern char *d_0220AF20;
extern int func_022088F4(u32 obj);
extern void func_02208900(u32 obj, u32 v);
extern void func_0220893C(u32 obj, u32 v);
extern void func_02005E9C(void);
extern void func_02005D90(u32 a, u16 b);

void func_021F878C(u32 a)
{
    if (func_022088F4(*(u32 *)(d_0220AF20 + 0x1A4))) {
        func_02208900(*(u32 *)(d_0220AF20 + 0x1A4), 0);
        func_02005E9C();
    }
    func_0220893C(*(u32 *)(d_0220AF20 + 0x1A4), 1);
    func_02005D90(a, 0xFFFF);
}
