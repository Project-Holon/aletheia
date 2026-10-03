/*
 * function: func_021C1318
 * address:  0x021C1318
 * packet:   pkt_ov021_021C1318
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_021C6B18  0x021C6B18  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *func_021A3074(unsigned char *p);
extern void func_0216DB4C(void *a, u32 b);
extern void func_0216D88C(void *a, Vec3 *v);
extern void func_02164208(u32 a, Vec3 *v, u32 c);
extern void func_02164280(int x, int y, void *p);
extern void func_02163E58(void *a, Vec3 *v, int *out);
extern u32 func_021A2F98(u32 a);
extern void func_021ACBB8(u32 a, u8 v);
extern u32 func_02188CD0(u32 a);
extern void func_021ABE30(int a, int *b, int c);
extern u32 func_021AD564(u32 a, u32 b, u32 c);
extern void func_021C6B18(u32 a, u16 b, u32 c);
extern void func_020061E4(u32 se);

int func_021C1318(u8 *p)
{
    u32 k;
    void *o;
    u32 r6;
    u32 r7;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = func_021A3074(*(void **)(p + 0x3c));
    k = 1;
    func_0216DB4C(o, 1);
    func_0216D88C(o, &v);
    a = v;
    b = a;
    c = a;
    func_02164208(*(u16 *)(p + 4), &b, 0x10000);
    func_02164208(*(u16 *)(p + 4), &c, 0x20000);
    func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), &b);
    func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), p + 0x24);
    *(Vec3 *)(p + 0x24) = c;
    func_02163E58(o, &c, (int *)(p + 0x28));
    *(int *)(p + 0x30) = (b.x - v.x) / 2 / 16;
    *(int *)(p + 0x38) = (b.z - v.z) / 2 / 16;
    *(int *)(p + 0x34) = 0x6000;
    *(int *)(p + 0x1c) = 0x1000;
    r6 = func_021A2F98(*(u32 *)(p + 0x3c));
    func_021ACBB8(r6, 2);
    if ((u16)(*(u16 *)(p + 4) + 0xfffe) <= 1)
        k = 3;
    r7 = func_02188CD0(*(u32 *)(p + 0x40));
    n = 9;
    func_021ABE30(r7, &n, 1);
    *(u32 *)(p + 0x48) = func_021AD564(r7, k, r6);
    func_021C6B18(*(u32 *)(p + 0x40), 0x10, 0x20000);
    func_020061E4(0x6e0);
    *(s16 *)(p + 2) = *(s16 *)(p + 2) + 1;
    return 1;
}
