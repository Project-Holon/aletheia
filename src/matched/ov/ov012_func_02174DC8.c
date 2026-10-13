/*
 * function: COLOSSEUM_RecvBattlePositions
 * address: 0x02174DC8
 * packet: pkt_ov012_02174DC8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj19289.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuCopy8(void *,void *,u32);
void COLOSSEUM_RecvBattlePositions(int unused, u32 n, void *src, u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19289 *)ctx)->f355C;
    if (p) {
        MI_CpuCopy8(src,p+0x15c,n);
        p[0x160] = 1;
    }
}
