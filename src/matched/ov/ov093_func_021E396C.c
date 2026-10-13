/*
 * function: HAND_WAZA_MagnitudeSetDefaultLevel
 * address:  0x021E396C
 * packet:   pkt_ov093_021E396C
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

void HAND_WAZA_MagnitudeSetDefaultLevel(int u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (*p == 0)
            *p = 10;
        BTL_EVENT_OverwriteVar(0x30, *p);
    }
}
