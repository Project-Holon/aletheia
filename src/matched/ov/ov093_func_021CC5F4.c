/*
 * function: BTL_SERVER_FLOW_ItemEffectPushTypeMessage
 * address:  0x021CC5F4
 * packet:   pkt_ov093_021CC5F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

int BTL_SERVER_FLOW_ItemEffectPushTypeMessage(char *p, void *m)
{
    u32 s;
    int id;
    u8 *r;
    char *q;

    s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 1968);
    id = BTL_POKEPARAM_GetPokeId(m);
    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(p, 16, id);
    r[4] = 1;
    r[5] = id;
    BTL_SERVER_FLOW_CommitCmdRecord(p, r);
    q = (char *)BTL_SERVER_FLOW_AllocCmdRecord(p, 4, id);
    BTL_SERVER_FLOW_InitMsgRecord(q + 4, 2, 228);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 4), id);
    BTL_SERVER_FLOW_CommitCmdRecord(p, q);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 1984);
    return 1;
}
