/*
 * function: EVENT_MAPCHANGE_CopySpecialLocation
 * address: 0x02185F18
 * packet: pkt_ov020_02185F18
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetStartLocation 0x0201284C thumb
 *   ZONEDATA_IsZoneInTableDFDC 0x02013FEC thumb
 *   GAME_DATA_GetSpecialLocation 0x02012894 thumb
 */
typedef struct { int f[7]; } S7;
extern unsigned short *GAME_DATA_GetStartLocation(void *);
typedef unsigned int   u32;
extern u32 ZONEDATA_IsZoneInTableDFDC(u32 id);
extern S7 *GAME_DATA_GetSpecialLocation(void *);
void EVENT_MAPCHANGE_CopySpecialLocation(void *p,S7 *out) { if (ZONEDATA_IsZoneInTableDFDC(GAME_DATA_GetStartLocation(p)[2])) *out=*GAME_DATA_GetSpecialLocation(p); }
