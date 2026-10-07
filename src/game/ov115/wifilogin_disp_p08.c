/*
 * file:     wifilogin_disp_p08.c
 * unit:     yes
 * function: func_021D4B3C, func_021D4B80, func_021D4BB4, func_021D4BC4
 * address:  0x021D4B3C
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
 *   func_0202208C 0x0202208C thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4A98 0x021D4A98 thumb ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_02167FA8 0x02167FA8 arm ov009
 *   d_021D65D0 0x021D65D0 data a4
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_02168040 0x02168040 arm ov009
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 */
#include "../../matched/include/Obj22595.h"

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02005E30(u32 a);
extern void func_021D426C(u8 *,u32);
extern void func_021D4A98(u8 *);
extern int func_021D4644(u8 *);
extern int func_02167FA8(char *svl, void *result);
extern u32 func_020221A4(void);
extern int func_021D5C70(int);
extern void *func_021D5D5C(u8 *,int,int,int);
extern int func_02168040(void);
extern void func_021D4AB0(u8 *);
void func_021D4B3C(u8 *p);
void func_021D4B80(u8 *p);
void func_021D4BB4(u8 *p);
void func_021D4BC4(u8 *p);
extern u8 d_021D65D0[];

void func_021D4B3C(u8 *p) {
 func_0202208C(0,0,0,0,6,1,((struct Obj22595 *)p)->fC); if(!*(int *)(P(0x40)+4) && !*(int *)(P(0x40)+0x18)) func_02005E30(8); func_021D426C(p,(u32)func_021D4A98);
}

void func_021D4B80(u8 *p) {
 if(!func_021D4644(p)) { if(func_02167FA8((char *)d_021D65D0,(void *)(*(int *)(P(0x40)+0x10)))) func_021D426C(p,(u32)func_021D4BC4); else func_021D4644(p); }
}

void func_021D4BB4(u8 *p) { func_021D426C(p,(u32)func_021D4B80); }

void func_021D4BC4(u8 *p) { int x; if(!func_021D4644(p)) { x=func_02168040(); if(x==3) func_021D426C(p,(u32)func_021D4AB0); else if(x==4 || x==0 || x==5) func_021D4644(p); } }
