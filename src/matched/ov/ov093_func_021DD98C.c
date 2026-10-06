/*
 * function: func_021DD98C
 * address:  0x021DD98C
 * packet:   pkt_ov093_021DD98C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021DD9E8  0x021DD9E8  thumb  ov093
 *   d_021F1364     0x021F1364  data  ov093  a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef signed char    s8;
extern void *func_021C7CF4(int *p, int i);
extern u8 *func_021C8120(u8 *p, int b);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_021D78AC(u32 range);
extern void func_021DD9E8(void *a, int b, int c, int d);
extern u8 d_021F1364[5];

void func_021DD98C(int x, void *a, u8 b)
{
    void *m = func_021C7CF4(a, b);
    u8 *buf = func_021C8120(a, 5);
    u32 n;
    u32 i;
    u8 e;

    i = 0;
    n = 0;
    for (; i < 5; i++) {
        e = d_021F1364[i];
        if (func_021D5D14(m, e, 1) != 0)
            buf[n++] = e;
    }
    if (n != 0)
        func_021DD9E8(a, b, buf[func_021D78AC(n)], 2);
}
