/*
 * function: FLDEFF_GYOE_DeleteResource
 * address:  0x021BB504
 * packet:   pkt_ov021_021BB504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm  arm9
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm  arm9
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm  arm9
 */

typedef struct {
    int pad0;
    void *a4[4];
    void *a14[4];
    void *a24[4];
} Obj;

struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FLDEFF_GYOE_DeleteResource(Obj *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        G3D_SYSTEM_DeleteObject(p->a24[i]);
        G3D_SYSTEM_DeleteRender(p->a14[i]);
        G3D_SYSTEM_DeleteResource(p->a4[i]);
    }
}
