/*
 * function: func_02174D10
 * address: 0x02174D10
 * packet: pkt_ov012_02174D10
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021750C8 0x021750C8 thumb ov012
 */
#include "../include/Obj19286.h"
#include "../include/Obj19287.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021750C8(u8 *p, int v);
void func_02174D10(u32 a, u32 b, u32 *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19286 *)d)->f355C;
    if (w == 0 || ((struct Obj19287 *)w)->f0 == 0) return;
    func_021750C8(w, *c);
}
