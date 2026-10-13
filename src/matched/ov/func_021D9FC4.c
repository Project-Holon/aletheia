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
 *   func_021E85F8   0x021E85F8  thumb ov093
 *   func_021C83D4   0x021C83D4  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_POKEPARAM_HasType   0x021D5814  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   BTLV_CORE_PackByteTwice   0x021E8CF0  thumb ov093
 *
 * Four gates before the body (func_021E85F8(c) non-zero, func_021C83D4(b)
 * zero, record valid, and the (u8) of BTL_EVENT_GetVar(0x16) neither 0x11 nor
 * rejected by BTL_POKEPARAM_HasType), then the 2-event, record, 3-event sequence of
 * BTL_TOKUSEI_CureSick with the halfword from BTLV_CORE_PackByteTwice in the record.
 */
#include "../include/Obj12144.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021E85F8(int c);
int func_021C83D4(u8 *p);
void *func_021C7CF4(int *p, int i);
int BTL_POKEPARAM_IsFainted(void *p);
int BTL_EVENT_GetVar(int a);
int BTL_POKEPARAM_HasType(void *p, int k);
void func_021C88B4(void *a, int k, int b);
void *func_021C88A4(char *p, int a, int b);
void func_021C88C8(void *a, void *b);
int BTLV_CORE_PackByteTwice(int k);

void HAND_TOKUSEI_ForecastOnWeatherChange(void *a, int b, int c)
{
    void *r, *p;
    u8 k;

    if (func_021E85F8(c) == 0)
        return;
    if (func_021C83D4((u8 *)b) != 0)
        return;
    r = func_021C7CF4((int *)b, c);
    if (BTL_POKEPARAM_IsFainted(r) != 0)
        return;
    k = (u8)BTL_EVENT_GetVar(0x16);
    if (k == 0x11)
        return;
    if (BTL_POKEPARAM_HasType(r, k) != 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 0x14, c);
    ((struct Obj12144 *)p)->f4 = BTLV_CORE_PackByteTwice(k);
    ((struct Obj12144 *)p)->f6 = c;
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}
