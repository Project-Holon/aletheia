/*
 * function: MUSICAL_SHOT_SYS_Exit3D
 * address: 0x021F3ED0
 * packet: pkt_ov112_021F3ED0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */
#include "../include/Obj13824.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32);
extern void BILLBOARD_Delete(void *);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
void MUSICAL_SHOT_SYS_Exit3D(u8 *p) { func_020403F4(3); func_020403F4(1); func_020403F4(2); BILLBOARD_Delete(((struct Obj13824 *)p)->f1C); G3D_CAMERA_Delete(((struct Obj13824 *)p)->f18); G3D_SYSTEM_Exit(); func_020403F4(0); }
