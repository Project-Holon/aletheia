/*
 * function: BTL_SERVER_SendCommandDataToClient
 * address: 0x021BB768
 * packet: pkt_ov093_021BB768
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_IsClientSlotUsed 0x021BB830 thumb ov093
 *   BTL_ADAPTER_Cancel 0x021EEB70 thumb ov093
 *   BTL_ADAPTER_SetSendData 0x021EEB00 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_IsClientSlotUsed(u8 *);
extern void BTL_ADAPTER_Cancel(u32);
extern void BTL_ADAPTER_SetSendData(u32, int, int, int);
void BTL_SERVER_SendCommandDataToClient(u8 *p, int a, u32 i, int b, int c) {
    u8 *q;
    q = (u8 *)((u32)p + 20);
    if (BTL_SERVER_IsClientSlotUsed((u8 *)((u32)q+i*12))) {
        BTL_ADAPTER_Cancel(*(u32 *)((u32)q+i*12));
        BTL_ADAPTER_SetSendData(*(u32 *)((u32)q+i*12),a,b,c);
    }
}
