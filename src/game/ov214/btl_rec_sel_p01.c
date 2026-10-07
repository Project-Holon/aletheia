/*
 * file:     btl_rec_sel_p01.c
 * unit:     yes
 * function: func_021B9EB8, func_021B9ED4, func_021B9EF0
 * address:  0x021B9EB8
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj05548.h"
#include "../../matched/include/Obj25721.h"
#include "../../matched/include/Obj10934.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

void func_021B9EB8(char *a, int b, char *c, int d, int e, int f, int g, int h, int i);
void func_021B9ED4(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d);
void func_021B9EF0(void *unused,char *p,unsigned a,unsigned b,unsigned c);


void func_021B9EB8(char *a, int b, char *c, int d, int e, int f, int g, int h, int i)
{
    ((struct Obj25721 *)a)->f0 = 0;
    ((struct Obj05548 *)c)->f1C = d;
    ((struct Obj05548 *)c)->f20 = e;
    ((struct Obj05548 *)c)->f24 = f;
    ((struct Obj05548 *)c)->f28 = g;
    ((struct Obj05548 *)c)->f2C = h;
    ((struct Obj05548 *)c)->f30 = i;
}

void func_021B9ED4(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d){*out=2;func_021B9EF0(a,p,b,c,d);}

void func_021B9EF0(void *unused,char *p,unsigned a,unsigned b,unsigned c){((struct Obj10934 *)p)->f34=a;((struct Obj10934 *)p)->f38=b;((struct Obj10934 *)p)->f3C=c;}
