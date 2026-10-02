/*
 * function: func_021D9670
 * address:  0x021D9670
 * packet:   pkt_ov093_021D9670
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021D9670(void *a, void *b, int c, int *d, u16 e)
{
    u8 *p;

    if (c == func_021D775C(4) && *d == 1) {
        func_021C88B4(b, 2, c);
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, e);
        func_021C8860(p + 4, c);
        func_021C88C8(b, p);
        func_021C88B4(b, 3, c);
        *d = 0;
    }
}
