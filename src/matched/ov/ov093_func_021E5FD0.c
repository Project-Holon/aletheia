/*
 * function: HAND_WAZA_HelpingHandBoostPower
 * address:  0x021E5FD0
 * packet:   pkt_ov093_021E5FD0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_WAZA_HelpingHandBoostPower(int a, int b, int c, int *d)
{
    if (*d == BTL_EVENT_GetVar(3))
        BTL_EVENT_MultiplyVar(0x31, 3 << 11);
}
