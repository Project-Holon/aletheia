/*
 * function: func_0204ED4C
 * address:  0x0204ED4C
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the flag word at +0x2c and copies three signed halfwords out of the
 * caller's array into +0x30, +0x32 and +0x34.
 *
 * Unlabelled in the generated listing, and it is the follower that makes
 * func_0204ED24 EXACT*: the prologue saves nothing, so `disasm.py` never
 * auto-labelled it, and the extent inferred for 0x0204ED24 runs through these
 * 36 bytes to the next label at 0x0204ED70
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Seeding
 * 0x0204ED4C in layout/function_starts.txt turns that EXACT* into EXACT and
 * changes nothing else - it is the integrator's file, not this packet's.
 *
 * The three `ldrsh` leave the array backwards (a1[2] first) and the three
 * `strh` write in order, so the values have to live in three registers at
 * once: the source holds them in locals, and the locals have to be *declared*
 * in reverse order (`v2`, `v1`, `v0`) while being assigned in the same
 * reverse order.  Declared v0, v1, v2 the compiler gives a1[1] the higher of
 * the two scratch registers and a1[2] the lower one, which is four bytes of
 * register field wrong - see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 * Writing the three stores straight from the array (no locals) interleaves
 * each load with its store and is eight bytes wrong.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0204ED4C(u8 *a0, short *a1)
{
    short v2;
    short v1;
    short v0;

    *(u32 *)(a0 + 0x2c) = 1;
    v2 = a1[2];
    v1 = a1[1];
    v0 = a1[0];
    *(short *)(a0 + 0x30) = v0;
    *(short *)(a0 + 0x32) = v1;
    *(short *)(a0 + 0x34) = v2;
}
