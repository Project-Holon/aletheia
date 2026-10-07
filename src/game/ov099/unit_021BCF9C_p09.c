/*
 * file:     unit_021BCF9C_p09.c
 * unit:     yes
 * function: func_021BD744, func_021BD778
 * address:  0x021BD744
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
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../../matched/include/Obj09198.h"
#include "../../matched/include/Obj22040.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BD744;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BD778;

extern void func_021BAAB8(char *p, int a, int b);
extern void func_021C18C8(char *, int, int);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
int func_021BD744(char *p, int v);
int func_021BD778(char *p, int v);


int func_021BD744(char *p, int v)
{
    u32_021BD744 x = ((struct Obj09198 *)p)->f135C;

    if (x - 2 <= 1) {
        func_021BAAB8(p, 0x7D, 0);
    } else {
        func_021BAAB8(p, 0x7C, 0);
    }

    ((struct Obj09198 *)p)->f135C = 0;
    ((struct Obj09198 *)p)->f1CC = 0x8E;
    return v;
}

int func_021BD778(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    func_0203D7B0(0);
    func_0203D7BC(0);
    ((struct Obj22040 *)p)->f1CC = 0x99;
    return v;
}
