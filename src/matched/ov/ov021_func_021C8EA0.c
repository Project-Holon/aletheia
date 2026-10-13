/*
 * function: FLDEFF_D06DENKI_LoadResources
 * address:  0x021C8EA0
 * packet:   pkt_ov021_021C8EA0
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
 *   sD06DenkiModelFiles     0x021DAB6C  data  a4
 *   sD06DenkiAnimeFiles     0x021DAB7C  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct A4 { u32 v[4]; } A4;
typedef struct A5 { u32 v[5]; } A5;

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
extern const A4 sD06DenkiModelFiles;
extern const A5 sD06DenkiAnimeFiles;

void FLDEFF_D06DENKI_LoadResources(u32 *p)
{
    A4 a;
    A5 b;
    u32 r6;
    u32 i;

    a = sD06DenkiModelFiles;
    b = sD06DenkiAnimeFiles;
    r6 = FIELD_EFFECT_GetArcHandle((u8 *)p[0]);
    for (i = 0; i < 4; i++) {
        p[1 + i] = (u32)G3D_SYSTEM_CreateResourceArcHandle(r6, a.v[i]);
        G3D_SYSTEM_TransVramTexture((int *)p[1 + i]);
    }
    for (i = 0; i < 5; i++) {
        p[5 + i] = (u32)G3D_SYSTEM_CreateResourceArcHandle(r6, b.v[i]);
    }
    p[11] = (u32)G3D_SYSTEM_CreateRender((void *)p[1], 0, (void *)p[1]);
    p[10] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p[11], (const struct G3dOwner *)p[5], 0);
    p[12] = (u32)G3D_SYSTEM_CreateObject(p[11], p + 10, 1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p[12], 0);
}
