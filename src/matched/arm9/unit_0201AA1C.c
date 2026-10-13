/*
 * unit:     yes
 * address:  0x0201AA1C
 * packet:   pkt_0201AA1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKEPARTY_GetNonEggCount, POKEPARTY_GetBattleReadyCount, POKEPARTY_GetEggCount, POKEPARTY_GetBadEggCount,
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
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_IsBattleReady  0x0201AD18  thumb
 *   POKEPARTY_IsNotEgg  0x0201AD40  thumb
 *   POKEPARTY_FindFirst  0x0201AD58  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned int u32;
typedef int s32;

extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32  POKE_TOOL_GetPartyValue(void *entry, u32 id, u32 v);
extern u32  POKEPARTY_IsBattleReady(void *entry);
extern u32  POKEPARTY_IsNotEgg(void *entry);

typedef u32 (*Predicate)(void *entry);

extern u32 POKEPARTY_FindFirst(void *p, Predicate pred);

u32 POKEPARTY_GetNonEggCount(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = POKEPARTY_GetCount(p);
    for (i = 0; i < count; i++) {
        void *entry = POKEPARTY_GetMember(p, i);

        if (POKE_TOOL_GetPartyValue(entry, 0x4C, 0) != 1) {
            n++;
        }
    }
    return n;
}

u32 POKEPARTY_GetBattleReadyCount(void *p)
{
    u32 n = 0;
    s32 count;
    s32 i;

    count = POKEPARTY_GetCount(p);
    for (i = 0; i < count; i++) {
        POKEPARTY_GetMember(p, i);
        if (POKEPARTY_IsBattleReady(POKEPARTY_GetMember(p, i)) != 0) {
            n++;
        }
    }
    return n;
}

u32 POKEPARTY_GetEggCount(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = POKEPARTY_GetCount(p);
    for (i = 0; i < count; i++) {
        void *entry = POKEPARTY_GetMember(p, i);
        u32 a = POKE_TOOL_GetPartyValue(entry, 0x4C, 0);
        u32 b = POKE_TOOL_GetPartyValue(entry, 3, 0);

        if (a == 1 && b == 0) {
            n++;
        }
    }
    return n;
}

u32 POKEPARTY_GetBadEggCount(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = POKEPARTY_GetCount(p);
    for (i = 0; i < count; i++) {
        void *entry = POKEPARTY_GetMember(p, i);

        if (POKE_TOOL_GetPartyValue(entry, 3, 0) == 1) {
            n++;
        }
    }
    return n;
}

u32 POKEPARTY_FindFirstBattleReady(void *p)
{
    return POKEPARTY_FindFirst(p, POKEPARTY_IsBattleReady);
}

u32 POKEPARTY_FindFirstNonEgg(void *p)
{
    return POKEPARTY_FindFirst(p, POKEPARTY_IsNotEgg);
}
