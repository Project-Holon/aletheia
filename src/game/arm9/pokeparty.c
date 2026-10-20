/*
 * file:     pokeparty.c
 * unit:     yes
 * function: POKEPARTY_Create, POKEPARTY_Init, POKEPARTY_InitEx, POKEPARTY_Add, POKEPARTY_RemoveMember, POKEPARTY_GetCapacity, POKEPARTY_GetCount, POKEPARTY_GetNonEggCount, POKEPARTY_GetBattleReadyCount, POKEPARTY_GetEggCount, POKEPARTY_GetBadEggCount, POKEPARTY_FindFirstBattleReady, POKEPARTY_FindFirstNonEgg, POKEPARTY_GetMember, POKEPARTY_IsMemberBattleReady, POKEPARTY_SetMember, POKEPARTY_SwapMembers, POKEPARTY_Copy, POKEPARTY_HasSpecies, POKEPARTY_GetAliveNonEggCount, POKEPARTY_GetSlotFlag, POKEPARTY_SetSlotFlag, POKEPARTY_GetSaveData, POKEPARTY_IsBattleReady, POKEPARTY_IsNotEgg, POKEPARTY_FindFirst
 * address:  0x0201A920
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokeparty.c by tools/splitfile.py.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   pokeparty_File  0x020A7304  data
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 */
#include "pokeparty_shared_types.h"

struct SaveControl;

typedef u32 (*PartyMemberPredicate)(struct PokemonParam *member);

#include "poke_tool.h"

#include "gfl_heap_wrap.h"


#include "mi_memory.h"


#include "save_control.h"

struct Party *POKEPARTY_Create(u32 heap);

void POKEPARTY_Init(struct Party *party);

void POKEPARTY_InitEx(struct Party *party, s32 capacity);

u32 POKEPARTY_Add(struct Party *party, const struct PokemonParam *member);

u32 POKEPARTY_RemoveMember(struct Party *party, s32 pos);

u32 POKEPARTY_GetCapacity(const struct Party *party);

u32 POKEPARTY_GetCount(const struct Party *party);

u32 POKEPARTY_GetNonEggCount(struct Party *party);

u32 POKEPARTY_GetBattleReadyCount(struct Party *party);

u32 POKEPARTY_GetEggCount(struct Party *party);

u32 POKEPARTY_GetBadEggCount(struct Party *party);

u32 POKEPARTY_FindFirstBattleReady(struct Party *party);

u32 POKEPARTY_FindFirstNonEgg(struct Party *party);

struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);

u32 POKEPARTY_IsMemberBattleReady(struct Party *party, u32 pos);

void POKEPARTY_SetMember(struct Party *party, u32 pos, const struct PokemonParam *member);

u32 POKEPARTY_SwapMembers(struct Party *party, u32 pos1, u32 pos2, u32 heap);

void POKEPARTY_Copy(const struct Party *src, struct Party *dst);

u32 POKEPARTY_HasSpecies(struct Party *party, u32 species);

u32 POKEPARTY_GetAliveNonEggCount(struct Party *party);

int POKEPARTY_GetSlotFlag(const struct Party *party, u32 pos);

void POKEPARTY_SetSlotFlag(struct Party *party, u32 pos, u32 set);

struct Party *POKEPARTY_GetSaveData(struct SaveControl *save);

u32 POKEPARTY_IsBattleReady(struct PokemonParam *member);

u32 POKEPARTY_IsNotEgg(struct PokemonParam *member);

u32 POKEPARTY_FindFirst(struct Party *party, PartyMemberPredicate pred);

extern const char pokeparty_File[];

/*
 *           POKEPARTY_RemoveMember
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * POKEPARTY_Init is the six-slot spelling of POKEPARTY_InitEx and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * POKEPARTY_Add's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * POKEPARTY_RemoveMember compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
struct Party *POKEPARTY_Create(u32 heap)
{
    struct Party *party = (struct Party *)GFL_HEAP_Alloc(heap, sizeof(struct Party), 0,
                                                   pokeparty_File, 65);

    POKEPARTY_Init(party);
    return party;
}

void POKEPARTY_Init(struct Party *party)
{
    POKEPARTY_InitEx(party, 6);
}

void POKEPARTY_InitEx(struct Party *party, s32 capacity)
{
    s32 i;

    MIi_CpuClearFast(0, party, sizeof(struct Party));
    party->capacity = capacity;
    party->count = 0;
    party->slotFlags = 0;
    for (i = 0; i < 6; i++) {
        POKE_TOOL_ClearPartyParam(&party->members[i]);
    }
}

u32 POKEPARTY_Add(struct Party *party, const struct PokemonParam *member)
{
    if (party->count >= party->capacity) {
        return 0;
    }
    party->members[party->count] = *member;
    POKEPARTY_SetSlotFlag(party, party->count, 1);
    party->count = party->count + 1;
    return 1;
}

u32 POKEPARTY_RemoveMember(struct Party *party, s32 pos)
{
    s32 i;

    for (i = pos; i < party->count - 1; i++) {
        party->members[i] = party->members[i + 1];
    }
    POKE_TOOL_ClearPartyParam(&party->members[i]);
    party->count = party->count - 1;
    return 1;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Two plain word getters, four bytes each: the object's first word and the
 * word at +4.  Both are called from POKEPARTY_GetNonEggCount (0x0201AA1C, still open)
 * and POKEPARTY_GetCount is also called from the unit at 0x0201AC2C, which is
 * where the concrete relocations against it are attested from.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA14.c \
 *       --addr 0x0201AA14 --thumb
 */
u32 POKEPARTY_GetCapacity(const struct Party *party)
{
    return party->capacity;
}

u32 POKEPARTY_GetCount(const struct Party *party)
{
    return party->count;
}

/*
 *           POKEPARTY_FindFirstBattleReady, POKEPARTY_FindFirstNonEgg
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine POKEPARTY_FindFirst.
 * Each counter walks 0 to POKEPARTY_GetCount(p) and tests one or two fields of the
 * entry through the getter POKE_TOOL_GetPartyValue.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  POKEPARTY_GetBattleReadyCount is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * POKEPARTY_GetBattleReadyCount really does call POKEPARTY_GetMember twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 POKEPARTY_GetNonEggCount(struct Party *party)
{
    s32 i;
    u32 total = 0;
    s32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        void *member = POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue(member, 0x4C, 0) != 1) {
            total++;
        }
    }
    return total;
}

u32 POKEPARTY_GetBattleReadyCount(struct Party *party)
{
    u32 total = 0;
    s32 memberCount;
    s32 i;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        POKEPARTY_GetMember(party, i);
        if (POKEPARTY_IsBattleReady(POKEPARTY_GetMember(party, i)) != 0) {
            total++;
        }
    }
    return total;
}

u32 POKEPARTY_GetEggCount(struct Party *party)
{
    s32 i;
    u32 total = 0;
    s32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        void *member = POKEPARTY_GetMember(party, i);
        u32 isEgg = POKE_TOOL_GetPartyValue(member, 0x4C, 0);
        u32 isBadEgg = POKE_TOOL_GetPartyValue(member, 3, 0);

        if (isEgg == 1 && isBadEgg == 0) {
            total++;
        }
    }
    return total;
}

u32 POKEPARTY_GetBadEggCount(struct Party *party)
{
    s32 i;
    u32 total = 0;
    s32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        void *member = POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue(member, 3, 0) == 1) {
            total++;
        }
    }
    return total;
}

u32 POKEPARTY_FindFirstBattleReady(struct Party *party)
{
    return POKEPARTY_FindFirst(party, POKEPARTY_IsBattleReady);
}

u32 POKEPARTY_FindFirstNonEgg(struct Party *party)
{
    return POKEPARTY_FindFirst(party, POKEPARTY_IsNotEgg);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * POKEPARTY_GetMember is the index calculator this whole neighbourhood shares: an
 * entry of an array of 0xDC-byte records starting eight bytes into the
 * object.  POKEPARTY_IsMemberBattleReady looks the entry up and, if it is non-null (in
 * practice it always is; the check reads as a defensive null guard rather
 * than a reachable branch), tail-hands it to POKEPARTY_IsBattleReady (0x0201AC2C..,
 * still open at the time of writing but pinned as an extern here since a
 * `label` witness for it exists outside this range).
 *
 * Immediately in front of POKEPARTY_GetMember, at 0x0201AB08..0x0201AB28, are two
 * back to back linker long-branch veneers (`ldr r1,[pc,#4]; ldr r3,[pc,#8];
 * bx r3` plus two pool words each) that this file does not claim; see
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for the general shape, though here both are Thumb-encoded stubs rather
 * than the ARM long-branch form.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB28.c \
 *       --addr 0x0201AB28 --thumb
 */
struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos)
{
    return &party->members[pos];
}

u32 POKEPARTY_IsMemberBattleReady(struct Party *party, u32 pos)
{
    struct PokemonParam *member = POKEPARTY_GetMember(party, pos);

    if (member != 0) {
        return POKEPARTY_IsBattleReady(member);
    }
    return 0;
}

/*
 * pokeparty.c: the store-at-index and swap-two-indices operations on the
 * party container, an array of 0xDC byte records eight bytes into the object
 * with a running count at +0x04.  The file name is the image's own: the debug
 * allocator call in POKEPARTY_SwapMembers passes 0x020A7304, which spells
 * "pokeparty.c", and its neighbours in the string area are
 * "poke_regulation.c" and "poke_personal.c".
 *
 * Both functions copy a whole record with a plain struct assignment, which
 * this front end inlines as a counted `ldm`/`stm` loop of 27 eight-byte steps
 * plus a trailing word rather than as a call
 * (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md).  The record is
 * declared as an array of `u32` and not of `u8` for exactly that reason: a
 * one-aligned declaration gives a byte loop of 0xDC iterations, the same
 * shape with completely different bytes.
 *
 * POKEPARTY_SetMember reads field 0xA9 (the "slot is occupied" derived id, see
 * src/pending/POKE_TOOL_GetBoxValueRaw.c) out of the destination slot before the copy and
 * out of the source after it, and adds the difference to the count, so the
 * count stays right whether the write fills an empty slot or overwrites a
 * full one.
 *
 * Two spellings in POKEPARTY_SetMember are load bearing and neither is obvious.  The
 * destination of the copy is written as byte arithmetic,
 * `(u8 *)p + idx * sizeof(rec) + 8`, while the getter's argument is the
 * ordinary `&p->mon[idx]`: written the same way twice the compiler common
 * subexpression eliminates them and keeps the finished address in a
 * callee-saved register across both calls, which is four bytes short.  What
 * the original keeps alive across the calls is the *product*, and only two
 * differently associated address expressions produce that.  And the second
 * getter's result is not bound to a local: `a - POKE_TOOL_GetPartyValue(...)` puts the
 * `subs` at the call, where the original has it, while a named `b` sinks it
 * past the copy loop (the mirror of
 * docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * POKEPARTY_SwapMembers swaps two slots through a heap-allocated temporary of exactly
 * one record, then swaps the two slots' 0x1B-keyed side values through
 * POKEPARTY_GetSlotFlag / POKEPARTY_SetSlotFlag (src/matched/unit_0201AC2C.c).  It returns 0
 * unconditionally.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB48.c \
 *       --addr 0x0201AB48 --thumb
 */
void POKEPARTY_SetMember(struct Party *party, u32 pos, const struct PokemonParam *member)
{
    u32 before = POKE_TOOL_GetPartyValue(&party->members[pos], 0xA9, 0);
    u32 delta = before - POKE_TOOL_GetPartyValue((void *)member, 0xA9, 0);

    *(struct PokemonParam *)((u8 *)party + pos * sizeof(struct PokemonParam) + 8) = *member;
    party->count += delta;
}

u32 POKEPARTY_SwapMembers(struct Party *party, u32 pos1, u32 pos2, u32 heap)
{
    u32 flags1;
    u32 flags2;
    struct PokemonParam *tmp = (struct PokemonParam *)GFL_HEAP_Alloc(heap, sizeof(struct PokemonParam), 0,
                                                           pokeparty_File, 382);

    *tmp = party->members[pos1];
    party->members[pos1] = party->members[pos2];
    party->members[pos2] = *tmp;
    GFL_HEAP_Free(tmp);
    flags1 = POKEPARTY_GetSlotFlag(party, pos1);
    flags2 = POKEPARTY_GetSlotFlag(party, pos2);
    POKEPARTY_SetSlotFlag(party, pos1, flags2);
    POKEPARTY_SetSlotFlag(party, pos2, flags1);
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           POKEPARTY_SetSlotFlag, POKEPARTY_GetSaveData, POKEPARTY_IsBattleReady, POKEPARTY_IsNotEgg,
 *           POKEPARTY_FindFirst
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * POKEPARTY_GetMember, in unit_0201AB28.c, indexes), all going through
 * POKE_TOOL_GetPartyValue, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * POKEPARTY_Copy copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * POKEPARTY_HasSpecies and POKEPARTY_GetAliveNonEggCount both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  POKEPARTY_GetAliveNonEggCount's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * POKEPARTY_GetSlotFlag is a plain bit test on a byte 0x530 into the object.
 * POKEPARTY_SetSlotFlag sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * POKEPARTY_GetSaveData is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * SAVE_CONTROL_GetBlock (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * POKEPARTY_IsBattleReady and POKEPARTY_IsNotEgg are both single-guard wrappers around
 * POKE_TOOL_GetPartyValue.  POKEPARTY_IsBattleReady's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * POKEPARTY_FindFirst is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = POKEPARTY_GetCount(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
void POKEPARTY_Copy(const struct Party *src, struct Party *dst)
{
    *dst = *src;
}

u32 POKEPARTY_HasSpecies(struct Party *party, u32 species)
{
    s32 i;

    for (i = 0; i < party->count; i++) {
        struct PokemonParam *member = &party->members[i];

        if (POKE_TOOL_GetPartyValue(member, 5, 0) == species) {
            break;
        }
    }
    if (i == party->count) {
        return 0;
    }
    return 1;
}

u32 POKEPARTY_GetAliveNonEggCount(struct Party *party)
{
    s32 memberCount = POKEPARTY_GetCount(party);
    s32 i, total = 0;

    for (i = 0; i < memberCount; i++) {
        struct PokemonParam *member = POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue(member, 0xA0, 0)) {
            if (!POKE_TOOL_GetPartyValue(member, 0x4C, 0)) {
                total++;
            }
        }
    }
    return total;
}

int POKEPARTY_GetSlotFlag(const struct Party *party, u32 pos)
{
    u8 flags = party->slotFlags;

    if (flags & (1u << pos)) {
        return 1;
    }
    return 0;
}

void POKEPARTY_SetSlotFlag(struct Party *party, u32 pos, u32 set)
{
    if (set == 1) {
        party->slotFlags = party->slotFlags | (1u << pos);
    } else {
        party->slotFlags = party->slotFlags & (0xFFu - (1u << pos));
    }
}

struct Party *POKEPARTY_GetSaveData(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x1A);
}

u32 POKEPARTY_IsBattleReady(struct PokemonParam *member)
{
    u32 isEgg = POKE_TOOL_GetPartyValue(member, 0x4C, 0);
    u32 hp = POKE_TOOL_GetPartyValue(member, 0xA0, 0);

    if (isEgg != 1 && hp != 0) {
        return 1;
    }
    return 0;
}

u32 POKEPARTY_IsNotEgg(struct PokemonParam *member)
{
    u32 result = 0;

    if (POKE_TOOL_GetPartyValue(member, 0x4C, 0) != 1) {
        result = 1;
    }
    return result;
}

u32 POKEPARTY_FindFirst(struct Party *party, PartyMemberPredicate pred)
{
    s32 i;
    s32 memberCount = POKEPARTY_GetCount(party);

    for (i = 0; i < memberCount; i++) {
        struct PokemonParam *member = POKEPARTY_GetMember(party, i);

        if (pred(member)) {
            return i;
        }
    }
    return memberCount;
}
