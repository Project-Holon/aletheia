/*
 * function: BTL_SERVER_FLOW_ThawTargetsHitByFireMove
 * address:  0x021C1CE4
 * packet:   pkt_ov093_021C1CE4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C1D30  0x021C1D30  thumb  ov093
 *   func_021C1D40  0x021C1D40  thumb  ov093
 *   func_021C1D50  0x021C1D50  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_SERVER_FLOW_CureMajorStatusWithMessage  0x021C557C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C1D30(u8 *w);
extern u8 *func_021C1D40(u8 *w);
extern u8 *func_021C1D50(u8 *w);
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern void BTL_SERVER_FLOW_CureMajorStatusWithMessage(u8 *p, u8 *a, int k, int flag);

void BTL_SERVER_FLOW_ThawTargetsHitByFireMove(u8 *p, u8 *q, u32 unused, u8 *w)
{
    u8 *t;
    if (q[6] == 9) {
        func_021C1D30(w);
        t = func_021C1D40(w);
        while (t) {
            int k = 3;
            if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)t) == 3 && BTL_POKEPARAM_HasSubstitute(t) == 0) {
                BTL_SERVER_FLOW_CureMajorStatusWithMessage(p, t, k, 1);
            }
            t = func_021C1D50(w);
        }
    }
}
