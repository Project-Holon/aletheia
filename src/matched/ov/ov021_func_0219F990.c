/*
 * function: func_0219F990
 * address:  0x0219F990
 * packet:   pkt_ov021_0219F990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CBC  0x02188CBC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3080  0x021A3080  thumb  ov021
 *   func_0219FADC  0x0219FADC  thumb  ov021
 *   func_0219FAB4  0x0219FAB4  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_02013D9C  0x02013D9C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec;

extern u8 *func_0216E3C4(u32);
extern s32 func_02197C9C(u32);
extern void func_0216D8B0(u32, Vec *);
extern s32 func_0216D83C(u32);
extern u32 func_0216D590(u32);
extern u32 func_0216D588(u32);
extern u32 func_0216D67C(u32);
extern u32 func_0216D534(u32);
extern int func_02188CBC(u32);
extern void *func_02188CB4(unsigned char *p);
extern int func_021A3080(int);
extern int func_0219FADC(u8 *p, u32 b, u8 *c);
extern void func_0219FAB4(u32, u32, u8 *, Vec *);
extern void func_0216D8C0(u32, Vec *);
extern int func_02013D9C(u32);

void func_0219F990(u32 a, u8 *p, u32 b)
{
    Vec d;
    Vec v;
    u32 u;
    s32 s14;
    u32 s10;
    s32 sc;
    u8 *info;
    int clr;
    int ok;
    int ff;
    u32 t;
    u8 m;
    int x;

    ok = 1;
    info = func_0216E3C4(a);
    ff = 0;
    d.x = 0;
    d.y = 0;
    d.z = 0;
    s14 = func_02197C9C(a);
    func_0216D8B0(a, &v);
    sc = func_0216D83C(a);
    s10 = func_0216D590(a);
    t = func_0216D588(a);
    if (t == 0xff)
        ff = ok;
    clr = (t == 0xfc) ? 1 : 0;
    if (ff != 0) {
        u = func_0216D534(func_0216D67C(a));
        if (func_02188CBC(u) != 0 && (x = func_02188CB4((void *)u)) != 0) {
            ok = func_021A3080(x) != 0;
        }
    }
    if (s14 != 0 || (v.y > 0x1800 && info[3] != 11)) {
        d.y = v.y;
    } else if (func_0219FADC(p, b, info) == 0 && ok != 0) {
        d.y = d.y + 0x1800;
    }
    if (func_02013D9C(s10) != 0 && ff == 0) {
        m = sc % 3;
        if (m == 0)
            d.z = d.z - 0x219a;
        else if (m == 2)
            d.z = d.z + 0x219a;
        d.z = d.z - 0x2000;
    }
    func_0219FAB4(a, b, info, &d);
    if (clr) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
    }
    func_0216D8C0(a, &d);
    p[3]++;
}
