/*
 * file:     brightness.c
 * unit:     yes
 * function: BRIGHTNESS_ChangeStep, BRIGHTNESS_ChangeInit, BRIGHTNESS_ChangeRequest, BRIGHTNESS_Set, BRIGHTNESS_ChangeReset, BRIGHTNESS_ChangeMain, BRIGHTNESS_IsFinished
 * address:  0x02023E0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   G2x_SetBlendBrightness_   0x0207D658  arm
 *   g_brightnessMain    0x0214691C  data
 *   g_brightnessRecords   0x021468FC  data
 *   g_brightnessSub  0x021468FC  data
 */
#include "../types.h"

struct BrightnessChange {
    u32 plane;
    u32 screenMask;
    u16 steps;
    u16 endValue;
    u16 reservedA;
    u16 reservedB;
    signed char direction;
    u8  reservedC;
    s16 distance;
    s16 stepValue;
    u16 remainder;
    u16 remainderSum;
    s16 current;
    u32 active;
};

extern void  MI_CpuFill8(void *p, u32 v, u32 n);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
void BRIGHTNESS_ChangeStep(struct BrightnessChange *p);
void BRIGHTNESS_ChangeInit(struct BrightnessChange *p, u16 steps, s16 from, s16 to, u32 plane, u32 screenMask);
void BRIGHTNESS_ChangeRequest(u16 steps, s16 from, s16 to, u32 plane, u32 mask);
void BRIGHTNESS_Set(u32 brightness, u32 plane, u32 mask);
void BRIGHTNESS_ChangeReset(u32 mask);
void BRIGHTNESS_ChangeMain(void);
int BRIGHTNESS_IsFinished(int a);

/* stand-in (literal pool): g_brightnessSub and g_brightnessRecords are two names for the one address 0x021468FC, the sub record followed by the main record, because the pool holds that base twice; g_brightnessMain is the main record, 0x20 bytes on */
extern struct BrightnessChange g_brightnessMain;

extern struct BrightnessChange g_brightnessSub;
extern struct BrightnessChange g_brightnessRecords[2];

/*
 * wipe_sub.c: the per-frame step of the brightness/blend interpolation
 * record that BRIGHTNESS_ChangeInit arms (docs/families/wipe_sub.h, struct BrightnessChange).
 * It advances the record's running position current towards the target endValue by
 * the per-step delta stepValue scaled by the sign direction, pushes the result to the
 * hardware register of whichever engine the screenMask bit mask selects, and
 * clears the active flag active once the target is reached.
 *
 * FOUR SPELLINGS ARE LOAD-BEARING.  The earlier note
 * (docs/notes/pkt_02023E0C.c.txt) read this function as a whole-function
 * register permutation the allocator would not move; it is not.  It is
 * four shape decisions, and with them the allocation falls out on its own.
 * The note's own draft is 140 bytes against 144 with 127 concrete bytes
 * out; each of the four below is worth a measured step:
 *
 *   1. THE TWO POINTER LOCALS ARE HOISTED to the top of the else arm,
 *      before the remainderSum accumulate and its test, not created inside the
 *      inner `if`.  This is the whole four-byte size gap: the image emits
 *      `adds r3, r4, #0 / adds r2, r4, #0 / adds r3, #0x1a / adds r2,
 *      #0x18` unconditionally on the else path.  127 bytes out -> 76.
 *
 *   2. THE MULTIPLY IS `step * p->stepValue`, not `p->stepValue * step`.  The image's
 *      `muls r1, r0, r1` keeps `step` in the accumulator, and the
 *      accumulator holds the chain's SECOND operand
 *      (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-
 *      operand.md).  24 bytes out -> 19.
 *
 *   3. BOTH `if`s ARE WRITTEN WITH THE NEGATED CONDITION, so the arm the
 *      image falls through into is the source's first
 *      (docs/idioms/the-fall-through-arm-is-the-source-order.md).  The
 *      outer one is `if (target != cur + v && cur != target) { <advance> }
 *      else { <snap to target> }`, and the inner one is `if (p->current !=
 *      target) { <decrement the timer> } else { flag = 1; }`.  Written the
 *      other way round the image's two `beq` to one target come out as a
 *      `beq`/`bne` pair and everything after shifts by one instruction.
 *      76 -> 24 for the outer, 19 -> 8 for the inner.
 *
 *   4. `cur` IS A NAMED LOCAL read BEFORE `target`.  This is the last
 *      eight bytes.  The image loads current and only then endValue; with `p->current` left inline in the condition the
 *      compiler evaluates `target = p->endValue` first and the two `movs
 *      #imm`/`ldrsh` pairs come out in the other order.  Binding the current
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
 * the negated `&&`), and the current store is `p->current + (s16)v` so the
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
 */
void BRIGHTNESS_ChangeStep(struct BrightnessChange *p)
{
    s8  step;
    int v;
    s16 target;
    int flag;
    u16 *timer;
    s16 *pos;
    s16 cur;

    step = p->direction;
    v = step * p->stepValue;
    cur = p->current;
    target = p->endValue;
    flag = 0;
    if (target != cur + v && cur != target) {
        p->current = p->current + (s16)v;
        pos = &p->current;
        timer = &p->remainderSum;
        p->remainderSum = p->remainderSum + p->remainder;
        if ((u16)p->remainderSum >= (u16)p->steps) {
            *pos = (s16)*pos + step;
            if (p->current != target) {
                *timer = *timer - p->steps;
            } else {
                flag = 1;
            }
        }
    } else {
        p->current = target;
        flag = 1;
    }
    if (p->screenMask & 1) {
        G2x_SetBlendBrightness_((u32)((void *)0x04000050), p->plane, p->current);
    } else if (p->screenMask & 2) {
        G2x_SetBlendBrightness_((u32)((void *)0x04001050), p->plane, p->current);
    }
    if (flag == 1)
        p->active = 0;
}

/*
 * Initialises the 0x20-byte interpolation record the packet's other two
 * functions drive. The two stack arguments are widened through the usual
 * lsls/lsrs #0x18 pair into the full words at +0x00 and +0x04, so they are
 * int-typed parameters narrowed with a (u8) cast, not u8 parameters.
 *
 * Field roles: steps = step count, endValue = from, current = to, distance = |to - from|,
 * direction = the sign (+1 or -1), stepValue = per-step delta, remainder = its remainder,
 * remainderSum = the running accumulator (cleared here), active = the active flag.
 *
 * Three spellings are load-bearing and were each isolated against the
 * bytes:
 *   - `p->active = 1;` must be the FIRST statement. The constant 1 has to
 *     land in r0 before the two stack arguments are widened; written
 *     anywhere later in the block the allocator promotes it to r6 and the
 *     whole entry block shifts register bank (19 and 14 bytes wrong for
 *     the two later positions tried).
 *   - the negation re-reads the field: the original is `ldrsh` + `subs
 *     r1,#0x13` + `muls`, four bytes more than the `rsbs` the compiler
 *     folds from a cached value. The volatile-qualified read is what
 *     defeats that fold; without it the function compiles 84 bytes, not
 *     88. The `-1` multiplier and the `-1` stored to direction in the other arm
 *     share one register, derived from the distance field offset.
 *   - `/` and `%` on the same operands are two separate _s32_div_f calls
 *     (docs/idioms/div-and-mod-are-two-calls.md); stepValue takes the quotient
 *     from r0 and remainder the remainder from r1.
 */
void BRIGHTNESS_ChangeInit(struct BrightnessChange *p, u16 steps, s16 from, s16 to,
                   u32 plane, u32 screenMask)
{
    p->active = 1;
    p->plane = (u8)plane;
    p->screenMask = (u8)screenMask;
    p->distance = to - from;
    p->steps = steps;
    p->current = to;
    p->endValue = from;

    if (p->distance > 0) {
        p->direction = -1;
    } else {
        p->direction = 1;
        p->distance = *(volatile s16 *)&p->distance * -1;
    }

    p->stepValue = p->distance / steps;
    p->remainder = p->distance % steps;
    p->remainderSum = 0;
}

/*
 * Front end for BRIGHTNESS_ChangeInit: given a record pointer and a two-bit engine
 * mask, it arms the record once per selected engine. Each arm first sets
 * the hardware blend-brightness register for that engine to the starting
 * value through G2x_SetBlendBrightness_ (0x0207D658), then calls
 * BRIGHTNESS_ChangeInit with the shared step/from/to triple and the two stack
 * arguments (the starting value, and the engine bit itself as the tag).
 *
 * The two pool words 0x04000050 and 0x04001050 are the main and sub
 * engine's BLDCNT/BLDY block; both arms are written out in full rather
 * than factored behind a helper, which is what keeps them as two separate
 * call sequences rather than one tail-merged site.
 *
 * Note the second engine's register word is the plain constant 0x04001050
 * in the pool, not 0x04000050 + 0x1000 computed at run time.
 *
 * RESOLVED 2026-09-21 (wave3 wipe_sub). This file sat in src/pending at
 * MATCH with the note below blaming a missing `literal` witness for the two
 * ABS32 pool words. The blocker was not evidentiary: the symbols block named
 * the tables at 0x0202691C and 0x020268FC, but the ROM pool words at
 * 0x02023F54 and 0x02023F5C are 0x0214691C and 0x021468FC. Because a MATCH
 * wildcards the relocation field, the wrong address was never compared and
 * the typo read as an attestation failure. With the real addresses both
 * sites resolve as `literal` (6 and 12 witnesses image-wide, e.g. the pool
 * words at 0x02023FCC and 0x02023FD0 in the neighbouring unit) and the
 * function is EXACT. Earlier prose, kept for the record:
 *
 * [stale] capped at MATCH; blocking evidence class literal; neither word
 * appears in any literal pool at another address. -- wrong on both counts,
 * see above.
 *
 * Both engines pass the same record pointer p to BRIGHTNESS_ChangeInit; the first
 * argument is the engine's own descriptor table, and the last argument is
 * the engine bit (1 or 2), which BRIGHTNESS_ChangeInit stores to screenMask.
 *
 * G2x_SetBlendBrightness_ takes three arguments (addr, plane, brightness)
 * and both arms pass all three. The first arm emits no `mov r2` because
 * `from` is still live in r2 from entry; the second arm reloads it from r6
 * after the intervening call. An earlier spelling declared a two-argument
 * extern for the first arm, which matched the bytes but left r2 unnamed
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 */
void BRIGHTNESS_ChangeRequest(u16 steps, s16 from, s16 to, u32 plane, u32 mask)
{
    if (steps == 0) {
        return;
    }

    if (mask & 1) {
        G2x_SetBlendBrightness_(0x04000050, plane, to);
        BRIGHTNESS_ChangeInit(&g_brightnessMain, steps, from, to, plane, 1);
    }

    if (mask & 2) {
        G2x_SetBlendBrightness_(0x04001050, plane, to);
        BRIGHTNESS_ChangeInit(&g_brightnessSub, steps, from, to, plane, 2);
    }
}

void BRIGHTNESS_Set(u32 brightness, u32 plane, u32 mask)
{
    if (mask & 1) {
        G2x_SetBlendBrightness_(0x04000050, plane, brightness);
    }
    if (mask & 2) {
        G2x_SetBlendBrightness_(0x04001050, plane, brightness);
    }
    BRIGHTNESS_ChangeReset(mask);
}

/*
 * The teardown counterpart of BRIGHTNESS_ChangeRequest: given the same two-bit engine
 * mask, it zeroes each selected engine's 0x20-byte blend record and clears
 * that engine's active flag.  Main engine's record is at 0x0214691C and its
 * flag at 0x021468FC+0x3c; the sub engine's record is at 0x021468FC+0x20
 * and its flag at 0x021468FC+0x1c.  The two arms are written out in full.
 *
 * THE POOL HAS A DUPLICATE OF 0x021468FC, AND WHICH USES SHARE A SLOT IS
 * THE WHOLE FINDING.  The three pool words are
 *
 *     0x02023FCC  .word 0x0214691C     <- arm 1's memset base
 *     0x02023FD0  .word 0x021468FC     <- BOTH flag stores
 *     0x02023FD4  .word 0x021468FC     <- arm 2's memset base
 *
 * mwccarm emits one pool word per source SYMBOL, in order of first use, so
 * the slot count and the sharing pattern read straight back as the number of
 * distinct externs and which statements name which.  The obvious spelling --
 * one `g_brightnessSub` at 0x021468FC for all three of its uses -- CSEs the two
 * 0x021468FC references into one slot, and the third slot then re-emits
 * 0x0214691C: 64 bytes, every instruction right, two bytes out at 0x02023FD4
 * and nothing any amount of statement shuffling reaches (63 single mutations
 * and a full permuter.py hill pass left it untouched, because it is a pool
 * layout decision, not an allocation one).
 *
 * What reproduces it is TWO distinct externs at 0x021468FC, split along the
 * image's own sharing: `g_brightnessRecords` names the object both arms' flag stores
 * reach (+0x3c for main, +0x1c for sub, one slot between them) and
 * `g_brightnessSub` names the one arm 2 memsets (its own slot).  Whether the
 * original really had two objects at one address or one object the compiler
 * saw through two declarations is not decidable from the bytes; what the
 * bytes do fix is that three source-level names were in play, not two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BRIGHTNESS_ChangeReset.c \
 *       --func BRIGHTNESS_ChangeReset --addr 0x02023F98 --cc 1.1p1 --thumb
 */
void BRIGHTNESS_ChangeReset(u32 mask)
{
    if (mask & 1) {
        MI_CpuFill8(&g_brightnessMain, 0, 0x20);
        g_brightnessRecords[1].active = 0;
    }
    if (mask & 2) {
        MI_CpuFill8(&g_brightnessSub, 0, 0x20);
        g_brightnessRecords[0].active = 0;
    }
}

/*
 *           outside 02023FD8..02024004; the only two branches to it in the
 *           image are these two
 *
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 44 concrete bytes (30 of code, then three literal words) reproduce
 * exactly.  The listing extent is 108 because the next labelled start in
 * asm/arm9/src/008_02021014.s is 0x02024044; the 64 bytes between are the
 * unlabelled function at 0x02024004 and its pool, so the entry also carries
 * the `*` of a listing-extent mismatch.  The worklist size is 32 code bytes.
 *
 * Two guards on a global struct: the word at +0x3C first, then the word at
 * +0x1C, each calling BRIGHTNESS_ChangeStep with a global address when it is set.
 *
 * The pool is THREE words and the first and third hold the same address
 * 0x021468FC.  mwccarm emits a pool word per source symbol, so a source that
 * reached the same object through one name would have CSEd the two loads into
 * one slot and one register (which is what the obvious spelling does: it
 * compares the field in r1 and reuses r0 for the call argument, 40 bytes).
 * The original loads the base twice, from two slots, so it is written here
 * with two names for the one address, g_brightnessRecords for the field base and
 * g_brightnessSub for the second call's argument.  That is the whole difference
 * between DIFF and MATCH here; both declarations are the same claim and both
 * are attested `literal` from outside (x6 from 0x02023F5C and friends).
 *
 * It cannot reach EXACT while BRIGHTNESS_ChangeStep is unfiled: 0x02023E0C is
 * labelled in the listings but every branch to it image-wide is one of these
 * two, so the `label` class has no witness outside the compared range.  It
 * closes the day 0x02023E0C gets a manifest entry (a large function outside
 * the 0-64 byte band, so not this lane's work), and that also releases
 * src/pending/GFL_USE_UpdateFrameSubsystems.c, whose first site names this address.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BRIGHTNESS_ChangeMain.c \
 *       --func BRIGHTNESS_ChangeMain --addr 0x02023FD8 --cc 1.1p1 --thumb
 */
void BRIGHTNESS_ChangeMain(void)
{
    if (g_brightnessRecords[1].active != 0) {
        BRIGHTNESS_ChangeStep(&g_brightnessMain);
    }
    if (g_brightnessRecords[0].active != 0) {
        BRIGHTNESS_ChangeStep(&g_brightnessSub);
    }
}

/*
 * Unlabelled Thumb leaf (no prologue, so disasm.py prints the run as ARM
 * data). A three-way guard on the object at 0x021468FC: mode 3 needs both
 * the +0x3C and +0x1C words clear, mode 1 only +0x3C, mode 2 only +0x1C;
 * anything else returns 0. The pointer is loaded from the pool word at
 * 0x02024040.
 *
 * Addresses are Black-image addresses.
 */
int BRIGHTNESS_IsFinished(int a)
{
    if (a == 3) {
        if (g_brightnessRecords[1].active == 0 && g_brightnessRecords[0].active == 0)
            return 1;
    } else if (a == 1) {
        if (g_brightnessRecords[1].active == 0)
            return 1;
    } else if (a == 2) {
        if (g_brightnessRecords[0].active == 0)
            return 1;
    }
    return 0;
}
