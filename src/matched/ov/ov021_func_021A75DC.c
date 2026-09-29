/*
 * function: func_021A75DC
 * address:  0x021A75DC
 * packet:   pkt_ov021_021A75DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_021A7678  0x021A7678  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct T { u32 n; } T;
typedef struct W { u8 a[0x400]; T *tbl; } W;

extern T *func_0204A1BC(u32 a, u32 b, u32 c, u32 d);
extern void func_021A7678(u8 *a, T *b, u32 c, u32 d, u32 e);

void func_021A75DC(W *w, u32 a, u32 b, u32 c, u32 heap)
{
    u32 i;
    w->tbl = func_0204A1BC(a, b, 0, heap);
    for (i = 0; i < w->tbl->n; i++)
        func_021A7678(&w->a[i * 64], w->tbl, i, c, heap);
}
