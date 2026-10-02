/*
 * function: func_02198F68
 * address:  0x02198F68
 * packet:   pkt_ov021_02198F68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021D04A4  0x021D04A4  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern u32 func_0216D6BC(u32, u32);
extern u32 func_0219BF48(u32);
extern void func_021D04A4(u32 a);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_0216D568(u32, u32);
extern u32 func_0216D570(u32, u32);
extern u32 func_0216D7CC(u32);

int func_02198F68(u32 a)
{
    u32 t;

    func_0216D6BC(a, 4);
    t = func_0219BF48(a);
    if (t != 0) {
        func_021D04A4(t);
    }
    {
        Vec v = { 0, 0, 0 };
        func_0216D8C0(a, &v);
    }
    func_0216D568(a, 160);
    func_0216D570(a, (2 << 14));
    func_0216D7CC(a);
    return 0;
}
