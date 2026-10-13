/*
 * function: FLD_EXP_OBJ_SetAnimeFrame
 * address:  0x021BE6CC
 * packet:   pkt_ov021_021BE6CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_EXP_OBJ_GetModelObject  0x021BE4C4  thumb  ov021
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm  arm9
 */

extern void *FLD_EXP_OBJ_GetModelObject(int a, int b, int c);
typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);

void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e)
{
    int t = e;

    G3D_SYSTEM_SetObjectAnimeFrame(FLD_EXP_OBJ_GetModelObject(a, b, c), d, &t);
}
