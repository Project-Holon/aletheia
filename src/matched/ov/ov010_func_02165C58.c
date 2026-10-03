/*
 * function: func_02165C58
 * packet: pkt_ov010_02165C58
 * address: 0x02165C58
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 4B getter 02165C5C, separately owned and filed.
 */
typedef unsigned char u8;
u8 func_02165C58(const u8 *p) { return p[1]; }
