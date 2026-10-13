/*
 * function: DWCi_CELLlSetEffect
 * address:  0x021D4FF4
 * packet:   pkt_ov016_021D4FF4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlSetEffect (libdwcutil.TWL.HYB.a(cell.o))
 *
 * symbols:
 *   (none)
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 attr01;
    u32 attr23;
} OamAttr;

typedef struct {
    int pad0;
    int pad4;
    OamAttr *oam;
    u8 num;
} CellInfo;

void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine)
{
    CellInfo *c = (CellInfo *)cell;
    OamAttr *oam = c->oam;
    int i;

    if (idx >= 0) {
        if (effect != 0x100 && effect != 0x300)
            { oam[idx].attr01 &= 0xC1FFFCFF; oam[idx].attr01 |= effect; }
        else
            { oam[idx].attr01 &= 0xC1FFFCFF; oam[idx].attr01 |= effect; oam[idx].attr01 |= (u32)affine << 25; }
    } else {
        for (i = 0; i < c->num; i++) {
            if (effect != 0x100 && effect != 0x300)
                { oam[i].attr01 &= 0xC1FFFCFF; oam[i].attr01 |= effect; }
            else
                { oam[i].attr01 &= 0xC1FFFCFF; oam[i].attr01 |= effect; oam[i].attr01 |= (u32)affine << 25; }
        }
    }
}
