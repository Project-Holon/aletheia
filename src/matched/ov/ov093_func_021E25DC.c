/*
 * function: HAND_WAZA_UproarPreventSleepSilently
 * address:  0x021E25DC
 * packet:   pkt_ov093_021E25DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_UproarPreventSleepSilently(int u, int a, int b, int *p)
{
    if (p[6] != 0)
        BTL_EVENT_OverwriteVar(0x41, 1);
}
