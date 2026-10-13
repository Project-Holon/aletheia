/*
 * function: HAND_WAZA_HazeResetRanks
 * address:  0x021E0D54
 * packet:   pkt_ov093_021E0D54
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
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);

void HAND_WAZA_HazeResetRanks(int unused, void *q, int id)
{
    u8 *r;
    int k;

    if (id == BTL_EVENT_GetVar(3)) {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0x10, id);
        k = 0x10;
        r[4] = BTL_SERVER_FLOW_CollectAlivePokeIds(q, (u16)((k << 7) | BTL_SERVER_FLOW_GetFrontPosOfPoke(q, id)), r + 5);
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 1, 0x65);
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    }
}
