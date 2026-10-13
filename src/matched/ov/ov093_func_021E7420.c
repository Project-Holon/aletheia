/*
 * function: HAND_WAZA_EntrainmentCopyAbility
 * address:  0x021E7420
 * packet:   pkt_ov093_021E7420
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The narrowed scan key is a `u8` local assigned from the call, then passed:
 * the inline cast `(u8)BTL_EVENT_GetVar(i + 6)` adds an `adds r1, r0` copy the
 * image does not have.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E74C8  0x021E74C8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07836.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E74C8(u16 k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_EntrainmentCopyAbility(int a, int b, int c)
{
    u16 k;
    u32 i;
    u32 n;
    u8 *p;
    u8 t;

    if (c == BTL_EVENT_GetVar(3)) {
        k = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 0x10);
        if (func_021E74C8(k) == 0) {
            n = BTL_EVENT_GetVar(5);
            for (i = 0; i < n; i++) {
                t = BTL_EVENT_GetVar(i + 6);
                if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam((int *)b, t), 0x10) != 0x36) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x1f, c);
                    ((struct Obj07836 *)p)->f6 = BTL_EVENT_GetVar(i + 6);
                    ((struct Obj07836 *)p)->f4 = k;
                    BTL_SERVER_FLOW_InitMsgRecord(p + 0xc, 2, 0x195);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f6);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f4);
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
        }
    }
}
