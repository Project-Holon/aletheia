/*
 * function: IRC_RHYTHM_ExitTextWindow
 * address: 0x021B7EC8
 * packet: pkt_ov104_021B7EC8
 * region: ov104
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
#include "../include/Obj13743.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec; struct Descriptor;
extern void STRBUF_Delete(struct U16Vec *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void MI_CpuFill8(void *,int,int);
void IRC_RHYTHM_ExitTextWindow(u8 *p) { STRBUF_Delete(*(struct U16Vec * *)&((struct Obj13743 *)p)->fC); BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj13743 *)p)->f0); MI_CpuFill8(p,0,20); }
