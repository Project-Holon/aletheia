/*
 * file:     unit_021BA594_p02.c
 * unit:     yes
 * function: func_021BA60C, func_021BA648
 * address:  0x021BA60C
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
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F34 0x02049F34 arm
 *   d_021C2878 0x021C2878 data ov099 a2
 *   sub_020307B0  0x020307B0  arm
 *   sub_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj06351.h"
#include "../../matched/include/Obj22018.h"
#include "../../matched/include/Obj18161.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021BA60C;

typedef unsigned long  u32_021BA648;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern void func_02082BCC(void *, u32_021BA60C, u32_021BA60C);
extern void *func_02049F34(u32_021BA60C a0, u32_021BA60C a1, u32_021BA60C a2, u32_021BA60C a3);
extern u32_021BA648 sub_020307B0(void *p);
extern void sub_02082BCC(void *p, int c, u32_021BA648 n);
void func_021BA60C(char *a, char *p, u32_021BA60C unused, u32_021BA60C arc);
void func_021BA648(int unused, void *p);
extern const u16 d_021C2878[];

void func_021BA60C(char *a, char *p, u32_021BA60C unused, u32_021BA60C arc)
{
    func_02082BCC(p, 0, 20);
    ((struct Obj06351 *)p)->f0 = func_02049F34(arc, 9, (u32_021BA60C)(p + 4), (u16)(((struct Obj22018 *)a)->f4));
    p[9] = 0;
    p[8] = 15;
    ((struct Obj06351 *)p)->fA = d_021C2878[(u8)p[9]];
}


void func_021BA648(int unused, void *p)
{
    sub_020307B0(((struct Obj18161 *)p)->f0);
    sub_02082BCC(p, 0, 0x14);
}
