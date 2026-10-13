/*
 * function: GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight
 * address:  0x021F45F0
 * packet:   pkt_ov048_021F45F0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   GIMMICK_OBJ_ELBOARD_ClearHighlights  0x021F44B8  thumb  ov048
 *   MOVE_POKEMON_HasActiveEntry  0x0215E404  thumb  ov010
 *   MOVE_POKEMON_GetEntryZoneId  0x0215E3E4  thumb  ov010
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 */
#include "../include/Obj13107.h"

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200D418(void *sys);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GIMMICK_OBJ_ELBOARD_ClearHighlights(u8 *p);
extern int MOVE_POKEMON_HasActiveEntry(int a);
extern u32 GPOWER_GetSpecialPowerId(void);
extern u32 MOVE_POKEMON_GetEntryZoneId(void *p, u32 slot);

void GIMMICK_OBJ_ELBOARD_CollectGPowerHighlight(int *a, void *b)
{
    int r7;
    int r4;
    int r6;
    int r0;

    r7 = (int)func_0200D418(GAME_DATA_GetSaveControl((struct Big *)a[2]));
    GIMMICK_OBJ_ELBOARD_ClearHighlights(b);
    if (MOVE_POKEMON_HasActiveEntry(r7)) {
        r0 = GPOWER_GetSpecialPowerId();
        switch (r0) {
        case 0x14:
            r4 = 0;
            break;
        case 0x15:
            r4 = 1;
            break;
        }
        switch (r4) {
        case 0:
            r6 = 6;
            break;
        case 1:
            r6 = 7;
            break;
        }
        r0 = (int)MOVE_POKEMON_GetEntryZoneId((void *)r7, (unsigned char)r4);
        if (r0 != 0xFFFF) {
            ((struct Obj13107 *)b)->f0 = r0;
            *((unsigned char *)b + 8) = r6;
        }
    }
}
