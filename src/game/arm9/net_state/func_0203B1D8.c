/*
 * function: func_0203B1D8
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
 * This is the same family idiom that closed src/matched/func_0203AF40.c in
 * the same wave (there the argument is func_0203D650()'s return value) and
 * that src/pending/func_0203B52C.c already documented in prose.  Across
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
 *   func_0203C934  0x0203C934  arm
 *   g_021469DC     0x021469DC  data
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_0203C934(void);

struct Sys {
    u8  pad_00[8];
    void (*f08)(u32 a);
};

extern struct Sys *g_021469DC;

u32 func_0203B1D8(void)
{
    struct Sys *s = g_021469DC;

    if (s == 0)
        return 1;
    if (s->f08 != 0)
        s->f08((u32)s);
    if (g_021469DC == 0)
        return 1;
    func_0203C934();
    return 0;
}
