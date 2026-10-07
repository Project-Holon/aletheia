/*
 * file:     fldeff_splash_p13.c
 * unit:     yes
 * function: func_021C59A8, func_021C59BC, func_021C59F8, func_021C5A28
 * address:  0x021C59A8
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
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_021C5A54  0x021C5A54  thumb  ov021
 */
#include "../../matched/include/Obj12133.h"
#include "../../matched/include/Obj09688.h"

struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Desc;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021C59A8;

typedef signed char    s8;

typedef short s16_021C59F8;

typedef struct {
    s16_021C59F8 x;
    s16_021C59F8 y;
} P2;

typedef struct {
    u8 pad[0x28];
    u32 h[3];
} S;

extern u32 func_0201F868(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021C5A54(int a, int *st, int *c);
int func_021C59A8(u32 a, u32 b, u32 c);
void func_021C59BC(void *a, u8 *p);
void func_021C59F8(S *p, int v);
void *func_021C5A28(void *a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C59A8(u32 a, u32 b, u32 c)
{
func_0202020C((struct Obj *)(((struct Obj12133 *)((u8 *)(a)))->f4), (u16 *)b, (u16 *)c);
return func_0201F868((void *)(((struct Obj12133 *)((u8 *)(a)))->f0));
}


/*
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 */
void func_021C59BC(void *a, u8 *p)
{
    u16 n = ((struct Obj09688 *)p)->f72;
    int v = n * 0xC0 / 4 - 0xC0;

    (((struct Obj09688 *)p)->f72)++;
    if (n >= 4) {
        v = 0;
        ((struct Obj09688 *)p)->f80 = 1;
    }
    func_02040618(1, 3, v);
}


/*
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 */
void func_021C59F8(S *p, int v)
{
    s16_021C59F8 y;
    int i;
    P2 t;

    i = 0;
    y = v;
    for (; i < 3; i++) {
        func_0204B454((struct Actor *)p->h[i], (struct PtS *)&t, 0);
        t.y = y;
        func_0204B404((struct Obj *)p->h[i], (const struct Vec2 *)(&t), 0);
    }
}


/*
 * Spawns the func_021C5A54 task with a four-word work area.
 */
void *func_021C5A28(void *a, u32 b, u32 c, u32 d)
{
    void *t = func_020122C0(a, 0, func_021C5A54, 0x10);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = c;
    w[3] = d;
    return t;
}
