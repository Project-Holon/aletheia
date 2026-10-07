/*
 * file:     wf2dmap_objdraw_p04.c
 * unit:     yes
 * function: func_021C58F8, func_021C5914
 * address:  0x021C58F8
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
 *   func_021C4268  0x021C4268  thumb
 *   d_021C60B6     0x021C60B6  data  a1
 *   func_021C4ADC 0x021C4ADC thumb ov127
 */
#include "../../matched/include/Obj23055.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { short x,y; } Pos;

extern int func_021C4268(char *);
extern Pos func_021C4ADC(char *);
int func_021C58F8(char *p, int b);
void func_021C5914(char *p,short *x,short *y);
extern unsigned char d_021C60B6[];


/*
 * Addresses are Black-image addresses.
 */
int func_021C58F8(char *p, int b)
{
    if (func_021C4268(p) == 2)
        return 0;
    return d_021C60B6[b];
}

void func_021C5914(char *p,short *x,short *y) { Pos a=func_021C4ADC(*(char * *)&((struct Obj23055 *)p)->f0); *x=a.x; *y=a.y; }
