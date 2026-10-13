/*
 * function: func_021EE244
 * address:  0x021EE244
 * packet:   pkt_ov170_021EE244
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_SetPos 0x0202590C thumb
 */

typedef signed short   s16;
struct Grid;
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);

void func_021EE244(char *p, int i, int flag)
{
    if (flag == 0)
        BMP_OAM_SetPos(*(void **)(p + i * 8 + 4), -0x94, 0x14);
    else
        BMP_OAM_SetPos(*(void **)(p + i * 8 + 4), 0xDC, 0x14);
}
