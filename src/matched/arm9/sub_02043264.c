/*
 * function: sub_02043264
 * address:  0x02043264
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * Apply one of three operations (set / add / subtract) to one of two
 * 32-bit scroll registers of the object, at +0x1c and +0x20, selected by
 * the opcode in r1.  Opcodes 0..2 are live case labels with empty bodies:
 * they are what makes the dispatch table start at zero and therefore what
 * makes it exist at all
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Their table
 * slots hold a bare `bx lr` rather than a branch, same as the out-of-range
 * default.
 *
 * The companion BG_SYS_ApplyCenterOp handles opcodes 9..14 on the two registers
 * at +0x24 and +0x28; nothing in this packet covers 15 and above.
 */

typedef unsigned int u32;

struct Obj {
    u32 pad_00[7];
    u32 unk_1c;
    u32 unk_20;
};

void sub_02043264(struct Obj *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        p->unk_1c = value;
        break;
    case 4:
        p->unk_1c = p->unk_1c + value;
        break;
    case 5:
        p->unk_1c = p->unk_1c - value;
        break;
    case 6:
        p->unk_20 = value;
        break;
    case 7:
        p->unk_20 = p->unk_20 + value;
        break;
    case 8:
        p->unk_20 = p->unk_20 - value;
        break;
    }
}
