/*
 * function: HAND_WAZA_RemoveMoveHandlerById
 * address:  0x021E03F8
 * packet:   pkt_ov093_021E03F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 */

typedef unsigned short u16;
struct Node;
struct QQ;
extern struct Node *BTL_EVENT_FindFactor(int id, int sub);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern struct Node *BTL_EVENT_FindNextFactor(struct Node *n);

void HAND_WAZA_RemoveMoveHandlerById(int a, int b)
{
    void *n = BTL_EVENT_FindFactor(0, a);

    while (n != 0) {
        if (b == BTL_EVENT_GetFactorKey(n)) {
            BTL_EVENT_RemoveFactor(n);
            n = BTL_EVENT_FindFactor(0, a);
        } else {
            n = BTL_EVENT_FindNextFactor(n);
        }
    }
}
