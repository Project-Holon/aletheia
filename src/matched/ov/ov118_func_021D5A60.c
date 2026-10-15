/*
 * function: POKETRADE_DEMO_DOWN_StepSetup
 * address:  0x021D5A60
 * packet:   pkt_ov118_021D5A60
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   POKETRADE_3D_InitParticleSystems  0x021E2F34  thumb
 *   POKETRADE_3D_CreateIcaStreamsForMode  0x021E2D70  thumb
 *   POKETRADE_3D_SetupParticleSystemsLow  0x021E2FB0  thumb ov119
 *   POKETRADE_DEMO_UP_SetFrame  0x021D56E4  thumb
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb
 *   POKETRADE_DEMO_DOWN_StepSetupParticles  0x021D5B74  thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   d_021D82A4  0x021D82A4  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13878.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void POKETRADE_PROC_DeleteAllResources(void *p);
extern void CLACT_ExitSystem(void);
extern void POKETRADE_2D_InitClactSystemMain(void *p);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_2D_SetupSummaryBgs(void *p, int a);
extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);
extern void MCSS_SetVanishFlag(void *p);
extern void POKETRADE_3D_InitParticleSystems(void *w);
extern void POKETRADE_3D_CreateIcaStreamsForMode(void *w, int a);
extern void POKETRADE_3D_SetupParticleSystemsLow(char *p);
extern void POKETRADE_DEMO_UP_SetFrame(u8 *p, u32 v);
extern void POKETRADE_NEGO_PlaySeByKeyA(u32 a);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_DEMO_DOWN_StepSetupParticles(u8 *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern const char d_021D82A4[];

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))

void POKETRADE_DEMO_DOWN_StepSetup(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources(p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(p);
    ((struct Obj13878 *)p)->f9C4 = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D82A4, 0xA8);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 5);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_SetVanishFlag((void *)OBJ(0));
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitParticleSystems(WORK);
    POKETRADE_3D_CreateIcaStreamsForMode(WORK, 3);
    POKETRADE_3D_SetupParticleSystemsLow((char *)WORK);
    POKETRADE_DEMO_UP_SetFrame(p, 0x2B5);
    POKETRADE_NEGO_PlaySeByKeyA(((struct Obj13878 *)p)->fF2C);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepSetupParticles);
    BG_SYS_SetSubVisiblePlanes(0x18);
}
