/*
 * unit:     yes
 * address:  0x0201BD28
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201BD28, WAZA_TOOL_GetDataParam
 *
 * waza_tool.c: the cached single-field read of a move record, and the 32 case
 * getter it ends in.
 *
 * sub_0201BD28 finds the move's record in the cache the constructor in
 * src/matched/unit_0201C328.c builds, loading it through func_02048F4C if the
 * slot it picks is empty or is holding a different move, and falls back to
 * the single record buffer at 0x02146534 when the cache has not been built.
 * The slot search, the "cache full, reuse the last slot" fixup and the load
 * are the same three blocks WAZA_TOOL_IsAlwaysHit and WAZA_TOOL_GetRankEffectCount repeat for their
 * own records.
 *
 * WAZA_TOOL_GetDataParam has to stay in this file.  The `bl` at 0x0201BDA6 is the only
 * branch to it anywhere in the image, so split off it would have no witness
 * at all; kept here the site is the `local` class and needs none
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, read the
 * other way round).
 *
 * The getter is an ordinary dense switch: `cmp #0x1F` / `bhi` and a table of
 * 32 signed halfword displacements
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Two things
 * the table says that the C has to repeat exactly:
 *
 *   * entry 29 points at the default body, so id 29 has no case label at all.
 *     It is a gap in the middle of the range and not an empty arm, which is
 *     the distinction docs/idioms/empty-switch-arms-are-what-make-the-table.md
 *     draws;
 *   * the arms are emitted in source order, and that order is not the numeric
 *     order: id 28 is written between 15 and 16, and the three three-way
 *     groups (16, 19, 22), (17, 20, 23) and (18, 21, 24) share one body each.
 *
 * The three grouped bodies index byte arrays at +0x15, +0x18 and +0x1B with a
 * run-time index, so the middle one costs a `movs`/`ldrsb` register-offset
 * pair rather than an immediate load, which is the only thing that says that
 * field is signed (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Ids 4 and 7 answer a substitute value for one particular stored value,
 * 0x64 for 0x65 and 0 for 6; both reach the function's shared `bx lr` with
 * the loaded value still in r0, which is what says the source returns the
 * value in the ordinary path rather than assigning a result variable.
 *
 * symbols:
 *   _pWazaTool   0x02146530  data
 *   _WazaTempData  0x02146534  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BD28.c \
 *       --addr 0x0201BD28 --thumb
 */

#include "../include/G_WazaTool.h"

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Waza {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    s8  unk06;
    u8  lo : 4;
    u8  hi : 4;
    u16 unk08;
    u8  unk0A;
    u8  unk0B;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
    u16 unk10;
    s8  unk12;
    s8  unk13;
    u8  unk14;
    u8  unk15[3];
    s8  unk18[3];
    u8  unk1B[3];
};

extern struct WazaTool *_pWazaTool;
extern struct Waza _WazaTempData;

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);

u32 WAZA_TOOL_GetDataParam(const struct Waza *p, u32 id);

u32 sub_0201BD28(u16 id, u32 field)
{
    struct Waza *rec;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (((u16 *)_pWazaTool->vals)[i] == 0) {
                ((u16 *)_pWazaTool->vals)[i] = id;
                func_02048F4C(_pWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == ((u16 *)_pWazaTool->vals)[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            ((u16 *)_pWazaTool->vals)[i] = id;
            func_02048F4C(_pWazaTool->recs[i], 0x15, id);
        }
        rec = _pWazaTool->recs[i];
    } else {
        rec = &_WazaTempData;
        func_02048F4C(rec, 0x15, id);
    }
    return WAZA_TOOL_GetDataParam(rec, field);
}

u32 WAZA_TOOL_GetDataParam(const struct Waza *p, u32 id)
{
    u32 v;

    switch (id) {
    case 0:  return p->unk00;
    case 1:  return p->unk01;
    case 2:  return p->unk02;
    case 3:  return p->unk03;
    case 4:
        v = p->unk04;
        if (v == 0x65) {
            return 0x64;
        }
        return v;
    case 5:  return p->unk05;
    case 6:  return p->unk06;
    case 7:
        v = p->unk0E;
        if (v == 6) {
            return 0;
        }
        return v;
    case 8:  return p->hi;
    case 9:  return p->lo;
    case 10: return p->unk0F;
    case 11: return p->unk08;
    case 12: return p->unk0A;
    case 13: return p->unk0B;
    case 14: return p->unk0C;
    case 15: return p->unk0D;
    case 28: return p->unk10;
    case 16: case 19: case 22:
        return p->unk15[id - 16];
    case 17: case 20: case 23:
        return p->unk18[id - 17];
    case 18: case 21: case 24:
        return p->unk1B[id - 18];
    case 25:
        if (p->unk12 > 0) {
            return p->unk12;
        }
        return 0;
    case 30:
        if (p->unk12 < 0) {
            return -p->unk12;
        }
        return 0;
    case 26:
        if (p->unk13 > 0) {
            return p->unk13;
        }
        return 0;
    case 31:
        if (p->unk13 < 0) {
            return -p->unk13;
        }
        return 0;
    case 27: return p->unk14;
    }
    return 0;
}
