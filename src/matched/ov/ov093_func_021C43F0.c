/*
 * function: BTL_SERVER_FLOW_CollectActivePokes
 * address:  0x021C43F0
 * packet:   pkt_ov093_021C43F0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C443C  0x021C443C  thumb  ov093
 *   BTL_SERVER_FLOW_InitFieldPokeIter  0x021BD2B4  thumb  ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter  0x021BD34C  thumb  ov093
 *   func_021C444C  0x021C444C  thumb  ov093
 *   func_021C445C  0x021C445C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C443C(u8 *a);
extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *it, u8 **q);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *it, u8 **q, u8 **x);
extern void func_021C444C(u8 *a, u8 *x);
extern void func_021C445C(u8 *a, u8 *p);

void BTL_SERVER_FLOW_CollectActivePokes(u8 *p, u8 *a)
{
    u32 it;
    u8 *x;
    func_021C443C(a);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &x)) {
        func_021C444C(a, x);
    }
    func_021C445C(a, p);
}
