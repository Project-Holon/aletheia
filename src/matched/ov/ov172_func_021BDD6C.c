/*
 * function: func_021BDD6C
 * address: 0x021BDD6C
 * packet: pkt_ov172_021BDD6C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B7B30 0x021B7B30 thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_021BDEF0 0x021BDEF0 thumb ov172
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021BE210 0x021BE210 thumb ov172
 */
#include "../include/Obj02215.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
extern int func_021BE05C(void *p);
struct Cfg;
struct Descriptor;
extern u32 func_021B8BA4(int unused, char *base, int i);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern u32 func_021B7B30(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern void func_021BDEF0(u8 *p, char *a, u32 b);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021BE210(u8 *p, u32 v);
void func_021BDD6C(u8 *p)
{
    u8 i;
    u32 found;
    u32 r;
    u32 m;
    u32 b;
    u32 w;
    found = 0;
    if (((struct Obj02215 *)p)->f8 == 3) {
        return;
    }
    r = func_021BE05C(p);
    for (i = found; i < 4; i++) {
        if (func_021B8BA4((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B8B8C((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B7B30((int)p, *(char * *)&((struct Obj02215 *)p)->f1E0, i) != 0) continue;
        m = 1 << i;
        if (m & p[0x1b4]) continue;
        {
            char *k = func_021B8B94((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i);
            if (r == 1) {
                if (i == 0) b = 2; else b = 3;
            } else {
                b = i;
            }
            func_021BDEF0(p, k, *(u32 *)(p + b * 4 + 0x1b8));
        }
        p[0x1b4] += (u8)m;
        p[0x1b5] += (u8)(1 << b);
    }
    for (i = 0; i < 4; i++) {
        m = 1 << i;
        if (!(p[0x1b5] & m)) continue;
        if (func_0201C6C4(((struct Obj02215 *)p)->f1D0, func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))) != 0) continue;
        w = *(u32 *)(p + i * 4 + 0x1b8);
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        p[0x1b5] -= (u8)m;
        found = 1;
    }
    if (found == 1) {
        u32 v = func_021B8B68((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4);
        if (v != 0xff) {
            func_021BE210(p, v);
        }
    }
}
