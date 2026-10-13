/*
 * function: HAND_ITEM_PowerItem_HalveSpeed
 * address:  0x021DF288
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_PowerItem_HalveSpeed   0x021DF288  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_EVENT_MultiplyVar   0x021D7704  thumb ov093
 *
 * Shape F1 (o28) with a two-argument tail: gate on BTL_EVENT_GetVar(2), then
 * BTL_EVENT_MultiplyVar(0x35, 2 << 10).  First parameter is not read.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_ITEM_PowerItem_HalveSpeed(void *a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_MultiplyVar(0x35, 2 << 10);
}
