/*
 * function: WEATHER_TASK_IsStarted
 * address:  0x021A2970
 * packet:   pkt_ov021_021A2970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (listed as .word data): reads the byte at offset 0x27.
 * Called by WEATHER_TASK_Update.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;

u8 WEATHER_TASK_IsStarted(u8 *p)
{
    return p[0x27];
}
