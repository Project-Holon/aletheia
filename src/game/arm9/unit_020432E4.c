/*
 * file:     unit_020432E4.c
 * function: sub_020432E4
 * address:  0x020432E4
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * The companion of sub_02043264: the same set / add / subtract triple, but
 * on the two 32-bit registers at +0x24 and +0x28 and for opcodes 9..14.
 * The table is rebased with a leading `sub r1, r1, #9`, so no empty low
 * arms are needed here.
 */

typedef unsigned int u32;

struct Obj {
    u32 pad_00[9];
    u32 unk_24;
    u32 unk_28;
};

void sub_020432E4(struct Obj *p, u32 op, u32 value)
{
    switch (op) {
    case 9:
        p->unk_24 = value;
        break;
    case 10:
        p->unk_24 = p->unk_24 + value;
        break;
    case 11:
        p->unk_24 = p->unk_24 - value;
        break;
    case 12:
        p->unk_28 = value;
        break;
    case 13:
        p->unk_28 = p->unk_28 + value;
        break;
    case 14:
        p->unk_28 = p->unk_28 - value;
        break;
    }
}
