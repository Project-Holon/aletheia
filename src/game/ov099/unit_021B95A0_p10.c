/*
 * file:     unit_021B95A0_p10.c
 * unit:     yes
 * function: func_021B9FD0, func_021B9FDC
 * address:  0x021B9FD0
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
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 */
#include "../../matched/include/Obj22013.h"

struct Obj;
typedef unsigned short u16;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work;

typedef unsigned char  u8;

typedef unsigned int   u32;

extern void func_0204B3DC(struct Obj *, unsigned int);
extern Pos func_021C4AC4(void *v);
extern int func_021C49A4(u8 *p, unsigned int i);
extern u32 func_021C4864(u8 *p, u16 x, u16 y);
void func_021B9FD0(void *p);
int func_021B9FDC(Work *w);


/*
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x2c]; ldr r3,[pc,#4]; movs r1,#0; bx r3; .word 0x0204B3DC
 */
void func_021B9FD0(void *p)
{
    func_0204B3DC((struct Obj *)((struct Obj22013 *)p)->f2C, 0);
}


int func_021B9FDC(Work *w)
{
    Pos b;
    int n;

    if (w->f570 == 0)
        return 0;
    b = func_021C4AC4(*w->f570);
    n = func_021C49A4(*w->f570, 6);
    if (func_021C4864(w->f588, b.x / 16, b.y / 16) == 15 && n == 1)
        return 1;
    return 0;
}
