/*
 * file:     unit_021B6100_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6138, func_021B616C, func_021B619C, func_021B61B8, func_021B61C8, func_021B61F4, func_021B6204
 * address:  0x021B6100
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02036270 0x02036270 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021B9850 0x021B9850 thumb ov070
 *   func_021B9AAC 0x021B9AAC thumb ov070
 *   func_021BA218 0x021BA218 thumb ov070
 *   func_021B81F4 0x021B81F4 thumb ov070
 *   func_020081DC 0x020081DC thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02007F7C 0x02007F7C thumb
 *   func_02007FA0 0x02007FA0 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF6C 0x0201EF6C thumb
 */
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj20659.h"
#include "../../matched/include/Obj20660.h"
#include "../../matched/include/Obj20661.h"
#include "../../matched/include/Obj20662.h"

struct Item;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_02036270(int a0, int a1);
extern u8 func_020355C4(void);
extern void func_021B9850(char *p);
extern void func_021B9AAC(char *p);
extern void func_021BA218(char *p);
extern void func_021B81F4(u8 *p);
extern struct Item *func_020081DC(u8 *base, u32 id, u32 index);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern unsigned int func_02007F7C(const struct Item *arr, unsigned int n);
extern u32 func_02007FA0(u8 *base, u32 id);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void func_021B6100(char *p, int k);
void func_021B6120(char *p);
void func_021B6138(char *p);
void *func_021B616C(u8 *p, int i);
int func_021B619C(int a, int b, unsigned int id);
int func_021B61B8(u8 *p);
int func_021B61C8(u8 *p);
void func_021B61F4(u8 *p, int a, unsigned int b);
void func_021B6204(u8 *p, int a, unsigned int b, int c, int d);

void func_021B6100(char *p, int k)
{
    *(int *)&((struct Obj00002 *)p)->f4F8 = k;
    func_02036270(((struct Obj00002 *)p)->f86C, ((struct Obj00002 *)p)->f870);
}

void func_021B6120(char *p)
{
    ((struct Obj20659 *)p)->f818 = 0xFFFF;
    func_021B6138(p);
}

void func_021B6138(char *p)
{
    if (func_020355C4() == 0)
        func_021B9850(p);
    else
        func_021B9AAC(p);
    func_021BA218(p);
    func_021B81F4((u8 *)p);
    ((struct Obj20660 *)p)->f83E = 1;
}

void *func_021B616C(u8 *p, int i)
{
    if (*(int *)&((struct Obj00002 *)p)->f81C) return (void *)((unsigned int)p + 0x20U + (unsigned int)i * 4U);
    return func_020081DC(((struct Obj00002 *)p)->f18, (u16)(((struct Obj00002 *)p)->f80C), (u16)i);
}

/*
 * extent: two bytes of zero alignment follow the 26-byte function.
 * lever: enum quotient preserves its r1 web and the copy to return r0.
 * The signed quotient is multiplied with unsigned modular arithmetic.
 */
int func_021B619C(int a, int b, unsigned int id)
{
    typedef enum { HALF_ZERO } Half;
    Half half;
    half = (Half)((int)func_02020FE4((void *)((u16)a), 0, id) / 2);
    return (int)((unsigned int)half * (unsigned int)b);
}

int func_021B61B8(u8 *p)
{
    return (int)(*(unsigned int *)&((struct Obj00002 *)p)->f810 + *(unsigned int *)&((struct Obj00002 *)p)->f814 + 1U);
}

int func_021B61C8(u8 *p)
{
    if (*(int *)&((struct Obj00002 *)p)->f81C) return func_02007F7C((const struct Item *)(p + 0x20), 0x136);
    return func_02007FA0(((struct Obj00002 *)p)->f18, ((struct Obj00002 *)p)->f80C);
}

void func_021B61F4(u8 *p, int a, unsigned int b)
{
    func_0201EF40(((struct Obj20661 *)p)->f520, a, b);
}

/*
 * Extent ends in two zero alignment bytes.
 */
void func_021B6204(u8 *p, int a, unsigned int b, int c, int d)
{
    func_0201EF6C(((struct Obj20662 *)p)->f520, a, b, c, d);
}
