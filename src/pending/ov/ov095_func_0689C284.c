/*
 * function: func_0689C284
 * address: 0x0689C284
 * packet: pkt_ov095_0689C284
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: THM_CALL +0x8C func_0689C354 has no witness outside
 *   0689C284..0689C354; caller-only tu --suggest-split leaves this sole section OUT.
 * extent: 208-byte corrected body; C354 is a 16-byte Thumb bx-pc veneer
 *   to untraced 021E8A78; C364 is existing code. No veneer C filed.
 * lever: Word passed by value preserves the add-sp then load call argument.
 * boundary: handed 0689C286 is the label after 0f b4 at 0689C284;
 *   parent cleared corrected start after existing-source/unit/shard audit.
 * symbols:
 *   func_0689C354 0x0689C354 thumb ov095
 */
typedef struct { int v; } Word;
extern int func_0689C354(Word);
int func_0689C284(unsigned int selector, Word value)
{
    int result = -1;
    switch (selector) {
    case 4: result = 0xff; break;
    case 1: result = 0x111; break;
    case 3: result = 0x120; break;
    case 2: result = 0x132; break;
    case 6: result = 0x159; break;
    case 7: result = 0x147; break;
    case 9: result = 0x141; break;
    case 11: result = 0x238; break;
    case 12: result = 0x241; break;
    case 14: result = 0x29b; break;
    case 18: result = 0x25f; break;
    case 17: result = 0x171; break;
    case 21: result = 0x2e0; break;
    case 19: result = 0x2d7; break;
    case 13: result = 0x250; break;
    case 15: result = 0x371; break;
    case 5:
        if (func_0689C354(value) != 0) result = 0xed;
        else result = 0xea;
        break;
    }
    return result;
}
