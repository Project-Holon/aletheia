/*
 * function: EVENT_POKE_STATUS_ResetFlag
 * address: 0x0215A500
 * packet: pkt_ov010_0215A500
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 * symbols:
 *   ZONEDATA_ResetEventFlag 0x0201433C thumb
 */
typedef unsigned short u16;
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);
void EVENT_POKE_STATUS_ResetFlag(char *a, unsigned b) { ZONEDATA_ResetEventFlag(a, (u16)(b + 1420)); }
