/*
 * function: func_021B229C
 * address:  0x021B229C
 * packet:   pkt_ov021_021B229C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B229C  0x021B229C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021C7684  0x021C7684  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   d_021D9424     0x021D9424  data   a4
 */

typedef short s16;
typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

extern const Vec d_021D9424;

extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *, void *);
extern u32 func_0215A5EC(u32);
extern u32 func_0216DE94(u32, u32);
extern u32 *func_02158F58(void *);
extern u32 func_02188D38(u32);
extern int func_02163E58(u32 m, Vec *pos, int *h);
extern void func_0216E084(u32 m, s16 x, s16 y, s16 z, u32 e);
extern void func_0216D89C(u32, Vec *);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_021C7684(u32 a, u32 b, int c, int d);
extern void func_021C6DE0(u32, u32, u32);

int func_021B229C(u32 a, u32 b)
{
    Vec pos;
    Vec rot;
    int h;
    u32 k0, k1, k2, k3, o, e, g;
    void *t;

    t = func_0215A5F4((void *)b);
    k0 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    k2 = func_02159B10((void *)a, (void *)b);
    k3 = func_02159B10((void *)a, (void *)b);
    o = func_0216DE94(func_0215A5EC(b), k0);
    e = func_02158F58(t)[1];
    g = func_02188D38(e);
    if (o == 0) {
        return 0;
    }
    h = 0;
    pos.x = (k1 << 16) + 0x8000;
    pos.y = 0xFA000;
    pos.z = (k2 << 16) + 0x8000;
    func_02163E58(o, &pos, &h);
    pos.y = h;
    func_0216E084(o, k1, (pos.y >> 4) / 0x1000, k2, k3);
    func_0216D89C(o, &pos);
    rot = d_021D9424;
    func_0216D8C0(o, &rot);
    func_021C6DE0(g, func_021C7684(e, o, 0x28, 0xfa), 0);
    return 0;
}
