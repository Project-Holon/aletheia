/*
 * unit:     yes
 * address:  0x0201C8A4
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PRINTSYS_SetJobColor
 *
 * Stores a halfword parameter at +0xE, then clears a four-bit field at bits
 * 20-23 of the word at +4 and sets it unconditionally to 1 (the mask/OR
 * pair is plain integer arithmetic, `(x & ~0xF00000) | (1 << 20)`; no
 * bitfield struct is needed since the two shift amounts in the AND/OR would
 * not match docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md's
 * shape anyway).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C8A4.c \
 *       --addr 0x0201C8A4 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Rec2 {
    u32 unk00;
    u32 unk04;
    u16 pad08[3];
    u16 unk0E;
};

void PRINTSYS_SetJobColor(struct Rec2 *p, u16 v)
{
    p->unk0E = v;
    p->unk04 = (p->unk04 & ~0xF00000u) | (1u << 20);
}
