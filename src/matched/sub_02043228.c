/*
 * function: sub_02043228
 * address:  0x02043228
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * The 16-bit member of the set / add / subtract family that sub_02043264
 * and sub_020432E4 cover for the 32-bit registers: opcodes 0..2 on the
 * halfword at +0x18.  Three comparisons rather than a table, because the
 * arms are too few to be worth one; the last arm is folded into predicated
 * `ldrheq`/`subeq`/`strheq` in the fall-through block and only the first
 * two get out-of-line bodies.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u16 pad_00[0x0c];
    u16 unk_18;
};

void sub_02043228(struct Obj *p, u32 op, u16 value)
{
    switch (op) {
    case 0:
        p->unk_18 = value;
        break;
    case 1:
        p->unk_18 = p->unk_18 + value;
        break;
    case 2:
        p->unk_18 = p->unk_18 - value;
        break;
    }
}
