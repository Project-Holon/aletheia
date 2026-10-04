/*
 * function: func_0218BFB4
 * address:  0x0218BFB4
 * packet:   pkt_ov021_0218BFB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The table index is narrowed in its own statement (`k = (u8)k;`): the
 * second definition makes k a two-definition web that is coloured after
 * the multiply product, so the ldrb lands in r4, the product in r3 and
 * the t reload in r0 (docs/idioms/a-self-narrowing-cast-statement-
 * recolours-a-table-index.md). A cast inside the subscript is inert.
 *
 * symbols:
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D3D58     0x021D3D58  data   a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19518.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef void (*Fn)(void *a, u32 *out);
typedef struct {
    Fn fn;
    u32 pad[2];
} Entry;

struct G3dOwner;
struct G3dRec;
extern u8 *func_0218BCAC(u8 *p);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern Entry d_021D3D58[];

void func_0218BFB4(u8 *a, u32 *out, u32 *st)
{
    u32 buf[4];
    u8 *t;
    u32 h;
    int i;
    u8 k;

    t = func_0218BCAC((u8 *)st[0]);
    h = (u32)func_02047400((void *)st[1], 0, (void *)(((struct Obj19518 *)a)->f1D0));
    for (i = 0; i < 4; i++) {
        if (st[2 + i] != 0)
            buf[i] = (u32)func_02047564((struct G3dOwner *)h, (const struct G3dOwner *)st[2 + i], 0);
        else
            buf[i] = 0;
    }
    out[0] = (u32)func_0204767C(h, buf, 4);
    out[1] = (u32)st;
    k = t[0];
    k = (u8)k;
    d_021D3D58[k].fn(a, out);
}
