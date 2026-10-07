/*
 * file:     shinka_demo_view_p13.c
 * unit:     yes
 * function: func_022083DC, func_022083EC, func_02208410
 * address:  0x022083DC
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022081A4 0x022081A4 thumb ov195
 */
#include "../../matched/include/Obj24977.h"
#include "../../matched/include/Obj24978.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct Fade {
    u8 f00[0x28];
    int state;
    u16 pal[16];
    u16 color;
    s16 cur;
    s16 end;
    s16 wait;
    s16 step;
    s16 level;
    s16 count;
} Fade;

extern void func_022081A4(Fade *p, int x, u16 color, s16 cur, s16 end, s16 wait, s16 step);
int func_022083DC(char *p, u16 heap);
void func_022083EC(Fade *p, int x);
int func_02208410(char *p, u16 heap);


int func_022083DC(char *p, u16 heap)
{
    return ((struct Obj24977 *)p)->f28 == 1;
}


void func_022083EC(Fade *p, int x)
{
    p->state = 2;
    func_022081A4(p, x, 0x7fff, 0, 31, 0, 1);
}


int func_02208410(char *p, u16 heap)
{
    return ((struct Obj24978 *)p)->f28 == 3;
}
