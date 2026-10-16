/*
 * function: BRIGHTNESS_ChangeStep
 * address:  0x02023E0C
 * packet:   pkt_02023E0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * wipe_sub.c: the per-frame step of the brightness/blend interpolation
 * record that BRIGHTNESS_ChangeInit arms (docs/families/wipe_sub.h, struct Interp).
 * It advances the record's running position f1a towards the target f0a by
 * the per-step delta f14 scaled by the sign f10, pushes the result to the
 * hardware register of whichever engine the f04 bit mask selects, and
 * clears the active flag f1c once the target is reached.
 *
 * FOUR SPELLINGS ARE LOAD-BEARING.  The earlier note
 * (docs/notes/pkt_02023E0C.c.txt) read this function as a whole-function
 * register permutation the allocator would not move; it is not.  It is
 * four shape decisions, and with them the allocation falls out on its own.
 * The note's own draft is 140 bytes against 144 with 127 concrete bytes
 * out; each of the four below is worth a measured step:
 *
 *   1. THE TWO POINTER LOCALS ARE HOISTED to the top of the else arm,
 *      before the f18 accumulate and its test, not created inside the
 *      inner `if`.  This is the whole four-byte size gap: the image emits
 *      `adds r3, r4, #0 / adds r2, r4, #0 / adds r3, #0x1a / adds r2,
 *      #0x18` unconditionally on the else path.  127 bytes out -> 76.
 *
 *   2. THE MULTIPLY IS `step * p->f14`, not `p->f14 * step`.  The image's
 *      `muls r1, r0, r1` keeps `step` in the accumulator, and the
 *      accumulator holds the chain's SECOND operand
 *      (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-
 *      operand.md).  24 bytes out -> 19.
 *
 *   3. BOTH `if`s ARE WRITTEN WITH THE NEGATED CONDITION, so the arm the
 *      image falls through into is the source's first
 *      (docs/idioms/the-fall-through-arm-is-the-source-order.md).  The
 *      outer one is `if (target != cur + v && cur != target) { <advance> }
 *      else { <snap to target> }`, and the inner one is `if (p->f1a !=
 *      target) { <decrement the timer> } else { flag = 1; }`.  Written the
 *      other way round the image's two `beq` to one target come out as a
 *      `beq`/`bne` pair and everything after shifts by one instruction.
 *      76 -> 24 for the outer, 19 -> 8 for the inner.
 *
 *   4. `cur` IS A NAMED LOCAL read BEFORE `target`.  This is the last
 *      eight bytes.  The image loads f1a (offset 0x1a) and only then f0a
 *      (offset 0xa); with `p->f1a` left inline in the condition the
 *      compiler evaluates `target = p->f0a` first and the two `movs
 *      #imm`/`ldrsh` pairs come out in the other order.  Binding the f1a
 *      read to its own local ahead of `target` pins it
 *      (docs/idioms/cmp-operand-order-names-the-temporary.md is the same
 *      tell).  8 -> 0.
 *
 * Statement order of `flag = 0` is NOT a lever: first, second, third and
 * fourth position all compile identically (the compiler sinks the zero to
 * where the image has it, `movs r7, #0` after the two loads).  That was
 * measured, not assumed.
 *
 * Two further facts confirming the earlier note's structural reads, which
 * did survive: the two entry tests really are one `||` (here written as
 * the negated `&&`), and the f1a store is `p->f1a + (s16)v` so the
 * truncation is on the delta and not on the sum -- the image's `lsls
 * r1,r1,#0x10 / asrs r1,r1,#0x10` narrows v alone.  The engine register
 * words are the plain constants 0x04000050 and 0x04001050; the second is
 * NOT 0x04001000 + 0x50 computed at run time, as src/pending/
 * BRIGHTNESS_ChangeRequest.c's header already records for the sibling.
 *
 * The two arms of the engine select tail-merge onto one call site, which
 * is what the image's shared `movs r2,#0x1a / ldrsh / ldr r1,[r4] / blx`
 * at +0x74 is; writing the two calls out in full is what produces it
 * (docs/idioms/switch-arms-tail-merge.md).
 *
 * Nothing here is version specific: 0x04000050 and 0x04001050 are DS
 * hardware register addresses and every other constant is a field offset
 * or a flag bit.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BRIGHTNESS_ChangeStep.c \
 *       --func BRIGHTNESS_ChangeStep --addr 0x02023E0C --cc 1.1p1 --thumb
 *
 * symbols:
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Anim {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0a;
    u16 f0c;
    u16 f0e;
    s8  f10;
    u8  f11;
    u16 f12;
    s16 f14;
    u16 f16;
    u16 f18;
    s16 f1a;
    u32 f1c;
};

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

void BRIGHTNESS_ChangeStep(struct Anim *p)
{
    s8  step;
    int v;
    s16 target;
    int flag;
    u16 *timer;
    s16 *pos;
    s16 cur;

    step = p->f10;
    v = step * p->f14;
    cur = p->f1a;
    target = p->f0a;
    flag = 0;
    if (target != cur + v && cur != target) {
        p->f1a = p->f1a + (s16)v;
        pos = &p->f1a;
        timer = &p->f18;
        p->f18 = p->f18 + p->f16;
        if ((u16)p->f18 >= (u16)p->f08) {
            *pos = (s16)*pos + step;
            if (p->f1a != target) {
                *timer = *timer - p->f08;
            } else {
                flag = 1;
            }
        }
    } else {
        p->f1a = target;
        flag = 1;
    }
    if (p->f04 & 1) {
        G2x_SetBlendBrightness_((u32)((void *)0x04000050), p->f00, p->f1a);
    } else if (p->f04 & 2) {
        G2x_SetBlendBrightness_((u32)((void *)0x04001050), p->f00, p->f1a);
    }
    if (flag == 1)
        p->f1c = 0;
}
