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
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj13726.h"
struct U16Vec; struct Descriptor; extern void STRBUF_Delete(struct U16Vec *); extern void BMP_WIN_Delete(struct Descriptor *); extern void MI_CpuFill8(void *,int,unsigned);
void func_021B7DA8(void *p) { STRBUF_Delete(*(struct U16Vec * *)&((struct Obj13726 *)p)->fC); BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj13726 *)p)->f0); MI_CpuFill8(p,0,20); }
