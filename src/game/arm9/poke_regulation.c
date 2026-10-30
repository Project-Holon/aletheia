/*
 * file:     poke_regulation.c
 * unit:     yes
 * function: POKE_REGULATION_IsInSpeciesTable, POKE_REGULATION_CheckPokemon, POKE_REGULATION_CheckSelection, POKE_REGULATION_CheckPartyUsable, POKE_REGULATION_CheckPokemonFlags, POKE_REGULATION_CheckParty, POKE_REGULATION_AdjustLevel, POKE_REGULATION_AdjustPartyLevels, POKE_REGULATION_ResetPartyNicknames, POKE_REGULATION_Load, POKE_REGULATION_LoadInto, POKE_REGULATION_BuildPartySizeLine, POKE_REGULATION_BuildLevelLine, POKE_REGULATION_GetBannedSpeciesLine, POKE_REGULATION_GetSpeciesClauseLine, POKE_REGULATION_GetItemClauseLine, POKE_REGULATION_GetBattleModeLine, POKE_REGULATION_CreateText, POKE_REGULATION_DeleteText, POKE_REGULATION_FindValidOrder, POKE_REGULATION_CheckOrder, POKE_REGULATION_NextOrder, POKE_REGULATION_GetDataSize
 * address:  0x02019D84
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from poke_regulation.c by tools/splitfile.py.
 *
 * symbols:
 *   poke_regulation_File 0x020A72F0 data
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   d_0209E42C 0x0209E42C data a2
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *   REGULATION_GetVetoBit   0x0200AFD4  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_GetBattleReadyCount   0x0201AA50  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   WORDSET_SetSlotNumber   0x0201EFA4  thumb
 *   STRBUF_Create   0x020457B0  arm
 *   MSGDATA_ReadString   0x02045CAC  arm
 *   WORDSET_CopyTaggedText   0x0201F250  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   STRBUF_Delete 0x02045808  arm
 *   MSGDATA_CreateFromArchive 0x02045B38  arm
 *   POKE_REGULATION_LineFns  0x0209E444  data
 *   MSGDATA_Delete   0x02045C04  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   POKE_REGULATION_InitialOrder      0x0209E424  data
 *   POKE_TOOL_SetDefaultName 0x02019B58 thumb arm9
 *   POKE_TOOL_SetLevelAndRecalc 0x02019CA0 thumb arm9
 */
#include "poke_tool_shared_types.h"

struct Party;

struct WordSet;

struct Strbuf;

#include "../types.h"
#include "../version.h"

#include "regulation_types.h"

/* Regulation summary: the message bank, one label and one rule line per
 * entry, and the battle mode used to pick the last line. */
struct RegulationText {
    struct MsgBank *bank;
    struct Strbuf  *labels[6];
    struct Strbuf  *lines[6];
    u8              battleMode;
};

/* Builds one rule line: (regulation, word set, text, scratch, heap). */
typedef struct Strbuf *(*RegulationLineFn)(const struct Regulation *, struct WordSet *,
                                           struct RegulationText *, struct Strbuf *, u16);

struct PokemonParam;

#include "poke_tool.h"

#include "regulation.h"


#include "pokeparty.h"

#include "mi_memory.h"



#ifdef __MWERKS__
extern void *ARC_TOOL_LoadMember(unsigned int archiveId, unsigned int memberId, unsigned int heapId); /* original prototype; the definition differs in argument width */
#else
#include "arc_tool.h"
#endif

#include "wordset.h"

#include "strbuf.h"

#include "msgdata.h"



#include "gfl_heap_wrap.h"







int POKE_REGULATION_IsInSpeciesTable(unsigned short species);

int POKE_REGULATION_CheckPokemon(const struct Regulation *reg, struct Pokemon *mon);

int POKE_REGULATION_CheckSelection(struct Regulation *reg, struct Party *party, u8 *order);

int POKE_REGULATION_CheckPartyUsable(const struct Regulation *reg, struct Party *party);

int POKE_REGULATION_CheckPokemonFlags(const struct Regulation *reg, struct Pokemon *mon, u32 *flags);

int POKE_REGULATION_CheckParty(const struct Regulation *reg, struct Party *party, u32 *flags);

u32 POKE_REGULATION_AdjustLevel(const struct Regulation *reg, u32 level);

void POKE_REGULATION_AdjustPartyLevels(const struct Regulation *reg, struct Party *party);

void POKE_REGULATION_ResetPartyNicknames(const struct Regulation *reg, struct Party *party, u32 unused);

void *POKE_REGULATION_Load(int memberId, int heapId);

void POKE_REGULATION_LoadInto(int memberId, void *dst);

struct Strbuf *POKE_REGULATION_BuildPartySizeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);

struct Strbuf *POKE_REGULATION_BuildLevelLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);

struct Strbuf *POKE_REGULATION_GetBannedSpeciesLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);

struct Strbuf *POKE_REGULATION_GetSpeciesClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);

struct Strbuf *POKE_REGULATION_GetItemClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);

struct Strbuf *POKE_REGULATION_GetBattleModeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);

struct RegulationText *POKE_REGULATION_CreateText(const struct Regulation *reg, struct WordSet *wordSet, u16 heapId, u32 battleMode);

void POKE_REGULATION_DeleteText(struct RegulationText *text);

int POKE_REGULATION_FindValidOrder(const struct Regulation *reg, struct Party *party, char *picked);

int POKE_REGULATION_CheckOrder(const struct Regulation *reg, struct Party *party, u8 *order, char *picked, u32 *flags);

int POKE_REGULATION_NextOrder(u8 *order);

int POKE_REGULATION_GetDataSize(void);

extern const char poke_regulation_File[];

extern const unsigned short d_0209E42C[];

extern RegulationLineFn POKE_REGULATION_LineFns[6];

extern const u8 POKE_REGULATION_InitialOrder[6];

/*
 * Witness leaf for ov119 POKETRADE_PROC_CanTradeMon: membership test in a 12 entry u16 table.
 */
int POKE_REGULATION_IsInSpeciesTable(unsigned short species)
{
    unsigned i;
    for (i = 0; i < 12; i++) {
        if (species == d_0209E42C[i])
            return 1;
    }
    return 0;
}

/*
 * A stat comparison against a threshold picked by selector 4 of the first
 * argument: selector 5 (one over the limit) and 6 (under it) are both
 * rejected with 2, and the tail reports 0x20 for the presence flag, 4 or
 * 0x40 for the two range checks, and 1 when there is no object at all.  The
 * two comparisons are signed, which is what `ble`/`bge` says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPokemon.c \
 *       --func POKE_REGULATION_CheckPokemon --addr 0x02019DA4 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckPokemon(const struct Regulation *reg, struct Pokemon *mon)
{
    u16 species = (u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0);
    u16 item = (u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 6, 0);
    int levelLimit;
    int levelRule;
    int level;
    int reason;

    if (reg == 0)
        return 1;

    levelLimit = REGULATION_GetRuleValue(reg, 4);
    levelRule = REGULATION_GetRuleValue(reg, 5);
    level = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9E, 0);

    switch (levelRule) {
    case 1:
        if (levelLimit > level)
            return 2;
        break;
    case 2:
        if (levelLimit < level)
            return 2;
        break;
    }

    reason = 0;
    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x4C, 0) != 0)
        return 0x20;
    if (REGULATION_GetVetoBit(reg, 9, species) != 0)
        return 4;
    if (REGULATION_GetVetoBit(reg, 0xA, item) != 0)
        reason = 0x40;
    return reason;
}

/*
 * Maps a flag word to a small code: the four bits 2, 4, 0x20 and 0x40 all
 * answer 5 (one disjunction, so they share a single exit), then 8, 0x10,
 * 0x100, 0x80 and 1 each answer their own code and zero answers 0.  The
 * query is answered through two stack words whose addresses are passed to
 * POKE_REGULATION_CheckOrder, and the caller's second and third registers are forwarded
 * unchanged, so the query takes five arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckSelection.c \
 *       --func POKE_REGULATION_CheckSelection --addr 0x02019E54 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckSelection(struct Regulation *reg, struct Party *party, u8 *order)
{
    u64 picked;
    u32 flags;

    if (reg == 0)
        return 0;

    POKE_REGULATION_CheckOrder(reg, party, order, (char *)(&picked), &flags);
    if (flags == 0)
        return 0;

    if ((flags & 2) || (flags & 4) || (flags & 0x20) || (flags & 0x40))
        return 5;
    if (flags & 8)
        return 2;
    if (flags & 0x10)
        return 3;
    if (flags & 0x100)
        return 1;
    if (flags & 0x80)
        return 7;
    if (flags & 1)
        return 4;
    return 0;
}

/*
 * EXACT*: the inferred extent runs 2 bytes past the 250-byte body because the
 * follower at 0x02019FD0 has no lr-saving prologue and so carries no label.
 * No byte differs.
 *
 * The party "is this team legal for the rule set" check.  It reads each
 * member's species (id 5) and form (id 0x9E) into two parallel u16[6] stack
 * arrays, zeroes the species of any member POKE_REGULATION_CheckPokemon rejects, then runs an
 * O(n^2) duplicate-species scan that zeroes the worse of each colliding pair
 * (worse = the larger form value) and decrements a running count.  If the
 * surviving count is below what REGULATION_GetRuleValue(ctx, 2) requires it answers 4;
 * otherwise the answer is 0 or 1 from POKE_REGULATION_FindValidOrder.
 *
 * Two layout tells pin the frame:
 *   - the 12-byte MI_CpuFill8 buffer is declared LAST, not first: the later
 *     declarator gets the lower stack address, which is what puts `pad` at
 *     sp+0x10 and `species` at sp+0x28
 *     (docs/idioms/local-declaration-order-is-stack-order.md).
 *   - the outer scan loop assigns its counter before its bound (`i = 0;`
 *     then `lim = n - 1;`), or the `movs r0,#0` and the `subs r0,r0,#1`
 *     swap places
 *     (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * VERSION SENSITIVITY: party ids 5 and 0x9E and the rule-set keys 7 and 2 are
 * content numbering; the team size 6 is the array bound and is structural.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPartyUsable.c \
 *       --func POKE_REGULATION_CheckPartyUsable --addr 0x02019ED4 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckPartyUsable(const struct Regulation *reg, struct Party *party)
{
    u16 species[6];
    u16 levels[6];
    u8 unused[12];
    int partyCount;
    int usable;
    int i;
    int j;
    int last;
    int result;

    partyCount = POKEPARTY_GetCount(party);
    usable = partyCount;
    MI_CpuFill8(unused, 0, 12);
    for (i = 0; i < partyCount; i++) {
        struct Pokemon *mon = (struct Pokemon *)POKEPARTY_GetMember(party, i);

        species[i] = (u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0);
        levels[i] = (u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9E, 0);
        if (POKE_REGULATION_CheckPokemon(reg, mon) != 0) {
            species[i] = 0;
            usable--;
        }
    }

    if ((int)REGULATION_GetRuleValue(reg, 7) == 0 && partyCount > 1) {
        i = 0;
        last = partyCount - 1;
        for (; i < last; i++) {
            for (j = i + 1; j < partyCount; j++) {
                if (species[i] == species[j] && species[i] != 0) {
                    if (levels[i] > levels[j]) {
                        species[i] = 0;
                    } else {
                        species[j] = 0;
                    }
                    usable--;
                }
            }
        }
    }

    if (usable < (int)REGULATION_GetRuleValue(reg, 2)) {
        return 4;
    }

    result = 0;
    if (POKE_REGULATION_FindValidOrder(reg, party, 0) != 1) {
        result = 1;
    }
    return result;
}

/*
 * EXACT* note: the 190 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A08E before the next labelled function at 0x0201A090.
 *
 * The same stat comparison as POKE_REGULATION_CheckPokemon, but it reports into the third
 * argument's word with or-bits instead of returning a code: bit 1 for a
 * selector 5 record above the threshold or a selector 6 one below it, bit 2
 * for the range check, bit 6 for the second one, and the return value stays 1
 * unless a bit was set.  The `*a2 |= 2; r = 0;` pair is written out in both
 * arms and the compiler cross-jumps them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPokemonFlags.c \
 *       --func POKE_REGULATION_CheckPokemonFlags --addr 0x02019FD0 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckPokemonFlags(const struct Regulation *reg, struct Pokemon *mon, u32 *flags)
{
    u16 species = (u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0);
    u16 item = (u16)POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 6, 0);
    int allowed = 1;
    int levelLimit;
    int levelRule;
    int level;

    if (reg == 0)
        return allowed;

    levelLimit = REGULATION_GetRuleValue(reg, 4);
    levelRule = REGULATION_GetRuleValue(reg, 5);
    level = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9E, 0);

    switch (levelRule) {
    case 1:
        if (levelLimit > level) {
            allowed = 0;
            *flags |= 2;
        }
        break;
    case 2:
        if (levelLimit < level) {
            allowed = 0;
            *flags |= 2;
        }
        break;
    }

    if (REGULATION_GetVetoBit(reg, 9, species) != 0) {
        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x4C, 0) == 0) {
            allowed = 0;
            *flags |= 4;
        }
    }
    if (REGULATION_GetVetoBit(reg, 0xA, item) != 0) {
        allowed = 0;
        *flags |= 0x40;
    }
    return allowed;
}

/*
 * poke_tool.c (wave 13): the party legality check against a rule set.
 * Three parallel six-entry u16 arrays (species, item, form) are collected
 * from the non-egg members; the rule set's queries 2 (minimum count),
 * 7 (duplicate species allowed), 8 (duplicate items allowed) and 0xB/0xC (a
 * required species/form) set bits 0x01/0x08/0x10/0x80 of *mask and the
 * error codes 4/2/3/7, a failing member check gives 5, and when nothing
 * failed POKE_REGULATION_FindValidOrder decides between 0 and 1.
 *
 * WHAT CLOSED IT (docs/notes/POKE_REGULATION_CheckParty.c.txt: 478 against 476, err
 * spilled to sp+8 with a six-register push): the arrays are indexed plainly,
 * `species[i]` -- the note's invented `j = i * 2; species[j >> 1]` was the
 * source of the `lsls/bics` fixups; the compiler itself CSEs `i * 2` into
 * the sp+8 slot.  Then the permuter (hill, one mutation) found the last
 * lever: in the duplicate-item test the mask update comes BEFORE the error
 * code (`*mask |= 0x10; err = 3;`), the opposite of the species test.  That
 * order is what keeps err in r7 for the whole function.
 *
 * EXACT* only because of the two-byte alignment pad at 0x0201A26A; the
 * follower 0x0201A26C is its own labelled EXACT entry.
 */
int POKE_REGULATION_CheckParty(const struct Regulation *reg, struct Party *party, u32 *flags)
{
    u16 species[6];
    u16 item[6];
    u16 levels[6];
    int i;
    int total;
    int levelSum;
    int error;
    struct Pokemon *mon;
    int k;
    int requiredSpecies, requiredForm;

    levelSum = 0;
    error = 0;
    if (reg == 0)
        return 0;
    for (i = 0; i < 6; i++) {
        species[i] = 0;
        levels[i] = 0;
        item[i] = 0;
    }
    total = POKEPARTY_GetBattleReadyCount(party);
    if (total < (int)REGULATION_GetRuleValue(reg, 2)) {
        *flags |= 1;
        error = 4;
    }
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = (struct Pokemon *)POKEPARTY_GetMember(party, i);
        if (POKE_REGULATION_CheckPokemonFlags(reg, mon, flags) == 0)
            error = 5;
        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x4c, 0) == 0) {
            species[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0);
            item[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 6, 0);
            levels[i] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x6f, 0);
            levelSum += POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9e, 0);
        }
    }
    if ((int)REGULATION_GetRuleValue(reg, 7) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (species[i] == species[k] && species[i] != 0) {
                    error = 2;
                    *flags |= 8;
                }
            }
        }
    }
    if ((int)REGULATION_GetRuleValue(reg, 8) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (item[i] == item[k] && species[i] != 0 && item[i] != 0) {
                    *flags |= 0x10;
                    error = 3;
                }
            }
        }
    }
    requiredSpecies = (int)REGULATION_GetRuleValue(reg, 0xb);
    requiredForm = (int)REGULATION_GetRuleValue(reg, 0xc);
    i = 0;
    if (requiredSpecies != 0 && total > 1) {
        for (i = 0; i < 6; i++) {
            if (requiredSpecies == species[i] && requiredForm == levels[i])
                break;
        }
    }
    if (i == 6) {
        *flags |= 0x80;
        error = 7;
    }
    if (error == 0 && POKE_REGULATION_FindValidOrder(reg, party, 0) == 0)
        error = 1;
    return error;
}

/*
 * Picks the smaller (or larger, per selector 5) of a value read from the
 * object and the caller's second argument, with the selector 3 / 4 / 5 arms
 * emitted as a compare chain and the default falling through to the caller's
 * value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_AdjustLevel.c \
 *       --func POKE_REGULATION_AdjustLevel --addr 0x0201A26C --cc 1.1p1 --thumb
 */
u32 POKE_REGULATION_AdjustLevel(const struct Regulation *reg, u32 level)
{
    u32 levelValue = REGULATION_GetRuleValue(reg, 4);
    u32 levelRule = REGULATION_GetRuleValue(reg, 5);

    switch (levelRule) {
    case 3:
        if (level > levelValue)
            return levelValue;
        break;
    case 4:
        return levelValue;
    case 5:
        if (level < levelValue)
            return levelValue;
        break;
    }
    return level;
}

/*
 * EXACT* note: the 98 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A30A before the next labelled function at 0x0201A30C.
 *
 * Sweeps the records of the second argument and rewrites those whose 0xA9
 * flag is set and whose recomputed value disagrees with what the first
 * argument's own query returns.  The value from before the loop is a spilled
 * local, so it is re-read from the frame at the one place it is used.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_AdjustPartyLevels.c \
 *       --func POKE_REGULATION_AdjustPartyLevels --addr 0x0201A2A8 --cc 1.1p1 --thumb
 */
void POKE_REGULATION_AdjustPartyLevels(const struct Regulation *reg, struct Party *party)
{
    u32 levelValue = REGULATION_GetRuleValue(reg, 4);
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        struct Pokemon *mon = (struct Pokemon *)POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0xA9, 0) != 0) {
            u32 level = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9E, 0);

            if (POKE_REGULATION_AdjustLevel(reg, level) != level)
                POKE_TOOL_SetLevelAndRecalc((struct PokemonParam *)mon, levelValue);
        }
    }
}

/*
 * EXACT* note: the 70 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A352, then two unlabelled 12-byte argument-shuffling tail-call thunks at 0x0201A354 (calls 0x02048F60 with (0x69, a, b)) and 0x0201A364 (calls 0x02048F4C with (b, 0x69, a)), each followed by its own pool word, before the next labelled function at 0x0201A374.
 *
 * Guarded sweep over a record array: only when the object reports state zero
 * does it walk the records and act on those whose 0xA9 flag is set.  The
 * bound is re-evaluated at the bottom of the loop, so it stays a call in the
 * condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_ResetPartyNicknames.c \
 *       --func POKE_REGULATION_ResetPartyNicknames --addr 0x0201A30C --cc 1.1p1 --thumb
 */
void POKE_REGULATION_ResetPartyNicknames(const struct Regulation *reg, struct Party *party, u32 unused)
{
    int i;

    if (REGULATION_GetRuleValue(reg, 0x11) != 0)
        return;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        struct Pokemon *mon = (struct Pokemon *)POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0xA9, 0) != 0)
            POKE_TOOL_SetDefaultName((struct PokemonParam *)mon);
    }
}

/*
 * Witness leaf for ov021 SCRCMD_FLD_BATTLE_CheckPartyRegulation and SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames.
 */
void *POKE_REGULATION_Load(int memberId, int heapId)
{
    return ARC_TOOL_LoadMember(0x69, memberId, heapId);
}

/*
 * Unlabelled Thumb argument-shuffling tail-call thunk: ARC_TOOL_ReadMember(b, 0x69, a).
 */
void POKE_REGULATION_LoadInto(int memberId, void *dst)
{
    ARC_TOOL_ReadMember(dst, 0x69, memberId);
}

/*
 * Load one 0x40-byte sprite record whose mode word is chosen from the pair of
 * bytes at a0+2/+3: (1,6) selects 6, equal bytes select 7, a byte above 1
 * with 6 following selects 8 and anything else 9.  Both palette fields are
 * stamped through WORDSET_SetSlotNumber, the record is allocated against a4, its
 * slots are filled from *a2 through MSGDATA_ReadString and the pair is bound by
 * WORDSET_CopyTaggedText.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_BuildPartySizeLine.c \
 *       --func POKE_REGULATION_BuildPartySizeLine --addr 0x0201A374 --cc 1.1p1 --thumb
 */
struct Strbuf *POKE_REGULATION_BuildPartySizeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId;
    struct Strbuf *line;

    if (reg->numLo == 1 && reg->numHi == 6) {
        messageId = 6;
    } else if (reg->numLo == reg->numHi) {
        messageId = 7;
    } else if (reg->numLo > 1 && reg->numHi == 6) {
        messageId = 8;
    } else {
        messageId = 9;
    }
    WORDSET_SetSlotNumber(wordSet, 0, reg->numLo, 1, 0, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(wordSet, 1, reg->numHi, 1, 0, PM_LANG_HALF_WIDTH_DIGITS);
    line = STRBUF_Create(0x40, heapId);
    MSGDATA_ReadString(text->bank, messageId, scratch);
    WORDSET_CopyTaggedText(wordSet, line, scratch);
    return line;
}

/*
 * poke_tool.c tail (wave 13), the twin of POKE_REGULATION_BuildPartySizeLine: pick the sprite
 * record's mode from the format byte at a0+5 (0 -> 6, 4 -> 0xb, 1 -> 0xd,
 * 2 -> 0xc, 3 -> 0xe, 5 -> 0xf, anything else 6; an if chain in that order,
 * the image tests it in source order), stamp the byte at a0+4 through
 * WORDSET_SetSlotNumber, allocate the 0x40-byte record against a4, fill it from *a2
 * and bind it with WORDSET_CopyTaggedText.
 *
 * WHAT CLOSED IT (docs/notes/pkt_0201A3F4.c.txt: 8 bytes out, the byte at
 * a0+4 loaded after the two outgoing stack stores instead of before): the
 * record parameter is `const u8 *`.  A load through a const pointer may move
 * above the stores to the outgoing-argument area; through a plain pointer it
 * may not.  Same lever as PARTICLE_CreateSystem and BUTTON_MAN_SetEmitterPos this wave.
 *
 * EXACT* because the follower at 0x0201A468 (a leaf that scans 0x52 bytes
 * from +0xa and tail-calls 0x02045EC0) carries no label.
 */
struct Strbuf *POKE_REGULATION_BuildLevelLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId;
    struct Strbuf *line;

    if (reg->levelRange == 0) {
        messageId = 6;
    } else if (reg->levelRange == 4) {
        messageId = 0xb;
    } else if (reg->levelRange == 1) {
        messageId = 0xd;
    } else if (reg->levelRange == 2) {
        messageId = 0xc;
    } else if (reg->levelRange == 3) {
        messageId = 0xe;
    } else if (reg->levelRange == 5) {
        messageId = 0xf;
    } else {
        messageId = 6;
    }
    WORDSET_SetSlotNumber(wordSet, 0, reg->level, 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
    line = STRBUF_Create(0x40, heapId);
    MSGDATA_ReadString(text->bank, messageId, scratch);
    WORDSET_CopyTaggedText(wordSet, line, scratch);
    return line;
}

struct Strbuf *POKE_REGULATION_GetBannedSpeciesLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    int i;
    u32 messageId;

    for (i = 0; i < 0x52; i++) {
        if (reg->vetoPokeBit[i] != 0)
            break;
    }
    messageId = 0x10;
    if (i != 0x52)
        messageId = 0x11;
    return MSGDATA_AllocString(text->bank, messageId);
}

struct Strbuf *POKE_REGULATION_GetSpeciesClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId = 0x12;

    if (reg->bothPoke != 1)
        messageId = 0x13;
    return MSGDATA_AllocString(text->bank, messageId);
}

struct Strbuf *POKE_REGULATION_GetItemClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId = 0x14;

    if (reg->bothItem != 1)
        messageId = 0x15;
    return MSGDATA_AllocString(text->bank, messageId);
}

struct Strbuf *POKE_REGULATION_GetBattleModeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId;
    u8 battleMode = text->battleMode;

    if (battleMode == 1) {
        messageId = 0x16;
    } else {
        messageId = 0x17;
        if (battleMode != 0)
            messageId = 0x16;
    }
    return MSGDATA_AllocString(text->bank, messageId);
}

/*
 * Wave 17 lane untried_small. What closed it (from 6 halfwords out): the heap
 * id parameter a2 is u16. The image homes it to the stack and reloads it for
 * every use (the allocator's first argument included); declared u32 it stays
 * in r2 and is copied, which was the whole parameter-homing residue.
 */
struct RegulationText *POKE_REGULATION_CreateText(const struct Regulation *reg, struct WordSet *wordSet, u16 heapId, u32 battleMode)
{
    struct RegulationText *text;
    struct Strbuf *scratch;
    int i;
    u32 regulationMode;

    text = (struct RegulationText *)GFL_HEAP_Alloc(heapId, sizeof(*text), 1, poke_regulation_File, 0x312);
    text->bank = MSGDATA_CreateFromArchive(0, 2, 0xa5, heapId);
    scratch = STRBUF_Create(0x40, heapId);
    regulationMode = reg->shooter;
    if (regulationMode == 2)
        text->battleMode = battleMode;
    else
        text->battleMode = regulationMode;
    for (i = 0; i < 6; i++) {
        text->labels[i] = MSGDATA_AllocString(text->bank, i);
        text->lines[i] = POKE_REGULATION_LineFns[i](reg, wordSet, text, scratch, heapId);
    }
    STRBUF_Delete(scratch);
    return text;
}

/*
 * EXACT* note: the 42 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A59A before the next labelled function at 0x0201A59C.
 *
 * Six records of 0x20 bytes, each with a pair of ARM calls at +4 and +0x1C,
 * then the object's first word through the ARM at 0x02045C04 and the object
 * itself through 0x020307B0.  The loop index is a signed int, so the bound
 * test is `blt` and no truncation appears.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_DeleteText.c \
 *       --func POKE_REGULATION_DeleteText --addr 0x0201A570 --cc 1.1p1 --thumb
 */
void POKE_REGULATION_DeleteText(struct RegulationText *text)
{
    int i;

    for (i = 0; i < 6; i++) {
        STRBUF_Delete(text->labels[i]);
        STRBUF_Delete(text->lines[i]);
    }
    MSGDATA_Delete(text->bank);
    GFL_HEAP_Free(text);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/pending/POKE_REGULATION_FindValidOrder.c \
 *       --func POKE_REGULATION_FindValidOrder --addr 0x0201A59C --cc 1.1p1 --thumb
 */
int POKE_REGULATION_FindValidOrder(const struct Regulation *reg, struct Party *party, char *picked)
{
    char order[6];

    order[0] = POKE_REGULATION_InitialOrder[0];
    order[1] = POKE_REGULATION_InitialOrder[1];
    order[2] = POKE_REGULATION_InitialOrder[2];
    order[3] = POKE_REGULATION_InitialOrder[3];
    order[4] = POKE_REGULATION_InitialOrder[4];
    order[5] = POKE_REGULATION_InitialOrder[5];

    if (POKE_REGULATION_NextOrder((u8 *)order) != 0) {
        do {
            if (POKE_REGULATION_CheckOrder(reg, party, (u8 *)order, picked, 0) == 1) {
                return 1;
            }
        } while (POKE_REGULATION_NextOrder((u8 *)order) != 0);
    }

    return 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckOrder.c  *       --func POKE_REGULATION_CheckOrder --addr 0x0201A5FC --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckOrder(const struct Regulation *reg, struct Party *party, u8 *order, char *picked, u32 *flags)
{
    u8 count = 0;
    u32 speciesList[6] = {0};
    u32 formList[6] = {0};
    u32 itemList[6] = {0};
    u8 i;
    int allowed;
    u32 levelTotal;
    struct Pokemon *mon;
    u32 species;
    u32 levelCost;
    u32 levelBudget;
    u8 slot;
    u8 j;
    u32 item;
    u32 requiredSpecies;
    u8 k;
    u32 requiredForm;
    u32 reason;
    int found;

    levelTotal = 0;
    levelBudget = (u32)(int)REGULATION_GetRuleValue(reg, (int)6);

    if (picked != 0)
        *picked = 0;
    if (flags != 0)
        *flags = 0;

    for (i = 0; i < 6; i++) {
        if (order[i] == 0)
            continue;
        slot = (u8)(order[i] - 1);
        if ((int)slot >= (int)POKEPARTY_GetCount(party))
            continue;
        mon = (struct Pokemon *)POKEPARTY_GetMember(party, slot);
        species = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0);
        item = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 6, 0);
        levelCost = (u32)POKE_REGULATION_AdjustLevel(reg, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9e, 0));
        reason = POKE_REGULATION_CheckPokemon(reg, mon);
        if (reason != 0) {
            if (flags != 0)
                *flags |= reason;
            continue;
        }
        allowed = 1;
        for (j = 0; j < count; j++) {
            if ((int)REGULATION_GetRuleValue(reg, (int)7) == 0 && species == speciesList[j]) {
                allowed = 0;
                if (flags != 0)
                    *flags |= 8;
                break;
            }
            if ((int)REGULATION_GetRuleValue(reg, (int)8) == 0 && item != 0 && item == itemList[j]) {
                allowed = 0;
                if (flags != 0)
                    *flags |= 0x10;
                break;
            }
        }
        if (allowed == 0)
            continue;
        if (levelBudget != 0 && (u32)(levelTotal + levelCost) > levelBudget) {
            if (flags != 0)
                *flags |= 0x100;
            continue;
        }
        if (picked != 0)
            picked[count] = (char)(slot + 1);
        speciesList[count] = species;
        formList[count] = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x6f, 0);
        itemList[count] = item;
        levelTotal = (u16)(levelTotal + (u16)levelCost);
        count = (u8)(count + 1);
        if ((int)count < (int)REGULATION_GetRuleValue(reg, (int)3))
            continue;
        if (flags != 0 && count < 6 && order[count] != 0)
            *flags |= 1;
        break;
    }

    if ((int)count >= (int)REGULATION_GetRuleValue(reg, (int)2)) {
        requiredSpecies = (u32)(int)REGULATION_GetRuleValue(reg, (int)0xb);
        found = 1;
        if (requiredSpecies != 0) {
            requiredForm = (u32)(int)REGULATION_GetRuleValue(reg, (int)0xc);
            found = 0;
            for (k = 0; k < count; k++) {
                if (requiredSpecies == speciesList[k] && requiredForm == formList[k]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1)
            return 1;
        if (flags != 0)
            *flags |= 0x80;
    } else {
        if (flags != 0)
            *flags |= 1;
    }
    return 0;
}

/*
 * A base-7 odometer with a distinctness test: six nested counters (a[0]
 * outermost) over 0..6, and the innermost body returns 1 as soon as all six
 * values differ.  The entry `a[5]++` is the source's own first statement, not
 * a loop increment.
 *
 * The fifteen `!=` tests are one conjunction: every `cmp` in the listing
 * branches to the same increment block (0x0201A8B8) on equality, which is the
 * "guard chain sharing one exit block" spelling, not a chain of ifs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_NextOrder.c \
 *       --func POKE_REGULATION_NextOrder --addr 0x0201A858 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_NextOrder(u8 *order)
{
    order[5]++;
    while (order[0] <= 6) {
        while (order[1] <= 6) {
            while (order[2] <= 6) {
                while (order[3] <= 6) {
                    while (order[4] <= 6) {
                        while (order[5] <= 6) {
                            if (order[0] != order[1] && order[0] != order[2] &&
                                order[0] != order[3] && order[0] != order[4] &&
                                order[0] != order[5] && order[1] != order[2] &&
                                order[1] != order[3] && order[1] != order[4] &&
                                order[1] != order[5] && order[2] != order[3] &&
                                order[2] != order[4] && order[2] != order[5] &&
                                order[3] != order[4] && order[3] != order[5] &&
                                order[4] != order[5]) {
                                return 1;
                            }
                            order[5]++;
                        }
                        order[5] = 1;
                        order[4]++;
                    }
                    order[4] = 1;
                    order[3]++;
                }
                order[3] = 1;
                order[2]++;
            }
            order[2] = 1;
            order[1]++;
        }
        order[1] = 1;
        order[0]++;
    }
    return 0;
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
int POKE_REGULATION_GetDataSize(void)
{
    return 0x534;
}
