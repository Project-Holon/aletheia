/*
 * function: GAME_BEACON_SEARCH_SetHalfwordValue
 * address: 0x021657B0
 * packet: pkt_ov010_021657B0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_CheckActionPriority 0x02027060 thumb
 *   GAME_BEACON_RequestSend 0x02026FB8 thumb
 *   GAME_BEACON_Work 0x02146940 data
 *   GAME_BEACON_SEARCH_SetInfoHalfwordValue 0x021657D8 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void GAME_BEACON_SEARCH_SetInfoHalfwordValue(void *,u16);
void GAME_BEACON_SEARCH_SetHalfwordValue(u16 v) { if(GAME_BEACON_CheckActionPriority(0x30)) { GAME_BEACON_SEARCH_SetInfoHalfwordValue(GAME_BEACON_Work+4,v); GAME_BEACON_RequestSend(GAME_BEACON_Work+4); } }
