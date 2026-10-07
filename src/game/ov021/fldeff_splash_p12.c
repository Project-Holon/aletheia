/*
 * file:     fldeff_splash_p12.c
 * unit:     yes
 * function: func_021C577C, func_021C5880, func_021C58CC
 * address:  0x021C577C
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
 *   func_02020350 0x02020350 thumb
 *   func_02020314 0x02020314 thumb
 *   func_02020324 0x02020324 thumb
 *   func_020202FC 0x020202FC thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C59F8 0x021C59F8 thumb ov021
 *   func_0200C468 0x0200C468 thumb
 *   func_0200C464 0x0200C464 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021C576C 0x021C576C thumb ov021
 *   func_0201FF30 0x0201FF30 thumb
 *   d_021DAA80    0x021DAA80 data  a4
 */
#include "../../matched/include/Obj04282.h"
#include "../../matched/include/Obj00874.h"

struct Obj;
struct Slot;
struct Src;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14[8];
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

extern u32 func_02020350(struct Obj *obj, u32 what);
extern u16 func_02020314(struct Obj *obj);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void func_021C59F8(char *w, int b);
extern u16 func_0200C468(const u8 *a);
extern u8 func_0200C464(const u8 *a, u32 i);
extern void *func_0201F81C(int n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021C576C(void *a);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
void func_021C577C(void *list);
void func_021C5880(u16 *a, u16 *b, u16 c);
void func_021C58CC(char *p, u16 a, u16 b, u32 heap);
extern const Tmpl d_021DAA80;


void func_021C577C(void *list)
{
    u16 v[2];
    char *w;
    u16 x;
    u32 y;
    u32 s;
    u32 t;
    u32 d;
    u16 a;

    w = (char *)func_02020350(list, 0x13);
    x = func_02020314(list) >> 3;
    y = func_02020350(list, 9) >> 3;
    if (((struct Obj04282 *)w)->f24 == 0) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020413B0(1, 1, x + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    } else if (((struct Obj04282 *)w)->f24 == 1) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020202FC(list, &v[1], &v[0]);
        s = func_02020350(list, 8);
        t = func_02020350(list, 9);
        d = ((struct Obj04282 *)w)->f1E + ((struct Obj04282 *)w)->f1C - v[1];
        s = s + d * t;
        func_020413B0(1, 1, (s >> 3) + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    }
    if (((struct Obj04282 *)w)->f40 == 1) {
        a = func_02020350(((struct Obj04282 *)w)->f4, 3);
        a = func_02020324(((struct Obj04282 *)w)->f4, a) >> 3;
        func_021C59F8(w, (a + 12) << 3);
    } else {
        func_021C59F8(w, (x + 12) << 3);
    }
}


void func_021C5880(u16 *a, u16 *b, u16 c)
{
    int s = *a + *b;

    if (c <= 5) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= 3) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= (int)c - 2 && s > 3) {
        *a = s - 3;
        *b = 3;
        return;
    }
    if (s == (int)c - 1) {
        *a = s - 4;
        *b = 4;
    }
}


void func_021C58CC(char *p, u16 a, u16 b, u32 heap)
{
    Tmpl t;
    u32 n;
    u32 i;

    n = func_0200C468(((struct Obj00874 *)p)->f20);
    ((struct Obj00874 *)p)->f0 = func_0201F81C(n, heap);
    for (i = 0; i < n; i++) {
        u8 v = func_0200C464(((struct Obj00874 *)p)->f20, (u8)i);
        func_0201F878(((struct Obj00874 *)p)->f0, ((struct Obj00874 *)p)->f38, (int)v, (int)v, heap);
    }
    while (b + a >= n) {
        if (b != 0) {
            b--;
        } else if (a != 0) {
            a--;
        }
    }
    func_021C5880(&a, &b, n);
    t = d_021DAA80;
    t.arr = ((struct Obj00874 *)p)->f0;
    t.count = n;
    t.cb04 = (void *)func_021C576C;
    t.cb08 = 0;
    t.w0c = *(u32 *)&((struct Obj00874 *)p)->f8;
    t.w1c = p;
    t.w24 = ((struct Obj00874 *)p)->f38;
    t.w28 = p + 0x10;
    t.w2c = ((struct Obj00874 *)p)->fC;
    t.w30 = ((struct Obj00874 *)p)->f3C;
    ((struct Obj00874 *)p)->f4 = func_0201FF30((struct Src *)(&t), a, b, heap);
}
