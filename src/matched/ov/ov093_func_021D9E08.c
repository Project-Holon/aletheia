/*
 * function: HAND_TOKUSEI_TryAddContactSick
 * address:  0x021D9E08
 * packet:   pkt_ov093_021D9E08
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   HAND_TOKUSEI_RollChanceOrFlag   0x021D85C0  thumb ov093
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 */
#include "../include/Obj06252.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 raw; } Slot;
typedef struct { u8 b; } Byte;

extern int BTL_EVENT_GetVar(int a);
extern int HAND_TOKUSEI_RollChanceOrFlag(int a, u32 b);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_TryAddContactSick(int a, int b, int c, Slot d, Byte e)
{
    u8 *p;
    u32 m = 4;

    if (b != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 0) == 0)
        return;
    if (HAND_TOKUSEI_RollChanceOrFlag(a, e.b) == 0)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xc, b);
    ((struct Obj06252 *)p)->f0 |= m << 21;
    ((struct Obj06252 *)p)->f4 = c;
    ((struct Obj06252 *)p)->f8 = d.raw;
    ((struct Obj06252 *)p)->fC = 0;
    ((struct Obj06252 *)p)->fF = BTL_EVENT_GetVar(3);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)a, p);
}
