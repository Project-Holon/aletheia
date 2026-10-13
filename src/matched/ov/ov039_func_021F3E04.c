/*
 * function: GIMMICK39_SetAnimeFrame
 * address: 0x021F3E04
 * packet: pkt_ov039_021F3E04
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLD_EXP_OBJ_GetModelObject 0x021BE4C4 thumb ov021
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FLD_EXP_OBJ_GetModelObject(void *p, u32 i, int delta);
typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
void GIMMICK39_SetAnimeFrame(void *p, u8 delta, u16 i, int frame) { G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)FLD_EXP_OBJ_GetModelObject(p, 0, delta), i, &frame); }
