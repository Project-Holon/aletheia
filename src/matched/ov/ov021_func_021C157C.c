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
#include "../include/Obj00657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *func_021A3074(unsigned char *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_0216D89C(void *a, Vec3 *v);
extern void func_021C12E4(void *a, u8 *b);

int func_021C157C(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(((struct Obj00657 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    if (v.x < ((struct Obj00657 *)p)->f24) {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x > ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    } else {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x < ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    }
    if (v.z < ((struct Obj00657 *)p)->f2C) {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z > ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    } else {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z < ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    }
    v.y += ((struct Obj00657 *)p)->f34;
    ((struct Obj00657 *)p)->f34 += ((struct Obj00657 *)p)->f10;
    ((struct Obj00657 *)p)->f8 += 1;
    if (((struct Obj00657 *)p)->f8 >= 0x10) {
        v = *(Vec3 *)(p + 0x24);
        ((struct Obj00657 *)p)->f18 = 0;
        ((struct Obj00657 *)p)->f1C = 0;
        ((struct Obj00657 *)p)->f20 = 0;
        ((struct Obj00657 *)p)->f2 = ((struct Obj00657 *)p)->f2 + 1;
    }
    func_0216D89C(r4, &v);
    func_021C12E4(r4, p + 0x18);
    return 0;
}
