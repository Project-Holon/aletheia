/*
 * function: BEACON_VIEW_SetEntrySlot
 * address: 0x021F0F30
 * packet: pkt_ov032_021F0F30
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BEACON_VIEW_ResetEntry 0x021F0EDC thumb ov032
 */
extern void BEACON_VIEW_ResetEntry(char *);
void BEACON_VIEW_SetEntrySlot(char *p, int a, int b) { BEACON_VIEW_ResetEntry(p); p[1]=a; p[2]=b; }
