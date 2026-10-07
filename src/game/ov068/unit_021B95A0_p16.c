/*
 * file:     unit_021B95A0_p16.c
 * unit:     yes
 * function: func_021BB4A4, func_021BB4D4
 * address:  0x021BB4A4
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BAFA8 0x021BAFA8 thumb ov068
 *   func_021BACF4 0x021BACF4 thumb ov068
 *   func_021BB138 0x021BB138 thumb ov068
 *   func_021BB188 0x021BB188 thumb ov068
 *   func_021BA9E0 0x021BA9E0 thumb ov068
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj20655.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a,b,c; } Blk;

extern void func_021BAFA8(u8 *p);
extern void func_021BACF4(u8 *p,u32 a,u32 b);
extern void func_021BB138(void *p,int v);
extern void func_021BB188(void *p,u32 *state);
extern void func_021BA9E0(u8 *p,Blk *out);
extern void func_020061E4(u32 id);
void func_021BB4A4(void *a,u32 b,u8 *p);
void func_021BB4D4(void *a,u32 b,u8 *p);

void func_021BB4A4(void *a,u32 b,u8 *p) { func_021BAFA8(p+0x248); func_021BACF4(p+0x148,((struct Obj20655 *)p)->f24B,1); func_021BB138(a,(int)func_021BB188); }

void func_021BB4D4(void *a,u32 b,u8 *p) { Blk t; func_021BA9E0(p+0x148,&t); func_021BAFA8((u8 *)&t); func_020061E4(0x558); func_021BB138(a,(int)func_021BB188); }
