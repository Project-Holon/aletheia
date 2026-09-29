/*
 * function: func_021E5D54
 * address:  0x021E5D54
 * packet:   pkt_ov093_021E5D54
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern u32 func_021D5B40(void *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, int v);
extern void func_021C88C8(void *a, void *b);

void func_021E5D54(u8 *p, void *a, int b)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != func_021D775C(3))
        return;
    r = func_021C7CF4(a, b);
    v = func_021D5B40(r);
    if (v == 0)
        return;
    q = func_021C88A4(a, 4, b);
    func_021C8838(q + 4, 2, 0x30b);
    func_021C8860(q + 4, b);
    func_021C8860(q + 4, v);
    func_021C88C8(a, q);
}
