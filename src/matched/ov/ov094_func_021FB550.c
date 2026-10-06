/*
 * function: func_021FB550
 * address:  0x021FB550
 * packet:   pkt_ov094_021FB550
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: func_0204047C(3, arg) and sets flag bit 4.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0204047C 0x0204047C arm
 */
#include "../include/Obj13587.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void func_0204047C(int idx, unsigned short val);

int func_021FB550(void *a, char *s)
{
    func_0204047C(3, (unsigned char)func_0201134C(a));
    ((struct Obj13587 *)s)->f0 |= 0x10;
    return ((struct Obj13587 *)s)->f23C;
}
