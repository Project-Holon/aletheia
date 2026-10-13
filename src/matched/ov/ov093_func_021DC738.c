/*
 * function: HAND_TOKUSEI_ZenModeUpdateForm
 * address:  0x021DC738
 * packet:   pkt_ov093_021DC738
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj00041.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_ZenModeUpdateForm(int a, void *b, int c)
{
    u8 *m;
    u8 f;

    m = (u8 *)BTL_SERVER_FLOW_GetPokeParam(b, c);
    if (BTL_POKEPARAM_GetSpecies((struct QF *)m) == 0x22b) {
        f = (func_021D59B4(m, 13) <= BTL_CALC_DivideMaxHp(m, 2));
        if (f != func_021D59B4(m, 0x13)) {
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x39, c);
            *(u32 *)&((struct Obj00041 *)m)->f0 |= 2 << 22;
            m[4] = c;
            m[5] = f;
            BTL_SERVER_FLOW_InitMsgRecord(m + 8, 1, (u16)(f == 1 ? 0xb9 : 0xba));
            BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        }
    }
}
