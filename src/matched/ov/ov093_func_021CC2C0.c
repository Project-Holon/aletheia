/*
 * function: BTL_SERVER_FLOW_ItemEffectRecoverHp
 * address:  0x021CC2C0
 * packet:   pkt_ov093_021CC2C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj05195.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

int BTL_SERVER_FLOW_ItemEffectRecoverHp(void *a, void *m, void *s)
{
    int id;
    u8 *r;
    u32 k;

    if (BTL_POKEPARAM_IsHpFull(m) == 0 && BTL_POKEPARAM_IsFainted(m) == 0) {
        id = BTL_POKEPARAM_GetPokeId(m);
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 5, id);
        r[6] = id;
        r[7] = 1;
        k = BTL_CALC_GetMonParamWithHeap(s, 0x3a);
        switch (k) {
        case 0xff:
            ((struct Obj05195 *)r)->f4 = BTL_POKEPARAM_GetValue(m, 14);
            break;
        case 0xfe:
            ((struct Obj05195 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 2);
            break;
        case 0xfd:
            ((struct Obj05195 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 4);
            break;
        default:
            ((struct Obj05195 *)r)->f4 = k;
            break;
        }
        BTL_SERVER_FLOW_InitMsgRecord(r + 8, 2, 387);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), id);
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
        return 1;
    }
    return 0;
}
