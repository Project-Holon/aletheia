/*
 * file:     fldeff_iwakudaki_p05.c
 * unit:     yes
 * function: func_021AE498, func_021AE4B4, func_021AE4E0, func_021AE524
 * address:  0x021AE498
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
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 */
#include "../../matched/include/Obj09181.h"
#include "../../matched/include/Obj05863.h"
#include "../../matched/include/Obj07220.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

extern int func_0216DA5C(void *a0);
extern char *func_0216DB04(void *a0);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216DAF8(void *a0);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(void *a0);
extern u16 func_0216D5A0(void *p);
extern int func_0216D3CC(int a0);
extern u32 func_0216D410(u32, u32);
extern int func_02197E7C(int a, int b);
int func_021AE498(u32 a, u32 b, u32 c, u32 d);
int func_021AE4B4(u32 a, u32 b, u32 c, u32 d);
int func_021AE4E0(Task *p);
int func_021AE524(u32 a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE498(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DA5C((void *)(((struct Obj09181 *)((u8 *)(a)))->f8)) == 1) {
    func_0216DB04((void *)(((struct Obj09181 *)((u8 *)(a)))->f8));
}
((struct Obj09181 *)((u8 *)(a)))->f0 = 1;
return 1;
}


int func_021AE4B4(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DA5C((void *)(((struct Obj05863 *)((u8 *)(a)))->f8)) == 1) {
    return 0;
}
func_0216D5E0(((struct Obj05863 *)((u8 *)(a)))->f8, ((((struct Obj05863 *)((u8 *)(a)))->f10 << 16) >> 16));
func_0216DAF8((void *)(((struct Obj05863 *)((u8 *)(a)))->f8));
((struct Obj05863 *)((u8 *)(a)))->f0 = 2;
return 1;
}


int func_021AE4E0(Task *p)
{
    if (func_0216D454(func_021A3074(p->f34)) == 0)
        return 0;
    p->state = 3;
    switch (func_0216D5A0(p->f08)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        p->state = 7;
        break;
    }
    return 1;
}


int func_021AE524(u32 a)
{
if (func_0216D3CC(((struct Obj07220 *)((u8 *)(a)))->f8) == 1) {
    func_0216D410(((struct Obj07220 *)((u8 *)(a)))->f8, func_02197E7C(((((struct Obj07220 *)((u8 *)(a)))->f10 << 16) >> 16), 0));
    ((struct Obj07220 *)((u8 *)(a)))->f0 = 4;
}
return 0;
}
