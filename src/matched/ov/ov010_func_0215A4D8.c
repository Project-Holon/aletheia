/*
 * function: EVENT_POKE_STATUS_CheckFlag
 * address: 0x0215A4D8
 * packet: pkt_ov010_0215A4D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 * symbols:
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 */
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
unsigned EVENT_POKE_STATUS_CheckFlag(void *a, unsigned b) { return ZONEDATA_CheckEventFlag(a, (u16)(b + 1420)); }
