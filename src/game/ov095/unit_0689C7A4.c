/*
 * file:     unit_0689C7A4.c
 * function: func_0689C7A4
 * address:  0x0689C7A4
 * packet:   pkt_ov095_0689C7A4
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 */

int BTL_POKEPARAM_HasSick(int a, int b);
int BTL_EVENT_OverwriteVar(int a, int b);
int BTL_POKEPARAM_GetPokeId(int a);
char *BTL_SERVER_FLOW_AllocCmdRecord(int a, int b, int c);
void BTL_SERVER_FLOW_InitMsgRecord(char *a, int b, int c);
void BTL_SERVER_FLOW_AppendMsgRecordArg(char *a, int b);
void BTL_SERVER_FLOW_CommitCmdRecord(int a, char *b);

void func_0689C7A4(int p, int x)
{
    int n;
    char *q;

    if (BTL_POKEPARAM_HasSick(x, 0x15) && BTL_EVENT_OverwriteVar(0x41, 1)) {
        n = BTL_POKEPARAM_GetPokeId(x);
        q = BTL_SERVER_FLOW_AllocCmdRecord(p, 4, n);
        BTL_SERVER_FLOW_InitMsgRecord(q + 4, 2, 0x2e6);
        BTL_SERVER_FLOW_AppendMsgRecordArg(q + 4, n);
        BTL_SERVER_FLOW_CommitCmdRecord(p, q);
    }
}
