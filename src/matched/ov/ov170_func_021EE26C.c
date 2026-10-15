/*
 * function: BOX2_UI_ShiftSlotOams
 * address:  0x021EE26C
 * packet:   pkt_ov170_021EE26C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_OAM_GetPos 0x020258E8 thumb
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BOX2_UI_SetSlotOamEnabled 0x021EE224 thumb
 */
#include "../include/Obj14282.h"

typedef signed short   s16;
struct Grid;
struct Obj02025774;
extern void BMP_OAM_GetPos(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
extern void BOX2_UI_SetSlotOamEnabled(char *p, int i, int v);

void BOX2_UI_ShiftSlotOams(char *p, int d)
{
    unsigned i;
    short x;
    short y;
    for (i = 7; i <= 8; i++) {
        char *e = p + i * 8;
        BMP_OAM_GetPos(((struct Obj14282 *)e)->f4, &x, &y);
        BMP_OAM_SetPos(((struct Obj14282 *)e)->f4, x + d, y);
        if (x + d == -0x94 || x + d == 0xDC)
            BOX2_UI_SetSlotOamEnabled(p, i, 0);
    }
}
