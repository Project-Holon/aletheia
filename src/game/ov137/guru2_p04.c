/*
 * file:     guru2_p04.c
 * unit:     yes
 * function: func_021DCBC4, func_021DCBCC
 * address:  0x021DCBC4
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
 *   func_021DCB94 0x021DCB94 thumb ov137
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj14205.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed short s16;

extern void func_021DCB94(u8 *p, u32 id, const void *data, u32 size);
extern int func_021DCE00(char *,int);
extern void func_02082D44(void *,int,u32);
void func_021DCBC4(void *p,u32 a,const void *b,u32 c);
void func_021DCBCC(int i,int unused,void *q,char *p);

void func_021DCBC4(void *p,u32 a,const void *b,u32 c) {func_021DCB94(p,a,b,c);}

void func_021DCBCC(int i,int unused,void *q,char *p) {((struct Obj14205 *)p)->f46=((struct Obj14205 *)p)->f46|(s16)(1<<i);func_02082D44(q,func_021DCE00(p,i),1428);}
