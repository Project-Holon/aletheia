/*
 * function: func_021B7D30
 * address: 0x021B7D30
 * packet: pkt_ov103_021B7D30
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 */
#include "../include/Obj22181.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void G3D_SYSTEM_DrawStart(void); extern void G3D_CAMERA_Reset(void *); extern void G3D_SYSTEM_ApplyLookAt(void);
void func_021B7D30(u8 *p) {G3D_SYSTEM_DrawStart(); G3D_CAMERA_Reset(((struct Obj22181 *)p)->f0); G3D_SYSTEM_ApplyLookAt();}
