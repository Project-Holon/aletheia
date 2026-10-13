/*
 * unit: yes
 * function: HAND_WAZA_SecretPowerOnAddEffect, HAND_WAZA_AddChatter
 * address: 0x021E11DC
 * packet: pkt_ov093_021E11DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E1298 store-return stub included; lead sentinel at +12 is signed byte.
 * symbols:
 *   gChatterHandlers 0x021F253C data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   HAND_WAZA_SecretPowerGetGroundEffect 0x021E112C thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_CALC_MakeSickContFromKind 0x021D7DC0 thumb ov093
 */
#include "../include/Obj03703.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef struct { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
extern u32 BTL_CALC_Random(u32);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u8 HAND_WAZA_SecretPowerGetGroundEffect(int *a, u8 *p1, u8 *p2);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_CALC_MakeSickContFromKind(int, int, Word *);
void HAND_WAZA_SecretPowerOnAddEffect(int unused, void *q, int id)
{
    void *m;
    u8 target;
    u8 kind;
    u8 value;
    u8 *r;
    if (id == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x47) == 0 && BTL_CALC_Random(100) < 30) {
        m = BTL_SERVER_FLOW_GetPokeParam(q, id);
        target = BTL_EVENT_GetVar(6);
        HAND_WAZA_SecretPowerGetGroundEffect(q, &kind, &value);
        switch (kind) {
        case 0:
            r = BTL_SERVER_FLOW_AllocCmdRecord(q, 12, id);
            r[15] = target;
            ((struct Obj03703 *)r)->f4 = value;
            BTL_CALC_MakeSickContFromKind(value, (int)m, (Word *)(r + 8));
            BTL_SERVER_FLOW_CommitCmdRecord(q, r);
            break;
        case 1:
            r = BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
            r[15] = 1;
            r[16] = target;
            ((struct Obj03703 *)r)->f4 = value;
            ((struct Obj03703 *)r)->fC = -1;
            BTL_SERVER_FLOW_CommitCmdRecord(q, r);
            break;
        case 2:
            r = BTL_SERVER_FLOW_AllocCmdRecord(q, 43, id);
            r[4] = target;
            r[5] = 100;
            BTL_SERVER_FLOW_CommitCmdRecord(q, r);
            break;
        }
    }
}
extern u32 gChatterHandlers[];
u32 *HAND_WAZA_AddChatter(u32 *p)
{
    *p = 1;
    return gChatterHandlers;
}
