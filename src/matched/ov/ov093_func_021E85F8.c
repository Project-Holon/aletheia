/*
 * function: HAND_COMMON_IsMoveTarget
 * address:  0x021E85F8
 * packet:   pkt_ov093_021E85F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);

int HAND_COMMON_IsMoveTarget(int v)
{
    u32 i;
    u32 n;

    n = BTL_EVENT_GetVar(5);
    i = 0;
    if (n != 0) {
        do {
            if (v == BTL_EVENT_GetVar(i + 6))
                return 1;
            i++;
        } while (i < n);
    }
    return 0;
}
