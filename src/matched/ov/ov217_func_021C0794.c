/*
 * function: RESEARCH_GRAPH_DeleteOamObjects
 * address:  0x021C0794
 * packet:   pkt_021C0794
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

void RESEARCH_GRAPH_DeleteOamObjects(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_OAM_Delete((struct Grid *)p[i + 0xEA]);
}
