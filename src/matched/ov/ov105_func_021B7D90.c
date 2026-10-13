/*
 * function: IRC_RESULT_ExitTextWindow
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
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj13752.h"
struct U16Vec; struct Descriptor; extern void STRBUF_Delete(struct U16Vec *); extern void BMP_WIN_Delete(struct Descriptor *); extern void MI_CpuFill8(void *,unsigned char,unsigned int);
void IRC_RESULT_ExitTextWindow(unsigned char *p) { STRBUF_Delete(*(struct U16Vec * *)&((struct Obj13752 *)p)->fC); BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj13752 *)p)->f0); MI_CpuFill8(p,0,20); }
