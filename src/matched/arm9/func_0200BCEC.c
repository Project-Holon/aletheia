/*
 * function: func_0200BCEC
 * address:  0x0200BCEC
 * packet:   pkt_0200BCEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 SODATEYA_CompactSlots
 * (wave A1, lane 13).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int active;
    u8 data[0xDC];
    u32 count;
} E;

void func_0200BCEC(E *e, int i, int j)
{
    E t;

    if (i < 0 || i >= 2 || j < 0 || j >= 2)
        return;
    t = e[i];
    e[i] = e[j];
    e[j] = t;
}
