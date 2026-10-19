/*
 * function: BEACON_DETAIL_GetRecordIndex
 * address: 0x02184790
 * packet: pkt_ov219_02184790
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NATION_AREA_FindRecordIndex 0x02025B3C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 NATION_AREA_FindRecordIndex(u32);
u32 BEACON_DETAIL_GetRecordIndex(u32 key){return NATION_AREA_FindRecordIndex(key);}
