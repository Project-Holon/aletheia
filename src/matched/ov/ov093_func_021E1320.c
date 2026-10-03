/*
 * function: func_021E1320
 * address:  0x021E1320
 * packet:   pkt_ov093_021E1320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E8B28  0x021E8B28  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned short u16;

extern int func_021D775C(int key);
typedef unsigned int   u32;
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void func_021E8B28(void *p, u16 v);
extern int func_021D76BC(int key, u32 val);

void func_021E1320(void *a, int b, int c)
{
    int v;
    u16 n;

    if (c != func_021D775C(3))
        return;
    n = func_021D70A8(a);
    v = func_021D775C(30);
    func_021E8B28(&v, n);
    func_021D76BC(30, v);
}
