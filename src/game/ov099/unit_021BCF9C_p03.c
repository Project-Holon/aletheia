/*
 * file:     unit_021BCF9C_p03.c
 * unit:     yes
 * function: func_021BD15C, func_021BD1A4
 * address:  0x021BD15C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BBE7C  0x021BBE7C  thumb  ov099
 *   func_02012934  0x02012934  thumb
 *   func_021BBD0C  0x021BBD0C  thumb  ov099
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_020202FC 0x020202FC thumb
 *   func_021BBA4C 0x021BBA4C thumb ov099
 *   func_021BBDD0 0x021BBDD0 thumb ov099
 *   func_0203D378 0x0203D378 arm
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../../matched/include/Obj07946.h"

struct BigObj;
struct Descriptor;
struct PrintSys;
struct Obj;
struct Rec534;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BD15C;

typedef unsigned int u32_021BD1A4;

typedef signed int     s32;

extern int func_021BA928(char *p, int v);
extern void func_021BBE7C(char *p);
extern void *func_02012934(const struct BigObj *p);
extern void func_021BBD0C(char *p, int a, int b);
extern void *func_02045770(struct Descriptor *p);
extern u32_021BD1A4 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern s32 func_020200CC(struct Obj *o);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_021BBA4C(char *p, void *x);
extern void func_021BBDD0(void *pv, int flag);
extern u32_021BD1A4 func_0203D378(void);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BD1A4 *mask);
extern int func_021BCBBC(int a, int b, int *out);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC0C4(char *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021BA8EC(char *p);
int func_021BD15C(char *p, int v);
int func_021BD1A4(char *p, int v);


int func_021BD15C(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }
    ((struct Obj07946 *)p)->f1354 = 2;
    func_021BBE7C(p);
    func_021BBD0C(p, (int)func_02012934(((struct Obj07946 *)p)->fC4), ((struct Obj07946 *)p)->fCC);
    ((struct Obj07946 *)p)->f1CC = 0x66;
    return v;
}


int func_021BD1A4(char *p, int v)
{
    int five;
    void *q;
    int r;
    int out;
    u16 x[2];

    five = 0;
    q = *(void **)(p + 0x1b8);
    if (*(u8 *)(p + 0x1b0) != 0) {
        if (func_0201C6C4(q, func_02045770(*(struct Descriptor **)(p + 0x1ac))) == 0) {
            func_02045334(*(struct Descriptor **)(p + 0x1ac));
            *(u8 *)(p + 0x1b0) = 0;
        }
    }
    r = func_020200CC(*(void **)(p + 0xbc));
    func_020202FC(*(void **)(p + 0xbc), &x[1], &x[0]);
    if (x[0] != *(u8 *)(p + 0x1354)) {
        *(u8 *)(p + 0x1354) = x[0];
        if (x[0] == 0) {
            func_021BBA4C(p, func_02012934(*(void **)(p + 0xc4)));
            func_021BBDD0(p, 1);
        } else {
            func_021BBA4C(p, *(void **)(p + 0xcc));
            func_021BBDD0(p, 0);
        }
    }
    if (func_0203D378() == 0) {
        five = 1;
    }
    switch (r) {
    case -1:
        return v;
    case -2:
        return v;
    case 0:
        if (func_021BCB70(*(void **)(p + 0x1348), *(void **)(p + 0xc4), (u32_021BD1A4 *)(&out)) != 0) {
            func_021BAAB8(p, 0x68, 0);
            *(u32_021BD1A4 *)(p + 0x1cc) = 0x6b;
            func_021BC0C4(p);
            return v;
        }
        func_0201AC2C(func_02012934(*(void **)(p + 0xc4)), *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32_021BD1A4 *)(p + 0x1cc) = 0x67;
        break;
    case 1:
        if (func_021BCBBC((int)(*(void **)(p + 0x1348)), (int)(*(void **)(p + 0xcc)), &out) != 0) {
            func_021BAAB8(p, 0x68, 0);
            *(u32_021BD1A4 *)(p + 0x1cc) = 0x6c;
            func_021BC0C4(p);
            return v;
        }
        func_0201AC2C(*(void **)(p + 0xcc), *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32_021BD1A4 *)(p + 0x1cc) = 0x67;
        break;
    }
    func_021BC0C4(p);
    func_021BA8EC(p);
    return v;
}
