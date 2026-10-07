/*
 * file:     unit_021B7560_p09.c
 * unit:     yes
 * function: func_021B8348, func_021B8358
 * address:  0x021B8348
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj13735.h"
#include "../../matched/include/Obj22191.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

void func_021B8348(u32 p,u32 a,u16 b);
void func_021B8358(u8 *p);

void func_021B8348(u32 p,u32 a,u16 b) {((struct Obj13735 *)p)->f728=a;((struct Obj13735 *)p)->f72C=b;}


void func_021B8358(u8 *p) { ((struct Obj22191 *)p)->f730 = 1; }
