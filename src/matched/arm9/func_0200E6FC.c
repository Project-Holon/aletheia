/*
 * function: MISC_SAVEDATA_CopyQuadRecord
 * address:  0x0200E6FC
 * packet:   pkt_0200E6FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   (none - no relocations)
 *
 * One 8-byte record copied out: four u16 fields, so the copy unrolls to four
 * ldrh/strh pairs rather than an ldm/stm.  It has to be written as a struct
 * assignment: the same copy spelled field by field, or through a `u16 *`
 * temporary, picks the other register for the scaled index (r1 instead of
 * r3) and lands six bytes wrong.  EXACT*: the listing extent runs 192 bytes
 * because the follower at 0x0200E714 saves nothing and carries no label.
 */

typedef unsigned short u16;

struct Rec0200E6FC {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

void MISC_SAVEDATA_CopyQuadRecord(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst)
{
    *dst = src[idx];
}
