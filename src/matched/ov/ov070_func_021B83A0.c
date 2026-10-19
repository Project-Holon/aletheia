/*
 * function: ITEMMENU_IsItemRegistered
 * address: 0x021B83A0
 * packet: pkt_ov070_021B83A0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT*: two bytes of zero alignment padding follow at 021B83B6.
 * The original explicitly narrows r1 before 0202E448; its extern uses u16.
 * symbols:
 *   ITEM_GetRegisterFlagId 0x0202E448 thumb
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 */
#include "../include/Obj20669.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 ITEM_GetRegisterFlagId(u32 id);
extern int GAME_DATA_ContainsRecentId(int p, int value);
int ITEMMENU_IsItemRegistered(char *p, int value)
{
    return GAME_DATA_ContainsRecentId(((struct Obj20669 *)p)->f0, (int)ITEM_GetRegisterFlagId((u16)value));
}
