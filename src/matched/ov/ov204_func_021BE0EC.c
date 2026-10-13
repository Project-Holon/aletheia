/*
 * unit: yes
 * function: func_021BE0EC, func_021BE100, func_021BE108
 * address: 0x021BE0EC
 * packet: pkt_ov204_021BE0EC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "../include/Obj25337.h"
struct Light;
/* Original consumes 02048AD0's live r0 through the next veneer call. */
extern void *G3D_CAMERA_Reset(struct Light *);
extern void G3D_SYSTEM_DrawStart(void *);
extern void G3D_SYSTEM_ApplyLookAt(void);
void func_021BE0EC(char *p){G3D_SYSTEM_DrawStart(G3D_CAMERA_Reset(*(struct Light * *)&((struct Obj25337 *)p)->f0));G3D_SYSTEM_ApplyLookAt();}
extern void G3D_SYSTEM_DrawEnd(void);
void func_021BE100(char *unused){G3D_SYSTEM_DrawEnd();}
int func_021BE108(void){return 1;}
