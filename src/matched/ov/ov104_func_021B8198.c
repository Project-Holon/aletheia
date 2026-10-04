/*
 * function: func_021B8198
 * address: 0x021B8198
 * packet: pkt_ov104_021B8198
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B816C 0x021B816C thumb ov104
 *   func_021B8178 0x021B8178 thumb ov104
 *   func_021B817C 0x021B817C thumb ov104
 *   func_021B818C 0x021B818C thumb ov104
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B8528 0x021B8528 thumb ov104
 *   func_02040588 0x02040588 arm
 *   func_021B8220 0x021B8220 thumb ov104
 */
#include "../include/Obj13744.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021B816C(u8 *);
extern u32 func_021B8178(u8 *);
extern void func_021B817C(u8 *,void (*)(u8 *,u16 *));
extern void func_021B818C(u8 *);
extern int func_021B7250(int *p);
extern int func_021B6480(int *p);
extern void func_021B8528(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
extern void func_02040588(u32 which, u32 enable);
extern void func_021B8220(u8 *,u16 *);
void func_021B8198(u8 *p,u16 *state) { switch(*state) { case 0: ((struct Obj13744 *)p)->f80A=0; *state=1; break; case 1: func_02040588(2,0); *state=3; break; case 3: func_021B816C(p+0x7b0); func_021B817C(p,func_021B8220); break; } if(func_021B7250(((struct Obj13744 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); } if(func_021B6480(*(void **)(CTX(p)+4))!=0) func_021B817C(p,func_021B8528); }
