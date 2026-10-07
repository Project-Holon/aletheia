/*
 * file:     unit_021B7560_p07.c
 * unit:     yes
 * function: func_021B87F4, func_021B8810, func_021B8834, func_021B884C
 * address:  0x021B87F4
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02035D20 0x02035D20 arm
 */
#include "../../matched/include/Obj22233.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 words[33]; } Record;

extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
void func_021B87F4(u8 *p,Record *out);
void func_021B8810(int a,int b,int c,u8 *p,int e);
u8 *func_021B8834(int a,u8 *p);
int func_021B884C(u32 *p);

/*
 * extent: Two zero bytes of alignment padding follow the return.
 */
void func_021B87F4(u8 *p,Record *out) { *out=*(Record *)(p+8); }

void func_021B8810(int a,int b,int c,u8 *p,int e) { if(e==(int)func_020399A8() && a!=func_02039338()) ((struct Obj22233 *)p)->f194=1; }

u8 *func_021B8834(int a,u8 *p) { if(a==func_02039338()) return p+0x8c; else return p+8; }

int func_021B884C(u32 *p) { u32 x,y; if(func_02035D20(&x,&y)) { if(x<=256 && y<=168) { p[0]=x; p[1]=y; return 1; } } return 0; }
