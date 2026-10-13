/*
 * function: FIELD_BUILDMODEL_InitAnimSetSeason
 * address:  0x0218C08C
 * packet:   pkt_ov021_0218C08C
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
 *   FIELD_BUILDMODEL_GetSeasonAnimSlot  0x0218BD24  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);
extern u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);
extern u8 FIELD_BUILDMODEL_GetSeasonAnimSlot(u8 *p);

void FIELD_BUILDMODEL_InitAnimSetSeason(u8 *a, void **b)
{
    int i;
    u32 m;

    FIELD_BUILDMODEL_GetModelAnimDefs(*(void **)b[1]);
    m = FIELD_BUILDMODEL_GetSeasonAnimSlot(a + 8);
    for (i = 0; i < 4; i++) {
        if (i != m) {
            b[2 + i] = 0;
        } else {
            G3D_SYSTEM_EnableObjectAnime(b[0], (u16)i);
            G3D_SYSTEM_ResetObjectAnimeFrame(b[0], i);
            b[2 + i] = (void *)1;
        }
    }
}
