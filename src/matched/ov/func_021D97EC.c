/*
 * function: BTL_TOKUSEI_WeatherLock_ClearWeather
 * address:  0x021D97EC
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_TOKUSEI_WeatherLock_ClearWeather   0x021D97EC  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Shape F1's long-bodied sibling: gate on BTL_EVENT_GetVar(2), then build the
 * record via func_021C88A4, set flag bit 22, and hand it to func_021C8838
 * and func_021C88C8.
 */
#include "../include/Obj09219.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C88C8(void *b, void *p);

void BTL_TOKUSEI_WeatherLock_ClearWeather(void *a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) {
        u8 *p = func_021C88A4(b, 0x1d, c);
        ((struct Obj09219 *)p)->f0 |= 2 << 22;
        ((struct Obj09219 *)p)->f4 = 0;
        ((struct Obj09219 *)p)->f6 = 1;
        func_021C8838(p + 8, 1, 0x5e);
        func_021C88C8(b, p);
    }
}
