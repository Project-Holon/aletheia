/*
 * unit:     yes
 * function: func_0200DFD8
 * address:  0x0200DFD8
 * packet:   pkt_0200DFD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two leaves after func_0200DFCC on a table of three-halfword records:
 * read entry [row][col], and write it clamped to 0..0xFFFF (signed
 * compares, so the value is an int). Seeded from ov175 (0x021D62E8,
 * 0x021D6502, 0x021D9DA2 and their siblings).
 */

typedef unsigned short u16;

typedef u16 Row[3];

u16 func_0200DFD8(Row *table, int row, int col)
{
    return table[row][col];
}

void func_0200DFE4(Row *table, int row, int col, int value)
{
    if (value > 0xFFFF) {
        value = 0xFFFF;
    } else if (value < 0) {
        value = 0;
    }
    table[row][col] = value;
}
