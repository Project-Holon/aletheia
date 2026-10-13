/*
 * function: FLDEFF_BUBBLE_FreeResources
 * address:  0x021D06E0
 * packet:   pkt_ov021_021D06E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_CheckResourceType  0x02046F50  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */

typedef struct S {
    int f0;
    int a[3];
    int f10;
    int b[2];
    int f1c;
} S;

typedef unsigned int   u32;
struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern u32 G3D_SYSTEM_CheckResourceType(struct Tagged *p, u32 sel);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FLDEFF_BUBBLE_FreeResources(S *p)
{
    int i;

    G3D_SYSTEM_DeleteObject((struct Rec *)p->f1c);
    for (i = 0; i < 2; i++) {
        G3D_SYSTEM_DeleteAnime((struct Rec *)p->b[i]);
    }
    G3D_SYSTEM_DeleteRender((struct Rec *)p->f10);
    for (i = 0; i < 3; i++) {
        if (G3D_SYSTEM_CheckResourceType((struct Tagged *)p->a[i], 2)) {
            G3D_SYSTEM_FreeVramTexture((u32 *)p->a[i]);
        }
        G3D_SYSTEM_DeleteResource((struct Tagged *)p->a[i]);
    }
}
