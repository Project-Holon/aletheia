/*
 * function: func_0689B7FC
 * address:  0x0689B7FC
 * packet:   pkt_ov095_0689B7FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Only the six real cases are written (8, 0x12, 0x14, 0x15, 0x17, 0x23), in
 * that source order; adding empty `case 0x13:`/`case 0x16:` arms pulls 8 into
 * one big table and swaps the a/t registers.
 *
 * symbols:
 *   func_0689B89C  0x0689B89C  thumb  ov095
 *   func_0689B8AC  0x0689B8AC  thumb  ov095
 *   func_0689B8BC  0x0689B8BC  thumb  ov095
 *   func_0689B974  0x0689B974  thumb  ov095
 *   func_0689B9F4  0x0689B9F4  thumb  ov095
 *   func_0689BB7C  0x0689BB7C  thumb  ov095
 *   func_0689BC30  0x0689BC30  thumb  ov095
 *   func_0689BDE0  0x0689BDE0  thumb  ov095
 *   func_0689BEAC  0x0689BEAC  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0689B89C(u32 a);
extern int func_0689B8AC(u32 a, u32 b);
extern void func_0689B8BC(u32 a, u32 b, u32 c, int d);
extern void func_0689B974(u32 a, u32 b, u32 c);
extern void func_0689B9F4(u32 a, u32 b, u32 c);
extern void func_0689BB7C(u32 a, u32 b, u32 c);
extern void func_0689BC30(u32 a, u32 b, u32 c);
extern void func_0689BDE0(u32 a, u32 b, u32 c);
extern void func_0689BEAC(u32 a, u32 b, u32 c);

void func_0689B7FC(u32 a, u32 b, u32 c, int t)
{
    int r;

    if (func_0689B89C(b) != 0)
        return;
    r = func_0689B8AC(b, t);
    if (r != 0)
        func_0689B8BC(a, b, t, r);
    switch (t) {
    case 0x14:
        func_0689B974(a, b, c);
        break;
    case 0x12:
        func_0689B9F4(a, b, c);
        break;
    case 0x15:
        func_0689BB7C(a, b, c);
        break;
    case 8:
        func_0689BC30(a, b, c);
        break;
    case 0x23:
        func_0689BDE0(a, b, c);
        break;
    case 0x17:
        func_0689BEAC(a, b, c);
        break;
    }
}
