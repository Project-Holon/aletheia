/*
 * function: DWCi_CELLlSetPosition
 * address:  0x021D5118
 * packet:   pkt_ov016_021D5118
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlSetPosition (libdwcutil.TWL.HYB.a(cell.o))
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;
typedef struct { int pad0; int pad4; GXOamAttr *oam; u8 num; } CellInfo;

static inline void G2_GetOBJPosition(const GXOamAttr *oam, unsigned long *x, unsigned long *y)
{
    *x = (oam->attr01 & 0x01FF0000) >> 16;
    *y = (oam->attr01 & 0x000000FF) >> 0;
}

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y)
{
    CellInfo *c = (CellInfo *)cell;
    GXOamAttr *oam;
    int i;
    int x0, y0, x1, y1, dx, dy;

    oam = c->oam;
    if (idx >= 0) {
        G2_SetOBJPosition(&oam[idx], x, y);
    } else {
        G2_GetOBJPosition(&oam[0], (unsigned long *)&x0, (unsigned long *)&y0);
        G2_SetOBJPosition(&oam[0], x, y);
        dx = x - x0;
        dy = y - y0;
        for (i = 1; i < c->num; i++) {
            G2_GetOBJPosition(&oam[i], (unsigned long *)&x1, (unsigned long *)&y1);
            G2_SetOBJPosition(&oam[i], x1 + dx, y1 + dy);
        }
    }
}
