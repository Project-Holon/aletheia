/*
 * file:     unit_0689BB7C.c
 * function: func_0689BB7C
 * address:  0x0689BB7C
 * packet:   pkt_ov095_0689BB7C
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
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    u8 pad[4];
    u16 f04;
    u8 f06;
    u8 f07;
    u8 f08[1];
} Rec;

extern int BTL_POKEPARAM_IsHpFull(void *);
extern Rec *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern int BTL_CALC_DivideMaxHpMin1(void *, int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *, int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);

void func_0689BB7C(void *a, void *b, int c)
{
    Rec *r;

    if (BTL_POKEPARAM_IsHpFull(b) == 0) {
        r = BTL_SERVER_FLOW_AllocCmdRecord(a, 6, c);
        r->f06 = c;
        r->f07 = 0x1f;
        r->f04 = BTL_CALC_DivideMaxHpMin1(b, 0x10);
        BTL_SERVER_FLOW_InitMsgRecord(r->f08, 2, 0x2e3);
        BTL_SERVER_FLOW_AppendMsgRecordArg(r->f08, c);
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
