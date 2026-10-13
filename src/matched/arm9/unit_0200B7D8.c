/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B7D8
 * packet:   pkt_0200B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_MakeHeader
 *
 * 176 bytes, 0x0200B7D8..0x0200B888, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  It builds the 0x44-byte battle header out of
 * the party records that live at +0xC3C of the 0x17E0-byte second half of the
 * record.  The layout, four sides of three or two of six, comes from
 * BATTLE_REC_GetModeLayout, and the group stride 0x2A4 is six 0x70-byte entries plus a
 * word.  An entry is skipped when either of two bits is set, and those two
 * bitfield reads are the only evidence in the image for those field widths.
 *
 * The destination byte packs a five bit field into the low seven bits and a
 * two bit field at bit 7, where only one of the two bits survives the `strb`.
 * That truncation is in the original and is reproduced rather than corrected;
 * the explicit `& 0x7F` on a field that is already five bits wide is what puts
 * the `movs r1, #0x7f` / `ands` pair there, and dropping it loses four bytes.
 *
 * This range starts at 0x0200B7D8 rather than at BATTLE_REC_GetModeLayout, which is its
 * only caller, because 0x0209DDCC is named by exactly two literal pool words
 * in the whole image: this function's at 0x0200B880 and BATTLE_REC_GetModeLayout's at
 * 0x0200B7D4.  One range holding both has no witness for the table at all.
 * Cut between them and each pool word attests the other file.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The call
 * to BATTLE_REC_GetModeLayout survives the cut because three overlay branches reach that
 * address from outside this region.
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC  arm
 *   BattleRecModeTable  0x0209DDCC  data
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members);

extern const u16 BattleRecModeTable[];

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

struct Ent70 {
    u8  unk00[4];
    u16 f04_0 : 2;
    u16 f04_2 : 1;
    u16 f04_3 : 13;
    u16 unk06;
    u8  unk08[0x24];
    u32 f2C_0 : 30;
    u32 f2C_30 : 1;
    u32 f2C_31 : 1;
    u8  f30_0 : 1;
    u8  f30_1 : 2;
    u8  f30_3 : 5;
    u8  unk31[0x3F];
};

struct Grp2A4 {
    struct Ent70 ent[6];
    u32 unk2A0;
};

struct RecC4 {
    u8  unk0000[0xC3C];
    struct Grp2A4 unkC3C[4];
    u8  unk16CC[0x10C];
    u16 unk17D8;
    u16 unk17DA;
    u16 unk17DC;
    u16 unk17DE;
};

void BATTLE_REC_MakeHeader(void *h, struct QRec *q, const struct RecC4 *src, u32 mode,
                   u32 e)
{
    s32 nsides;
    s32 nmembers;
    u16 kind;
    s32 i;
    s32 j;
    s32 k;

    k = 0;
    MI_CpuFill8(q, 0, sizeof(struct QRec));
    kind = BattleRecModeTable[mode];
    BATTLE_REC_GetModeLayout(kind, &nsides, &nmembers);
    for (i = 0; i < nsides; i++) {
        for (j = 0; j < nmembers; j++) {
            const struct Ent70 *t = &src->unkC3C[i].ent[j];

            if (t->f2C_30 == 0 && t->f04_2 == 0) {
                q->unk00[k] = t->unk06;
                q->unk18[k] = (u8)((t->f30_3 & 0x7F) | (t->f30_1 << 7));
            }
            k++;
        }
    }
    q->unk24 = e;
    q->unk26 = kind;
    q->unk2B = 100;
}
