/*
 * file:     research_top_p14.c
 * unit:     yes
 * function: func_021BCF20, func_021BCF4C, func_021BCF68, func_021BCF98
 * address:  0x021BCF20
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   d_021C305C 0x021C305C data a1
 *   d_021C3060 0x021C3060 data a2
 *   func_0204B1CC  0x0204B1CC  arm
 */
#include "../../matched/include/Obj08434.h"

struct Bank;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct S { char pad0[8]; u16 h8; char pad[0x10a]; int arr[3]; };

extern void func_0204A8D4(u32 i);
extern u32 func_0204ADA4();
extern void func_0204AFD8(u32 i);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0204B1CC(struct Bank *bank);
u32 func_021BCF20(u32 a0);
void func_021BCF4C(void *p);
void func_021BCF68(struct S *p);
void func_021BCF98(int *p);
extern const u8 d_021C305C[];
extern const u16 d_021C3060[];

u32 func_021BCF20(u32 a0)
{
    func_0204A8D4(((struct Obj08434 *)((u8*)a0))->fF8);
    func_0204ADA4(((struct Obj08434 *)((u8*)a0))->fFC);
    func_0204AFD8(((struct Obj08434 *)(((u8*)a0)))->f100);
    return func_0204ADA4(((struct Obj08434 *)(((u8*)a0)))->f104);
}


void func_021BCF4C(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x114) = 0;
}


void func_021BCF68(struct S *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->arr[i] = (int)func_0204B100(d_021C3060[i], d_021C305C[i], p->h8);
    }
}


void func_021BCF98(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B1CC((struct Bank *)p[i + 0x45]);
}
