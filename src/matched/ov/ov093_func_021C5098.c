/*
 * function: BTL_SERVER_FLOW_GetHighestOpponentLevel
 * address:  0x021C5098
 * packet:   pkt_ov093_021C5098
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_MAIN_IsSameTeamClient  0x021B902C  thumb  ov093
 *   func_021C50F8  0x021C50F8  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 */
#include "../include/Obj07755.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern unsigned int BTL_MAIN_GetRuleSlotSpan(unsigned int **p);
extern u8 BTL_MAIN_GetOwnClientId(u8 *m);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern int BTL_MAIN_IsSameTeamClient(int a, int b);
extern u8 func_021C50F8(u8 *q, u8 i);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);

u32 BTL_SERVER_FLOW_GetHighestOpponentLevel(u8 *p)
{
    u32 best = 1;
    u32 n = BTL_MAIN_GetRuleSlotSpan((unsigned int **)(*(u8 * *)&((struct Obj07755 *)p)->f4));
    u8 x = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj07755 *)p)->f4);
    u32 i;
    for (i = 0; i <= n; i++) {
        if (BTL_MAIN_IsSameTeamClient(x, BTL_MAIN_GetSlotClientIdThunk((char *)(*(u8 * *)&((struct Obj07755 *)p)->f4), (u8)i)) == 0) {
            int r = func_021C50F8(p + 0x1AB8, i);
            if (r != 0x1f) {
                u32 t = BTL_POKEPARAM_GetValue((u8 *)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj07755 *)p)->f8, r), 0xf);
                if (t > best) {
                    best = t;
                }
            }
        }
    }
    return best;
}
