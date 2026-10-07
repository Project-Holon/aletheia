/*
 * file:     zonedata_p02.c
 * unit:     yes
 * function: func_02013AD0, func_02013B10, func_02013B38, func_02013B44, func_02013B50, func_02013B5C, func_02013B68, func_02013B74, func_02013B90, func_02013BA8, func_02013BBC, func_02013BD0, func_02013BDC, func_02013C10, func_02013C20, func_02013C30, func_02013C40, func_02013C50, func_02013C60
 * address:  0x02013AD0
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
 *   g_sub02013AD0Obj  0x02146264  data
 *   sub_02013A94      0x02013A94  thumb
 *   sub_0204944C      0x0204944C  arm
 */
struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int             s32;

struct Sub02013AD0Rec_02013AD0 {
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
    struct Sub02013AD0Rec_02013AD0  record;
    u16                     cached_id;
};

struct Sub02013AD0Rec_02013BA8 {
    u8 pad00[0x1c];
    struct {
        u16 lo6 : 6;
        u16 mid3 : 3;
        u16 hi7 : 7;
    } unk1c;
    u16 unk1e;
    u16 unk20;
};

struct ZoneRec {
    u8  pad00[0x0c - 0x00];
    u16 conn0c;
    u16 conn0e;
    u16 conn10;
    u16 conn12;
};

struct Sub02013AD0Rec_02013C10 {
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

extern u16 sub_02013A94(u32 key);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
void *sub_02013AD0(u32 id);
u32 sub_02013B10(u32 id, const u16 *table, s32 count);
u32 sub_02013B38(u32 id);
u32 sub_02013B44(u32 id);
u32 sub_02013B50(u32 id);
u32 sub_02013B5C(u32 id);
u32 sub_02013B68(u32 id);
void sub_02013B74(u32 id, u32 *out);
void sub_02013B90(u32 id, u32 *out);
u8 sub_02013BA8(u32 id);
u8 sub_02013BBC(u32 id);
u32 sub_02013BD0(u32 id);
u32 func_02013BDC(u32 id, u32 which);
u32 sub_02013C10(u32 id);
u32 sub_02013C20(u32 id);
u32 sub_02013C30(u32 id);
u32 sub_02013C40(u32 id);
u32 sub_02013C50(u32 id);
u32 sub_02013C60(u32 id);
extern struct Sub02013AD0Outer *g_sub02013AD0Obj;


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013B50, sub_02013B5C, sub_02013B68, sub_02013B74,
 *           sub_02013B90
 *
 * alias: the record-cache accessor every function in unit_02013BA8.c,
 * unit_02013C10.c, unit_02013CC8.c, unit_02013D9C.c, unit_02013DF0.c and
 * unit_02013EC0.c is built on, plus the leaf accessors those files' own
 * declarations of sub_02013B10 and sub_02013B44 point at.
 *
 * sub_02013A94, the id remapper this file calls, is immediately before it
 * and is a documented near miss (see below); it is only reached here as an
 * ordinary extern call, which does not need its body to be attested, only
 * the call to it.
 *
 * g_sub02013AD0Obj is a single cached object (call it P): P+0x00 is the
 * handle sub_0204944C reads records from, P+0x04..0x33 (0x30 bytes) is the
 * cached record every accessor in the other files of this run reads
 * through the pointer sub_02013AD0() returns, and P+0x34 is the id that
 * record was cached for.  sub_02013AD0 reloads the record through
 * sub_0204944C only when the requested id (after remapping through
 * sub_02013A94) does not match the cached one.
 *
 * sub_02013B74 and sub_02013B90 read the same three fields (+0x24, +0x28,
 * +0x2c); sub_02013B74 additionally shifts each left 16 bits, which is an
 * integer-to-Fx32 conversion (multiply by 0x10000) rather than a
 * truncation, since the source field is the full 32-bit word both
 * functions load.
 *
 * Near miss: sub_02013A94 (0x02013A94 to 0x02013AD0, 60 bytes) reproduces
 * every concrete byte but caps at MATCH.  It reads a two-entry { from; to }
 * substitution table at 0x020A72A8; the only other two words in the image
 * that hold that address are themselves data (an unrelated 0x01A80000 in
 * two overlay listings, not a reference to it), so the table has no
 * attestable witness anywhere outside this one function's own pool.  It is
 * not in this file.  What looks like a small version- or form-exclusive id
 * substitution, gated per entry by a two-byte flag array on the same
 * cached object this file's sub_02013AD0 maintains, is worth flagging as
 * possibly version-specific, though nothing at this address range says
 * which meaning it carries.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013AD0.c \
 *       --addr 0x02013AD0 --thumb
 */
void *sub_02013AD0(u32 id)
{
    u32 rid;

    if (g_sub02013AD0Obj == 0)
        return 0;

    rid = sub_02013A94(id);
    if (rid == g_sub02013AD0Obj->cached_id)
        return &g_sub02013AD0Obj->record;

    sub_0204944C(g_sub02013AD0Obj->table, 0, rid * 0x30, 0x30,
                 &g_sub02013AD0Obj->record);
    g_sub02013AD0Obj->cached_id = rid;
    return &g_sub02013AD0Obj->record;
}


u32 sub_02013B10(u32 id, const u16 *table, s32 count)
{
    u32 rid = sub_02013A94(id);
    s32 i;

    for (i = 0; i < count; i++) {
        if (rid == table[i])
            return 1;
    }
    return 0;
}


u32 sub_02013B38(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk02;
}


u32 sub_02013B44(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk04;
}


u32 sub_02013B50(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk00;
}


u32 sub_02013B5C(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk06;
}


u32 sub_02013B68(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk0a;
}


void sub_02013B74(u32 id, u32 *out)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);

    out[0] = r->unk24 << 0x10;
    out[1] = r->unk28 << 0x10;
    out[2] = r->unk2c << 0x10;
}


void sub_02013B90(u32 id, u32 *out)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);

    out[0] = r->unk24;
    out[1] = r->unk28;
    out[2] = r->unk2c;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: three bitfield accessors on the record sub_02013AD0() returns for a
 * given id.  The halfword at +0x1c of that record is split into three
 * bitfields with no gap: bits[0:5] (6 bits, read by the neighbouring
 * sub_02013C10, not in this file), bits[6:8] (3 bits, sub_02013BA8) and
 * bits[9:15] (7 bits, sub_02013BBC).  sub_02013BD0 reads the separate plain
 * halfword at +0x20.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013BA8.c \
 *       --addr 0x02013BA8 --thumb
 */
u8 sub_02013BA8(u32 id)
{
    struct Sub02013AD0Rec_02013BA8 *r = sub_02013AD0(id);
    return r->unk1c.mid3;
}


u8 sub_02013BBC(u32 id)
{
    struct Sub02013AD0Rec_02013BA8 *r = sub_02013AD0(id);
    return r->unk1c.hi7;
}


u32 sub_02013BD0(u32 id)
{
    struct Sub02013AD0Rec_02013BA8 *r = sub_02013AD0(id);
    return r->unk20;
}


/*
 * The only indexed accessor on the zone record: four u16 lanes at record
 * +0x0c, +0x0e, +0x10 and +0x12 selected by a second argument bounded to
 * 0..3, with 0 returned for anything else.  That is what makes those eight
 * bytes one array of four rather than four unrelated fields, and it is the
 * only place in the subsystem where a record field is read by index.
 *
 * The dispatch is the dense PC-relative halfword table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md): the four
 * displacements in the table at 0x02013BF8 are exactly the four `ldrh r4`
 * encodings, so all four case labels existed and none of them is empty.
 *
 * The zero default is initialised before the call to sub_02013AD0, not in a
 * default arm: `movs r4, #0` sits at +0x04, ahead of the `bl`, which is what
 * lets every arm share one `adds r0, r4, #0` exit instead of carrying its own
 * return (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013BDC.c \
 *       --func func_02013BDC --addr 0x02013BDC --cc 1.1p1 --thumb
 */
u32 func_02013BDC(u32 id, u32 which)
{
    u16 v = 0;
    struct ZoneRec *r = sub_02013AD0(id);

    switch (which) {
    case 0:
        v = r->conn0c;
        break;
    case 1:
        v = r->conn0e;
        break;
    case 2:
        v = r->conn10;
        break;
    case 3:
        v = r->conn12;
        break;
    }
    return v;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013C50, sub_02013C60
 *
 * alias: continues the run of leaf accessors on the record sub_02013AD0()
 * returns for a given id.  sub_02013BDC, the dense-switch dispatcher
 * immediately before this range, is a documented near miss and is not in
 * this file; see its header note for why.
 *
 * The record's halfword at +0x1c holds the same three-way bitfield as
 * unit_02013BA8.c (bits[0:5] here, bits[6:8] and bits[9:15] there);
 * sub_02013C10 is the low six bits and needs no narrowing return, unlike its
 * two neighbours there, which return u8 and pick up an extra truncation pair
 * for it.  The halfword at +0x1e is five single-bit flags at bits 10, 12,
 * 13, 14 and 15 (bit 11 has no accessor in this range).
 *
 * Near miss: sub_02013C70, sub_02013C80 and sub_02013C9C (0x02013C70 to
 * 0x02013CC8, 88 bytes) reproduce every concrete byte but cap at MATCH.
 * sub_02013C70 tail calls sub_02013B10 (defined in the neighbouring packet)
 * through a pool word, and also holds a pointer to sub_02013C70_Table
 * (0x0209E010); sub_02013C9C searches sub_02013C9C_Table (0x0209E026).  All
 * three addresses are named in the image only inside this same 88-byte
 * range: the other five images of the sub_02013B10 pointer are themselves
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
u32 sub_02013C10(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1c.lo6;
}


u32 sub_02013C20(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag10;
}


u32 sub_02013C30(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag14;
}


u32 sub_02013C40(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag13;
}


u32 sub_02013C50(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag12;
}


u32 sub_02013C60(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag15;
}
