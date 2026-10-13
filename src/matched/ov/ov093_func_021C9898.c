/*
 * function: BTL_SERVER_FLOW_ExecCmdRegisterFieldSlot
 * address: 0x021C9898
 * packet: pkt_ov093_021C9898
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of trailing alignment padding.
 * symbols:
 *   BTL_SERVER_FLOW_TryRegisterFieldSlot 0x021C3C60 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int x; } S;
struct Msg;
extern int BTL_SERVER_FLOW_TryRegisterFieldSlot(u8 *, int, S, int);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *, const struct Msg *);
int BTL_SERVER_FLOW_ExecCmdRegisterFieldSlot(u8 *p, u8 *q)
{
    if (BTL_SERVER_FLOW_TryRegisterFieldSlot(p, *(int *)(q + 4), *(S *)(q + 8), q[12])) {
        BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(q + 16));
        return 1;
    }
    return 0;
}
