/*
 * file:     wifilogin_disp_p03.c
 * unit:     yes
 * function: func_021D4430, func_021D4474
 * address:  0x021D4430
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
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_02156C84 0x02156C84 thumb ov009
 *   func_021D5C24 0x021D5C24 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D43F4 0x021D43F4 thumb ov115
 *   func_021D4360 0x021D4360 thumb ov115
 *   func_02085D3C 0x02085D3C arm
 *   func_0203CBAC 0x0203CBAC arm
 *   func_0203C8A8 0x0203C8A8 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_021D592C 0x021D592C thumb ov115
 *   d_021D6560 0x021D6560 data a4
 *   d_021D65C0 0x021D65C0 data a4
 *   d_021D6640 0x021D6640 data a4
 */
#include "../../matched/include/Obj13849.h"

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
struct Req;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D5C70(u8 *p);
extern unsigned char func_02156C84(void);
extern void func_021D5C24(void *,int);
extern void func_021D426C(u8 *,u32);
extern void func_021D43F4(u8 *);
extern void func_021D4360(u8 *);
extern int func_02085D3C(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203C8A8(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021D592C(u8 *);
void func_021D4430(u8 *p);
void func_021D4474(u8 *p);
extern u8 d_021D6560[];
extern u8 d_021D65C0[];
extern u8 d_021D6640[];

void func_021D4430(u8 *p) {
 if(func_021D5C70((u8 *)W(0x38))) { if(func_02156C84() && !W(0x24) && *(int *)(P(0x40)+0x14)!=2) { func_021D5C24((void *)W(0x38),30); func_021D426C(p,(u32)func_021D43F4); } else { func_021D4360(p); } }
}

void func_021D4474(u8 *p) {
 int z; if(func_02085D3C()) *(u32 *)(d_021D6560+0x48)=0x79000; else *(u32 *)(d_021D6560+0x48)=0x5e400; if(*(int *)(P(0x40)+0xc)==44) *(u32 *)(d_021D6560+0x48)=0x50000; else if(*(int *)(P(0x40)+0xc)==36) *(u32 *)(d_021D6560+0x48)=0x6e000; if(*(int *)(P(0x40)+0xc)!=10) *(u32 *)(d_021D6560+0x40)=0; z=0; d_021D65C0[7]=*(int *)(P(0x40)+0xc); *(u32 *)d_021D6640=*(int *)(P(0x40)+0xc); func_0203CBAC((struct Req *)d_021D6560,z,(u32)p); func_0203C8A8(); if(!*(int *)(P(0x40)+8)) func_0203D34C(z,((struct Obj13849 *)p)->fC); else func_0203D34C(1,((struct Obj13849 *)p)->fC); func_021D5C24((void *)W(0x38),23); func_021D592C(P(0x34)); func_021D426C(p,(u32)func_021D4430);
}
