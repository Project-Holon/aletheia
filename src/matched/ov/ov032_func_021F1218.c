/*
 * function: func_021F1218
 * address:  0x021F1218
 * packet:   pkt_ov032_021F1218
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F1218 0x021F1218 thumb
 *   func_021F0DE0 0x021F0DE0 thumb
 *   func_0202590C 0x0202590C thumb
 */
#include "../include/Obj00225.h"

extern void func_021F0DE0(void *, short, short);
typedef signed short   s16;
struct Grid;
extern void func_0202590C(struct Grid *g, s16 x, s16 y);

void func_021F1218(char *p, short x, short y)
{
    ((struct Obj00225 *)p)->f8 = x;
    ((struct Obj00225 *)p)->fA = y;
    func_021F0DE0(((struct Obj00225 *)p)->fC, x, y);
    func_021F0DE0(((struct Obj00225 *)p)->f10, x + 0x20, y + 0x18);
    func_021F0DE0(((struct Obj00225 *)p)->f14, x + 0x3c, y + 0x18);
    func_0202590C(((struct Obj00225 *)p)->f18, x + 0x48, y + 0x10);
}
