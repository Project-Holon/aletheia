/*
 * function: func_0200BC2C
 * address:  0x0200BC2C
 * packet:   pkt_0200BC2C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C3490 and func_021C34C4
 * (wave A1, lane 13).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int active;
    u8 data[0xDC];
    u32 count;
} E;

void *func_0200BC2C(E *e, int i)
{
    if (i < 0 || i >= 2 || e[i].active != 1)
        i = 0;
    return e[i].data;
}
