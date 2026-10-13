/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013EC0
 * packet:   pkt_02013BA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_GetEncountId, ZONEDATA_GetEventDataId
 *
 * symbols:
 *   ZONEDATA_GetHeader  0x02013AD0  thumb
 *
 * alias: the last two leaf accessors on the record ZONEDATA_GetHeader() returns,
 * and the end of pkt_02013BA8.  sub_02013E90, immediately before this
 * file, is a documented near miss; see unit_02013DF0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013EC0.c \
 *       --addr 0x02013EC0 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ZONEDATA_GetHeader(u32 id);

struct Sub02013AD0Rec {
    u8 pad00[0x14];
    u16 unk14;
    u16 unk16;
};

u32 ZONEDATA_GetEncountId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk14;
}

u32 ZONEDATA_GetEventDataId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk16;
}
