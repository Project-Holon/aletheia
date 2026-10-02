/*
 * function: func_021C14F8
 * address:  0x021C14F8
 * packet:   pkt_ov021_021C14F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021C6B18  0x021C6B18  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *func_021A3074(unsigned char *p);
extern void func_0216D88C(void *a, Vec3 *v);
extern void func_0216D89C(void *a, Vec3 *v);
extern int func_0209C0A4(int a, int b);
extern void func_021C6B18(u32 a, u32 b, u32 c);
extern void func_021AC154(u32 a);

int func_021C14F8(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(*(void **)(p + 0x3c));
    func_0216D88C(r4, &v);
    v.y += *(int *)(p + 0x34);
    if (v.y >= *(int *)(p + 0x28)) {
        v.y = *(int *)(p + 0x28);
        *(s16 *)(p + 2) = *(s16 *)(p + 2) + 1;
        *(int *)(p + 0x30) = (*(int *)(p + 0x24) - v.x) / 16;
        *(int *)(p + 0x38) = (*(int *)(p + 0x2c) - v.z) / 16;
        *(int *)(p + 0x10) = -0x8000;
        *(int *)(p + 0x34) = 0x6000;
        *(int *)(p + 0x10) = func_0209C0A4(-0x8000, 0xb);
        func_021C6B18(*(u32 *)(p + 0x40), 0x10, (u32)-0x8000 << 2);
        func_021AC154(*(u32 *)(p + 0x48));
    }
    func_0216D89C(r4, &v);
    return 0;
}
