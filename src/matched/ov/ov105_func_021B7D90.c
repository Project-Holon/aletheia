/*
 * function: func_021B7D90
 * address: 0x021B7D90
 * packet: pkt_ov105_021B7D90
 * region: ov105
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
#include "../include/Obj13752.h"
struct U16Vec; struct Descriptor; extern void STRBUF_Delete(struct U16Vec *); extern void func_020452E8(struct Descriptor *); extern void func_02082BCC(void *,unsigned char,unsigned int);
void func_021B7D90(unsigned char *p) { STRBUF_Delete(*(struct U16Vec * *)&((struct Obj13752 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13752 *)p)->f0); func_02082BCC(p,0,20); }
