/*
 * function: BR_UTIL_MainProfileScreen
 * address: 0x021FD6B0
 * packet: pkt_ov186_021FD6B0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 */
#include "../include/Obj24841.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BR_UTIL_FlushText(u8 *p);
extern void PMS_DRAW_Main(u8 *);
int BR_UTIL_MainProfileScreen(u8 *p)
{
    int result=1;
    int i;
    for(i=0;i<7;i++)if(*(void **)((u32)p+(u32)i*4)!=0)result &=BR_UTIL_FlushText(*(void **)((u32)p+(u32)i*4));
    PMS_DRAW_Main(*(u8 * *)&((struct Obj24841 *)p)->f20);
    return result;
}
