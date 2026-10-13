/*
 * function: POKELIST_ShutdownLight
 * address: 0x021B7040
 * packet: pkt_ov091_021B7040
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj20855.h"
extern void PARTICLE_ExitManager(void);
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void func_0207D63C(unsigned,unsigned,unsigned,unsigned,unsigned);
void POKELIST_ShutdownLight(unsigned p) { PARTICLE_ExitManager(); G3D_CAMERA_Delete((void *)(((struct Obj20855 *)p)->f258)); G3D_SYSTEM_Exit(); func_020403F4(0); func_0207D63C(0x04000050,20,8,16,10); }
