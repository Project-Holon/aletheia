/*
 * unit:     yes
 * function: func_0204F6B4, func_0204F6DC, BILLBOARD_GetElemVisible
 * address:  0x0204F6B4
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The three accessors that follow func_0204F684, 0x0204F6B4..0x0204F720, on
 * the three bitfields of the packed halfword at +0x18 of one 0x1c-byte entry
 * of the descriptor's +8 array: five bits at bit 0, four bits at bit 5, and
 * the single bit at bit 9.
 *
 * All three are unlabelled in the generated listing, because none of them
 * saves a register in a prologue and `disasm.py` only auto-labels a function
 * whose prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes; the range is contiguous and this unit reproduces all
 * 108 bytes of it.
 *
 * Each one is a read-modify-write of the whole halfword, which is what a
 * bitfield assignment costs: `ldrh` the word, `bic` the field's mask out,
 * `orr` the shifted new value in, `strh` it back.  The widths and positions of
 * the three fields are exactly the masks in the image (0x1f at bit 0,
 * 0x1e0 at bit 5, bit 9 read with `lsl #22` / `lsr #31`), so nothing about the
 * field layout is guessed.
 */
#include "../include/Obj17359.h"
#include "../include/Obj17361.h"
#include "../include/Obj17363.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent {
    u8  pad_00[0x18];
    u16 f0 : 5;      /* +0x18 bit 0, five bits  */
    u16 f1 : 4;      /* +0x18 bit 5, four bits  */
    u16 f2 : 1;      /* +0x18 bit 9             */
    u16 f3 : 6;      /* +0x18 bit 10, the rest  */
    u8  pad_1a[2];
};

void func_0204F6B4(u8 *a0, int i, u8 *px)
{
    struct Ent *e = &((struct Ent *)((struct Obj17359 *)a0)->f8)[i];

    e->f0 = *px;
}

void func_0204F6DC(u8 *a0, int i, u8 *px)
{
    struct Ent *e = &((struct Ent *)((struct Obj17361 *)a0)->f8)[i];

    e->f1 = *px;
}

u32 BILLBOARD_GetElemVisible(u8 *a0, int i)
{
    struct Ent *e = &((struct Ent *)((struct Obj17363 *)a0)->f8)[i];

    return e->f2;
}
