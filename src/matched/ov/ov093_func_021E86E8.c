/*
 * function: func_021E86E8
 * address:  0x021E86E8
 * packet:   pkt_ov093_021E86E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E86C8  0x021E86C8  thumb  ov093
 *   func_021E869C  0x021E869C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021E8638  0x021E8638  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021E86C8(void *a, int b);
extern int func_021E869C(void *a, int b);
struct QF;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
struct QI;
extern u16 func_021D5B40(struct QI *p);
extern int func_021E8638(int a, int b);

int func_021E86E8(void *a, int b, int c)
{
    void *x;
    void *y;
    int t;
    u16 h;

    if (func_021E86C8(a, b) != 0)
        return 1;
    if (func_021E869C(a, c) != 0)
        return 1;
    x = func_021C7CF4(a, b);
    y = func_021C7CF4(a, c);
    t = func_021D5444(x);
    h = (int)func_021D5B40(y);
    if (func_021E8638(t, h) != 0)
        return 1;
    return 0;
}
