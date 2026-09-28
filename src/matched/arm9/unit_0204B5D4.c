/*
 * unit:     yes
 * function: sub_0204B5D4
 * address:  0x0204B5D4
 * packet:   pkt_0204B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Write and read one of the two u32 slots at +0x14 and +0x18 of the cell
 * actor, selected by the last argument.  0x0204B5E4 is an unlabelled leaf and
 * is a seed for layout/function_starts.txt.
 *
 * Both bodies if-convert to a single predicated memory access, the same shape
 * as src/matched/sub_0204B550.c and src/matched/sub_0204B560.c have for the
 * halfword pair at +0x0c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B5D4.c \
 *       --addr 0x0204B5D4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor {
    u8  pad_00[0x14];
    u32 unk_14;
    u32 unk_18;
};

void sub_0204B5D4(struct Actor *actor, u32 value, u32 which)
{
    if (which == 0) {
        actor->unk_14 = value;
    } else {
        actor->unk_18 = value;
    }
}

u32 sub_0204B5E4(const struct Actor *actor, u32 which)
{
    if (which == 0) {
        return actor->unk_14;
    } else {
        return actor->unk_18;
    }
}
