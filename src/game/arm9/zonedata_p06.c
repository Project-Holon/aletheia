/*
 * file:     zonedata_p06.c
 * unit:     yes
 * function: func_02013DF0, func_02013E04, func_02013E40, func_02013E4C, func_02013E6C, func_02013E7C, func_02013E90, func_02013EC0, func_02013ECC, func_02013ED8, func_02013EEC, func_02013F2C, func_02013F6C, func_02013FA8, func_02013FD8, func_02013FFC, func_0201400C, func_02014018, func_02014024, func_02014034, func_02014044, func_0201405C, func_02014068, func_0201407C
 * address:  0x02013DF0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02013AD0  0x02013AD0  thumb
 *   sub_02013A94  0x02013A94  thumb
 *   sub_02013CC8  0x02013CC8  thumb
 *   sub_02013CE0  0x02013CE0  thumb
 *   sub_02013D00  0x02013D00  thumb
 *   sub_02013D5C  0x02013D5C  thumb
 *   sub_02013D74  0x02013D74  thumb
 *   func_02013B44  0x02013B44  thumb
 *   g_sub02013AD0Obj2  0x02146264  data
 *   sub_0209DFC8_Map  0x0209DFC8  data
 *   sub_02013B10       0x02013B10  thumb
 *   sub_020140E8  0x020140E8  thumb
 *   func_02020E08  0x02020E08  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub02013AD0Rec_02013DF0 {
    u8 pad00[4];
    u16 unk04;
    u8 pad06[0x14 - 6];
    u16 unk14;
    u16 unk16;
    u16 unk18;
    struct {
        u16 lo10 : 10;
        u16 hi6 : 6;
    } unk1a;
};

struct Sub02013AD0Rec_02013EC0 {
    u8 pad00[0x14];
    u16 unk14;
    u16 unk16;
};

typedef int             s32;

/* the record sub_02013AD0() returns; only the two 5 bit fields at 0x1e
 * that this file reads. */
struct Sub02013AD0Rec_02013ED8 {
    u8  pad00[0x1e];
    u16 lo5 : 5;
    u16 mid5 : 5;
    u16 hi6 : 6;
};

struct Sub02013ED8Pair {
    u16 key;
    u16 val;
};

struct Sub02013ED8Obj {
    u8                        pad00[0x38];
    const struct Sub02013ED8Pair *arr1;    /* 0x38 */
    const struct Sub02013ED8Pair *arr2;    /* 0x3c */
    u16                        count1;      /* 0x40 */
    u8                         count2;      /* 0x42 */
    u8                         count3;      /* 0x43 */
    const struct Sub02013ED8Pair *arr3;    /* 0x44 */
};

struct Ent0209DFC8 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

extern void *sub_02013AD0(u32 id);
extern u16 sub_02013A94(u32 key);
extern u32   sub_02013CC8(u32 id);
extern u32   sub_02013CE0(u32 id);
extern u32   sub_02013D00(u32 id);
extern u32   sub_02013D5C(u32 id);
extern int sub_02013D74(u32 key);
extern u32 func_02013B44(u32 id);
extern u16 func_02013A94(u32 key);
extern u32   sub_02013B10(u32 id, const u16 *table, s32 count);
extern u32 sub_020140E8(u32 index);
extern void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size);
u32 sub_02013DF0(u32 id);
u32 sub_02013E04(u32 id);
u32 sub_02013E40(u32 id);
u32 sub_02013E4C(u32 id);
u32 sub_02013E6C(u32 id);
u32 sub_02013E7C(u32 id);
u32 func_02013E90(u32 a, u32 b);
u32 sub_02013EC0(u32 id);
u32 sub_02013ECC(u32 id);
u8 sub_02013ED8(u32 id);
u32 sub_02013EEC(u32 id);
u32 sub_02013F2C(u32 id);
u32 sub_02013F6C(u32 id);
int func_02013FA8(u16 key);
u8 sub_02013FD8(u32 id);
u32 sub_02013FEC(u32 id);
u32 sub_02013FFC(u32 id);
u32 sub_0201400C(u32 id);
u32 sub_02014018(u32 id);
u32 sub_02014024(u32 id);
u32 sub_02014034(u32 id);
u32 sub_02014044(u32 id);
u8 sub_0201405C(u32 id);
u32 sub_02014068(u32 id);
void *sub_0201407C(u32 heap, u16 index, u32 delta);
extern struct Sub02013ED8Obj *g_sub02013AD0Obj2;
extern struct Ent0209DFC8 sub_0209DFC8_Map[];


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013E6C, sub_02013E7C
 *
 * alias: the last id predicate, sub_02013E04, and three more leaf accessors
 * on the record sub_02013AD0() returns.  sub_02013D74 (a documented near
 * miss, see unit_02013C10.c) is only reached here as an ordinary extern
 * call from sub_02013E04, which does not need sub_02013D74's own body to
 * be attested, only the call to it.
 *
 * sub_02013E04 returns true only when NONE of five predicates
 * (sub_02013CC8, sub_02013CE0, sub_02013D00, sub_02013D5C, sub_02013D74)
 * match, written as the direct disjunction `if (a || b || c || d || e)
 * return 0; return 1;`.  Splitting the disjunction into two `if`s, or
 * writing the same thing as `if (x) return 0;` five times, both changed
 * which comparisons share the shared-exit block with which: this compiler
 * only tail-merges an early `return 0;` across every operand of one `||`
 * expression, and only the last operand gets different codegen (its
 * comparison result stands for the whole expression rather than branching
 * past a shared block), so the five calls have to be one source-level
 * disjunction to reproduce the original's four-shared/one-different shape.
 *
 * The record's halfword at +0x1a is a ten-bit low field and a six-bit high
 * field, the same two-way split as the +0x1c and +0x1e halfwords documented
 * in unit_02013C10.c and unit_02013BA8.c.  sub_02013E4C reads the low field
 * and then substitutes 0x70 for either of the two values immediately above
 * it (0x70 and 0x71): the substitution test adds the POOL CONSTANT 0xff90
 * (-0x70 as an unsigned 16-bit value) rather than subtracting the immediate
 * 0x70, the same non-foldable-immediate shape documented in
 * unit_02013CC8.c for sub_02013CE0 and sub_02013D00.
 *
 * Near miss: sub_02013E90 (0x02013E90 to 0x02013EC0, 48 bytes) reproduces
 * every concrete byte of its first half (the va==vb case) but the two
 * remaining special cases (0 and 0xaf treated as equivalent to each other)
 * compile to a different shared-exit shape than the original under every
 * phrasing tried: two plain `&&` conjunctions, one written as a nested
 * `if`, and both orders of the pair.  It is not in this file; see
 * unit_02013EC0.c for what resumes after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013DF0.c \
 *       --addr 0x02013DF0 --thumb
 */
u32 sub_02013DF0(u32 id)
{
    return sub_02013A94(id) == 0x4e;
}


u32 sub_02013E04(u32 id)
{
    if (sub_02013CC8(id) || sub_02013CE0(id) || sub_02013D00(id) ||
        sub_02013D5C(id) || sub_02013D74(id))
        return 0;
    return 1;
}


u32 sub_02013E40(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    return r->unk18;
}


u32 sub_02013E4C(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    u32 v = r->unk1a.lo10;

    if ((u16)(v + 0xff90) <= 1)
        v = 0x70;
    return v;
}


u32 sub_02013E6C(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    return r->unk1a.hi6;
}


u32 sub_02013E7C(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    return r->unk04 == 0;
}


/*
 * "Do these two zones share a region?": both ids are reduced through
 * func_02013B44, the accessor for record +0x04, and the two results compared.
 * The +0x04 lane is therefore a grouping key rather than a per-zone index,
 * which agrees with the data: 238 distinct values over 427 records.
 *
 * On top of plain equality, 0 and 0xaf are treated as the same group in either
 * order.  That is a hard-coded pair of content constants, not a computed one,
 * and is exactly the kind of value that may differ in White; nothing here
 * reads a version identifier.
 *
 * The equality test is one `if` with its own return, and the special case is a
 * single disjunction afterwards: writing the special case as two separate
 * `if`s gives each its own epilogue instead of the shared one the original
 * has (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013E90.c \
 *       --func func_02013E90 --addr 0x02013E90 --cc 1.1p1 --thumb
 */
u32 func_02013E90(u32 a, u32 b)
{
    u32 ga = func_02013B44(a);
    u32 gb = func_02013B44(b);

    if (ga == gb)
        return 1;
    if ((ga == 0 && gb == 0xaf) || (ga == 0xaf && gb == 0))
        return 1;
    return 0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: the last two leaf accessors on the record sub_02013AD0() returns,
 * and the end of pkt_02013BA8.  sub_02013E90, immediately before this
 * file, is a documented near miss; see unit_02013DF0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013EC0.c \
 *       --addr 0x02013EC0 --thumb
 */
u32 sub_02013EC0(u32 id)
{
    struct Sub02013AD0Rec_02013EC0 *r = sub_02013AD0(id);
    return r->unk14;
}


u32 sub_02013ECC(u32 id)
{
    struct Sub02013AD0Rec_02013EC0 *r = sub_02013AD0(id);
    return r->unk16;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: continues the record-cache family of unit_02013AD0.c and
 * unit_02013BA8.c: every accessor here that calls sub_02013AD0() reads
 * through the same cached record, at offsets not used by those two files.
 * g_sub02013AD0Obj2 is the same cache object (0x02146264) as
 * unit_02013AD0.c's g_sub02013AD0Obj, redeclared here with only the extra
 * fields (0x38..0x43, two of its three small lookup tables and their
 * counts) this file touches; nothing about the two declarations needs to
 * agree byte for byte, only the addresses they claim.
 *
 * The halfword at the cached record's offset 0x1e holds two adjacent 5 bit
 * fields with no gap (bits[0:4] and bits[5:9]); sub_02013ED8 is the
 * accessor for the high one (unit_02014034.c has the low one).
 * sub_02013EEC/F2C/F6C are three independent { key(u16); val(u16) } lookup
 * tables reached through the cache object, differing only in the width of
 * their count field and in their not-found sentinel (0x0FFFFFFF for the
 * first two, 0 for the third).  The third table's array pointer and count
 * sit at offsets 0x44/0x43, immediately after this file's range in the
 * struct, and are declared again in unit_02014034.c.
 *
 * Near miss: sub_02013FA8 (0x02013FA8..0x02013FD8, 48 bytes), a five entry
 * table lookup unrelated to the cache object, reproduces every concrete
 * byte and caps at MATCH: the only pool word anywhere in the image that
 * names its table address is its own, so the honesty rule refuses the
 * witness.  Parked at src/pending/sub_02013FA8.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013ED8.c \
 *       --addr 0x02013ED8 --thumb
 */
u8 sub_02013ED8(u32 id)
{
    struct Sub02013AD0Rec_02013ED8 *r = sub_02013AD0(id);
    return r->mid5;
}


u32 sub_02013EEC(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count1; i++) {
        if (rid == g_sub02013AD0Obj2->arr1[i].key) {
            result = g_sub02013AD0Obj2->arr1[i].val;
            break;
        }
    }
    return result;
}


u32 sub_02013F2C(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count2; i++) {
        if (rid == g_sub02013AD0Obj2->arr2[i].key) {
            result = g_sub02013AD0Obj2->arr2[i].val;
            break;
        }
    }
    return result;
}


u32 sub_02013F6C(u32 id)
{
    u32 result = 0;
    u32 rid;
    s32 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count3; i++) {
        if (rid == g_sub02013AD0Obj2->arr3[i].key) {
            result = g_sub02013AD0Obj2->arr3[i].val;
            break;
        }
    }
    return result;
}


int func_02013FA8(u16 key)
{
    u32 v = func_02013A94(key);
    u32 i;

    for (i = 0; i < 5; i++) {
        if (v == sub_0209DFC8_Map[i].code)
            return sub_0209DFC8_Map[i].kind;
    }
    return 0xffff;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014018, sub_02014024, sub_02014034, sub_02014044,
 *           sub_0201405C, sub_02014068
 *
 * alias: sub_02013FD8 is the low 5 bit accessor of the cache record's
 * offset 0x1e halfword (unit_02013ED8.c has the high one).
 *
 * sub_02013FEC, sub_02013FFC and sub_02014024 are plain tail calls to
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
 * sub_02014034 and sub_02014044 are plain range/equality tests on the raw
 * id (no call to sub_02013AD0).  sub_0201405C is another cache-record
 * accessor, the byte at offset 0x01.  sub_02014068 forwards to the
 * existing sub_02013E40 (unit_02013DF0.c region), an accessor on the same
 * cache record's offset 0x18.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013FD8.c \
 *       --addr 0x02013FD8 --thumb
 */
u8 sub_02013FD8(u32 id)
{
    struct { u8 pad[0x1e]; u16 lo5 : 5; u16 mid5 : 5; u16 hi6 : 6; } *r =
        sub_02013AD0(id);
    return r->lo5;
}


u32 sub_02013FEC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFDC, 8);
}


u32 sub_02013FFC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFB8, 4);
}


u32 sub_0201400C(u32 id)
{
    return id == 0xF6;
}


u32 sub_02014018(u32 id)
{
    return id == 0xF7;
}


u32 sub_02014024(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFD2, 5);
}


u32 sub_02014034(u32 id)
{
    return id >= 0x4C && id <= 0x69;
}


u32 sub_02014044(u32 id)
{
    return id == 0x17A || id == 0x176;
}


u8 sub_0201405C(u32 id)
{
    struct { u8 unk00; u8 unk01; } *r = sub_02013AD0(id);
    return r->unk01;
}


u32 sub_02014068(u32 id)
{
    return sub_02013E40(id) == 0xD6;
}


/*
 * The reader for the raw file a/0/1/3 (archive id 13, the identity-mapped
 * name table entry at 0x020A6C58[13]).  a/0/1/3 is not a NARC: it is a flat
 * 2820-byte file of 282 fixed 10-byte records, so this function does not go
 * through the arc_tool.c member API at all.  It calls func_02020E08, the
 * by-id raw byte-range read (open the whole file by its name-table path,
 * then read `size` bytes at `offset`), with offset = index * 10 and size = 10.
 *
 * Two facts about the domain fall straight out of the code:
 *
 *   - the clamp constant in the pool at 0x020140B0 is 0x11A = 282, exactly
 *     the record count of a/0/1/3, so `index` is a record index;
 *   - sub_020140E8 (already EXACT, src/matched/sub_020140E8.c) answers
 *     "2 <= index < 0xD2", and only for that window is `delta` added.  The
 *     window is 208 records wide, a multiple of four, and the callers pass
 *     the season for `delta`: the file's records 2..209 are four seasonal
 *     variants of 52 base entries and records 210..281 have none.
 *
 * The record index itself comes from the zone table: ov021's fieldmap.c
 * and ov020's event_mapchange.c both call this as
 * sub_0201407C(heap, sub_02013B38(zone_id), season), and sub_02013B38
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
void *sub_0201407C(u32 heap, u16 index, u32 delta)
{
    u16 record = index;

    if (sub_020140E8(index) != 0) {
        record = (u16)(index + (u16)delta);
    }
    if (record >= 282) {
        record = 0;
    }
    return func_02020E08(13, heap, record * 10, 10);
}
