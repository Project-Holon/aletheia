/*
 * function: func_021D5250
 * address:  0x021D5250
 * packet:   pkt_ov016_021D5250
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlGetPosition (libdwcutil.TWL.HYB.a(cell.o))
 *
 * symbols:
 *   (none)
 */

typedef unsigned int u32;

typedef struct {
    u32 attr01;
    u32 attr23;
} OamAttr;

typedef struct {
    int pad0;
    int pad4;
    OamAttr *oam;
} CellInfo;

void func_021D5250(void *cell, int idx, int *x, int *y)
{
    OamAttr *oam = ((CellInfo *)cell)->oam;
    *x = (oam[idx].attr01 & 0x01ff0000) >> 16;
    *y = oam[idx].attr01 & 0xff;
}
