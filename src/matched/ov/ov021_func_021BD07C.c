/*
 * function: FIELD_PLACE_NAME_DeleteBmpWin
 * address:  0x021BD07C
 * packet:   pkt_ov021_021BD07C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 */

typedef struct {
    char pad[0x24];
    void *f24;
} Obj;

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void FIELD_PLACE_NAME_DeleteBmpWin(Obj *p)
{
    if (p->f24 != 0) {
        BMP_WIN_Delete(p->f24);
        p->f24 = 0;
    }
}
