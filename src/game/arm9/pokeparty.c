/*
 * file:     pokeparty.c
 * unit:     yes
 * function: POKEPARTY_Create, POKEPARTY_Init, POKEPARTY_InitEx, POKEPARTY_Add, POKEPARTY_RemoveMember, POKEPARTY_GetCapacity, POKEPARTY_GetCount, POKEPARTY_GetNonEggCount, POKEPARTY_GetBattleReadyCount, POKEPARTY_GetEggCount, POKEPARTY_GetBadEggCount, POKEPARTY_FindFirstBattleReady, POKEPARTY_FindFirstNonEgg, POKEPARTY_GetMember, POKEPARTY_IsMemberBattleReady, POKEPARTY_SetMember, POKEPARTY_SwapMembers, POKEPARTY_Copy, POKEPARTY_HasSpecies, POKEPARTY_GetAliveNonEggCount, POKEPARTY_GetSlotFlag, POKEPARTY_SetSlotFlag, POKEPARTY_GetSaveData, POKEPARTY_IsBattleReady, POKEPARTY_IsNotEgg, POKEPARTY_FindFirst, POKE_PERSONAL_OpenHandle, POKE_PERSONAL_LoadData, POKE_PERSONAL_LoadDataDirect, POKE_PERSONAL_Create, POKE_PERSONAL_Delete, POKE_PERSONAL_GetParam, POKE_PERSONAL_IsPlaceholderAbility, POKE_PERSONAL_LoadFormTable, POKE_PERSONAL_GetFormDataId, POKERUS_TryInfectParty, POKERUS_DecreaseDays, POKERUS_SpreadParty, POKERUS_GetInfectedMask, POKERUS_IsInfected, POKERUS_IsBoxInfected, POKERUS_IsCured, POKERUS_IsBoxCured
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
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   pokeparty_File  0x020A7304  data
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   _pPersonalArc  0x0214652C  data
 *   poke_personal_File  0x020A7310  data
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   ARC_TOOL_GetHandleMemberOffset  0x02049578  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   ARC_TOOL_SeekHandle  0x0204960C  arm
 */
#include "pokeparty_shared_types.h"

struct SaveControl;

typedef u32 (*PartyMemberPredicate)(struct PokemonParam *member);

/* The 0x3C byte personal record of one species or form (poke_personal.c). */
struct PersonalData {
    u8  baseHp;
    u8  baseAttack;
    u8  baseDefense;
    u8  baseSpeed;
    u8  baseSpAttack;
    u8  baseSpDefense;
    u8  type1;
    u8  type2;
    u8  catchRate;
    u8  evoStage;
    u16 evHp : 2;
    u16 evAttack : 2;
    u16 evDefense : 2;
    u16 evSpeed : 2;
    u16 evSpAttack : 2;
    u16 evSpDefense : 2;
    u16 yieldFlag : 1;
    u16 reserved : 3;
    u16 heldItemCommon;
    u16 heldItemRare;
    u16 heldItemDream;
    u8  genderRatio;
    u8  eggCycles;
    u8  baseFriendship;
    u8  growthRate;
    u8  eggGroup1;
    u8  eggGroup2;
    u8  ability1;
    u8  ability2;
    u8  hiddenAbility;
    u8  escapeRate;
    u16 formStatsIndex;
    u16 formSpriteIndex;
    u8  formCount;
    u8  color : 6;
    u8  spriteFlip : 1;
    u8  formSpriteShared : 1;
    u16 baseExp;
    u16 height;
    u16 weight;
    u32 tmFlags1;
    u32 tmFlags2;
    u32 tmFlags3;
    u32 tmFlags4;
    u32 tutorFlags;
};

extern struct BoxPokemon *POKE_TOOL_Dummy(struct PokemonParam *pp);

extern u32   POKE_TOOL_GetBoxValue(struct BoxPokemon *box, u32 id, u32 arg);

extern void  ARC_TOOL_ReadMember(void *dst, u32 arcId, u32 dataId);

extern u32   POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 id, u32 arg);

extern void  POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 id, u32 value);

extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int fromTail, const char *file, u16 line);

extern u32   GFL_HEAP_Free(void *ptr);

extern void  MIi_CpuClearFast(u32 value, void *dest, u32 size);

extern void  POKE_TOOL_ClearPartyParam(struct PokemonParam *pp);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern struct ArcHandle *ARC_TOOL_CreateHandle(unsigned int arcId, unsigned int heap);

extern u32   ARC_TOOL_GetHandleMemberOffset(struct ArcHandle *arc, u32 dataId);

extern void  ARC_TOOL_SeekHandle(struct ArcHandle *arc, u32 offset);

extern void  ARC_TOOL_ReadHandle(struct ArcHandle *arc, u32 size, void *dst);

extern void *ARC_UTIL_LoadHandleMemberWithSize(struct ArcHandle *arc, int dataId, int fromTail, u32 heap, u32 *sizeOut);

extern u32   GF_STANDARD_Rand(void);

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

void POKE_PERSONAL_OpenHandle(u32 heap);

void POKE_PERSONAL_LoadData(u32 species, int form, void *dst);

void POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dst);

struct PersonalData *POKE_PERSONAL_Create(u32 species, int form, u32 heap);

void POKE_PERSONAL_Delete(struct PersonalData *data);

u32 POKE_PERSONAL_GetParam(const struct PersonalData *data, u32 field);

u32 POKE_PERSONAL_IsPlaceholderAbility(u32 ability);

u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

u32 POKE_PERSONAL_GetFormDataId(u32 species, s32 form);

void POKERUS_TryInfectParty(struct Party *party);

void POKERUS_DecreaseDays(struct Party *party, s32 days);

void POKERUS_SpreadParty(struct Party *party);

u32 POKERUS_GetInfectedMask(struct Party *party);

u32 POKERUS_IsInfected(struct PokemonParam *pp);

u32 POKERUS_IsBoxInfected(struct BoxPokemon *box);

u32 POKERUS_IsCured(struct PokemonParam *pp);

u32 POKERUS_IsBoxCured(struct BoxPokemon *box);

extern const char pokeparty_File[];

extern struct ArcHandle *_pPersonalArc;

extern const char poke_personal_File[];

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

/*
 * The lazy constructor for the static handle at 0x0214652C that
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c thread every
 * call through: allocates a 0x10 byte object out of the heap named by the
 * parameter the first time it is asked and does nothing afterwards.
 *
 * The `adds r1, r0, #0` that moves the parameter out of r0 sits in front of
 * the guard's own load rather than inside the `if`, which is what the
 * parameter being live across the test costs; it is not an argument set-up
 * for a call that happens later.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AD88.c \
 *       --addr 0x0201AD88 --thumb
 */
void POKE_PERSONAL_OpenHandle(u32 heap)
{
    if (_pPersonalArc == 0) {
        _pPersonalArc = ARC_TOOL_CreateHandle(0x10, heap);
    }
}

/*
 * A three-parameter wrapper: calls POKE_PERSONAL_GetFormDataId(a, b) (0x0201AFD4, still
 * open) and threads its result through two handler calls keyed off a static
 * handle at 0x0214652C, then hands the third parameter off to a third
 * handler with a literal id of 0x3C.  Kept as its own file rather than
 * merged with the neighbouring POKE_PERSONAL_LoadDataDirect/POKE_PERSONAL_Create
 * (src/matched/unit_0201ADD0.c) because both of those call POKE_PERSONAL_GetFormDataId as
 * well; one range holding all three calls has none of them attested and
 * caps at MATCH (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * With this function alone, the other two callers are outside the range and
 * carry the `label` evidence.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADA4.c \
 *       --addr 0x0201ADA4 --thumb
 */
void POKE_PERSONAL_LoadData(u32 species, int form, void *dst)
{
    u32 dataId = POKE_PERSONAL_GetFormDataId(species, form);

    dataId = ARC_TOOL_GetHandleMemberOffset(_pPersonalArc, dataId);
    ARC_TOOL_SeekHandle(_pPersonalArc, dataId);
    ARC_TOOL_ReadHandle(_pPersonalArc, 0x3C, dst);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * POKE_PERSONAL_LoadDataDirect is a second, smaller wrapper around POKE_PERSONAL_GetFormDataId (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * POKE_PERSONAL_Create constructs an object from the debug allocator,
 * GFL_HEAP_Alloc(heap, size, zero, file, tag), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to POKE_PERSONAL_LoadData (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */
void POKE_PERSONAL_LoadDataDirect(u32 species, int form, void *dst)
{
    u32 dataId = POKE_PERSONAL_GetFormDataId(species, form);

    ARC_TOOL_ReadMember(dst, 0x12, dataId);
}

struct PersonalData *POKE_PERSONAL_Create(u32 species, int form, u32 heap)
{
    struct PersonalData *data = GFL_HEAP_Alloc(heap, 0x3C, 0, poke_personal_File, 0x76);

    POKE_PERSONAL_LoadData(species, form, data);
    return data;
}

/*
 * poke_personal.c's record destructor: four bytes of code and one pool word,
 * a tail call with no argument set-up at all
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  It abuts
 * src/matched/unit_0201ADD0.c on the left, whose POKE_PERSONAL_Create carries the
 * "poke_personal.c" file string.
 *
 * This file used to hold the whole middle of poke_personal.c
 * (0x0201AE14..0x0201AFD4: this destructor, the 44 field getter, the
 * placeholder-ability predicate and the form-table loader).  It was cut into
 * three so that the 44 field getter, which the whole poke_* region reads the
 * personal record through, gets a manifest entry of its own instead of being
 * an interior function with no attestable address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The other two
 * pieces are src/matched/POKE_PERSONAL_GetParam.c and src/matched/unit_0201AF6C.c; the
 * C in all three is unchanged, only the file boundaries moved, and no
 * relocation crosses a new boundary.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AE14.c \
 *       --addr 0x0201AE14 --thumb
 */
void POKE_PERSONAL_Delete(struct PersonalData *data)
{
    GFL_HEAP_Free(data);
}

/*
 * poke_personal.c's 44 field getter over the 0x3C byte personal record, cut
 * out of src/matched/unit_0201AE14.c so that it has a manifest entry of its
 * own.  The bytes and the C are unchanged; only the file boundary moved.
 *
 * Why it is its own file: the manifest records one entry per unit at the
 * unit's start address, so while this function sat in the middle of
 * unit_0201AE14.c the address 0x0201AE1C had no entry, was not an address the
 * `matched` evidence class could attest, and read as still open to every
 * consumer that asked the manifest what the record layer covers
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  It has high
 * fan-in: it is the field selector the whole poke_* region reads the personal
 * record through, so it is exactly the address that wants an entry.
 *
 * Splitting costs nothing here: POKE_PERSONAL_Delete (the record destructor, four
 * bytes of code and a pool word) keeps the start address and therefore keeps
 * its entry, POKE_PERSONAL_IsPlaceholderAbility and POKE_PERSONAL_LoadFormTable move into
 * src/matched/unit_0201AF6C.c which starts at the address of the first of
 * them, and this function holds no relocation at all, so no cut can take a
 * witness away from anybody.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * The 44 case ids are an interface rather than content: they are the field
 * selector the whole region uses, and src/matched/POKE_TOOL_CalcParam.c reads the
 * same record through ids of its own.  The field offsets are structure and
 * will not move; the ids will not either unless a field is added, which is
 * exactly the kind of thing a version diff does, so the map below is the thing
 * to check against IRAO rather than any single number.  No constant in this
 * function is a content id.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP, from the jump table
 * ---------------------------------------------------------------------------
 * The table at 0x0201AE2E is 44 signed halfwords and every one of them names a
 * real body, so the source has case labels 0 through 43 with no gaps
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  The bodies
 * are emitted in the source's order, which here is also the numeric order,
 * even though the offsets they read are not monotonic: id 9 reads +0x22 and id
 * 36 reads +0x09, both out of sequence.
 *
 *    0.. 5  +0x00..+0x05  the six base stats
 *    6, 7   +0x06, +0x07  the two types
 *    8      +0x08
 *    9      +0x22
 *   10..15  +0x0A bits 0..11, six 2 bit fields: the six effort yields
 *   16      +0x0A bit 12, one bit
 *   17..19  +0x0C, +0x0E, +0x10  three held item ids
 *   20..29  +0x12..+0x1B  ten bytes
 *   30, 31  +0x1C, +0x1E  the form table base and its companion; +0x1C is the
 *                         same field src/matched/unit_0201AFD4.c reads
 *   32      +0x20         the form count, also read by unit_0201AFD4.c
 *   33      +0x21 bits 0..5
 *   34, 35  +0x21 bit 6, bit 7
 *   36      +0x09
 *   37, 38  +0x24, +0x26
 *   39..43  +0x28..+0x38  five words
 *
 * Two shapes in there are readings of the declaration rather than of the code.
 * The 2 bit and 1 bit extractions at +0x0A are `lsls`/`lsrs` pairs whose width
 * is neither 8, 16 nor 32, so they are bitfields and nothing else
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the
 * container has to be `u16` for the load to be a `ldrh`, and `u8` at +0x21 for
 * it to be a `ldrb`.  And the two bytes at +0x20 and +0x21 each cost an
 * `adds r0, #0x20` first, which is only the byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); the halfword at +0x22
 * needs none, because `ldrh` reaches 62.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/POKE_PERSONAL_GetParam.c \
 *       --addr 0x0201AE1C --thumb
 */
u32 POKE_PERSONAL_GetParam(const struct PersonalData *data, u32 field)
{
    switch (field) {
    case 0:  return data->baseHp;
    case 1:  return data->baseAttack;
    case 2:  return data->baseDefense;
    case 3:  return data->baseSpeed;
    case 4:  return data->baseSpAttack;
    case 5:  return data->baseSpDefense;
    case 6:  return data->type1;
    case 7:  return data->type2;
    case 8:  return data->catchRate;
    case 9:  return data->baseExp;
    case 10: return data->evHp;
    case 11: return data->evAttack;
    case 12: return data->evDefense;
    case 13: return data->evSpeed;
    case 14: return data->evSpAttack;
    case 15: return data->evSpDefense;
    case 16: return data->yieldFlag;
    case 17: return data->heldItemCommon;
    case 18: return data->heldItemRare;
    case 19: return data->heldItemDream;
    case 20: return data->genderRatio;
    case 21: return data->eggCycles;
    case 22: return data->baseFriendship;
    case 23: return data->growthRate;
    case 24: return data->eggGroup1;
    case 25: return data->eggGroup2;
    case 26: return data->ability1;
    case 27: return data->ability2;
    case 28: return data->hiddenAbility;
    case 29: return data->escapeRate;
    case 30: return data->formStatsIndex;
    case 31: return data->formSpriteIndex;
    case 32: return data->formCount;
    case 33: return data->color;
    case 34: return data->spriteFlip;
    case 35: return data->formSpriteShared;
    case 36: return data->evoStage;
    case 37: return data->height;
    case 38: return data->weight;
    case 39: return data->tmFlags1;
    case 40: return data->tmFlags2;
    case 41: return data->tmFlags3;
    case 42: return data->tmFlags4;
    case 43: return data->tutorFlags;
    }
    return 0;
}

/*
 * The tail of poke_personal.c: the "is this a placeholder ability id"
 * predicate and the form-table loader.  Cut out of
 * src/matched/unit_0201AE14.c together with src/matched/POKE_PERSONAL_GetParam.c so
 * that the 44 field getter at 0x0201AE1C gets a manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The C is
 * unchanged; only the file boundary moved.  This file still starts at the
 * address of its own first function, so it loses no entry by the same rule:
 * POKE_PERSONAL_LoadFormTable was already an interior function of unit_0201AE14.c.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live here and every one of them is a number the
 * game's data, not its structure, decides:
 *
 *   0x29C (668)  POKE_PERSONAL_LoadFormTable's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          POKE_PERSONAL_LoadFormTable's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF POKE_PERSONAL_IsPlaceholderAbility's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * ---------------------------------------------------------------------------
 * THE TWO FUNCTIONS
 * ---------------------------------------------------------------------------
 * POKE_PERSONAL_IsPlaceholderAbility is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * POKE_PERSONAL_LoadFormTable narrows the byte length the archive hands back to a halfword
 * count with a single `lsls #0xf` / `lsrs #0x10` pair.  The amounts are
 * unequal, so it is a cast folded with a shift and not a bitfield: 32 - 16 is
 * the width and 15 - 16 is the shift, i.e. `(u16)(len >> 1)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * Writing `(u16)(len / 2)` costs a second pair.  The counter's zero is a copy
 * of the accumulator's (`adds r2, r5, #0`), which is what says the
 * accumulator is assigned first
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AF6C.c \
 *       --addr 0x0201AF6C --thumb
 */
u32 POKE_PERSONAL_IsPlaceholderAbility(u32 ability)
{
    if (ability == 0 || ability - 0xFE <= 1) {
        return 1;
    }
    return 0;
}

u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut)
{
    u32 size;
    u16 *table;
    u16 count;
    u16 entryCount;
    u16 i;

    count = 0;
    table = ARC_UTIL_LoadHandleMemberWithSize(_pPersonalArc, 0x29C, 0, heap, &size);
    entryCount = (u16)(size >> 1);
    if (countOut != 0) {
        for (i = 0; i < entryCount; i++) {
            if (table[i] != 999) {
                count++;
            }
        }
        *countOut = count;
    }
    return table;
}

/*
 * The species-to-form resolver the three wrappers in
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c open with: it
 * reads the 0x3C byte personal record for the species out of the archive
 * handle at 0x0214652C and, when the record has a form table and the
 * requested form is inside it, answers with the form's own species-like id.
 *
 * VERSION SENSITIVITY: the guard rejects exactly the two ids 650 and 651,
 * which are the egg and bad-egg entries src/pending/POKE_TOOL_GetBoxValueRaw.c's field
 * map already names, and it spells them as a 16 bit range test.  They are
 * content ids rather than structure offsets, so they are the first thing to
 * re-read for a Pokemon White build; nothing else in this function is
 * version dependent.
 *
 * The test is written `(u16)(species + 0xFD76) > 1`, not `species - 650`:
 * 0x28A does not fit an 8 bit immediate either way, and only the positive
 * unsigned 16 bit spelling of the complement keeps the constant in the pool
 * where the original has it
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md).
 *
 * The three tests in the tail are one disjunction guarding `return species`,
 * not the conjunction guarding the computed answer that the semantics
 * suggest: written the other way round every byte is still right but the two
 * exit blocks are emitted in the opposite order, because the block the source
 * writes inside the `if` is the one that comes first
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md and
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The record's halfword at +0x1C is reached with a plain `ldrh [r0, #0x1c]`
 * while its byte at +0x20 costs an `add r0, sp, #0x20` first, which is only
 * the byte immediate's reach of 31 and not a second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AFD4.c \
 *       --addr 0x0201AFD4 --thumb
 */
u32 POKE_PERSONAL_GetFormDataId(u32 species, s32 form)
{
    struct PersonalData data;

    if ((u16)(species + 0xFD76) <= 1) {
        return 0;
    }
    ARC_TOOL_SeekHandle(_pPersonalArc, ARC_TOOL_GetHandleMemberOffset(_pPersonalArc, species));
    ARC_TOOL_ReadHandle(_pPersonalArc, 0x3C, &data);
    if (data.formStatsIndex == 0 || data.formCount <= form || form == 0) {
        return species;
    }
    return (u16)(data.formStatsIndex + form - 1);
}

/*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0201B0FE.  The rare random event that seeds party record
 *           field 0x97 (see docs/notes/POKERUS_TryInfectParty.c.txt for the draws and
 *           the version-sensitive constants 0x4000/0x8000/0xC000, 7, 0xF3,
 *           content values rather than addresses).  Closed in wave 16: the
 *           packed byte is built as `w = v; w |= (u8)(v << 4);` (the copy is
 *           the image's `adds r3, r0, #0` before the orrs), and the last two
 *           truncations are written inside the call argument, which lets the
 *           final lsls/lsrs pair straddle the argument set-up.
 */
void POKERUS_TryInfectParty(struct Party *party)
{
    u32 infectedMask;
    u32 chance;
    u32 slot;
    struct PokemonParam *member;
    u32 strain;
    u32 pokerus;
    u32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    chance = (u16)((u64)GF_STANDARD_Rand() * 0x10000 >> 32);
    infectedMask = POKERUS_GetInfectedMask(party);
    if (chance == 0x4000 || chance == 0x8000 || chance == 0xC000) {
        do {
            slot = GF_STANDARD_Rand();
            if (memberCount != 0) {
                slot = (u32)(((u64)slot * memberCount) >> 32);
            }
            member = POKEPARTY_GetMember(party, slot);
        } while (POKE_TOOL_GetPartyValue(member, 5, 0) == 0
                 || POKE_TOOL_GetPartyValue(member, 0x4C, 0) != 0);
        if ((infectedMask & (1 << slot)) != 0) {
            return;
        }
        do {
            strain = (u8)((u64)GF_STANDARD_Rand() * 0x100 >> 32);
        } while ((strain & 7) == 0);
        if ((strain & 0xF0) != 0) {
            strain = strain & 7;
        }
        pokerus = strain; pokerus |= (u8)(strain << 4);
        POKE_TOOL_SetPartyValue(member, 0x97, (u8)((u8)(pokerus & 0xF3) + 1));
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The two writers of the packed byte field id 0x97 that
 * src/matched/unit_0201B220.c reads: POKERUS_DecreaseDays counts its low nibble down
 * across the whole party, and POKERUS_SpreadParty spreads it to the neighbouring
 * slots one time in three.
 *
 * POKERUS_DecreaseDays walks every occupied slot, clears the low nibble outright when
 * the amount to subtract is larger than it or larger than 4, subtracts it
 * otherwise, and forces 0x10 when the whole byte comes out zero so that the
 * high nibble stays distinguishable from "never set".  POKERUS_SpreadParty copies a
 * slot's byte into the slot before and the slot after it whenever theirs has
 * no high nibble, and advances the index an extra step when it wrote forwards
 * so that a value cannot propagate down the party in one pass.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  What is content shaped:
 *
 *   4      POKERUS_DecreaseDays's threshold: an amount above it always clears the
 *          nibble instead of subtracting, so it is a rule about the field's
 *          range rather than about its layout.
 *   0x10   the value written when the subtraction leaves zero, i.e. the low
 *          nibble empty and the high nibble at one.
 *   3      POKERUS_SpreadParty's odds, one call in three.
 *   0xF, 0xF0   the two nibble masks, the field's own layout.
 *   0x97, 5   party record ids in src/matched/POKE_TOOL_GetPartyValueRaw.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * POKERUS_SpreadParty's odds are a 64 bit multiply and not a modulo:
 * `(u64)rand() * 3 >> 32` puts the answer in the `_ull_mul` call's **r1**, and
 * the `movs r1, #0` in front of the call is the draw's high half rather than a
 * second argument.  See
 * docs/idioms/random-below-n-is-a-64-bit-multiply-high.md.
 *
 * It has no `last` variable.  The original loads the count once, tests it,
 * decrements it and spills the result, which reads like `last = n - 1` written
 * after an `if (n > 0)` guard; it is not.  It is `if (i < n - 1)` inside the
 * loop, with `n - 1` hoisted into the loop preheader by the compiler, which is
 * why the decrement lands after the loop's own entry guard rather than before
 * it.  Writing the guard and the local out by hand costs six bytes.
 *
 * POKERUS_DecreaseDays's two arms are not spelled the same way.  The masking arm is a
 * compound assignment, `v &= 0xF0`, and the subtracting arm carries an explicit
 * `(u8)` cast; written with the cast on both, the two truncations cross-jump
 * into one block that both arms branch to and the function is four bytes
 * short.  That is
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md
 * seen on a local rather than on a field: the compound form is the one that
 * does not materialise a fresh truncation.
 *
 * Both loop counters are signed, and in POKERUS_DecreaseDays the amount and the
 * extracted nibble are signed too: the comparisons are `blt` and `ble`, not
 * `blo` and `bls`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B100.c \
 *       --addr 0x0201B100 --thumb
 */
void POKERUS_DecreaseDays(struct Party *party, s32 days)
{
    s32 memberCount;
    struct PokemonParam *member;
    s32 i;
    u8 pokerus;
    s32 daysLeft;

    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        member = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(member, 5, 0) == 0) {
            continue;
        }
        pokerus = (u8)POKE_TOOL_GetPartyValue(member, 0x97, 0);
        daysLeft = pokerus & 0xF;
        if (daysLeft == 0) {
            continue;
        }
        if (daysLeft < days || days > 4) {
            pokerus &= 0xF0;
        } else {
            pokerus = (u8)(pokerus - (u8)days);
        }
        if (pokerus == 0) {
            pokerus = 0x10;
        }
        POKE_TOOL_SetPartyValue(member, 0x97, pokerus);
    }
}

void POKERUS_SpreadParty(struct Party *party)
{
    s32 i;
    struct PokemonParam *member;
    struct PokemonParam *neighbor;
    u8 pokerus;
    s32 memberCount;

    memberCount = POKEPARTY_GetCount(party);
    if ((u32)((u64)GF_STANDARD_Rand() * 3 >> 32) != 0) {
        return;
    }
    for (i = 0; i < memberCount; i++) {
        member = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(member, 5, 0) == 0) {
            continue;
        }
        pokerus = (u8)POKE_TOOL_GetPartyValue(member, 0x97, 0);
        if ((pokerus & 0xF) == 0) {
            continue;
        }
        if (i != 0) {
            neighbor = POKEPARTY_GetMember(party, i - 1);
            if ((POKE_TOOL_GetPartyValue(neighbor, 0x97, 0) & 0xF0) == 0) {
                POKE_TOOL_SetPartyValue(neighbor, 0x97, pokerus);
            }
        }
        if (i < memberCount - 1) {
            neighbor = POKEPARTY_GetMember(party, i + 1);
            if ((POKE_TOOL_GetPartyValue(neighbor, 0x97, 0) & 0xF0) == 0) {
                POKE_TOOL_SetPartyValue(neighbor, 0x97, pokerus);
                i++;
            }
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           POKERUS_IsBoxCured
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * POKERUS_GetInfectedMask answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  POKERUS_IsBoxInfected asks whether the low nibble is set and
 * POKERUS_IsBoxCured whether the high nibble is set and the low one is not;
 * POKERUS_IsInfected and POKERUS_IsCured are their two-instruction wrappers over
 * POKE_TOOL_Dummy.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/POKE_TOOL_GetPartyValueRaw.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * POKERUS_GetInfectedMask assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * POKERUS_IsBoxCured reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; POKERUS_IsBoxInfected
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 POKERUS_GetInfectedMask(struct Party *party)
{
    s32 i;
    u32 infectedMask;
    s32 memberCount;

    infectedMask = 0;
    memberCount = POKEPARTY_GetCount(party);
    for (i = 0; i < memberCount; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 0x97, 0) != 0) {
            infectedMask |= (u8)(1 << i);
        }
    }
    return infectedMask;
}

u32 POKERUS_IsInfected(struct PokemonParam *pp)
{
    return POKERUS_IsBoxInfected(POKE_TOOL_Dummy(pp));
}

u32 POKERUS_IsBoxInfected(struct BoxPokemon *box)
{
    u32 result;

    result = 0;
    if ((POKE_TOOL_GetBoxValue(box, 0x97, 0) & 0xF) != 0) {
        result = 1;
    }
    return result;
}

u32 POKERUS_IsCured(struct PokemonParam *pp)
{
    return POKERUS_IsBoxCured(POKE_TOOL_Dummy(pp));
}

u32 POKERUS_IsBoxCured(struct BoxPokemon *box)
{
    u32 result;
    u8 pokerus;

    result = 0;
    pokerus = (u8)POKE_TOOL_GetBoxValue(box, 0x97, 0);
    if ((pokerus & 0xF) == 0 && (pokerus & 0xF0) != 0) {
        result = 1;
    }
    return result;
}
