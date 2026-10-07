/*
 * file:     field_g3dobj_p03.c
 * unit:     yes
 * function: func_021C61D4, func_021C61EC, func_021C622C
 * address:  0x021C61D4
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
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C62F0  0x021C62F0  thumb  ov021
 *   func_021C6368  0x021C6368  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021D3288  0x021D3288  thumb  ov021
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 */
#include "../../matched/include/Obj18307.h"
#include "../../matched/include/Obj06083.h"

struct Desc;
struct Evt;
struct Obj;
struct St021D3244;
struct St021D325C;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    void *f4;
} Ctx;

extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02188E30(u8 *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_021C62F0(u8 *p);
extern void func_021C6368(u8 *p);
extern void func_020061E4(u32 a);
extern void func_021D3288(void *a, int b, int c);
extern void func_021D325C(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);
int func_021C61D4(u32 a);
void func_021C61EC(void *a, void *b, void *c);
int func_021C622C(void *unused, int *st, Ctx *c);


int func_021C61D4(u32 a)
{
if (func_021A1BF4((u8 *)func_02188C6C((u8 *)(((struct Obj18307 *)((u8 *)(a)))->fC))) == 0) {
    return 1;
}
return 0;
}


void func_021C61EC(void *a, void *b, void *c)
{
    void *task;
    u8 *w;

    task = func_020122C0(b, 0, func_021C622C, 8);
    w = func_020124E8(task);
    w[0] = 3;
    w[1] = 0;
    w[2] = 2;
    w[3] = 0;
    ((struct Obj06083 *)w)->f4 = func_02188E30(c);
    func_02012374(a, task);
}


int func_021C622C(void *unused, int *st, Ctx *c)
{
    switch (*st) {
    case 0:
        func_021C62F0((u8 *)c);
        func_020061E4(0x683);
        *st = *st + 1;
        break;
    case 1:
        if (c->f3++ >= c->f2) {
            c->f1++;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 >= 8) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (c->f3++ < 0x1e) {
            *st = *st + 1;
        }
        break;
    case 3:
        if (c->f3++ >= c->f2) {
            c->f1--;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 == 0) {
            *st = *st + 1;
        }
        break;
    case 4:
        func_021D325C(c->f4, 0, 0, 0, 0x1f);
        func_021D3244(c->f4, c->f0, 0);
        *st = *st + 1;
        break;
    default:
        func_021C6368((u8 *)c);
        return 1;
    }
    return 0;
}
