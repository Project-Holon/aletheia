/*
 * function: BTL_SERVER_FLOW_ClearMoveLockSicks
 * address:  0x021BFE60
 * packet:   pkt_ov093_021BFE60
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_CureSick  0x021C5620  thumb  ov093
 *   BTL_POKEPARAM_SetTurnFlag  0x021D5FC0  thumb  ov093
 *   BTL_POKEPARAM_GetSemiInvulnerableFlag  0x021D5C08  thumb  ov093
 *   BTL_SERVER_FLOW_ClearContFlag  0x021C6110  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
struct Slot;
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern u32 BTL_POKEPARAM_GetSemiInvulnerableFlag(struct UtilWork *p);
extern void BTL_SERVER_FLOW_ClearContFlag(u8 *p, u8 *a, unsigned int n);

void BTL_SERVER_FLOW_ClearMoveLockSicks(u8 *p, u8 *a)
{
    int k = 0x1a;
    u32 r;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, k) != 0) {
        BTL_SERVER_FLOW_CureSick(p, a, k, 0);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 0xb);
    }
    r = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a);
    while (r != 0x10) {
        BTL_SERVER_FLOW_ClearContFlag(p, a, r);
        r = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a);
    }
}
