/*
 * file:     unit_021B7560_p07.c
 * unit:     yes
 * function: func_021B87BC, func_021B87C8
 * address:  0x021B87BC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B8A90 0x021B8A90 thumb ov102
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../../matched/include/Obj07980.h"

struct Struct021B8A90;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02082BCC(void *, int, u32);
extern int func_021B8A90(struct Struct021B8A90 *p);
extern void func_02041EE4(u32,u32,u32);
void func_021B87BC(void *p);
void func_021B87C8(u8 *p);

void func_021B87BC(void *p) { func_02082BCC(p,0,28); }

void func_021B87C8(u8 *p) { if(((struct Obj07980 *)p)->f18) { if(func_021B8A90((struct Struct021B8A90 *)p))((struct Obj07980 *)p)->f18=0; func_02041EE4(4,3,88-((struct Obj07980 *)p)->f0); func_02041EE4(7,3,88-((struct Obj07980 *)p)->f0); } }
