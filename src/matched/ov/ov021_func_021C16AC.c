/*
 * function: func_021C16AC
 * address:  0x021C16AC
 * packet:   pkt_ov021_021C16AC
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
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021ABE64  0x021ABE64  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021C6B18  0x021C6B18  thumb  ov021
 *   func_021C12E4  0x021C12E4  thumb  ov021
 *   func_021A35A0  0x021A35A0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00129.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *func_021A3074(unsigned char *p);
extern void func_0216DB4C(void *a, u32 b);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_0216D89C(void *a, Vec3 *v);
extern void func_02164208(int dir, int *p, int amt);
extern void func_02164280(int x, int y, int *p);
extern void func_02163E58(void *a, Vec3 *v, int *out);
extern void func_0216E014(void *a, int *p, int b);
extern void *func_021A2F98(u32 a);
extern void func_021ACBB8(u32 a, u8 v);
extern u32 func_02188CD0(u8 *p);
extern void func_021ABE30(int a, int *b, int c);
extern void func_021ABE64(u32 a, int b);
extern u32 func_021AD564(u32 a, u32 b, void *c);
extern void func_021AC154(u32 a);
extern void func_021C6B18(u32 a, u16 b, u32 c);
extern void func_021C12E4(void *a, u8 *b);
extern void func_021A35A0(u32 *p, int a);
extern void func_020061E4(u32 se);

void func_021C16AC(u8 *p)
{
    void *o;
    u32 k;
    void *r7;
    u32 t;
    Vec3 w;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = func_021A3074(((struct Obj00129 *)p)->f3C);
    switch (((struct Obj00129 *)p)->f2) {
    case 0:
        k = 1;
        func_0216DB4C(o, 1);
        func_0216D88C(o, (struct VecFx32 *)&v);
        a = v;
        b = a;
        c = a;
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&b), 0x10000);
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&c), 0x20000);
        func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&b), 0x4000);
        func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(&c));
        *(Vec3 *)(p + 0x24) = c;
        func_02163E58(o, &c, (int *)(p + 0x28));
        ((struct Obj00129 *)p)->f30 = (b.x - v.x) / 16;
        ((struct Obj00129 *)p)->f38 = (b.z - v.z) / 16;
        ((struct Obj00129 *)p)->f34 = -0x6000;
        ((struct Obj00129 *)p)->f1C = 0x1000;
        r7 = func_021A2F98(*(u32 *)&((struct Obj00129 *)p)->f3C);
        func_021ACBB8((u32)r7, 2);
        if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
            k = 3;
        t = func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40));
        n = 9;
        func_021ABE30(t, &n, 1);
        ((struct Obj00129 *)p)->f48 = func_021AD564(t, k, r7);
        func_021C6B18(((struct Obj00129 *)p)->f40, 0x10, 0x20000);
        func_020061E4(0x6e1);
        ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
    case 1:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        func_0216D89C(o, &w);
        ((struct Obj00129 *)p)->f1C = -((struct Obj00129 *)p)->f1C;
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            ((struct Obj00129 *)p)->f8 = 0;
            ((struct Obj00129 *)p)->f1C = 0;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            func_021AC154(((struct Obj00129 *)p)->f48);
            r7 = func_021A2F98(*(u32 *)&((struct Obj00129 *)p)->f3C);
            {
                u32 k2 = 2;
                if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
                    k2 = 2;
                ((struct Obj00129 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40)), k2, r7);
            }
        }
        func_021C12E4(o, p + 0x18);
        break;
    case 2:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.y += ((struct Obj00129 *)p)->f34;
        if (w.y <= ((struct Obj00129 *)p)->f28) {
            w.y = ((struct Obj00129 *)p)->f28;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            ((struct Obj00129 *)p)->f30 = (((struct Obj00129 *)p)->f24 - w.x) / 16;
            ((struct Obj00129 *)p)->f38 = (((struct Obj00129 *)p)->f2C - w.z) / 16;
            func_021C6B18(((struct Obj00129 *)p)->f40, 0x10, -0x20000);
            func_021AC154(((struct Obj00129 *)p)->f48);
            r7 = func_021A2F98(*(u32 *)&((struct Obj00129 *)p)->f3C);
            func_021ACBB8((u32)r7, 1);
            ((struct Obj00129 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40)), 0, r7);
        }
        func_0216D89C(o, &w);
        break;
    case 3:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        func_0216D89C(o, &w);
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            t = func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40));
            func_0216DB4C(o, 0);
            func_0216E014(o, (int *)(p + 0x24), ((struct Obj00129 *)p)->f4);
            func_021AC154(((struct Obj00129 *)p)->f48);
            func_021ABE64(t, 9);
            func_021A35A0((u32 *)(*(u32 *)&((struct Obj00129 *)p)->f3C), 1);
            ((struct Obj00129 *)p)->f48 = 0;
            ((struct Obj00129 *)p)->f6 = 1;
            func_020061E4(0x6e2);
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
        }
        break;
    }
}
