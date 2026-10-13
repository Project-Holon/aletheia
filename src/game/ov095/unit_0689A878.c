/*
 * file:     unit_0689A878.c
 * function: func_0689A878
 * address:  0x0689A878
 * packet:   pkt_ov095_0689A878
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb
 *   func_021B8E70  0x021B8E70  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb
 *   func_021D5528  0x021D5528  thumb
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb
 *   func_0220270C  0x0220270C  thumb
 */
#include "../../matched/include/Obj03724.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a[4];
    u8 b[4];
    u8 c[4];
    u32 x;
    u32 w;
} R;

extern u32 BTL_POKEPARAM_GetMoveCount(u32 h);
extern u32 BTL_POKEPARAM_IsTransformed(u32 h);
extern u16 func_021D5528(u32 h, u8 i, u8 *p, u8 *q);
extern u32 BTL_POKEPARAM_GetPokeId(u32 h);
extern u32 func_021B8D8C(u32 a, u32 b, u32 c);
extern u32 func_021B8E70(u32 a, u32 b);
extern void func_0220270C(u32 h, int k, R *r);

int func_0689A878(int unused, u8 *s)
{
    R r;
    u8 t[2];
    u16 i;
    u32 n;

    n = BTL_POKEPARAM_GetMoveCount(((struct Obj03724 *)s)->f6C);
    r.w = BTL_POKEPARAM_IsTransformed(((struct Obj03724 *)s)->f6C);
    for (i = 0; i < n; i++) {
        r.a[i] = func_021D5528(((struct Obj03724 *)s)->f6C, i, &t[1], &t[0]);
        r.b[i] = t[1];
        r.c[i] = t[0];
    }
    for (; i < 4; i++) {
        r.a[i] = 0;
        r.b[i] = 0;
        r.c[i] = 0;
    }
    r.x = func_021B8E70(((struct Obj03724 *)s)->fA0,
                        func_021B8D8C(((struct Obj03724 *)s)->fA0, ((struct Obj03724 *)s)->fA4,
                                      BTL_POKEPARAM_GetPokeId(((struct Obj03724 *)s)->f6C)));
    func_0220270C(((struct Obj03724 *)s)->fB0, 2, &r);
    return 1;
}
