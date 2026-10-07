/*
 * file:     compatible_irc_sys_p09.c
 * unit:     yes
 * function: func_021B6E8C, func_021B6EBC
 * address:  0x021B6E8C
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021B753C 0x021B753C data a1
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj22124.h"
#include "../../matched/include/Obj22125.h"
#include "../../matched/include/Obj22127.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020307B0(void *p);
void *func_021B6E8C(u32 heap,u8 *p);
void func_021B6EBC(void *q,u8 *p);
extern const char d_021B753C[];

void *func_021B6E8C(u32 heap,u8 *p) { void *q; q=func_02030734(heap,4,0,d_021B753C,0x49b); func_02082BCC(q,0,4); ((struct Obj22125 *)q)->f0=**(u32 * *)&((struct Obj22124 *)p)->f10; return q; }

void func_021B6EBC(void *q,u8 *p) { func_020307B0(q); ((struct Obj22127 *)p)->f38=1; }
