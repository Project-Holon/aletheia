/*
 * function: func_021DCC80
 * address:  0x021DCC80
 * packet:   pkt_ov093_021DCC80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021DCCEC  0x021DCCEC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B9A40(int v);
extern u8 func_021B9A5C(int v);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, u16 b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7320(void *a, void *cb);
extern void func_021DCCEC(void);

void func_021DCC80(void *a, void *b, int c, int *d)
{
    u8 *m;
    u32 x;

    if (*d == 0) {
        x = func_021B9A5C(func_021B9A40(c));
        func_021C88B4(b, 2, c);
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 1, 0xb0);
        func_021C8860(m + 4, x);
        func_021C88C8(b, m);
        func_021C88B4(b, 3, c);
        func_021D7320(a, (void *)func_021DCCEC);
        *d = 1;
    }
}
