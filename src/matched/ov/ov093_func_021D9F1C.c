/*
 * function: HAND_TOKUSEI_AftermathOnDamageReaction
 * address:  0x021D9F1C
 * packet:   pkt_ov093_021D9F1C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 */
#include "../include/Obj06253.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_AftermathOnDamageReaction(int a, int b, int c)
{
    u8 *p;
    u8 k;
    void *m;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam((int *)b, c)) == 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 0) == 0)
        return;
    k = BTL_EVENT_GetVar(3);
    m = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 7, c);
    ((struct Obj06253 *)p)->f0 |= 4 << 21;
    ((struct Obj06253 *)p)->f6 = k;
    ((struct Obj06253 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(m, 4);
    p[7] = (p[7] & ~1) | 1;
    BTL_SERVER_FLOW_InitMsgRecord(p + 0xc, 2, 0x192);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), k);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
