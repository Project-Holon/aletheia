/*
 * function: func_021DF3A4
 * address:  0x021DF3A4
 * packet:   pkt_ov093_021DF3A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E889C  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021E889C(int a, int b, int c);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C888C(void *p, int v);
extern int func_021D70A8(int a);

void func_021DF3A4(int a, void *b, int c)
{
    u8 *r;

    if (func_021E889C(a, (int)b, c) != 0) {
        r = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(r + 4, 2, 0x3ec);
        func_021C8860(r + 4, c);
        func_021C8860(r + 4, func_021D70A8(a));
        func_021C888C(r + 4, 0x56a);
        func_021C88C8(b, r);
    }
}
