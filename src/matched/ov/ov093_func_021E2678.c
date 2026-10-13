/*
 * function: HAND_WAZA_RolloutEndOnDoneOrFail
 * address:  0x021E2678
 * packet:   pkt_ov093_021E2678
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_WAZA_RolloutEndLock  0x021E26C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void HAND_WAZA_RolloutEndLock(void *u, int a, int b, int *p);

void HAND_WAZA_RolloutEndOnDoneOrFail(void *u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2))
        HAND_WAZA_RolloutEndLock(u, a, b, p);
}
