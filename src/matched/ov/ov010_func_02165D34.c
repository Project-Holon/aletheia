/*
 * function: GAME_BEACON_ACCESSOR_GetTownmapRootZoneId
 * address: 0x02165D34
 * packet: pkt_ov010_02165D34
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Parent-cleared leaf for ov216021BD448 after same-region source/unit/shard
 * and SDK union checks. Coherent ov010 Thumb accessor; ov009 is interior ARM.
 */
struct Bits { unsigned a, b; unsigned low:22; unsigned value:10; };
unsigned short GAME_BEACON_ACCESSOR_GetTownmapRootZoneId(const struct Bits *p) { return p->value; }
