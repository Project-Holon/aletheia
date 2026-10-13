/*
 * function: GAME_BEACON_ACCESSOR_GetZoneId
 * address: 0x02165D28
 * packet: pkt_ov010_02165D28
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
struct Bits { unsigned a; unsigned low:17; unsigned value:10; unsigned high:5; };
unsigned short GAME_BEACON_ACCESSOR_GetZoneId(const struct Bits *p) { return p->value; }
