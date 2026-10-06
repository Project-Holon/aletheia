/*
 * function: func_02184AB4
 * address:  0x02184AB4
 * packet:   pkt_ov020_02184AB4
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */
#include "../include/Obj09424.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

typedef struct { int f[39]; } S9C;

typedef unsigned int   u32;
struct Desc;
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void *func_02161824(void *a, void *b);
extern int func_02184504(int a, int *state, u8 *p);
extern u32 func_02188D20(u8 *p);
extern void func_021BC550(void *p, int v);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int func_02184AB4(int ctx, int *state, u8 *p)
{
    int x = ((struct Obj09424 *)p)->f0;
    int z = ((struct Obj09424 *)p)->f8;
    int r;
    S9C *o;

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 0, 0));
        (*state)++;
        break;
    case 2:
        r = (int)func_020122C0((void *)x, 0, func_02184504, 0x9c);
        o = func_020124E8((struct Obj *)r);
        *o = *(S9C *)p;
        func_02012374((struct Evt *)ctx, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), ((struct Obj09424 *)p)->f14);
        return 1;
    }
    return 0;
}
