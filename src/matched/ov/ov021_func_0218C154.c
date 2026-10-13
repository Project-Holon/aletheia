/*
 * function: FIELD_BUILDMODEL_UpdateAnimSetSeason
 * address:  0x0218C154
 * packet:   pkt_ov021_0218C154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts slot i of a four-slot effect set, or resets it.
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetSeasonAnimSlot  0x0218BD24  thumb  ov021
 *   FIELD_BUILDMODEL_GetSeasonChanged  0x0218BD20  thumb  ov021
 *   FIELD_BUILDMODEL_ResetAnimSet  0x0218C388  thumb  ov021
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 FIELD_BUILDMODEL_GetSeasonAnimSlot(u8 *p);
extern u32 FIELD_BUILDMODEL_GetSeasonChanged(u8 *p);
extern void FIELD_BUILDMODEL_ResetAnimSet(u32 *st);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

void FIELD_BUILDMODEL_UpdateAnimSetSeason(u8 *a, u32 *st)
{
    int i = FIELD_BUILDMODEL_GetSeasonAnimSlot(a + 8);

    if (FIELD_BUILDMODEL_GetSeasonChanged(a + 8) != 0) {
        FIELD_BUILDMODEL_ResetAnimSet(st);
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)st[0], (u16)i);
        G3D_SYSTEM_ResetObjectAnimeFrame((struct AnmCtl *)st[0], i);
        (st + i)[2] = 1;
    } else {
        G3D_SYSTEM_LoopObjectAnimeFrame((void *)st[0], (u16)i, 0x1000);
    }
}
