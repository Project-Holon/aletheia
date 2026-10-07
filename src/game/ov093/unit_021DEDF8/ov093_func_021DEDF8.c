/*
 * function: func_021DEDF8
 * address:  0x021DEDF8
 * packet:   pkt_ov093_021DEDF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021E8C50  0x021E8C50  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern int func_021DCFF8(int a, int b);
union U;
extern void func_021E8C50(union U *p, u32 v);

void func_021DEDF8(int a, int b, int c)
{
    int t;
    u8 k;

    if (c == func_021D775C(2) && (u32)func_021D775C(0x53) <= 1) {
        t = func_021D775C(0x1e);
        k = func_021DCFF8(a, 2);
        func_021E8C50((union U *)(&t), k);
        func_021D76BC(0x1e, t);
    }
}
