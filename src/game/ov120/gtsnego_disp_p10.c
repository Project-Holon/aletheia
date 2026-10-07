/*
 * file:     gtsnego_disp_p10.c
 * unit:     yes
 * function: func_021D51D4, func_021D5208
 * address:  0x021D51D4
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
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5188 0x021D5188 thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_021D6D94 0x021D6D94 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
#include "../../matched/include/Obj10389.h"
#include "../../matched/include/Obj22831.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021D79F4(u8 *p, u16 n);
extern void func_021D4244(int,void (*)(int),int);
extern void func_021D5188(int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D6D94(u8 *);
extern void func_021D588C(int);
void func_021D51D4(u8 *p);
void func_021D5208(u8 *p);

/*
 * lever: The caller has no halfword truncation before func_021D79F4;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 */
void func_021D51D4(u8 *p) { if (((struct Obj10389 *)p)->f148==-1) func_021D79F4(*(u8 * *)&((struct Obj10389 *)p)->f40,45); else func_021D79F4(*(u8 * *)&((struct Obj10389 *)p)->f40,31); func_021D4244((int)p,func_021D5188,0x646); }

void func_021D5208(u8 *p) { func_02040588(4,0); func_021D6D94(*(u8 * *)&((struct Obj22831 *)p)->f3C); func_021D4244((int)p,func_021D588C,0x64e); }
