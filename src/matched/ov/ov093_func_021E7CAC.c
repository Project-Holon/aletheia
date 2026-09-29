/*
 * function: func_021E7CAC
 * address:  0x021E7CAC
 * packet:   pkt_ov093_021E7CAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E7CAC(int a, u8 *b, int c)
{
    u8 *p;
    if (c == func_021D775C(3)) {
        p = func_021C88A4(b, 0x2f, c);
        p[4] = func_021D775C(6);
        func_021C8838(p + 8, 2, 1134);
        func_021C8860(p + 8, p[4]);
        func_021C88C8(b, p);
    }
}
