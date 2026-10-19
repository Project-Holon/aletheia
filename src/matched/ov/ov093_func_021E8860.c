/*
 * function: HAND_COMMON_EventScaleDamage
 * address:  0x021E8860
 * packet:   pkt_ov093_021E8860
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_COMMON_EventScaleDamage(int n)
{
    n *= BTL_EVENT_GetVar(0x30);
    BTL_EVENT_OverwriteVar(0x30, n);
}
