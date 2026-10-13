/*
 * function: PLACE_NAME_LETTER_DeleteBmpOam
 * address:  0x021BD2A4
 * packet:   pkt_ov021_021BD2A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_Delete  0x0202570C  thumb  arm9
 */

typedef struct {
    char pad[0xC];
    void *fC;
} Obj;

struct Grid;
extern void BMP_OAM_Delete(struct Grid *g);

void PLACE_NAME_LETTER_DeleteBmpOam(Obj *p)
{
    if (p->fC != 0) {
        BMP_OAM_Delete(p->fC);
        p->fC = 0;
    }
}
