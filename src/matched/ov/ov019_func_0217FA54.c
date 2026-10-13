/*
 * function: UNION_EFF_DeleteAnimObj
 * address: 0x0217FA54
 * packet: pkt_ov019_0217FA54
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   MI_CpuFill8 0x02082BCC arm
 */

typedef unsigned int u32;
struct Rec;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
void UNION_EFF_DeleteAnimObj(u32 *p) { G3D_SYSTEM_DeleteAnime((struct Rec *)p[2]); G3D_SYSTEM_DeleteObject((struct Rec *)p[3]); G3D_SYSTEM_DeleteRender((struct Rec *)p[1]); MI_CpuFill8(p,0,0x14); }
