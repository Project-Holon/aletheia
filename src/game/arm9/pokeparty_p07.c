/*
 * file:     pokeparty_p07.c
 * unit:     yes
 * function: func_0201C020, func_0201C0BC, func_0201C158, func_0201C184, func_0201C1BC
 * address:  0x0201C020
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
 *   gWazaTool   0x02146530  data
 *   g_02146534  0x02146534  data
 *   _s32_div_f  0x0209C0A4  arm
 */
typedef unsigned char  u8;

typedef signed char    s8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32;

struct Waza {
    u8  unk00[0x15];
    u8  unk15[3];
    s8  unk18[3];
};

struct WazaTool {
    struct Waza **recs;
    u16 *vals;
    s32 count;
};

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern u32 sub_0201BD28(u16 id, u32 field);
u8 sub_0201C020(u16 id);
u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
u8 sub_0201C158(u16 move, u32 ppUp);
u32 sub_0201C184(int id);
u32 sub_0201C1BC(u16 move);
extern struct WazaTool *gWazaTool;
extern struct Waza g_02146534;


/*
 * waza_tool.c: two more readers over a move record, each with its own copy of
 * the cache lookup src/matched/unit_0201BD28.c and
 * src/matched/unit_0201C1F4.c also carry.  sub_0201C020 counts how many of
 * the three bytes at +0x15 are set; sub_0201C0BC hands one of the three
 * signed bytes at +0x18 back through an out-parameter, or zero when the
 * matching +0x15 byte is clear.
 *
 * The +0x18 read is a `movs`/`ldrsb` register-offset pair because the index
 * is a run-time value and Thumb has no immediate-offset `ldrsb`, which is
 * also the only evidence that the field is signed where its +0x15 neighbour
 * is not (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C020.c  *       --addr 0x0201C020 --thumb
 */
u8 sub_0201C020(u16 id)
{
    struct Waza *rec;
    s32 i;
    u32 k;
    u32 n;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    n = 0;
    for (k = 0; k < 3; k++) {
        if (rec->unk15[k] != 0) {
            n++;
        }
    }
    return (u8)n;
}


u8 sub_0201C0BC(u16 id, u32 idx, s32 *out)
{
    struct Waza *rec;
    s32 i;
    u8 v;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    v = rec->unk15[idx];
    if (v != 0) {
        *out = rec->unk18[idx];
    } else {
        *out = 0;
    }
    return v;
}


/*
 * waza_tool.c: the effective PP calculation, a four-entry id translation and
 * one more named field read.
 *
 * sub_0201C158 is the function src/pending/sub_02018E34.c's field map calls
 * for ids 0x42 to 0x45: base PP (field 5 of the move record, through
 * src/matched/unit_0201BD28.c) plus base * 20 * ppUp / 100, with ppUp clamped
 * to 3 and every intermediate truncated to u8.  The two `muls` are one
 * expression and their order is the source's: the clamped count multiplies
 * the already-scaled base, not the other way round
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The clamp compares unsigned (`bls`) while the division calls _s32_div_f,
 * so the count is an unsigned parameter and the product is cast to `int`
 * before the divide; written unsigned throughout, every concrete byte is
 * still right and the call goes to _u32_div_f instead, which is a different
 * address and a DIFF.
 *
 * sub_0201C184 is a sparse four-case switch, which this front end lowers as a
 * binary search rather than a table: `> 0xF1`, then `< 0xF0`, then the two
 * equality tests.  The bodies are still emitted in source order, so the arms
 * are written 0xF0, 0xF1, 0xC9, 0x102 even though the comparisons are in
 * value order, and the value is signed: the two range tests are `bgt`/`blt`,
 * so the parameter is `int` and not `u32`.  0x102 arrives from a pool word because it is past the 255 a
 * `movs` immediate reaches.
 *
 * VERSION SENSITIVITY: 0xF0, 0xF1, 0xC9 and 0x102 are content ids (moves or
 * items), not offsets.  They are expected to be the same in Pokemon White,
 * which shares Black's numbering, but they are the constants to re-read first
 * if a White build diverges here.
 *
 * sub_0201C1BC is an unlabelled tail call, three instructions and two pool
 * words (docs/idioms/tail-call-is-a-pool-word-and-bx.md), reading field 1.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C158.c \
 *       --addr 0x0201C158 --thumb
 */
u8 sub_0201C158(u16 move, u32 ppUp)
{
    u8 base;

    if (ppUp > 3) {
        ppUp = 3;
    }
    base = (u8)sub_0201BD28(move, 5);
    return (u8)(base + (u8)((int)(ppUp * (base * 20)) / 100));
}


u32 sub_0201C184(int id)
{
    switch (id) {
    case 0xF0:  return 2;
    case 0xF1:  return 1;
    case 0xC9:  return 4;
    case 0x102: return 3;
    }
    return 0;
}


u32 sub_0201C1BC(u16 move)
{
    return sub_0201BD28(move, 1);
}
