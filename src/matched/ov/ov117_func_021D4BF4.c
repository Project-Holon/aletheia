/*
 * function: func_021D4BF4
 * address:  0x021D4BF4
 * packet:   pkt_ov117_021D4BF4
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC720  0x021DC720  thumb  ov119
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb  ov119
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   POKETRADE_3D_InitTradeParticleSet  0x021E3070  thumb  ov119
 *   POKETRADE_3D_CreateIcaStreamsEnding  0x021E2EFC  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov117
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   func_021D4CE8  0x021D4CE8  thumb  ov117
 *   d_021D55CC     0x021D55CC  data
 *
 * Addresses are Black-image addresses.
 *
 * The call to 0x021E3E40 (ov119 tail-call wrapper to 0x0204A48C) attests
 * through src/matched/ov119_func_021E3E40.c, seeded in function_starts.txt.
 */
#include "../include/Obj02829.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021DC720(char *p);
extern void CLACT_ExitSystem(void);
extern void POKETRADE_2D_InitClactSystemMain(char *p);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_2D_SetupSummaryBgs(char *p, int mode);
extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetVanishFlag(void *p);
extern void POKETRADE_3D_InitTradeParticleSet(void *w);
extern void POKETRADE_3D_CreateIcaStreamsEnding(char *p);
extern void func_021D4484(u8 *p, u32 v);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void func_021D4CE8(u8 *p);
extern const char d_021D55CC[];

#define HEAP (*(u16 *)(p + 0x5F4))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define WORK (*(u8 **)(p + 0xc))

void func_021D4BF4(u8 *p)
{
    func_021DC720((char *)p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain((char *)p);
    ((struct Obj02829 *)p)->f9C4 = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D55CC, 0x65);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs((char *)p, 1);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 2);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_GetScale((void *)OBJ(3), (u32 *)(WORK + 0x54));
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitTradeParticleSet(WORK);
    POKETRADE_3D_CreateIcaStreamsEnding((char *)WORK);
    func_021D4484(p, 0);
    POKETRADE_PROC_SetStep(p, (int)func_021D4CE8);
}
