/*
 * function: func_021BE0E4
 * address:  0x021BE0E4
 * packet:   pkt_ov210_021BE0E4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B93D4  0x021B93D4  thumb  ov067
 *   func_021BE8B8  0x021BE8B8  thumb  ov210
 *   func_021BF85C  0x021BF85C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct S;
extern void func_021B93D4(struct S *s, int v);
extern void func_021BE8B8(u8 *p);
extern void func_021BF85C(char *p, int i, int flag);

void func_021BE0E4(u8 *p, u32 v)
{
    (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[1] = v;
    func_021B93D4(((struct Obj00085 *)p)->f1E0, v);
    func_021BE8B8(p);
    func_021BF85C((char *)p, (u16)v, 1);
}
