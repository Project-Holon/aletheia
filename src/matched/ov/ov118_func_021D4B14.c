/*
 * function: func_021D4B14
 * address:  0x021D4B14
 * packet:   pkt_ov118_021D4B14
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
 *   POKETRADE_3D_SetupParticleSystemsLow  0x021E2FB0  thumb ov119
 *   POKETRADE_3D_CreateIcaStreamsForMode  0x021E2D70  thumb
 *   POKETRADE_DEMO_COMMON_SetFrame  0x021D4484  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb
 *   func_021D4C08  0x021D4C08  thumb
 *   d_021D7FD4  0x021D7FD4  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22662.h"

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
extern void POKETRADE_3D_SetupParticleSystemsLow(char *p);
extern void POKETRADE_3D_CreateIcaStreamsForMode(void *w, int a);
extern void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void func_021D4C08(u8 *p);
extern const char d_021D7FD4[];

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))

void func_021D4B14(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources(p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(p);
    ((struct Obj22662 *)p)->f9C4 = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D7FD4, 0x98);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 3);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitParticleSystems(WORK);
    POKETRADE_3D_SetupParticleSystemsLow((char *)WORK);
    POKETRADE_3D_CreateIcaStreamsForMode(WORK, 1);
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)func_021D4C08);
}
