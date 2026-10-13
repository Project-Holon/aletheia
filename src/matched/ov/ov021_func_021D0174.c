/*
 * function: FLDEFF_BTRAIN_LoadResources
 * address:  0x021D0174
 * packet:   pkt_ov021_021D0174
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
 *   sBtrainAnimeFiles  0x021DB8C4  data  a2
 *   sBtrainModelFiles  0x021DB8CC  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern const u16 sBtrainModelFiles[];
extern const u16 sBtrainAnimeFiles[];

typedef struct B {
    u32 f0;
    u32 f4[4 + 4];
    u32 f24[4];
    u32 f34[8];
} B;

void FLDEFF_BTRAIN_LoadResources(B *p, int i)
{
    u32 x;
    const u16 *s;
    const u16 *t;
    int j;

    x = FIELD_EFFECT_GetArcHandle((u8 *)p->f0);
    s = sBtrainModelFiles;
    if (p->f4[i] == 0) {
        p->f4[i] = (u32)G3D_SYSTEM_CreateResourceArcHandle(x, s[i]);
        G3D_SYSTEM_TransVramTexture((int *)p->f4[i]);
        p->f34[i] = (u32)G3D_SYSTEM_CreateRender((void *)p->f4[i], 0, (void *)p->f4[i]);
    }
    t = sBtrainAnimeFiles;
    for (j = 0; j < 4; j++, t++) {
        if (p->f24[j] == 0) {
            p->f24[j] = (u32)G3D_SYSTEM_CreateResourceArcHandle(x, *t);
        }
    }
}
