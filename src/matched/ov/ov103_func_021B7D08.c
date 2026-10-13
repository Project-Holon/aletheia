/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_Exit3D
 * address: 0x021B7D08
 * packet: pkt_ov103_021B7D08
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitModel 0x021B7EB8 thumb ov103
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */
#include "../include/Obj22180.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitModel(u8 *); extern void G3D_CAMERA_Delete(void *); extern void G3D_SYSTEM_Exit(void);
void IRC_COMPATIBLE_TOUCH_TEST_Exit3D(u8 *p) { int i; for(i=0;i<2;i++)IRC_COMPATIBLE_TOUCH_TEST_ExitModel(p+4+i*0x60); G3D_CAMERA_Delete(((struct Obj22180 *)p)->f0); G3D_SYSTEM_Exit(); }
