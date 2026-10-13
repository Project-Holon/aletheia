/*
 * function: func_021BD458
 * address:  0x021BD458
 * packet:   pkt_021BD458
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_Delete  0x0202570C  thumb
 *
 * Addresses are Black-image addresses.
 */

struct Grid;
extern void BMP_OAM_Delete(struct Grid *g);

void func_021BD458(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        BMP_OAM_Delete((struct Grid *)p[i + 0x4C]);
}
