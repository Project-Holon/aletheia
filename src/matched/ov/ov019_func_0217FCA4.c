/*
 * function: UNION_EFF_DeleteIconObj
 * address: 0x0217FCA4
 * packet: pkt_ov019_0217FCA4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef unsigned int u32;
struct Rec; struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
void UNION_EFF_DeleteIconObj(u32 *p) { G3D_SYSTEM_DeleteObject((struct Rec *)p[3]); G3D_SYSTEM_DeleteRender((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }
