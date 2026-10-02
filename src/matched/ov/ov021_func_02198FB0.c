/*
 * function: func_02198FB0
 * address:  0x02198FB0
 * packet:   pkt_ov021_02198FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021D04C4  0x021D04C4  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0219BF54  0x0219BF54  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern u32 *func_0216D6D4(u32);
extern u32 *d_021DDBD4;
extern void func_0216D8C0(u32, Vec *);
extern u32 func_0219BF48(u32);
extern u32 func_021D04C4(u32 a);
extern u32 func_021AC154(u32);
extern u32 func_0219BF3C(u32, u32);
extern u32 func_0216D568(u32, u32);
extern u32 func_0219BF54(u32);
extern u32 func_0216D7CC(u32);

int func_02198FB0(u32 a)
{
    u32 *p;
    u32 r;

    p = func_0216D6D4(a);
    {
        Vec v = { 0, 0, 0 };
        v.y = d_021DDBD4[p[0]];
        func_0216D8C0(a, &v);
        r = func_0219BF48(a);
        if (r != 0) {
            if (func_021D04C4(r) == 1) {
                func_021AC154(r);
                func_0219BF3C(a, 0);
            }
        }
        p[0] = p[0] + 2;
        if (p[0] < 16) {
            return 0;
        }
        v.y = 0;
        func_0216D8C0(a, &v);
    }
    func_0216D568(a, 1344);
    func_0219BF54(a);
    func_0216D7CC(a);
    return 1;
}
