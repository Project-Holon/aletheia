/*
 * function: WEATHER_TASK_MarkStarted
 * address:  0x021A2968
 * packet:   pkt_ov021_021A2968
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (listed as .word data): sets the byte at offset 0x27.
 * Called by WEATHER_TASK_Update.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;

void WEATHER_TASK_MarkStarted(u8 *p)
{
    p[0x27] = 1;
}
