/*
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
 *   func_0689A918  0x0689A918  thumb  ov095
 *   func_0689A928  0x0689A928  thumb  ov095
 *   func_0689A938  0x0689A938  thumb  ov095
 *   func_0689A948  0x0689A948  thumb  ov095
 *   func_0689A958  0x0689A958  thumb  ov095
 *   func_0689A968  0x0689A968  thumb  ov095
 *   func_0689A978  0x0689A978  thumb  ov095
 */
#include "../../../matched/include/Obj03724.h"

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

extern u32 func_0689A918(u32 h);
extern u32 func_0689A928(u32 h);
extern u16 func_0689A938(u32 h, u8 i, u8 *p, u8 *q);
extern u32 func_0689A948(u32 h);
extern u32 func_0689A958(u32 a, u32 b, u32 c);
extern u32 func_0689A968(u32 a, u32 b);
extern void func_0689A978(u32 h, int k, R *r);

int func_0689A878(int unused, u8 *s)
{
    R r;
    u8 t[2];
    u16 i;
    u32 n;

    n = func_0689A918(((struct Obj03724 *)s)->f6C);
    r.w = func_0689A928(((struct Obj03724 *)s)->f6C);
    for (i = 0; i < n; i++) {
        r.a[i] = func_0689A938(((struct Obj03724 *)s)->f6C, i, &t[1], &t[0]);
        r.b[i] = t[1];
        r.c[i] = t[0];
    }
    for (; i < 4; i++) {
        r.a[i] = 0;
        r.b[i] = 0;
        r.c[i] = 0;
    }
    r.x = func_0689A968(((struct Obj03724 *)s)->fA0,
                        func_0689A958(((struct Obj03724 *)s)->fA0, ((struct Obj03724 *)s)->fA4,
                                      func_0689A948(((struct Obj03724 *)s)->f6C)));
    func_0689A978(((struct Obj03724 *)s)->fB0, 2, &r);
    return 1;
}
