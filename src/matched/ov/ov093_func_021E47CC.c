/*
 * function: HAND_WAZA_TormentOnUncategorizedMove
 * address:  0x021E47CC
 * packet:   pkt_ov093_021E47CC
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
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10090.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTLV_CORE_MakeSlotKind1Empty(void);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_TormentOnUncategorizedMove(int a0, u8 *s, int k)
{
    u8 v;
    u8 *q;
    u8 *e;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        q = BTL_SERVER_FLOW_GetPokeParam((int *)s, v);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 12) == 0) {
            e = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 12, k);
            ((struct Obj10090 *)e)->f4 = 12;
            ((struct Obj10090 *)e)->f8 = BTLV_CORE_MakeSlotKind1Empty();
            e[0xf] = v;
            BTL_SERVER_FLOW_CommitCmdRecord(s, e);
        }
    }
}
