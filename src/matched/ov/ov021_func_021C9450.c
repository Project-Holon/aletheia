/*
 * function: LAND_DATA_PATCH_AddBuildModels
 * address:  0x021C9450
 * packet:   pkt_ov021_021C9450
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   LAND_DATA_PATCH_GetBuildModelBlock  0x021C94B4  thumb  ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *   FIELD_BUILDMODEL_RegisterObject  0x0218BA04  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern int LAND_DATA_PATCH_GetBuildModelBlock(u32 a);
extern void MI_CpuCopy8(void *src, void *dst, int n);
extern void FIELD_BUILDMODEL_RegisterObject(u32 a, u32 b, u32 *c, u32 d);

u32 LAND_DATA_PATCH_AddBuildModels(u32 a, u32 b, u32 c, u32 d, int e, int f)
{
    u32 *t = (u32 *)LAND_DATA_PATCH_GetBuildModelBlock(a);
    u32 *e0 = t + 1;
    u32 i;
    u32 loc[4];

    for (i = 0; i < t[0]; i++) {
        MI_CpuCopy8(e0 + i * 4, loc, 0x10);
        loc[0] += e << 16;
        loc[2] -= f << 16;
        FIELD_BUILDMODEL_RegisterObject(b, c, loc, d + i);
    }
    return d + t[0];
}
