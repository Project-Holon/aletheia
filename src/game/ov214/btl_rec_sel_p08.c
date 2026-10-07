/*
 * file:     btl_rec_sel_p08.c
 * unit:     yes
 * function: func_021BAE10, func_021BAE4C
 * address:  0x021BAE10
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   d_021BB498 0x021BB498 data a4
 *   func_021BB2A8 0x021BB2A8 thumb ov214
 *   func_021BAB0C 0x021BAB0C thumb ov214
 */
#include "../../matched/include/Obj00182.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_020403F4(u8);
extern u32 func_021BB2A8(u8 *);
extern int func_021BAB0C(int,u16,int,u8,u32,u32,u32,u32,void *,u8,u8,u8,u8,u8);
void func_021BAE10(int unused, char *p);
void func_021BAE4C(int unused,u8 *p);
extern const u8 d_021BB498[];

static inline void GXS_SetVisibleWnd(int window){*(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000&~0xe000u)|(window<<13);}

/*
 * volatile: hardware registers 0x04001050 (021BAE30), 0x04001000 read/write (021BAE34/021BAE3A).
 */
void func_021BAE10(int unused, char *p){int i;for(i=0;i<1u;i++)func_020403F4(*(u32 *)(d_021BB498+i*44));*(volatile u16 *)0x04001050=0;GXS_SetVisibleWnd(0);}

void func_021BAE4C(int unused,u8 *p){*(int *)&((struct Obj00182 *)p)->f2D4=func_021BAB0C(func_021BB2A8(*(u8 * *)&((struct Obj00182 *)p)->f4),((struct Obj00182 *)p)->f0,0,0,1,0,0,0,p+0x2c4,0,0,0,1,1);}
