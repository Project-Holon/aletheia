/*
 * function: sub_02040968
 * address:  0x02040968
 * packet:   pkt_02040618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020834C0  0x020834C0  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02082A60  0x02082A60  arm
 *
 * A copy that picks its word width from the operands.  A zero length goes
 * to func_020834C0 (the SDK's own degenerate-copy path, reached with all
 * three arguments still in place).  Otherwise the 32-bit copy is taken only
 * when both pointers are word aligned and the length is a whole number of
 * words; anything else falls back to the byte copy.
 *
 * The three tests share one exit, so they are one conjunction rather than
 * three separate `if`s
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md),
 * and the fall-through arm is the 32-bit copy.  Writing the byte copy as
 * the fall-through instead inverts all three branch conditions and swaps
 * the two call targets, five bytes wrong
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The length test is the tell for the parameter's type.  It compiles to a
 * zero-extending 16-bit shift pair followed by the signed remainder
 * sequence (`lsr ip, r3, #31` / `rsb r3, ip, r3, lsl #30` /
 * `adds r3, ip, r3, ror #30`), which is what `% 4` on an `int` produces.
 * Both halves are needed: the shift pair says the value is narrowed to 16
 * bits first, and the signed form says the narrowed value then sits in a
 * plain `int` by integer promotion.  A `u32 size % 4` would have been a
 * bare `tst r2, #3` like the two alignment tests just above it, and a
 * `u16 size % 4` with no cast would not have needed the shift pair at the
 * remainder rather than at the `size == 0` test.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02040968.c \
 *       --func sub_02040968 --addr 0x02040968 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020834C0(void *dest, const void *src, u32 size);
extern void func_02082A90(void *dest, const void *src, u32 size);
extern void func_02082A60(void *dest, const void *src, u32 size);

void sub_02040968(void *dest, const void *src, u32 size)
{
    if (size == 0) {
        func_020834C0(dest, src, size);
        return;
    }

    if (((u32)dest & 3) == 0 && ((u32)src & 3) == 0 && ((u16)size % 4) == 0) {
        func_02082A90(dest, src, size);
        return;
    }

    func_02082A60(dest, src, size);
}

