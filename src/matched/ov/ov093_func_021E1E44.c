/*
 * function: HAND_WAZA_FocusEnergyApplyEffect
 * address:  0x021E1E44
 * packet:   pkt_ov093_021E1E44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *
 * The tail after the pop (movs r1,#4; str r1,[r0]; ldr r0,[pc]; bx lr) is an
 * unlabelled follower stub.
 */
#include "../include/Obj13506.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);

void HAND_WAZA_FocusEnergyApplyEffect(int u, int a, int b)
{
    u8 *r;
    u8 *s;

    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam((int *)a, b), 9) == 0) {
            r = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0x17, b);
            r[8] = b;
            ((struct Obj13506 *)r)->f4 = 9;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
            s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 4, b);
            BTL_SERVER_FLOW_InitMsgRecord(s + 4, 2, 0x411);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(s + 4), b);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
        }
    }
}
