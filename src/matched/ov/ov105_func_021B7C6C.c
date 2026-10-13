/*
 * function: IRC_RESULT_ExitTextSystem
 * address: 0x021B7C6C
 * packet: pkt_ov105_021B7C6C
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07989.h"
struct WordSet; struct Rec; struct PrintSys; extern void func_0201ED04(struct WordSet *); extern void MSGDATA_Delete(struct Rec *); extern void PRINTSYS_QUE_Delete(struct PrintSys *); extern void GF_FONT_Delete(void *); extern void MI_CpuFill8(void *,unsigned char,unsigned int);
void IRC_RESULT_ExitTextSystem(unsigned char *p) { func_0201ED04(*(struct WordSet * *)&((struct Obj07989 *)p)->fC); MSGDATA_Delete(*(struct Rec * *)&((struct Obj07989 *)p)->f4); PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj07989 *)p)->f8); GF_FONT_Delete(((struct Obj07989 *)p)->f0); MI_CpuFill8(p,0,16); }
