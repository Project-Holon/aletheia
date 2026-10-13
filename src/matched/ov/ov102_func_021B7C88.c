/*
 * function: func_021B7C88
 * address: 0x021B7C88
 * packet: pkt_ov102_021B7C88
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj07975.h"
struct Rec; extern void func_0201ED04(void *); extern void MSGDATA_Delete(struct Rec *); extern void func_0201C4C0(unsigned); extern void GF_FONT_Delete(void *); extern void func_02082BCC(void *,int,unsigned);
void func_021B7C88(void *p) { func_0201ED04(((struct Obj07975 *)p)->fC); MSGDATA_Delete(*(struct Rec * *)&((struct Obj07975 *)p)->f4); func_0201C4C0(((struct Obj07975 *)p)->f8); GF_FONT_Delete(((struct Obj07975 *)p)->f0); func_02082BCC(p,0,16); }
