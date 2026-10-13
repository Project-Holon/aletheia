/*
 * function: ZONEDATA_IsRailMap
 * address:  0x02013C70
 * packet:   pkt_02013C70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  data_table - 0x0209E010 is named in the image only by the
 *           pool word inside this eight-byte range, so the `literal`
 *           class has no outside witness and no cut moves one there.
 *           Same finding as src/matched/unit_02013C10.c's header.
 *
 * symbols:
 *   _RailMapZoneTable  0x0209E010  data
 *   ZONEDATA_IsZoneInTable  0x02013B10  thumb
 * Verified with:
 *   python tools/match.py one --src src/pending/ZONEDATA_IsRailMap.c \
 *       --func ZONEDATA_IsRailMap --addr 0x02013C70 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u8   _RailMapZoneTable[];
typedef signed int     s32;
extern u32 ZONEDATA_IsZoneInTable(u32 id, const u16 *table, s32 count);

int ZONEDATA_IsRailMap(u32 a)
{
    return ZONEDATA_IsZoneInTable(a, (const u16 *)_RailMapZoneTable, 0xb);
}
