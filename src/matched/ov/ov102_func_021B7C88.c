/*
 * function: IRC_COMPATIBLE_MENU_ExitText
 * address: 0x021B7C88
 * packet: pkt_ov102_021B7C88
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07975.h"
struct Rec; extern void WORDSET_DeleteStrbufED04(void *); extern void MSGDATA_Delete(struct Rec *); extern void PRINTSYS_QUE_Delete(unsigned); extern void GF_FONT_Delete(void *); extern void MI_CpuFill8(void *,int,unsigned);
void IRC_COMPATIBLE_MENU_ExitText(void *p) { WORDSET_DeleteStrbufED04(((struct Obj07975 *)p)->fC); MSGDATA_Delete(*(struct Rec * *)&((struct Obj07975 *)p)->f4); PRINTSYS_QUE_Delete(((struct Obj07975 *)p)->f8); GF_FONT_Delete(((struct Obj07975 *)p)->f0); MI_CpuFill8(p,0,16); }
