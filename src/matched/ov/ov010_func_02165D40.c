/*
 * function: func_02165D40
 * packet: pkt_ov010_02165D40
 * address: 0x02165D40
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 8B getter 02165D48, separately owned and filed.
 */
typedef unsigned int u32;
struct S {u32 a,b;u32 value:17;u32 rest:15;};
u32 func_02165D40(const struct S *p) { return p->value; }
