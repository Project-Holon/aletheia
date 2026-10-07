/*
 * file:     oekaki_p02.c
 * unit:     yes
 * function: func_02184454, func_02184474, func_021844B4
 * address:  0x02184454
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_021844D8  0x021844D8  thumb  ov023
 */
#include "../../matched/include/Obj20339.h"
#include "../../matched/include/Obj09766.h"
#include "../../matched/include/Obj20341.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern u16 func_02039338(void);
extern void func_02185AB0(char *p, int a, int b);
extern u32 func_021844D8(char *p, int x, int y);
void func_02184454(int a0, int a1, int a2, char *a3);
void func_02184474(int a0, int a1, u8 *a2, char *p, int a4);
void func_021844B4(int a, int b, int c, char *p);


void func_02184454(int a0, int a1, int a2, char *a3)
{
    if (func_02039338())
        return;
    ((struct Obj20339 *)a3)->f9280 |= 1 << a0;
}


void func_02184474(int a0, int a1, u8 *a2, char *p, int a4)
{
    if (((struct Obj09766 *)p)->f928A == 0) {
        func_02185AB0(p, 1, *a2);
        if (func_02039338() == 0 && ((struct Obj09766 *)p)->f194 == 1) {
            ((struct Obj09766 *)p)->f428C = 0;
            func_021844D8(p, 0, a4);
        }
    }
}

void func_021844B4(int a, int b, int c, char *p)
{
    ((struct Obj20341 *)p)->f928A = 1;
    if (func_02039338() != 0)
        func_02185AB0(p, 0x12, 0);
}
