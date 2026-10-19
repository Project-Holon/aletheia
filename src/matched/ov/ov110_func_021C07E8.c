/*
 * function: PMS_SELECT_GRAPHIC_DeleteBg
 * address: 0x021C07E8
 * packet: pkt_ov110_021C07E8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj08011.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);
void PMS_SELECT_GRAPHIC_DeleteBg(u8 *p) { BMP_WIN_Delete(((struct Obj08011 *)p)->f24); BG_SYS_FreeTileRun(3,(u16)(((struct Obj08011 *)p)->f0),(u16)(((struct Obj08011 *)p)->f0>>16)); func_020307B0(((struct Obj08011 *)p)->f4); }
