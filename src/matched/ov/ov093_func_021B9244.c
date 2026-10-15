/*
 * function: BTL_MAIN_CalcPenaltyMoney
 * address:  0x021B9244
 * packet:   pkt_ov093_021B9244
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetPoints  0x0200C274  thumb
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_CALC_CalcDefeatMoneyLoss  0x021D7FF8  thumb  ov093
 */
#include "../include/Obj04354.h"
#include "../include/Obj20982.h"
#include "../include/Obj20983.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Blk34;
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_GetPoints(struct Blk34 *p);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
extern u32 BTL_CALC_CalcDefeatMoneyLoss(u32 a, void *b);

u32 BTL_MAIN_CalcPenaltyMoney(char *p)
{
    u32 r;
    u32 m;
    u32 c;

    r = 0;
    if (((u32)((struct Obj04354 *)p)->f473 << 27 >> 31) == 0) {
        if (**(u32 * *)&((struct Obj04354 *)p)->f0 <= 1) {
            m = BEACON_GetPoints(GAME_DATA_GetMiscSave(((struct Obj20982 *)(*(char * *)&((struct Obj04354 *)p)->f0))->f58));
            c = BTL_CALC_CalcDefeatMoneyLoss(((struct Obj20983 *)(*(char * *)&((struct Obj04354 *)p)->f0))->f80, BTL_SIDE_GetSlotOfClientThunk(p + 0x1b0, ((struct Obj04354 *)p)->f46C));
            if (c > m)
                c = m;
            r = c;
            ((struct Obj04354 *)p)->f438 = r;
        }
        ((struct Obj04354 *)p)->f473 |= 0x10;
    }
    return r;
}
