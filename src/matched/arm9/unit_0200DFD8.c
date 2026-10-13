/*
 * unit:     yes
 * function: BSUBWAY_SAVEDATA_GetStat
 * address:  0x0200DFD8
 * packet:   pkt_0200DFD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two leaves after BSUBWAY_SAVEDATA_InitStats on a table of three-halfword records:
 * read entry [row][col], and write it clamped to 0..0xFFFF (signed
 * compares, so the value is an int). Seeded from ov175 (0x021D62E8,
 * 0x021D6502, 0x021D9DA2 and their siblings).
 */

typedef unsigned short u16;

typedef u16 Row[3];

u16 BSUBWAY_SAVEDATA_GetStat(Row *table, int row, int col)
{
    return table[row][col];
}

void BSUBWAY_SAVEDATA_SetStat(Row *table, int row, int col, int value)
{
    if (value > 0xFFFF) {
        value = 0xFFFF;
    } else if (value < 0) {
        value = 0;
    }
    table[row][col] = value;
}
