/*
 * file:     field_player_grid_event_p21.c
 * unit:     yes
 * function: func_021C1318, func_021C146C, func_021C14F8
 * address:  0x021C1318
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021C12E4  0x021C12E4  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 */
#include "../../matched/include/Obj01665.h"
#include "../../matched/include/Obj01359.h"
#include "../../matched/include/Obj01506.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *func_021A3074(unsigned char *p);
extern int func_0216DB4C(void *a0, int a1);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_02164208(int dir, int *p, int amt);
extern void func_02164280(int x, int y, int *p);
extern void func_02163E58(void *a, Vec3 *v, int *out);
extern u32 func_021A2F98(u8 *p);
extern void func_021ACBB8(u32 a, u8 v);
extern u32 func_02188CD0(u8 *p);
extern void func_021ABE30(int a, int *b, int c);
extern u32 func_021AD564(u32 a, u32 b, u32 c);
extern void func_021C6B18(u32 a, u16 b, u32 c);
extern void func_020061E4(u32 se);
extern void func_0216D89C(void *a, Vec3 *v);
extern void func_021AC154(u32 a);
extern void func_021C12E4(void *a, u8 *b);
extern int func_0209C0A4(int a, int b);
int func_021C1318(u8 *p);
int func_021C146C(u8 *p);
int func_021C14F8(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
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

    o = func_021A3074(((struct Obj01665 *)p)->f3C);
    k = 1;
    func_0216DB4C(o, 1);
    func_0216D88C(o, (struct VecFx32 *)&v);
    a = v;
    b = a;
    c = a;
    func_02164208(((struct Obj01665 *)p)->f4, (int *)(&b), 0x10000);
    func_02164208(((struct Obj01665 *)p)->f4, (int *)(&c), 0x20000);
    func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
    func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(p + 0x24));
    *(Vec3 *)(p + 0x24) = c;
    func_02163E58(o, &c, (int *)(p + 0x28));
    ((struct Obj01665 *)p)->f30 = (b.x - v.x) / 2 / 16;
    ((struct Obj01665 *)p)->f38 = (b.z - v.z) / 2 / 16;
    ((struct Obj01665 *)p)->f34 = 0x6000;
    ((struct Obj01665 *)p)->f1C = 0x1000;
    r6 = func_021A2F98((u8 *)(*(u32 *)&((struct Obj01665 *)p)->f3C));
    func_021ACBB8(r6, 2);
    if ((u16)(((struct Obj01665 *)p)->f4 + 0xfffe) <= 1)
        k = 3;
    r7 = func_02188CD0((u8 *)(((struct Obj01665 *)p)->f40));
    n = 9;
    func_021ABE30(r7, &n, 1);
    ((struct Obj01665 *)p)->f48 = func_021AD564(r7, k, r6);
    func_021C6B18(((struct Obj01665 *)p)->f40, 0x10, 0x20000);
    func_020061E4(0x6e0);
    ((struct Obj01665 *)p)->f2 = ((struct Obj01665 *)p)->f2 + 1;
    return 1;
}


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


int func_021C14F8(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(((struct Obj01506 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    v.y += ((struct Obj01506 *)p)->f34;
    if (v.y >= ((struct Obj01506 *)p)->f28) {
        v.y = ((struct Obj01506 *)p)->f28;
        ((struct Obj01506 *)p)->f2 = ((struct Obj01506 *)p)->f2 + 1;
        ((struct Obj01506 *)p)->f30 = (((struct Obj01506 *)p)->f24 - v.x) / 16;
        ((struct Obj01506 *)p)->f38 = (((struct Obj01506 *)p)->f2C - v.z) / 16;
        ((struct Obj01506 *)p)->f10 = -0x8000;
        ((struct Obj01506 *)p)->f34 = 0x6000;
        ((struct Obj01506 *)p)->f10 = func_0209C0A4(-0x8000, 0xb);
        func_021C6B18(((struct Obj01506 *)p)->f40, 0x10, (u32)-0x8000 << 2);
        func_021AC154(((struct Obj01506 *)p)->f48);
    }
    func_0216D89C(r4, &v);
    return 0;
}
