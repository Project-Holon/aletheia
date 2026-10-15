/*
 * function: SPL_EMITTER_InterpTarget
 * address:  0x02057F8C
 * packet:   pkt_02057F8C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * wave r8 lane rigD: the wave r6 DIFF at this address is closed.  The two
 * levers the r6 note asked for are both real and both necessary:
 *
 *  - the mode dispatch is a `switch` on a 2-bit bitfield member, not an
 *    if/else-if chain: `sw` puts BOTH case tests before the default `bx lr`
 *    and the two bodies after it, which is the 284-byte layout (the
 *    if/else-if spelling hoists case 0's body to the first test and comes
 *    out 260 bytes).
 *  - the mode-1 clamp is the 64-bit `(s64)x * y + 0x800 >> 12` form, not the
 *    32-bit one: 32-bit gives `mul/add/asr` (4 instructions, 260 bytes),
 *    the `long long` form gives the image's `smull/adc/lsr/orr` quartet with
 *    the pooled `mov r0, #0x800` in the middle.
 *
 * The arm shape the r6 note arrived at is also exact as written: the inner
 * `return` sits INSIDE the inner `if` (predicated `bxgt lr` in mode 0, a
 * `ble <tail>` out-of-line clamp in mode 1), and the redundant
 * `if (v < target) return;` after it is what makes the shared tail block
 * exist at all.
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct A {
    int target;
    s16 f04;
    u16 mode : 2;
    u16 rest : 14;
};

struct C {
    char _00[0x74];
    int f74;
};

struct S {
    char _00[0xc];
    int c;
    char _10[8];
    int f18;
    char _1c[8];
    u16 f24;
    u16 f26;
    char _28[0x14];
    int f3c;
};

void SPL_EMITTER_InterpTarget(struct A *a, struct S *s, int unused, struct C *c)
{
    int target;
    int v;

    target = a->target;
    if (c->f74 != 0x80000000) target = c->f74;

    switch (a->mode) {
    case 0:
        v = s->f3c;
        if (v < target) {
            if (v + s->c > target) {
                s->c = target - v;
                s->f26 = s->f24;
                return;
            }
        }
        if (v < target) return;
        if (v + s->c < target) {
            s->c = target - v;
            s->f26 = s->f24;
        }
        return;
    case 1:
        v = s->f3c;
        if (v < target) {
            if (v + s->c > target) {
                s->c = target - v;
                s->f18 = -(int)(((long long)s->f18 * a->f04 + 0x800) >> 12);
                return;
            }
        }
        if (v < target) return;
        if (v + s->c < target) {
            s->c = target - v;
            s->f18 = -(int)(((long long)s->f18 * a->f04 + 0x800) >> 12);
        }
        return;
    }
}
