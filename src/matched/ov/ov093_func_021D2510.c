/*
 * function: BTL_CLIENT_StepEndWeather
 * address:  0x021D2510
 * packet:   pkt_ov093_021D2510
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CORE_PrintSideMessage  0x021EA678  thumb  ov093
 *   BTLV_CORE_WaitMessage  0x021EA710  thumb  ov093
 *   BTL_FIELD_ClearCountdown  0x021EF9C8  thumb  ov093
 */
#include "../include/Obj10021.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTLV_CORE_PrintSideMessage(char *p, u16 k, int *c);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern void BTL_FIELD_ClearCountdown(int *p);

int BTL_CLIENT_StepEndWeather(u8 *p, int *st, u32 *c)
{
    u16 v;

    switch (*st) {
    case 0:
        switch ((u8)c[0]) {
        case 1:
            v = 0x59;
            break;
        case 2:
            v = 0x5a;
            break;
        case 4:
            v = 0x5b;
            break;
        case 3:
            v = 0x5c;
            break;
        default:
            return 1;
        }
        BTLV_CORE_PrintSideMessage(((struct Obj10021 *)p)->f54, v, 0);
        (*st)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(((struct Obj10021 *)p)->f54)) {
            BTL_FIELD_ClearCountdown(((struct Obj10021 *)p)->f34);
            return 1;
        }
        break;
    }
    return 0;
}
