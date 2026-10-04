/*
 * function: func_021CD214
 * address:  0x021CD214
 * packet:   pkt_ov021_021CD214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0204ED4C  0x0204ED4C  arm
 *   func_0204ED80  0x0204ED80  arm
 *   func_0204ED8C  0x0204ED8C  arm
 *   func_0204ED98  0x0204ED98  arm
 *   func_0204EDA4  0x0204EDA4  arm
 */
#include "../include/Obj01220.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_0207CDB8(u16 *a, u16 *b);
extern void func_0204ED4C(void *o, u16 *v);
extern void func_0204ED80(u8 *dst, u16 *src);
extern void func_0204ED8C(u8 *dst, u16 *src);
extern void func_0204ED98(u8 *dst, u16 *src);
extern void func_0204EDA4(u8 *dst, u16 *src);

void func_021CD214(u8 *s, void *o)
{
    u16 v[3];
    u16 c[4];

    v[0] = ((struct Obj01220 *)s)->f4;
    v[1] = ((struct Obj01220 *)s)->f8;
    v[2] = ((struct Obj01220 *)s)->fC;
    func_0207CDB8(v, v);
    func_0204ED4C(o, v);
    c[3] = ((struct Obj01220 *)s)->f10 | (((struct Obj01220 *)s)->f12 << 5) | (((struct Obj01220 *)s)->f14 << 10);
    func_0204ED80(o, &c[3]);
    c[2] = ((struct Obj01220 *)s)->f16 | (((struct Obj01220 *)s)->f18 << 5) | (((struct Obj01220 *)s)->f1A << 10);
    func_0204ED8C(o, &c[2]);
    c[1] = ((struct Obj01220 *)s)->f1C | (((struct Obj01220 *)s)->f1E << 5) | (((struct Obj01220 *)s)->f20 << 10);
    func_0204ED98(o, &c[1]);
    c[0] = ((struct Obj01220 *)s)->f22 | (((struct Obj01220 *)s)->f24 << 5) | (((struct Obj01220 *)s)->f26 << 10);
    func_0204EDA4(o, &c[0]);
}
