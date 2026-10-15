/*
 * function: WIFI_BSUBWAY_GRAPHIC_SetWord
 * address: 0x021D8118
 * packet: pkt_ov116_021D8118
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 */
#include "../include/Obj22631.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct WordSet;
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void WIFI_BSUBWAY_GRAPHIC_SetWord(u8 *p, u32 i, u32 a, u32 b)
{
    WORDSET_SetSlotNumber(((struct Obj22631 *)p)->f994, i, a, b, 2, 1);
}
