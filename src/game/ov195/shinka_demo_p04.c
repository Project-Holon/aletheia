/*
 * file:     shinka_demo_p04.c
 * unit:     yes
 * function: func_02204EF0, func_02204F00, func_02204F24, func_02204F40, func_02204F68, func_02204F78, func_02204F90, func_02204FA0, func_02204FC4, func_02204FD4, func_02204FF8
 * address:  0x02204EF0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020063B4 0x020063B4 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005D28 0x02005D28 thumb
 */
#include "../../matched/include/Obj10816.h"
#include "../../matched/include/Obj08346.h"
#include "../../matched/include/Obj14525.h"
#include "../../matched/include/Obj24949.h"
#include "../../matched/include/Obj14527.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern int func_02005E9C(void);
extern void func_02005DF8(u32 a);
extern void func_02005E30(u32 a);
extern void func_02005D90(int, int);
extern void func_02005D28(void);
int func_02204EF0(int a, int *p);
void func_02204F00(int unused, char *p);
void func_02204F24(int a, int *b);
void func_02204F40(int a, int *p);
int func_02204F68(int a, int *p);
void func_02204F78(int a, char *b);
int func_02204F90(int a, char *b);
void func_02204FA0(int a, int *p);
int func_02204FC4(int a, int *p);
void func_02204FD4(int a, int *p);
void func_02204FF8(int a, char *b);

/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 2.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204EF0(int a, int *p)
{
    return p[0xc] == 2;
}


void func_02204F00(int unused, char *p)
{
    if (((struct Obj10816 *)p)->f30 == 0)
    {
        ((struct Obj10816 *)p)->f34 = 0;
        func_020063B4((void *)0x3f3, (u32 *)(p + 0x34), 1);
        ((struct Obj10816 *)p)->f30 = 3;
    }
}


void func_02204F24(int a, int *b)
{
    if (((struct Obj08346 *)b)->f30 == 4) {
        func_02005DE4((void *)1);
        func_02005E64();
        ((struct Obj08346 *)b)->f30 = 5;
    }
}


/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state 5 or in state 8/9, run the cue trio and drop it into state 4.
 */
void func_02204F40(int a, int *p)
{
    int s = p[0xc];

    if (s == 5 || (unsigned)(s - 8) <= 1) {
        func_02005E9C();
        func_02005DE4(0);
        func_02005DF8(6);
        p[0xc] = 4;
    }
}

/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 4.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204F68(int a, int *p)
{
    return p[0xc] == 4;
}


void func_02204F78(int a, char *b)
{
    if (((struct Obj14525 *)b)->f30 == 4) {
        func_02005E30(0x3c);
        ((struct Obj14525 *)b)->f30 = 6;
    }
}


int func_02204F90(int a, char *b)
{
    if (((struct Obj24949 *)b)->f30 == 6)
        return 1;
    return 0;
}


/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 5, clear word +0x34, arm a 1-flag timer on it and move
 * to state 7.
 */
void func_02204FA0(int a, int *p)
{
    if (p[0xc] == 5) {
        p[0xd] = 0;
        func_020063B4((unsigned char *)0x519, (u32 *)(&p[0xd]), 1);
        p[0xc] = 7;
    }
}

/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 7 or 8.
 */
int func_02204FC4(int a, int *p)
{
    return p[0xc] == 7 || p[0xc] == 8;
}


/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 4, hand it to func_02204F24 and play cue 0x515, then
 * park it in state 9.  First argument is forwarded untouched.
 */
void func_02204FD4(int a, int *p)
{
    if (p[0xc] == 4) {
        func_02204F24(a, p);
        func_02005D90(0x515, 0xffff);
        p[0xc] = 9;
    }
}


void func_02204FF8(int a, char *b)
{
    if (((struct Obj14527 *)b)->f30 == 5) {
        func_02005E9C();
        func_02005D28();
        ((struct Obj14527 *)b)->f30 = 0;
    }
}
