/*
 * function: func_021C157C
 * address:  0x021C157C
 * packet:   pkt_ov021_021C157C
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
 *   func_021C12E4  0x021C12E4  thumb  ov021
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
extern void func_021C12E4(void *a, u8 *b);

int func_021C157C(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(*(void **)(p + 0x3c));
    func_0216D88C(r4, &v);
    if (v.x < *(int *)(p + 0x24)) {
        v.x += *(int *)(p + 0x30);
        if (v.x > *(int *)(p + 0x24))
            v.x = *(int *)(p + 0x24);
    } else {
        v.x += *(int *)(p + 0x30);
        if (v.x < *(int *)(p + 0x24))
            v.x = *(int *)(p + 0x24);
    }
    if (v.z < *(int *)(p + 0x2c)) {
        v.z += *(int *)(p + 0x38);
        if (v.z > *(int *)(p + 0x2c))
            v.z = *(int *)(p + 0x2c);
    } else {
        v.z += *(int *)(p + 0x38);
        if (v.z < *(int *)(p + 0x2c))
            v.z = *(int *)(p + 0x2c);
    }
    v.y += *(int *)(p + 0x34);
    *(int *)(p + 0x34) += *(int *)(p + 0x10);
    *(u16 *)(p + 8) += 1;
    if (*(u16 *)(p + 8) >= 0x10) {
        v = *(Vec3 *)(p + 0x24);
        *(int *)(p + 0x18) = 0;
        *(int *)(p + 0x1c) = 0;
        *(int *)(p + 0x20) = 0;
        *(s16 *)(p + 2) = *(s16 *)(p + 2) + 1;
    }
    func_0216D89C(r4, &v);
    func_021C12E4(r4, p + 0x18);
    return 0;
}
