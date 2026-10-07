/*
 * file:     game_beacon_search_p21.c
 * unit:     yes
 * function: func_02165D40, func_02165D48
 * address:  0x02165D40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

struct S_02165D40 {u32 a,b;u32 value:17;u32 rest:15;};

struct S_02165D48 {u32 a;u32 value:17;u32 rest:15;};

u32 func_02165D40(const struct S_02165D40 *p);
u32 func_02165D48(const struct S_02165D48 *p);

/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 8B getter 02165D48, separately owned and filed.
 */
u32 func_02165D40(const struct S_02165D40 *p) { return p->value; }

/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
u32 func_02165D48(const struct S_02165D48 *p) { return p->value; }
