/*
 * function: func_021E7388
 * address:  0x021E7388
 * packet:   pkt_ov093_021E7388
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07835.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void func_021E7388(int a, void *b, int c)
{
    u32 i;
    u32 n;
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        n = BTL_EVENT_GetVar(5);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(i + 6)), 0x10) != 0x36) {
                m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1f, c);
                m[6] = BTL_EVENT_GetVar(i + 6);
                ((struct Obj07835 *)m)->f4 = 0x56;
                BTL_SERVER_FLOW_InitMsgRecord(m + 0xc, 2, 0x195);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), m[6]);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), ((struct Obj07835 *)m)->f4);
                BTL_SERVER_FLOW_CommitCmdRecord(b, m);
            }
        }
    }
}
