/*
 * function: B_PLIST_MAIN_GetMonAnimState
 * address: 0x0220F158
 * packet: pkt_ov198_0220F158
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 */
#include "../include/Obj10848.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Bits { u8 low:3; u8 kind:4; u8 high:1; };
extern int BGWINFRM_GetScaleRank(unsigned,unsigned);
int B_PLIST_MAIN_GetMonAnimState(char *p)
{
    u16 a=((struct Obj10848 *)p)->f10;
    if (a==0) return 0;
    if (((struct Bits *)(p+0x17))->kind!=8 && ((struct Bits *)(p+0x17))->kind!=6) return 5;
    if (a==((struct Obj10848 *)p)->f12) return 1;
    switch (BGWINFRM_GetScaleRank(a,((struct Obj10848 *)p)->f12)) {
    case 0: return 2;
    case 1: return 3;
    case 2: return 4;
    }
    return 0;
}
