/*
 * function: func_021D49C4
 * address:  0x021D49C4
 * packet:   pkt_ov118_021D49C4
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_COMMON_ReleaseUnit  0x021D4434  thumb  ov118
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *
 * Same body as ov118 POKETRADE_DEMO_MIDDLE_StepEndScene (third copy of this module); the first
 * callee is this overlay's own copy at 0x021D4434.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01723.h"

extern void POKETRADE_DEMO_COMMON_ReleaseUnit(void *);
typedef unsigned int   u32;
extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);
extern void POKETRADE_3D_FreeParticleResources(void *);
extern u32 func_020307B0(void *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);

void func_021D49C4(void *p)
{
    POKETRADE_DEMO_COMMON_ReleaseUnit(p);
    POKETRADE_3D_ExitParticleManager(((struct Obj01723 *)p)->fC, 6);
    POKETRADE_3D_FreeParticleResources(((struct Obj01723 *)p)->fC);
    func_020307B0(((struct Obj01723 *)p)->fC);
    ((struct Obj01723 *)p)->fC = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}
