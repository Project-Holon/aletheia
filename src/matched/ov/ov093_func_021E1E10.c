/*
 * function: HAND_WAZA_SelfDestructFaintOnFinish
 * address:  0x021E1E10
 * packet:   pkt_ov093_021E1E10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_SelfDestructFaintOnFinish(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0x13, b);
        s[4] = b;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
    }
}
