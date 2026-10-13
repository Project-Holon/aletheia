/*
 * unit:     yes
 * function: CLACT_SetActorAffineMode
 * address:  0x0204B570
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two more leaf accessors of the 0xE4-byte cell actor.  0x0204B588 saves no
 * lr and so carries no label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); it is a seed
 * for layout/function_starts.txt.
 *
 * CLACT_SetActorAffineMode writes a two-bit field at bits 18..19 of the u32 flag word at
 * +0x60.  The base type has to be u32, not u8 as in
 * src/matched/unit_0204B22C.c: a u8-based bitfield would truncate the
 * incoming value with an `and r1, r1, #0xff` first, and there is no such
 * instruction here.
 *
 * 0x0204B588 is the +0x10 twin of src/matched/CLACT_SetActorPos.c, so the actor
 * carries two halfword pairs, the screen position at +0x0c and this second
 * pair at +0x10.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B570.c \
 *       --addr 0x0204B570 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Pt {
    u16 x;
    u16 y;
};

struct Actor {
    u8        pad_00[0x10];
    struct Pt unk_10;
    u8        pad_14[0x4c];
    u32       unk_60_00 : 18;
    u32       unk_60_18 : 2;
    u32       unk_60_20 : 12;
};

void CLACT_SetActorAffineMode(struct Actor *actor, u32 value)
{
    actor->unk_60_18 = value;
}

void CLACT_SetActorAffineOrigin(struct Actor *actor, const struct Pt *src)
{
    actor->unk_10.x = src->x;
    actor->unk_10.y = src->y;
}
