/*
 * unit:     no
 * address:  0x02030734
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030734
 *
 * The allocation entry point of the game's heap layer, and the highest-
 * radiation function in the image: 1163 branch references from arm9 and
 * the overlays. Every object constructor in the game that wants memory
 * goes through this wrapper rather than calling the raw allocator at
 * 0x02030098 directly.
 *
 *   void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                      u16 tag)
 *
 * Previously capped at MATCH: all 124 concrete bytes were correct but four
 * of the seven relocation sites had no witness, each target's only branch
 * reference in the image being the call inside this function. All four are
 * now EXACT and attest this file by the `matched` class:
 *
 *   0x02030098  the raw allocator            src/matched/sub_02030098.c
 *   0x02030880  provenance stamp             src/matched/sub_02030880.c
 *   0x02030958  out-of-memory reporter       src/matched/sub_02030958.c
 *   0x02030A00  watched-allocation hook      src/matched/sub_02030A00.c
 *
 * The fifth argument is a u16 delivered on the stack; with six registers
 * pushed it lands at [sp, #0x18], and the callee reads it back with a
 * halfword load rather than a word load, which is what pins its type.
 * It is carried, together with the fourth argument, into the success-side
 * bookkeeping call sub_02030880, which stamps the pair into the 0x1c-byte
 * block header the raw allocator reserved: the string goes into the
 * 0x12-byte name field at header+4 and the tag into the halfword at
 * header+0x16. It is *not* the classic __FILE__/__LINE__ pair: the sites
 * that call this pass addresses above the arm9 static image end
 * (0x020A6800 per layout/layout.json), i.e. BSS globals, not string
 * constants. See src/matched/sub_020457B0.c for a worked caller.
 *
 * Shape notes:
 *
 *  - The raw allocator sub_02030098 reads only r0 and r1, so this call
 *    forwards only heapId and size; r2 and r3 arriving unchanged from
 *    this function's own prologue are leftovers, the shape of
 *    docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md.
 *    The same is true of the failure reporter: sub_02030958 reads only
 *    r0, so the site and tag registers set up for it are leftovers too,
 *    and the four-parameter declaration below is kept only because it is
 *    what the original call site's register setup looks like.
 *  - The failure arm is the fall-through, so it is written first
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md). It calls
 *    sub_02030524 with no arguments, reports, then OS_Terminate; the
 *    branch to the shared `return p` tail after OS_Terminate shows the
 *    compiler was not told OS_Terminate is noreturn.
 *  - The clear flag guards MIi_CpuClear32(0, p, size), which is why a
 *    caller that wants zeroed memory passes a non-zero third argument
 *    rather than clearing at the call site.
 *
 * layout/symbols_sdk.json offers the names GX_GetBankForBGExtPltt for
 * 0x02030524 and ENV_SetResourceSet for 0x020307B0. Both are
 * signature-matcher guesses with large sibling sets (37 and 8
 * respectively) and neither fits the role played here, so the canonical
 * sub_ names are used. MIi_CpuClear32 and OS_Terminate have no such
 * ambiguity and keep their SDK names.
 *
 * symbols:
 *   sub_02030098    0x02030098  arm
 *   sub_02030524    0x02030524  arm
 *   sub_02030880    0x02030880  arm
 *   sub_02030958    0x02030958  arm
 *   sub_02030A00    0x02030A00  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   OS_Terminate    0x02088234  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030734.c \
 *       --func sub_02030734 --addr 0x02030734 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *sub_02030098(u32 heapId, u32 size);
extern u16 sub_02030524(void);
extern void sub_02030880(void *p, const char *site, u16 tag);
extern void sub_02030958(u32 heapId, u32 size, const char *site, u16 tag);
extern void sub_02030A00(u32 heapId, void *p, u32 size);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void OS_Terminate(void);

void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag)
{
    void *p;

    p = sub_02030098(heapId, size);
    if (p == 0) {
        sub_02030524();
        sub_02030958(heapId, size, site, tag);
        OS_Terminate();
    } else {
        sub_02030880(p, site, tag);
        sub_02030A00(heapId, p, size);
        if (clear != 0) {
            MIi_CpuClear32(0, p, size);
        }
    }
    return p;
}
