/*
 * file:     wf2dmap_objdraw_p03.c
 * unit:     yes
 * function: func_021C5898, func_021C58B8, func_021C58C8
 * address:  0x021C5898
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C428C  0x021C428C  thumb  ov127
 */
#include "../../matched/include/Obj23053.h"
#include "../../matched/include/Obj23054.h"
#include "../../matched/include/Obj10478.h"

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_021C428C(char *p, int x, int y);
void func_021C5898(char *p, P2 v);
int func_021C58B8(char *p);
char *func_021C58C8(u8 *p);


/*
 * Unlabelled: forwards a by-value {s16 x, y} pair to func_021C428C with the
 * pointer at +4.  Blocker of ov099 func_021BA2D4 / func_021BA36C.
 */
void func_021C5898(char *p, P2 v)
{
    func_021C428C(((struct Obj23053 *)p)->f4, v.x, v.y);
}


int func_021C58B8(char *p)
{
    return ((struct Obj23054 *)p)->f4 == 0;
}

char *func_021C58C8(u8 *p) { int i,offset; for(i=0;i<((struct Obj10478 *)p)->f8;i++) { offset=i*20; if(func_021C58B8(*(char * *)&((struct Obj10478 *)p)->f4+offset)==1) return *(char * *)&((struct Obj10478 *)p)->f4+offset; } return 0; }
