/*
 * function: GIMMICK57_DeleteModelScene
 * address:  0x021F37BC
 * packet:   pkt_ov057_021F37BC
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_CheckResourceType  0x02046F50  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */

typedef unsigned int   u32;
struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern u32 G3D_SYSTEM_CheckResourceType(struct Tagged *p, u32 sel);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void GIMMICK57_DeleteModelScene(int a, int b, char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        G3D_SYSTEM_DeleteObject((struct Rec *)(*(int *)(p + i * 4 + 0x38)));
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_DeleteAnime((struct Rec *)(*(int *)(p + i * 4 + 0x28)));
    for (i = 0; i < 3; i++)
        G3D_SYSTEM_DeleteRender((struct Rec *)(*(int *)(p + i * 4 + 0x1c)));
    for (i = 0; i < 7; i++) {
        if (G3D_SYSTEM_CheckResourceType((struct Tagged *)(*(int *)(p + i * 4)), 2))
            G3D_SYSTEM_FreeVramTexture((u32 *)(*(int *)(p + i * 4)));
        G3D_SYSTEM_DeleteResource((struct Tagged *)(*(int *)(p + i * 4)));
    }
}
