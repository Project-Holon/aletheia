/*
 * file:     unit_021ECE60_p06.c
 * unit:     yes
 * function: func_021ED660, func_021ED6BC
 * address:  0x021ED660
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
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED724  0x021ED724  thumb  ov093
 */
#include "../../matched/include/Obj10120.h"
#include "../../matched/include/Obj10121.h"
#include "../../matched/include/Obj12174.h"

struct S02030FB4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern void *func_021D5844(void *m);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021ED724(u32 x, struct S *t);
void func_021ED660(char *p, u32 k, u32 a, u32 b);
void func_021ED6BC(char *p, u32 k, u32 a);
int func_021ED714(char *p);


void func_021ED660(char *p, u32 k, u32 a, u32 b)
{
    struct S *t;

    t = (struct S *)func_02031290(func_020311B8(((struct Obj10120 *)p)->f2C, (void *)func_021ED724, 0x18, 1));
    t->v = func_021D5844(func_021B98AC(*(char *const * *)&((struct Obj10120 *)p)->f138,
                                              func_021B8ED8(*(u8 * *)&((struct Obj10120 *)p)->f134, a)));
    t->w = p;
    t->k = k;
    t->cnt = (u8 *)p + 0x40;
    t->f = b;
    t->c = 0;
    (*t->cnt)++;
}


void func_021ED6BC(char *p, u32 k, u32 a)
{
    struct S *t;

    t = (struct S *)func_02031290(func_020311B8(((struct Obj10121 *)p)->f2C, (void *)func_021ED724, 0x18, 1));
    t->v = func_021D5844(func_021B98AC(*(char *const * *)&((struct Obj10121 *)p)->f138,
                                              func_021B8ED8(*(u8 * *)&((struct Obj10121 *)p)->f134, k)));
    t->w = p;
    t->k = k;
    t->cnt = (u8 *)p + 0x40;
    t->f = a;
    t->c = 0;
    (*t->cnt)++;
}


int func_021ED714(char *p)
{
    if (((struct Obj12174 *)p)->f40 == 0)
        return 1;
    return 0;
}
