/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013FD8
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_GetExpObjSetId, ZONEDATA_IsZoneInTableDFDC, ZONEDATA_IsZoneInTableDFB8, ZONEDATA_IsRawZoneF6,
 *           ZONEDATA_IsRawZoneF7, ZONEDATA_IsZoneInTableDFD2, ZONEDATA_IsRawZoneGroup4CTo69, ZONEDATA_IsRawZone176Or17A,
 *           ZONEDATA_GetMapSubType, ZONEDATA_IsParentZoneD6
 *
 * symbols:
 *   ZONEDATA_GetHeader       0x02013AD0  thumb
 *   sub_02013B10       0x02013B10  thumb
 *   ZONEDATA_GetParentZoneId       0x02013E40  thumb
 *
 * alias: ZONEDATA_GetExpObjSetId is the low 5 bit accessor of the cache record's
 * offset 0x1e halfword (unit_02013ED8.c has the high one).
 *
 * ZONEDATA_IsZoneInTableDFDC, ZONEDATA_IsZoneInTableDFB8 and ZONEDATA_IsZoneInTableDFD2 are plain tail calls to
 * sub_02013B10 (unit_02013AD0.c) against three small { key; value } tables
 * of their own (0x0209DFDC/8, 0x0209DFB8/4, 0x0209DFD2/5); mwccarm emits a
 * tail call as a pool word and `bx` even to a function outside the unit
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so each is a function
 * with no prologue, invisible to disasm.py's prologue sweep and printed
 * inside the extent of the labelled accessor at 0x02013FD8.  The pool
 * words that hold sub_02013B10's own address are wildcarded (`literal`
 * class, attested by the same address in unit_02013AD0.c's callers); the
 * table addresses themselves need no attestation, since they are ordinary
 * immediate constants passed by value, not relocated pointers into this
 * range.
 *
 * ZONEDATA_IsRawZoneGroup4CTo69 and ZONEDATA_IsRawZone176Or17A are plain range/equality tests on the raw
 * id (no call to ZONEDATA_GetHeader).  ZONEDATA_GetMapSubType is another cache-record
 * accessor, the byte at offset 0x01.  ZONEDATA_IsParentZoneD6 forwards to the
 * existing ZONEDATA_GetParentZoneId (unit_02013DF0.c region), an accessor on the same
 * cache record's offset 0x18.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013FD8.c \
 *       --addr 0x02013FD8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

extern void *ZONEDATA_GetHeader(u32 id);
extern u32   sub_02013B10(u32 id, const u16 *table, s32 count);
extern u32   ZONEDATA_GetParentZoneId(u32 id);

u8 ZONEDATA_GetExpObjSetId(u32 id)
{
    struct { u8 pad[0x1e]; u16 lo5 : 5; u16 mid5 : 5; u16 hi6 : 6; } *r =
        ZONEDATA_GetHeader(id);
    return r->lo5;
}

u32 ZONEDATA_IsZoneInTableDFDC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFDC, 8);
}

u32 ZONEDATA_IsZoneInTableDFB8(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFB8, 4);
}

u32 ZONEDATA_IsRawZoneF6(u32 id)
{
    return id == 0xF6;
}

u32 ZONEDATA_IsRawZoneF7(u32 id)
{
    return id == 0xF7;
}

u32 ZONEDATA_IsZoneInTableDFD2(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFD2, 5);
}

u32 ZONEDATA_IsRawZoneGroup4CTo69(u32 id)
{
    return id >= 0x4C && id <= 0x69;
}

u32 ZONEDATA_IsRawZone176Or17A(u32 id)
{
    return id == 0x17A || id == 0x176;
}

u8 ZONEDATA_GetMapSubType(u32 id)
{
    struct { u8 unk00; u8 unk01; } *r = ZONEDATA_GetHeader(id);
    return r->unk01;
}

u32 ZONEDATA_IsParentZoneD6(u32 id)
{
    return ZONEDATA_GetParentZoneId(id) == 0xD6;
}
