/*
 * function: BTL_SERVER_FLOW_TickSleepTurn
 * address:  0x021C03D8
 * packet:   pkt_ov093_021C03D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_TickSleepTurn  0x021D6130  thumb  ov093
 *   BTL_SERVER_FLOW_CureMajorStatusWithMessage  0x021C557C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
struct UtilSlots;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int BTL_POKEPARAM_TickSleepTurn(struct UtilSlots *p);
extern void BTL_SERVER_FLOW_CureMajorStatusWithMessage(u8 *p, u8 *a, int k, int flag);

void BTL_SERVER_FLOW_TickSleepTurn(u8 *p, u8 *a, u16 a2)
{
    int k = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    if (k == 2 && BTL_POKEPARAM_TickSleepTurn((struct UtilSlots *)a) != 0) {
        BTL_SERVER_FLOW_CureMajorStatusWithMessage(p, a, k, 1);
    }
}
