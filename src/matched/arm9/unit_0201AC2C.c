/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201AC2C
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKEPARTY_Copy, POKEPARTY_HasSpecies, POKEPARTY_GetAliveNonEggCount, POKEPARTY_GetSlotFlag,
 *           POKEPARTY_SetSlotFlag, POKEPARTY_GetSaveData, POKEPARTY_IsBattleReady, POKEPARTY_IsNotEgg,
 *           POKEPARTY_FindFirst
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
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

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

struct Rec534 {
    u32 unk000[0x14D];
};

void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst)
{
    *dst = *src;
}

struct Rec {
    u32 unk00;
    s32 unk04;
    u8  unk08[1];
};

u32 POKEPARTY_HasSpecies(struct Rec *p, u32 target)
{
    s32 i;

    for (i = 0; i < p->unk04; i++) {
        void *entry = &p->unk08[i * 0xDC];

        if (POKE_TOOL_GetPartyValue(entry, 5, 0) == target) {
            break;
        }
    }
    if (i == p->unk04) {
        return 0;
    }
    return 1;
}

extern u32   POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);

u32 POKEPARTY_GetAliveNonEggCount(void *p)
{
    s32 n = POKEPARTY_GetCount(p);
    s32 i, count = 0;

    for (i = 0; i < n; i++) {
        void *entry = POKEPARTY_GetMember(p, i);

        if (POKE_TOOL_GetPartyValue(entry, 0xA0, 0)) {
            if (!POKE_TOOL_GetPartyValue(entry, 0x4C, 0)) {
                count++;
            }
        }
    }
    return count;
}

int POKEPARTY_GetSlotFlag(void *p, u32 pos)
{
    u8 b = ((u8 *)p)[0x530];

    if (b & (1u << pos)) {
        return 1;
    }
    return 0;
}

void POKEPARTY_SetSlotFlag(void *p, u32 pos, u32 mode)
{
    if (mode == 1) {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] | (1u << pos);
    } else {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] & (0xFFu - (1u << pos));
    }
}

struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

void *POKEPARTY_GetSaveData(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, 0x1A);
}

u32 POKEPARTY_IsBattleReady(void *p)
{
    u32 a = POKE_TOOL_GetPartyValue(p, 0x4C, 0);
    u32 b = POKE_TOOL_GetPartyValue(p, 0xA0, 0);

    if (a != 1 && b != 0) {
        return 1;
    }
    return 0;
}

u32 POKEPARTY_IsNotEgg(void *p)
{
    u32 r = 0;

    if (POKE_TOOL_GetPartyValue(p, 0x4C, 0) != 1) {
        r = 1;
    }
    return r;
}

typedef u32 (*Predicate)(void *entry);

u32 POKEPARTY_FindFirst(void *p, Predicate pred)
{
    s32 i;
    s32 n = POKEPARTY_GetCount(p);

    for (i = 0; i < n; i++) {
        void *entry = POKEPARTY_GetMember(p, i);

        if (pred(entry)) {
            return i;
        }
    }
    return n;
}
