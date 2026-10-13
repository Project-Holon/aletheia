/*
 * function: BTL_SERVER_FLOW_GetLockState
 * address:  0x021C88E4
 * packet:   pkt_ov093_021C88E4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_IsHandExScopeActive  0x021CC96C  thumb  ov093
 *   BTL_SERVER_FLOW_IsHandExScopeInterrupted  0x021CC9A4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q9;
extern int BTL_SERVER_FLOW_IsHandExScopeActive(struct Q9 *p);
extern u32 BTL_SERVER_FLOW_IsHandExScopeInterrupted(u32 *p);

int BTL_SERVER_FLOW_GetLockState(u8 *p)
{
    if (BTL_SERVER_FLOW_IsHandExScopeActive((struct Q9 *)(p + 0x1D74)) != 0) {
        if (BTL_SERVER_FLOW_IsHandExScopeInterrupted((u32 *)(p + 0x1D74)) != 0) return 2;
        return 1;
    }
    return 0;
}
