/*
 * function: FLDEFF_FISHING_LoadResources
 * address:  0x021ADF14
 * packet:   pkt_ov021_021ADF14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   sFishingAnimeFile     0x021DE120  data  a2
 */

typedef unsigned short u16;

extern u16 sFishingAnimeFile;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

void FLDEFF_FISHING_LoadResources(int *p)
{
    int r5 = FIELD_EFFECT_GetArcHandle((u8 *)p[0]);

    G3D_SYSTEM_TransVramTexture((int *)(p[1] = (int)G3D_SYSTEM_CreateResourceArcHandle(r5, 0x54)));
    p[2] = (int)G3D_SYSTEM_CreateResourceArcHandle(r5, sFishingAnimeFile);
    p[5] = (int)G3D_SYSTEM_CreateRender((void *)p[1], 0, (void *)p[1]);
    p[4] = (int)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p[5], (const struct G3dOwner *)p[2], 0);
    p[3] = (int)G3D_SYSTEM_CreateObject(p[5], (u32 *)(&p[4]), 1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p[3], 0);
}
