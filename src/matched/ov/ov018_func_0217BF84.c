/*
 * function: func_0217BF84
 * address: 0x0217BF84
 * packet: pkt_ov018_0217BF84
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum inner counter preserves the one-iteration loop; unsigned comparison;
 *   named column load fixes the Thumb add operands.
 * symbols:
 *   func_0217BF2C 0x0217BF2C thumb ov018
 *   d_02182B54 0x02182B54 data a4
 */
typedef unsigned short u16;
typedef enum { INDEX_ZERO, INDEX_ONE } Index;
typedef struct { u16 f0, f2, f4, f6, f8; } Ent;
extern void func_0217BF2C(int, u16, u16, int, u16, u16, u16);
extern const Ent d_02182B54[];
void func_0217BF84(int a)
{
    Index i;
    int j;
    unsigned int column;
    j = 1;
    do {
        i = INDEX_ZERO;
        do {
            column = d_02182B54[i].f2;
            func_0217BF2C(a, column + (j << 6), d_02182B54[i].f4, 0x2001F, d_02182B54[i].f0, d_02182B54[i].f6, j + d_02182B54[i].f8 - 1);
            i++;
        } while ((unsigned int)i < 1);
        j++;
    } while (j < 3);
}
