/*
 * function: func_021B1FB8
 * address:  0x021B1FB8
 * packet:   pkt_ov021_021B1FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02161AC0  0x02161AC0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5F4(u32);
extern int func_02159B10(u32, u32);
extern u32 func_0215A5EC(u32);
extern u32 func_0215A5DC(u32);
extern u32 func_0216DE94(u32, int);
extern void func_0216D88C(u32, void *);
extern u32 func_02161AC0(u32, u32, void *, void *);
extern void func_0215897C(u32, u32);

int func_021B1FB8(u32 a, u32 b)
{
    int buf[3];
    int vec[3];
    u32 t;
    int i;
    int x;
    int y;
    int z;
    u32 m;
    u32 w;
    u32 o;

    t = func_0215A5F4(b);
    i = func_02159B10(a, b);
    x = func_02159B10(a, b);
    y = func_02159B10(a, b);
    z = func_02159B10(a, b);
    m = func_0215A5EC(b);
    w = func_0215A5DC(b);
    o = func_0216DE94(m, i);
    func_0216D88C(o, buf);
    vec[0] = (x << 16) + 0x8000;
    vec[1] = y << 16;
    vec[2] = (z << 16) + 0x8000;
    func_0215897C(t, func_02161AC0(w, o, buf, vec));
    return 1;
}
