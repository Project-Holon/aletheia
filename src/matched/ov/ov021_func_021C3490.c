/*
 * function: SODATEYA_GetLevelsGained
 * address:  0x021C3490
 * packet:   pkt_ov021_021C3490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 *
 * symbols:
 *   DAYCARE_GetSlotMon  0x0200BC2C  thumb
 *   SODATEYA_GetCurrentLevel  0x021C341C  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern void *DAYCARE_GetSlotMon(void *e, int i);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern int SODATEYA_GetCurrentLevel(u32 *p, u32 b);

int SODATEYA_GetLevelsGained(void **p, int i)
{
    int lv = POKE_TOOL_GetPartyValue(DAYCARE_GetSlotMon(p[2], i), 0x9E, 0);

    return SODATEYA_GetCurrentLevel((u32 *)p, i) - lv;
}
