/*
 * function: func_021B7DA8
 * address: 0x021B7DA8
 * packet: pkt_ov102_021B7DA8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj13726.h"
struct U16Vec; struct Descriptor; extern void STRBUF_Delete(struct U16Vec *); extern void func_020452E8(struct Descriptor *); extern void func_02082BCC(void *,int,unsigned);
void func_021B7DA8(void *p) { STRBUF_Delete(*(struct U16Vec * *)&((struct Obj13726 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13726 *)p)->f0); func_02082BCC(p,0,20); }
