/*
 * function: func_021BD838
 * address:  0x021BD838
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *
 * Picks 0x49 when the owner record class byte at +0x45 is zero and 0x48
 * otherwise, runs the setup on it, and stamps selector 0x7E; returns the
 * selector.  The if/else on a named local is the form the image has - the
 * ternary comes out with its arms swapped.
 */
#include "../include/Obj12117.h"
#include "../include/Obj18241.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021BAAB8(char *p, int a, int b);

int func_021BD838(char *p, int v)
{
    u8 b = ((struct Obj18241 *)(*(char * *)&((struct Obj12117 *)p)->f248))->f45;
    int a;

    if (b != 0) {
        a = 0x48;
    } else {
        a = 0x49;
    }

    func_021BAAB8(p, a, 0);
    ((struct Obj12117 *)p)->f1CC = 0x7E;
    return v;
}
