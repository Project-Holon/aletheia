/*
 * function: BG_SYS_SetScrollField
 * address:  0x02042360
 * packet:   pkt_02041F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 32-bit member of the set / add / subtract family whose 16-bit
 * counterpart is src/matched/BG_SYS_SetAffineField.c: opcodes 0..2 on the word at
 * +0xc of the record in r0, opcodes 3..5 on the word at +0x10, and nothing
 * at all above 5.  Each arm loads, combines and stores the field spelled
 * out as two statements of one expression, which is what keeps a single
 * `ldr` per arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetScrollField.c \
 *       --func BG_SYS_SetScrollField --addr 0x02042360 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
};

void BG_SYS_SetScrollField(struct Obj *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
        p->unk_0c = value;
        break;
    case 1:
        p->unk_0c = p->unk_0c + value;
        break;
    case 2:
        p->unk_0c = p->unk_0c - value;
        break;
    case 3:
        p->unk_10 = value;
        break;
    case 4:
        p->unk_10 = p->unk_10 + value;
        break;
    case 5:
        p->unk_10 = p->unk_10 - value;
        break;
    }
}
