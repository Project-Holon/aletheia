/*
 * function: func_021DBC68
 * address:  0x021DBC68
 * packet:   pkt_021DBC68
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DBCA8   0x021DBCA8  thumb
 *   func_021DCEE4   0x021DCEE4  thumb
 *   func_021DCDD8   0x021DCDD8  thumb
 *   func_021DC8EC   0x021DC8EC  thumb
 *   func_021FD73C   0x021FD73C  thumb
 *
 * Flush the object, dispatch on the p+0xB0 flag, then chain to 0x21FD73C.
 */
#include "../../../matched/include/Obj00730.h"


extern void func_021DBCA8(int *task, int *state, char *p);
extern void func_021DCEE4(char *p, char *q);
extern void func_021DCDD8(char *p, char *q);
extern void func_021DC8EC(char *p, char *q);
extern void func_021FD73C(int, void *);

void func_021DBC68(int a, int b, char *p)
{
    func_021DCEE4(p, (char *)(((struct Obj00730 *)p)->fD0));
    if (((struct Obj00730 *)p)->fB0 != 0)
        func_021DCDD8(p, (char *)(((struct Obj00730 *)p)->fD0));
    else
        func_021DC8EC(p, (char *)(((struct Obj00730 *)p)->fD0));
    func_021FD73C(a, func_021DBCA8);
}
