/*
 * function: func_021B68DC
 * address: 0x021B68DC
 * packet: pkt_ov098_021B68DC
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020403F4 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec); extern void func_0201ED04(void *); extern void func_0201CE48(void *); extern void func_020403F4(int); extern void MSGDATA_Delete(void *); extern void func_020452E8(void *); extern void func_020307B0(void *);
void func_021B68DC(u8 *p) { STRBUF_Delete(((struct Obj05259 *)p)->f2C); func_0201ED04(((struct Obj05259 *)p)->f30); if (((struct Obj05259 *)p)->f0) func_0201CE48(((struct Obj05259 *)p)->f0); func_020403F4(1); MSGDATA_Delete(((struct Obj05259 *)p)->f20); func_020452E8(((struct Obj05259 *)p)->f1C); func_020307B0(p); }
