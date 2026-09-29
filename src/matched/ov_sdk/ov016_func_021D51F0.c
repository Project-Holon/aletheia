/*
 * function: func_021D51F0
 * address:  0x021D51F0
 * packet:   pkt_ov016_021D51F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlSetPriority (libdwcutil.TWL.HYB.a(cell.o))
 *
 * symbols:
 *   (none)
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 pad;
} OamAttr;

typedef struct {
    int pad0;
    int pad4;
    OamAttr *oam;
    u8 num;
} CellInfo;

void func_021D51F0(void *cell, int idx, int priority)
{
    CellInfo *c = (CellInfo *)cell;
    OamAttr *oam = c->oam;
    int i;

    if (idx >= 0) {
        oam[idx].attr2 = (oam[idx].attr2 & ~0xC00) | (priority << 10);
    } else {
        for (i = 0; i < c->num; i++)
            oam[i].attr2 = (oam[i].attr2 & ~0xC00) | (priority << 10);
    }
}
