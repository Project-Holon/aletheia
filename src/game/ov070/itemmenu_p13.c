/*
 * file:     itemmenu_p13.c
 * unit:     yes
 * function: func_021B9758, func_021B97CC
 * address:  0x021B9758
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 *   func_02040588 0x02040588 arm
 */
#include "../../matched/include/Obj06175.h"

typedef unsigned int   u32;

extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021B9758(char *p);
void func_021B97CC(void *p, int v);


void func_021B9758(char *p)
{
    unsigned v;
    v = ((struct Obj06175 *)p)->f7FC;
    func_0203FB44((int)4, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f800;
    func_0203FB44((int)5, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f808;
    func_0203FB44((int)3, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f7F8;
    func_0203FB44((int)0, (unsigned short)v, (unsigned short)(v >> 16));
    v = ((struct Obj06175 *)p)->f804;
    func_0203FB44((int)1, (unsigned short)v, (unsigned short)(v >> 16));
}

void func_021B97CC(void *p, int v) { func_02040588(5, v); func_02040588(6, v); }
