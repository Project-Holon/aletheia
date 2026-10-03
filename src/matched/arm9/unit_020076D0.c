/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x020076D0
 * packet:   pkt_020076D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020076D0
 *
 * symbols:
 *   sub_020074CC  0x020074CC  thumb
 *   sub_02007AF4  0x02007AF4  thumb
 *   sub_02017E88  0x02017E88  thumb
 *
 * The one function between unit_02007664.c and unit_02007774.c: given a box
 * and a slot by reference, find the next occupied slot at or after it,
 * wrapping round the boxes, and write the answer back through the two
 * pointers.  sub_02017E88 asked with the field id 0xA9 is the "is this entry
 * empty" test, the same call unit_02007774.c counts with.
 *
 * Three things the shape says.  The box and slot are read out of the two
 * pointers once, before the outer loop, and are carried in registers: the
 * back edge at 0x0200774A lands on the sub_02007AF4 call and not on the
 * loads, so a source that re-read `*pbox` each time round would be a
 * different function.  The wrap comparison is signed (`blt`), so the index
 * is an int even though the bound is the unsigned byte at 0x3DD.  And that
 * byte is loaded once for the whole tail: the compiler keeps it live across
 * the loop exit and uses the same register for the `cmp #0x18` and for the
 * value written back through the pointer, so only the increment reloads it.
 *
 * The four parameters and the header pointer are all spilled to the stack at
 * sp+0..sp+0xC.  That is register pressure with r4..r7 carrying the box, the
 * slot, the entry base and the constant 0x88, not five pointers in the
 * source.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020076D0Entry {
    u8 data[0x88];
};

struct Sub020076D0Header {
    u32 unk00;
    u8  pad04[0x3C4 - 4];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern struct Sub020076D0Header *sub_020074CC(void *save);
extern struct Sub020076D0Entry  *sub_02007AF4(void *save, u32 box);
extern u32 sub_02017E88(void *p, u32 id, u32 v);

int sub_020076D0(void *save, int *pbox, int *pslot)
{
    struct Sub020076D0Header *h = sub_020074CC(save);
    int box;
    int slot;

    if (*pbox == -1) {
        *pbox = h->unk00;
    }
    box = *pbox;
    slot = *pslot;
    while (1) {
        struct Sub020076D0Entry *base = sub_02007AF4(save, box);

        while (slot < 30) {
            if (sub_02017E88(&base[slot], 0xA9, 0) == 0) {
                *pbox = box;
                *pslot = slot;
                return 1;
            }
            slot++;
        }
        box++;
        if (box >= h->unk3DD) {
            box = 0;
        }
        if (box == *pbox) {
            break;
        }
        slot = 0;
    }
    if (h->unk3DD != 0x18) {
        *pbox = h->unk3DD;
        *pslot = 0;
        h->unk3DD += 8;
        return 1;
    }
    return 0;
}
