/*
 * function: BTL_SERVER_FLOW_PushFieldEffectExpireMessage
 * address:  0x021C4C50
 * packet:   pkt_ov093_021C4C50
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_CollectActivePokes  0x021C43F0  thumb  ov093
 *   func_021C4CEC  0x021C4CEC  thumb  ov093
 *   func_021C4CFC  0x021C4CFC  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction  0x021C195C  thumb  ov093
 *   func_021C4D0C  0x021C4D0C  thumb  ov093
 */
#include "../include/Obj05192.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_CollectActivePokes(u8 *p, u8 *a);
extern void func_021C4CEC(u8 *a);
extern u8 *func_021C4CFC(u8 *a);
extern int BTL_POKEPARAM_IsAbleToBattle(void *m);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
extern u8 *func_021C4D0C(u8 *a);

void BTL_SERVER_FLOW_PushFieldEffectExpireMessage(u8 *p, int k)
{
    int r = -1;
    u8 *q;
    switch (k) {
    case 0: break;
    case 1: r = 0x74; break;
    case 2: r = 0x76; break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: r = 0xb3; break;
    case 7: r = 0xb5; break;
    }
    if (r >= 0) {
        BTL_SERVER_CMD_PushVariable(((struct Obj05192 *)p)->fC, 0x5a, r, 0xffff0000);
    }
    BTL_SERVER_CMD_Push(((struct Obj05192 *)p)->fC, 0x24, (u8)k);
    if (k == 7) {
        BTL_SERVER_FLOW_CollectActivePokes(p, *(u8 * *)&((struct Obj05192 *)p)->f868);
        func_021C4CEC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        q = func_021C4CFC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        while (q) {
            if (BTL_POKEPARAM_IsAbleToBattle(q)) {
                BTL_SERVER_FLOW_ProcDamagedItemReaction(p, q, 0);
            }
            q = func_021C4D0C(*(u8 * *)&((struct Obj05192 *)p)->f868);
        }
    }
}
