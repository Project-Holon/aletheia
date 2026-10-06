/*
 * function: func_021F0E40
 * address: 0x021F0E40
 * packet: pkt_ov107_021F0E40
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0203E6C0 0x0203E6C0 arm
 */
#include "../include/Obj10259.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u8 pad[24];unsigned short low:11,flag:1,rest:4;} State;
extern u32 func_020307B0(void *p);
extern void func_0203E6C0(void);
void func_021F0E40(State *p) { if(((struct Obj10259 *)p)->f14)func_020307B0(((struct Obj10259 *)p)->f14);if(p->flag==1)func_0203E6C0();func_020307B0(((struct Obj10259 *)p)->f10);func_020307B0(p); }
