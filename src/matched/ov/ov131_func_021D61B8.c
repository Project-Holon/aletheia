/*
 * function: func_021D61B8
 * address: 0x021D61B8
 * packet: pkt_ov131_021D61B8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 */
#include "../include/Obj08145.h"
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
typedef unsigned short u16;
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021D61B8(unsigned char *p,int a,void *b,int c,short d,short e,unsigned short f) {
 void *t=func_020457B0(16,((struct Obj08145 *)p)->f0);
 void *s=func_02045EC0(((struct Obj08145 *)p)->f7C,c);
 func_0201F250(b,t,s);
 func_0201C724(((struct Obj08145 *)p)->f84,a,d,e,(u32)t,((struct Obj08145 *)p)->f80,f);
 func_02045808(s);
 func_02045808(t);
}
