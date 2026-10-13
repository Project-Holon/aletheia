/*
 * function: func_021B9BD0
 * address: 0x021B9BD0
 * packet: pkt_ov133_021B9BD0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj06501.h"
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p); extern void MSGDATA_Delete(void *); extern void GF_FONT_Delete(void *);
void func_021B9BD0(unsigned char *p) {PRINTSYS_QUE_Delete(((struct Obj06501 *)p)->f18E8);MSGDATA_Delete(((struct Obj06501 *)p)->f18DC);MSGDATA_Delete(((struct Obj06501 *)p)->f18E0);MSGDATA_Delete(((struct Obj06501 *)p)->f18D8);GF_FONT_Delete(((struct Obj06501 *)p)->f18E4);}
