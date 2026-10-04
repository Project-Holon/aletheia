/*
 * function: func_021D49C4
 * address:  0x021D49C4
 * packet:   pkt_ov117_021D49C4
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4434  0x021D4434  thumb  ov117
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *
 * Same body as ov118 func_021D6C78 (third copy of this module); the first
 * callee is this overlay's own copy at 0x021D4434.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01722.h"

extern void func_021D4434(void *);
extern void func_021E3034(void *, int);
extern void func_021E2F2C(void *);
extern void func_020307B0(void *);
extern void func_021D8E84(void *, int);
extern void func_021DFDA0(void *p);

void func_021D49C4(void *p)
{
    func_021D4434(p);
    func_021E3034(((struct Obj01722 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01722 *)p)->fC);
    func_020307B0(((struct Obj01722 *)p)->fC);
    ((struct Obj01722 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}
