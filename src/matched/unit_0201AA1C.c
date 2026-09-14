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
 * function: sub_0201AA1C, sub_0201AA50, sub_0201AA88, sub_0201AAD4,
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
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
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern s32  sub_0201AA18(void *p);
extern void *sub_0201AB28(void *p, s32 idx);
extern u32  func_02017E1C(void *entry, u32 id, u32 v);
extern u32  sub_0201AD18(void *entry);
extern u32  sub_0201AD40(void *entry);

typedef u32 (*Predicate)(void *entry);

extern u32 sub_0201AD58(void *p, Predicate pred);

u32 sub_0201AA1C(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 0x4C, 0) != 1) {
            n++;
        }
    }
    return n;
}

u32 sub_0201AA50(void *p)
{
    u32 n = 0;
    s32 count;
    s32 i;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        sub_0201AB28(p, i);
        if (sub_0201AD18(sub_0201AB28(p, i)) != 0) {
            n++;
        }
    }
    return n;
}

u32 sub_0201AA88(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);
        u32 a = func_02017E1C(entry, 0x4C, 0);
        u32 b = func_02017E1C(entry, 3, 0);

        if (a == 1 && b == 0) {
            n++;
        }
    }
    return n;
}

u32 sub_0201AAD4(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 3, 0) == 1) {
            n++;
        }
    }
    return n;
}

u32 sub_0201AB08(void *p)
{
    return sub_0201AD58(p, sub_0201AD18);
}

u32 sub_0201AB18(void *p)
{
    return sub_0201AD58(p, sub_0201AD40);
}
