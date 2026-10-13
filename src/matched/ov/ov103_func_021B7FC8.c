/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ExitText
 * address: 0x021B7FC8
 * packet: pkt_ov103_021B7FC8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07982.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern u32 func_0201ED04(struct WordSet *p); extern void MSGDATA_Delete(void *); extern void PRINTSYS_QUE_Delete(void *); extern void GF_FONT_Delete(void *); extern void MI_CpuFill8(void *,int,u32);
void IRC_COMPATIBLE_TOUCH_TEST_ExitText(u8 *p) {func_0201ED04(((struct Obj07982 *)p)->fC);MSGDATA_Delete(((struct Obj07982 *)p)->f4);PRINTSYS_QUE_Delete(((struct Obj07982 *)p)->f8);GF_FONT_Delete(((struct Obj07982 *)p)->f0);MI_CpuFill8(p,0,16);}
