/*
 * function: func_021B7EC8
 * address: 0x021B7EC8
 * packet: pkt_ov104_021B7EC8
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj13743.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec; struct Descriptor;
extern void func_02045808(struct U16Vec *);
extern void func_020452E8(struct Descriptor *);
extern void func_02082BCC(void *,int,int);
void func_021B7EC8(u8 *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13743 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13743 *)p)->f0); func_02082BCC(p,0,20); }
