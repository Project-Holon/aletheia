/*
 * unit:     yes
 * function: func_020051D8, func_02005204
 * address:  0x020051D8
 * packet:   pkt_020051D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020392B8  0x020392B8  arm
 *   func_0203D26C  0x0203D26C  arm
 *   func_0203D29C  0x0203D29C  arm
 *   sub_02005610   0x02005610  thumb
 *
 * Boot path, 0x020051D8..0x0200520C: a three-step readiness test (each
 * step its own early `return 0`, per the image's four epilogues) and the
 * unlabelled forwarding thunk func_02005204 to sub_02005610
 * (src/matched/unit_0200560C.c), a pool-word tail call.
 *
 * Rewritten wave 16 from src/pending/func_020051D8.c, a one-line generated
 * body with implicit declarations that was EXACT* on its own.
 * Integrator: seed 0x02005204 (unlabelled follower, member of this unit).
 */

extern int func_020392B8(void);
typedef unsigned int   u32;
extern u32 func_0203D26C(void);
extern u32 func_0203D29C(void);
extern void sub_02005610(void);

int func_020051D8(void)
{
    if (func_020392B8() > 1)
        return 0;
    if (func_0203D26C() != 0)
        return 0;
    if (func_0203D29C() == 0)
        return 1;
    return 0;
}

void func_02005204(void)
{
    sub_02005610();
}
