/*
 * function: HAND_WAZA_BideDoubleStoredDamage
 * address:  0x021E3E30
 * packet:   pkt_ov093_021E3E30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_BideDoubleStoredDamage(int u, void *a, int b, int *p)
{
    int x;

    if (b == BTL_EVENT_GetVar(3)) {
        if (*p >= 2) {
            BTL_SERVER_FLOW_GetPokeParam(a, b);
            x = p[1];
            if (x != 0)
                x *= 2;
            BTL_EVENT_OverwriteVar(0x37, x);
            *p = 3;
        }
    }
}
