/*
 * function: INTRUDE_COMM_GetRelativeSlot
 * address: 0x021751A8
 * packet: pkt_ov011_021751A8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   GAME_DATA_GetExitMode 0x02012B58 thumb
 */
#include "../include/Obj07330.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct BigObj;
extern u32 func_02026478(void *obj);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
int INTRUDE_COMM_GetRelativeSlot(u8 *p, int index)
{
    int value;
    if (index >= p[0x902]) return 0;
    value = index - GAME_DATA_GetExitMode((const struct BigObj *)func_02026478((void *)(((struct Obj07330 *)p)->f4)));
    if (value < 0) value += p[0x902];
    return value;
}
