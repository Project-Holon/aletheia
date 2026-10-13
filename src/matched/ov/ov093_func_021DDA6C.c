/*
 * function: HAND_ITEM_RecoverHpByMaxHpDivisor
 * address:  0x021DDA6C
 * packet:   pkt_ov093_021DDA6C
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
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13487.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int HAND_ITEM_GetParam(int a, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_RecoverHpByMaxHpDivisor(int a, u8 *b, int c)
{
    void *m;
    u8 *p;
    u8 k;
    if (c == BTL_EVENT_GetVar(2)) {
        m = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
        k = HAND_ITEM_GetParam(a, 2);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 5, c);
        p[6] = c;
        ((struct Obj13487 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(m, k);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
