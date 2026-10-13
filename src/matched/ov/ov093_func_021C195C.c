/*
 * function: BTL_SERVER_FLOW_ProcDamagedItemReaction
 * address:  0x021C195C
 * packet:   pkt_ov093_021C195C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_RunDamagedItemEvent  0x021C199C  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 func_021CC8D8(void *lock, int line);
extern void BTL_SERVER_FLOW_RunDamagedItemEvent(u8 *p, u8 *q, u32 n);
extern void func_021CC95C(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n)
{
    if (BTL_POKEPARAM_GetItem((struct QI *)q)) {
        u32 s = func_021CC8D8(p + 0x1D74, 6844);
        BTL_SERVER_FLOW_RunDamagedItemEvent(p, q, n);
        func_021CC95C((u32 *)(p + 0x1D74), s, 6850);
    }
}
