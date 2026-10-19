/*
 * function: RESEARCH_LIST_ApplyScrollRegs
 * address: 0x021BC338
 * packet: pkt_ov217_021BC338
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   RESEARCH_LIST_GetScrollMin 0x021BC3D4 thumb ov217
 *   RESEARCH_LIST_GetScrollMax 0x021BC3E0 thumb ov217
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 */
#include "../include/Obj25856.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 RESEARCH_LIST_GetScrollMin(void);
extern u32 RESEARCH_LIST_GetScrollMax(void);
extern void BG_SYS_ChangeScroll(unsigned layer,unsigned mode,unsigned value);
void RESEARCH_LIST_ApplyScrollRegs(u8 *p)
{
    int position;
    int low;
    int high;
    position=((struct Obj25856 *)p)->f34;
    low=RESEARCH_LIST_GetScrollMin();
    high=RESEARCH_LIST_GetScrollMax();
    if(position<low) {
        position-=24;
        BG_SYS_ChangeScroll(2,3,position);
        BG_SYS_ChangeScroll(3,3,position);
    } else if(high<position) {
        position-=168;
        BG_SYS_ChangeScroll(2,3,position);
        BG_SYS_ChangeScroll(3,3,position);
    }
}
