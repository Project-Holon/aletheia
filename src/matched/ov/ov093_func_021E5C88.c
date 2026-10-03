/*
 * function: func_021E5C88
 * address:  0x021E5C88
 * packet:   pkt_ov093_021E5C88
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, int v);
extern void func_021C88C8(void *a, void *b);

void func_021E5C88(u8 *p, void *a, int b)
{
    u8 *r;
    if (func_021D76BC(0x51, 1) != 0) {
        r = func_021C88A4(a, 4, b);
        func_021C8838(r + 4, 2, 0x2ff);
        func_021C8860(r + 4, b);
        func_021C88C8(a, r);
    }
}
