/*
 * function: HAND_WAZA_SelfDestructPushUserCmd
 * address:  0x021E1DF4
 * packet:   pkt_ov093_021E1DF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);

void HAND_WAZA_SelfDestructPushUserCmd(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(2))
        BTL_SERVER_FLOW_PushCmdRecord(a, 0x3b, b);
}
