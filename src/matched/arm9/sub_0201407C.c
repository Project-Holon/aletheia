/*
 * function: sub_0201407C
 * address:  0x0201407C
 * packet:   pkt_0201407C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_IsSeasonArea  0x020140E8  thumb
 *   FILE_UTIL_LoadRange  0x02020E08  thumb
 *
 * The reader for the raw file a/0/1/3 (archive id 13, the identity-mapped
 * name table entry at 0x020A6C58[13]).  a/0/1/3 is not a NARC: it is a flat
 * 2820-byte file of 282 fixed 10-byte records, so this function does not go
 * through the arc_tool.c member API at all.  It calls FILE_UTIL_LoadRange, the
 * by-id raw byte-range read (open the whole file by its name-table path,
 * then read `size` bytes at `offset`), with offset = index * 10 and size = 10.
 *
 * Two facts about the domain fall straight out of the code:
 *
 *   - the clamp constant in the pool at 0x020140B0 is 0x11A = 282, exactly
 *     the record count of a/0/1/3, so `index` is a record index;
 *   - ZONEDATA_IsSeasonArea (already EXACT, src/matched/ZONEDATA_IsSeasonArea.c) answers
 *     "2 <= index < 0xD2", and only for that window is `delta` added.  The
 *     window is 208 records wide, a multiple of four, and the callers pass
 *     the season for `delta`: the file's records 2..209 are four seasonal
 *     variants of 52 base entries and records 210..281 have none.
 *
 * The record index itself comes from the zone table: ov021's fieldmap.c
 * and ov020's event_mapchange.c both call this as
 * sub_0201407C(heap, ZONEDATA_GetAreaId(zone_id), season), and ZONEDATA_GetAreaId
 * (EXACT in src/matched/unit_02013AD0.c) returns the u16 at +2 of the
 * a/0/1/2 zone record.  That field ranges 2..273 over all 427 zones, i.e.
 * it stays inside this function's 282-record clamp.  See the "Archive
 * readers traced by call graph" section of docs/ASSETS.md.
 *
 * The narrowing to u16 is real, not an artefact: `index + delta` is
 * truncated before the clamp, so a caller passing 0xFFFF for delta walks
 * the index backwards rather than off the end of the file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201407C.c \
 *       --func sub_0201407C --addr 0x0201407C --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 ZONEDATA_IsSeasonArea(u32 index);
extern void *FILE_UTIL_LoadRange(u32 archive_id, u32 heap, u32 offset, u32 size);

void *sub_0201407C(u32 heap, u16 index, u32 delta)
{
    u16 record = index;

    if (ZONEDATA_IsSeasonArea(index) != 0) {
        record = (u16)(index + (u16)delta);
    }
    if (record >= 282) {
        record = 0;
    }
    return FILE_UTIL_LoadRange(13, heap, record * 10, 10);
}
