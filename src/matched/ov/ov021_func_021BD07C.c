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
 */

typedef struct {
    char pad[0x24];
    void *f24;
} Obj;

struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);

void FIELD_PLACE_NAME_DeleteBmpWin(Obj *p)
{
    if (p->f24 != 0) {
        func_020452E8(p->f24);
        p->f24 = 0;
    }
}
