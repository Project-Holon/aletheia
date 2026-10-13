/*
 * function: BTL_HANDLER_ITEM_RemoveFactor
 * address:  0x021DCF9C
 * packet:   pkt_021DCF9C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb ov093
 *   BTL_HANDLER_ITEM_RemoveFactor   0x021DCF9C  thumb ov093
 *
 * tail-call thunk to BTL_EVENT_RemoveFactor
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Node;
extern void BTL_EVENT_RemoveFactor(struct Node *n);

void BTL_HANDLER_ITEM_RemoveFactor(void *n)
{
    BTL_EVENT_RemoveFactor(n);
}
