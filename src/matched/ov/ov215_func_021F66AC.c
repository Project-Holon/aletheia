/*
 * unit: yes
 * function: func_021F66AC,func_021F66C0
 * address: 0x021F66AC
 * packet: pkt_ov215_021F66AC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes cleared tiny follower func_021F66C0; no further code included.
 * symbols:
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "../include/Obj25755.h"
struct Light;
extern void G3D_SYSTEM_DrawStart(void *);
extern void G3D_CAMERA_Reset(struct Light *);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
void func_021F66AC(void *p){G3D_SYSTEM_DrawStart(p);G3D_CAMERA_Reset(*(struct Light * *)&((struct Obj25755 *)p)->f0);G3D_SYSTEM_ApplyLookAt();}
void func_021F66C0(void *p){G3D_SYSTEM_DrawEnd();}
