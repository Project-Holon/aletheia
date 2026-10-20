/*
 * file:     shinka_check.c
 * unit:     yes
 * function: SHINKA_CHECK_CheckEvolution, SHINKA_CHECK_OpenHandle, SHINKA_CHECK_GetRowParam, SHINKA_CHECK_LoadData, SHINKA_CHECK_KnowsMove
 * address:  0x0201B2B0
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
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   FILE_UTIL_GetItemParam   0x02020FE4  thumb
 *   TIMEZONE_IsNight   0x02011410  thumb
 *   shinka_check_File 0x020A7330 data  a1
 *   _IceRockZones      0x020A7320  data  a2
 *   _MossRockZones      0x020A7322  data  a2
 *   _MagneticZones      0x020A7324  data  a2
 *   _ExtraEvolutionZones      0x020A732A  data  a2
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   POKEPARTY_HasSpecies 0x0201AC44 thumb arm9
 */
#include "pokeparty_shared_types.h"

/* One evolution: method, its argument (level, item, move, species ...)
 * and the species it evolves into. */
struct EvolutionRow {
    u16 method;
    u16 param;
    u16 species;
};

/* The 0x2C byte evolution record of one species. */
struct EvolutionData {
    struct EvolutionRow rows[7];
    u16 pad;
};

extern void  ARC_TOOL_ReadMember(void *dst, u32 arcId, u32 dataId);

#include "poke_tool.h"

#include "gfl_heap_wrap.h"


extern struct ArcHandle *ARC_TOOL_CreateHandle(unsigned int arcId, unsigned int heap);

extern u32   FILE_UTIL_GetItemParam(u32 item, u32 param, u16 heap);

#include "timezone.h"

extern void  ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 dataId, void *dst);

#include "pokeparty.h"

u32 SHINKA_CHECK_CheckEvolution(struct Party *party, struct PokemonParam *pp, u32 mode, u32 arg, u8 timezone, u32 *methodOut, u16 heap);

struct ArcHandle *SHINKA_CHECK_OpenHandle(u32 heap);

u32 SHINKA_CHECK_GetRowParam(struct ArcHandle *arc, u32 species, u32 rowIndex, u32 field);

void SHINKA_CHECK_LoadData(u32 species, struct EvolutionRow *rows);

u32 SHINKA_CHECK_KnowsMove(struct PokemonParam *pp, u32 move);

extern u8 shinka_check_File[];

extern const u16 _IceRockZones[1];

extern const u16 _MossRockZones[1];

extern const u16 _MagneticZones[3];

extern const u16 _ExtraEvolutionZones[3];

/*
 * note:     wave 18 (2026-09-24): EXACT* (the listing extent includes the
 *           12-byte unlabelled follower at 0x0201B70C, src/matched/
 *           unit_0201B70C.c).  Closed by the heap id's width: the seventh
 *           parameter is a u16 and FILE_UTIL_GetItemParam takes its third argument
 *           as a u16.  With both u32 the gate's `ldr r2, [sp, #0x68]` is
 *           hoisted above the pidHigh store (12 bytes out); u16 on the
 *           parameter alone breaks the size, u16 on both keeps the load
 *           behind the store as in the image.  FILE_UTIL_GetItemParam masks the id to
 *           fifteen bits and ORs in 0x8000 (a temporary-heap id), and
 *           src/matched/unit_02007CB0.c already declares that parameter u16.
 *
 * shinka_check.c (the string at 0x020A7330), the evolution checker: the
 * egg/everstone gate, then the 0x2A-byte evolution record (seven six-byte
 * rows, SHINKA_CHECK_LoadData) walked under a switch on the context (0 level up,
 * 1 trade, 2 and 3 item use); the first row that fires gives the target
 * species and its method goes to *methodOut (method 15 writes 15 and gives
 * no species).  docs/notes/SHINKA_CHECK_CheckEvolution.c.txt holds the method map and the
 * history.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SHINKA_CHECK_CheckEvolution.c \
 *       --func SHINKA_CHECK_CheckEvolution --addr 0x0201B2B0 --cc 1.1p1 --thumb
 */
u32 SHINKA_CHECK_CheckEvolution(struct Party *party, struct PokemonParam *pp, u32 mode, u32 arg,
                 u8 timezone, u32 *methodOut, u16 heap)
{
    u32 unusedMethod;
    u32 attackLess;
    u32 attackEqual;
    u32 attackGreater;
    u32 personality;
    struct EvolutionRow *rows;
    u16 species;
    u16 heldItem;
    u16 friendship;
    u16 personalityHigh;
    u8  level;
    u8  beauty;
    int i;
    u16 result;
    u8  holdEffect;
    struct EvolutionRow *row;
    u32 k;

    result = 0;
    if (POKE_TOOL_GetPartyValue(pp, 0x4C, 0) != 0) {
        return result;
    }
    species = POKE_TOOL_GetPartyValue(pp, 5, 0);
    heldItem = POKE_TOOL_GetPartyValue(pp, 6, 0);
    personality = POKE_TOOL_GetPartyValue(pp, 0, 0);
    beauty = POKE_TOOL_GetPartyValue(pp, 0x14, 0);
    personalityHigh = (personality & 0xFFFF0000) >> 16;
    holdEffect = FILE_UTIL_GetItemParam(heldItem, 1, heap);
    if (species != 0x40 && holdEffect == 0x40 && mode != 3) {
        return result;
    }
    if (methodOut == 0) {
        methodOut = &unusedMethod;
    }
    i = 0;
    rows = GFL_HEAP_Alloc(heap, 0x2A, 0, (const char *)shinka_check_File, 0x6A);
    SHINKA_CHECK_LoadData(species, rows);

    switch (mode) {
    case 0:
        level = POKE_TOOL_GetPartyValue(pp, 0x9E, i);
        friendship = POKE_TOOL_GetPartyValue(pp, 9, i);
        for (i = 0; i < 7; i++) {
            row = &rows[i];
            switch (row->method) {
            case 1:
                if (friendship >= 220) {
                    result = row->species;
                }
                break;
            case 2:
                if (TIMEZONE_IsNight(timezone) == 0 && friendship >= 220) {
                    result = row->species;
                }
                break;
            case 3:
                if (TIMEZONE_IsNight(timezone) == 1 && friendship >= 220) {
                    result = row->species;
                }
                break;
            case 4:
                if (row->param <= level) {
                    result = row->species;
                }
                break;
            case 9:
                if (row->param <= level) {
                    attackGreater = POKE_TOOL_GetPartyValue(pp, 0xA2, 0);
                    if (attackGreater > POKE_TOOL_GetPartyValue(pp, 0xA3, 0)) {
                        result = row->species;
                    }
                }
                break;
            case 10:
                if (row->param <= level) {
                    attackEqual = POKE_TOOL_GetPartyValue(pp, 0xA2, 0);
                    if (attackEqual == POKE_TOOL_GetPartyValue(pp, 0xA3, 0)) {
                        result = row->species;
                    }
                }
                break;
            case 11:
                if (row->param <= level) {
                    attackLess = POKE_TOOL_GetPartyValue(pp, 0xA2, 0);
                    if (attackLess < POKE_TOOL_GetPartyValue(pp, 0xA3, 0)) {
                        result = row->species;
                    }
                }
                break;
            case 12:
                if (row->param <= level && personalityHigh % 10 < 5) {
                    result = row->species;
                }
                break;
            case 13:
                if (row->param <= level && personalityHigh % 10 >= 5) {
                    result = row->species;
                }
                break;
            case 14:
                if (row->param <= level) {
                    result = row->species;
                }
                break;
            case 15:
                *methodOut = 15;
                break;
            case 16:
                if (row->param <= beauty) {
                    result = row->species;
                }
                break;
            case 19:
                if (TIMEZONE_IsNight(timezone) == 0 && heldItem == row->param) {
                    result = row->species;
                }
                break;
            case 20:
                if (TIMEZONE_IsNight(timezone) == 1 && heldItem == row->param) {
                    result = row->species;
                }
                break;
            case 21:
                if (SHINKA_CHECK_KnowsMove(pp, row->param) == 1) {
                    result = row->species;
                }
                break;
            case 22:
                if (party != 0 && POKEPARTY_HasSpecies(party, row->param) == 1) {
                    result = row->species;
                }
                break;
            case 23:
                if (POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 0 && row->param <= level) {
                    result = row->species;
                }
                break;
            case 24:
                if (POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 1 && row->param <= level) {
                    result = row->species;
                }
                break;
            case 25:
                for (k = 0; k < 3; k++) {
                    if (arg == _MagneticZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            case 26:
                for (k = 0; k < 1; k++) {
                    if (arg == _MossRockZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            case 27:
                for (k = 0; k < 1; k++) {
                    if (arg == _IceRockZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            case 28:
                for (k = 0; k < 3; k++) {
                    if (arg == _ExtraEvolutionZones[k]) {
                        result = row->species;
                        break;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            row = &rows[i];
            switch (row->method) {
            case 5:
                result = row->species;
                break;
            case 6:
                if (heldItem == row->param) {
                    result = row->species;
                }
                break;
            case 7:
                if (FILE_UTIL_GetItemParam((u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)arg, 6, 0), 1, heap) != 0x40) {
                    if ((POKE_TOOL_GetPartyValue(pp, 0xAB, 0) == 588
                         && POKE_TOOL_GetPartyValue((struct PokemonParam *)arg, 0xAB, 0) == 616)
                     || (POKE_TOOL_GetPartyValue((struct PokemonParam *)arg, 0xAB, 0) == 588
                         && POKE_TOOL_GetPartyValue(pp, 0xAB, 0) == 616)) {
                        result = row->species;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 2:
    case 3:
        for (i = 0; i < 7; i++) {
            row = &rows[i];
            if (row->method == 8 && arg == row->param) {
                result = row->species;
            }
            if (row->method == 0x11 && POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 0 && arg == row->param) {
                result = row->species;
            }
            if (row->method == 0x12 && POKE_TOOL_GetPartyValue(pp, 0x6E, 0) == 1 && arg == row->param) {
                result = row->species;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    }
    GFL_HEAP_Free(rows);
    return result;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what SHINKA_CHECK_GetRowParam's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   SHINKA_CHECK_KnowsMove's move id range: the four move slots of the
 *          party record, in src/matched/POKE_TOOL_GetPartyValueRaw.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * SHINKA_CHECK_OpenHandle and SHINKA_CHECK_LoadData are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); SHINKA_CHECK_LoadData
 * passes exactly three and is at the limit.
 *
 * SHINKA_CHECK_GetRowParam's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * SHINKA_CHECK_KnowsMove keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
struct ArcHandle *SHINKA_CHECK_OpenHandle(u32 heap)
{
    return ARC_TOOL_CreateHandle(0x13, heap);
}

u32 SHINKA_CHECK_GetRowParam(struct ArcHandle *arc, u32 species, u32 rowIndex, u32 field)
{
    struct EvolutionData data;

    ARC_TOOL_ReadHandleMember(arc, species, &data);
    switch (field) {
    case 0:
        return data.rows[rowIndex].method;
    case 1:
        return data.rows[rowIndex].param;
    case 2:
        return data.rows[rowIndex].species;
    }
    return 0;
}

void SHINKA_CHECK_LoadData(u32 species, struct EvolutionRow *rows)
{
    ARC_TOOL_ReadMember(rows, 0x13, species);
}

u32 SHINKA_CHECK_KnowsMove(struct PokemonParam *pp, u32 move)
{
    u32 found;
    s32 i;

    found = 0;
    for (i = 0x36; i < 0x3A; i++) {
        if (move == POKE_TOOL_GetPartyValue(pp, i, 0)) {
            found = 1;
            break;
        }
    }
    return found;
}
