/*
 * function: ISS_CITY_SYS_Enable
 * address:  0x0202AC00
 * packet:   pkt_0202AC00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_CITY_SYS_SetMode  0x0202ABFC  thumb
 *   ISS_CITY_SYS_GetPlayerZoneId  0x0202ACBC  thumb
 *   ISS_CITY_SYS_IsEnabled  0x0202ACC8  thumb
 *   ISS_CITY_SYS_HasCurrentUnit  0x0202AD8C  thumb
 *   ISS_CITY_SYS_SelectUnitForZone  0x0202ADB4  thumb
 *   ISS_CITY_SYS_SetVolume  0x0202AEB8  thumb
 *   ISS_CITY_SYS_ApplyVolume  0x0202AEBC  thumb
 */
#include "../include/Obj15813.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 ISS_CITY_SYS_IsEnabled(void *obj);
extern void ISS_CITY_SYS_SetVolume(void *obj, u32 value);
extern int ISS_CITY_SYS_ApplyVolume(int a0);
extern u32 ISS_CITY_SYS_GetPlayerZoneId(u32 *p);
extern int ISS_CITY_SYS_SelectUnitForZone(int a0, int a1);
extern int ISS_CITY_SYS_HasCurrentUnit(int a0);
extern void ISS_CITY_SYS_SetMode(void *obj, u32 value);

void ISS_CITY_SYS_Enable(u8 *p)
{
    if (ISS_CITY_SYS_IsEnabled(p) != 0)
        return;

    ((struct Obj15813 *)p)->f4 = 1;
    ISS_CITY_SYS_SetVolume(p, 0);
    ISS_CITY_SYS_ApplyVolume((int)p);
    ISS_CITY_SYS_SelectUnitForZone((int)p, ISS_CITY_SYS_GetPlayerZoneId((u32 *)p));

    if (ISS_CITY_SYS_HasCurrentUnit((int)p) == 1)
        ISS_CITY_SYS_SetMode(p, 1);
    else
        ISS_CITY_SYS_SetMode(p, 0);
}
