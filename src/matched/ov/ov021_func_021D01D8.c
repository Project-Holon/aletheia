/*
 * function: FLDEFF_BTRAIN_FreeResources
 * address:  0x021D01D8
 * packet:   pkt_ov021_021D01D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FLDEFF_BTRAIN_FreeResources(u32 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (p[1 + i] != 0) {
            G3D_SYSTEM_DeleteRender((struct Rec *)p[13 + i]);
            G3D_SYSTEM_FreeVramTexture((u32 *)p[1 + i]);
            G3D_SYSTEM_DeleteResource((struct Tagged *)p[1 + i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (p[9 + i] != 0) {
            G3D_SYSTEM_DeleteResource((struct Tagged *)p[9 + i]);
        }
    }
}
