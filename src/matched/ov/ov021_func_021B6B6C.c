/*
 * function: func_021B6B6C
 * address:  0x021B6B6C
 * packet:   pkt_ov021_021B6B6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A6C4  0x0215A6C4  thumb  ov010
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 *   func_021B6AB0  0x021B6AB0  thumb
 *   func_021B6AA4  0x021B6AA4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern u32 func_02159B10(void *, void *);
extern void *func_0215A6C4(void *);
extern u16 func_0215A5D0(void *);
extern u32 func_021B6AB0(void *);
extern u16 *func_021B6AA4(void *, u32);
extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *);
extern void *func_0201210C(void *p);
extern int func_021854B0(void *, void *, int, Vec3 *, int);
extern void func_0215897C(void *, int);

u32 func_021B6B6C(void *a, void *b)
{
    u32 idx = func_02159B10(a, b);
    void *tab = func_0215A6C4(b);

    func_0215A5D0(b);
    if (idx < func_021B6AB0(tab)) {
        const u16 *e = func_021B6AA4(tab, idx);
        void *r5 = func_0215A5F4(b);
        void *r6 = func_02158F54(r5);
        void *cur = func_0201210C();
        Vec3 v;
        u32 f3 = e[3];
        u32 f4 = e[4];
        u32 f1 = e[1];
        u32 f2 = e[2];

        v.x = f2 << 16;
        v.y = f3 << 16;
        v.z = f4 << 16;
        func_0215897C(r5, func_021854B0(r6, cur, f1, &v, 1));
    }
    return 1;
}
