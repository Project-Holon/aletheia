/*
 * file:     unit_068994A8.c
 * unit:     yes
 * function: func_068994A8, func_068994B4
 * address:  0x068994A8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   func_021B9A40  0x021B9A40  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   data_0689D718 0x0689D718 data a4
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int a);
extern int func_021B9A40(int a);
extern int WAZA_TOOL_GetParam(u16 a, int b);
extern int BTL_EVENT_OverwriteVar(int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(int p, int n, int c);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(int p, int v);
void *func_068994A8(u32 *p);
void func_068994B4(int a0, int a1, int x);
extern u32 data_0689D718;

/*
 * Unlabelled store-and-return follower after veneer 0x06899498.
 */
void *func_068994A8(u32 *p) { *p = 1; return &data_0689D718; }


void func_068994B4(int a0, int a1, int x)
{
    u8 v;
    int q;

    v = BTL_EVENT_GetVar(4);
    if (x == func_021B9A40(v) && v != BTL_EVENT_GetVar(3)
        && WAZA_TOOL_GetParam(BTL_EVENT_GetVar(0x12), 6) >= 1
        && BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
        q = BTL_EVENT_GetVar(0x3f);
        BTL_SERVER_FLOW_InitMsgRecord(q, 2, 0x320);
        BTL_SERVER_FLOW_AppendMsgRecordArg(q, v);
    }
}
