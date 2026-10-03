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
 * function: sub_0201AC2C, sub_0201AC44, sub_0201AC80, sub_0201ACC4,
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
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
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);

struct Rec534 {
    u32 unk000[0x14D];
};

void sub_0201AC2C(const struct Rec534 *src, struct Rec534 *dst)
{
    *dst = *src;
}

struct Rec {
    u32 unk00;
    s32 unk04;
    u8  unk08[1];
};

u32 sub_0201AC44(struct Rec *p, u32 target)
{
    s32 i;

    for (i = 0; i < p->unk04; i++) {
        void *entry = &p->unk08[i * 0xDC];

        if (func_02017E1C(entry, 5, 0) == target) {
            break;
        }
    }
    if (i == p->unk04) {
        return 0;
    }
    return 1;
}

extern u32   sub_0201AA18(void *p);
extern void *sub_0201AB28(void *p, u32 idx);

u32 sub_0201AC80(void *p)
{
    s32 n = sub_0201AA18(p);
    s32 i, count = 0;

    for (i = 0; i < n; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 0xA0, 0)) {
            if (!func_02017E1C(entry, 0x4C, 0)) {
                count++;
            }
        }
    }
    return count;
}

int sub_0201ACC4(void *p, u32 pos)
{
    u8 b = ((u8 *)p)[0x530];

    if (b & (1u << pos)) {
        return 1;
    }
    return 0;
}

void sub_0201ACDC(void *p, u32 pos, u32 mode)
{
    if (mode == 1) {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] | (1u << pos);
    } else {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] & (0xFFu - (1u << pos));
    }
}

struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *sub_0201AD0C(void *sys)
{
    return sub_020071CC(sys, 0x1A);
}

u32 sub_0201AD18(void *p)
{
    u32 a = func_02017E1C(p, 0x4C, 0);
    u32 b = func_02017E1C(p, 0xA0, 0);

    if (a != 1 && b != 0) {
        return 1;
    }
    return 0;
}

u32 sub_0201AD40(void *p)
{
    u32 r = 0;

    if (func_02017E1C(p, 0x4C, 0) != 1) {
        r = 1;
    }
    return r;
}

typedef u32 (*Predicate)(void *entry);

u32 sub_0201AD58(void *p, Predicate pred)
{
    s32 i;
    s32 n = sub_0201AA18(p);

    for (i = 0; i < n; i++) {
        void *entry = sub_0201AB28(p, i);

        if (pred(entry)) {
            return i;
        }
    }
    return n;
}
