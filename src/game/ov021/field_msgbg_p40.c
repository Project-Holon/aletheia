/*
 * file:     field_msgbg_p40.c
 * unit:     yes
 * function: func_0218F004, func_0218F050, func_0218F05C, func_0218F0A8, func_0218F0D4, func_0218F0E8, func_0218F0F8, func_0218F114, func_0218F134, func_0218F14C, func_0218F18C, func_0218F19C, func_0218F1AC, func_0218F1B4
 * address:  0x0218F004
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_0218ED9C  0x0218ED9C  thumb  ov021
 *   func_02082D44   0x02082D44  arm
 *   func_0204A380  0x0204A380  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00428.h"
#include "../../matched/include/Obj00612.h"
#include "../../matched/include/Obj01653.h"
#include "../../matched/include/Obj09464.h"
#include "../../matched/include/Obj19568.h"
#include "../../matched/include/Obj19569.h"
#include "../../matched/include/Obj12594.h"
#include "../../matched/include/Obj19570.h"
#include "../../matched/include/Obj09465.h"
#include "../../matched/include/Obj17915.h"
#include "../../matched/include/Obj17916.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

extern void func_02048B30(int, void *);
extern void func_02048AE8(int, void *);
extern void func_02048B44(int, void *);
extern void func_02048AFC(int, void *);
extern void func_0218ED9C(int a, void *b, void *c, void *d, void *e);
extern void func_02082D44(void *, void *, int);
extern void func_02082BCC(void *dst, int val, u32 size);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
void func_0218F004(u8 *a);
int func_0218F050(u32 a);
void func_0218F05C(unsigned char *a);
void func_0218F0A8(u8 *a);
void func_0218F0D4(u8 *a, int b);
u32 func_0218F0E8(u8 *a);
int func_0218F0F8(u8 *a);
void func_0218F114(char *arg0, char *arg1);
void func_0218F134(u8 *a);
void func_0218F14C(u8 *p, u32 a, u32 b);
void func_0218F18C(u8 *a, Vec3 *out);
void func_0218F19C(u8 *a, Vec3 *out);
void func_0218F1AC(u8 *p, u32 v);
u8 func_0218F1B4(u8 *p);


/*
 * Fetches three vectors from the owner, calls the solver, writes two back.
 *
 * Addresses are Black-image addresses.
 */
void func_0218F004(u8 *a)
{
    if (*(int *)&((struct Obj00428 *)a)->f1C != 0) {
        u8 d[12];
        u8 v[12];
        u8 c[12];
        u8 b[12];

        func_02048B30(((struct Obj00428 *)a)->fC, v);
        func_02048AE8(((struct Obj00428 *)a)->fC, d);
        func_0218ED9C(((struct Obj00428 *)a)->fEC, v, d, b, c);
        func_02048B44(((struct Obj00428 *)a)->fC, b);
        func_02048AFC(((struct Obj00428 *)a)->fC, c);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218F050(u32 a)
{
((struct Obj00612 *)((u8 *)(a)))->f2C = 0;
((struct Obj00612 *)((u8 *)(a)))->f28 = 0;
((struct Obj00612 *)((u8 *)(a)))->f10 = 0;
return a;
}


/*
 * Resets a table object's two entry arrays (12-byte entries) and cursors.
 *
 * Addresses are Black-image addresses.
 */
void func_0218F05C(unsigned char *a)
{
    int *p = *(int * *)&((struct Obj01653 *)a)->fEC;
    int i;

    if (p != 0) {
        for (i = 0; i < p[0]; i++) {
            int *e = (int *)((unsigned char *)p[8] + i * 12);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
            e = (int *)((unsigned char *)p[9] + i * 12);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }
        p[1] = 0;
        p[2] = p[3];
        p[4] = 0;
        p[10] = 1;
        p[11] = 0;
    }
}


void func_0218F0A8(u8 *a)
{
    u8 *p = *(u8 * *)&((struct Obj01653 *)a)->fEC;
    if (p != 0) {
        if (((struct Obj00612 *)p)->f10 == 0 && *(u32 *)&((struct Obj00612 *)p)->f8 == *(u32 *)&((struct Obj00612 *)p)->fC && *(u32 *)&((struct Obj00612 *)p)->f4 == 0)
            func_0218F050((u32)p);
        else
            ((struct Obj00612 *)p)->f2C = 1;
    }
}


void func_0218F0D4(u8 *a, int b)
{
    u8 *p = *(u8 * *)&((struct Obj19568 *)a)->fEC;
    if (p != 0) {
        ((struct Obj09464 *)p)->f2C = 0;
        ((struct Obj09464 *)p)->f28 = 0;
        ((struct Obj09464 *)p)->f10 = 0;
    }
}


u32 func_0218F0E8(u8 *a)
{
    u8 *p = *(u8 * *)&((struct Obj01653 *)a)->fEC;
    if (p == 0)
        return 0;
    return ((struct Obj19569 *)p)->f28;
}


int func_0218F0F8(u8 *a)
{
    if (*(u32 *)&((struct Obj01653 *)a)->f1C == 0)
        return 0;
    if (*(u32 *)&((struct Obj01653 *)a)->fEC != 0)
        return 1;
    return 0;
}


/*
 * Copies 0x18 * count bytes (count = *(int *)(arg1)) from arg0+0x88 to
 * arg1+4, then stores the low byte of count at arg0+0xe8.  Callee of
 * func_0218F14C.  EXACT* (unlabelled follower 0x0218F134).
 */
void func_0218F114(char *arg0, char *arg1)
{
    func_02082D44(arg1 + 4, arg0 + 0x88, 0x18 * ((struct Obj12594 *)arg1)->f0);
    ((struct Obj19570 *)arg0)->fE8 = ((struct Obj12594 *)arg1)->f0;
}


void func_0218F134(u8 *a)
{
    func_02082BCC(a + 0x88, 0, 0x60);
    *(a + 0xe8) = 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0218F14C(u8 *p, u32 a, u32 b)
{
    u32 r;
    if (((struct Obj09465 *)p)->fEA != a) {
        r = (u32)func_0204A380((void *)(((struct Obj09465 *)p)->f8), a, 0, (u16)((b & 0x7fff) | 0x8000));
        func_0218F114((char *)p, (char *)r);
        func_020307B0((void *)r);
        ((struct Obj09465 *)p)->fEA = a;
    }
}


void func_0218F18C(u8 *a, Vec3 *out)
{
    *out = *(Vec3 *)(a + 0x54);
}


void func_0218F19C(u8 *a, Vec3 *out)
{
    *out = *(Vec3 *)(a + 0x3c);
}


/*
 * Field setter at +0xe9 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_0218F1AC(u8 *p, u32 v)
{
    ((struct Obj17915 *)p)->fE9 = v;
}


/*
 * Loads the byte at byte +0xe9 of the object.
 */
u8 func_0218F1B4(u8 *p)
{
    return ((struct Obj17916 *)p)->fE9;
}
