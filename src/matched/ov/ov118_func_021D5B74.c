/*
 * function: POKETRADE_DEMO_DOWN_StepSetupParticles
 * address:  0x021D5B74
 * packet:   pkt_ov118_021D5B74
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_3D_SetupParticleSystemsHigh  0x021E3004  thumb  ov119
 *   POKETRADE_DEMO_DOWN_StepPlaySe  0x021D5B98  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13879.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
extern void POKETRADE_3D_SetupParticleSystemsHigh(char *p);
extern void POKETRADE_DEMO_DOWN_StepPlaySe(u8 *p);

void POKETRADE_DEMO_DOWN_StepSetupParticles(u8 *p)
{
    POKETRADE_NEGO_PlaySeByKeyA(((struct Obj13879 *)p)->fF2C);
    POKETRADE_3D_SetupParticleSystemsHigh(((struct Obj13879 *)p)->fC);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepPlaySe);
}
