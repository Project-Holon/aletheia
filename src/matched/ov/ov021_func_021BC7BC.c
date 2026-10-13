/*
 * function: FIELD_PLACE_NAME_SetClactUnitRenderer
 * address:  0x021BC7BC
 * packet:   pkt_ov021_021BC7BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetUnitRenderer  0x0204B258  arm  arm9
 */

typedef struct {
    char pad[0x34];
    void *f34[1];
    void *f38;
} Obj;

struct Bank;
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);

void FIELD_PLACE_NAME_SetClactUnitRenderer(Obj *p, int i)
{
    if (p->f38 != 0) {
        CLACT_SetUnitRenderer(p->f34[i], p->f38);
    }
}
