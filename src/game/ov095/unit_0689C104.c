/*
 * file:     unit_0689C104.c
 * function: func_0689C104
 * address:  0x0689C104
 * packet:   pkt_ov095_0689C104
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 */

typedef unsigned char u8;

typedef struct Rec {
    int f00;
    u8 f04[1];
} Rec;

extern int BTL_POKEPARAM_GetPokeId(void *);
extern Rec *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *, int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, Rec *);

void func_0689C104(void *a, void *b, u8 c)
{
    int k;
    Rec *r;

    k = BTL_POKEPARAM_GetPokeId(b);
    r = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, k);
    BTL_SERVER_FLOW_InitMsgRecord(r->f04, 2, 0x35c);
    BTL_SERVER_FLOW_AppendMsgRecordArg(r->f04, k);
    BTL_SERVER_FLOW_AppendMsgRecordArg(r->f04, c);
    BTL_SERVER_FLOW_CommitCmdRecord(a, r);
}
