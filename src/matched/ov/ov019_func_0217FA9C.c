/*
 * function: UNION_EFF_DrawAnimObj
 * address: 0x0217FA9C
 * packet: pkt_ov019_0217FA9C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   G3D_SYSTEM_DrawObjectCulling 0x02047AC8 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Actor; struct Arg;
typedef struct { int x,y,z; } VecFx32;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern int G3D_SYSTEM_DrawObjectCulling(void *a, struct Arg *b);
void UNION_EFF_DrawAnimObj(u32 *p, u32 *b) { FLDMMDL_GetPos((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6000; G3D_SYSTEM_DrawObjectCulling((void *)p[3], (struct Arg *)b); }
