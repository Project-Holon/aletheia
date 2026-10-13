/*
 * function: HAND_TOKUSEI_ForecastOnWeatherChange
 * address:  0x021D9FC4
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_ForecastOnWeatherChange   0x021D9FC4  thumb ov093
 *   HAND_COMMON_IsMoveTarget   0x021E85F8  thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk   0x021C83D4  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_POKEPARAM_HasType   0x021D5814  thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord   0x021C88B4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTLV_CORE_PackByteTwice   0x021E8CF0  thumb ov093
 *
 * Four gates before the body (HAND_COMMON_IsMoveTarget(c) non-zero, BTL_SERVER_FLOW_CheckShowdownThunk(b)
 * zero, record valid, and the (u8) of BTL_EVENT_GetVar(0x16) neither 0x11 nor
 * rejected by BTL_POKEPARAM_HasType), then the 2-event, record, 3-event sequence of
 * HAND_TOKUSEI_CureSick with the halfword from BTLV_CORE_PackByteTwice in the record.
 */
#include "../include/Obj12144.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int HAND_COMMON_IsMoveTarget(int c);
int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
int BTL_POKEPARAM_IsFainted(void *p);
int BTL_EVENT_GetVar(int a);
int BTL_POKEPARAM_HasType(void *p, int k);
void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
int BTLV_CORE_PackByteTwice(int k);

void HAND_TOKUSEI_ForecastOnWeatherChange(void *a, int b, int c)
{
    void *r, *p;
    u8 k;

    if (HAND_COMMON_IsMoveTarget(c) == 0)
        return;
    if (BTL_SERVER_FLOW_CheckShowdownThunk((u8 *)b) != 0)
        return;
    r = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
    if (BTL_POKEPARAM_IsFainted(r) != 0)
        return;
    k = (u8)BTL_EVENT_GetVar(0x16);
    if (k == 0x11)
        return;
    if (BTL_POKEPARAM_HasType(r, k) != 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 2, c);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x14, c);
    ((struct Obj12144 *)p)->f4 = BTLV_CORE_PackByteTwice(k);
    ((struct Obj12144 *)p)->f6 = c;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 3, c);
}
