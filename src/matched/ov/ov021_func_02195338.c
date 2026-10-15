/*
 * function: TALKMSGWIN_UpdateShape
 * address:  0x02195338
 * packet:   pkt_ov021_02195338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VEC_Subtract  0x0207CA00  arm
 *   TALKMSGWIN_ProjectToWorld  0x02194E74  thumb  ov021
 *   TALKMSGWIN_GetAnchorWindowPoint  0x02194E90  thumb  ov021
 *   TALKMSGWIN_CalcTail  0x02194F84  thumb  ov021
 *   TALKMSGWIN_GetWindowCornerPoints  0x02195128  thumb  ov021
 *   TALKMSGWIN_BuildShape  0x0219518C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01494.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

extern void VEC_Subtract(u32 a, u8 *b, V *c);
extern int TALKMSGWIN_ProjectToWorld(u32 a, u32 b, u32 c, u32 d);
extern void TALKMSGWIN_GetAnchorWindowPoint(u8 *e, u8 *ent, int *b, int *c, void *d);
extern int TALKMSGWIN_CalcTail(u8 *e, int b, int c, void *d, void *f);
extern void TALKMSGWIN_GetWindowCornerPoints(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3);
extern void TALKMSGWIN_BuildShape(u8 *p, u8 *e, V *a, V *b, V *c, V *d, V *f, V *g, V *h);

u32 TALKMSGWIN_UpdateShape(u8 *p, u8 *e)
{
    V v8;
    V v7;
    V v6;
    V v5;
    V v4;
    V v3;
    V v2;
    V v1;
    int b;
    int c;
    int r;

    if (((struct Obj01494 *)e)->f10 != 0) {
        VEC_Subtract(((struct Obj01494 *)e)->f10, p + 0xCB8, &v1);
        TALKMSGWIN_ProjectToWorld((u32)(&v1), (u32)(&b), (u32)(&c), (u32)(&v8));
    } else {
        TALKMSGWIN_GetAnchorWindowPoint(e, p + 0x18 + ((struct Obj01494 *)e)->f1A * 100, &b, &c, &v8);
    }
    r = TALKMSGWIN_CalcTail(e, b, c, &v7, &v6);
    TALKMSGWIN_GetWindowCornerPoints(e, (u32)(&v5), (u32)(&v4), (u32)(&v3), (u32)(&v2));
    TALKMSGWIN_BuildShape(p, e, &v8, &v7, &v6, &v5, &v4, &v3, &v2);
    if (((struct Obj01494 *)e)->f58 != r) {
        ((struct Obj01494 *)e)->f58 = r;
        return 1;
    }
    return 0;
}
