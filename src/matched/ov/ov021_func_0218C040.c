/*
 * function: FIELD_BUILDMODEL_InitAnimSetAll
 * address:  0x0218C040
 * packet:   pkt_ov021_0218C040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 *   FIELD_BUILDMODEL_GetModelAnimDefs  0x0218BCAC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);
extern u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);

void FIELD_BUILDMODEL_InitAnimSetAll(void *a, void **b)
{
    u8 *t;
    u32 n;
    int i;

    t = FIELD_BUILDMODEL_GetModelAnimDefs(*(void **)b[1]);
    n = t[2];
    for (i = 0; i < 4 && i < n; i++) {
        G3D_SYSTEM_EnableObjectAnime(b[0], (u16)i);
        G3D_SYSTEM_ResetObjectAnimeFrame(b[0], i);
        b[2 + i] = (void *)1;
    }
    for (; i < 4; i++)
        b[2 + i] = 0;
}
