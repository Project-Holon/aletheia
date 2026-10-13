/*
 * function: BTL_SERVER_FLOW_CheckFreezeThaw
 * address:  0x021C0404
 * packet:   pkt_ov093_021C0404
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_CALC_RollPercent  0x021D7AF0  thumb  ov093
 *   BTL_SERVER_FLOW_CureMajorStatusWithMessage  0x021C557C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
extern int BTL_CALC_RollPercent(u32 pct);
extern void BTL_SERVER_FLOW_CureMajorStatusWithMessage(u8 *p, u8 *a, int k, int flag);
int BTL_SERVER_FLOW_CheckFreezeThaw(u8 *p, u8 *a, void *bag)
{
    int k = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    int f = 0;
    int r = 0;
    if (k == 3) {
        if (WAZA_TOOL_GetFlag(bag, 10) != 0) {
            r = 1;
        } else if (BTL_CALC_RollPercent(20) != 0) {
            f = 1;
        }
    }
    if (f != 0) {
        BTL_SERVER_FLOW_CureMajorStatusWithMessage(p, a, k, 1);
    }
    return r;
}
