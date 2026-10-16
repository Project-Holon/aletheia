/*
 * function: HAND_TOKUSEI_Forecast_ResetForm
 * address:  0x021DB318
 * packet:   pkt_ov093_021DB318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_TOKUSEI_Forecast_ResetForm(int unused, void *a, int id)
{
    u8 *r;
    void *m;

    m = BTL_SERVER_FLOW_GetPokeParam(a, id);
    if (BTL_POKEPARAM_GetSpecies(m) == 0x15f && BTL_POKEPARAM_GetValue(m, 0x13) != 0) {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 0x39, id);
        r[4] = id;
        r[5] = 0;
        BTL_SERVER_FLOW_InitMsgRecord(r + 8, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), id);
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
