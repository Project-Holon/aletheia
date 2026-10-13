/*
 * function: INTRUDE_FIELD_AddAreaMmdls
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
 *   INTRUDE_FIELD_AddMmdl 0x0217BF2C thumb ov018
 *   INTRUDE_FIELD_gAreaMmdlDefs 0x02182B54 data a4
 */
typedef unsigned short u16;
typedef enum { INDEX_ZERO, INDEX_ONE } Index;
typedef struct { u16 f0, f2, f4, f6, f8; } Ent;
extern void INTRUDE_FIELD_AddMmdl(int, u16, u16, int, u16, u16, u16);
extern const Ent INTRUDE_FIELD_gAreaMmdlDefs[];
void INTRUDE_FIELD_AddAreaMmdls(int a)
{
    Index i;
    int j;
    unsigned int column;
    j = 1;
    do {
        i = INDEX_ZERO;
        do {
            column = INTRUDE_FIELD_gAreaMmdlDefs[i].f2;
            INTRUDE_FIELD_AddMmdl(a, column + (j << 6), INTRUDE_FIELD_gAreaMmdlDefs[i].f4, 0x2001F, INTRUDE_FIELD_gAreaMmdlDefs[i].f0, INTRUDE_FIELD_gAreaMmdlDefs[i].f6, j + INTRUDE_FIELD_gAreaMmdlDefs[i].f8 - 1);
            i++;
        } while ((unsigned int)i < 1);
        j++;
    } while (j < 3);
}
