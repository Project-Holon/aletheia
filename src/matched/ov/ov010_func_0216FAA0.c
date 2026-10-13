/*
 * function: WAZA_OSHIE_IsListEntryValid
 * address: 0x0216FAA0
 * packet: pkt_ov010_0216FAA0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
int WAZA_OSHIE_IsListEntryValid(u16 *p) { if (*p != 0xffff) return 1; return 0; }
