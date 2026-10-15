/*
 * function: POKETRADE_DEMO_MIDDLE_StepEndScene
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
 *   POKETRADE_DEMO_DOWN_ReleaseUnit  0x021D66E8  thumb  ov118
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *
 * EXACT (48 bytes). Was MATCH-capped on three ov119 relocations: the calls
 * to POKETRADE_3D_ExitParticleManager (0x021E3034) and POKETRADE_3D_FreeParticleResources (0x021E2F2C), and the
 * ABS32 func_021DFDA1 callback (0x021DFDA0 -> 0x021DFDA1). Matching the
 * ov119 targets bottom-up (POKETRADE_DEMO_DOWN_ReleaseUnit, POKETRADE_3D_ExitParticleManager, POKETRADE_SAVE_ResetClactAndBeginEvent;
 * POKETRADE_3D_FreeParticleResources was already EXACT) and naming them with an explicit
 * `thumb ov119` (and `thumb ov118` for POKETRADE_DEMO_DOWN_ReleaseUnit) moves the two
 * callback sites from sole-ref to `matched` and the two calls to `label`.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01725.h"

extern void POKETRADE_DEMO_DOWN_ReleaseUnit(void *);
typedef unsigned int   u32;
extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);
extern void POKETRADE_3D_FreeParticleResources(void *);
extern u32 func_020307B0(void *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);

void POKETRADE_DEMO_MIDDLE_StepEndScene(void *p)
{
    POKETRADE_DEMO_DOWN_ReleaseUnit(p);
    POKETRADE_3D_ExitParticleManager(((struct Obj01725 *)p)->fC, 6);
    POKETRADE_3D_FreeParticleResources(((struct Obj01725 *)p)->fC);
    func_020307B0(((struct Obj01725 *)p)->fC);
    ((struct Obj01725 *)p)->fC = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}
