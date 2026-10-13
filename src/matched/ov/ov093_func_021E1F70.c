/*
 * function: HAND_WAZA_ChargeExpireOnMoveEnd
 * address:  0x021E1F70
 * packet:   pkt_ov093_021E1F70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct Node;
extern void BTL_EVENT_RemoveFactor(struct Node *n);

void HAND_WAZA_ChargeExpireOnMoveEnd(void *u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2)) {
        if (*p == 2)
            BTL_EVENT_RemoveFactor(u);
    }
}
