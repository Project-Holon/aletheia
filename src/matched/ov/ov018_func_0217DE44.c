/*
 * function: INTRUDE_SUBDISP_DeleteButtonBmpOam
 * address: 0x0217DE44
 * packet: pkt_ov018_0217DE44
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 */
struct Grid;
struct Obj020437AC;
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
void INTRUDE_SUBDISP_DeleteButtonBmpOam(void **p)
{
    int i;
    for (i = 0; i < 2; i++) {
        BMP_OAM_Delete(p[0xc0 / 4 + i]);
        BMP_Delete(p[0xb4 / 4 + i]);
    }
}
