/*
 * function: STA_ACT_LIGHT_FreeModel
 * address: 0x021F7048
 * packet: pkt_ov112_021F7048
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding before 021F7098.
 * symbols:
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 */
typedef unsigned char u8;
typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;
typedef unsigned int   u32;
struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
void STA_ACT_LIGHT_FreeModel(Cleanup *p) {
    u8 i;
    G3D_SYSTEM_DeleteObject((struct Rec *)p->d);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteAnime((struct Rec *)p->c[i]);
    G3D_SYSTEM_DeleteRender((struct Rec *)p->b);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteResource((struct Tagged *)p->a[i]);
    G3D_SYSTEM_FreeVramTexture((u32 *)p->single);
    G3D_SYSTEM_DeleteResource((struct Tagged *)p->single);
    p->single = 0;
}
