/*
 * function: EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather
 * address: 0x021B9AA0
 * packet: pkt_ov092_021B9AA0
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * levers: loop index declared before tier puts j in r2 and tier in r3; omit contested table hint.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   sPickupRollThresholds 0x021B9D44 data a1
 *   sPickupCommonItems 0x021B9D6E data ov092 a2
 *   sPickupRareItems 0x021B9D58 data ov092 a2
 *   sHoneyGatherChance 0x021B9D4D data ov092 a1
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 func_020056EC(u32);
extern const u8 sPickupRollThresholds[];
extern const u16 sPickupCommonItems[];
extern const u16 sPickupRareItems[];
extern const u8 sHoneyGatherChance[];
void EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(void *party)
{
    int i;
    void *mon;
    u16 species,item;
    int ability;
    int random;
    int j;
    u8 tier;
    int threshold;
    int index;
    for (i=0;i<(int)func_0201AA18(party);i++) {
        mon = func_0201AB28(party,i);
        species = POKE_TOOL_GetPartyValue(mon,0xab,0);
        item = POKE_TOOL_GetPartyValue(mon,6,0);
        ability = (u8)POKE_TOOL_GetPartyValue(mon,0xa,0);
        if (ability == 0x35 && species != 0 && species != 0x28a && item == 0 && func_020056EC(10) == 0) {
            random = func_020056EC(100);
            tier = (POKE_TOOL_GetPartyValue(mon,0x9e,0)-1)/10u;
            if (tier >= 10) tier=9;
            for (j=0;j<9;j++) {
                if (sPickupRollThresholds[j] > random) {
                    POKE_TOOL_SetPartyValue(mon,6,sPickupCommonItems[tier+j]);
                    break;
                } else if (random >= 98 && random <= 99) {
                    POKE_TOOL_SetPartyValue(mon,6,sPickupRareItems[tier+(99-random)]);
                    break;
                }
            }
        }
        if (ability == 0x76 && species != 0 && species != 0x28a && item == 0) {
            index=0;
            threshold=10;
            ability=(u8)POKE_TOOL_GetPartyValue(mon,0x9e,0);
            while (threshold < ability) {
                threshold+=10;
                index++;
            }
            if (func_020056EC(100) < sHoneyGatherChance[index]) POKE_TOOL_SetPartyValue(mon,6,0x5e);
        }
    }
}
