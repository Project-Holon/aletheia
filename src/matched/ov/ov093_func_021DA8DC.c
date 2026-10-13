/*
 * function: HAND_TOKUSEI_AbsorbRecoverHp
 * address:  0x021DA8DC
 * packet:   pkt_ov093_021DA8DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsHpFull   0x021D5B48  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 */
#include "../include/Obj10060.h"
#include "../include/Obj21303.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 a);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_AbsorbRecoverHp(int a, int b, int c)
{
    void *m;
    u8 *p;
    u8 *q;

    m = BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
    if (BTL_POKEPARAM_IsHpFull(m) == 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 5, b);
        p[6] = b;
        ((struct Obj10060 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(m, c);
        ((struct Obj10060 *)p)->f0 |= 2 << 22;
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 0x183);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), b);
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, p);
    } else {
        q = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 4, b);
        BTL_SERVER_FLOW_InitMsgRecord(q + 4, 2, 0xd2);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 4), b);
        ((struct Obj21303 *)q)->f0 |= 2 << 22;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, q);
    }
    BTL_EVENT_OverwriteVar(0x51, 1);
}
