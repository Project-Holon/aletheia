/*
 * function: BTL_POKEPARAM_GetMaxLevelExp
 * address: 0x021D6B6C
 * packet: pkt_ov093_021D6B6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 */
#include "../include/Obj13443.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetExpForLevel(u16,u16,u16);
u32 BTL_POKEPARAM_GetMaxLevelExp(u8 *p) { return POKE_TOOL_GetExpForLevel(((struct Obj13443 *)p)->fC,p[0x141],100); }
