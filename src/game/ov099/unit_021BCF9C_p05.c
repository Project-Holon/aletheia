/*
 * file:     unit_021BCF9C_p05.c
 * unit:     yes
 * function: func_021BD3A8, func_021BD41C
 * address:  0x021BD3A8
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
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0200AE54  0x0200AE54  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 */
#include "../../matched/include/Obj07947.h"
#include "../../matched/include/Obj00008.h"

struct Entry;
struct Link;
struct Reg;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *h, unsigned int a, unsigned int b);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);
extern int func_021BA928(void *p, int v);
int func_021BD3A8(char *p, int v);
int func_021BD41C(char *p, int v);


int func_021BD3A8(char *p, int v)
{
    int a;
    int b;
    int id;

    if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 0xA) != 0) {
        a = func_0200AE54((struct Reg *)(((struct Obj07947 *)p)->f1348), 2);
        b = func_0200AE54((struct Reg *)(((struct Obj07947 *)p)->f1348), 3);
        if (a == 3 && b == 3) {
            id = 0x92;
        } else if (a == 4 && b == 4) {
            id = 0x93;
        } else if (a == 6 && b == 6) {
            id = 0x94;
        } else {
            id = 0x91;
        }
        func_021BAAB8(p, id, 0);
        func_021BC090(p);
        ((struct Obj07947 *)p)->f1E0 = 0x78;
        ((struct Obj07947 *)p)->f1CC = 0x69;
    }
    return v;
}


int func_021BD41C(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        int x = ((struct Obj00008 *)p)->f1E0;

        ((struct Obj00008 *)p)->f1E0 = x - 1;

        if (x < 0) {
            *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x6A;
        }
    }

    return v;
}
