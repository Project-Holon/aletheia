/*
 * function: func_02179A4C
 * address:  0x02179A4C
 * packet:   pkt_ov015_02179A4C
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0217AB80     0x0217AB80  data   ov015  a1
 *   d_0217AAAC     0x0217AAAC  data   ov015  a1
 *   d_0217ABA0     0x0217ABA0  data   ov015  a1
 *   d_0217AB40     0x0217AB40  data   ov015  a4
 *   func_02034714  0x02034714  arm
 *   func_021798DC  0x021798DC  thumb  ov015
 */

#include "../include/G_s_ab40.h"
#include "../include/G_s_aba0.h"
#include "../include/G_State.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct State d_0217AB80;
extern u8 d_0217AAAC[];
extern struct s_aba0 d_0217ABA0;
extern struct s_ab40 d_0217AB40;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021798DC(void *dst, int n, u8 a, u8 b);

void func_02179A4C(void *dst, u8 a, u8 b)
{
    if (((u8 *)&d_0217AB80)[0xE] != 1)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    func_021798DC(dst, a, b, (u8)(d_0217ABA0.b2 | (d_0217ABA0.b3 << 4)));
    d_0217AB40.f44 = (u32)dst;
    ((u8 *)&d_0217AB80)[0x1E] = a;
    ((u8 *)&d_0217AB80)[0x1F] = b;
    d_0217ABA0.b0 = d_0217ABA0.b2;
    d_0217ABA0.b1 = 1;
    ((u8 *)&d_0217AB80)[0xE] = 0;
}
