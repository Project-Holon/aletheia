/*
 * function: func_0204F748
 * address:  0x0204F748
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The single bit at bit 10 of the packed halfword at +0x18 of one 0x1c-byte
 * entry of the descriptor's +8 array: `lsl #0x15` / `lsr #0x1f`, which is bit
 * 10 exactly, and no other read-modify-write.
 *
 * Unlabelled in the generated listing because the prologue saves nothing, and
 * it is the follower that makes func_0204F720 EXACT*.  Seeding 0x0204F748 in
 * layout/function_starts.txt turns that EXACT* into EXACT; that file is the
 * integrator's, not this packet's.
 *
 * It is the same array and the same stride as the three accessors in
 * src/matched/unit_0204F6B4.c, one bit along: that file has bit 9, this one
 * bit 10.  The entry type is declared with its sizeof at 0x1c, so the encoder
 * emits the image's `mov r0, #0x1c` plus `mla`.
 */
#include "../include/Obj16146.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent {
    u8  pad_00[0x18];
    u16 pad_b0 : 10;     /* +0x18 bits 0..9  */
    u16 f10 : 1;         /* +0x18 bit 10     */
    u16 pad_b11 : 5;     /* +0x18 bits 11..15 */
    u8  pad_1a[2];
};

u32 func_0204F748(u8 *a0, int i)
{
    struct Ent *e = &((struct Ent *)((struct Obj16146 *)a0)->f8)[i];

    return e->f10;
}
