/*
 * function: BTL_SERVER_FLOW_TryClearContFlag
 * address:  0x021C5418
 * packet:   pkt_ov093_021C5418
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_ClearContFlag  0x021C6110  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_CureSick  0x021C5620  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_MarkActionDone  0x021BD1D0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_FLOW_ClearContFlag(u8 *p, u8 *a, unsigned int n);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
struct Slot { u32 kind : 3; u32 rest : 29; };
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_MarkActionDone(u8 *p, u8 n);

int BTL_SERVER_FLOW_TryClearContFlag(u8 *p, u8 *a, int b)
{
    u8 n;
    if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, b)) {
        n = BTL_POKEPARAM_GetPokeId(a);
        BTL_SERVER_FLOW_ClearContFlag(p, a, b);
        b = 0x1a;
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x1a)) {
            BTL_SERVER_FLOW_CureSick(p, a, b, 0);
        }
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x31, n, 0);
        BTL_SERVER_FLOW_MarkActionDone(p, n);
        return 1;
    }
    return 0;
}
