/*
 * function: BTL_CLIENT_StepSendActions
 * address:  0x021CF2F0
 * packet:   pkt_ov093_021CF2F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_FlushSlotLinkWords  0x021CF3F8  thumb  ov093
 *   BTL_MAIN_GetCommPos  0x021B86C0  thumb  ov093
 *   BTLV_CORE_StartWaitMessage  0x021EA7FC  thumb  ov093
 *   BTLV_CORE_UpdateWaitMessage  0x021EA814  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   BTL_CLIENT_StopTimeLimit  0x021CE0E0  thumb  ov093
 */
#include "../include/Obj07772.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_CLIENT_FlushSlotLinkWords(u8 *p);
extern u8 BTL_MAIN_GetCommPos(u8 **p);
extern void BTLV_CORE_StartWaitMessage(char *p);
extern int BTLV_CORE_UpdateWaitMessage(u32 *p);
extern int func_021F7EB4(void);
extern void BTL_CLIENT_StopTimeLimit(u8 *p);

u32 BTL_CLIENT_StepSendActions(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        BTL_CLIENT_FlushSlotLinkWords(p);
        if (BTL_MAIN_GetCommPos(*(u8 ** *)&((struct Obj07772 *)p)->f0) != 0) {
            p[0x1a9] = 1;
            BTLV_CORE_StartWaitMessage((char *)(*(u32 *)&((struct Obj07772 *)p)->f54));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (BTLV_CORE_UpdateWaitMessage(*(u32 * *)&((struct Obj07772 *)p)->f54) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            BTL_CLIENT_StopTimeLimit(p);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
