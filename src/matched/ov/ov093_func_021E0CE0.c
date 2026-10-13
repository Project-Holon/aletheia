/*
 * function: HAND_WAZA_TrapAddNoEscape
 * address:  0x021E0CE0
 * packet:   pkt_ov093_021E0CE0
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_MakeSickContPoke  0x021D7D9C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10072.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern u32 BTL_CALC_MakeSickContPoke(int x);

void HAND_WAZA_TrapAddNoEscape(int unused, void *q, int id)
{
    u8 *r;
    u8 k;

    if (id == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(q, k), 0x16) == 0) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0xc, id);
            r[0xf] = k;
            ((struct Obj10072 *)r)->f4 = 0x16;
            ((struct Obj10072 *)r)->f8 = BTL_CALC_MakeSickContPoke(id);
            BTL_SERVER_FLOW_InitMsgRecord(r + 0x14, 2, 0x368);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0x14), k);
            BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        }
    }
}
