/*
 * function: INTRO_MSG_StartTimeIcon
 * address: 0x021BF560
 * packet: pkt_ov204_021BF560
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Start 0x0202EF98 thumb
 */
#include "../include/Obj14625.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern void TIME_ICON_Start(u8 *,u32,u32,u8,u8);
void INTRO_MSG_StartTimeIcon(u8 *p)
{
    TIME_ICON_Start(*(u8 * *)&((struct Obj14625 *)p)->f44,func_020056BC(),((struct Obj14625 *)p)->f1C,15,16);
}
