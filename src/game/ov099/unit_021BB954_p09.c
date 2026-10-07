/*
 * file:     unit_021BB954_p09.c
 * unit:     yes
 * function: func_021BC43C, func_021BC468
 * address:  0x021BC43C
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
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_021BA858  0x021BA858  thumb  ov099
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj13687.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef enum { K274 = 0x274 } Off;

extern void func_021B9B64(char *p);
extern int func_021BA928(void *p);
extern void func_021BA828(char *p);
extern u32 func_021BA858(char *p);
int func_021BC43C(char *p, int v);
int func_021BC468(char *p, int v);


int func_021BC43C(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0xA5;
    }

    return v;
}


/*
 * Levers: the 0x274 offset is an enum-typed local (keeps r4 = 0x274 live and
 * derives 0x1CC as `o - 0xa8`); the two stores are written out in each arm.
 */
int func_021BC468(char *p, int v)
{
    int r;
    Off o;

    r = func_021BA858(p);
    o = K274;
    func_021B9B64(p + o);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((struct Obj13687 *)p)->f1353 = 0x4c;
        *(u32 *)(p + (o - 0xa8)) = 0x8a;
    } else {
        ((struct Obj13687 *)p)->f1353 = 0x9b;
        *(u32 *)(p + (o - 0xa8)) = 0x8a;
    }
    return v;
}
