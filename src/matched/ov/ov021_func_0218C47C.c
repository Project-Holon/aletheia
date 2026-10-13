/*
 * function: FIELD_BUILDMODEL_GetSlotFrame
 * address:  0x0218C47C
 * packet:   pkt_ov021_0218C47C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 */

typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);

int FIELD_BUILDMODEL_GetSlotFrame(int *p, int id)
{
    int out;
    G3D_SYSTEM_GetObjectAnimeFrame((struct AnmCtl *)(*p), (unsigned short)id, &out);
    return out;
}
