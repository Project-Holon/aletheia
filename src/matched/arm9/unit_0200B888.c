/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B888
 * packet:   pkt_0200B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B888, func_0200B8AC
 *
 * 120 bytes, 0x0200B888..0x0200B900, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "battle_rec.c"; the two validity checks src/matched/
 * unit_0200B4E0.c and unit_0200B5CC.c run over a loaded record, and the reason
 * those two are separate files.
 *
 * 0xE281 is the record's magic, stamped into both halves by func_0200B6E0 and
 * into the 0x44-byte header's +0x28 by func_0200B938.  func_0200B888 answers
 * "this record is NOT stamped", so its result is 1 on failure; func_0200B8AC
 * answers "this record is whole", checking the magic in both halves and then
 * both checksums.
 *
 * Both take a first parameter they never read.  func_0200B888 reaches the
 * 0x17D8 field of the second half as one folded offset 0x189C off the record
 * pointer, because the source names the field through the record rather than
 * through a local, while func_0200B8AC needs a local for the sub-record and so
 * carries 0x17D8 in a register instead; the difference is two instructions and
 * is a statement about the source rather than about the value.
 *
 * The two checksum comparisons each bind the call result to a local before
 * comparing, which is what puts it in `cmp`'s left slot; written inline the
 * operand order flips and the entry is two bytes out.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * symbols:
 *   func_0203F1FC  0x0203F1FC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0203F1FC(const u8 *src, u32 len);

struct QRec {
    u16 unk00[0x0C];
    u8  unk18[0x0C];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u8  unk2A;
    u8  unk2B;
    u8  unk2C[0x0C];
    u8  unk38[8];
    u16 unk40;
    u16 unk42;
};

struct RecC4 {
    u8  unk0000[0x17D8];
    u16 unk17D8;
    u16 unk17DA;
    u16 unk17DC;
    u16 unk17DE;
};

struct BattleRec {
    u8  unk00[0x80];
    struct QRec unk80;
    struct RecC4 unkC4;
};

u32 func_0200B888(void *a, struct BattleRec *b)
{
    struct QRec *q = &b->unk80;

    if (b->unkC4.unk17D8 != 0xE281 || q->unk28 != 0xE281) {
        return 1;
    }
    return 0;
}

u32 func_0200B8AC(void *a, struct BattleRec *b)
{
    struct RecC4 *r = &b->unkC4;
    struct QRec *q = &b->unk80;
    u16 sum;

    if (r->unk17D8 != 0xE281 || q->unk28 != 0xE281) {
        return 0;
    }
    sum = func_0203F1FC((const u8 *)q, 0x38);
    if (sum != q->unk40) {
        return 0;
    }
    sum = func_0203F1FC((const u8 *)r, 0x17DC);
    if (sum == r->unk17DC) {
        return 1;
    }
    return 0;
}
