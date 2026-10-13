/*
 * function: HAND_WAZA_RolloutEndLock
 * address:  0x021E26C8
 * packet:   pkt_ov093_021E26C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerById  0x021E03F8  thumb  ov093
 */
#include "../include/Obj10080.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void HAND_WAZA_RemoveMoveHandlerById(int a, int b);

void HAND_WAZA_RolloutEndLock(void *u, int a, int b, int *p)
{
    u8 *s;

    s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xb, b);
    s[8] = b;
    s[0x14] = 1;
    ((struct Obj10080 *)s)->f4 = 0x19;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
    p[6] = 0;
    HAND_WAZA_RemoveMoveHandlerById(b, BTL_EVENT_GetFactorKey(u));
}
