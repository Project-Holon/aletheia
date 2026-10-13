/*
 * function: FIELD_BUILDMODEL_StartGroupClosing
 * address:  0x0218C2E4
 * packet:   pkt_ov021_0218C2E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts a group of slots, sets a parameter, marks them state 4.
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelAnimDefs  0x0218BCAC  thumb  ov021
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern int G3D_SYSTEM_GetObjectAnime(int *p, int i);
extern int G3D_SYSTEM_GetAnimeObj(int p);
typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

void FIELD_BUILDMODEL_StartGroupClosing(u32 *st, int n)
{
    u8 *q = FIELD_BUILDMODEL_GetModelAnimDefs(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;
    int v;

    for (i = 0; i < q[2]; i++) {
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)st[0], (u16)(base + i));
        v = *(u16 *)(*(u8 **)(G3D_SYSTEM_GetAnimeObj((int)G3D_SYSTEM_GetObjectAnime((int *)st[0], (u16)(base + i))) + 8) + 4) << 12;
        G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)st[0], base + i, &v);
        (st + base)[2 + i] = 4;
    }
}
