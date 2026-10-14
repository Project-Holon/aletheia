/*
 * function: func_021D4C08
 * address:  0x021D4C08
 * packet:   pkt_ov118_021D4C08
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_3D_SetupParticleSystemsHigh  0x021E3004  thumb  ov119
 *   func_021D4C20  0x021D4C20  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22663.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_3D_SetupParticleSystemsHigh(char *p);
extern void func_021D4C20(u8 *p);

void func_021D4C08(u8 *p)
{
    POKETRADE_3D_SetupParticleSystemsHigh(((struct Obj22663 *)p)->fC);
    POKETRADE_PROC_SetStep(p, (int)func_021D4C20);
}
