/*
 * unit:     yes
 * function: sub_0204B5F4
 * address:  0x0204B5F4
 * packet:   pkt_0204B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The write and read of the u16 at +0x58 of the cell actor.  Neither saves lr,
 * so only the first carries a label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x0204B5FC is
 * a seed for layout/function_starts.txt.
 *
 * The unit deliberately stops here rather than running on to the end of the
 * listing extent at 0x0204B658.  The next leaf, 0x0204B604, is a closed near
 * miss recorded in docs/notes/sub_0204B604.c.txt, and folding it in would put
 * this range back to DIFF.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B5F4.c \
 *       --addr 0x0204B5F4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Actor {
    u8  pad_00[0x58];
    u16 unk_58;
};

void sub_0204B5F4(struct Actor *actor, u16 value)
{
    actor->unk_58 = value;
}

u16 sub_0204B5FC(const struct Actor *actor)
{
    return actor->unk_58;
}
