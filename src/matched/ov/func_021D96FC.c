/*
 * function: HAND_TOKUSEI_CureSick
 * address:  0x021D96FC
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_CureSick   0x021D96FC  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord   0x021C88B4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *
 * Build the record for (a, b) after a two-step gate, fill in c, publish it
 * through BTL_SERVER_FLOW_CommitCmdRecord, then emit the "3" event through BTL_SERVER_FLOW_PushCmdRecord.
 */
#include "../include/Obj09218.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Unk021D62A8;
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);

void HAND_TOKUSEI_CureSick(void *a, int b, int c)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(a, b), c) != 0) {
        u8 *p;
        BTL_SERVER_FLOW_PushCmdRecord(a, 2, b);
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xb, b);
        ((struct Obj09218 *)p)->f4 = c;
        ((struct Obj09218 *)p)->f14 = 1;
        ((struct Obj09218 *)p)->f8 = b;
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
        BTL_SERVER_FLOW_PushCmdRecord(a, 3, b);
    }
}
