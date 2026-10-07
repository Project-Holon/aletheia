/*
 * file:     field_place_name_p20.c
 * unit:     yes
 * function: func_021BD7A8, func_021BD7E0, func_021BD874
 * address:  0x021BD7A8
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
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_021BD94C  0x021BD94C  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj03588.h"

struct Evt;
struct Args;
typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
} Cfg;

typedef struct {
    u32 f00;
    u32 f04;
    Cfg *cfg;
} Ctx;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void *func_021BFE00(int a0, void *p, int a2);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02188C58(void *p);
extern int func_0218F0F8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern void func_0218EC54(u8 *p);
extern void *func_021A7E3C(struct Args *a);
extern void func_021BD94C(u32 *);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_020061E4(u32);
int func_021BD7A8(void *task, u32 *state, Ctx *ctx);
u32 func_021BD7E0(u32 a, int *st, u32 *ctx);
u32 func_021BD874(u32 a, int *st, u32 *ctx);


/*
 * Addresses are Black-image addresses.
 */
int func_021BD7A8(void *task, u32 *state, Ctx *ctx)
{
    Cfg *cfg = ctx->cfg;
    u32 x = cfg->f04;
    u32 y = cfg->f0C;

    switch (*state) {
    case 0:
        func_02012374(task, func_021BFE00(0, (void *)x, y));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}


u32 func_021BD7E0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 h = (u32)func_02188C58((void *)(*(u32 *)&((struct Obj03588 *)p)->fC));

    switch (*st) {
    case 0:
        if (func_0218F0F8((u8 *)h) && func_0218F0E8((u8 *)h)) {
            func_0218F0A8((u8 *)h);
            *st = 1;
        } else {
            *st = 2;
        }
        return 0x21;
    case 1:
        if (!func_0218F0F8((u8 *)h)) {
            *st = 2;
            return 0x21;
        }
        if (func_0218F0E8((u8 *)h))
            break;
        func_0218EC54((u8 *)h);
        *st = 2;
        return 0x21;
    case 2:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)((u32)p)));
        *st = 3;
        return 0x21;
    case 3:
        return 1;
    }
    return 0;
}


u32 func_021BD874(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[2];
    u32 x = p[1];
    u32 y = p[3];

    switch (*st) {
    case 0:
        func_021BD94C(ctx);
        func_020061E4(0x737);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, y, 2, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
