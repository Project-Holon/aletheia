/*
 * unit:     no
 * function: sub_02045F50
 * address:  0x02045F50
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A three-instruction accessor: follow the pointer at +0 of the object and
 * return the halfword at +2 of what it points at.  It saves nothing, so
 * disasm.py never labelled it and it only shows up by sweeping the packet
 * by address (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * `ldrh` with no sign extension fixes the field as u16; an s16 would have
 * needed a register-offset `ldrsh`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045F50.c \
 *       --func sub_02045F50 --addr 0x02045F50 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Head {
    u8  pad_00[2];
    u16 unk_02;
};

struct Obj {
    struct Head *head;
};

u16 sub_02045F50(const struct Obj *o)
{
    return o->head->unk_02;
}
