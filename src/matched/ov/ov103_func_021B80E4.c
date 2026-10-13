/*
 * function: func_021B80E4
 * address: 0x021B80E4
 * packet: pkt_ov103_021B80E4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj13732.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec); extern void func_020452E8(void *); extern void func_02082BCC(void *,int,u32);
void func_021B80E4(u8 *p) {STRBUF_Delete(((struct Obj13732 *)p)->fC);func_020452E8(((struct Obj13732 *)p)->f0);func_02082BCC(p,0,20);}
