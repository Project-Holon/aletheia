/*
 * function: WEATHER_LIGHTNING_Init
 * address: 0x021EF9B0
 * packet: pkt_ov026_021EF9B0
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020056EC 0x020056EC thumb
 */
#include "../include/Obj13039.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, u32);
extern u32 func_020056EC(u32);
void WEATHER_LIGHTNING_Init(u8 *p, int b)
{
    MI_CpuFill8(p, 0, 64);
    ((struct Obj13039 *)p)->f38 = func_020056EC(3);
    p[1] = b;
}
