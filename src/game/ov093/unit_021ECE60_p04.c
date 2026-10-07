/*
 * file:     unit_021ECE60_p04.c
 * unit:     yes
 * function: func_021ED57C, func_021ED590
 * address:  0x021ED57C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED5E8  0x021ED5E8  thumb  ov093
 */
#include "../../matched/include/Obj12173.h"
#include "../../matched/include/Obj13568.h"

struct S02030FB4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S { char *p; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

extern int func_021F7EB4(void);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021ED5E8(u32 x, struct S *t);
int func_021ED57C(int a, int b);
void func_021ED590(char *p, u8 k, u32 a);
int func_021ED5D8(char *p);

int func_021ED57C(int a, int b)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}


void func_021ED590(char *p, u8 k, u32 a)
{
    struct S *t;

    if (k != 6) {
        t = (struct S *)func_02031290(func_020311B8(((struct Obj13568 *)p)->f2C, (void *)func_021ED5E8, 0x18, 1));
        t->p = p;
        t->k = k;
        t->a = a;
        t->v = func_021B8E70(*(u8 * *)&((struct Obj13568 *)p)->f134, k);
        t->cnt = (u8 *)p + 0x40;
        t->c = 0;
        (*t->cnt)++;
    }
}


int func_021ED5D8(char *p)
{
    if (((struct Obj12173 *)p)->f40 == 0)
        return 1;
    return 0;
}
