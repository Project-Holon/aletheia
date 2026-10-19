/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013C10
 * packet:   pkt_02013BA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_GetWeatherId, ZONEDATA_IsBikeEnabled, ZONEDATA_IsRideBgmEnabled, ZONEDATA_IsFlyEnabled,
 *           ZONEDATA_IsWeatherEnabled, ZONEDATA_IsPalaceEnabled
 *
 * symbols:
 *   ZONEDATA_GetHeader        0x02013AD0  thumb
 *
 * alias: continues the run of leaf accessors on the record ZONEDATA_GetHeader()
 * returns for a given id.  sub_02013BDC, the dense-switch dispatcher
 * immediately before this range, is a documented near miss and is not in
 * this file; see its header note for why.
 *
 * The record's halfword at +0x1c holds the same three-way bitfield as
 * unit_02013BA8.c (bits[0:5] here, bits[6:8] and bits[9:15] there);
 * ZONEDATA_GetWeatherId is the low six bits and needs no narrowing return, unlike its
 * two neighbours there, which return u8 and pick up an extra truncation pair
 * for it.  The halfword at +0x1e is five single-bit flags at bits 10, 12,
 * 13, 14 and 15 (bit 11 has no accessor in this range).
 *
 * Near miss: sub_02013C70, sub_02013C80 and sub_02013C9C (0x02013C70 to
 * 0x02013CC8, 88 bytes) reproduce every concrete byte but cap at MATCH.
 * sub_02013C70 tail calls ZONEDATA_IsZoneInTable (defined in the neighbouring packet)
 * through a pool word, and also holds a pointer to sub_02013C70_Table
 * (0x0209E010); sub_02013C9C searches sub_02013C9C_Table (0x0209E026).  All
 * three addresses are named in the image only inside this same 88-byte
 * range: the other five images of the ZONEDATA_IsZoneInTable pointer are themselves
 * unlabelled leaf thunks (data words, not literal pools, in the same
 * function's neighbourhood further down this file), sub_02013C9C's only
 * caller anywhere is sub_02013C80 one function above it, and neither table
 * is referenced from anywhere else at all.  No cut of this file moves any
 * of those three witnesses outside the range that needs them, so this is
 * the "only caller in the ROM" case from docs/MATCHING.md rather than
 * anything a rewrite of the C would fix.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013C10.c \
 *       --addr 0x02013C10 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ZONEDATA_GetHeader(u32 id);

struct Sub02013AD0Rec {
    u8 pad00[0x1c];
    struct {
        u16 lo6 : 6;
        u16 mid3 : 3;
        u16 hi7 : 7;
    } unk1c;
    struct {
        u16 pad0 : 10;
        u16 flag10 : 1;
        u16 pad11 : 1;
        u16 flag12 : 1;
        u16 flag13 : 1;
        u16 flag14 : 1;
        u16 flag15 : 1;
    } unk1e;
};

u32 ZONEDATA_GetWeatherId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1c.lo6;
}

u32 ZONEDATA_IsBikeEnabled(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1e.flag10;
}

u32 ZONEDATA_IsRideBgmEnabled(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1e.flag14;
}

u32 ZONEDATA_IsFlyEnabled(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1e.flag13;
}

u32 ZONEDATA_IsWeatherEnabled(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1e.flag12;
}

u32 ZONEDATA_IsPalaceEnabled(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1e.flag15;
}
