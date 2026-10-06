/*
 * function: func_02064178
 * address:  0x02064178
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Opens one 0x28-byte group header of the two-level cell-array shape: clears
 * the header's first word, stores the cell pointer at +0x04, sets the "in use"
 * word at +0x08 and tail-calls func_02064140 on the SRT block at +0x0c.
 * func_02064754 drives it once per group.
 *
 * PIN ../2.0/sp2: the tail-call scheduling form of the "kept constants" tell.
 * The image materialises the zero FIRST and stores it first -- `mov r2,#0` at
 * 0x02064178 / `str r2,[r0]` / `str r1,[r0,#4]` / `mov r1,#1` / `str r1,[r0,#8]`
 * -- and only then loads the tail-call pool word (`ldr ip,[pc,#4]` at
 * 0x0206418C).  1.1p1 -O4,p hoists that pool load ABOVE the three stores and
 * posts the zero store after them, which lets it drop one instruction: 32
 * bytes against the original's 36, 23 concrete out.  An earlier lane measured
 * the array spelling `((u32 *)o)[0] = 0; ...`, the named-field spelling and a
 * `(u8 *)o + 0xc` call argument and found all three byte-identical to each
 * other, i.e. the scheduling is not source-driven
 * (docs/notes/pkt_02064178.c.txt).  Under the pin this SAME C is 36 bytes, 0
 * mismatches.
 *
 * symbols:
 *   func_02064140  0x02064140  arm
 */
#include "../include/Obj07023.h"
typedef unsigned int u32;
struct O02064140;
extern void func_02064140(struct O02064140 *o, u32 a);

void func_02064178(char *o, u32 a)
{
    *(u32 *)&((struct Obj07023 *)o)->f0 = 0;
    ((struct Obj07023 *)o)->f4 = a;
    ((struct Obj07023 *)o)->f8 = 1;
    func_02064140((struct O02064140 *)(o + 0xc), 1);
}
