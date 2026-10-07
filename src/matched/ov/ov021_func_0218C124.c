/*
 * function: func_0218C124
 * address:  0x0218C124
 * packet:   pkt_ov021_0218C124
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   d_021D3D5C     0x021D3D5C  data  a4
 */

#include "../include/G_Ops.h"

typedef struct {
    void (*f0)(void *p, void *s);
    void (*f4)(void *p, int idx, int c);
    void (*f8)(void);
} Ops;

typedef struct {
    int f0;
    int *f4;
} Obj;

extern struct Ops d_021D3D5C[];
typedef unsigned char  u8;
u8 *func_0218BCAC(u8 *p);

void func_0218C124(void *p, Obj *s)
{
    unsigned char k = *func_0218BCAC((u8 *)(*s->f4));
    if (s->f0 != 0)
        d_021D3D5C[k].f0(p, s);
}
