/*
 * function: HAND_WAZA_IsKeptOnSuspend
 * address:  0x021E03E8
 * packet:   pkt_ov093_021E03E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

int HAND_WAZA_IsKeptOnSuspend(void *n, u32 *q)
{
    if (q[6] != 0) return 1;
    return 0;
}
