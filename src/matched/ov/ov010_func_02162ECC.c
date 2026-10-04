/*
 * function: func_02162ECC
 * address: 0x02162ECC
 * packet: pkt_ov010_02162ECC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: const source pointer hoists the last halfword load before the output store.
 * symbols:
 *   func_0207C768 0x0207C768 arm
 */
#include "../include/Obj18972.h"
typedef unsigned short u16;
typedef short s16;
typedef unsigned int   u32;
extern u32 func_0207C768(u32 a, u32 b);
void func_02162ECC(const char *p, int *out)
{
    const u16 *q = (const u16 *)(p + 10);
    int y, x, z;
    z = func_0207C768(q[3] << 16, 0x2000);
    z = ((unsigned)q[1] << 16) + z;
    y = ((const s16 *)q)[4] << 12;
    x = func_0207C768(q[2] << 16, 0x2000);
    out[2] = z;
    out[0] = ((unsigned)((struct Obj18972 *)p)->fA << 16) + x;
    out[1] = y;
}
