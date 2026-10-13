/*
 * function: HAND_WAZA_SkyDropBlockFlyingTarget
 * address:  0x021E814C
 * packet:   pkt_ov093_021E814C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasType(void *a, int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_SkyDropBlockFlyingTarget(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_HasType(BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(4)), 2) != 0)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}
