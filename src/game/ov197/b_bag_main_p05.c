/*
 * file:     b_bag_main_p05.c
 * unit:     yes
 * function: func_0220C68C, func_0220C6C0, func_0220C6D0
 * address:  0x0220C68C
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0220AF6C 0x0220AF6C thumb ov196
 *   func_0220AFDC 0x0220AFDC thumb ov196
 *   func_0220AFC4 0x0220AFC4 thumb ov196
 *   func_02209A7C 0x02209A7C thumb
 */
#include "../../matched/include/Obj00315.h"
#include "../../matched/include/Obj25044.h"

typedef unsigned char  u8;

extern void func_0220AF6C(char *,int,int,int,int),func_0220AFDC(char *,void *);
extern void func_0220AFC4(u8 *p);
extern int func_02209A7C(int, int, int);
void func_0220C68C(char *p);
void func_0220C6C0(char *a);
void func_0220C6D0(char *a);

void func_0220C68C(char *p){func_0220AF6C(*(char * *)&((struct Obj00315 *)p)->f148,*(int *)&((struct Obj00315 *)p)->f420,((struct Obj00315 *)p)->f564,((struct Obj00315 *)p)->f588,((struct Obj00315 *)p)->f594);func_0220AFDC(*(char * *)&((struct Obj00315 *)p)->f148,0);}


void func_0220C6C0(char *a)
{
    func_0220AFC4((u8 *)(((struct Obj25044 *)a)->f148));
}


void func_0220C6D0(char *a)
{
    ((struct Obj00315 *)a)->f14C = func_02209A7C(*(int *)&((struct Obj00315 *)a)->f8, 9,
                                         *(unsigned short *)(*(int *)&((struct Obj00315 *)a)->f0 + 0xc));
}
