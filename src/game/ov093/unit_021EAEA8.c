/*
 * file:     unit_021EAEA8.c
 * unit:     yes
 * function: func_021EAEA8, func_021EAECC
 * address:  0x021EAEA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689B780  0x0689B780  thumb  ov095
 */
#include "../../matched/include/Obj07848.h"
#include "../../matched/include/Obj07849.h"

typedef unsigned char u8;

extern void func_0689B780(void *, void *);
void func_021EAEA8(u8 *p, int v);
void func_021EAECC(u8 *p, int v, int w);

void func_021EAEA8(u8 *p, int v)
{
    ((struct Obj07848 *)p)->f160 = v;
    ((struct Obj07848 *)p)->f164 = v;
    ((struct Obj07848 *)p)->f16C = 3;
    func_0689B780(((struct Obj07848 *)p)->f180, p + 0x160);
}

void func_021EAECC(u8 *p, int v, int w)
{
    ((struct Obj07849 *)p)->f160 = v;
    ((struct Obj07849 *)p)->f164 = v;
    ((struct Obj07849 *)p)->f16C = w;
    func_0689B780(((struct Obj07849 *)p)->f180, p + 0x160);
}
