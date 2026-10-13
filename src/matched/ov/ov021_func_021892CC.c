/*
 * function: FIELDMAP_UpdateZoneChange
 * address:  0x021892CC
 * packet:   pkt_ov021_021892CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_CheckPlayerMoved  0x0218932C  thumb
 *   FIELDMAP_CheckZoneBoundary  0x02189370  thumb
 *   FIELDMAP_ChangeZone  0x021893C0  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_IsEncountDataLoaded  0x02162458  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   EVENTDATA_SYSTEM_LoadEncountData  0x02162438  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09443.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int FIELDMAP_CheckPlayerMoved(char *p);
extern u32 FIELDMAP_CheckZoneBoundary(char *p);
extern void FIELDMAP_ChangeZone(u8 *p);
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 EVENTDATA_SYSTEM_IsEncountDataLoaded(u8 *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void EVENTDATA_SYSTEM_LoadEncountData(int a0, int a1, int a2);

u32 FIELDMAP_UpdateZoneChange(u8 *a)
{
    u32 h;

    if (FIELDMAP_CheckPlayerMoved((char *)a) == 1 && FIELDMAP_CheckZoneBoundary((char *)a) == 1) {
        FIELDMAP_ChangeZone(a);
        return 1;
    }
    h = GAME_DATA_GetEventData((const struct BigObj *)(((struct Obj09443 *)a)->f8));
    if (EVENTDATA_SYSTEM_IsEncountDataLoaded((u8 *)h) == 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        EVENTDATA_SYSTEM_LoadEncountData(h, ((struct Obj09443 *)a)->fD8, GAME_DATA_GetSeason((const struct BigObj *)(((struct Obj09443 *)a)->f8)));
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    return 0;
}
