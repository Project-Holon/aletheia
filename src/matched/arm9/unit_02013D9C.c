/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013D9C
 * packet:   pkt_02013BA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_IsZoneGroup118To120, ZONEDATA_IsRawZoneGroup121To13C
 *
 * symbols:
 *   ZONEDATA_GetChangedZoneId  0x02013A94  thumb
 *
 * alias: the id-classification predicate started in unit_02013CC8.c, plus
 * one unlabelled leaf immediately after it, read out of the bytes the same
 * way as the ones in unit_0200E884.c: ZONEDATA_IsRawZoneGroup121To13C saves no registers and
 * calls nothing, so disasm.py never gave it a label.  It is the same range
 * check as ZONEDATA_IsZoneGroup118To13C (a documented near miss two functions before this
 * one) but on the RAW id, with no call to ZONEDATA_GetChangedZoneId at all, which is
 * exactly what its lack of a stack frame says.
 *
 * Near miss: 0x02013DD0 to 0x02013DF0 (32 bytes, two more unlabelled leaves)
 * immediately follows and is not in this file.  Both tail call
 * ZONEDATA_IsZoneInTable (defined in the neighbouring packet) through a pool word
 * over a different fixed table (0x0209DFC0 count 4, 0x0209DFEC count 9),
 * the same shape as sub_02013C70 in unit_02013C10.c, and for the same
 * reason: every other place either pointer or table address appears in the
 * image is itself one of these unlabelled thunks rather than a literal pool
 * or a direct call, so neither has an attestable witness outside its own
 * bytes.  ZONEDATA_IsZone4E onward resumes in unit_02013DF0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013D9C.c \
 *       --addr 0x02013D9C --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 ZONEDATA_GetChangedZoneId(u32 key);

u32 ZONEDATA_IsZoneGroup118To120(u32 id)
{
    u32 v = ZONEDATA_GetChangedZoneId(id);

    return v >= 0x118 && v <= 0x120;
}

u32 ZONEDATA_IsRawZoneGroup121To13C(u32 id)
{
    return id >= 0x121 && id <= 0x13c;
}
