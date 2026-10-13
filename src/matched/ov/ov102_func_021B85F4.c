/*
 * function: IRC_COMPATIBLE_MENU_ExitButtons
 * address: 0x021B85F4
 * packet: pkt_ov102_021B85F4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj13728.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BUTTON_MAN_Delete(void *);
extern void MI_CpuFill8(void *, int, u32);
void IRC_COMPATIBLE_MENU_ExitButtons(u8 *p) { int i; for(i=0;i<((struct Obj13728 *)p)->f2C;i++)BMP_WIN_Delete(*(void **)(p+4+i*4)); BUTTON_MAN_Delete(((struct Obj13728 *)p)->f0); MI_CpuFill8(p,0,60); }
