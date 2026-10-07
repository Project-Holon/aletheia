/*
 * file:     pms_input_view_p04.c
 * unit:     yes
 * function: func_021B99A4, func_021B99C4, func_021B99D8
 * address:  0x021B99A4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02024810 0x02024810 thumb
 *   func_021B98F8  0x021B98F8  thumb  ov110
 */
#include "../../matched/include/Obj22312.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern void func_02024810(char *,int,int);
extern u32 func_021B98F8(u8 *p, u16 *src, u16 *out, u32 n);
void func_021B99A4(unsigned int a,unsigned int b,unsigned int c,int d);
unsigned short func_021B99C4(unsigned int a,unsigned int b,unsigned int c);
u32 func_021B99D8(u32 a, u32 b, u32 c);

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void func_021B99A4(unsigned int a,unsigned int b,unsigned int c,int d) { unsigned int value; value=*(unsigned int *)(a+b*4+0x38); func_02024810(*(char * *)&((struct Obj22312 *)a)->f4,*(unsigned short *)(a+(value+c)*2+0x68),d); }

unsigned short func_021B99C4(unsigned int a,unsigned int b,unsigned int c) { unsigned int value; value=*(unsigned int *)(a+b*4+0x38); return *(unsigned short *)(a+(value+c)*2+0x68); }

u32 func_021B99D8(u32 a, u32 b, u32 c) { return func_021B98F8((u8 *)a, (u16 *)b, (u16 *)c, 0); }
