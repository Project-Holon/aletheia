/*
 * function: HAND_WAZA_RemoveMoveHandlerUnlessKept
 * address:  0x021E0394
 * packet:   pkt_ov093_021E0394
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
typedef unsigned int   u32;
struct Node;
struct QQ;
extern struct Node *BTL_EVENT_FindFactor(int id, int sub);
extern struct Node *BTL_EVENT_FindNextFactor(struct Node *n);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u32 BTL_EVENT_GetFactorWork(u8 *p, int i);
extern void BTL_EVENT_RemoveFactor(struct Node *n);

void HAND_WAZA_RemoveMoveHandlerUnlessKept(u8 *a, int b)
{
    void *n;
    void *next;

    n = BTL_EVENT_FindFactor(0, BTL_POKEPARAM_GetPokeId(a));
    while (n != 0) {
        next = BTL_EVENT_FindNextFactor(n);
        if (b == BTL_EVENT_GetFactorKey(n) && BTL_EVENT_GetFactorWork(n, 6) == 0) {
            BTL_EVENT_RemoveFactor(n);
        }
        n = next;
    }
}
