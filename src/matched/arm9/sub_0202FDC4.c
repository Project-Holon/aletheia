/*
 * function: sub_0202FDC4
 * address:  0x0202FDC4
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_EnvModule   0x02146954  data
 *   GFL_HEAP_GetHeap  0x0202FBAC  arm
 *   sub_0202FED8  0x0202FED8  arm
 *   sub_02060CA0  0x02060CA0  arm
 *
 * Bind one resource of the module at g_EnvModule to a destination slot.  Both
 * identifiers carry a flag in bit 15 and an index in the low fifteen bits: on
 * the destination the flag selects the step, +4 or -4, handed to 0x02060CA0,
 * and the low bits index the id table at g_EnvModule+4, which must still read
 * 0xff (free) or the attempt fails.
 *
 * Three of the four failures are distinguished in the module's error halfword
 * at g_EnvModule+0xE: 1 for a destination slot already taken, 2 for a source
 * resource that does not resolve, 3 for the 0x02060CA0 step failing.  The
 * fourth, 0x0202FED8 returning zero, deliberately leaves the error word alone,
 * which is visible as the fall-through into the shared `mov r0, #0` tail with
 * no `strh` in front of it.
 *
 * All four zero returns share one `mov r0, #0` / `pop` tail, and calls sit
 * between the guards, so the only spelling that reproduces it is an explicit
 * `goto fail` (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md);
 * plain `return 0;` in each arm costs four extra instructions.
 *
 * The masked destination index reuses the parameter's own register
 * (`and r6, r6, r1`), so it is written back over `dst` rather than bound to a
 * fresh local, which would take a register of its own.
 *
 * The single pooled 0x7fff is shared by both masks (`and r6, r6, r1` and
 * `and r0, r0, r1` read the same register), so the mask must be spelled the
 * same way on both identifiers rather than folded into one of them.
 *
 * GFL_HEAP_GetHeap is declared here with a u16 parameter, not the u32 of
 * src/matched/unit_0202FBAC.c: the `lsl #16` / `lsr #16` pair after the mask
 * is the argument truncation and nothing else in the function produces it
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md,
 * read for the equal-amount case).  The two declarations live in different
 * translation units and never meet.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202FDC4.c \
 *       --func sub_0202FDC4 --addr 0x0202FDC4 --cc 1.1p1 --arm
 */

#include "../include/G_EnvModule.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct EnvEntry {
    void *ptr00;
    u32   field04;
    u32   field08;
    u16   field0c;
};

extern struct EnvModule g_EnvModule;

extern void *GFL_HEAP_GetHeap(u32 idx);
struct ExpHeap;
extern void *sub_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
extern int sub_0202FED8(u32 a0, u32 a1, u32 a2, u32 a3);

int sub_0202FDC4(u32 src, u32 dst, u32 param)
{
    void *res;
    void *bound;
    s32   step;

    if (dst & 0x8000) {
        step = -4;
    } else {
        step = 4;
    }
    dst = dst & 0x7fff;

    if (((u8 *)g_EnvModule.ids)[dst] != 0xff) {
        g_EnvModule.error = 1;
        goto fail;
    }

    res = GFL_HEAP_GetHeap((u16)(src & 0x7fff));
    if (res == 0) {
        g_EnvModule.error = 2;
        goto fail;
    }

    bound = sub_02060CA0(res, param, step);
    if (bound == 0) {
        g_EnvModule.error = 3;
        goto fail;
    }

    if (sub_0202FED8((u32)res, dst, (u32)bound, param) == 0) {
        goto fail;
    }
    return 1;

fail:
    return 0;
}
