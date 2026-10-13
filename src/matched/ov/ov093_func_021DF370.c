/*
 * function: BTL_HANDLER_ITEM_BigRoot_BoostDrain
 * address:  0x021DF370
 * packet:   pkt_ov093_021DF370
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern int BTL_HANDLER_ITEM_GetBoostRatio(int);
extern void BTL_EVENT_MultiplyVar(int, int);
void BTL_HANDLER_ITEM_BigRoot_BoostDrain(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_MultiplyVar(0x35, BTL_HANDLER_ITEM_GetBoostRatio(a));
}
