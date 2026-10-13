/*
 * function: GAME_BEACON_SEARCH_SetInfoVersionAction
 * address: 0x021652EC
 * packet: pkt_ov010_021652EC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_ResetDetails 0x0202744C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GAME_BEACON_ResetDetails(void *);
typedef struct Obj { u8 pad[3]; u8 lo:7; u8 hi:1; u8 gap[0x2c]; u16 event; } Obj;
void GAME_BEACON_SEARCH_SetInfoVersionAction(Obj *p,u32 v) { p->event=0x12; p->lo=(u8)v; GAME_BEACON_ResetDetails(p); }
