/*
 * file:     field_place_name_p25.c
 * unit:     yes
 * function: func_021BDC2C, func_021BDC80
 * address:  0x021BDC2C
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
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 */
#include "../../matched/include/Obj05065.h"

struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct {
    char pad[0xC];
    void *fC;
    char pad2[0x10];
    s16 s20;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02188D20(u8 *p);
extern void func_021BC550(void *p, int v);
void func_021BDC2C(u32 *ctx, u32 a);
void func_021BDC80(Obj *p);


void func_021BDC2C(u32 *ctx, u32 a)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj05065 *)p)->f4;
    u32 y = ((struct Obj05065 *)p)->fC;

    if (((struct Obj05065 *)p)->f40 != 0)
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 3, 0, 0, p[0x44], p[0x45]));
    else
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, ((struct Obj05065 *)p)->f3C, 0, 1, 0, 0));
}


void func_021BDC80(Obj *p)
{
    Inner *q = p->f0;

    func_021BC550((void *)func_02188D20(q->fC), q->s20);
}
