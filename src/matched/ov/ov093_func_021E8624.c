/*
 * function: HAND_COMMON_IsLastToAct
 * address:  0x021E8624
 * packet:   pkt_ov093_021E8624
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_AreAllOtherActionsDone  0x021C80AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_SERVER_FLOW_AreAllOtherActionsDone(u8 *p, int key);

int HAND_COMMON_IsLastToAct(int a, int b)
{
    if (BTL_SERVER_FLOW_AreAllOtherActionsDone((u8 *)a, b) != 0)
        return 1;
    return 0;
}
