/*
 * file:     guru2_p05.c
 * unit:     yes
 * function: func_021DCF50, func_021DCF58
 * address:  0x021DCF50
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../../matched/include/Obj01414.h"
#include "../../matched/include/Obj23703.h"
#include "../../matched/include/Obj23705.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed short s16;

typedef unsigned short u16;

extern u16 func_02039338(void);
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
void *func_021DCF50(u8 *p);
void func_021DCF58(int a,int b,u8 *p);


void *func_021DCF50(u8 *p) {return **(void ** *)&((struct Obj23703 *)(*(u8 * *)&((struct Obj01414 *)p)->fC))->f14;}

void func_021DCF58(int a,int b,u8 *p) {u8 v;if(func_02039338()==0) {v=a;func_021DCBC4(((struct Obj23705 *)p)->f10,10240,&v,1);}}
