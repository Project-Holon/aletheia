/*
 * function: BTL_SERVER_SendCommandData
 * address:  0x021BB724
 * packet:   pkt_ov093_021BB724
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_ADAPTER_NotifyNet  0x021EEAE8  thumb  ov093
 *   BTL_SERVER_IsClientSlotUsed  0x021BB830  thumb  ov093
 *   BTL_ADAPTER_SetSendData  0x021EEB00  thumb  ov093
 *   BTL_ADAPTER_Idle  0x021EEAFC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BTL_ADAPTER_NotifyNet(void);
extern int BTL_SERVER_IsClientSlotUsed(u8 *);
extern void BTL_ADAPTER_SetSendData(u32, int, int, int);
extern void BTL_ADAPTER_Idle(void);

void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c)
{
    int i;
    u8 *q;

    BTL_ADAPTER_NotifyNet();
    i = 0;
    q = p + 0x14;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed(q + i * 12) != 0)
            BTL_ADAPTER_SetSendData(*(u32 *)(p + 0x14 + i * 12), a, b, c);
    }
    BTL_ADAPTER_Idle();
}
