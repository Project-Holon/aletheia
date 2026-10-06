/*
 * function: func_021FFC8C
 * address: 0x021FFC8C
 * packet: pkt_ov135_021FFC8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207E804 0x0207E804 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   d_02203884 0x02203884 data a2
 *   d_02203892 0x02203892 data a1
 */
#include "../include/Obj23438.h"
#include "../include/Obj23439.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const u16 d_02203884[];
extern const u8 d_02203892[];
extern void func_0207E804(void *, int, int);
extern void func_0207E5D0(void *, int, int);
void func_021FFC8C(u8 **p, u8 *q, int k, int n, int a4)
{
    u8 *dst;
    if (n > 16) n = 16;
    else if (n < 0) n = 0;
    dst = *(u8 * *)&((struct Obj23438 *)q)->fC;
    func_0207E804(((struct Obj23439 *)(p[n]))->f14, d_02203884[k], 512);
    func_0207E5D0(dst + d_02203892[n] * 32, (k + 2) * 32, 32);
}
