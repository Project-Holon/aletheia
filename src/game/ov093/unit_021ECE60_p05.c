/*
 * file:     unit_021ECE60_p05.c
 * unit:     yes
 * function: func_021ED5D8, func_021ED5E8
 * address:  0x021ED5D8
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
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021F7D80  0x021F7D80  thumb  ov094
 *   func_021F7E38  0x021F7E38  thumb  ov094
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F803C  0x021F803C  thumb  ov094
 *   func_02031194  0x02031194  arm
 */
#include "../../matched/include/Obj21597.h"
#include "../../matched/include/Obj21598.h"
#include "../../matched/include/Obj21599.h"

struct TcblNode;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct S { char *w; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

extern u8 *func_021B98AC(char *const *q, u8 b);
extern void *func_021D5844(void *m);
extern void func_021F7D80(void *a, int b);
extern void func_021F7E38(void *a, int b);
extern void func_021F80E4(u32 a);
extern int func_021F7EB4(void);
extern void func_021F803C(u32 a, void *m, u32 c);
extern void func_02031194(struct TcblNode *n);
u32 func_021ED5D8(u8 *p);
void func_021ED5E8(u32 x, struct S *t);


u32 func_021ED5D8(u8 *p) { if (p[0x40] == 0) return 1; return 0; }


void func_021ED5E8(u32 x, struct S *t)
{
    void *r;

    switch (t->c) {
    case 0:
        r = func_021D5844(func_021B98AC(*(char *const * *)&((struct Obj21597 *)(t->w))->f138, t->k));
        if (t->a == 0)
            func_021F7D80(r, t->v);
        else
            func_021F7E38(r, t->v);
        func_021F80E4(t->v);
        t->c++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021F803C(((struct Obj21598 *)(t->w))->f134,
                          func_021B98AC(*(char *const * *)&((struct Obj21599 *)(t->w))->f138, t->k), t->v);
            (*t->cnt)--;
            func_02031194((struct TcblNode *)x);
        }
        break;
    }
}
