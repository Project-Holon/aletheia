/*
 * file:     unit_021BA290_p02.c
 * unit:     yes
 * function: func_021BA6BC, func_021BA6E8
 * address:  0x021BA6BC
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021BA720 0x021BA720 thumb ov218
 */
#include "../../matched/include/Obj03959.h"

struct Actor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct PtS{s16 x,y;} PtS;

extern void func_0204B454(struct Actor *,PtS *,u32);
extern void func_0204B404(struct Obj *,const PtS *,u32);
extern int func_021BA720(u32 base, u32 i, u32 space, int y);
void func_021BA6BC(char *p,int y);
void func_021BA6E8(u32 p, int sel, u32 y);

void func_021BA6BC(char *p,int y){PtS pos;void *o=((struct Obj03959 *)p)->f240;func_0204B454(o,&pos,65535);pos.y=y;func_0204B404(o,&pos,65535);}

void func_021BA6E8(u32 p, int sel, u32 y)
{
    u32 base;
    u32 space;
    int i;
    int n;
    if (sel) {
        space = 0;
        base = p + 0x294;
        n = 7;
    } else {
        space = 1;
        base = p + 0x2B0;
        n = 7;
    }
    for (i = 0; i < n; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}
