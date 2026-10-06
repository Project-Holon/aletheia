/*
 * function: func_021C146C
 * address:  0x021C146C
 * packet:   pkt_ov021_021C146C
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
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_021C12E4  0x021C12E4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01359.h"

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
extern void func_021AC154(u32 a);
extern u32 func_021A2F98(u8 *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021AD564(u32 a, u32 b, u32 c);
extern void func_021C12E4(void *a, u8 *b);

int func_021C146C(u8 *p)
{
    Vec3 v;
    void *r4;
    u32 r6;

    r4 = func_021A3074(((struct Obj01359 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    v.x += ((struct Obj01359 *)p)->f30;
    v.z += ((struct Obj01359 *)p)->f38;
    func_0216D89C(r4, &v);
    ((struct Obj01359 *)p)->f1C = -((struct Obj01359 *)p)->f1C;
    ((struct Obj01359 *)p)->f8 += 1;
    if (((struct Obj01359 *)p)->f8 >= 0x10) {
        ((struct Obj01359 *)p)->f8 = 0;
        ((struct Obj01359 *)p)->f1C = 0;
        ((struct Obj01359 *)p)->f2 = ((struct Obj01359 *)p)->f2 + 1;
        func_021AC154(((struct Obj01359 *)p)->f48);
        r6 = func_021A2F98((u8 *)(*(u32 *)&((struct Obj01359 *)p)->f3C));
        {
            u32 k = 2;
            if ((u16)(((struct Obj01359 *)p)->f4 + 0xfffe) <= 1)
                k = 2;
            ((struct Obj01359 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj01359 *)p)->f40)), k, r6);
        }
    }
    func_021C12E4(r4, p + 0x18);
    return 0;
}
