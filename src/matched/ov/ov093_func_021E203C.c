/*
 * function: HAND_WAZA_PayDayScatterCoins
 * address:  0x021E203C
 * packet:   pkt_ov093_021E203C
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
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_TryAddMainCounter  0x021C83E8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *
 * Note: src/matched/ov/HAND_WAZA_PayDayScatterCoins.c is a different function (region ov170).
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_SERVER_FLOW_TryAddMainCounter(unsigned char *p, int i, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_PayDayScatterCoins(int u, int a, int b)
{
    int t;
    u8 *s;

    if (b == BTL_EVENT_GetVar(3)) {
        t = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam((int *)a, b), 0xf);
        if (BTL_SERVER_FLOW_TryAddMainCounter((unsigned char *)a, t * 5, b) != 0) {
            s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 4, b);
            BTL_SERVER_FLOW_InitMsgRecord(s + 4, 1, 0x7a);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
        }
    }
}
