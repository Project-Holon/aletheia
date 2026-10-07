/*
 * file:     zukan_detail_graphic_p08.c
 * unit:     yes
 * function: func_021BD538, func_021BD56C
 * address:  0x021BD538
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj05865.h"

typedef unsigned int   u32;

extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02082BCC(int, int, int);
void func_021BD538(char *p);
int func_021BD56C(int *p, int i);


/*
 * Releases +8, +4 and +0, passes the pair at +0x10 on and clears the 0x14-byte object.
 */
void func_021BD538(char *p)
{
    unsigned int w;

    func_0204AFD8(((struct Obj05865 *)p)->f8);
    func_0204A8D4(((struct Obj05865 *)p)->f4);
    func_0204ADA4(((struct Obj05865 *)p)->f0);
    w = ((struct Obj05865 *)p)->f10;
    func_0203FB44(((struct Obj05865 *)p)->fC, (unsigned short)w, (unsigned short)(w >> 16));
    func_02082BCC((int)p, 0, 0x14);
}

int func_021BD56C(int *p, int i)
{
    return p[i];
}
