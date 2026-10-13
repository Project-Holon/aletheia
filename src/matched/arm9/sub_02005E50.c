/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * function: GFL_USE_IsBgmFading
 * address:  0x02005E50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02005E50_State  0x020AA260  data
 *
 * Original (20 bytes, leaf, one ABS32 literal):
 *   ldr  r0, [pc, #0xc]   ; &sub_02005E50_State
 *   ldr  r0, [r0, #8]
 *   cmp  r0, #0
 *   beq  .zero
 *   movs r0, #1
 *   bx   lr
 *  .zero:
 *   movs r0, #0
 *   bx   lr
 *
 * The two-exit branch shape is what a boolean-valued != 0 compiles to in
 * Thumb, where there is no conditional move.  Returning the field itself
 * would have been three instructions with no branch at all.
 *
 * The pool word is an ABS32 relocation, resolved to the address declared
 * above; eighteen other functions load the same address from their own
 * pools.
 */

typedef unsigned int u32;

struct Sub02005E50State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

extern struct Sub02005E50State sub_02005E50_State;

int GFL_USE_IsBgmFading(void)
{
    return sub_02005E50_State.unk08 != 0;
}
