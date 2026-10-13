/*
 * function: func_021C47A0
 * address: 0x021C47A0
 * packet: pkt_ov208_021C47A0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_Draw 0x02014D2C thumb
 */
#include "../include/Obj14660.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct McssSys;
extern void MCSS_Draw(struct McssSys *sys);
void func_021C47A0(u32 a, u32 b, u32 c, u8 *p)
{
    if (p != 0 && *(struct McssSys * *)&((struct Obj14660 *)p)->f8 != 0)
        MCSS_Draw(*(struct McssSys * *)&((struct Obj14660 *)p)->f8);
}
