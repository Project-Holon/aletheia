/*
 * function: func_021A40A8
 * address:  0x021A40A8
 * packet:   pkt_ov021_021A40A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3D6C  0x021A3D6C  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02164240  0x02164240  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0219F5C8  0x0219F5C8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void func_021A3D6C(u8 *, int);
extern int func_021A3974(u8 *);
extern u32 func_021A3960(u8 *);
extern u32 func_0216D67C(u32);
extern int func_0216D83C(u32);
extern int func_0216D86C(u32);
extern void func_02164240(int, s16 *, s16 *, int);
extern u32 func_0216DDC0(u32, int, int, int);
extern void func_0219F5C8(u32, int);

int func_021A40A8(u8 *p)
{
    s16 v[2];
    int f;
    u32 a;
    u32 b;

    func_021A3D6C(p, 8);
    if (*(u16 *)(p + 0x32) == 1 && func_021A3974(p) == 2) {
        f = 0;
        a = func_021A3960(p);
        b = func_0216D67C(a);
        v[1] = func_0216D83C(a);
        v[0] = func_0216D86C(a);
        func_02164240(1, &v[1], &v[0], 1);
        if (func_0216DDC0(b, v[1], v[0], 1) != 0) {
            f = 1;
        }
        func_0219F5C8(a, f);
    }
    return 0;
}
