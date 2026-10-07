/*
 * file:     field_nogrid_mapper_p04.c
 * unit:     yes
 * function: func_021B9530, func_021B95C0, func_021B960C
 * address:  0x021B9530
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
 *   func_021B94D8  0x021B94D8  thumb
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B8514  0x021B8514  thumb
 *   func_021B86A4  0x021B86A4  thumb
 *   func_021B87FC  0x021B87FC  thumb  ov021
 */
#include "../../matched/include/Obj01203.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 key[4]; u32 val[4]; } T;

int func_021B94D8(u16 *r, u8 *tbl, u8 *sr);
u8 *func_021B87D8(u8 *p, u32 idx);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6);
extern u8 *func_021B87FC(u8 *p, u32 idx);
void func_021B9530(u16 *t, u8 *p, int dx, int dy, int a6);
int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
u32 func_021B960C(T *t, int b, u32 c);


/*
 * Addresses are Black-image addresses.
 */
void func_021B9530(u16 *t, u8 *p, int dx, int dy, int a6)
{
    if (func_021B94D8(t, *(u8 * *)&((struct Obj01203 *)p)->f4, *(u8 * *)&((struct Obj01203 *)p)->f24) != 0) {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj01203 *)p)->f24, **(u32 * *)&((struct Obj01203 *)p)->f4);
        u8 *res = func_021B8514(row, a6, *(u8 * *)&((struct Obj01203 *)p)->f24, t, 0);
        u32 out1, out2;

        func_021B86A4(*(u8 * *)&((struct Obj01203 *)p)->f24, (const u32 *)(*(u8 * *)&((struct Obj01203 *)p)->f4), (int *)(&out1), (int *)(&out2),
                      (u16 *)t, ((struct Obj01203 *)p)->f1C);
        ((struct Obj01203 *)p)->fC += dx;
        ((struct Obj01203 *)p)->f14 += dy;
        if (((struct Obj01203 *)p)->fC > (int)out1)
            ((struct Obj01203 *)p)->fC = out1;
        if (res == 0) {
            int f = ((struct Obj01203 *)p)->f14;
            int a = f < 0 ? -f : f;
            if (a > (int)out2) {
                if (f > 0)
                    ((struct Obj01203 *)p)->f14 = out2;
                else
                    ((struct Obj01203 *)p)->f14 = -(int)out2;
            }
        }
        return;
    }
    ((struct Obj01203 *)p)->fC += dx;
    ((struct Obj01203 *)p)->f14 += dy;
}


int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6)
{
    u32 c, d;

    if (func_021B94D8((u16 *)p, q, sr) == 0)
        goto ok;
    func_021B86A4(sr, (u32 *)q, (int *)(&c), (int *)(&d), (u16 *)((u32)p), a6);
    if (a3 > (int)c)
        goto fail;
    if (a4 < 0)
        a4 = -a4;
    if (a4 > (int)d)
        goto fail;
    return 1;
fail:
    return 0;
ok:
    return 1;
}

u32 func_021B960C(T *t, int b, u32 c)
{
    int i;
    int r;
    for (i = 0; i < 4; i++) {
        r = (int)func_021B87FC((u8 *)c, t->key[i]);
        if (r == b)
            return t->val[i];
    }
    return 0;
}
