/*
 * file:     waza_tool.c
 * unit:     yes
 * function: WAZA_TOOL_GetParam, WAZA_TOOL_GetDataParam, WAZA_TOOL_GetFlag, WAZA_TOOL_GetDataFlag, WAZA_TOOL_GetSickCont, WAZA_TOOL_GetRankEffectCount, WAZA_TOOL_GetRankEffect, WAZA_TOOL_GetMaxPP, WAZA_TOOL_GetWeather, WAZA_TOOL_GetCategory, WAZA_TOOL_GetType, WAZA_TOOL_GetPower, WAZA_TOOL_GetDamageType, WAZA_TOOL_IsAlwaysHit, WAZA_TOOL_IsAlwaysCritical, WAZA_TOOL_IsDamaging, WAZA_TOOL_CreateCache, WAZA_TOOL_DeleteCache, WAZA_TOOL_IsCacheCreated
 * address:  0x0201BD28
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from shinka_check.c by tools/splitfile.py.
 *
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   _pWazaTool   0x02146530  data
 *   _WazaTempData  0x02146534  data
 *   waza_tool_File  0x020A7340  data
 *   STRBUF_SetEosChar  0x020457A0  arm
 *   BMP_Create  0x02043678  arm
 */
#include "pokeparty_shared_types.h"
#include "natsuki_shared_types.h"
#include "waza_tool_shared_types.h"

/* The 0x24 byte move record (waza_tool.c). */
struct WazaData {
    u8  type;
    u8  category;
    u8  damageType;
    u8  power;
    u8  accuracy;
    u8  basePP;
    s8  priority;
    u8  hitMin : 4;
    u8  hitMax : 4;
    u16 sickId;
    u8  sickPercent;
    u8  sickContType;
    u8  sickTurnMin;
    u8  sickTurnMax;
    u8  criticalRank;
    u8  shrinkPercent;
    u16 effectSequence;
    s8  drainRatio;
    s8  healRatio;
    u8  target;
    u8  rankType[3];
    s8  rankValue[3];
    u8  rankPercent[3];
    u8  pad[2];
    u32 flags;
};

/* The move record cache: `count` records and the move id each one holds
 * (0 for an empty slot). */
struct WazaTool {
    struct WazaData **records;
    u16 *moveIds;
    s32 count;
};

/* The packed sick-continuation value WAZA_TOOL_GetSickCont returns. */
union WazaSickCont {
    struct {
        u16 type : 4;
        u16 turnMin : 6;
        u16 turnMax : 6;
    } bits;
    s16 value;
};

extern void  ARC_TOOL_ReadMember(void *dst, u32 arcId, u32 dataId);

extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int fromTail, const char *file, u16 line);

extern u32   GFL_HEAP_Free(void *ptr);

u32 WAZA_TOOL_GetParam(u16 move, u32 param);

u32 WAZA_TOOL_GetDataParam(const struct WazaData *data, u32 param);

u32 WAZA_TOOL_GetFlag(u16 move, u32 flag);

u32 WAZA_TOOL_GetDataFlag(const struct WazaData *data, u32 flag);

s16 WAZA_TOOL_GetSickCont(u16 move);

u8 WAZA_TOOL_GetRankEffectCount(u16 move);

u8 WAZA_TOOL_GetRankEffect(u16 move, u32 index, s32 *value);

u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);

u32 WAZA_TOOL_GetWeather(int item);

u32 WAZA_TOOL_GetCategory(u16 move);

u8 WAZA_TOOL_GetType(u16 move);

u16 WAZA_TOOL_GetPower(u16 move);

int WAZA_TOOL_GetDamageType(u16 move);

u32 WAZA_TOOL_IsAlwaysHit(u16 move);

u32 WAZA_TOOL_IsAlwaysCritical(u16 move);

u32 WAZA_TOOL_IsDamaging(u16 move);

void WAZA_TOOL_CreateCache(s32 count, u32 heap);

void WAZA_TOOL_DeleteCache(void);

u32 WAZA_TOOL_IsCacheCreated(void);

extern struct WazaTool *_pWazaTool;

extern struct WazaData _WazaTempData;

extern const char waza_tool_File[];

/*
 * waza_tool.c: the cached single-field read of a move record, and the 32 case
 * getter it ends in.
 *
 * WAZA_TOOL_GetParam finds the move's record in the cache the constructor in
 * src/matched/unit_0201C328.c builds, loading it through ARC_TOOL_ReadMember if the
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
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BD28.c \
 *       --addr 0x0201BD28 --thumb
 */
u32 WAZA_TOOL_GetParam(u16 move, u32 param)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    return WAZA_TOOL_GetDataParam(data, param);
}

u32 WAZA_TOOL_GetDataParam(const struct WazaData *data, u32 param)
{
    u32 value;

    switch (param) {
    case 0:  return data->type;
    case 1:  return data->category;
    case 2:  return data->damageType;
    case 3:  return data->power;
    case 4:
        value = data->accuracy;
        if (value == 0x65) {
            return 0x64;
        }
        return value;
    case 5:  return data->basePP;
    case 6:  return data->priority;
    case 7:
        value = data->criticalRank;
        if (value == 6) {
            return 0;
        }
        return value;
    case 8:  return data->hitMax;
    case 9:  return data->hitMin;
    case 10: return data->shrinkPercent;
    case 11: return data->sickId;
    case 12: return data->sickPercent;
    case 13: return data->sickContType;
    case 14: return data->sickTurnMin;
    case 15: return data->sickTurnMax;
    case 28: return data->effectSequence;
    case 16: case 19: case 22:
        return data->rankType[param - 16];
    case 17: case 20: case 23:
        return data->rankValue[param - 17];
    case 18: case 21: case 24:
        return data->rankPercent[param - 18];
    case 25:
        if (data->drainRatio > 0) {
            return data->drainRatio;
        }
        return 0;
    case 30:
        if (data->drainRatio < 0) {
            return -data->drainRatio;
        }
        return 0;
    case 26:
        if (data->healRatio > 0) {
            return data->healRatio;
        }
        return 0;
    case 31:
        if (data->healRatio < 0) {
            return -data->healRatio;
        }
        return 0;
    case 27: return data->target;
    }
    return 0;
}

u32 WAZA_TOOL_GetFlag(u16 move, u32 flag)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    return WAZA_TOOL_GetDataFlag(data, flag);
}

u32 WAZA_TOOL_GetDataFlag(const struct WazaData *data, u32 flag)
{
    u32 result = 1;

    if ((data->flags & (1 << flag)) != 0) {
        return result;
    }
    result = 0;
    return result;
}

s16 WAZA_TOOL_GetSickCont(u16 move)
{
    struct WazaData *data;
    s32 i;
    union WazaSickCont cont;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    if (data->sickContType != 0) {
        cont.bits.type = data->sickContType;
        cont.bits.turnMin = data->sickTurnMin;
        cont.bits.turnMax = data->sickTurnMax;
    }
    return cont.value;
}

/*
 * waza_tool.c: two more readers over a move record, each with its own copy of
 * the cache lookup src/matched/unit_0201BD28.c and
 * src/matched/unit_0201C1F4.c also carry.  WAZA_TOOL_GetRankEffectCount counts how many of
 * the three bytes at +0x15 are set; WAZA_TOOL_GetRankEffect hands one of the three
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
u8 WAZA_TOOL_GetRankEffectCount(u16 move)
{
    struct WazaData *data;
    s32 i;
    u32 k;
    u32 rankCount;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    rankCount = 0;
    for (k = 0; k < 3; k++) {
        if (data->rankType[k] != 0) {
            rankCount++;
        }
    }
    return (u8)rankCount;
}

u8 WAZA_TOOL_GetRankEffect(u16 move, u32 index, s32 *value)
{
    struct WazaData *data;
    s32 i;
    u8 rankType;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    rankType = data->rankType[index];
    if (rankType != 0) {
        *value = data->rankValue[index];
    } else {
        *value = 0;
    }
    return rankType;
}

/*
 * waza_tool.c: the effective PP calculation, a four-entry id translation and
 * one more named field read.
 *
 * WAZA_TOOL_GetMaxPP is the function src/pending/POKE_TOOL_GetBoxValueRaw.c's field map calls
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
 * WAZA_TOOL_GetWeather is a sparse four-case switch, which this front end lowers as a
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
 * WAZA_TOOL_GetCategory is an unlabelled tail call, three instructions and two pool
 * words (docs/idioms/tail-call-is-a-pool-word-and-bx.md), reading field 1.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C158.c \
 *       --addr 0x0201C158 --thumb
 */
u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp)
{
    u8 basePP;

    if (ppUp > 3) {
        ppUp = 3;
    }
    basePP = (u8)WAZA_TOOL_GetParam(move, 5);
    return (u8)(basePP + (u8)((int)(ppUp * (basePP * 20)) / 100));
}

u32 WAZA_TOOL_GetWeather(int item)
{
    switch (item) {
    case 0xF0:  return 2;
    case 0xF1:  return 1;
    case 0xC9:  return 4;
    case 0x102: return 3;
    }
    return 0;
}

u32 WAZA_TOOL_GetCategory(u16 move)
{
    return WAZA_TOOL_GetParam(move, 1);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two truncating wrappers around WAZA_TOOL_GetParam (0x0201BD28, still open, a
 * getter dispatched by a small id constant), one narrowing the result to a
 * byte for id 0, the other to a halfword for id 3.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1C8.c \
 *       --addr 0x0201C1C8 --thumb
 */
u8 WAZA_TOOL_GetType(u16 move)
{
    return (u8)WAZA_TOOL_GetParam(move, 0);
}

u16 WAZA_TOOL_GetPower(u16 move)
{
    return (u16)WAZA_TOOL_GetParam(move, 3);
}

/*
 * Tail call with argument 2. Filed as the witness for ov094 BTLV_EFFECT_StartDamageTintTask.
 */
int WAZA_TOOL_GetDamageType(u16 move)
{
    return WAZA_TOOL_GetParam(move, 2);
}

/*
 * waza_tool.c: two predicates over a move record, "is field 4 equal to 0x65"
 * and "is field 0x0E equal to 6", which are the same two special values
 * src/matched/unit_0201BD28.c's getter substitutes for at ids 4 and 7.
 *
 * Both carry their own copy of that file's cache lookup rather than calling
 * it: the slot search, the "cache full, reuse the last slot" fixup, the
 * ARC_TOOL_ReadMember load and the not-yet-built fallback to 0x02146534 are written
 * out again in each.  The duplication is in the source, not an inlining
 * decision: WAZA_TOOL_GetParam is a real function with eight callers, and the
 * bodies here reach the record directly instead of going through its
 * 32 case getter.
 *
 * VERSION SENSITIVITY: 0x65 and 6 are content ids of the move table, not
 * offsets.  They are expected to be identical in Pokemon White but are the
 * constants to re-read first if a White build diverges.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1F4.c \
 *       --addr 0x0201C1F4 --thumb
 */
u32 WAZA_TOOL_IsAlwaysHit(u16 move)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    if (data->accuracy == 0x65) {
        return 1;
    }
    return 0;
}

u32 WAZA_TOOL_IsAlwaysCritical(u16 move)
{
    struct WazaData *data;
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (_pWazaTool->moveIds[i] == 0) {
                _pWazaTool->moveIds[i] = move;
                ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
                break;
            }
            if (move == _pWazaTool->moveIds[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            _pWazaTool->moveIds[i] = move;
            ARC_TOOL_ReadMember(_pWazaTool->records[i], 0x15, move);
        }
        data = _pWazaTool->records[i];
    } else {
        data = &_WazaTempData;
        ARC_TOOL_ReadMember(data, 0x15, move);
    }
    if (data->criticalRank == 6) {
        return 1;
    }
    return 0;
}

/*
 * A boolean wrapper around WAZA_TOOL_GetParam (see src/matched/unit_0201C1C8.c),
 * id 3 again, this time reduced to 0/1 rather than truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C314.c \
 *       --addr 0x0201C314 --thumb
 */
u32 WAZA_TOOL_IsDamaging(u16 move)
{
    if (WAZA_TOOL_GetParam(move, 3) == 0) {
        return 0;
    }
    return 1;
}

/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) PRINTSYS_Init, which resets
 * something with 0xFFFF and hands BMP_Create's result to the static at
 * 0x02146558.  PRINTSYS_Init used to be cut out into src/pending/PRINTSYS_Init.c
 * because its one call, to STRBUF_SetEosChar, had no witness anywhere in the
 * image; STRBUF_SetEosChar is now EXACT in src/matched/STRBUF_SetEosChar.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * WAZA_TOOL_IsCacheCreated is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
void WAZA_TOOL_CreateCache(s32 count, u32 heap)
{
    s32 i;

    if (_pWazaTool != 0) {
        return;
    }
    _pWazaTool = (struct WazaTool *)GFL_HEAP_Alloc(heap, sizeof(struct WazaTool), 0,
                                                waza_tool_File, 577);
    _pWazaTool->records = (struct WazaData **)GFL_HEAP_Alloc(heap, count * sizeof(void *), 0,
                                             waza_tool_File, 578);
    _pWazaTool->moveIds = (u16 *)GFL_HEAP_Alloc(heap, count * sizeof(u16), 0,
                                           waza_tool_File, 579);
    _pWazaTool->count = count;
    for (i = 0; i < count; i++) {
        _pWazaTool->records[i] = GFL_HEAP_Alloc(heap, 0x24, 0, waza_tool_File, 584);
        _pWazaTool->moveIds[i] = 0;
    }
}

void WAZA_TOOL_DeleteCache(void)
{
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            GFL_HEAP_Free(_pWazaTool->records[i]);
        }
        GFL_HEAP_Free(_pWazaTool->moveIds);
        GFL_HEAP_Free(_pWazaTool->records);
        GFL_HEAP_Free(_pWazaTool);
        _pWazaTool = 0;
    }
}

u32 WAZA_TOOL_IsCacheCreated(void)
{
    if (_pWazaTool != 0) {
        return 1;
    }
    return 0;
}
