/*
 * function: func_021B7C08
 * address: 0x021B7C08
 * packet: pkt_ov103_021B7C08
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2-byte zero padding before the next labelled function.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj07981.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
struct Obj;
extern void func_0204B3B4(struct Obj *p); extern void func_0204ADA4(int); extern void func_0204A8D4(int); extern void func_0204AFD8(int); extern int func_0204B1CC(int); extern void func_0204A5AC(int); extern void func_02082BCC(void *,int,int);
void func_021B7C08(u8 *p) { int i; for(i=0;i<33;i++) { if(*(int *)(p+16+i*4)) func_0204B3B4((struct Obj *)(*(int *)(p+16+i*4))); } func_0204ADA4(((struct Obj07981 *)p)->f4); func_0204A8D4(((struct Obj07981 *)p)->f8); func_0204AFD8(((struct Obj07981 *)p)->fC); func_0204A5AC(func_0204B1CC(((struct Obj07981 *)p)->f0)); func_02082BCC(p,0,0x94); }
