/*
 * function: BTL_SERVER_FLOW_ProcSubstituteMove
 * address:  0x021C4034
 * packet:   pkt_ov093_021C4034
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C40F4  0x021C40F4  thumb  ov093
 *   BTL_SERVER_FLOW_ChangeHp  0x021C5B74  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction  0x021C195C  thumb  ov093
 *   BTL_POKEPARAM_SetSubstituteHp  0x021D6D5C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgStd  0x021C5DAC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke  0x021C5D88  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int func_021D59B4(u8 *p, int k);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021C40F4(u8 *p, int i);
extern void BTL_SERVER_FLOW_ChangeHp(u8 *p, u8 *a, int c, int k);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
extern void BTL_POKEPARAM_SetSubstituteHp(u8 *a, u16 v);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
extern void BTL_SERVER_FLOW_PushMsgStd(u8 *p, u32 a, int n, const int *v);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *p, u8 *a, int b);

int BTL_SERVER_FLOW_ProcSubstituteMove(u8 *p, u8 *a)
{
    int n;
    int r;
    if (BTL_POKEPARAM_HasSubstitute(a) == 0) {
        n = BTL_CALC_DivideMaxHpMin1(a, 4);
        if (func_021D59B4(a, 0xd) > n) {
            r = func_021C40F4(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(a));
            if (r != 6) {
                BTL_SERVER_FLOW_ChangeHp(p, a, -n, 1);
                BTL_SERVER_FLOW_ProcDamagedItemReaction(p, a, 1);
                BTL_POKEPARAM_SetSubstituteHp(a, n);
                BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x27, BTL_POKEPARAM_GetPokeId(a), (u16)n);
                BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x51, r);
                BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x311, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
                return 1;
            }
        }
        BTL_SERVER_FLOW_PushMsgStd(p, 0x7b, 0, 0);
    } else {
        BTL_SERVER_FLOW_PushMsgSetPoke(p, a, 0x314);
    }
    return 0;
}
