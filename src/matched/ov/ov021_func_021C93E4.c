/*
 * function: LAND_DATA_PATCH_OverwriteAttr
 * address:  0x021C93E4
 * packet:   pkt_ov021_021C93E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   LAND_DATA_PATCH_GetAttrBlock  0x021C94AC  thumb  ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20227.h"
#include "../include/Obj20228.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int LAND_DATA_PATCH_GetAttrBlock(u32 a);
extern void MI_CpuCopy8(void *src, void *dst, int n);

void LAND_DATA_PATCH_OverwriteAttr(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt)
{
    u8 *t = (u8 *)LAND_DATA_PATCH_GetAttrBlock(a);
    u8 *qb = q + 4;
    u8 *tb = t + 4;
    u32 i;

    for (i = 0; i < cnt; i++) {
        MI_CpuCopy8(tb + (x + (y + i) * ((struct Obj20228 *)t)->f0) * 0x18,
                      qb + (z + (w + i) * ((struct Obj20227 *)q)->f0) * 0x18, n * 0x18);
    }
}
