/*
 * function: FIELD_PLACE_NAME_DeleteBmpOamSys
 * address:  0x021BC9AC
 * packet:   pkt_ov021_021BC9AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_DeleteSys  0x02025588  thumb  arm9
 */

typedef struct {
    char pad[0x30];
    void *f30;
} Obj;

extern void BMP_OAM_DeleteSys(void *a);

void FIELD_PLACE_NAME_DeleteBmpOamSys(Obj *p)
{
    if (p->f30 != 0) {
        BMP_OAM_DeleteSys(p->f30);
        p->f30 = 0;
    }
}
