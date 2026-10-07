/*
 * file:     unit_021B95A0_p13.c
 * unit:     yes
 * function: func_021BA2A4, func_021BA2D0
 * address:  0x021BA2A4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA578 0x021BA578 thumb ov099
 *   func_021BA36C 0x021BA36C thumb ov099
 *   func_021BA5B4 0x021BA5B4 thumb ov099
 *   func_021C57D8 0x021C57D8 thumb ov127
 */
#include "../../matched/include/Obj02448.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021BA578(void *,void *);
extern void func_021BA36C(void *,void *);
extern void func_021BA5B4(void *,int,void *);
extern void func_021C57D8(void *,int);
void func_021BA2A4(void *w,u8 *s);
void func_021BA2D0(void);

void func_021BA2A4(void *w,u8 *s) { ((struct Obj02448 *)s)->f10=(void *)func_021BA578; ((struct Obj02448 *)s)->f18=(void *)func_021BA36C; ((struct Obj02448 *)s)->f8=28; ((struct Obj02448 *)s)->fC=4; func_021BA5B4(w,4,s); func_021C57D8(((struct Obj02448 *)s)->f4,0); }

void func_021BA2D0(void)
{
}
