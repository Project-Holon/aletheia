/*
 * function: HAND_ITEM_RemoveUnforcedFactors
 * address:  0x021DCF24
 * packet:   pkt_ov093_021DCF24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node Node;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern struct Node *BTL_EVENT_FindFactor(int id, int sub);
extern struct Node *BTL_EVENT_FindNextFactor(struct Node *n);
extern u32 BTL_EVENT_GetFactorWork(u8 *p, int i);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
void HAND_ITEM_RemoveUnforcedFactors(u8 *p)
{
    Node *n = BTL_EVENT_FindFactor(5, BTL_POKEPARAM_GetPokeId(p));
    while (n != 0) {
        Node *next = BTL_EVENT_FindNextFactor(n);
        if (BTL_EVENT_GetFactorWork((u8 *)n, 6) == 0)
            BTL_EVENT_RemoveFactor(n);
        n = next;
    }
}
