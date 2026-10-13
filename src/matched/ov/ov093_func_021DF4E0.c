/*
 * function: BTL_HANDLER_ITEM_ExtendWeatherTurns
 * address:  0x021DF4E0
 * packet:   pkt_ov093_021DF4E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
void BTL_HANDLER_ITEM_ExtendWeatherTurns(void *a, int b, int c, int d)
{
    if (c == BTL_EVENT_GetVar(3) && d == BTL_EVENT_GetVar(0x39))
        BTL_EVENT_OverwriteVar(0x24, BTL_HANDLER_ITEM_GetParam((int)a, 2));
}
