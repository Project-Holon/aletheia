/*
 * function: P_STATUS_PrintMsg
 * address: 0x021D614C
 * packet: pkt_ov131_021D614C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj10506.h"
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
typedef unsigned short u16;
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void P_STATUS_PrintMsg(unsigned char *p,int a,int b,int c,short d,unsigned short e) {
 void *t=func_02045EC0(((struct Obj10506 *)p)->f7C,b);
 func_0201C724(((struct Obj10506 *)p)->f84,a,(short)c,d,(u32)t,((struct Obj10506 *)p)->f80,e);
 func_02045808(t);
}
