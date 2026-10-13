/*
 * function: FIELD_BUILDMODEL_StartGroupOpening
 * address:  0x0218C23C
 * packet:   pkt_ov021_0218C23C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts a group of slots and marks them state 3.
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelAnimDefs  0x0218BCAC  thumb  ov021
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);

void FIELD_BUILDMODEL_StartGroupOpening(u32 *st, int n)
{
    u8 *q = FIELD_BUILDMODEL_GetModelAnimDefs(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)st[0], (u16)(base + i));
        G3D_SYSTEM_ResetObjectAnimeFrame((struct AnmCtl *)st[0], base + i);
        (st + base)[2 + i] = 3;
    }
}
