/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02026454
 * packet:   pkt_02026250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02026454, sub_02026460, sub_02026474, sub_02026478,
 *           sub_0202647C, sub_02026480, sub_02026484, sub_0202648C
 *
 * Eight two-to-five-instruction accessors on one object, none of them
 * pushing a register: only the first is a real label in the generated
 * listing (a `func_starts` seed reached it some other way), and the other
 * seven print as `.word` runs between the two named functions this range
 * sits between, the same gap docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md describes.
 *
 * sub_02026454 returns byte field +5 unconditionally: the original's
 * `bne`-around-a-redundant-`movs r0,#0` is what a plain `return v;`
 * compiles to when `v` is already known nonzero on one path, not a
 * guard. sub_02026460 is a genuine conjunction, `field5 != 0 &&
 * field0x10 != 2`, and only that phrasing (not two early-return `if`s)
 * produces the shared branch target both comparisons jump to
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * The rest are plain word/byte getters and setters on fields +0x18, +0,
 * +6 and +8, one of them (sub_02026484) a "clear to zero" specialisation
 * of the setter that immediately follows it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026454.c \
 *       --addr 0x02026454 --thumb
 */
#include "../include/Obj17245.h"
#include "../include/Obj17246.h"
#include "../include/Obj17248.h"
#include "../include/Obj17249.h"
#include "../include/Obj17250.h"

typedef unsigned char u8;
typedef unsigned int u32;

u32 sub_02026454(void *obj)
{
    u8 v = *((u8 *)obj + 5);
    if (v != 0) {
        return v;
    }
    return 0;
}

u32 sub_02026460(void *obj)
{
    if (*((u8 *)obj + 5) != 0 && *((u8 *)obj + 0x10) != 2) {
        return 1;
    }
    return 0;
}

u32 sub_02026474(void *obj)
{
    return ((struct Obj17245 *)obj)->f18;
}

u32 sub_02026478(void *obj)
{
    return ((struct Obj17246 *)obj)->f0;
}

u32 sub_0202647C(void *obj)
{
    return *((u8 *)obj + 6);
}

void sub_02026480(void *obj, u32 value)
{
    ((struct Obj17248 *)obj)->f8 = value;
}

void sub_02026484(void *obj)
{
    ((struct Obj17249 *)obj)->f8 = 0;
}

u32 sub_0202648C(void *obj)
{
    return ((struct Obj17250 *)obj)->f8;
}
