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
 * function: GAME_COMM_GetKind, GAME_COMM_IsTransition, GAME_COMM_GetWork, GAME_COMM_GetGameData,
 *           GAME_COMM_GetLastKind, GAME_COMM_SetCounter, GAME_COMM_ClearCounter, GAME_COMM_GetCounter
 *
 * Eight two-to-five-instruction accessors on one object, none of them
 * pushing a register: only the first is a real label in the generated
 * listing (a `func_starts` seed reached it some other way), and the other
 * seven print as `.word` runs between the two named functions this range
 * sits between, the same gap docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md describes.
 *
 * GAME_COMM_GetKind returns byte field +5 unconditionally: the original's
 * `bne`-around-a-redundant-`movs r0,#0` is what a plain `return v;`
 * compiles to when `v` is already known nonzero on one path, not a
 * guard. GAME_COMM_IsTransition is a genuine conjunction, `field5 != 0 &&
 * field0x10 != 2`, and only that phrasing (not two early-return `if`s)
 * produces the shared branch target both comparisons jump to
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * The rest are plain word/byte getters and setters on fields +0x18, +0,
 * +6 and +8, one of them (GAME_COMM_ClearCounter) a "clear to zero" specialisation
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

u32 GAME_COMM_GetKind(void *obj)
{
    u8 v = *((u8 *)obj + 5);
    if (v != 0) {
        return v;
    }
    return 0;
}

u32 GAME_COMM_IsTransition(void *obj)
{
    if (*((u8 *)obj + 5) != 0 && *((u8 *)obj + 0x10) != 2) {
        return 1;
    }
    return 0;
}

u32 GAME_COMM_GetWork(void *obj)
{
    return ((struct Obj17245 *)obj)->f18;
}

u32 GAME_COMM_GetGameData(void *obj)
{
    return ((struct Obj17246 *)obj)->f0;
}

u32 GAME_COMM_GetLastKind(void *obj)
{
    return *((u8 *)obj + 6);
}

void GAME_COMM_SetCounter(void *obj, u32 value)
{
    ((struct Obj17248 *)obj)->f8 = value;
}

void GAME_COMM_ClearCounter(void *obj)
{
    ((struct Obj17249 *)obj)->f8 = 0;
}

u32 GAME_COMM_GetCounter(void *obj)
{
    return ((struct Obj17250 *)obj)->f8;
}
