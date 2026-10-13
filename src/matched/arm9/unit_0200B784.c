/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B784
 * packet:   pkt_0200B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_GetModeLayout
 *
 * 84 bytes, 0x0200B784..0x0200B7D8, one function, which carries a label in the
 * generated listing.
 *
 * alias: inside "battle_rec.c"; the team-layout lookup the record builder at
 * 0x0200B7D8 calls.  It walks a 0x29-entry `u16` table of mode ids at
 * 0x0209DDCC, and the indices 0x10..0x13 and 0x16 are the multi
 * battle modes, which get four sides of three; everything else gets two sides
 * of six.  Indices 0x14 and 0x15 fall back into the search rather than
 * answering, which is the pair of exit-valued entries in the jump table.
 *
 * The switch is written with `case 0x14:` and `case 0x15:` as empty arms even
 * though they do nothing, because without them the labels the compiler sees
 * are not dense and it emits a compare chain instead of the seven-entry
 * `.hword` table the original has.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * This is a file of its own rather than part of the range that follows it
 * because 0x0209DDCC is named by exactly two literal pool words in the whole
 * image, this function's and BATTLE_REC_MakeHeader's, so a range holding both has no
 * witness left.  Cut between them and this one is attested by the other's
 * pool word.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The cut
 * does not save BATTLE_REC_MakeHeader, which is the only caller of this function and
 * therefore cannot be split away from it and attested at the same time; it is
 * parked in src/pending/unit_0200B7D8.c.
 *
 * symbols:
 *   BattleRecModeTable  0x0209DDCC  data
 */

typedef unsigned short u16;
typedef signed int     s32;

extern const u16 BattleRecModeTable[];

void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members)
{
    s32 i;

    for (i = 0; i < 0x29; i++) {
        if (mode == BattleRecModeTable[i]) {
            switch (i) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x16:
                *sides = 4;
                *members = 3;
                return;
            case 0x14:
            case 0x15:
                break;
            }
        }
    }
    *sides = 2;
    *members = 6;
}
