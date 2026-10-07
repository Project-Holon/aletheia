/*
 * file:     pdw_postman_p15.c
 * unit:     yes
 * function: func_021B8514, func_021B854C, func_021B8658, func_021B8674, func_021B868C
 * address:  0x021B8514
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
 *   func_021B9510  0x021B9510  thumb
 *   func_021B87FC  0x021B87FC  thumb
 *   func_021B95C0  0x021B95C0  thumb
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B9278  0x021B9278  thumb
 *   func_021B9280  0x021B9280  thumb
 *   func_021B963C  0x021B963C  thumb
 */
#include "../../matched/include/Obj00010.h"
#include "../../matched/include/Obj02052.h"
#include "../../matched/include/Obj04134.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

u8 *func_021B9510(u16 *p, u8 *q, u32 v);
u8 *func_021B87FC(u8 *p, u32 idx);
int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
u8 *func_021B87D8(u8 *p, u32 idx);
int func_021B93D4(int dir);
int func_021B9278(u32 a, u32 b, u32 c);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int func_021B963C(u8 *a, u8 *b);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7);
void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
int func_021B8674(u8 *p, u32 *q, u32 v);
int func_021B868C(u8 *p, u32 *q, void *v);


/*
 * Addresses are Black-image addresses.
 */
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (v == ((u32 *)p)[i + 4]) {
            if (flag)
                return func_021B9510(r, q, ((u32 *)p)[i]);
            return func_021B87FC(q, ((u32 *)p)[i]);
        }
    }
    return 0;
}


/*
 * closed 2026-09-27 (tree_ov018): the early exit is one guard,
 * if (arg4 < arg6 && arg4 >= 0) goto tail; ahead of a plain if/else for the
 * two row lookups, and arg6 is reassigned in place of a separate m local.
 * Addresses are Black-image addresses.
 */
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7)
{
    int res;

    if (func_021B95C0(*(u8 * *)&((struct Obj00010 *)p)->f28, a, arg4, arg5,
                      *(u8 * *)&((struct Obj00010 *)p)->f24, *(u32 *)&((struct Obj00010 *)p)->f1C) == 0)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > arg7)
        return 0;
    if (arg4 < arg6 && arg4 >= 0)
        goto tail;
    if (arg4 >= arg6) {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f4);
        res = (int)func_021B8514(row, ((struct Obj02052 *)a)->f8,
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    } else {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f0);
        res = (int)func_021B8514(row, func_021B93D4(((struct Obj02052 *)a)->f8),
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    }
    if (res == 0) {
        if (arg4 > arg6)
            return 0;
        goto tail;
    }
    a = (u8 *)res;
    if (arg4 >= arg6) {
        arg4 -= arg6;
        arg6 = func_021B9278(res, *(u32 *)&((struct Obj00010 *)p)->f1C, *(u32 *)&((struct Obj00010 *)p)->f24);
        arg7 = (u32)func_021B9280((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    } else if (arg4 < 0) {
        arg6 = func_021B9278(res, *(u32 *)&((struct Obj00010 *)p)->f1C, *(u32 *)&((struct Obj00010 *)p)->f24);
        arg4 += arg6;
        arg7 = (u32)func_021B9280((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    }
    if (arg4 >= arg6)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > (int)arg7)
        return 0;
tail:
    func_021B8658(p, (u32)a, arg3, arg4, arg5, arg6, (int)arg7);
    func_021B963C(a, *(u8 * *)&((struct Obj00010 *)p)->f24);
    return arg3;
}


void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    ((struct Obj04134 *)p)->f0 = 1;
    ((struct Obj04134 *)p)->f4 = a;
    ((struct Obj04134 *)p)->f14 = d;
    ((struct Obj04134 *)p)->f10 = e;
    ((struct Obj04134 *)p)->f20 = b;
    ((struct Obj04134 *)p)->fC = c;
    ((struct Obj04134 *)p)->f18 = f;
}


int func_021B8674(u8 *p, u32 *q, u32 v)
{
    return func_021B87D8(p, *q) == (u8 *)v;
}


int func_021B868C(u8 *p, u32 *q, void *v)
{
    return func_021B87D8(p, q[1]) == (u8 *)v;
}
