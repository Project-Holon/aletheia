/*
 * function: func_021D6C78
 * address:  0x021D6C78
 * packet:   pkt_021D6C78
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D66E8  0x021D66E8  thumb  ov118
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *
 * EXACT (48 bytes). Was MATCH-capped on three ov119 relocations: the calls
 * to func_021E3034 (0x021E3034) and func_021E2F2C (0x021E2F2C), and the
 * ABS32 func_021DFDA1 callback (0x021DFDA0 -> 0x021DFDA1). Matching the
 * ov119 targets bottom-up (func_021D66E8, func_021E3034, func_021DFDA0;
 * func_021E2F2C was already EXACT) and naming them with an explicit
 * `thumb ov119` (and `thumb ov118` for func_021D66E8) moves the two
 * callback sites from sole-ref to `matched` and the two calls to `label`.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01725.h"

extern void func_021D66E8(void *);
extern void func_021E3034(void *, int);
extern void func_021E2F2C(void *);
extern void func_020307B0(void *);
extern void func_021D8E84(void *, int);
extern void func_021DFDA0(void *p);

void func_021D6C78(void *p)
{
    func_021D66E8(p);
    func_021E3034(((struct Obj01725 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01725 *)p)->fC);
    func_020307B0(((struct Obj01725 *)p)->fC);
    ((struct Obj01725 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}
