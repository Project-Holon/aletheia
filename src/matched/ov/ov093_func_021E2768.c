/*
 * function: HAND_WAZA_TripleKickRaisePower
 * address:  0x021E2768
 * packet:   pkt_ov093_021E2768
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_TripleKickRaisePower(int u, int a, int b, int *p)
{
    int n;

    if (b == BTL_EVENT_GetVar(3)) {
        n = *p + 1;
        *p = n;
        BTL_EVENT_OverwriteVar(0x30, n * 10);
    }
}
