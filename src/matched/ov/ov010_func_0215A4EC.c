/*
 * function: EVENT_TRAINER_SetDefeatedFlag
 * address: 0x0215A4EC
 * packet: pkt_ov010_0215A4EC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 * symbols:
 *   ZONEDATA_SetEventFlag 0x02014314 thumb
 */
typedef unsigned short u16;
extern void ZONEDATA_SetEventFlag(char *a0, int a1);
void EVENT_TRAINER_SetDefeatedFlag(char *a, unsigned b) { ZONEDATA_SetEventFlag(a, (u16)(b + 1420)); }
