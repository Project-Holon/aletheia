/*
 * function: GAME_BEACON_ACCESSOR_GetThanksCount
 * packet: pkt_ov010_02165D48
 * address: 0x02165D48
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
typedef unsigned int u32;
struct S {u32 a;u32 value:17;u32 rest:15;};
u32 GAME_BEACON_ACCESSOR_GetThanksCount(const struct S *p) { return p->value; }
