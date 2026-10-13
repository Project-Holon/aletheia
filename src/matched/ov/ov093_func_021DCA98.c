/*
 * function: BTL_ABILITY_PranksterRaiseStatusPriority
 * address:  0x021DCA98
 * packet:   pkt_ov093_021DCA98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int WAZA_TOOL_GetDamageType(int a);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void BTL_ABILITY_PranksterRaiseStatusPriority(int a, int b, int c)
{
    u8 v;

    if (c == BTL_EVENT_GetVar(3) && WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 0) {
        v = BTL_EVENT_GetVar(0x18);
        BTL_EVENT_OverwriteVar(0x18, v + 1);
    }
}
