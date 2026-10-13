/*
 * function: INTRUDE_FIELD_FindZonePos
 * address: 0x0217BEA8
 * packet: pkt_ov018_0217BEA8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_FIELD_gZonePositions 0x02182B9C data ov018 a4
 */
typedef unsigned int u32;
typedef struct { u32 x:10; u32 rest:22; u32 y, z; } Entry;
extern Entry INTRUDE_FIELD_gZonePositions[];
Entry *INTRUDE_FIELD_FindZonePos(u32 a) { u32 i; for (i=0; i<218; i++) { if (INTRUDE_FIELD_gZonePositions[i].x == a) return &INTRUDE_FIELD_gZonePositions[i]; } return 0; }
