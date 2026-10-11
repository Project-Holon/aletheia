/*
 * file:     unit_0689B558.c
 * function: func_0689B558
 * address: 0x0689B558
 * packet: pkt_ov095_0689B558
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing 0689B572..0689B574 is Thumb alignment padding.
 * symbols:
 *   func_021F81EC  0x021F81EC  thumb
 *   func_021F8A78  0x021F8A78  thumb
 *   func_0220270C  0x0220270C  thumb
 */
#include "../../matched/include/Obj21898.h"
extern void func_0220270C(void *, int, int);
extern int func_021F81EC(int);
extern void func_021F8A78(int);
void func_0689B558(void *p)
{
    func_0220270C(((struct Obj21898 *)p)->fB0, 0, 0);
    func_021F8A78(func_021F81EC(8));
}
