/*
 * function: func_021B6A00
 * address: 0x021B6A00
 * packet: pkt_ov098_021B6A00
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6148 0x021B6148 thumb ov098
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6B8C 0x021B6B8C thumb ov098
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj07936.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index); extern u32 func_021B6148(u8 *); extern void func_0201F02C(void *,u32,void *); extern void func_0201F250(void *,void *,void *); extern void func_021B6B8C(int,int); extern void STRBUF_Delete(void *);
void func_021B6A00(u8 *p,u8 *q) { void *r; u32 t; r=func_02045EC0(((struct Obj07936 *)p)->f20,4); t=func_021B6148(q); func_0201F02C(((struct Obj07936 *)p)->f30,0,(void *)t); func_0201F250(((struct Obj07936 *)p)->f30,((struct Obj07936 *)p)->f2C,r); func_021B6B8C((int)p,80); STRBUF_Delete(r); }
