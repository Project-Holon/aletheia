/*
 * function: func_02178D20
 * address:  0x02178D20
 * packet:   pkt_ov014_02178D20
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178D74  0x02178D74  thumb  ov014
 *   func_020862F0  0x020862F0  arm
 *   func_0208FCB4  0x0208FCB4  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;
void func_02178D74(u8 *m);
void func_020862F0(u32 a, u32 b);
int func_0208FCB4(void *cb, u32 c, u32 a, u32 b, u32 d, u32 e, u32 f);

int func_02178D20(u32 a, u32 b, u32 c)
{
    func_020862F0(*(u32 *)(((u8 *)g_021797A8) + 0x1E68), *(u32 *)(((u8 *)g_021797A8) + 0x1E8C));
    if (func_0208FCB4((void *)func_02178D74, c, a, b, 0xFFFF, 0xE, 2) == 2)
        return 1;
    return 0;
}
