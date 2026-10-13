/*
 * function: func_021E8190
 * address:  0x021E8190
 * packet:   pkt_ov093_021E8190
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_EVENT_GetVar(int key);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void func_021E8190(int a, void *b, int c)
{
    int f;
    u8 *p;
    void *m;

    m = BTL_SERVER_FLOW_GetPokeParam(b, c);
    if (BTL_POKEPARAM_GetSpecies(m) == 0x288 && c == BTL_EVENT_GetVar(3)) {
        f = func_021D59B4(m, 0x13) == 0;
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x39, c);
        p[4] = c;
        p[5] = f;
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
