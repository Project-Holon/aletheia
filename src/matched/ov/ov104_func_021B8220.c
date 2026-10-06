/*
 * function: func_021B8220
 * address: 0x021B8220
 * packet: pkt_ov104_021B8220
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
 *   func_021B8104 0x021B8104 thumb ov104
 *   func_021B85E4 0x021B85E4 thumb ov104
 *   func_021B8F00 0x021B8F00 thumb ov104
 *   func_021B829C 0x021B829C thumb ov104
 */
#include "../include/Obj13745.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021B816C(u8 *);
extern u32 func_021B8178(u8 *);
extern void func_021B817C(char *p, u32 v);
extern void func_021B818C(u8 *);
extern int func_021B7250(int *p);
extern int func_021B6480(int *p);
extern void func_021B8528(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
extern void func_021B8104(u32 *);
extern void func_021B85E4(u8 *p);
extern void func_021B8F00(void *);
extern void func_021B829C(u8 *,u16 *);
void func_021B8220(u8 *p,u16 *state) { func_021B8104((u32 *)(p+0x7b0)); if(func_021B8178(p+0x7b0)) { ((struct Obj13745 *)p)->f8A8=1; func_021B85E4(p+0x814); func_021B8F00(p+0x7cc); func_021B817C((char *)p,(u32)func_021B829C); } if(func_021B7250(((struct Obj13745 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); } if(func_021B6480(*(void **)(CTX(p)+4))!=0) func_021B817C((char *)p,(u32)func_021B8528); }
