/*
 * function: func_021ED660
 * address:  0x021ED660
 * packet:   pkt_ov093_021ED660
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetSlotFromViewPos  0x021B8ED8  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   func_021ED724  0x021ED724  thumb  ov093
 */
#include "../include/Obj10120.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void func_021ED724(u32 x, struct S *t);

void func_021ED660(char *p, u32 k, u32 a, u32 b)
{
    struct S *t;

    t = (struct S *)TCBL_GetWork(TCBL_AddTask(((struct Obj10120 *)p)->f2C, (void *)func_021ED724, 0x18, 1));
    t->v = BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj10120 *)p)->f138,
                                              BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj10120 *)p)->f134, a)));
    t->w = p;
    t->k = k;
    t->cnt = (u8 *)p + 0x40;
    t->f = b;
    t->c = 0;
    (*t->cnt)++;
}
