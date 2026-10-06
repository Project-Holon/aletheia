/*
 * function: func_021D4C4C
 * address: 0x021D4C4C
 * packet: pkt_ov123_021D4C4C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4C24 0x021D4C24 thumb ov123
 */
#include "../include/Obj05360.h"
typedef unsigned int u32;
typedef unsigned char  u8;
extern void func_021D4C24(u8 *p, int v);
void func_021D4C4C(char *p)
{
    u32 keys = ((struct Obj05360 *)p)->f278;
    if (keys != ((struct Obj05360 *)p)->f27C) {
        if (keys & 0x40) func_021D4C24((u8 *)p, 0x18);
        else if (keys & 0x80) func_021D4C24((u8 *)p, 0x16);
        else if (keys & 0x100) func_021D4C24((u8 *)p, 0x15);
        else if (keys & 0x200) func_021D4C24((u8 *)p, 0x15);
        else func_021D4C24((u8 *)p, 0xe);
    }
}
