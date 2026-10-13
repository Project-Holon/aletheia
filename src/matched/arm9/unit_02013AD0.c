/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013AD0
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_GetHeader, ZONEDATA_IsZoneInTable, ZONEDATA_GetAreaId, ZONEDATA_GetMatrixId,
 *           ZONEDATA_GetMapType, ZONEDATA_GetScriptArcId, ZONEDATA_GetMsgArcId, ZONEDATA_GetStartPos,
 *           ZONEDATA_GetStartRailPos
 *
 * symbols:
 *   g_ZoneDataMgr  0x02146264  data
 *   ZONEDATA_GetChangedZoneId      0x02013A94  thumb
 *   sub_0204944C      0x0204944C  arm
 *
 * alias: the record-cache accessor every function in unit_02013BA8.c,
 * unit_02013C10.c, unit_02013CC8.c, unit_02013D9C.c, unit_02013DF0.c and
 * unit_02013EC0.c is built on, plus the leaf accessors those files' own
 * declarations of ZONEDATA_IsZoneInTable and ZONEDATA_GetMatrixId point at.
 *
 * ZONEDATA_GetChangedZoneId, the id remapper this file calls, is immediately before it
 * and is a documented near miss (see below); it is only reached here as an
 * ordinary extern call, which does not need its body to be attested, only
 * the call to it.
 *
 * g_ZoneDataMgr is a single cached object (call it P): P+0x00 is the
 * handle sub_0204944C reads records from, P+0x04..0x33 (0x30 bytes) is the
 * cached record every accessor in the other files of this run reads
 * through the pointer ZONEDATA_GetHeader() returns, and P+0x34 is the id that
 * record was cached for.  ZONEDATA_GetHeader reloads the record through
 * sub_0204944C only when the requested id (after remapping through
 * ZONEDATA_GetChangedZoneId) does not match the cached one.
 *
 * ZONEDATA_GetStartPos and ZONEDATA_GetStartRailPos read the same three fields (+0x24, +0x28,
 * +0x2c); ZONEDATA_GetStartPos additionally shifts each left 16 bits, which is an
 * integer-to-Fx32 conversion (multiply by 0x10000) rather than a
 * truncation, since the source field is the full 32-bit word both
 * functions load.
 *
 * Near miss: ZONEDATA_GetChangedZoneId (0x02013A94 to 0x02013AD0, 60 bytes) reproduces
 * every concrete byte but caps at MATCH.  It reads a two-entry { from; to }
 * substitution table at 0x020A72A8; the only other two words in the image
 * that hold that address are themselves data (an unrelated 0x01A80000 in
 * two overlay listings, not a reference to it), so the table has no
 * attestable witness anywhere outside this one function's own pool.  It is
 * not in this file.  What looks like a small version- or form-exclusive id
 * substitution, gated per entry by a two-byte flag array on the same
 * cached object this file's ZONEDATA_GetHeader maintains, is worth flagging as
 * possibly version-specific, though nothing at this address range says
 * which meaning it carries.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013AD0.c \
 *       --addr 0x02013AD0 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

struct Sub02013AD0Rec {
    u8  unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u8  pad08[0x0a - 0x08];
    u16 unk0a;
    u8  pad0c[0x24 - 0x0c];
    u32 unk24;
    u32 unk28;
    u32 unk2c;
};

struct Sub02013AD0Outer {
    void                   *table;
    struct Sub02013AD0Rec  record;
    u16                     cached_id;
};

extern struct Sub02013AD0Outer *g_ZoneDataMgr;
struct ArcFile;
extern u16 ZONEDATA_GetChangedZoneId(u32 key);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);

void *ZONEDATA_GetHeader(u32 id)
{
    u32 rid;

    if (g_ZoneDataMgr == 0)
        return 0;

    rid = ZONEDATA_GetChangedZoneId(id);
    if (rid == g_ZoneDataMgr->cached_id)
        return &g_ZoneDataMgr->record;

    sub_0204944C(g_ZoneDataMgr->table, 0, rid * 0x30, 0x30,
                 &g_ZoneDataMgr->record);
    g_ZoneDataMgr->cached_id = rid;
    return &g_ZoneDataMgr->record;
}

u32 ZONEDATA_IsZoneInTable(u32 id, const u16 *table, s32 count)
{
    u32 rid = ZONEDATA_GetChangedZoneId(id);
    s32 i;

    for (i = 0; i < count; i++) {
        if (rid == table[i])
            return 1;
    }
    return 0;
}

u32 ZONEDATA_GetAreaId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk02;
}

u32 ZONEDATA_GetMatrixId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk04;
}

u32 ZONEDATA_GetMapType(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk00;
}

u32 ZONEDATA_GetScriptArcId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk06;
}

u32 ZONEDATA_GetMsgArcId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk0a;
}

void ZONEDATA_GetStartPos(u32 id, u32 *out)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);

    out[0] = r->unk24 << 0x10;
    out[1] = r->unk28 << 0x10;
    out[2] = r->unk2c << 0x10;
}

void ZONEDATA_GetStartRailPos(u32 id, u32 *out)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);

    out[0] = r->unk24;
    out[1] = r->unk28;
    out[2] = r->unk2c;
}
