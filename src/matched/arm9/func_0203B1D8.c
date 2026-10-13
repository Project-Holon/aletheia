/*
 * function: GFL_NET_STATE_Main
 * address:  0x0203B1D8
 * packet:   pkt_0203B1D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * The trailing `*` is the unlabelled-follower artefact, never a byte
 * difference: the inferred extent runs to 84 bytes because the two `bx lr`
 * filler words at 0x0203B224 and 0x0203B228 have no label (a prologue that
 * saves no lr is never auto-labelled by disasm.py).  The function itself is
 * 72 bytes of code plus one pool word = 76, and all 76 compiled bytes match.
 * 0x0203B224 is the follower to seed into layout/function_starts.txt
 * (integrator's file, not edited here).
 *
 * Closes docs/notes/pkt_0203B1D8.c.txt, which parked this at "DIFF, 3 bytes,
 * one register" -- the +0x8 callback word landing in r1 in the image and r0
 * in every compile -- and concluded it was an unbreakable Chaitin allocation
 * tie.  It was not a tie: THE CALLBACK TAKES AN ARGUMENT.  Spelling the
 * field `void (*f08)(u32)` and calling `s->f08((u32)s)` pins r0 to the
 * argument, so the function pointer must load into r1, and the three bytes
 * fall out together.
 *
 * This is the same family idiom that closed src/matched/GFL_NET_STATE_DeviceInitialized.c in
 * the same wave (there the argument is func_0203D650()'s return value) and
 * that src/pending/GFL_NET_STATE_ChangeoverParentConnectWait.c already documented in prose.  Across
 * net_state.c, a `ldr rN,[base,#off] / cmp rN,#0 / blx rN` where N is not r0
 * means the callback is being PASSED something, and the thing passed is
 * whatever r0 already holds.  A void-arity guess is what produces the r0
 * spelling.
 *
 * PERMUTER RUN BEFORE THE FIX, and it found nothing, as recorded in the
 * note's appended section: --mode hill --budget 800 exhausted 76 singles
 * with no improvement, --mode anneal --budget 700 spent 700 distinct
 * compiles in 89s and never moved off asm=215 / bytes-out=3.  A
 * function-pointer's ARITY is not in the mutation table (all its mutations
 * are value-preserving except `type`, which changes an integer type, not a
 * signature), so no search over this body could have reached it.
 *
 * symbols:
 *   GFL_NET_STATE_NoProc  0x0203C934  arm
 *   _pNetState     0x021469DC  data
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void GFL_NET_STATE_NoProc(void);

extern struct Sys *_pNetState;

u32 GFL_NET_STATE_Main(void)
{
    struct Sys *s = _pNetState;

    if (s == 0)
        return 1;
    if (s->cb != 0)
        s->cb((u32)s);
    if (_pNetState == 0)
        return 1;
    GFL_NET_STATE_NoProc();
    return 0;
}
