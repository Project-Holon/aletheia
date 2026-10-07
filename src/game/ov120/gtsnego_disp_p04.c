/*
 * file:     gtsnego_disp_p04.c
 * unit:     yes
 * function: func_021D4774, func_021D4798
 * address:  0x021D4774
 * region:   ov120
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
 *   func_02039C68 0x02039C68 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D46A4 0x021D46A4 thumb ov120
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../../matched/include/Obj22826.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *,u32,u32);
extern void func_021D4244(int,void (*)(int),int);
extern void func_021D46A4(int);
extern int func_02008468(void);
extern int func_0203D3A8(void *,u16,u16,u32);
void func_021D4774(int p);
void func_021D4798(u8 *p);

void func_021D4774(int p) { func_02039C68((struct Link *)func_020399A8(),3,34); func_021D4244(p,func_021D46A4,0x2ac); }

void func_021D4798(u8 *p) { void *link; int n; link=func_020399A8(); n=func_02008468(); if (func_0203D3A8(link,0x2201,n,*(u32 *)(((struct Obj22826 *)p)->f48+20))) func_021D4244((int)p,func_021D4774,0x2bd); }
