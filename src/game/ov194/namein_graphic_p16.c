/*
 * file:     namein_graphic_p16.c
 * unit:     yes
 * function: func_021F3EB0, func_021F3ED0
 * address:  0x021F3EB0
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC arm
 *   func_0203101C  0x0203101C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj24909.h"
#include "../../matched/include/Obj10810.h"

struct S02031140;
extern void MI_CpuFill8(void *, int, int);
extern void *func_0203101C(int, int, int, int);
extern void func_0201CE48(int);
extern void func_02031140(struct S02031140 *);
extern void func_02082BCC(void *,int,int);
void func_021F3EB0(char *p, int v);
void func_021F3ED0(unsigned char *p);


void func_021F3EB0(char *p, int v)
{
    MI_CpuFill8(p, 0, 0x10);
    ((struct Obj24909 *)p)->f4 = func_0203101C(v, v, 1, 0);
}

void func_021F3ED0(unsigned char *p){if(((struct Obj10810 *)p)->f0)func_0201CE48(((struct Obj10810 *)p)->f0);func_02031140(*(struct S02031140 * *)&((struct Obj10810 *)p)->f4);func_02082BCC(p,0,16);}
