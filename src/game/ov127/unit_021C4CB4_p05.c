/*
 * file:     unit_021C4CB4_p05.c
 * unit:     yes
 * function: func_021C5300, func_021C5334, func_021C5370, func_021C539C
 * address:  0x021C5300
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C4A00 0x021C4A00 thumb ov127
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4CE4 0x021C4CE4 thumb ov127
 *   func_021C4994 0x021C4994 thumb ov127
 *   d_021C607C 0x021C607C data a4
 *   func_021C5564 0x021C5564 thumb ov127
 */
#include "../../matched/include/Obj10473.h"

typedef unsigned char u8;

typedef unsigned short u16;

struct pair {u16 a,b;};

typedef int (*Callback)(void *,void *,void *,const u8 *,void *);

extern int func_021C49A4(u8 *,unsigned);
extern void func_021C4A00(void *,int,int);
extern struct pair func_021C4AC4(char *);
extern void func_021C4CE4(char *,struct pair,int);
extern char *func_021C4994(unsigned *p, unsigned id);
extern void func_021C5564(u8 *,void *,int,int,int);
int func_021C5300(u8 *p);
void func_021C5334(char *p);
int func_021C5370(void *a, void *b, const u8 *desc, int *out);
int func_021C539C(u8 *p,int a,int b,const u8 *desc,u8 *out);
extern const Callback d_021C607C[];

int func_021C5300(u8 *p)
{
 int a=func_021C49A4(p,8), b=func_021C49A4(p,9);
 if(a<b) { func_021C4A00(p,8,a+1); if(a+1<b) return 0; }
 return 1;
}

void func_021C5334(char *p) { struct pair v=func_021C4AC4(p); func_021C4CE4(p,v,func_021C49A4((u8 *)p,6)); }

int func_021C5370(void *a, void *b, const u8 *desc, int *out) { return d_021C607C[*(u16 *)desc](func_021C4994(b,desc[3]),a,b,desc,out); }

int func_021C539C(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5);  if(v==0 || v==4) { func_021C5564(out,p,((struct Obj10473 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }
