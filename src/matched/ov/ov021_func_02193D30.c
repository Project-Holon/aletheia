/*
 * function: func_02193D30
 * address:  0x02193D30
 * packet:   pkt_ov021_02193D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218625C  0x0218625C  thumb  ov020
 *   func_02193CBC  0x02193CBC  thumb  ov021
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186818  0x02186818  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_02193F80  0x02193F80  thumb  ov021
 *   func_02194084  0x02194084  thumb  ov021
 *   func_02194128  0x02194128  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_0204932C  0x0204932C  arm
 *   d_021D3F58     0x021D3F58  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00485.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 a; u8 b; u8 rest[0x16]; } E18;
typedef struct { u16 h0; u16 h1; u32 w4; E18 A[10]; E18 B[10]; } Src;

extern int d_021D3F58[];
extern void func_0218625C(Src *s);
extern void func_02193CBC(u8 *o);
extern int func_02161ECC(E18 *p);
struct ArcFile;
extern void func_02186818(u32 *p, u32 member);
extern u8 *func_02186844(u8 *t, int i);
extern char *func_0218682C(char *p);
extern void func_02193F80(void *dst, E18 *src, u8 *pair, u16 *r);
extern void func_02194084(u8 *p, Src *s, int h);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02194128(u8 *p, int a, u8 *b);

void func_02193D30(u8 *o, Src *s, int which)
{
    int i;
    int off;
    u8 *pair;

    func_0218625C(s);
    func_02193CBC(o);
    o[0] = s->h1;
    o[1] = which;
    for (i = 0; i < 10; i++) {
        if (which == 0) {
            off = i * 0x18;
            if (func_02161ECC((E18 *)((u8 *)s->A + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->A[i].b);
                func_02193F80(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50, (E18 *)((u8 *)s->A + off),
                              func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i),
                              (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        } else {
            off = i * 0x18;
            if (func_02161ECC((E18 *)((u8 *)s->B + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->B[i].b);
                pair = func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i);
                func_0218682C((char *)(((struct Obj00485 *)o)->fC));
                func_02193F80(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50, (E18 *)((u8 *)s->B + off),
                              pair, (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        }
    }
    func_02194084(o + 0x11c, s, ((struct Obj00485 *)o)->fC);
    if (which == 0)
        *(Src * *)&((struct Obj00485 *)o)->f8 = s;
    else
        *(Src * *)&((struct Obj00485 *)o)->f8 = 0;
    func_020493D4((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]]);
    func_0204932C((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]], (void *)(*(int *)&((struct Obj00485 *)o)->f14));
    func_02194128(o + 0x11c, *(int *)&((struct Obj00485 *)o)->f14, o + 0x18);
}
