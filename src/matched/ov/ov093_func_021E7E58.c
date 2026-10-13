/*
 * function: HAND_WAZA_AllySwitchSwapPositions
 * address:  0x021E7E58
 * packet:   pkt_ov093_021E7E58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_SERVER_FLOW_GetClientIdBySide  0x021C8300  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 *   BTL_MAIN_IsBackRowPos  0x021B99F0  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern int BTL_SERVER_FLOW_GetRule(int *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u32 BTL_SERVER_FLOW_GetClientIdBySide(int *p, u8 k);
extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);
extern u32 BTL_MAIN_IsBackRowPos(u32 x);
extern int BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(void *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_AllySwitchSwapPositions(int a, u8 *b, int c)
{
    int x, y;
    u32 k;
    u8 *p;

    x = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
    y = c;
    switch (BTL_SERVER_FLOW_GetRule((int *)b)) {
    case 1:
        if (BTL_SERVER_FLOW_GetClientIdBySide((int *)b, BTL_MAIN_PokeIdToClientIdThunk(c)) == 4) {
            k = BTL_MAIN_GetOwnLanePos(x, 0);
            if (k == x)
                k = BTL_MAIN_GetOwnLanePos(x, 1);
            y = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, k);
        }
        break;
    case 2:
        if (BTL_MAIN_IsBackRowPos(x) == 0) {
            k = BTL_MAIN_GetOwnLanePos(x, 0);
            if (k == x)
                k = BTL_MAIN_GetOwnLanePos(x, 2);
            y = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, k);
        }
        break;
    }
    if (y != c) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x32, c);
        p[4] = c;
        p[5] = y;
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 1137);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), y);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
