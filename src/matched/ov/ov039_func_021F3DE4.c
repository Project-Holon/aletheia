/*
 * function: FIELD_GIMMICK_CART_LANES_GetAnimeFrame
 * address: 0x021F3DE4
 * packet: pkt_ov039_021F3DE4
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLD_EXP_OBJ_GetModelObject 0x021BE4C4 thumb ov021
 *   G3D_SYSTEM_GetObjectAnimeFrame 0x02047828 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FLD_EXP_OBJ_GetModelObject(void *p, u32 i, int delta);
typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);
int FIELD_GIMMICK_CART_LANES_GetAnimeFrame(void *p, u16 delta, u16 i) { int v = 0; G3D_SYSTEM_GetObjectAnimeFrame((struct AnmCtl *)FLD_EXP_OBJ_GetModelObject(p, 0, delta), i, &v); return v; }
