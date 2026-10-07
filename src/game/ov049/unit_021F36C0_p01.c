/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC
 * address:  0x021F36C0
 * region:   ov049
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021F3714 0x021F3714 thumb ov049
 *   func_021F3864 0x021F3864 thumb ov049
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3868 0x021F3868 thumb ov049
 *   func_021897A0 0x021897A0 thumb ov021
 */
#include "../../matched/include/Obj20549.h"

typedef unsigned short u16;

typedef unsigned char  u8;

extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p,int id,int a,int b);
extern void func_021F3714(unsigned int a0,unsigned int a);
extern void func_021F3864(void *q,unsigned char *p);
extern int *func_021897BC(char *p,int idx);
extern void func_021F3868(int *q,char *p);
extern void func_021897A0(unsigned char *p,int id);
void func_021F36C0(unsigned char *p);
void func_021F36EC(char *p);

void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=func_02188C84((u8 *)((int)p)); q=func_02189764(p,0,h,2); ((struct Obj20549 *)q)->f0=h; func_021F3714((unsigned int)q,(unsigned int)p); func_021F3864(q,p); }

void func_021F36EC(char *p) { func_021F3868(func_021897BC(p,0),p); func_021897A0((unsigned char *)p,0); }
