/*
 * file:     wf2dmap_objdraw_p05.c
 * unit:     yes
 * function: func_021C5944, func_021C5994
 * address:  0x021C5944
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
 *   func_021C4280 0x021C4280 thumb ov127
 *   func_021C4270 0x021C4270 thumb ov127
 *   func_021C42A8 0x021C42A8 thumb ov127
 *   func_021C4274 0x021C4274 thumb ov127
 *   d_021C60AC 0x021C60AC data a1
 *   func_021C4ADC 0x021C4ADC thumb ov127
 *   func_021C59DC 0x021C59DC thumb ov127
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj00328.h"

struct obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef struct { s16 x, y; } Pos;

extern int func_021C4280(char *p);
extern u32 func_021C4270(char *p);
extern void func_021C42A8(struct obj *p, int idx, int a);
extern void func_021C4274(char *p, u32 a);
extern Pos func_021C4ADC(void *);
extern void func_021C59DC(s16 *p, s16 a, s16 b);
extern void func_02082BCC(void *, int, int);
void func_021C5944(u8 *p, int n, int a);
void func_021C5994(void *p, void *q);
void func_021C59D0(void *p);
extern u8 d_021C60AC[];

void func_021C5944(u8 *p, int n, int a)
{
    int v = func_021C4280(((struct Obj00328 *)p)->f4);
    u16 old = func_021C4270(((struct Obj00328 *)p)->f4);
    func_021C42A8(((struct Obj00328 *)p)->f4, n, a);
    if (old != n) {
        if (d_021C60AC[n] == 1 && ((struct Obj00328 *)p)->f10 == n)
            func_021C4274(((struct Obj00328 *)p)->f4, ((struct Obj00328 *)p)->fE);
        if (d_021C60AC[old] == 1) {
            ((struct Obj00328 *)p)->f10 = old;
            ((struct Obj00328 *)p)->fE = v;
        }
    }
}

void func_021C5994(void *p, void *q)
{
    Pos v = func_021C4ADC(q);
    func_021C59DC(p, v.y - 96, v.x - 112);
}

void func_021C59D0(void *p) { func_02082BCC(p, 0, 4); }
