/*
 * file:     unit_068993A4.c
 * unit:     yes
 * function: func_068993A4, func_068993B0
 * address:  0x068993A4
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
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   func_021B9A40  0x021B9A40  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   data_0689D700 0x0689D700 data a4
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int a);
extern u8 func_021B9A40(u32 a);
extern u32 WAZA_TOOL_GetParam(u32 a, int b);
extern u32 WAZA_TOOL_IsDamaging(u32 a);
extern int BTL_EVENT_OverwriteVar(int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(int p, int n, int c);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(int p, int v);
void *func_068993A4(u32 *p);
void func_068993B0(int a0, int a1, u32 x);
extern u32 data_0689D700;

/*
 * Unlabelled store-and-return follower after veneer 0x06899394.
 */
void *func_068993A4(u32 *p) { *p = 1; return &data_0689D700; }


/*
 * note: recoup 2026-10-05: callee return types from matched definitions closed it. func_021B9A40 (func_021B9A40) returns u8, WAZA_TOOL_GetParam (WAZA_TOOL_GetParam) and WAZA_TOOL_IsDamaging (WAZA_TOOL_IsDamaging) return u32, x is u32, h is u16. Earlier DIFF was a v/h colour swap caused by int declarations.
 */
void func_068993B0(int a0, int a1, u32 x)
{
    u8 v;
    u16 h;

    v = BTL_EVENT_GetVar(4);
    if (x == func_021B9A40(v)) {
        h = BTL_EVENT_GetVar(0x12);
        x = WAZA_TOOL_GetParam(h, 0x1b);
        if (WAZA_TOOL_IsDamaging(h) != 0) {
            if (x == 4 || x == 5) {
                if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
                    x = BTL_EVENT_GetVar(0x3f);
                    BTL_SERVER_FLOW_InitMsgRecord(x, 2, 0x31d);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(x, v);
                }
            }
        }
    }
}
