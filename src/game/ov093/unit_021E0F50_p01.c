/*
 * file:     unit_021E0F50_p01.c
 * unit:     yes
 * function: func_021E0F74, func_021E0FB8
 * address:  0x021E0F74
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj07826.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
void func_021E0F74(int unused, void *q, int id);
void func_021E0FB8(int unused, void *q, int id);


void func_021E0F74(int unused, void *q, int id)
{
    void *m;
    int k;
    u8 t;

    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        m = func_021C7CF4(q, t);
        k = 0x11;
        if (func_021D59B4(m, 0x11) == 0x36 || func_021D59B4(m, k) == 0xf)
            func_021D76BC(0x40, 1);
    }
}


void func_021E0FB8(int unused, void *q, int id)
{
    u8 *r;
    int t;

    if (id == func_021D775C(3)) {
        t = func_021D775C(6);
        r = (u8 *)func_021C88A4(q, 0x1f, id);
        r[6] = t;
        ((struct Obj07826 *)r)->f4 = 0xf;
        func_021C8838(r + 0xc, 2, 0x195);
        func_021C8860((struct S *)(r + 0xc), r[6]);
        func_021C8860((struct S *)(r + 0xc), ((struct Obj07826 *)r)->f4);
        func_021C88C8(q, r);
    }
}
