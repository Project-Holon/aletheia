/*
 * file:     wifilogin_disp_p05.c
 * unit:     yes
 * function: func_021D46CC, func_021D4708, func_021D4798
 * address:  0x021D46CC
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D456C 0x021D456C thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_02009800 0x02009800 thumb
 *   func_021D4474 0x021D4474 thumb ov115
 *   func_021D497C 0x021D497C thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 */
#include "../../matched/include/Obj08041.h"
#include "../../matched/include/Obj22591.h"
#include "../../matched/include/Obj10330.h"
#include "../../matched/include/Obj22592.h"

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
struct Big;
struct Obj;
struct Rec160;
struct Reg2;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

extern u32 func_020221A4(void);
extern int func_021D5C70(int);
extern void func_021D426C(u8 *,u32);
extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D456C(u8 *);
extern void func_021D5D3C(int);
extern int func_021D5E6C(u8 *p);
extern u8 func_021D5EA8(u8 *p);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200B358(void *);
extern void *func_02012EBC(struct Big *p);
extern void func_0200BBD8(struct Obj *p, int v);
extern void *func_0200BAC8(void *);
extern void func_0200B110(struct Reg2 *p, u32 id, s32 value);
extern void func_02009800(void *p);
extern void func_021D4474(u8 *);
extern void func_021D497C(u8 *);
extern void func_021D5F7C(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_021D5E34(u8 *p);
void func_021D46CC(u8 *p);
void func_021D4708(u8 *p);
void func_021D4798(u8 *p);

void func_021D46CC(u8 *p) { if(func_020221A4() && func_021D5C70(*(int *)&((struct Obj08041 *)p)->f38)) { ((struct Obj08041 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj08041 *)p)->f38,0,!((struct Obj22591 *)(*(u8 * *)&((struct Obj08041 *)p)->f40))->f4,0); func_021D426C(p,(u32)func_021D456C); } }

void func_021D4708(u8 *p) {
 void *v; if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { v=func_0200B1D4(func_0200B358(func_02012EBC((void *)W(0x44))),0); func_0200BBD8(func_0200BAC8(func_02012EBC((void *)W(0x44))),1); func_0200B110(v,10,5); *(int *)(P(0x40)+0x1c)=0; func_02009800((void *)W(0x3c)); func_021D426C(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; func_021D426C(p,(u32)func_021D497C); } func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}

void func_021D4798(u8 *p) { ((struct Obj10330 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj10330 *)p)->f38,1,!((struct Obj22592 *)(*(u8 * *)&((struct Obj10330 *)p)->f40))->f4,1); func_021D426C(p,(u32)func_021D4708);  }
