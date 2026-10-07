/*
 * file:     pdw_postman_p13.c
 * unit:     yes
 * function: func_021B8328, func_021B833C, func_021B834C
 * address:  0x021B8328
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
 *   func_021B91F8  0x021B91F8  thumb ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 */
#include "../../matched/include/Obj00454.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0xC];
    void *xc;
} Obj;

extern void func_021B91F8(Obj *, void *);
extern u8 *func_021B87D8(u8 *p, u32 idx);
void func_021B8328(Obj *o, void *a, void *b);
u8 *func_021B833C(u8 *p);
u8 *func_021B834C(u8 *p);


void func_021B8328(Obj *o, void *a, void *b)
{
    void *save = o->xc;

    o->xc = a;
    func_021B91F8(o, b);
    o->xc = save;
}


u8 *func_021B833C(u8 *p)
{
    return func_021B87D8((u8 *)(*(u32 *)&((struct Obj00454 *)p)->f24), *(u32 *)*(u32 *)&((struct Obj00454 *)p)->f4);
}


/*
 * Tail call with two object fields.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_021B834C(u8 *p)
{
    return func_021B87D8((u8 *)(*(u32 *)&((struct Obj00454 *)p)->f24), *(u32 *)(*(u32 *)&((struct Obj00454 *)p)->f4 + 4));
}
