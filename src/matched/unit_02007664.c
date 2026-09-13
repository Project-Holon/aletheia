/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007664
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007664, sub_02007698, sub_020076A4, sub_020076B4
 *
 * symbols:
 *   sub_020074CC  0x020074CC  thumb
 *   sub_02007AF4  0x02007AF4  thumb
 *   sub_02017550  0x02017550  thumb
 *
 * The box accessors: sub_020074CC turns the caller's save handle into the
 * 0x3DE byte box header, and sub_02007AF4 turns a box index into that box's
 * array of thirty 0x88 byte entries.
 *
 * Two encodings to note.  The header's `unk3DD` sits past every Thumb
 * immediate, so it arrives as a pool word and a register offset `ldrb`
 * rather than as an offset in the instruction, and sub_020076B4 loads that
 * same pool word twice, once for the read-modify-write and once for the
 * value it returns.  And the entry index is scaled by 0x88, which is not a
 * power of two, so it is a real `muls` with the constant materialised by
 * `movs r1, #0x88`: that is what indexing an array of a non power of two
 * sized struct looks like, and it is what says the element is 0x88 bytes
 * rather than that there is a multiply in the source.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sub02007664Entry {
    u8 data[0x88];
};

struct Sub02007664Header {
    u32 unk00;
    u8  pad04[0x3C4 - 4];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern struct Sub02007664Header *sub_020074CC(void *save);
extern struct Sub02007664Entry  *sub_02007AF4(void *save, u32 box);
extern void sub_02017550(struct Sub02007664Entry *entry);

void sub_02007664(void *save, u32 box, u32 slot)
{
    struct Sub02007664Header *h = sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (slot < 30 && box < 0x18) {
        sub_02017550(&sub_02007AF4(save, box)[slot]);
    }
}

u32 sub_02007698(void *save)
{
    return sub_020074CC(save)->unk00;
}

u8 sub_020076A4(void *save)
{
    return sub_020074CC(save)->unk3DD;
}

u8 sub_020076B4(void *save)
{
    struct Sub02007664Header *h = sub_020074CC(save);

    if (h->unk3DD != 0x18) {
        h->unk3DD += 8;
    }
    return h->unk3DD;
}
