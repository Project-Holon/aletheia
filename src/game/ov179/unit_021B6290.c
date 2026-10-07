/*
 * file:     unit_021B6290.c
 * unit:     yes
 * function: func_021B6290, func_021B62B8, func_021B62E0, func_021B630C, func_021B6338, func_021B6380
 * address:  0x021B6290
 * region:   ov179
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_02049F78  0x02049F78  arm
 *   func_02082A90  0x02082A90  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020362DC 0x020362DC arm
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E30 0x02005E30 thumb
 *   d_021B6A04 0x021B6A04 data a4
 */
#include "../../matched/include/Obj24466.h"
#include "../../matched/include/Obj24467.h"
#include "../../matched/include/Obj24468.h"
#include "../../matched/include/Obj24469.h"
#include "../../matched/include/Obj14384.h"
#include "../../matched/include/Obj14385.h"
#include "../../matched/include/Obj24470.h"
#include "../../matched/include/Obj08292.h"

typedef unsigned int u32;

extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082A90(int, int, int);
extern u32 func_020307B0(void *p);
extern u32 func_020362DC(void);
extern int func_02005F38(void);
extern void func_02005E30(unsigned v);
void func_021B6290(char *p, u32 a, u32 b, u32 c);
void func_021B62B8(char *p, u32 a, u32 b, u32 c);
void func_021B62E0(char *p, u32 a, u32 b, u32 c);
void func_021B630C(char *p, u32 a, u32 b, u32 c);
void func_021B6338(void *obj, int a, int b);
int func_021B6380(char *p);


void func_021B6290(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 1, 1, 0, a, b, 0x7f);
    ((struct Obj24466 *)p)->f6054 = c;
}


void func_021B62B8(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 0, 0, 0, a, b, 0x7f);
    ((struct Obj24467 *)p)->f6054 = c;
}


void func_021B62E0(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 1, 1, 0x7fff, a, b, 0x7f);
    ((struct Obj24468 *)p)->f6054 = c;
}


void func_021B630C(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 0, 0, 0x7fff, a, b, 0x7f);
    ((struct Obj24469 *)p)->f6054 = c;
}


void func_021B6338(void *obj, int a, int b)
{
    void *ptr;
    int t;
    char *p;

    t = (int)func_02049F78((void *)(((struct Obj24470 *)obj)->f4), b, (u32)(&ptr), 0x807f);
    p = (char *)obj + 8 + a * 0x2004;
    ((struct Obj14385 *)p)->f2000 = ((struct Obj14384 *)ptr)->f8;
    func_02082A90(((struct Obj14384 *)ptr)->fC, (int)p, ((struct Obj14385 *)p)->f2000);
    func_020307B0((void *)t);
}

extern int (*const d_021B6A04[])(char *);

int func_021B6380(char *p)
{
    if (((unsigned char *)*(char * *)&((struct Obj08292 *)p)->f0)[2] != 0 && (func_020362DC() & 0xB) != 0) {
        if (func_02005F38() == 1)
            func_02005E30(8);
        ((struct Obj08292 *)p)->f6050 = 1;
        (*(char **)p)[3] = 1;
    }
    ((struct Obj08292 *)p)->f6050 = d_021B6A04[*(int *)(p + 0x6050)](p);
    if (((struct Obj08292 *)p)->f6050 != 6)
        return 1;
    return 0;
}
