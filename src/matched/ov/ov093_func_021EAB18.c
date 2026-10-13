/*
 * function: BTLV_CORE_ProcClearSidePosition
 * address:  0x021EAB18
 * packet:   pkt_ov093_021EAB18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021F8414  0x021F8414  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   BTLV_SCU_HideMon  0x021ED53C  thumb  ov093
 *   BTLV_SCU_ShowMon  0x021ED554  thumb  ov093
 */
#include "../include/Obj04382.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021F8414(int a, int b, int c);
extern int func_021F7EB4(void);
extern void BTLV_SCU_HideMon(u8 *p, int k);
extern int BTLV_SCU_ShowMon(u8 *p, int k);

int BTLV_CORE_ProcClearSidePosition(int *st, u8 *b)
{
    u8 *t = BTLV_CORE_GetTaskWork(b, 8);
    int r;

    switch (*st) {
    case 0:
        func_021F8414(t[1], t[2] & 1, BTL_CLIENT_IsMainStepActive(((struct Obj04382 *)b)->f4) == 0);
        *st = *st + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            BTLV_SCU_HideMon((u8 *)(((struct Obj04382 *)b)->f17C), t[5]);
            BTLV_SCU_HideMon((u8 *)(((struct Obj04382 *)b)->f17C), t[6]);
            BTLV_SCU_HideMon((u8 *)(((struct Obj04382 *)b)->f17C), t[7]);
            *st = *st + 1;
        }
        break;
    case 2:
        r = 1;
        if (BTLV_SCU_ShowMon((u8 *)(((struct Obj04382 *)b)->f17C), t[5]) == 0) {
            r = 0;
        }
        if (BTLV_SCU_ShowMon((u8 *)(((struct Obj04382 *)b)->f17C), t[6]) == 0) {
            r = 0;
        }
        if (BTLV_SCU_ShowMon((u8 *)(((struct Obj04382 *)b)->f17C), t[7]) == 0) {
            r = 0;
        }
        if (r != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
