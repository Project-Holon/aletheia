/*
 * function: ISS_CITY_SYS_CalcUnitVolume
 * address:  0x0202AE9C
 * packet:   pkt_0202AE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: call target ISS_CITY_UNIT_CalcVolume is unlabelled and unmatched (it lives in
 * another lane's packet, pkt_0202AF34). Every concrete byte reproduces.
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_GetCurrentUnit  0x0202AD78  thumb
 *   ISS_CITY_UNIT_CalcVolume  0x0202AF34  thumb
 */
#include "../include/Obj15818.h"

typedef unsigned int u32;

extern int ISS_CITY_SYS_GetCurrentUnit(int a0);
struct Rec44;
struct Vec12;
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void ISS_CITY_UNIT_CalcVolume(int a, u32 b);

void ISS_CITY_SYS_CalcUnitVolume(void *p)
{
    int a = ISS_CITY_SYS_GetCurrentUnit((int)p);

    ISS_CITY_UNIT_CalcVolume(a, (u32)func_02012AA0((struct Rec44 *)(((struct Obj15818 *)p)->f0)));
}
