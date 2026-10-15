/*
 * function: INTRO_CMD_GetScenarioRow
 * address: 0x021BF094
 * packet: pkt_ov204_021BF094
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIntroScenarioTables 0x021C0AB8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 gIntroScenarioTables[];
void*INTRO_CMD_GetScenarioRow(u32 n){return *(void**)((u32)gIntroScenarioTables+n*4);}
