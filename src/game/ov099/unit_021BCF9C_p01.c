/*
 * file:     unit_021BCF9C_p01.c
 * unit:     yes
 * function: func_021BCF9C, func_021BCFB4, func_021BD014, func_021BD038
 * address:  0x021BCF9C
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
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj06356.h"
#include "../../matched/include/Obj12114.h"
#include "../../matched/include/Obj05263.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern void func_021BA828(char *p);
extern void func_0201DD68(void);
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern void func_021BAAB8(char *p, int a, int b);
extern u32 func_020362DC(void);
extern void func_021BCC4C(void *a);
extern int func_021BDDF4(char *p);
int func_021BCF9C(char *p, int v);
int func_021BCFB4(char *p, int v);
int func_021BD014(char *p, int v);
int func_021BD038(char *p, int v);


/*
 * Runs the setup for selector 0x61 and stamps it 0x1CC bytes in.
 */
int func_021BCF9C(char *p, int v)
{
    func_021BA828(p);
    *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x61;
    return v;
}


int func_021BCFB4(char *p, int v)
{
    int r;

    func_0201DD68();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((struct Obj06356 *)p)->f1CC = 0x62;
        func_021BA8EC(p);
    } else {
        if ((unsigned)(((struct Obj06356 *)p)->f135C - 1) <= 1) {
            ((struct Obj06356 *)p)->f1353 = 0x4A;
            func_021BAAB8(p, 0x4A, 0);
        } else {
            ((struct Obj06356 *)p)->f1353 = 0x90;
        }
        ((struct Obj06356 *)p)->f1CC = 0x8A;
    }
    return v;
}


/*
 * Asks the arm9 predicate at 0x020362DC about the block; on a non-zero answer
 * stamps 0x6E in the byte at +0x1353 and selector 0x8A.  Returns the second
 * argument.  The predicate takes only the block.
 */
int func_021BD014(char *p, int v)
{
    if (func_020362DC() != 0) {
        ((struct Obj12114 *)p)->f1353 = 0x6E;
        ((struct Obj12114 *)p)->f1CC = 0x8A;
    }
    return v;
}


int func_021BD038(char *p, int v)
{
    func_021BCC4C(p);
    if (func_021BDDF4(p) == 0) {
        switch (((struct Obj05263 *)p)->f135C) {
        case 3:
            ((struct Obj05263 *)p)->f1CC = 0x9D;
            func_021BAAB8(p, 0x68, 0);
            return v;
        case 2:
        case 4:
            ((struct Obj05263 *)p)->f1CC = 0x63;
            func_021BAAB8(p, 0x68, 0);
            return v;
        default:
            ((struct Obj05263 *)p)->f1CC = 0x96;
            func_021BAAB8(p, 0x68, 0);
            return v;
        }
    }
    ((struct Obj05263 *)p)->f1353 = 0x64;
    ((struct Obj05263 *)p)->f1CC = 0x8A;
    return v;
}
