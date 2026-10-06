/*
 * function: func_021C58CC
 * address:  0x021C58CC
 * packet:   pkt_ov021_021C58CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200C468 0x0200C468 thumb
 *   func_0200C464 0x0200C464 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021C5880 0x021C5880 thumb ov021
 *   func_021C576C 0x021C576C thumb ov021
 *   func_0201FF30 0x0201FF30 thumb
 *   d_021DAA80    0x021DAA80 data  a4
 */
#include "../include/Obj00874.h"

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

extern const Tmpl d_021DAA80;

extern u16 func_0200C468(const u8 *a);
struct Obj;
struct Slot;
struct Src;
extern u8 func_0200C464(const u8 *a, u32 i);
extern void *func_0201F81C(int n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021C5880(u16 *a, u16 *b, u16 c);
extern void func_021C576C(void *a);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);

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
