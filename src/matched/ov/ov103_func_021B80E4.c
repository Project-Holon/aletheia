/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ExitWindow
 * address: 0x021B80E4
 * packet: pkt_ov103_021B80E4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj13732.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec); extern void BMP_WIN_Delete(void *); extern void MI_CpuFill8(void *,int,u32);
void IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(u8 *p) {STRBUF_Delete(((struct Obj13732 *)p)->fC);BMP_WIN_Delete(((struct Obj13732 *)p)->f0);MI_CpuFill8(p,0,20);}
