/*
 * file:     br_btn_p10.c
 * unit:     yes
 * function: func_021FB514, func_021FB548, func_021FB578
 * address:  0x021FB514
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0202590C 0x0202590C thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0204B800  0x0204B800  arm
 *   func_020259C4  0x020259C4  thumb
 */
#include "../../matched/include/Obj10786.h"
#include "../../matched/include/Obj14456.h"

struct Obj;
struct Grid;
struct Actor;
struct Node;
struct Vec2{short x,y;};

typedef unsigned int   u32;

struct PtS { short x,y; };

typedef unsigned short u16;

typedef unsigned char  u8;

extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0202590C(struct Grid *,short,short);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_020259C4(u8 *g, u32 a);
void func_021FB514(char *p, short x, int y);
void func_021FB548(char *p,short *x,short *y);
void func_021FB578(int *p, unsigned char b);

void func_021FB514(char *p, short x, int y) { struct Vec2 v;v.x=x;v.y=y;func_0204B404(*(struct Obj * *)&((struct Obj10786 *)p)->f0,&v,(unsigned short)(((struct Obj10786 *)p)->f10));func_0202590C(*(struct Grid * *)&((struct Obj10786 *)p)->f4,v.x+32,v.y-8); }

void func_021FB548(char *p,short *x,short *y) { struct PtS v;func_0204B454(*(struct Actor * *)&((struct Obj14456 *)p)->f0,&v,(unsigned short)((struct Obj14456 *)p)->f10);if(x)*x=v.x;if(y)*y=v.y; }


void func_021FB578(int *p, unsigned char b)
{
    func_0204B800((struct Node *)p[0], b);
    func_020259C4((u8 *)p[1], (unsigned char)(b - 1));
}
