/*
 * function: BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent
 * address: 0x021C024C
 * packet: pkt_ov093_021C024C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Wide third extern argument preserves the full r2 passed by the image.
 * symbols:
 *   BTL_SERVER_FLOW_QueryMoveFailReasonEvent 0x021C02CC thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecuteFail 0x021C0450 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_QueryMoveFailReasonEvent(u8 *, u8 *, u32, int);
extern void BTL_SERVER_FLOW_ProcMoveExecuteFail(u8 *, u8 *, u32, int);
int BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent(u8 *p, u8 *a, u32 c)
{
    int result;
    if (c != 0xa5) {
        result = BTL_SERVER_FLOW_QueryMoveFailReasonEvent(p, a, c, 0x1f);
        if (result != 0) {
            BTL_SERVER_FLOW_ProcMoveExecuteFail(p, a, c, result);
            return 1;
        }
    }
    return 0;
}
