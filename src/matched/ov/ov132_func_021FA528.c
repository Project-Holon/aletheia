/*
 * function: STA_ACT_AUDIENCE_RandomizeRecords
 * address: 0x021FA528
 * packet: pkt_ov132_021FA528
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005728 0x02005728 thumb
 */
#include "../include/Obj14091.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_02005728(unsigned);
void STA_ACT_AUDIENCE_RandomizeRecords(char *p)
{
    u8 i;
    for (i = 0; i < 60; i++) {
        char *q = p + i * 8;
        ((struct Obj14091 *)q)->f205 = func_02005728(60) + 1;
        ((struct Obj14091 *)q)->f204 = 255;
    }
}
