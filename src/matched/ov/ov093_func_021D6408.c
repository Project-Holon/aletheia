/*
 * function: BTL_POKEPARAM_AdvanceTurn
 * address: 0x021D6408
 * packet: pkt_ov093_021D6408
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: halfword at +0x146 re-read at 021D641C and 021D6428.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   BTL_POKEPARAM_AdvanceHitTurn 0x021D6824 thumb ov093
 */
#include "../include/Obj00041.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *, int, u32);
extern void BTL_POKEPARAM_AdvanceHitTurn(u8 *);
void BTL_POKEPARAM_AdvanceTurn(u8 *p)
{
    func_02082BCC(p + 0x153, 0, 2);
    if (*(volatile u16 *)&((struct Obj00041 *)p)->f146 < 9999)
        *(volatile u16 *)&((struct Obj00041 *)p)->f146 += 1;
    BTL_POKEPARAM_AdvanceHitTurn(p);
}
