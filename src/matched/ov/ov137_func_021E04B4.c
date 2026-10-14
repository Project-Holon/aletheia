/*
 * unit: no
 * function: GURU2_MAIN_DeleteCamera
 * address: 0x021E04B4
 * packet: pkt_ov137_021E04B4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 */
#include "../include/Obj03842.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern u32 G3D_CAMERA_Delete(void *ptr);
void GURU2_MAIN_DeleteCamera(u8 *p){G3D_CAMERA_Delete(((struct Obj03842 *)p)->fD54);}
