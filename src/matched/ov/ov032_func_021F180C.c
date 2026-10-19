/*
 * function: BEACON_VIEW_HandleRecordAction
 * address:  0x021F180C
 * packet:   pkt_ov032_021F180C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_HandleRecordAction 0x021F180C thumb
 *   GAME_BEACON_ACCESSOR_GetActionNo 0x02165E24 thumb ov010
 *   GAME_BEACON_ACCESSOR_RegisterRecordWords 0x02165FCC thumb ov010
 *   GAME_BEACON_SEARCH_SetPresetEvent 0x02165374 thumb ov010
 *   MISC_IncrementGreetCount 0x0200C1C8 thumb
 *   BEACON_VIEW_ShowFormatMessage 0x021F18C4 thumb
 *   BEACON_VIEW_HandlePowerRecord 0x021F199C thumb
 *   BEACON_VIEW_ShowRecordMessage 0x021F1888 thumb
 */
#include "../include/Obj00007.h"

typedef unsigned short u16;

extern int GAME_BEACON_ACCESSOR_GetActionNo(int a);
extern void GAME_BEACON_ACCESSOR_RegisterRecordWords(int a, int b, u16 c);
extern void GAME_BEACON_SEARCH_SetPresetEvent(unsigned a0);
typedef unsigned int   u32;
struct Blk34;
extern u32 MISC_IncrementGreetCount(struct Blk34 *p);
extern void BEACON_VIEW_ShowFormatMessage(char *this, int a);
extern int BEACON_VIEW_HandlePowerRecord(char *p, void *x, int flag);
extern void BEACON_VIEW_ShowRecordMessage(char *this, int a);

int BEACON_VIEW_HandleRecordAction(char *this, int x, int flag)
{
    int k;

    k = GAME_BEACON_ACCESSOR_GetActionNo(x);
    if (flag != 0) {
        GAME_BEACON_ACCESSOR_RegisterRecordWords(x, *(int *)&((struct Obj00007 *)this)->f110, ((struct Obj00007 *)this)->f96);
        BEACON_VIEW_ShowFormatMessage(this, 0x12);
        return 1;
    }
    switch (k) {
    case 1:
        return 0;
    case 0x12:
        return BEACON_VIEW_HandlePowerRecord(this, (void *)x, 0);
    case 0x32:
        return BEACON_VIEW_HandlePowerRecord(this, (void *)x, 1);
    case 0x18:
        GAME_BEACON_SEARCH_SetPresetEvent(MISC_IncrementGreetCount((struct Blk34 *)(((struct Obj00007 *)this)->f14)));
        break;
    }
    BEACON_VIEW_ShowRecordMessage(this, x);
    return 1;
}
