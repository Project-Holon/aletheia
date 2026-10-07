/*
 * function: func_0200E124
 * address:  0x0200E124
 * packet:   pkt_0200E0BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209DE90     0x0209DE90  data
 *   func_0200E0BC  0x0200E0BC  thumb
 *   func_02082D44  0x02082D44  arm
 *
 * The third pass's one in-lane conversion (lane 1 of the 0-64 byte band).
 * The two earlier attempts on this address both stopped at MATCH/DIFF on the
 * *pool word* rather than on any instruction: the entry point is a two-field
 * record table, and the field the original reads is the SECOND one, so its
 * `ldr r0, [pc, #0x28]` loads `g_0209DE90 + 2` (the address of `.b`), not the
 * table base.  Reading `struct Rec { u16 a; u16 b; } g_0209DE90[]` and taking
 * `.b` folds that +2 into the pool word exactly as the original does;
 * reading the same address as `u16[]` at `[i * 2]` gives `.a` (the wrong
 * field, one byte off in the pool) and `[i * 2 + 1]` gives 68 bytes instead
 * of 64.  See `docs/idioms/table-field-offset-folds-into-the-pool-word.md`
 * for the lever and docs/notes/pkt_0200E0BC.c.txt for the two residues.
 *
 * `u32 *o = obj;` is load-bearing: without it mwcc strength-reduces
 * `obj + (idx + 1)` to `(obj + idx) + 4`, which is the same address but a
 * different instruction order in the argument set-up.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E124.c \
 *       --func func_0200E124 --addr 0x0200E124 --cc 1.1p1 --thumb
 */

#include "../include/G_Rec.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Rec g_0209DE90[];
extern u32 func_0200E0BC(u32 value);
extern void func_02082D44(void *dst, const void *src, u32 size);

void func_0200E124(u32 *obj, u32 idx)
{
    u32 hi = g_0209DE90[func_0200E0BC(idx)].b;
    u32 *o = obj;

    if (idx < hi)
        func_02082D44(o + (idx + 1), o + idx, (hi - (idx + 1)) * 4);
    o[hi - 1] &= 0xfffff800;
}
