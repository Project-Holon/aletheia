/*
 * function: GURU2_MAIN_StateComputeReward
 * address: 0x021DF4AC
 * packet: pkt_ov137_021DF4AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Mutable range table is reloaded after RNG; updating low in place preserves r4/r5 colouring.
 * symbols:
 *   GURU2_MAIN_AddPulseEffectsForMask 0x021E14E4 thumb ov137
 *   GURU2_MAIN_PrintMessageWithNumber 0x021E026C thumb ov137
 *   GURU2_MAIN_PushAndPlayBgm 0x021E1988 thumb ov137
 *   func_020056EC 0x020056EC thumb
 *   GAME_DATA_GetMyItem 0x0201292C thumb
 *   func_02007E50 0x02007E50 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   gGuru2RewardRangeTable 0x021E1F34 data a4
 */
#include "../include/Obj05430.h"
#include "../include/Obj23759.h"
#include "../include/Obj23760.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Range { u32 low, high; };
extern struct Range gGuru2RewardRangeTable[];
extern void GURU2_MAIN_AddPulseEffectsForMask(const char *p);
struct BigObj;
extern void GURU2_MAIN_PrintMessageWithNumber(u8 *p, int message, unsigned value);
extern void GURU2_MAIN_PushAndPlayBgm(unsigned int n);
extern u32 func_020056EC(u32);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 func_02007E50(u8 *, u16, u16, u16);
int GURU2_MAIN_StateComputeReward(u8 *p)
{
    u32 low, high, value;
    int count;
    GURU2_MAIN_AddPulseEffectsForMask((const char *)p);
    if ((((struct Obj05430 *)p)->f1C & (1 << (*(int **)(p + 40))[3])) == 0) {
        ((struct Obj05430 *)p)->f0 = 42;
        return 0;
    }
    count = ((struct Obj05430 *)p)->f30;
    low = gGuru2RewardRangeTable[count].low;
    high = gGuru2RewardRangeTable[count].high;
    low += func_020056EC(65535) % (high - low + 1);
    if (low < gGuru2RewardRangeTable[count].low) low = gGuru2RewardRangeTable[count].low;
    else if (low > high) low = high;
    GURU2_MAIN_PrintMessageWithNumber(p, 3, low);
    value = func_02007E50(GAME_DATA_GetMyItem((((struct Obj23760 *)(*(u8 * *)&((struct Obj23759 *)(*(u8 * *)&((struct Obj05430 *)p)->fD8))->f14))->f4)), low, 1, 114);
    GURU2_MAIN_PushAndPlayBgm(1302);
    if (value == 1) ((struct Obj05430 *)p)->f0 = 39;
    else ((struct Obj05430 *)p)->f0 = 40;
    return 0;
}
