/*
 * file:     unit_021B95A0_p04.c
 * unit:     yes
 * function: func_021B9E08, func_021B9E28, func_021B9E50, func_021B9E80
 * address:  0x021B9E08
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_021B9830 0x021B9830 thumb ov213
 */
#include "../../matched/include/Obj25692.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0204E804(void);
extern void func_021B9830(u8 *task, char *p);
int func_021B9E08(void *a,void *b);
int func_021B9E28(const char *p);
int func_021B9E50(u32 x);
int func_021B9E80(u32 x);

int func_021B9E08(void *a,void *b) {if(func_0204E804()==1)return 0;func_021B9830(a,b);return 1;}

int func_021B9E28(const char *p) {switch(((struct Obj25692 *)p)->f44){case 1:case 3:return 0;case 2:case 4:return 1;case 0:default:return 0;}}

int func_021B9E50(u32 x) {switch(x){case 1:return 1;case 2:return 1;case 3:return 0;case 4:return 0;case 0:default:return 1;}}

int func_021B9E80(u32 x) {switch(x){case 1:return 1;case 2:return 0;case 3:return 1;case 4:return 0;case 0:default:return 1;}}
