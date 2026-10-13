/*
 * function: HAND_WAZA_BideCureStoringState
 * address:  0x021E3F08
 * packet:   pkt_ov093_021E3F08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07830.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);

void HAND_WAZA_BideCureStoringState(void *a, int b, int *p)
{
    u8 *s;

    if (p[6] != 0) {
        s = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xb, b);
        ((struct Obj07830 *)s)->f4 = 0x19;
        s[0x14] = 1;
        s[8] = b;
        s[0x15] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(a, s);
        p[6] = 0;
    }
}
