/*
 * function: func_021CDF58
 * address:  0x021CDF58
 * packet:   pkt_ov093_021CDF58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   BTL_CLIENT_StartTimeLimit  0x021CE068  thumb  ov093
 *   BTL_CLIENT_PollTimeLimitReady  0x021CE08C  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   BTL_CLIENT_PickWindowMode  0x021CDFE4  thumb  ov093
 *   BTL_CLIENT_StopTimeLimit  0x021CE0E0  thumb  ov093
 */
#include "../include/Obj01892.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021EAA00(u8 *p, u8 v);
extern void BTL_CLIENT_StartTimeLimit(u8 *p);
extern int BTL_CLIENT_PollTimeLimitReady(u8 *p);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern u32 BTL_CLIENT_PickWindowMode(u32 mode);
extern void BTL_CLIENT_StopTimeLimit(u8 *p);

int func_021CDF58(u8 *p, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(((struct Obj01892 *)p)->f54, p[0xc4]);
        BTL_CLIENT_StartTimeLimit(p);
        *st = *st + 1;
        break;
    case 1:
        if (BTL_CLIENT_PollTimeLimitReady(p) != 0) {
            func_021EAA5C(((struct Obj01892 *)p)->f54);
            *st = 2;
        } else if (func_021EAA34(((struct Obj01892 *)p)->f54, &buf) != 0) {
            p[0xc4] = buf;
            *st = 3;
        }
        break;
    case 2:
        p[0xc4] = BTL_CLIENT_PickWindowMode(p[0xc4]);
        *st = *st + 1;
        break;
    case 3:
        BTL_CLIENT_StopTimeLimit(p);
        *st = *st + 1;
        break;
    case 4:
        *(u8 * *)&((struct Obj01892 *)p)->fD8 = p + 0xc4;
        ((struct Obj01892 *)p)->fDC = 1;
        return 1;
    }
    return 0;
}
